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
 * GraphicsPipeline class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <Core/Result.hpp>
#include "UniformBuffer.hpp"
#include <vulkan/vulkan.hpp>


/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class GraphicsPipelineStatus
    {
        Fail,
        Success
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    struct GraphicsPipelineSpec {
        vk::Format format;
        vk::Extent2D extent;
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class GraphicsPipeline
    {
    public:
        GraphicsPipeline() = default;
        ~GraphicsPipeline();

    public:
        Result<GraphicsPipelineStatus> Init(vk::Device device, GraphicsPipelineSpec graphicsPipelineSpec );
        Result<GraphicsPipelineStatus> Update(vk::Device device,UniformBuffer* uniformBuffer);

        Result<GraphicsPipelineStatus, vk::Pipeline> GetGraphicsPipeline();
        Result<GraphicsPipelineStatus, vk::PipelineLayout> GetGraphicsPipelineLayout();
        Result<GraphicsPipelineStatus, GraphicsPipelineSpec> GetGraphicsPipelineSpec();
        Result<GraphicsPipelineStatus> Destroy( vk::Device device );

    private:
        vk::Pipeline m_GraphicsPipeline;
        vk::PipelineLayout m_GraphicsPipelineLayout;
        vk::DescriptorSetLayout m_DescriptorSetLayout;
        vk::DescriptorPool m_DescriptorPool;
        vk::DescriptorSet m_DescriptorSet;
        vk::DeviceMemory m_Memory;

        GraphicsPipelineSpec m_GraphicsPipelineSpec;
    };
}// namespace FikoEngine