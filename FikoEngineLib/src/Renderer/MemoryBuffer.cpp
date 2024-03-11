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
 * MemoryBuffer class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "MemoryBuffer.hpp"
#include <Core/Log.hpp>
#include <Core/VulkanInterface.hpp>

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
MemoryBuffer Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    ResultValueType<BufferStatus> MemoryBuffer::InitMemoryBuffer( vk::PhysicalDevice physicalDevice, vk::Device device,
                                                                  vk::PhysicalDeviceMemoryProperties& memoryProperties,
                                                                  vk::MemoryRequirements& memoryRequirements,
                                                                  vk::MemoryPropertyFlags flags )
    {
        if ( memoryRequirements.size <= 0 ) { return { BufferStatus::CanNotAllocateMemory }; }

        auto allocationStatus =
                AllocateMemory( physicalDevice, device, memoryProperties, memoryRequirements, flags );
        if ( BufferStatus::Success != allocationStatus ) { return { allocationStatus.status }; }

        m_BufferSize = memoryRequirements.size;

        return ResultValueType<BufferStatus>{ BufferStatus::Success };
    }

    ResultValueType<BufferStatus> MemoryBuffer::BindBuffer( vk::Device device, vk::Buffer buffer )
    {
        auto bindStatus = vkInterface::BindBufferMemory( device, buffer, m_BufferMemory, 0 );
        if ( vk::Result::eSuccess != bindStatus )
        {
            LOG_ERROR( "Can Not Bind Buffer Memory!" );
            return ResultValueType{ BufferStatus::CanNotBindMemory };
        }
        return ResultValueType<BufferStatus>{ BufferStatus::Bound };
    }

    ResultValueType<BufferStatus> MemoryBuffer::BindImage( vk::Device device, vk::Image image )
    {
        auto bindStatus = vkInterface::BindImageMemory( device, image, m_BufferMemory, 0 );
        if ( vk::Result::eSuccess != bindStatus )
        {
            LOG_ERROR( "Can Not Bind Image Memory!" );
            return ResultValueType{ BufferStatus::CanNotBindMemory };
        }
        return ResultValueType<BufferStatus>{ BufferStatus::Bound };
    }

    ResultValueType<BufferStatus> MemoryBuffer::CopyData( vk::Device device, uint8_t* data, size_t size )
    {
        if ( size > m_BufferSize ) { return { BufferStatus::Fail }; }

        auto mapMemoryStatus = vkInterface::MapMemory( device, m_BufferMemory, 0, size, {} );
        if ( vk::Result::eSuccess != mapMemoryStatus )
        {
            LOG_ERROR( "Can Not Map Buffer Memory!" );
            return ResultValueType{ BufferStatus::CanNotMapMemory };
        }

        uint8_t* pData = static_cast<uint8_t*>( mapMemoryStatus.value );
        memcpy( pData, &data, size );
        vkInterface::UnmapMemory( device, m_BufferMemory );

        return ResultValueType<BufferStatus>{ BufferStatus::Success };
    }

    ResultValueType<BufferStatus> MemoryBuffer::DestroyMemoryBuffer( vk::Device device )
    {
        if ( VK_NULL_HANDLE != m_BufferMemory ) { return ResultValueType{ BufferStatus::Fail }; }
        device.freeMemory( m_BufferMemory );

        return ResultValueType{ BufferStatus::Success };
    }

    ResultValue<BufferStatus, uint32_t>
    MemoryBuffer::FindMemoryTypeIndex( vk::PhysicalDeviceMemoryProperties& memoryProperties,
                                       vk::MemoryRequirements& memoryRequirements,
                                       vk::MemoryPropertyFlags propertyFlags )
    {
        uint32_t typeBits = memoryRequirements.memoryTypeBits;
        uint32_t typeIndex = uint32_t( ~0 );
        for ( uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++ )
        {
            if ( ( typeBits & 1 ) &&
                 ( ( memoryProperties.memoryTypes[ i ].propertyFlags & propertyFlags ) == propertyFlags ) )
            {
                typeIndex = i;
                break;
            }
            typeBits >>= 1;
        }

        if ( typeIndex == uint32_t( ~0 ) )
        {
            LOG_ERROR( "Can Not Find Correct Memory Type" );
            return ResultValue<BufferStatus, uint32_t>{ BufferStatus::CanNotFindMemoryType, 0 };
        }
        return ResultValue<BufferStatus, uint32_t>{ BufferStatus::Success, typeIndex };
    }

    ResultValue<BufferStatus, vk::DeviceMemory>
    MemoryBuffer::AllocateMemory( vk::PhysicalDevice physicalDevice, vk::Device device,
                                  vk::PhysicalDeviceMemoryProperties& memoryProperties,
                                  vk::MemoryRequirements& memoryRequirements, vk::MemoryPropertyFlags memoryMask )
    {
        auto typeIndex =
                FindMemoryTypeIndex( memoryProperties, memoryRequirements, vk::MemoryPropertyFlagBits::eDeviceLocal );
        if ( BufferStatus::Success != typeIndex )
        {
            return ResultValue<BufferStatus, vk::DeviceMemory>{ typeIndex.status };
        }

        vk::MemoryAllocateInfo memoryAllocateInfo( memoryRequirements.size, typeIndex );
        auto memory = vkInterface::AllocateMemory( device, memoryAllocateInfo );

        if ( vk::Result::eSuccess != memory )
        {
            LOG_ERROR( "Can Not Allocate Image Memory!" );
            return ResultValue<BufferStatus, vk::DeviceMemory>{ BufferStatus::CanNotAllocateMemory };
        }

        return ResultValue<BufferStatus, vk::DeviceMemory>{ BufferStatus::Success, memory };
    }

    const size_t MemoryBuffer::GetBufferSize() const { return m_BufferSize; }

}// namespace FikoEngine