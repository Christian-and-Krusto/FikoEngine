/**
 * @file
 * @author Krusto Stoyanov ( k.stoianov2@gmail.com )
 * @brief 
 * @version 1.0
 * @date 
 * 
 * @section LICENSE
 * MIT License
 * 
 * Copyright (c) 2024 Christian and Krusto
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 * @section DESCRIPTION
 * 
 * VulkanContext class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "VulkanContext.hpp"
#include "DebugMessanger.hpp"
#include "Window.hpp"

#include <Core/EngineInfo.hpp>
#include <Core/Log.hpp>

#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_to_string.hpp>

#include <algorithm>
#include <ranges>

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Type definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Static variables
***********************************************************************************************************************/
FikoEngine::VulkanContext* FikoEngine::VulkanContext::s_VulkanContext = {};

/***********************************************************************************************************************
VulkanContext Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    Result<VulkanContextStatus> VulkanContext::Create( VulkanSpec spec, Window* windowPtr )
    {
        VulkanContext::s_VulkanContext = new VulkanContext( spec, windowPtr );
        auto vulkanContextPtr = VulkanContext::Get();

        //Create Instance
        if ( VulkanInstanceStatus::Created != vulkanContextPtr->CreateInstance() )
        {
            LOG_ERROR( "Could not create Vulkan Instance!" );
            return { VulkanContextStatus::Fail };
        }

        //Create Debug Callback
        DebugMessanger::Create( VulkanContext::Get()->m_Instance );

        //Create Window Surface
        auto surfaceStatus = windowPtr->CreateSurface( vulkanContextPtr->m_Instance );
        if ( WindowStatus::Surface_Created != surfaceStatus )
        {
            LOG_ERROR( "Could Not Create Window Surface!" );
            return { VulkanContextStatus::Fail };
        }
        vulkanContextPtr->m_Surface = windowPtr->GetSurface().returnValue;
        LOG_INFO( "Created Window Surface!" );

        //Select Physical Device
        if ( VulkanPhysicalDeviceStatus::Selected != vulkanContextPtr->SelectPhysicalDevice() )
        {
            return { VulkanContextStatus::Fail };
        }

        //Create Logical Device
        if ( VulkanDeviceStatus::Created != vulkanContextPtr->CreateDevice() ) { return { VulkanContextStatus::Fail }; }

        if ( VulkanSwapchainStatus::Created != vulkanContextPtr->CreateSwapchain() )
        {
            return { VulkanContextStatus::Fail };
        }

        //Create Command Pool
        auto result = CommandPool::Create( &vulkanContextPtr->m_Device, vulkanContextPtr->m_GraphicsQueueIndex );
        VulkanContext::Get()->m_CommandPool = result.returnValue;


        LOG_INFO( "Vulkan Context Created!" );
        return { VulkanContextStatus::Created };
    }

    Result<VulkanContextStatus> VulkanContext::Destroy()
    {
        auto vulkanCtxPtr = VulkanContext::Get();

        CommandPool::Destroy( vulkanCtxPtr->m_CommandPool );

        vulkanCtxPtr->m_Device.destroySwapchainKHR(vulkanCtxPtr->m_Swapchain);
        LOG_INFO("Destroyed Swapchain!");

        vulkanCtxPtr->m_Device.destroy();
        LOG_INFO( "Destroyed Logical Device" );

        auto windowSurfaceStatus = vulkanCtxPtr->m_WindowPtr->DestroySurface( vulkanCtxPtr->m_Instance );
        if ( WindowStatus::Surface_Destroyed == windowSurfaceStatus ) { LOG_INFO( "Destroyed Window Surface" ); }

        DebugMessanger::Destroy( vulkanCtxPtr->m_Instance );

        vulkanCtxPtr->m_Instance.destroy();
        LOG_INFO( "Destroyed Vulkan Instance" );

        delete VulkanContext::s_VulkanContext;
        LOG_INFO( "Vulkan Context Destroyed!" );

        return { VulkanContextStatus::Destroyed };
    }

    VulkanContext* VulkanContext::Get() { return VulkanContext::s_VulkanContext; }

    VulkanContext::VulkanContext( VulkanSpec spec, Window* windowPtr ) : m_WindowPtr( windowPtr ), m_Spec( spec ) {}

    Result<VulkanInstanceStatus> VulkanContext::CreateInstance()
    {
        LOG_INFO( "Creating Vulkan Instance" );
        LOG_INFO( "    Application Name: " + std::string( m_Spec.rendererSpec.AppName ) );
        LOG_INFO( "    Engine Name: " + std::string( ENGINE_INFO.Name ) );
        LOG_INFO( "    Engine Version: " + std::to_string( ENGINE_INFO.Version ) );

        uint32_t api_Version = VK_API_VERSION_1_3;
        LOG_INFO( "    Vulkan API Version: " + std::to_string( api_Version ) );

        VkApplicationInfo applicationInfo = {};
        applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        applicationInfo.pApplicationName = m_Spec.rendererSpec.AppName.data();
        applicationInfo.applicationVersion = 1;
        applicationInfo.pEngineName = ENGINE_INFO.Name.c_str();
        applicationInfo.engineVersion = ENGINE_INFO.Version;
        applicationInfo.apiVersion = api_Version;

        bool availableDebugFlag = DebugMessanger::IsDebugExtensionAvailable();

        std::vector<const char*> extensions;

        LOG_INFO( "Enabled Instance Extensions:" )
        for ( auto& extension: m_Spec.extensions )
        {
            extensions.push_back( extension.c_str() );
            LOG_INFO( "    " + std::string( extension ) );
        }

        if ( availableDebugFlag )
        {
            extensions.push_back( VK_EXT_DEBUG_UTILS_EXTENSION_NAME );
            LOG_INFO( "    " + std::string( VK_EXT_DEBUG_UTILS_EXTENSION_NAME ) );
        }

        VkInstanceCreateInfo instanceCreateInfo = {};
        instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instanceCreateInfo.pApplicationInfo = &applicationInfo;
        instanceCreateInfo.enabledExtensionCount = extensions.size();
        instanceCreateInfo.ppEnabledExtensionNames = extensions.data();

        VulkanContext::Get()->m_Instance = vk::createInstance( instanceCreateInfo ).value;

        return Result<VulkanInstanceStatus>( VulkanInstanceStatus::Created );
    }

    Result<VulkanPhysicalDeviceStatus> VulkanContext::SelectPhysicalDevice()
    {
        LOG_INFO( "Found Devices:" );
        std::vector<vk::PhysicalDevice> enumeratedDevices =
                VulkanContext::Get()->m_Instance.enumeratePhysicalDevices().value;

        for ( auto device: enumeratedDevices )
        {
            auto deviceProps = device.getProperties();

            LOG_INFO( "    " + std::string( deviceProps.deviceName ) );
            LOG_INFO( "        Type: " + vk::to_string( deviceProps.deviceType ) );
            LOG_INFO( "        Vendor: " + std::to_string( deviceProps.vendorID ) );
            LOG_INFO( "        Driver Version: " + std::to_string( deviceProps.driverVersion ) );

            if ( deviceProps.deviceType == vk::PhysicalDeviceType::eDiscreteGpu ) { m_PhysicalDevice = device; }
        }

        if ( VK_NULL_HANDLE == m_PhysicalDevice )
        {
            if ( enumeratedDevices.size() > 0 )
            {
                m_PhysicalDevice = enumeratedDevices[ 0 ];

                LOG_INFO( "Selected Physical Device!" );
                return { VulkanPhysicalDeviceStatus::Selected };
            }
            else
            {
                LOG_ERROR( "Physical Device Not Found!" );
                return { VulkanPhysicalDeviceStatus::Not_Found };
            }
        }

        std::string selectedDevice = std::string( m_PhysicalDevice.getProperties().deviceName );
        LOG_INFO( "Selected: " + selectedDevice );

        return { VulkanPhysicalDeviceStatus::Selected };
    }

    Result<VulkanQueueFamilyStatus> VulkanContext::SelectQueueFamily()
    {
        std::vector<vk::QueueFamilyProperties> queueFamilyProperties = m_PhysicalDevice.getQueueFamilyProperties();

        //Find Graphics Queue Index
        auto propertyIterator = std::find_if(
                queueFamilyProperties.begin(), queueFamilyProperties.end(),
                []( vk::QueueFamilyProperties const& qfp ) { return qfp.queueFlags & vk::QueueFlagBits::eGraphics; } );
        size_t graphicsQueueFamilyIndex = std::distance( queueFamilyProperties.begin(), propertyIterator );
        if ( graphicsQueueFamilyIndex >= queueFamilyProperties.size() )
        {
            LOG_ERROR( "Queues Not Found!" );
            return { VulkanQueueFamilyStatus::Not_Found };
        }

        size_t presentQueueFamilyIndex = m_PhysicalDevice.getSurfaceSupportKHR( m_GraphicsQueueIndex, m_Surface ).value
                                                 ? graphicsQueueFamilyIndex
                                                 : queueFamilyProperties.size();

        if ( presentQueueFamilyIndex != queueFamilyProperties.size() ) { return { VulkanQueueFamilyStatus::Found }; }

        // the graphicsQueueFamilyIndex doesn't support present -> look for an other family index that supports both
        // graphics and present
        for ( size_t i = 0; i < queueFamilyProperties.size(); i++ )
        {
            if ( ( queueFamilyProperties[ i ].queueFlags & vk::QueueFlagBits::eGraphics ) &&
                 m_PhysicalDevice.getSurfaceSupportKHR( static_cast<uint32_t>( i ), m_Surface ).value )
            {
                graphicsQueueFamilyIndex = i;
                presentQueueFamilyIndex = i;
                break;
            }
        }
        if ( presentQueueFamilyIndex == queueFamilyProperties.size() )
        {
            // there's nothing like a single family index that supports both graphics and present -> look for an other
            // family index that supports present
            for ( size_t i = 0; i < queueFamilyProperties.size(); i++ )
            {
                if ( m_PhysicalDevice.getSurfaceSupportKHR( static_cast<uint32_t>( i ), m_Surface ).value )
                {
                    presentQueueFamilyIndex = i;
                    break;
                }
            }
        }

        if ( presentQueueFamilyIndex == queueFamilyProperties.size() )
        {
            LOG_ERROR( "Queues Not Found!" );
            return { VulkanQueueFamilyStatus::Not_Found };
        }

        m_PresentQueueIndex = presentQueueFamilyIndex;
        m_GraphicsQueueIndex = graphicsQueueFamilyIndex;

        LOG_INFO( "Selected Queues!" );

        return { VulkanQueueFamilyStatus::Found };
    }

    Result<VulkanSwapchainStatus> VulkanContext::GetCapabilities()
    {
        auto surfaceFormatStatus = m_PhysicalDevice.getSurfaceFormatsKHR( m_Surface );
        if ( vk::Result::eSuccess != surfaceFormatStatus.result )
        {
            LOG_ERROR( "Can Not Retrieve Surface Formats!" );
            return { VulkanSwapchainStatus::Fail };
        }

        m_SupportedFormats = surfaceFormatStatus.value;
        if ( m_SupportedFormats.empty() )
        {
            LOG_ERROR( "Surface Formats Not Available!" );
            return { VulkanSwapchainStatus::Fail };
        }

        m_Format = m_SupportedFormats[ 0 ].format;
        if ( vk::Format::eUndefined == m_SupportedFormats[ 0 ].format ) { m_Format = vk::Format::eB8G8R8A8Unorm; }

        auto surfaceCapabilitiesStatus = m_PhysicalDevice.getSurfaceCapabilitiesKHR( m_Surface );
        if ( vk::Result::eSuccess != surfaceCapabilitiesStatus.result )
        {
            LOG_ERROR( "Can Not Retrieve Surface Capabilities!" );
            return { VulkanSwapchainStatus::Fail };
        }

        m_SurfaceCapabilities = surfaceCapabilitiesStatus.value;

        if ( m_SurfaceCapabilities.currentExtent.width == std::numeric_limits<uint32_t>::max() )
        {
            m_SwapchainExtent.width = std::clamp( m_Spec.rendererSpec.width, m_SurfaceCapabilities.minImageExtent.width,
                                                  m_SurfaceCapabilities.maxImageExtent.width );
            m_SwapchainExtent.height =
                    std::clamp( m_Spec.rendererSpec.height, m_SurfaceCapabilities.minImageExtent.height,
                                m_SurfaceCapabilities.maxImageExtent.height );
        }
        else { m_SwapchainExtent = m_SurfaceCapabilities.currentExtent; }

        return { VulkanSwapchainStatus::Success };
    }

    Result<VulkanSwapchainStatus> VulkanContext::CreateSwapchain()
    {

        auto queueFamilyStatus = SelectQueueFamily();
        if ( VulkanQueueFamilyStatus::Found != queueFamilyStatus )
        {
            LOG_ERROR( "Swapchain Can Not Find Queue Family Indices!" );
            return { VulkanSwapchainStatus::Fail };
        }

        auto capabilitiesStatus = GetCapabilities();
        if ( VulkanSwapchainStatus::Success != capabilitiesStatus )
        {
            LOG_ERROR( "Swapchain Can Not Get Capabiliteis!" );
            return { VulkanSwapchainStatus::Fail };
        }

        vk::PresentModeKHR swapchainPresentMode = vk::PresentModeKHR::eFifo;

        vk::SurfaceTransformFlagBitsKHR preTransform =
                ( m_SurfaceCapabilities.supportedTransforms & vk::SurfaceTransformFlagBitsKHR::eIdentity )
                        ? vk::SurfaceTransformFlagBitsKHR::eIdentity
                        : m_SurfaceCapabilities.currentTransform;

        vk::CompositeAlphaFlagBitsKHR compositeAlpha =
                ( m_SurfaceCapabilities.supportedCompositeAlpha & vk::CompositeAlphaFlagBitsKHR::ePreMultiplied )
                        ? vk::CompositeAlphaFlagBitsKHR::ePreMultiplied
                : ( m_SurfaceCapabilities.supportedCompositeAlpha & vk::CompositeAlphaFlagBitsKHR::ePostMultiplied )
                        ? vk::CompositeAlphaFlagBitsKHR::ePostMultiplied
                : ( m_SurfaceCapabilities.supportedCompositeAlpha & vk::CompositeAlphaFlagBitsKHR::eInherit )
                        ? vk::CompositeAlphaFlagBitsKHR::eInherit
                        : vk::CompositeAlphaFlagBitsKHR::eOpaque;

        vk::SwapchainCreateInfoKHR swapChainCreateInfo(
                {}, m_Surface,
                std::clamp( 3u, m_SurfaceCapabilities.minImageCount, m_SurfaceCapabilities.maxImageCount ), m_Format,
                vk::ColorSpaceKHR::eSrgbNonlinear, m_SwapchainExtent, 1, vk::ImageUsageFlagBits::eColorAttachment,
                vk::SharingMode::eExclusive, {}, preTransform, compositeAlpha, swapchainPresentMode, true, nullptr );

        uint32_t queueFamilyIndices[ 2 ] = { static_cast<uint32_t>( m_GraphicsQueueIndex ),
                                             static_cast<uint32_t>( m_PresentQueueIndex ) };
        if ( m_GraphicsQueueIndex != m_PresentQueueIndex )
        {
            swapChainCreateInfo.imageSharingMode = vk::SharingMode::eConcurrent;
            swapChainCreateInfo.queueFamilyIndexCount = 2;
            swapChainCreateInfo.pQueueFamilyIndices = queueFamilyIndices;
        }

        auto swapchainStatus = m_Device.createSwapchainKHR( swapChainCreateInfo );
        if ( vk::Result::eSuccess != swapchainStatus.result )
        {
            LOG_ERROR( "Can Not Create Swapchain!" );
            return { VulkanSwapchainStatus::Fail };
        }
        m_Swapchain = swapchainStatus.value;
        
        LOG_INFO( "Created Swapchain!" );
        return { VulkanSwapchainStatus::Created };
    }

    Result<VulkanDeviceStatus> VulkanContext::CreateDevice()
    {
        auto availableExtensionsStatus = m_PhysicalDevice.enumerateDeviceExtensionProperties();
        if ( vk::Result::eSuccess != availableExtensionsStatus.result )
        {
            LOG_ERROR( "Can Not Retrieve Available Device Extensions!" );
            return { VulkanDeviceStatus::Fail };
        }
        auto availableExtensions = availableExtensionsStatus.value;

        auto propertyIterator =
                std::find_if( availableExtensions.begin(), availableExtensions.end(),
                              []( vk::ExtensionProperties const& properties ) {
                                  return std::string( properties.extensionName ) == std::string( "VK_KHR_swapchain" );
                              } );
        if ( availableExtensions.end() == propertyIterator )
        {
            LOG_ERROR( "Device Swapchain Extension Not Available!" );
            return { VulkanDeviceStatus::Fail };
        }

        float queuePriority = 0.0f;
        VkDeviceQueueCreateInfo deviceQueueCreateInfo = {};
        deviceQueueCreateInfo.queueFamilyIndex = m_GraphicsQueueIndex;
        deviceQueueCreateInfo.queueCount = 1;
        deviceQueueCreateInfo.pQueuePriorities = &queuePriority;

        const std::vector<const char*> deviceExtensions = { "VK_KHR_swapchain" };
        VkDeviceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        createInfo.queueCreateInfoCount = 1;
        createInfo.pQueueCreateInfos = &deviceQueueCreateInfo;
        createInfo.enabledExtensionCount = 1;
        createInfo.ppEnabledExtensionNames = deviceExtensions.data();

        auto deviceStatus = m_PhysicalDevice.createDevice( createInfo );

        if ( vk::Result::eSuccess != deviceStatus.result )
        {
            LOG_ERROR( "Can Not Create Logical Device!" );
            return { VulkanDeviceStatus::Fail };
        }

        m_Device = deviceStatus.value;
        LOG_INFO( "Logical Device Created" );
        return { VulkanDeviceStatus::Created };
    }

}// namespace FikoEngine