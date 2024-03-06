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
        
        static vk::ResultValue<vk::CommandPool> CreateCommandPool( vk::Device* device,
                                                                     uint32_t graphicsQueueFamilyIndex );

        static void DestroyCommandPool( vk::Device* device, vk::CommandPool commandPool );
        static void FreeCommandBuffers( vk::Device* device, vk::CommandPool commandPool, vk::CommandBuffer buffer );

        static vk::ResultValue<std::vector<vk::CommandBuffer>>
        AllocateCommandBuffers( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo );

    protected:
        virtual vk::ResultValue<vk::CommandPool> _CreateCommandPool( vk::Device* device,
                                                                      uint32_t graphicsQueueFamilyIndex );

        virtual void _DestroyCommandPool( vk::Device* device, vk::CommandPool commandPool );
        virtual void _FreeCommandBuffers( vk::Device* device, vk::CommandPool commandPool, vk::CommandBuffer buffer );

        virtual vk::ResultValue<std::vector<vk::CommandBuffer>>
        _AllocateCommandBuffers( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo );
    };
}// namespace FikoEngine