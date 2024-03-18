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
 * CommandPool class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "CommandPool.hpp"
#include <Core/Log.hpp>

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Type definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Static variables
***********************************************************************************************************************/

/***********************************************************************************************************************
CommandPool Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{
    ResultValue<CommandPoolState, CommandPool*> CommandPool::Create( vk::Device device,
                                                                     uint32_t graphicsQueueFamilyIndex )
    {


        CommandPool* commandPool = new CommandPool();

        commandPool->m_VkDevice = device;
        auto createInfo = vk::CommandPoolCreateInfo( {}, graphicsQueueFamilyIndex );
        auto result = vkInterface::CreateCommandPool( device, createInfo );

        if ( vk::Result::eSuccess != result )
        {
            LOG_ERROR( "Can Not Create Command Pool!" );
            return { CommandPoolState::Fail, nullptr };
        }

        commandPool->m_VkCommandPool = result.value;
        LOG_INFO( "Created Command Pool" );

        commandPool->CreateCommandBuffer();

        return ResultValue{ CommandPoolState::Created, commandPool };
    }

    ResultValueType<CommandPoolState> CommandPool::Destroy( CommandPool* commandPool )
    {
        if ( commandPool )
        {
            for ( auto& [ bufferState, buffer ]: commandPool->m_VkCommandBuffers )
            {
                vkInterface::FreeCommandBuffers( commandPool->m_VkDevice, commandPool->m_VkCommandPool,1, &buffer );
                bufferState = CommandBufferState::Invalid;
            }
            commandPool->Destroy();
            delete commandPool;

            LOG_INFO( "Destroyed Command Pool" );
            return ResultValueType{ CommandPoolState::Destroyed };
        }
        return ResultValueType{ CommandPoolState::Fail };
    }

    void CommandPool::Destroy()
    {
        vkInterface::DestroyCommandPool( m_VkDevice, m_VkCommandPool );
    }

    ResultValueType<CommandBufferState> CommandPool::CreateCommandBuffer()
    {
        vk::CommandBufferAllocateInfo allocateInfo( m_VkCommandPool, vk::CommandBufferLevel::ePrimary, 1 );
        auto buffers = vkInterface::AllocateCommandBuffers( m_VkDevice, allocateInfo ).value;

        if ( buffers.size() > 0 )
        {
            auto buffer = buffers.front();
            m_VkCommandBuffers.emplace_back( ResultValue{ CommandBufferState::Initial, buffer } );
        }

        return ResultValueType{ CommandBufferState::Created };
    }

    ResultValue<CommandBufferState, vk::CommandBuffer> CommandPool::GetCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id )
        {
            return ResultValue<CommandBufferState, vk::CommandBuffer>{ CommandBufferState::Invalid };
        }

        return ResultValue{ m_VkCommandBuffers[ id ].status, m_VkCommandBuffers[ id ].value };
    }

    ResultValueType<CommandBufferState> CommandPool::BeginCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return ResultValueType{ CommandBufferState::Invalid }; }

        if ( CommandBufferState::Initial != m_VkCommandBuffers[ id ].status )
        {
            return ResultValueType{ CommandBufferState::Invalid };
        }

        auto bufferStatus = vkInterface::Begin(
                m_VkCommandBuffers[ id ].value,
                vk::CommandBufferBeginInfo( vk::CommandBufferUsageFlagBits::eOneTimeSubmit ) );

        if ( vk::Result::eSuccess != bufferStatus ) { return ResultValueType{ CommandBufferState::Invalid }; }


        m_VkCommandBuffers[ id ].status = CommandBufferState::Recording;
        return ResultValueType{ CommandBufferState::Recording };
    }

    ResultValueType<CommandBufferState> CommandPool::EndCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return ResultValueType{ CommandBufferState::Invalid }; }
        if ( CommandBufferState::Recording != m_VkCommandBuffers[ id ].status )
        {
            return ResultValueType{ CommandBufferState::Invalid };
        }

        auto bufferStatus = vkInterface::End( m_VkCommandBuffers[ id ].value );
        if ( vk::Result::eSuccess != bufferStatus ) { return ResultValueType{ CommandBufferState::Invalid }; }

        m_VkCommandBuffers[ id ].status = CommandBufferState::Executable;
        return ResultValueType{ CommandBufferState::Executable };
    }

}// namespace FikoEngine