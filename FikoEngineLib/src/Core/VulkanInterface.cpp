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

    vk::ResultValue<vk::CommandPool> vkInterface::CreateCommandPool( vk::Device* device,
                                                                     uint32_t graphicsQueueFamilyIndex )
    {
        return vkInterface()._CreateCommandPool( device, graphicsQueueFamilyIndex );
    }

    void vkInterface::DestroyCommandPool( vk::Device* device, vk::CommandPool commandPool ) {
        vkInterface()._DestroyCommandPool(device,commandPool);
    }

    void vkInterface::FreeCommandBuffers( vk::Device* device, vk::CommandPool commandPool, vk::CommandBuffer buffer ) {
        vkInterface()._FreeCommandBuffers(device,commandPool,buffer);
    }

    vk::ResultValue<std::vector<vk::CommandBuffer>>
    vkInterface::AllocateCommandBuffers( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo )
    {
        return vkInterface()._AllocateCommandBuffers(device,allocateInfo);
    }

    vk::ResultValue<vk::CommandPool> vkInterface::_CreateCommandPool( vk::Device* device,
                                                                      uint32_t graphicsQueueFamilyIndex )
    {
        return device->createCommandPool(
                vk::CommandPoolCreateInfo( vk::CommandPoolCreateFlags(), graphicsQueueFamilyIndex ) );
    }

    void vkInterface::_DestroyCommandPool( vk::Device* device, vk::CommandPool commandPool )
    {
        device->destroyCommandPool( commandPool );
    }

    void vkInterface::_FreeCommandBuffers( vk::Device* device, vk::CommandPool commandPool, vk::CommandBuffer buffer )
    {
        device->freeCommandBuffers( commandPool, buffer );
    }

    vk::ResultValue<std::vector<vk::CommandBuffer>>
    vkInterface::_AllocateCommandBuffers( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo )
    {
        return device->allocateCommandBuffers( allocateInfo );
    }

}// namespace FikoEngine