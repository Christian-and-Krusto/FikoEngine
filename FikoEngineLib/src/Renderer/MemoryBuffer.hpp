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
 * Buffer class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <Core/Result.hpp>
#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class BufferStatus
    {
        Fail,
        CanNotFindMemoryType,
        CanNotAllocateMemory,
        CanNotBindMemory,
        CanNotMapMemory,
        Bound,
        Success
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/
namespace FikoEngine
{
}// namespace FikoEngine

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class MemoryBuffer
    {
    public:
        MemoryBuffer() = default;
        ~MemoryBuffer() = default;

        ResultValueType<BufferStatus> InitMemoryBuffer( vk::PhysicalDevice physicalDevice, vk::Device device,
                                                        vk::PhysicalDeviceMemoryProperties& memoryProperties,
                                                        vk::MemoryRequirements& memoryRequirements,
                                                        vk::MemoryPropertyFlags flags );

        ResultValueType<BufferStatus> BindBuffer( vk::Device device, vk::Buffer buffer );
        ResultValueType<BufferStatus> BindImage( vk::Device device, vk::Image image );

        ResultValueType<BufferStatus> CopyData(vk::Device device,uint8_t* data,size_t size);

        ResultValueType<BufferStatus> DestroyMemoryBuffer( vk::Device device );

        ResultValue<BufferStatus, uint32_t> FindMemoryTypeIndex( vk::PhysicalDeviceMemoryProperties& memoryProperties,
                                                                 vk::MemoryRequirements& memoryRequirements,
                                                                 vk::MemoryPropertyFlags propertyFlags );
        ResultValue<BufferStatus, vk::DeviceMemory>
        AllocateMemory( vk::PhysicalDevice physicalDevice, vk::Device device,
                        vk::PhysicalDeviceMemoryProperties& memoryProperties,
                        vk::MemoryRequirements& memoryRequirements, vk::MemoryPropertyFlags memoryMask );

        const size_t GetBufferSize() const;        
    protected:
        size_t m_BufferSize{};
        vk::DeviceMemory m_BufferMemory{};
    };
}// namespace FikoEngine