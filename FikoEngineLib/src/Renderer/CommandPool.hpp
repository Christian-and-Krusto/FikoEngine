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
 * Command Pool class definition 
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <Core/Result.hpp>
#include <Core/VulkanInterface.hpp>

/***********************************************************************************************************************
Enum class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class CommandPoolState
    {
        Fail,
        Created,
        Destroyed
    };

    enum class CommandBufferState
    {
        Created,
        Destroyed,
        Initial,
        Recording,
        Executable,
        Pending,
        Invalid
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class CommandPool
    {
    public:
        CommandPool() = default;
        ~CommandPool() = default;

    public:
        ResultValueType<CommandBufferState> CreateCommandBuffer();
        ResultValue<CommandBufferState, vk::CommandBuffer> GetCommandBuffer( uint32_t id = 0 );

        ResultValueType<CommandBufferState> BeginCommandBuffer( uint32_t id = 0 );
        ResultValueType<CommandBufferState> EndCommandBuffer( uint32_t id = 0 );

    public:
        static ResultValue<CommandPoolState, CommandPool*> Create( vk::Device device,
                                                                   uint32_t graphicsQueueFamilyIndex );
        static ResultValueType<CommandPoolState> Destroy( CommandPool* commandPool );

    public:
        operator VkCommandPool() const { return m_VkCommandPool; }

        operator vk::CommandPool() const { return m_VkCommandPool; }

    private:
        vk::CommandPool m_VkCommandPool;
        std::vector<ResultValue<CommandBufferState, vk::CommandBuffer>> m_VkCommandBuffers;
        vk::Device m_VkDevice;

    };
}// namespace FikoEngine