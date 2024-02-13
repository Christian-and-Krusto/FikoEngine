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
        auto result = device->createCommandPool(
                vk::CommandPoolCreateInfo( vk::CommandPoolCreateFlags(), graphicsQueueFamilyIndex ) );
        commandPool->m_VkCommandPool = result.value;

        LOG_INFO( "Created Command Pool" );

        commandPool->CreateCommandBuffer();

        return { CommandPoolState::Created, commandPool };
    }

    Result<CommandPoolState> CommandPool::Destroy( CommandPool* commandPool )
    {
        if ( commandPool )
        {
            for ( auto& [ bufferState, buffer ]: commandPool->m_VkCommandBuffers )
            {
                commandPool->m_VkDevice->freeCommandBuffers( commandPool->m_VkCommandPool, buffer );
                bufferState = CommandBufferState::Invalid;
            }
            commandPool->m_VkDevice->destroyCommandPool( *commandPool );
            delete commandPool;

            LOG_INFO( "Destroyed Command Pool" );
            return Result<CommandPoolState>( CommandPoolState::Destroyed );
        }
        return { CommandPoolState::Fail };
    }

    Result<CommandBufferState> CommandPool::CreateCommandBuffer()
    {
        auto buffer = m_VkDevice
                              ->allocateCommandBuffers( vk::CommandBufferAllocateInfo(
                                      m_VkCommandPool, vk::CommandBufferLevel::ePrimary, 1 ) )
                              .value.front();

        m_VkCommandBuffers.emplace_back( std::pair{ CommandBufferState::Initial, buffer } );

        return { CommandBufferState::Created };
    }

    Result<CommandBufferState, vk::CommandBuffer> CommandPool::GetCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }

        return { m_VkCommandBuffers[ id ].first, m_VkCommandBuffers[ id ].second };
    }

    Result<CommandBufferState> CommandPool::BeginCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }

        if ( CommandBufferState::Initial != m_VkCommandBuffers[ id ].first ) { return { CommandBufferState::Invalid }; }

        m_VkCommandBuffers[ id ].second.begin(
                vk::CommandBufferBeginInfo( vk::CommandBufferUsageFlagBits::eOneTimeSubmit ) );
        m_VkCommandBuffers[ id ].first = CommandBufferState::Recording;

        return { CommandBufferState::Recording };
    }

    Result<CommandBufferState> CommandPool::EndCommandBuffer( uint32_t id )
    {
        if ( m_VkCommandBuffers.size() <= id ) { return { CommandBufferState::Invalid }; }
        if ( CommandBufferState::Recording != m_VkCommandBuffers[ id ].first )
        {
            return { CommandBufferState::Invalid };
        }

        m_VkCommandBuffers[ id ].second.end();
        m_VkCommandBuffers[ id ].first = CommandBufferState::Executable;

        return { CommandBufferState::Executable };
    }

}// namespace FikoEngine