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
 * VulkanInterface class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "VulkanInterface.hpp"

/***********************************************************************************************************************
Enum Class implementation
***********************************************************************************************************************/

/***********************************************************************************************************************
Struct implementation
***********************************************************************************************************************/

/***********************************************************************************************************************
Class implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    ResultValue<vk::Result, vk::CommandPool> vkInterface::CreateCommandPool( vk::Device device,
                                                                             uint32_t graphicsQueueFamilyIndex )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 1
        auto res = device.createCommandPool(
                vk::CommandPoolCreateInfo( vk::CommandPoolCreateFlags(), graphicsQueueFamilyIndex ) );
        return ResultValue<vk::Result, vk::CommandPool>( res.result, res.value );
#else
        return s_MockPtr->_CreateCommandPool( device, graphicsQueueFamilyIndex );
#endif


    }

    void vkInterface::DestroyCommandPool( vk::Device device, vk::CommandPool commandPool )
    {
        if constexpr ( !s_EnableTest ) { device.destroyCommandPool( commandPool ); }
        else { s_MockPtr->_DestroyCommandPool( device, commandPool ); }
    }

    void vkInterface::FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, vk::CommandBuffer buffer )
    {
        if constexpr ( !s_EnableTest ) { device.freeCommandBuffers( commandPool, buffer ); }
        else { s_MockPtr->_FreeCommandBuffers( device, commandPool, buffer ); }
    }

    ResultValue<vk::Result, std::vector<vk::CommandBuffer>>
    vkInterface::AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo )
    {
        if constexpr ( !s_EnableTest )
        {
            auto res = device.allocateCommandBuffers( allocateInfo );
            return { res.result, res.value };
        }

        return s_MockPtr->_AllocateCommandBuffers( device, allocateInfo );
    }

    ResultValueType<> vkInterface::CommandBufferBegin( vk::CommandBuffer buffer, vk::CommandBufferBeginInfo beginInfo )
    {
        if constexpr ( !s_EnableTest ) { return ResultValueType<>( buffer.begin( beginInfo ) ); }

        return { s_MockPtr->_CommandBufferBegin( buffer, beginInfo ) };
    }

    ResultValueType<> vkInterface::CommandBufferEnd( vk::CommandBuffer buffer )
    {
        if constexpr ( !s_EnableTest ) { return ResultValueType<>( buffer.end() ); }

        return { s_MockPtr->_CommandBufferEnd( buffer ) };
    }

    ResultValue<vk::Result, vk::FormatProperties> vkInterface::GetFormatProperties( vk::PhysicalDevice physicalDevice,
                                                                                    vk::Format format )
    {
        if constexpr ( !s_EnableTest )
        {
            return { vk::Result::eSuccess, physicalDevice.getFormatProperties( format ) };
        }

        return s_MockPtr->_GetFormatProperties( physicalDevice, format );
    }

    ResultValue<vk::Result, vk::Image> vkInterface::CreateImage( vk::Device device,
                                                                 vk::ImageCreateInfo& imageCreateInfo )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::Image>( device.createImage( imageCreateInfo ) );
        }

        return s_MockPtr->_CreateImage( device, imageCreateInfo );
    }

    ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>
    vkInterface::GetMemoryProperties( vk::PhysicalDevice physicalDevice )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>( vk::Result::eSuccess,
                                                                                physicalDevice.getMemoryProperties() );
        }

        return s_MockPtr->_GetMemoryProperties( physicalDevice );
    }

    ResultValue<vk::Result, vk::MemoryRequirements> vkInterface::GetImageMemoryRequirements( vk::Device device,
                                                                                             vk::Image image )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::MemoryRequirements>( vk::Result::eSuccess,
                                                                    device.getImageMemoryRequirements( image ) );
        }

        return s_MockPtr->_GetImageMemoryRequirements( device, image );
    }

    ResultValue<vk::Result, vk::MemoryRequirements> vkInterface::GetBufferMemoryRequirements( vk::Device device,
                                                                                              vk::Buffer buffer )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::MemoryRequirements>( vk::Result::eSuccess,
                                                                    device.getBufferMemoryRequirements( buffer ) );
        }

        return s_MockPtr->_GetBufferMemoryRequirements( device, buffer );
    }

    ResultValue<vk::Result, vk::DeviceMemory> vkInterface::AllocateMemory( vk::Device device,
                                                                           vk::MemoryAllocateInfo& memoryAllocateInfo )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::DeviceMemory>( device.allocateMemory( memoryAllocateInfo ) );
        }

        return s_MockPtr->_AllocateMemory( device, memoryAllocateInfo );
    }

    ResultValue<vk::Result, vk::ImageView> vkInterface::CreateImageView( vk::Device device,
                                                                         vk::ImageViewCreateInfo& imageViewCreateInfo )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::ImageView>( device.createImageView( imageViewCreateInfo ) );
        }

        return s_MockPtr->_CreateImageView( device, imageViewCreateInfo );
    }

    ResultValueType<> vkInterface::BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                                    vk::DeviceSize memoryOffset )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValueType( device.bindImageMemory( image, memory, memoryOffset ) );
        }

        return s_MockPtr->_BindImageMemory( device, image, memory, memoryOffset );
    }

    ResultValueType<> vkInterface::BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory,
                                                     vk::DeviceSize memoryOffset )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValueType( device.bindBufferMemory( buffer, memory, memoryOffset ) );
        }

        return s_MockPtr->_BindBufferMemory( device, buffer, memory, memoryOffset );
    }

    ResultValue<vk::Result, void*> vkInterface::MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                           vk::DeviceSize offset, vk::DeviceSize size,
                                                           vk::MemoryMapFlags flags )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, void*>( device.mapMemory( memory, offset, size, flags ) );
        }

        return s_MockPtr->_MapMemory( device, memory, offset, size, flags );
    }

    void vkInterface::UnmapMemory( vk::Device device, vk::DeviceMemory memory )
    {
        if constexpr ( !s_EnableTest ) { device.unmapMemory( memory ); }

        return s_MockPtr->_UnmapMemory( device, memory );
    }

    ResultValue<vk::Result, vk::Buffer> vkInterface::CreateBuffer( vk::Device device,
                                                                   vk::BufferCreateInfo bufferCreateInfo )
    {
        if constexpr ( !s_EnableTest )
        {
            return ResultValue<vk::Result, vk::Buffer>( device.createBuffer( bufferCreateInfo ) );
        }

        return s_MockPtr->_CreateBuffer( device, bufferCreateInfo );
    }
}// namespace FikoEngine