#pragma once

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
#include <Core/Result.hpp>
#define VULKAN_HPP_DISABLE_ENHANCED_MODE
#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class vkInterface
    {
    public:
        vkInterface() = default;
        ~vkInterface() = default;

        static ResultValue<vk::Result, vk::CommandPool> CreateCommandPool( vk::Device device,
                                                                           uint32_t graphicsQueueFamilyIndex );

        static void DestroyCommandPool( vk::Device device, vk::CommandPool commandPool );

        static ResultValue<vk::Result, std::vector<vk::CommandBuffer>>
        AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo );

        static void FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, vk::CommandBuffer buffer );

        static ResultValueType<> CommandBufferBegin( vk::CommandBuffer buffer, vk::CommandBufferBeginInfo beginInfo );

        static ResultValueType<> CommandBufferEnd( vk::CommandBuffer buffer );

        static ResultValue<vk::Result, vk::FormatProperties> GetFormatProperties( vk::PhysicalDevice physicalDevice,
                                                                                  vk::Format format );

        static ResultValue<vk::Result, vk::Image> CreateImage( vk::Device device,
                                                               vk::ImageCreateInfo& imageCreateInfo );

        static ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>
        GetMemoryProperties( vk::PhysicalDevice physicalDevice );

        static ResultValue<vk::Result, vk::MemoryRequirements> GetImageMemoryRequirements( vk::Device device,
                                                                                           vk::Image image );

        static ResultValue<vk::Result, vk::MemoryRequirements> GetBufferMemoryRequirements( vk::Device device,
                                                                                            vk::Buffer buffer );

        static ResultValue<vk::Result, vk::DeviceMemory> AllocateMemory( vk::Device device,
                                                                         vk::MemoryAllocateInfo& memoryAllocateInfo );

        static ResultValue<vk::Result, vk::ImageView> CreateImageView( vk::Device device,
                                                                       vk::ImageViewCreateInfo& imageViewCreateInfo );

        static ResultValueType<> BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                                  vk::DeviceSize memoryOffset );

        static ResultValueType<> BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory,
                                                   vk::DeviceSize memoryOffset );

        static ResultValue<vk::Result, void*> MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                         vk::DeviceSize offset, vk::DeviceSize size,
                                                         vk::MemoryMapFlags flags );

        static void UnmapMemory( vk::Device device, vk::DeviceMemory memory );

        static ResultValue<vk::Result, vk::Buffer> CreateBuffer( vk::Device device,
                                                                 vk::BufferCreateInfo bufferCreateInfo );

    public:
        template <typename T>
        static void RegisterMockPtr()
        {
            if ( s_EnableTest ) s_MockPtr = new T();
        }

        template <typename T>
        static void DestroyMockPtr()
        {
            if ( s_EnableTest && s_MockPtr ) delete ( T* ) s_MockPtr;
        }

        template <typename T>
        static T* GetMockPtr()
        {
            return ( T* ) s_MockPtr;
        }

    protected:
        virtual ResultValue<vk::Result, vk::CommandPool> _CreateCommandPool( vk::Device device,
                                                                             uint32_t graphicsQueueFamilyIndex ) = 0;

        virtual void _DestroyCommandPool( vk::Device device, vk::CommandPool commandPool ) = 0;

        virtual ResultValue<vk::Result, std::vector<vk::CommandBuffer>>
        _AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo ) = 0;
        virtual void _FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool,
                                          vk::CommandBuffer buffer ) = 0;

        virtual ResultValueType<> _CommandBufferBegin( vk::CommandBuffer buffer,
                                                       vk::CommandBufferBeginInfo beginInfo ) = 0;

        virtual ResultValueType<> _CommandBufferEnd( vk::CommandBuffer buffer ) = 0;

        virtual ResultValue<vk::Result, vk::FormatProperties> _GetFormatProperties( vk::PhysicalDevice physicalDevice,
                                                                                    vk::Format format ) = 0;

        virtual ResultValue<vk::Result, vk::Image> _CreateImage( vk::Device device,
                                                                 vk::ImageCreateInfo& imageCreateInfo ) = 0;

        virtual ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>
        _GetMemoryProperties( vk::PhysicalDevice physicalDevice ) = 0;

        virtual ResultValue<vk::Result, vk::MemoryRequirements> _GetImageMemoryRequirements( vk::Device device,
                                                                                             vk::Image image ) = 0;

        virtual ResultValue<vk::Result, vk::MemoryRequirements> _GetBufferMemoryRequirements( vk::Device device,
                                                                                              vk::Buffer buffer ) = 0;

        virtual ResultValue<vk::Result, vk::DeviceMemory>
        _AllocateMemory( vk::Device device, vk::MemoryAllocateInfo& memoryAllocateInfo ) = 0;

        virtual ResultValue<vk::Result, vk::ImageView>
        _CreateImageView( vk::Device device, vk::ImageViewCreateInfo& imageViewCreateInfo ) = 0;

        virtual ResultValueType<> _BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                                    vk::DeviceSize memoryOffset ) = 0;

        virtual ResultValueType<> _BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory,
                                                     vk::DeviceSize memoryOffset ) = 0;
        virtual ResultValue<vk::Result, void*> _MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                           vk::DeviceSize offset, vk::DeviceSize size,
                                                           vk::MemoryMapFlags flags ) = 0;

        virtual void _UnmapMemory( vk::Device device, vk::DeviceMemory memory ) = 0;
        virtual ResultValue<vk::Result, vk::Buffer> _CreateBuffer( vk::Device device,
                                                                   vk::BufferCreateInfo bufferCreateInfo ) = 0;

    public:
        inline static vkInterface* s_MockPtr = nullptr;

#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 1
        constexpr inline static bool s_EnableTest = true;
#else
        constexpr inline static bool s_EnableTest = false;
#endif
    };
}// namespace FikoEngine

#include "VulkanInterface_impl.hpp"