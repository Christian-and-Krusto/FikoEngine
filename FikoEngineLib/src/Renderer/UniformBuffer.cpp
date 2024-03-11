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
UniformBuffer Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{
    ResultValueType<BufferStatus> UniformBuffer::Init( vk::PhysicalDevice physicalDevice, vk::Device device,
                                                       uint32_t size, uint8_t* data )
    {
        auto uniformDataBufferStatus =
                vkInterface::CreateBuffer( device, vk::BufferCreateInfo( vk::BufferCreateFlags(), size,
                                                                         vk::BufferUsageFlagBits::eUniformBuffer ) );
        if ( vk::Result::eSuccess != uniformDataBufferStatus )
        {
            LOG_ERROR( "Can Not Create Uniform Buffer!" );
            return ResultValueType{ BufferStatus::Fail };
        }
        m_Buffer = uniformDataBufferStatus.value;

        auto memoryProperties = vkInterface::GetMemoryProperties( physicalDevice ).value;
        auto memoryRequirements = vkInterface::GetBufferMemoryRequirements( device, m_Buffer ).value;

        auto allocateBufferStatus = InitMemoryBuffer(
                physicalDevice, device, memoryProperties, memoryRequirements,
                ( vk::MemoryPropertyFlagBits::eHostVisible | vk::MemoryPropertyFlagBits::eHostCoherent ) );

        if ( BufferStatus::Success != allocateBufferStatus ) { return allocateBufferStatus; }

        auto copyStatus = CopyData( device, data, size );
        if ( BufferStatus::Success != copyStatus ) { return copyStatus; }

        auto bindStatus = BindBuffer( device, m_Buffer );
        if ( BufferStatus::Bound != bindStatus ) { return bindStatus; }

        return ResultValueType{ BufferStatus::Success };
    }

    ResultValue<BufferStatus, vk::Buffer> UniformBuffer::GetBufferHandle()
    {
        if ( VK_NULL_HANDLE == m_Buffer )
        {
            return ResultValue<BufferStatus, vk::Buffer>{ BufferStatus::Fail, VK_NULL_HANDLE };
        }
        return ResultValue<BufferStatus, vk::Buffer>{ BufferStatus::Success, m_Buffer };
    }

    ResultValueType<BufferStatus> UniformBuffer::Destroy( vk::Device device )
    {
        if ( VK_NULL_HANDLE == m_Buffer ) { return ResultValueType{ BufferStatus::Fail }; }
        device.destroyBuffer( m_Buffer );

        return DestroyMemoryBuffer( device );
    }

    const size_t UniformBuffer::GetSize() const { return m_Size; }


}// namespace FikoEngine