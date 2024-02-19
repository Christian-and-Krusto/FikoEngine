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
 * UniformBuffer class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "UniformBuffer.hpp"
#include <Core/Log.hpp>
#include <vulkan/vulkan.hpp>

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
UniformBuffer Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{
    Result<UniformBufferStatus> UniformBuffer::Init( vk::PhysicalDevice physicalDevice, vk::Device device,
                                                     uint32_t size, uint8_t* data )
    {
        m_Size = size;
        auto uniformDataBufferStatus = device.createBuffer(
                vk::BufferCreateInfo( vk::BufferCreateFlags(), size, vk::BufferUsageFlagBits::eUniformBuffer ) );
        if ( vk::Result::eSuccess != uniformDataBufferStatus.result )
        {
            LOG_ERROR( "Can Not Create Uniform Buffer!" );
            return { UniformBufferStatus::Fail };
        }
        m_Buffer = uniformDataBufferStatus.value;

        auto memoryProperties = physicalDevice.getMemoryProperties();
        auto memoryRequirements = device.getBufferMemoryRequirements( m_Buffer );
        auto memoryMask = ( vk::MemoryPropertyFlagBits::eHostVisible | vk::MemoryPropertyFlagBits::eHostCoherent );

        uint32_t typeIndex = uint32_t( ~0 );
        for ( uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++ )
        {
            if ( ( memoryRequirements.memoryTypeBits & 1 ) &&
                 ( ( memoryProperties.memoryTypes[ i ].propertyFlags & memoryMask ) == memoryMask ) )
            {
                typeIndex = i;
                break;
            }
            memoryRequirements.memoryTypeBits >>= 1;
        }

        if ( typeIndex == uint32_t( ~0 ) )
        {
            LOG_ERROR( "Can Not Find Right Memory Type!" );
            return { UniformBufferStatus::Fail };
        }
        auto uniformDataMemoryStatus =
                device.allocateMemory( vk::MemoryAllocateInfo( memoryRequirements.size, typeIndex ) );

        if ( vk::Result::eSuccess != uniformDataMemoryStatus.result )
        {
            LOG_ERROR( "Can Not Allocate Uniform Buffer Memory!" );
            return { UniformBufferStatus::Fail };
        }
        m_BufferMemory = uniformDataMemoryStatus.value;
        if ( size > 0 )
        {
            auto mapMemoryStatus = device.mapMemory( m_BufferMemory, 0, memoryRequirements.size );
            if ( vk::Result::eSuccess != uniformDataMemoryStatus.result )
            {
                LOG_ERROR( "Can Not Map Uniform Buffer Memory!" );
                return { UniformBufferStatus::Fail };
            }
            uint8_t* pData = static_cast<uint8_t*>( mapMemoryStatus.value );
            memcpy( pData, &data, size );
            device.unmapMemory( m_BufferMemory );

            auto bindStatus = device.bindBufferMemory( m_Buffer, m_BufferMemory, 0 );
            if ( vk::Result::eSuccess != bindStatus )
            {
                LOG_ERROR( "Can Not Bind Uniform Buffer Memory!" );
                return { UniformBufferStatus::Fail };
            }
        }

        return {UniformBufferStatus::Success};
    }

    Result<UniformBufferStatus, vk::Buffer> UniformBuffer::GetBufferHandle()
    {
        if(VK_NULL_HANDLE == m_Buffer)
        {
            return {UniformBufferStatus::Fail};
        }
        return {UniformBufferStatus::Success,m_Buffer};
    }

    Result<UniformBufferStatus> UniformBuffer::Destroy( vk::Device device ) {
        if ( VK_NULL_HANDLE == m_Buffer ) { return { UniformBufferStatus::Fail }; }
        device.destroyBuffer( m_Buffer );
        if ( VK_NULL_HANDLE == m_BufferMemory ) { return { UniformBufferStatus::Fail }; }
        device.freeMemory( m_BufferMemory );

        return { UniformBufferStatus::Success }; 
    }

    const size_t UniformBuffer::GetSize() const{ return m_Size; }


}// namespace FikoEngine