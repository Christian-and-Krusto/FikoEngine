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
 * GraphicsPipeline class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "GraphicsPipeline.hpp"
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
GraphicsPipeline Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    GraphicsPipeline::~GraphicsPipeline() {}

    Result<GraphicsPipelineStatus> GraphicsPipeline::Init( vk::Device device,
                                                           GraphicsPipelineSpec graphicsPipelineSpec )
    {
        m_GraphicsPipelineSpec = graphicsPipelineSpec;

        vk::DescriptorSetLayoutBinding descriptorSetLayoutBinding( 0, vk::DescriptorType::eUniformBuffer, 1,
                                                                   vk::ShaderStageFlagBits::eVertex );
        auto descriptorSetLayoutStatus = device.createDescriptorSetLayout(
                vk::DescriptorSetLayoutCreateInfo( vk::DescriptorSetLayoutCreateFlags(), descriptorSetLayoutBinding ) );
        if ( vk::Result::eSuccess != descriptorSetLayoutStatus.result )
        {
            LOG_ERROR( "Can Not Create Descriptor Set Layout!" );
            return { GraphicsPipelineStatus::Fail };
        }
        m_DescriptorSetLayout = descriptorSetLayoutStatus.value;

        auto pipelineLayoutStatus = device.createPipelineLayout(
                vk::PipelineLayoutCreateInfo( vk::PipelineLayoutCreateFlags(), m_DescriptorSetLayout ) );
        if ( vk::Result::eSuccess != pipelineLayoutStatus.result )
        {
            LOG_ERROR( "Can Not Create Graphics Pipeline Layout Layout!" );
            return { GraphicsPipelineStatus::Fail };
        }
        m_GraphicsPipelineLayout = pipelineLayoutStatus.value;

        vk::DescriptorPoolSize poolSize( vk::DescriptorType::eUniformBuffer, 1 );
        auto descriptorPoolStatus = device.createDescriptorPool(
                vk::DescriptorPoolCreateInfo( vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, 1, poolSize ) );
        if ( vk::Result::eSuccess != descriptorPoolStatus.result )
        {
            LOG_ERROR( "Can Not Create Descriptor Pool!" );
            return { GraphicsPipelineStatus::Fail };
        }
        m_DescriptorPool = descriptorPoolStatus.value;

        // allocate a descriptor set
        vk::DescriptorSetAllocateInfo descriptorSetAllocateInfo( m_DescriptorPool, m_DescriptorSetLayout );

        auto descriptorSetStatus = device.allocateDescriptorSets( descriptorSetAllocateInfo );
        if ( vk::Result::eSuccess != descriptorSetStatus.result )
        {
            LOG_ERROR( "Can Not Allocate Descriptor Sets!" );
            return { GraphicsPipelineStatus::Fail };
        }
        m_DescriptorSet = descriptorSetStatus.value.front();

        return { GraphicsPipelineStatus::Success };
    }

    Result<GraphicsPipelineStatus> GraphicsPipeline::Update( vk::Device device, UniformBuffer* uniformBuffer )
    {
        auto bufferStatus = uniformBuffer->GetBufferHandle();
        if ( UniformBufferStatus::Success != bufferStatus )
        {
            LOG_ERROR( "Can Not Get UniformBuffer handle!" );
            return { GraphicsPipelineStatus::Fail };
        }
        if ( VK_NULL_HANDLE == m_DescriptorSet )
        {
            LOG_ERROR( "Invalid Discriptor Set!" );
            return { GraphicsPipelineStatus::Fail };
        }

        vk::DescriptorBufferInfo descriptorBufferInfo( bufferStatus.returnValue, 0, uniformBuffer->GetSize() );
        vk::WriteDescriptorSet writeDescriptorSet( m_DescriptorSet, 0, 0, vk::DescriptorType::eUniformBuffer, {},
                                                   descriptorBufferInfo );
        device.updateDescriptorSets( writeDescriptorSet, nullptr );
        return { GraphicsPipelineStatus::Success };
    }

    Result<GraphicsPipelineStatus, GraphicsPipelineSpec> GraphicsPipeline::GetGraphicsPipelineSpec()
    {
        return { {}, m_GraphicsPipelineSpec };
    }

    Result<GraphicsPipelineStatus, vk::Pipeline> GraphicsPipeline::GetGraphicsPipeline()
    {
        if ( VK_NULL_HANDLE != m_GraphicsPipeline ) { return { GraphicsPipelineStatus::Fail }; }
        return { GraphicsPipelineStatus::Success, m_GraphicsPipeline };
    }

    Result<GraphicsPipelineStatus, vk::PipelineLayout> GraphicsPipeline::GetGraphicsPipelineLayout()
    {
        if ( VK_NULL_HANDLE != m_GraphicsPipelineLayout ) { return { GraphicsPipelineStatus::Fail }; }
        return { GraphicsPipelineStatus::Success, m_GraphicsPipelineLayout };
    }

    Result<GraphicsPipelineStatus> GraphicsPipeline::Destroy( vk::Device device )
    {
        if ( VK_NULL_HANDLE != m_DescriptorPool ) { return { GraphicsPipelineStatus::Fail }; }
        if ( VK_NULL_HANDLE != m_DescriptorSet ) { return { GraphicsPipelineStatus::Fail }; }
        
        device.freeDescriptorSets( m_DescriptorPool, m_DescriptorSet );
        device.destroyDescriptorPool( m_DescriptorPool );

        if ( VK_NULL_HANDLE != m_GraphicsPipelineLayout ) { return { GraphicsPipelineStatus::Fail }; }
        device.destroyPipelineLayout( m_GraphicsPipelineLayout );

        if ( VK_NULL_HANDLE != m_DescriptorSetLayout ) { return { GraphicsPipelineStatus::Fail }; }
        device.destroyDescriptorSetLayout( m_DescriptorSetLayout );
        return { GraphicsPipelineStatus::Success };
    }

}// namespace FikoEngine