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
    Result<CommandPoolState, CommandPool*> CommandPool::Create( vk::Device* device, uint32_t graphicsQueueFamilyIndex )
    {
        CommandPool* commandPool = new CommandPool();

        commandPool->m_VkDevice = device;
        auto result = vkInterface::CreateCommandPool( device, graphicsQueueFamilyIndex );

        if ( vk::Result::eSuccess != result.result )
        {
            LOG_ERROR( "Can Not Create Command Pool!" );
            return { CommandPoolState::Fail, nullptr };
        }

        commandPool->m_VkCommandPool = result.value;
        LOG_INFO( "Created Command Pool" );

        commandPool->CreateCommandBuffer();

        return { CommandPoolState::Created, commandPool };
    }

    Result<CommandPoolState> CommandPool::Destroy( CommandPool* commandPool )
    {
        if ( commandPool )
        {
            LOG_INFO(commandPool->m_VkCommandBuffers.size());
            for ( auto& [ bufferState, buffer ]: commandPool->m_VkCommandBuffers )
            {
                vkInterface::FreeCommandBuffers( commandPool->m_VkDevice, commandPool->m_VkCommandPool, buffer );
                bufferState = CommandBufferState::Invalid;
            }
            vkInterface::DestroyCommandPool( commandPool->m_VkDevice, *commandPool );
            delete commandPool;

            LOG_INFO( "Destroyed Command Pool" );
            return Result<CommandPoolState>( CommandPoolState::Destroyed );
        }
        return { CommandPoolState::Fail };
    }

    Result<CommandBufferState> CommandPool::CreateCommandBuffer()
    {
        vk::CommandBufferAllocateInfo allocateInfo( m_VkCommandPool, vk::CommandBufferLevel::ePrimary, 1 );
        auto buffers = vkInterface::AllocateCommandBuffers( m_VkDevice, allocateInfo ).value;
        auto buffer = buffers.front();

        m_VkCommandBuffers.emplace_back( Result{ CommandBufferState::Initial, buffer } );

        return { CommandBufferState::Created };
    }

    Result<CommandBufferState, vk::CommandBuffer> CommandPool::GetCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }

        return { m_VkCommandBuffers[ id ].status, m_VkCommandBuffers[ id ].returnValue };
    }

    Result<CommandBufferState> CommandPool::BeginCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }

        if ( CommandBufferState::Initial != m_VkCommandBuffers[ id ].status ) { return { CommandBufferState::Invalid }; }

        auto bufferStatus = m_VkCommandBuffers[ id ].returnValue.begin(
                vk::CommandBufferBeginInfo( vk::CommandBufferUsageFlagBits::eOneTimeSubmit ) );

        if ( vk::Result::eSuccess != bufferStatus ) { return { CommandBufferState::Invalid }; }

        m_VkCommandBuffers[ id ].status = CommandBufferState::Recording;
        return { CommandBufferState::Recording };
    }

    Result<CommandBufferState> CommandPool::EndCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }
        if ( CommandBufferState::Recording != m_VkCommandBuffers[ id ].status )
        {
            return { CommandBufferState::Invalid };
        }

        auto bufferStatus = m_VkCommandBuffers[ id ].returnValue.end();
        if ( vk::Result::eSuccess != bufferStatus ) { return { CommandBufferState::Invalid }; }

        m_VkCommandBuffers[ id ].status = CommandBufferState::Executable;
        return { CommandBufferState::Executable };
    }

}// namespace FikoEngine