#include "VulkanInstance.hpp"
#include <Core/EngineInfo.hpp>
#include <Core/Log.hpp>
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_to_string.hpp>


namespace FikoEngine
{
    Result<VulkanInstanceStatus, vk::Instance> CreateInstance( VulkanSpec spec )
    {
        LOG_INFO( "Creating Vulkan Instance" );
        LOG_INFO( "    Application Name: " + std::string( spec.rendererSpec.AppName ) );
        LOG_INFO( "    Engine Name: " + std::string( ENGINE_INFO.Name ) );
        LOG_INFO( "    Engine Version: " + std::to_string( ENGINE_INFO.Version ) );

        uint32_t api_Version;
        vk::Result result = vk::enumerateInstanceVersion( &api_Version );
        if ( result != vk::Result::eSuccess )
        {
            return Result<VulkanInstanceStatus, vk::Instance>( VulkanInstanceStatus::Fail, VK_NULL_HANDLE );
        }

        LOG_INFO( "    Vulkan API Version: " + std::to_string( api_Version ) );

        vk::ApplicationInfo applicationInfo( spec.rendererSpec.AppName.data(), 1, ENGINE_INFO.Name.c_str(),
                                             ENGINE_INFO.Version, api_Version );

        // initialize the vk::InstanceCreateInfo
        vk::InstanceCreateInfo instanceCreateInfo( {}, &applicationInfo );

        // create an Instance
        vk::Instance instance = vk::createInstance( instanceCreateInfo );


        LOG_INFO( "Found Devices:" );
        std::vector<vk::PhysicalDevice> enumeratedDevices = instance.enumeratePhysicalDevices();
        for ( auto device: enumeratedDevices )
        {
            auto properties = device.getProperties();

            LOG_INFO( "     " + std::string( properties.deviceName ) );
            LOG_INFO( "         Type: " + vk::to_string( properties.deviceType ) );
            LOG_INFO( "         Vendor: " + std::to_string( properties.vendorID ) );
            LOG_INFO( "         Driver Version: " + std::to_string( properties.driverVersion ) );
        }

        return Result<VulkanInstanceStatus, vk::Instance>( VulkanInstanceStatus::Fail, instance );
    }
}// namespace FikoEngine