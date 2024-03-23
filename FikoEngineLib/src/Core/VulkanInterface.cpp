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
 * VulkanInterface class definition
 */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "VulkanInterface.hpp"
#include <vector>
#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_to_string.hpp>

/***********************************************************************************************************************
// clang-format off
***********************************************************************************************************************/

/***********************************************************************************************************************
Enum Class implementation
***********************************************************************************************************************/

/***********************************************************************************************************************
Struct implementation
***********************************************************************************************************************/

/***********************************************************************************************************************
Class implementation
***********************************************************************************************************************/

namespace FikoEngine
{


    ResultValueType<vk::Result> vkInterface::Begin( vk::CommandBuffer commandBuffer, const vk::CommandBufferBeginInfo pBeginInfo )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = commandBuffer.begin( pBeginInfo );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_Begin( commandBuffer, &pBeginInfo );
#endif
    }

    ResultValueType<vk::Result> vkInterface::End( vk::CommandBuffer commandBuffer )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = commandBuffer.end();
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_End( commandBuffer );
#endif
    }

    ResultValueType<vk::Result> vkInterface::Reset( vk::CommandBuffer commandBuffer, vk::CommandBufferResetFlags flags )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = commandBuffer.reset( flags );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_Reset( commandBuffer, flags );
#endif
    }

//     void vkInterface::BindPipeline( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::Pipeline pipeline )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindPipeline( pipelineBindPoint, pipeline );
// #else
//         s_MockPtr->_BindPipeline( commandBuffer, pipelineBindPoint, pipeline );
// #endif
//     }

//     void vkInterface::SetViewport( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const vk::Viewport* pViewports )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewport( firstViewport, viewportCount, pViewports );
// #else
//         s_MockPtr->_SetViewport( commandBuffer, firstViewport, viewportCount, pViewports );
// #endif
//     }

//     void vkInterface::SetScissor( vk::CommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount, const vk::Rect2D* pScissors )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setScissor( firstScissor, scissorCount, pScissors );
// #else
//         s_MockPtr->_SetScissor( commandBuffer, firstScissor, scissorCount, pScissors );
// #endif
//     }

//     void vkInterface::SetLineWidth( vk::CommandBuffer commandBuffer, float lineWidth )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLineWidth( lineWidth );
// #else
//         s_MockPtr->_SetLineWidth( commandBuffer, lineWidth );
// #endif
//     }

//     void vkInterface::SetDepthBias( vk::CommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBias( depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor );
// #else
//         s_MockPtr->_SetDepthBias( commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor );
// #endif
//     }

//     void vkInterface::SetBlendConstants( vk::CommandBuffer commandBuffer, const float blendConstants[ 4 ] )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setBlendConstants( blendConstants );
// #else
//         s_MockPtr->_SetBlendConstants( commandBuffer, blendConstants );
// #endif
//     }

//     void vkInterface::SetDepthBounds( vk::CommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBounds( minDepthBounds, maxDepthBounds );
// #else
//         s_MockPtr->_SetDepthBounds( commandBuffer, minDepthBounds, maxDepthBounds );
// #endif
//     }

//     void vkInterface::SetStencilCompareMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, uint32_t compareMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilCompareMask( faceMask, compareMask );
// #else
//         s_MockPtr->_SetStencilCompareMask( commandBuffer, faceMask, compareMask );
// #endif
//     }

//     void vkInterface::SetStencilWriteMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, uint32_t writeMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilWriteMask( faceMask, writeMask );
// #else
//         s_MockPtr->_SetStencilWriteMask( commandBuffer, faceMask, writeMask );
// #endif
//     }

//     void vkInterface::SetStencilReference( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, uint32_t reference )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilReference( faceMask, reference );
// #else
//         s_MockPtr->_SetStencilReference( commandBuffer, faceMask, reference );
// #endif
//     }

//     void vkInterface::BindDescriptorSets( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount, const vk::DescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount, const uint32_t* pDynamicOffsets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindDescriptorSets( pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets );
// #else
//         s_MockPtr->_BindDescriptorSets( commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets );
// #endif
//     }

//     void vkInterface::BindIndexBuffer( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::IndexType indexType )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindIndexBuffer( buffer, offset, indexType );
// #else
//         s_MockPtr->_BindIndexBuffer( commandBuffer, buffer, offset, indexType );
// #endif
//     }

//     void vkInterface::BindVertexBuffers( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindVertexBuffers( firstBinding, bindingCount, pBuffers, pOffsets );
// #else
//         s_MockPtr->_BindVertexBuffers( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets );
// #endif
//     }

//     void vkInterface::Draw( vk::CommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.draw( vertexCount, instanceCount, firstVertex, firstInstance );
// #else
//         s_MockPtr->_Draw( commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance );
// #endif
//     }

//     void vkInterface::DrawIndexed( vk::CommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndexed( indexCount, instanceCount, firstIndex, vertexOffset, firstInstance );
// #else
//         s_MockPtr->_DrawIndexed( commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance );
// #endif
//     }

//     void vkInterface::DrawIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, uint32_t drawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndirect( buffer, offset, drawCount, stride );
// #else
//         s_MockPtr->_DrawIndirect( commandBuffer, buffer, offset, drawCount, stride );
// #endif
//     }

//     void vkInterface::DrawIndexedIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, uint32_t drawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndexedIndirect( buffer, offset, drawCount, stride );
// #else
//         s_MockPtr->_DrawIndexedIndirect( commandBuffer, buffer, offset, drawCount, stride );
// #endif
//     }

//     void vkInterface::Dispatch( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.dispatch( groupCountX, groupCountY, groupCountZ );
// #else
//         s_MockPtr->_Dispatch( commandBuffer, groupCountX, groupCountY, groupCountZ );
// #endif
//     }

//     void vkInterface::DispatchIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.dispatchIndirect( buffer, offset );
// #else
//         s_MockPtr->_DispatchIndirect( commandBuffer, buffer, offset );
// #endif
//     }

//     void vkInterface::CopyBuffer( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Buffer dstBuffer, uint32_t regionCount, const vk::BufferCopy* pRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBuffer( srcBuffer, dstBuffer, regionCount, pRegions );
// #else
//         s_MockPtr->_CopyBuffer( commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions );
// #endif
//     }

//     void vkInterface::CopyImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout, vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount, const vk::ImageCopy* pRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
// #else
//         s_MockPtr->_CopyImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
// #endif
//     }

//     void vkInterface::BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout, vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount, const vk::ImageBlit* pRegions, vk::Filter filter )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.blitImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter );
// #else
//         s_MockPtr->_BlitImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter );
// #endif
//     }

//     void vkInterface::CopyBufferToImage( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount, const vk::BufferImageCopy* pRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBufferToImage( srcBuffer, dstImage, dstImageLayout, regionCount, pRegions );
// #else
//         s_MockPtr->_CopyBufferToImage( commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions );
// #endif
//     }

//     void vkInterface::CopyImageToBuffer( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout, vk::Buffer dstBuffer, uint32_t regionCount, const vk::BufferImageCopy* pRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImageToBuffer( srcImage, srcImageLayout, dstBuffer, regionCount, pRegions );
// #else
//         s_MockPtr->_CopyImageToBuffer( commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions );
// #endif
//     }

//     void vkInterface::UpdateBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset, vk::DeviceSize dataSize, const void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.updateBuffer( dstBuffer, dstOffset, dataSize, pData );
// #else
//         s_MockPtr->_UpdateBuffer( commandBuffer, dstBuffer, dstOffset, dataSize, pData );
// #endif
//     }

//     void vkInterface::FillBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset, vk::DeviceSize size, uint32_t data )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.fillBuffer( dstBuffer, dstOffset, size, data );
// #else
//         s_MockPtr->_FillBuffer( commandBuffer, dstBuffer, dstOffset, size, data );
// #endif
//     }

//     void vkInterface::ClearColorImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout, const vk::ClearColorValue* pColor, uint32_t rangeCount, const vk::ImageSubresourceRange* pRanges )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.clearColorImage( image, imageLayout, pColor, rangeCount, pRanges );
// #else
//         s_MockPtr->_ClearColorImage( commandBuffer, image, imageLayout, pColor, rangeCount, pRanges );
// #endif
//     }

//     void vkInterface::ClearDepthStencilImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout, const vk::ClearDepthStencilValue* pDepthStencil, uint32_t rangeCount, const vk::ImageSubresourceRange* pRanges )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.clearDepthStencilImage( image, imageLayout, pDepthStencil, rangeCount, pRanges );
// #else
//         s_MockPtr->_ClearDepthStencilImage( commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges );
// #endif
//     }

//     void vkInterface::ClearAttachments( vk::CommandBuffer commandBuffer, uint32_t attachmentCount, const vk::ClearAttachment* pAttachments, uint32_t rectCount, const vk::ClearRect* pRects )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.clearAttachments( attachmentCount, pAttachments, rectCount, pRects );
// #else
//         s_MockPtr->_ClearAttachments( commandBuffer, attachmentCount, pAttachments, rectCount, pRects );
// #endif
//     }

//     void vkInterface::ResolveImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout, vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount, const vk::ImageResolve* pRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resolveImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
// #else
//         s_MockPtr->_ResolveImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
// #endif
//     }

//     void vkInterface::SetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setEvent( event, stageMask );
// #else
//         s_MockPtr->_SetEvent( commandBuffer, event, stageMask );
// #endif
//     }

//     void vkInterface::ResetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resetEvent( event, stageMask );
// #else
//         s_MockPtr->_ResetEvent( commandBuffer, event, stageMask );
// #endif
//     }

//     void vkInterface::WaitEvents( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents, vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask, uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
//                                   const vk::BufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const vk::ImageMemoryBarrier* pImageMemoryBarriers )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.waitEvents( eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers );
// #else
//         s_MockPtr->_WaitEvents( commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers );
// #endif
//     }

//     void vkInterface::PipelineBarrier( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask, vk::DependencyFlags dependencyFlags, uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
//                                        const vk::BufferMemoryBarrier* pBufferMemoryBarriers, uint32_t imageMemoryBarrierCount, const vk::ImageMemoryBarrier* pImageMemoryBarriers )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pipelineBarrier( srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers );
// #else
//         s_MockPtr->_PipelineBarrier( commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers );
// #endif
//     }

//     void vkInterface::BeginQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query, vk::QueryControlFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginQuery( queryPool, query, flags );
// #else
//         s_MockPtr->_BeginQuery( commandBuffer, queryPool, query, flags );
// #endif
//     }

//     void vkInterface::EndQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endQuery( queryPool, query );
// #else
//         s_MockPtr->_EndQuery( commandBuffer, queryPool, query );
// #endif
//     }

//     void vkInterface::ResetQueryPool( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resetQueryPool( queryPool, firstQuery, queryCount );
// #else
//         s_MockPtr->_ResetQueryPool( commandBuffer, queryPool, firstQuery, queryCount );
// #endif
//     }

//     void vkInterface::WriteTimestamp( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage, vk::QueryPool queryPool, uint32_t query )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeTimestamp( pipelineStage, queryPool, query );
// #else
//         s_MockPtr->_WriteTimestamp( commandBuffer, pipelineStage, queryPool, query );
// #endif
//     }

//     void vkInterface::CopyQueryPoolResults( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, vk::Buffer dstBuffer, vk::DeviceSize dstOffset, vk::DeviceSize stride, vk::QueryResultFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyQueryPoolResults( queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags );
// #else
//         s_MockPtr->_CopyQueryPoolResults( commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags );
// #endif
//     }

//     void vkInterface::PushConstants( vk::CommandBuffer commandBuffer, vk::PipelineLayout layout, vk::ShaderStageFlags stageFlags, uint32_t offset, uint32_t size, const void* pValues )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pushConstants( layout, stageFlags, offset, size, pValues );
// #else
//         s_MockPtr->_PushConstants( commandBuffer, layout, stageFlags, offset, size, pValues );
// #endif
//     }

//     void vkInterface::BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin, vk::SubpassContents contents )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginRenderPass( pRenderPassBegin, contents );
// #else
//         s_MockPtr->_BeginRenderPass( commandBuffer, pRenderPassBegin, contents );
// #endif
//     }


//     void vkInterface::NextSubpass( vk::CommandBuffer commandBuffer, vk::SubpassContents contents )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.nextSubpass( contents );
// #else
//         s_MockPtr->_NextSubpass( commandBuffer, contents );
// #endif
//     }

//     void vkInterface::EndRenderPass( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endRenderPass();
// #else
//         s_MockPtr->_EndRenderPass( commandBuffer );
// #endif
//     }

//     void vkInterface::ExecuteCommands( vk::CommandBuffer commandBuffer, uint32_t commandBufferCount, const vk::CommandBuffer* pCommandBuffers )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.executeCommands( commandBufferCount, pCommandBuffers );
// #else
//         s_MockPtr->_ExecuteCommands( commandBuffer, commandBufferCount, pCommandBuffers );
// #endif
//     }

//     void vkInterface::SetDeviceMask( vk::CommandBuffer commandBuffer, uint32_t deviceMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDeviceMask( deviceMask );
// #else
//         s_MockPtr->_SetDeviceMask( commandBuffer, deviceMask );
// #endif
//     }

//     void vkInterface::DispatchBase( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.dispatchBase( baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
// #else
//         s_MockPtr->_DispatchBase( commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
// #endif
//     }

//     void vkInterface::DrawIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndirectCount( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndirectCount( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::DrawIndexedIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndexedIndirectCount( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndexedIndirectCount( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::BeginRenderPass2( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin, const vk::SubpassBeginInfo* pSubpassBeginInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginRenderPass2( pRenderPassBegin, pSubpassBeginInfo );
// #else
//         s_MockPtr->_BeginRenderPass2( commandBuffer, pRenderPassBegin, pSubpassBeginInfo );
// #endif
//     }

//     void vkInterface::NextSubpass2( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo, const vk::SubpassEndInfo* pSubpassEndInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.nextSubpass2( pSubpassBeginInfo, pSubpassEndInfo );
// #else
//         s_MockPtr->_NextSubpass2( commandBuffer, pSubpassBeginInfo, pSubpassEndInfo );
// #endif
//     }

//     void vkInterface::EndRenderPass2( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endRenderPass2( pSubpassEndInfo );
// #else
//         s_MockPtr->_EndRenderPass2( commandBuffer, pSubpassEndInfo );
// #endif
//     }

//     void vkInterface::SetEvent2( vk::CommandBuffer commandBuffer, vk::Event event, const vk::DependencyInfo* pDependencyInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setEvent2( event, pDependencyInfo );
// #else
//         s_MockPtr->_SetEvent2( commandBuffer, event, pDependencyInfo );
// #endif
//     }

//     void vkInterface::ResetEvent2( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags2 stageMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resetEvent2( event, stageMask );
// #else
//         s_MockPtr->_ResetEvent2( commandBuffer, event, stageMask );
// #endif
//     }

//     void vkInterface::WaitEvents2( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents, const vk::DependencyInfo* pDependencyInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.waitEvents2( eventCount, pEvents, pDependencyInfos );
// #else
//         s_MockPtr->_WaitEvents2( commandBuffer, eventCount, pEvents, pDependencyInfos );
// #endif
//     }

//     void vkInterface::PipelineBarrier2( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pipelineBarrier2( pDependencyInfo );
// #else
//         s_MockPtr->_PipelineBarrier2( commandBuffer, pDependencyInfo );
// #endif
//     }

//     void vkInterface::WriteTimestamp2( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::QueryPool queryPool, uint32_t query )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeTimestamp2( stage, queryPool, query );
// #else
//         s_MockPtr->_WriteTimestamp2( commandBuffer, stage, queryPool, query );
// #endif
//     }

//     void vkInterface::CopyBuffer2( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBuffer2( pCopyBufferInfo );
// #else
//         s_MockPtr->_CopyBuffer2( commandBuffer, pCopyBufferInfo );
// #endif
//     }

//     void vkInterface::CopyImage2( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImage2( pCopyImageInfo );
// #else
//         s_MockPtr->_CopyImage2( commandBuffer, pCopyImageInfo );
// #endif
//     }

//     void vkInterface::CopyBufferToImage2( vk::CommandBuffer commandBuffer, const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBufferToImage2( pCopyBufferToImageInfo );
// #else
//         s_MockPtr->_CopyBufferToImage2( commandBuffer, pCopyBufferToImageInfo );
// #endif
//     }

//     void vkInterface::CopyImageToBuffer2( vk::CommandBuffer commandBuffer, const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImageToBuffer2( pCopyImageToBufferInfo );
// #else
//         s_MockPtr->_CopyImageToBuffer2( commandBuffer, pCopyImageToBufferInfo );
// #endif
//     }

//     void vkInterface::BlitImage2( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.blitImage2( pBlitImageInfo );
// #else
//         s_MockPtr->_BlitImage2( commandBuffer, pBlitImageInfo );
// #endif
//     }

//     void vkInterface::ResolveImage2( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resolveImage2( pResolveImageInfo );
// #else
//         s_MockPtr->_ResolveImage2( commandBuffer, pResolveImageInfo );
// #endif
//     }

//     void vkInterface::BeginRendering( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginRendering( pRenderingInfo );
// #else
//         s_MockPtr->_BeginRendering( commandBuffer, pRenderingInfo );
// #endif
//     }

//     void vkInterface::EndRendering( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endRendering();
// #else
//         s_MockPtr->_EndRendering( commandBuffer );
// #endif
//     }

//     void vkInterface::SetCullMode( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCullMode( cullMode );
// #else
//         s_MockPtr->_SetCullMode( commandBuffer, cullMode );
// #endif
//     }

//     void vkInterface::SetFrontFace( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setFrontFace( frontFace );
// #else
//         s_MockPtr->_SetFrontFace( commandBuffer, frontFace );
// #endif
//     }

//     void vkInterface::SetPrimitiveTopology( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPrimitiveTopology( primitiveTopology );
// #else
//         s_MockPtr->_SetPrimitiveTopology( commandBuffer, primitiveTopology );
// #endif
//     }

//     void vkInterface::SetViewportWithCount( vk::CommandBuffer commandBuffer, uint32_t viewportCount, const vk::Viewport* pViewports )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportWithCount( viewportCount, pViewports );
// #else
//         s_MockPtr->_SetViewportWithCount( commandBuffer, viewportCount, pViewports );
// #endif
//     }

//     void vkInterface::SetScissorWithCount( vk::CommandBuffer commandBuffer, uint32_t scissorCount, const vk::Rect2D* pScissors )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setScissorWithCount( scissorCount, pScissors );
// #else
//         s_MockPtr->_SetScissorWithCount( commandBuffer, scissorCount, pScissors );
// #endif
//     }

//     void vkInterface::BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindVertexBuffers2( firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
// #else
//         s_MockPtr->_BindVertexBuffers2( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
// #endif
//     }


//     void vkInterface::SetDepthTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthTestEnable( depthTestEnable );
// #else
//         s_MockPtr->_SetDepthTestEnable( commandBuffer, depthTestEnable );
// #endif
//     }

//     void vkInterface::SetDepthWriteEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthWriteEnable( depthWriteEnable );
// #else
//         s_MockPtr->_SetDepthWriteEnable( commandBuffer, depthWriteEnable );
// #endif
//     }

//     void vkInterface::SetDepthCompareOp( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthCompareOp( depthCompareOp );
// #else
//         s_MockPtr->_SetDepthCompareOp( commandBuffer, depthCompareOp );
// #endif
//     }

//     void vkInterface::SetDepthBoundsTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBoundsTestEnable( depthBoundsTestEnable );
// #else
//         s_MockPtr->_SetDepthBoundsTestEnable( commandBuffer, depthBoundsTestEnable );
// #endif
//     }

//     void vkInterface::SetStencilTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilTestEnable( stencilTestEnable );
// #else
//         s_MockPtr->_SetStencilTestEnable( commandBuffer, stencilTestEnable );
// #endif
//     }

//     void vkInterface::SetStencilOp( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, vk::StencilOp failOp, vk::StencilOp passOp, vk::StencilOp depthFailOp, vk::CompareOp compareOp )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilOp( faceMask, failOp, passOp, depthFailOp, compareOp );
// #else
//         s_MockPtr->_SetStencilOp( commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp );
// #endif
//     }

//     void vkInterface::SetRasterizerDiscardEnable( vk::CommandBuffer commandBuffer, vk::Bool32 rasterizerDiscardEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRasterizerDiscardEnable( rasterizerDiscardEnable );
// #else
//         s_MockPtr->_SetRasterizerDiscardEnable( commandBuffer, rasterizerDiscardEnable );
// #endif
//     }

//     void vkInterface::SetDepthBiasEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBiasEnable( depthBiasEnable );
// #else
//         s_MockPtr->_SetDepthBiasEnable( commandBuffer, depthBiasEnable );
// #endif
//     }

//     void vkInterface::SetPrimitiveRestartEnable( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPrimitiveRestartEnable( primitiveRestartEnable );
// #else
//         s_MockPtr->_SetPrimitiveRestartEnable( commandBuffer, primitiveRestartEnable );
// #endif
//     }

//     void vkInterface::DebugMarkerBeginEXT( vk::CommandBuffer commandBuffer, const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.debugMarkerBeginEXT( pMarkerInfo );
// #else
//         s_MockPtr->_DebugMarkerBeginEXT( commandBuffer, pMarkerInfo );
// #endif
//     }

//     void vkInterface::DebugMarkerEndEXT( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.debugMarkerEndEXT();
// #else
//         s_MockPtr->_DebugMarkerEndEXT( commandBuffer );
// #endif
//     }

//     void vkInterface::DebugMarkerInsertEXT( vk::CommandBuffer commandBuffer, const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.debugMarkerInsertEXT( pMarkerInfo );
// #else
//         s_MockPtr->_DebugMarkerInsertEXT( commandBuffer, pMarkerInfo );
// #endif
//     }

//     void vkInterface::BeginVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoBeginCodingInfoKHR* pBeginInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginVideoCodingKHR( pBeginInfo );
// #else
//         s_MockPtr->_BeginVideoCodingKHR( commandBuffer, pBeginInfo );
// #endif
//     }

//     void vkInterface::EndVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoEndCodingInfoKHR* pEndCodingInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endVideoCodingKHR( pEndCodingInfo );
// #else
//         s_MockPtr->_EndVideoCodingKHR( commandBuffer, pEndCodingInfo );
// #endif
//     }

//     void vkInterface::ControlVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoCodingControlInfoKHR* pCodingControlInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.controlVideoCodingKHR( pCodingControlInfo );
// #else
//         s_MockPtr->_ControlVideoCodingKHR( commandBuffer, pCodingControlInfo );
// #endif
//     }

//     void vkInterface::DecodeVideoKHR( vk::CommandBuffer commandBuffer, const vk::VideoDecodeInfoKHR* pDecodeInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.decodeVideoKHR( pDecodeInfo );
// #else
//         s_MockPtr->_DecodeVideoKHR( commandBuffer, pDecodeInfo );
// #endif
//     }

//     void vkInterface::BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindTransformFeedbackBuffersEXT( firstBinding, bindingCount, pBuffers, pOffsets, pSizes );
// #else
//         s_MockPtr->_BindTransformFeedbackBuffersEXT( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes );
// #endif
//     }

//     void vkInterface::BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers, const vk::DeviceSize* pCounterBufferOffsets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginTransformFeedbackEXT( firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets );
// #else
//         s_MockPtr->_BeginTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets );
// #endif
//     }

//     void vkInterface::EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer, uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers, const vk::DeviceSize* pCounterBufferOffsets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endTransformFeedbackEXT( firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets );
// #else
//         s_MockPtr->_EndTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers, pCounterBufferOffsets );
// #endif
//     }

//     void vkInterface::BeginQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query, vk::QueryControlFlags flags, uint32_t index )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginQueryIndexedEXT( queryPool, query, flags, index );
// #else
//         s_MockPtr->_BeginQueryIndexedEXT( commandBuffer, queryPool, query, flags, index );
// #endif
//     }

//     void vkInterface::EndQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query, uint32_t index )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endQueryIndexedEXT( queryPool, query, index );
// #else
//         s_MockPtr->_EndQueryIndexedEXT( commandBuffer, queryPool, query, index );
// #endif
//     }

//     void vkInterface::DrawIndirectByteCountEXT( vk::CommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance, vk::Buffer counterBuffer, vk::DeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndirectByteCountEXT( instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride );
// #else
//         s_MockPtr->_DrawIndirectByteCountEXT( commandBuffer, instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride );
// #endif
//     }

//     void vkInterface::CuLaunchKernelNVX( vk::CommandBuffer commandBuffer, const vk::CuLaunchInfoNVX* pLaunchInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.cuLaunchKernelNVX( pLaunchInfo );
// #else
//         s_MockPtr->_CuLaunchKernelNVX( commandBuffer, pLaunchInfo );
// #endif
//     }

//     void vkInterface::DrawIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndirectCountAMD( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndirectCountAMD( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::DrawIndexedIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndexedIndirectCountAMD( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndexedIndirectCountAMD( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::BeginRenderingKHR( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginRenderingKHR( pRenderingInfo );
// #else
//         s_MockPtr->_BeginRenderingKHR( commandBuffer, pRenderingInfo );
// #endif
//     }

//     void vkInterface::EndRenderingKHR( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endRenderingKHR();
// #else
//         s_MockPtr->_EndRenderingKHR( commandBuffer );
// #endif
//     }

//     void vkInterface::SetDeviceMaskKHR( vk::CommandBuffer commandBuffer, uint32_t deviceMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDeviceMaskKHR( deviceMask );
// #else
//         s_MockPtr->_SetDeviceMaskKHR( commandBuffer, deviceMask );
// #endif
//     }

//     void vkInterface::DispatchBaseKHR( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.dispatchBaseKHR( baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
// #else
//         s_MockPtr->_DispatchBaseKHR( commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
// #endif
//     }

//     void vkInterface::PushDescriptorSetKHR( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount, const vk::WriteDescriptorSet* pDescriptorWrites )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pushDescriptorSetKHR( pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites );
// #else
//         s_MockPtr->_PushDescriptorSetKHR( commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites );
// #endif
//     }

//     void vkInterface::PushDescriptorSetWithTemplateKHR( vk::CommandBuffer commandBuffer, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, vk::PipelineLayout layout, uint32_t set, const void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pushDescriptorSetWithTemplateKHR( descriptorUpdateTemplate, layout, set, pData );
// #else
//         s_MockPtr->_PushDescriptorSetWithTemplateKHR( commandBuffer, descriptorUpdateTemplate, layout, set, pData );
// #endif
//     }

//     void vkInterface::BeginConditionalRenderingEXT( vk::CommandBuffer commandBuffer, const vk::ConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginConditionalRenderingEXT( pConditionalRenderingBegin );
// #else
//         s_MockPtr->_BeginConditionalRenderingEXT( commandBuffer, pConditionalRenderingBegin );
// #endif
//     }

//     void vkInterface::EndConditionalRenderingEXT( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endConditionalRenderingEXT();
// #else
//         s_MockPtr->_EndConditionalRenderingEXT( commandBuffer );
// #endif
//     }

//     void vkInterface::SetViewportWScalingNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const vk::ViewportWScalingNV* pViewportWScalings )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportWScalingNV( firstViewport, viewportCount, pViewportWScalings );
// #else
//         s_MockPtr->_SetViewportWScalingNV( commandBuffer, firstViewport, viewportCount, pViewportWScalings );
// #endif
//     }

//     void vkInterface::SetDiscardRectangleEXT( vk::CommandBuffer commandBuffer, uint32_t firstDiscardRectangle, uint32_t discardRectangleCount, const vk::Rect2D* pDiscardRectangles )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDiscardRectangleEXT( firstDiscardRectangle, discardRectangleCount, pDiscardRectangles );
// #else
//         s_MockPtr->_SetDiscardRectangleEXT( commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles );
// #endif
//     }

//     void vkInterface::SetDiscardRectangleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 discardRectangleEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDiscardRectangleEnableEXT( discardRectangleEnable );
// #else
//         s_MockPtr->_SetDiscardRectangleEnableEXT( commandBuffer, discardRectangleEnable );
// #endif
//     }

//     void vkInterface::SetDiscardRectangleModeEXT( vk::CommandBuffer commandBuffer, vk::DiscardRectangleModeEXT discardRectangleMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDiscardRectangleModeEXT( discardRectangleMode );
// #else
//         s_MockPtr->_SetDiscardRectangleModeEXT( commandBuffer, discardRectangleMode );
// #endif
//     }

//     void vkInterface::BeginRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin, const vk::SubpassBeginInfo* pSubpassBeginInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginRenderPass2KHR( pRenderPassBegin, pSubpassBeginInfo );
// #else
//         s_MockPtr->_BeginRenderPass2KHR( commandBuffer, pRenderPassBegin, pSubpassBeginInfo );
// #endif
//     }

//     void vkInterface::NextSubpass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo, const vk::SubpassEndInfo* pSubpassEndInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.nextSubpass2KHR( pSubpassBeginInfo, pSubpassEndInfo );
// #else
//         s_MockPtr->_NextSubpass2KHR( commandBuffer, pSubpassBeginInfo, pSubpassEndInfo );
// #endif
//     }

//     void vkInterface::EndRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endRenderPass2KHR( pSubpassEndInfo );
// #else
//         s_MockPtr->_EndRenderPass2KHR( commandBuffer, pSubpassEndInfo );
// #endif
//     }

//     void vkInterface::BeginDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT* pLabelInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.beginDebugUtilsLabelEXT( pLabelInfo );
// #else
//         s_MockPtr->_BeginDebugUtilsLabelEXT( commandBuffer, pLabelInfo );
// #endif
//     }

//     void vkInterface::EndDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.endDebugUtilsLabelEXT();
// #else
//         s_MockPtr->_EndDebugUtilsLabelEXT( commandBuffer );
// #endif
//     }

//     void vkInterface::InsertDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT* pLabelInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.insertDebugUtilsLabelEXT( pLabelInfo );
// #else
//         s_MockPtr->_InsertDebugUtilsLabelEXT( commandBuffer, pLabelInfo );
// #endif
//     }

//     void vkInterface::SetSampleLocationsEXT( vk::CommandBuffer commandBuffer, const vk::SampleLocationsInfoEXT* pSampleLocationsInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setSampleLocationsEXT( pSampleLocationsInfo );
// #else
//         s_MockPtr->_SetSampleLocationsEXT( commandBuffer, pSampleLocationsInfo );
// #endif
//     }

//     void vkInterface::BuildAccelerationStructuresKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount, const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos, const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.buildAccelerationStructuresKHR( infoCount, pInfos, ppBuildRangeInfos );
// #else
//         s_MockPtr->_BuildAccelerationStructuresKHR( commandBuffer, infoCount, pInfos, ppBuildRangeInfos );
// #endif
//     }

//     void vkInterface::BuildAccelerationStructuresIndirectKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount, const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos, const vk::DeviceAddress* pIndirectDeviceAddresses, const uint32_t* pIndirectStrides,
//                                                               const uint32_t* const* ppMaxPrimitiveCounts )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.buildAccelerationStructuresIndirectKHR( infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts );
// #else
//         s_MockPtr->_BuildAccelerationStructuresIndirectKHR( commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides, ppMaxPrimitiveCounts );
// #endif
//     }

//     void vkInterface::CopyAccelerationStructureKHR( vk::CommandBuffer commandBuffer, const vk::CopyAccelerationStructureInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyAccelerationStructureKHR( pInfo );
// #else
//         s_MockPtr->_CopyAccelerationStructureKHR( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::CopyAccelerationStructureToMemoryKHR( vk::CommandBuffer commandBuffer, const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyAccelerationStructureToMemoryKHR( pInfo );
// #else
//         s_MockPtr->_CopyAccelerationStructureToMemoryKHR( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::CopyMemoryToAccelerationStructureKHR( vk::CommandBuffer commandBuffer, const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMemoryToAccelerationStructureKHR( pInfo );
// #else
//         s_MockPtr->_CopyMemoryToAccelerationStructureKHR( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::WriteAccelerationStructuresPropertiesKHR( vk::CommandBuffer commandBuffer, uint32_t accelerationStructureCount, const vk::AccelerationStructureKHR* pAccelerationStructures, vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeAccelerationStructuresPropertiesKHR( accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery );
// #else
//         s_MockPtr->_WriteAccelerationStructuresPropertiesKHR( commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery );
// #endif
//     }

//     void vkInterface::TraceRaysKHR( vk::CommandBuffer commandBuffer, const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable, const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
//                                     const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysKHR( pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth );
// #else
//         s_MockPtr->_TraceRaysKHR( commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, width, height, depth );
// #endif
//     }

//     void vkInterface::TraceRaysKHR( vk::CommandBuffer commandBuffer, const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable, const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable, const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
//                                     const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysKHR( raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable, callableShaderBindingTable, width, height, depth );
// #else
//         s_MockPtr->_TraceRaysKHR( commandBuffer, raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable, callableShaderBindingTable, width, height, depth );
// #endif
//     }

//     void vkInterface::TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer, const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable, const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable, const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
//                                             const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable, vk::DeviceAddress indirectDeviceAddress )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysIndirectKHR( pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress );
// #else
//         s_MockPtr->_TraceRaysIndirectKHR( commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress );
// #endif
//     }

//     void vkInterface::TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer, const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable, const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable, const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
//                                             const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable, vk::DeviceAddress indirectDeviceAddress )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysIndirectKHR( raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable, callableShaderBindingTable, indirectDeviceAddress );
// #else
//         s_MockPtr->_TraceRaysIndirectKHR( commandBuffer, raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable, callableShaderBindingTable, indirectDeviceAddress );
// #endif
//     }

//     void vkInterface::SetRayTracingPipelineStackSizeKHR( vk::CommandBuffer commandBuffer, uint32_t pipelineStackSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRayTracingPipelineStackSizeKHR( pipelineStackSize );
// #else
//         s_MockPtr->_SetRayTracingPipelineStackSizeKHR( commandBuffer, pipelineStackSize );
// #endif
//     }

//     void vkInterface::BindShadingRateImageNV( vk::CommandBuffer commandBuffer, vk::ImageView imageView, vk::ImageLayout imageLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindShadingRateImageNV( imageView, imageLayout );
// #else
//         s_MockPtr->_BindShadingRateImageNV( commandBuffer, imageView, imageLayout );
// #endif
//     }

//     void vkInterface::SetViewportShadingRatePaletteNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const vk::ShadingRatePaletteNV* pShadingRatePalettes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportShadingRatePaletteNV( firstViewport, viewportCount, pShadingRatePalettes );
// #else
//         s_MockPtr->_SetViewportShadingRatePaletteNV( commandBuffer, firstViewport, viewportCount, pShadingRatePalettes );
// #endif
//     }

//     void vkInterface::SetCoarseSampleOrderNV( vk::CommandBuffer commandBuffer, vk::CoarseSampleOrderTypeNV sampleOrderType, uint32_t customSampleOrderCount, const vk::CoarseSampleOrderCustomNV* pCustomSampleOrders )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoarseSampleOrderNV( sampleOrderType, customSampleOrderCount, pCustomSampleOrders );
// #else
//         s_MockPtr->_SetCoarseSampleOrderNV( commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders );
// #endif
//     }

//     void vkInterface::BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer, const vk::AccelerationStructureInfoNV* pInfo, vk::Buffer instanceData, vk::DeviceSize instanceOffset, vk::Bool32 update, vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src, vk::Buffer scratch,
//                                                     vk::DeviceSize scratchOffset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.buildAccelerationStructureNV( pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset );
// #else
//         s_MockPtr->_BuildAccelerationStructureNV( commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset );
// #endif
//     }

//     void vkInterface::BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer, const vk::AccelerationStructureInfoNV& info, vk::Buffer instanceData, vk::DeviceSize instanceOffset, vk::Bool32 update, vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src, vk::Buffer scratch,
//                                                     vk::DeviceSize scratchOffset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.buildAccelerationStructureNV( info, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset );
// #else
//         s_MockPtr->_BuildAccelerationStructureNV( commandBuffer, info, instanceData, instanceOffset, update, dst, src, scratch, scratchOffset );
// #endif
//     }

//     void vkInterface::CopyAccelerationStructureNV( vk::CommandBuffer commandBuffer, vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src, vk::CopyAccelerationStructureModeKHR mode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyAccelerationStructureNV( dst, src, mode );
// #else
//         s_MockPtr->_CopyAccelerationStructureNV( commandBuffer, dst, src, mode );
// #endif
//     }

//     void vkInterface::TraceRaysNV( vk::CommandBuffer commandBuffer, vk::Buffer raygenShaderBindingTableBuffer, vk::DeviceSize raygenShaderBindingOffset, vk::Buffer missShaderBindingTableBuffer, vk::DeviceSize missShaderBindingOffset, vk::DeviceSize missShaderBindingStride,
//                                    vk::Buffer hitShaderBindingTableBuffer, vk::DeviceSize hitShaderBindingOffset, vk::DeviceSize hitShaderBindingStride, vk::Buffer callableShaderBindingTableBuffer, vk::DeviceSize callableShaderBindingOffset, vk::DeviceSize callableShaderBindingStride,
//                                    uint32_t width, uint32_t height, uint32_t depth )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysNV( raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer,
//                                    callableShaderBindingOffset, callableShaderBindingStride, width, height, depth );
// #else
//         s_MockPtr->_TraceRaysNV( commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer,
//                                  callableShaderBindingOffset, callableShaderBindingStride, width, height, depth );
// #endif
//     }

//     void vkInterface::WriteAccelerationStructuresPropertiesNV( vk::CommandBuffer commandBuffer, uint32_t accelerationStructureCount, const vk::AccelerationStructureNV* pAccelerationStructures, vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeAccelerationStructuresPropertiesNV( accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery );
// #else
//         s_MockPtr->_WriteAccelerationStructuresPropertiesNV( commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery );
// #endif
//     }

//     void vkInterface::DrawIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndirectCountKHR( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndirectCountKHR( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::DrawIndexedIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawIndexedIndirectCountKHR( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawIndexedIndirectCountKHR( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::WriteBufferMarkerAMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage, vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeBufferMarkerAMD( pipelineStage, dstBuffer, dstOffset, marker );
// #else
//         s_MockPtr->_WriteBufferMarkerAMD( commandBuffer, pipelineStage, dstBuffer, dstOffset, marker );
// #endif
//     }

//     void vkInterface::DrawMeshTasksNV( vk::CommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksNV( taskCount, firstTask );
// #else
//         s_MockPtr->_DrawMeshTasksNV( commandBuffer, taskCount, firstTask );
// #endif
//     }

//     void vkInterface::DrawMeshTasksIndirectNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, uint32_t drawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksIndirectNV( buffer, offset, drawCount, stride );
// #else
//         s_MockPtr->_DrawMeshTasksIndirectNV( commandBuffer, buffer, offset, drawCount, stride );
// #endif
//     }

//     void vkInterface::DrawMeshTasksIndirectCountNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksIndirectCountNV( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawMeshTasksIndirectCountNV( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::SetExclusiveScissorEnableNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const vk::Bool32* pExclusiveScissorEnables )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setExclusiveScissorEnableNV( firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables );
// #else
//         s_MockPtr->_SetExclusiveScissorEnableNV( commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables );
// #endif
//     }

//     void vkInterface::SetExclusiveScissorNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor, uint32_t exclusiveScissorCount, const vk::Rect2D* pExclusiveScissors )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setExclusiveScissorNV( firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors );
// #else
//         s_MockPtr->_SetExclusiveScissorNV( commandBuffer, firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors );
// #endif
//     }

//     void vkInterface::SetCheckpointNV( vk::CommandBuffer commandBuffer, const void* pCheckpointMarker )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCheckpointNV( pCheckpointMarker );
// #else
//         s_MockPtr->_SetCheckpointNV( commandBuffer, pCheckpointMarker );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPerformanceMarkerINTEL( vk::CommandBuffer commandBuffer, const vk::PerformanceMarkerInfoINTEL* pMarkerInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = commandBuffer.setPerformanceMarkerINTEL( pMarkerInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPerformanceMarkerINTEL( commandBuffer, pMarkerInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPerformanceStreamMarkerINTEL( vk::CommandBuffer commandBuffer, const vk::PerformanceStreamMarkerInfoINTEL* pMarkerInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = commandBuffer.setPerformanceStreamMarkerINTEL( pMarkerInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPerformanceStreamMarkerINTEL( commandBuffer, pMarkerInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPerformanceOverrideINTEL( vk::CommandBuffer commandBuffer, const vk::PerformanceOverrideInfoINTEL* pOverrideInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = commandBuffer.setPerformanceOverrideINTEL( pOverrideInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPerformanceOverrideINTEL( commandBuffer, pOverrideInfo );
// #endif
//     }

//     void vkInterface::SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D* pFragmentSize, const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setFragmentShadingRateKHR( pFragmentSize, combinerOps );
// #else
//         s_MockPtr->_SetFragmentShadingRateKHR( commandBuffer, pFragmentSize, combinerOps );
// #endif
//     }

//     void vkInterface::SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D& fragmentSize, const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setFragmentShadingRateKHR( fragmentSize, combinerOps );
// #else
//         s_MockPtr->_SetFragmentShadingRateKHR( commandBuffer, fragmentSize, combinerOps );
// #endif
//     }

//     void vkInterface::SetLineStippleEXT( vk::CommandBuffer commandBuffer, uint32_t lineStippleFactor, uint16_t lineStipplePattern )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLineStippleEXT( lineStippleFactor, lineStipplePattern );
// #else
//         s_MockPtr->_SetLineStippleEXT( commandBuffer, lineStippleFactor, lineStipplePattern );
// #endif
//     }

//     void vkInterface::SetCullModeEXT( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCullModeEXT( cullMode );
// #else
//         s_MockPtr->_SetCullModeEXT( commandBuffer, cullMode );
// #endif
//     }

//     void vkInterface::SetFrontFaceEXT( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setFrontFaceEXT( frontFace );
// #else
//         s_MockPtr->_SetFrontFaceEXT( commandBuffer, frontFace );
// #endif
//     }

//     void vkInterface::SetPrimitiveTopologyEXT( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPrimitiveTopologyEXT( primitiveTopology );
// #else
//         s_MockPtr->_SetPrimitiveTopologyEXT( commandBuffer, primitiveTopology );
// #endif
//     }

//     void vkInterface::SetViewportWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t viewportCount, const vk::Viewport* pViewports )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportWithCountEXT( viewportCount, pViewports );
// #else
//         s_MockPtr->_SetViewportWithCountEXT( commandBuffer, viewportCount, pViewports );
// #endif
//     }

//     void vkInterface::SetScissorWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t scissorCount, const vk::Rect2D* pScissors )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setScissorWithCountEXT( scissorCount, pScissors );
// #else
//         s_MockPtr->_SetScissorWithCountEXT( commandBuffer, scissorCount, pScissors );
// #endif
//     }

//     void vkInterface::BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount, const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindVertexBuffers2EXT( firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
// #else
//         s_MockPtr->_BindVertexBuffers2EXT( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
// #endif
//     }

//     void vkInterface::SetDepthTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthTestEnableEXT( depthTestEnable );
// #else
//         s_MockPtr->_SetDepthTestEnableEXT( commandBuffer, depthTestEnable );
// #endif
//     }

//     void vkInterface::SetDepthWriteEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthWriteEnableEXT( depthWriteEnable );
// #else
//         s_MockPtr->_SetDepthWriteEnableEXT( commandBuffer, depthWriteEnable );
// #endif
//     }

//     void vkInterface::SetDepthCompareOpEXT( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthCompareOpEXT( depthCompareOp );
// #else
//         s_MockPtr->_SetDepthCompareOpEXT( commandBuffer, depthCompareOp );
// #endif
//     }

//     void vkInterface::SetDepthBoundsTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBoundsTestEnableEXT( depthBoundsTestEnable );
// #else
//         s_MockPtr->_SetDepthBoundsTestEnableEXT( commandBuffer, depthBoundsTestEnable );
// #endif
//     }

//     void vkInterface::SetStencilTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilTestEnableEXT( stencilTestEnable );
// #else
//         s_MockPtr->_SetStencilTestEnableEXT( commandBuffer, stencilTestEnable );
// #endif
//     }

//     void vkInterface::SetStencilOpEXT( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, vk::StencilOp failOp, vk::StencilOp passOp, vk::StencilOp depthFailOp, vk::CompareOp compareOp )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setStencilOpEXT( faceMask, failOp, passOp, depthFailOp, compareOp );
// #else
//         s_MockPtr->_SetStencilOpEXT( commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp );
// #endif
//     }

//     void vkInterface::PreprocessGeneratedCommandsNV( vk::CommandBuffer commandBuffer, const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.preprocessGeneratedCommandsNV( pGeneratedCommandsInfo );
// #else
//         s_MockPtr->_PreprocessGeneratedCommandsNV( commandBuffer, pGeneratedCommandsInfo );
// #endif
//     }

//     void vkInterface::ExecuteGeneratedCommandsNV( vk::CommandBuffer commandBuffer, vk::Bool32 isPreprocessed, const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.executeGeneratedCommandsNV( isPreprocessed, pGeneratedCommandsInfo );
// #else
//         s_MockPtr->_ExecuteGeneratedCommandsNV( commandBuffer, isPreprocessed, pGeneratedCommandsInfo );
// #endif
//     }

//     void vkInterface::BindPipelineShaderGroupNV( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::Pipeline pipeline, uint32_t groupIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindPipelineShaderGroupNV( pipelineBindPoint, pipeline, groupIndex );
// #else
//         s_MockPtr->_BindPipelineShaderGroupNV( commandBuffer, pipelineBindPoint, pipeline, groupIndex );
// #endif
//     }

//     void vkInterface::SetDepthBias2EXT( vk::CommandBuffer commandBuffer, const vk::DepthBiasInfoEXT* pDepthBiasInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBias2EXT( pDepthBiasInfo );
// #else
//         s_MockPtr->_SetDepthBias2EXT( commandBuffer, pDepthBiasInfo );
// #endif
//     }

//     void vkInterface::SetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event, const vk::DependencyInfo* pDependencyInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setEvent2KHR( event, pDependencyInfo );
// #else
//         s_MockPtr->_SetEvent2KHR( commandBuffer, event, pDependencyInfo );
// #endif
//     }

//     void vkInterface::ResetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags2 stageMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resetEvent2KHR( event, stageMask );
// #else
//         s_MockPtr->_ResetEvent2KHR( commandBuffer, event, stageMask );
// #endif
//     }

//     void vkInterface::WaitEvents2KHR( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents, const vk::DependencyInfo* pDependencyInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.waitEvents2KHR( eventCount, pEvents, pDependencyInfos );
// #else
//         s_MockPtr->_WaitEvents2KHR( commandBuffer, eventCount, pEvents, pDependencyInfos );
// #endif
//     }

//     void vkInterface::PipelineBarrier2KHR( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.pipelineBarrier2KHR( pDependencyInfo );
// #else
//         s_MockPtr->_PipelineBarrier2KHR( commandBuffer, pDependencyInfo );
// #endif
//     }

//     void vkInterface::WriteTimestamp2KHR( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::QueryPool queryPool, uint32_t query )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeTimestamp2KHR( stage, queryPool, query );
// #else
//         s_MockPtr->_WriteTimestamp2KHR( commandBuffer, stage, queryPool, query );
// #endif
//     }

//     void vkInterface::WriteBufferMarker2AMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeBufferMarker2AMD( stage, dstBuffer, dstOffset, marker );
// #else
//         s_MockPtr->_WriteBufferMarker2AMD( commandBuffer, stage, dstBuffer, dstOffset, marker );
// #endif
//     }

//     void vkInterface::BindDescriptorBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t bufferCount, const vk::DescriptorBufferBindingInfoEXT* pBindingInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindDescriptorBuffersEXT( bufferCount, pBindingInfos );
// #else
//         s_MockPtr->_BindDescriptorBuffersEXT( commandBuffer, bufferCount, pBindingInfos );
// #endif
//     }

//     void vkInterface::SetDescriptorBufferOffsetsEXT( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout, uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices, const vk::DeviceSize* pOffsets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDescriptorBufferOffsetsEXT( pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets );
// #else
//         s_MockPtr->_SetDescriptorBufferOffsetsEXT( commandBuffer, pipelineBindPoint, layout, firstSet, setCount, pBufferIndices, pOffsets );
// #endif
//     }

//     void vkInterface::BindDescriptorBufferEmbeddedSamplersEXT( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout, uint32_t set )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindDescriptorBufferEmbeddedSamplersEXT( pipelineBindPoint, layout, set );
// #else
//         s_MockPtr->_BindDescriptorBufferEmbeddedSamplersEXT( commandBuffer, pipelineBindPoint, layout, set );
// #endif
//     }

//     void vkInterface::SetFragmentShadingRateEnumNV( vk::CommandBuffer commandBuffer, vk::FragmentShadingRateNV shadingRate, const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setFragmentShadingRateEnumNV( shadingRate, combinerOps );
// #else
//         s_MockPtr->_SetFragmentShadingRateEnumNV( commandBuffer, shadingRate, combinerOps );
// #endif
//     }

//     void vkInterface::DrawMeshTasksEXT( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksEXT( groupCountX, groupCountY, groupCountZ );
// #else
//         s_MockPtr->_DrawMeshTasksEXT( commandBuffer, groupCountX, groupCountY, groupCountZ );
// #endif
//     }

//     void vkInterface::DrawMeshTasksIndirectEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, uint32_t drawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksIndirectEXT( buffer, offset, drawCount, stride );
// #else
//         s_MockPtr->_DrawMeshTasksIndirectEXT( commandBuffer, buffer, offset, drawCount, stride );
// #endif
//     }

//     void vkInterface::DrawMeshTasksIndirectCountEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMeshTasksIndirectCountEXT( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #else
//         s_MockPtr->_DrawMeshTasksIndirectCountEXT( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
// #endif
//     }

//     void vkInterface::CopyBuffer2KHR( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBuffer2KHR( pCopyBufferInfo );
// #else
//         s_MockPtr->_CopyBuffer2KHR( commandBuffer, pCopyBufferInfo );
// #endif
//     }

//     void vkInterface::CopyImage2KHR( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImage2KHR( pCopyImageInfo );
// #else
//         s_MockPtr->_CopyImage2KHR( commandBuffer, pCopyImageInfo );
// #endif
//     }

//     void vkInterface::CopyBufferToImage2KHR( vk::CommandBuffer commandBuffer, const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyBufferToImage2KHR( pCopyBufferToImageInfo );
// #else
//         s_MockPtr->_CopyBufferToImage2KHR( commandBuffer, pCopyBufferToImageInfo );
// #endif
//     }

//     void vkInterface::CopyImageToBuffer2KHR( vk::CommandBuffer commandBuffer, const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyImageToBuffer2KHR( pCopyImageToBufferInfo );
// #else
//         s_MockPtr->_CopyImageToBuffer2KHR( commandBuffer, pCopyImageToBufferInfo );
// #endif
//     }

//     void vkInterface::BlitImage2KHR( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.blitImage2KHR( pBlitImageInfo );
// #else
//         s_MockPtr->_BlitImage2KHR( commandBuffer, pBlitImageInfo );
// #endif
//     }

//     void vkInterface::ResolveImage2KHR( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.resolveImage2KHR( pResolveImageInfo );
// #else
//         s_MockPtr->_ResolveImage2KHR( commandBuffer, pResolveImageInfo );
// #endif
//     }

//     void vkInterface::SetVertexInputEXT( vk::CommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount, const vk::VertexInputBindingDescription2EXT* pVertexBindingDescriptions, uint32_t vertexAttributeDescriptionCount,
//                                          const vk::VertexInputAttributeDescription2EXT* pVertexAttributeDescriptions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setVertexInputEXT( vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions );
// #else
//         s_MockPtr->_SetVertexInputEXT( commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions, vertexAttributeDescriptionCount, pVertexAttributeDescriptions );
// #endif
//     }

//     void vkInterface::SubpassShadingHUAWEI( vk::CommandBuffer commandBuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.subpassShadingHUAWEI();
// #else
//         s_MockPtr->_SubpassShadingHUAWEI( commandBuffer );
// #endif
//     }

//     void vkInterface::BindInvocationMaskHUAWEI( vk::CommandBuffer commandBuffer, vk::ImageView imageView, vk::ImageLayout imageLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindInvocationMaskHUAWEI( imageView, imageLayout );
// #else
//         s_MockPtr->_BindInvocationMaskHUAWEI( commandBuffer, imageView, imageLayout );
// #endif
//     }

//     void vkInterface::SetPatchControlPointsEXT( vk::CommandBuffer commandBuffer, uint32_t patchControlPoints )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPatchControlPointsEXT( patchControlPoints );
// #else
//         s_MockPtr->_SetPatchControlPointsEXT( commandBuffer, patchControlPoints );
// #endif
//     }

//     void vkInterface::SetRasterizerDiscardEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 rasterizerDiscardEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRasterizerDiscardEnableEXT( rasterizerDiscardEnable );
// #else
//         s_MockPtr->_SetRasterizerDiscardEnableEXT( commandBuffer, rasterizerDiscardEnable );
// #endif
//     }

//     void vkInterface::SetDepthBiasEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthBiasEnableEXT( depthBiasEnable );
// #else
//         s_MockPtr->_SetDepthBiasEnableEXT( commandBuffer, depthBiasEnable );
// #endif
//     }

//     void vkInterface::SetLogicOpEXT( vk::CommandBuffer commandBuffer, vk::LogicOp logicOp )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLogicOpEXT( logicOp );
// #else
//         s_MockPtr->_SetLogicOpEXT( commandBuffer, logicOp );
// #endif
//     }

//     void vkInterface::SetPrimitiveRestartEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPrimitiveRestartEnableEXT( primitiveRestartEnable );
// #else
//         s_MockPtr->_SetPrimitiveRestartEnableEXT( commandBuffer, primitiveRestartEnable );
// #endif
//     }

//     void vkInterface::SetColorWriteEnableEXT( vk::CommandBuffer commandBuffer, uint32_t attachmentCount, const vk::Bool32* pColorWriteEnables )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setColorWriteEnableEXT( attachmentCount, pColorWriteEnables );
// #else
//         s_MockPtr->_SetColorWriteEnableEXT( commandBuffer, attachmentCount, pColorWriteEnables );
// #endif
//     }

//     void vkInterface::TraceRaysIndirect2KHR( vk::CommandBuffer commandBuffer, vk::DeviceAddress indirectDeviceAddress )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.traceRaysIndirect2KHR( indirectDeviceAddress );
// #else
//         s_MockPtr->_TraceRaysIndirect2KHR( commandBuffer, indirectDeviceAddress );
// #endif
//     }

//     void vkInterface::DrawMultiEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount, const vk::MultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMultiEXT( drawCount, pVertexInfo, instanceCount, firstInstance, stride );
// #else
//         s_MockPtr->_DrawMultiEXT( commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride );
// #endif
//     }

//     void vkInterface::DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount, const vk::MultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawMultiIndexedEXT( drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset );
// #else
//         s_MockPtr->_DrawMultiIndexedEXT( commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset );
// #endif
//     }

//     void vkInterface::BuildMicromapsEXT( vk::CommandBuffer commandBuffer, uint32_t infoCount, const vk::MicromapBuildInfoEXT* pInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.buildMicromapsEXT( infoCount, pInfos );
// #else
//         s_MockPtr->_BuildMicromapsEXT( commandBuffer, infoCount, pInfos );
// #endif
//     }

//     void vkInterface::CopyMicromapEXT( vk::CommandBuffer commandBuffer, const vk::CopyMicromapInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMicromapEXT( pInfo );
// #else
//         s_MockPtr->_CopyMicromapEXT( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::CopyMicromapToMemoryEXT( vk::CommandBuffer commandBuffer, const vk::CopyMicromapToMemoryInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMicromapToMemoryEXT( pInfo );
// #else
//         s_MockPtr->_CopyMicromapToMemoryEXT( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::CopyMemoryToMicromapEXT( vk::CommandBuffer commandBuffer, const vk::CopyMemoryToMicromapInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMemoryToMicromapEXT( pInfo );
// #else
//         s_MockPtr->_CopyMemoryToMicromapEXT( commandBuffer, pInfo );
// #endif
//     }

//     void vkInterface::WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer, uint32_t micromapCount, const vk::MicromapEXT* pMicromaps, vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.writeMicromapsPropertiesEXT( micromapCount, pMicromaps, queryType, queryPool, firstQuery );
// #else
//         s_MockPtr->_WriteMicromapsPropertiesEXT( commandBuffer, micromapCount, pMicromaps, queryType, queryPool, firstQuery );
// #endif
//     }

//     void vkInterface::DrawClusterHUAWEI( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawClusterHUAWEI( groupCountX, groupCountY, groupCountZ );
// #else
//         s_MockPtr->_DrawClusterHUAWEI( commandBuffer, groupCountX, groupCountY, groupCountZ );
// #endif
//     }

//     void vkInterface::DrawClusterIndirectHUAWEI( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.drawClusterIndirectHUAWEI( buffer, offset );
// #else
//         s_MockPtr->_DrawClusterIndirectHUAWEI( commandBuffer, buffer, offset );
// #endif
//     }

//     void vkInterface::CopyMemoryIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMemoryIndirectNV( copyBufferAddress, copyCount, stride );
// #else
//         s_MockPtr->_CopyMemoryIndirectNV( commandBuffer, copyBufferAddress, copyCount, stride );
// #endif
//     }

//     void vkInterface::CopyMemoryToImageIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride, vk::Image dstImage, vk::ImageLayout dstImageLayout, const vk::ImageSubresourceLayers* pImageSubresources )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.copyMemoryToImageIndirectNV( copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources );
// #else
//         s_MockPtr->_CopyMemoryToImageIndirectNV( commandBuffer, copyBufferAddress, copyCount, stride, dstImage, dstImageLayout, pImageSubresources );
// #endif
//     }

//     void vkInterface::DecompressMemoryNV( vk::CommandBuffer commandBuffer, uint32_t decompressRegionCount, const vk::DecompressMemoryRegionNV* pDecompressMemoryRegions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.decompressMemoryNV( decompressRegionCount, pDecompressMemoryRegions );
// #else
//         s_MockPtr->_DecompressMemoryNV( commandBuffer, decompressRegionCount, pDecompressMemoryRegions );
// #endif
//     }

//     void vkInterface::DecompressMemoryIndirectCountNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress indirectCommandsAddress, vk::DeviceAddress indirectCommandsCountAddress, uint32_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.decompressMemoryIndirectCountNV( indirectCommandsAddress, indirectCommandsCountAddress, stride );
// #else
//         s_MockPtr->_DecompressMemoryIndirectCountNV( commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress, stride );
// #endif
//     }

//     void vkInterface::UpdatePipelineIndirectBufferNV( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint, vk::Pipeline pipeline )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.updatePipelineIndirectBufferNV( pipelineBindPoint, pipeline );
// #else
//         s_MockPtr->_UpdatePipelineIndirectBufferNV( commandBuffer, pipelineBindPoint, pipeline );
// #endif
//     }

//     void vkInterface::SetTessellationDomainOriginEXT( vk::CommandBuffer commandBuffer, vk::TessellationDomainOrigin domainOrigin )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setTessellationDomainOriginEXT( domainOrigin );
// #else
//         s_MockPtr->_SetTessellationDomainOriginEXT( commandBuffer, domainOrigin );
// #endif
//     }

//     void vkInterface::SetDepthClampEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClampEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthClampEnableEXT( depthClampEnable );
// #else
//         s_MockPtr->_SetDepthClampEnableEXT( commandBuffer, depthClampEnable );
// #endif
//     }

//     void vkInterface::SetPolygonModeEXT( vk::CommandBuffer commandBuffer, vk::PolygonMode polygonMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setPolygonModeEXT( polygonMode );
// #else
//         s_MockPtr->_SetPolygonModeEXT( commandBuffer, polygonMode );
// #endif
//     }

//     void vkInterface::SetRasterizationSamplesEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits rasterizationSamples )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRasterizationSamplesEXT( rasterizationSamples );
// #else
//         s_MockPtr->_SetRasterizationSamplesEXT( commandBuffer, rasterizationSamples );
// #endif
//     }

//     void vkInterface::SetSampleMaskEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits samples, const vk::SampleMask* pSampleMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setSampleMaskEXT( samples, pSampleMask );
// #else
//         s_MockPtr->_SetSampleMaskEXT( commandBuffer, samples, pSampleMask );
// #endif
//     }

//     void vkInterface::SetAlphaToCoverageEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToCoverageEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setAlphaToCoverageEnableEXT( alphaToCoverageEnable );
// #else
//         s_MockPtr->_SetAlphaToCoverageEnableEXT( commandBuffer, alphaToCoverageEnable );
// #endif
//     }

//     void vkInterface::SetAlphaToOneEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToOneEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setAlphaToOneEnableEXT( alphaToOneEnable );
// #else
//         s_MockPtr->_SetAlphaToOneEnableEXT( commandBuffer, alphaToOneEnable );
// #endif
//     }

//     void vkInterface::SetLogicOpEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 logicOpEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLogicOpEnableEXT( logicOpEnable );
// #else
//         s_MockPtr->_SetLogicOpEnableEXT( commandBuffer, logicOpEnable );
// #endif
//     }

//     void vkInterface::SetColorBlendEnableEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const vk::Bool32* pColorBlendEnables )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setColorBlendEnableEXT( firstAttachment, attachmentCount, pColorBlendEnables );
// #else
//         s_MockPtr->_SetColorBlendEnableEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables );
// #endif
//     }

//     void vkInterface::SetColorBlendEquationEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const vk::ColorBlendEquationEXT* pColorBlendEquations )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setColorBlendEquationEXT( firstAttachment, attachmentCount, pColorBlendEquations );
// #else
//         s_MockPtr->_SetColorBlendEquationEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations );
// #endif
//     }

//     void vkInterface::SetColorWriteMaskEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const vk::ColorComponentFlags* pColorWriteMasks )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setColorWriteMaskEXT( firstAttachment, attachmentCount, pColorWriteMasks );
// #else
//         s_MockPtr->_SetColorWriteMaskEXT( commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks );
// #endif
//     }

//     void vkInterface::SetRasterizationStreamEXT( vk::CommandBuffer commandBuffer, uint32_t rasterizationStream )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRasterizationStreamEXT( rasterizationStream );
// #else
//         s_MockPtr->_SetRasterizationStreamEXT( commandBuffer, rasterizationStream );
// #endif
//     }

//     void vkInterface::SetConservativeRasterizationModeEXT( vk::CommandBuffer commandBuffer, vk::ConservativeRasterizationModeEXT conservativeRasterizationMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setConservativeRasterizationModeEXT( conservativeRasterizationMode );
// #else
//         s_MockPtr->_SetConservativeRasterizationModeEXT( commandBuffer, conservativeRasterizationMode );
// #endif
//     }

//     void vkInterface::SetExtraPrimitiveOverestimationSizeEXT( vk::CommandBuffer commandBuffer, float extraPrimitiveOverestimationSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setExtraPrimitiveOverestimationSizeEXT( extraPrimitiveOverestimationSize );
// #else
//         s_MockPtr->_SetExtraPrimitiveOverestimationSizeEXT( commandBuffer, extraPrimitiveOverestimationSize );
// #endif
//     }

//     void vkInterface::SetDepthClipEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClipEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthClipEnableEXT( depthClipEnable );
// #else
//         s_MockPtr->_SetDepthClipEnableEXT( commandBuffer, depthClipEnable );
// #endif
//     }

//     void vkInterface::SetSampleLocationsEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 sampleLocationsEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setSampleLocationsEnableEXT( sampleLocationsEnable );
// #else
//         s_MockPtr->_SetSampleLocationsEnableEXT( commandBuffer, sampleLocationsEnable );
// #endif
//     }

//     void vkInterface::SetColorBlendAdvancedEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount, const vk::ColorBlendAdvancedEXT* pColorBlendAdvanced )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setColorBlendAdvancedEXT( firstAttachment, attachmentCount, pColorBlendAdvanced );
// #else
//         s_MockPtr->_SetColorBlendAdvancedEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced );
// #endif
//     }

//     void vkInterface::SetProvokingVertexModeEXT( vk::CommandBuffer commandBuffer, vk::ProvokingVertexModeEXT provokingVertexMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setProvokingVertexModeEXT( provokingVertexMode );
// #else
//         s_MockPtr->_SetProvokingVertexModeEXT( commandBuffer, provokingVertexMode );
// #endif
//     }

//     void vkInterface::SetLineRasterizationModeEXT( vk::CommandBuffer commandBuffer, vk::LineRasterizationModeEXT lineRasterizationMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLineRasterizationModeEXT( lineRasterizationMode );
// #else
//         s_MockPtr->_SetLineRasterizationModeEXT( commandBuffer, lineRasterizationMode );
// #endif
//     }

//     void vkInterface::SetLineStippleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stippledLineEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setLineStippleEnableEXT( stippledLineEnable );
// #else
//         s_MockPtr->_SetLineStippleEnableEXT( commandBuffer, stippledLineEnable );
// #endif
//     }

//     void vkInterface::SetDepthClipNegativeOneToOneEXT( vk::CommandBuffer commandBuffer, vk::Bool32 negativeOneToOne )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setDepthClipNegativeOneToOneEXT( negativeOneToOne );
// #else
//         s_MockPtr->_SetDepthClipNegativeOneToOneEXT( commandBuffer, negativeOneToOne );
// #endif
//     }

//     void vkInterface::SetViewportWScalingEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 viewportWScalingEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportWScalingEnableNV( viewportWScalingEnable );
// #else
//         s_MockPtr->_SetViewportWScalingEnableNV( commandBuffer, viewportWScalingEnable );
// #endif
//     }

//     void vkInterface::SetViewportSwizzleNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount, const vk::ViewportSwizzleNV* pViewportSwizzles )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setViewportSwizzleNV( firstViewport, viewportCount, pViewportSwizzles );
// #else
//         s_MockPtr->_SetViewportSwizzleNV( commandBuffer, firstViewport, viewportCount, pViewportSwizzles );
// #endif
//     }

//     void vkInterface::SetCoverageToColorEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 coverageToColorEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageToColorEnableNV( coverageToColorEnable );
// #else
//         s_MockPtr->_SetCoverageToColorEnableNV( commandBuffer, coverageToColorEnable );
// #endif
//     }

//     void vkInterface::SetCoverageToColorLocationNV( vk::CommandBuffer commandBuffer, uint32_t coverageToColorLocation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageToColorLocationNV( coverageToColorLocation );
// #else
//         s_MockPtr->_SetCoverageToColorLocationNV( commandBuffer, coverageToColorLocation );
// #endif
//     }

//     void vkInterface::SetCoverageModulationModeNV( vk::CommandBuffer commandBuffer, vk::CoverageModulationModeNV coverageModulationMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageModulationModeNV( coverageModulationMode );
// #else
//         s_MockPtr->_SetCoverageModulationModeNV( commandBuffer, coverageModulationMode );
// #endif
//     }

//     void vkInterface::SetCoverageModulationTableEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 coverageModulationTableEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageModulationTableEnableNV( coverageModulationTableEnable );
// #else
//         s_MockPtr->_SetCoverageModulationTableEnableNV( commandBuffer, coverageModulationTableEnable );
// #endif
//     }

//     void vkInterface::SetCoverageModulationTableNV( vk::CommandBuffer commandBuffer, uint32_t coverageModulationTableCount, const float* pCoverageModulationTable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageModulationTableNV( coverageModulationTableCount, pCoverageModulationTable );
// #else
//         s_MockPtr->_SetCoverageModulationTableNV( commandBuffer, coverageModulationTableCount, pCoverageModulationTable );
// #endif
//     }

//     void vkInterface::SetShadingRateImageEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 shadingRateImageEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setShadingRateImageEnableNV( shadingRateImageEnable );
// #else
//         s_MockPtr->_SetShadingRateImageEnableNV( commandBuffer, shadingRateImageEnable );
// #endif
//     }

//     void vkInterface::SetRepresentativeFragmentTestEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 representativeFragmentTestEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setRepresentativeFragmentTestEnableNV( representativeFragmentTestEnable );
// #else
//         s_MockPtr->_SetRepresentativeFragmentTestEnableNV( commandBuffer, representativeFragmentTestEnable );
// #endif
//     }

//     void vkInterface::SetCoverageReductionModeNV( vk::CommandBuffer commandBuffer, vk::CoverageReductionModeNV coverageReductionMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setCoverageReductionModeNV( coverageReductionMode );
// #else
//         s_MockPtr->_SetCoverageReductionModeNV( commandBuffer, coverageReductionMode );
// #endif
//     }

//     void vkInterface::OpticalFlowExecuteNV( vk::CommandBuffer commandBuffer, vk::OpticalFlowSessionNV session, const vk::OpticalFlowExecuteInfoNV* pExecuteInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.opticalFlowExecuteNV( session, pExecuteInfo );
// #else
//         s_MockPtr->_OpticalFlowExecuteNV( commandBuffer, session, pExecuteInfo );
// #endif
//     }

//     void vkInterface::BindIndexBuffer2KHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, vk::DeviceSize size, vk::IndexType indexType )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindIndexBuffer2KHR( buffer, offset, size, indexType );
// #else
//         s_MockPtr->_BindIndexBuffer2KHR( commandBuffer, buffer, offset, size, indexType );
// #endif
//     }

//     void vkInterface::BindShadersEXT( vk::CommandBuffer commandBuffer, uint32_t stageCount, const vk::ShaderStageFlagBits* pStages, const vk::ShaderEXT* pShaders )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.bindShadersEXT( stageCount, pStages, pShaders );
// #else
//         s_MockPtr->_BindShadersEXT( commandBuffer, stageCount, pStages, pShaders );
// #endif
//     }

//     void vkInterface::SetAttachmentFeedbackLoopEnableEXT( vk::CommandBuffer commandBuffer, vk::ImageAspectFlags aspectMask )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         commandBuffer.setAttachmentFeedbackLoopEnableEXT( aspectMask );
// #else
//         s_MockPtr->_SetAttachmentFeedbackLoopEnableEXT( commandBuffer, aspectMask );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::Submit( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo* pSubmits, vk::Fence fence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.submit( submitCount, pSubmits, fence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_Submit( queue, submitCount, pSubmits, fence );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitIdle( vk::Queue queue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.waitIdle();
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitIdle( queue );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindSparse( vk::Queue queue, uint32_t bindInfoCount, const vk::BindSparseInfo* pBindInfo, vk::Fence fence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.bindSparse( bindInfoCount, pBindInfo, fence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindSparse( queue, bindInfoCount, pBindInfo, fence );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::Submit2( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo2* pSubmits, vk::Fence fence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.submit2( submitCount, pSubmits, fence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_Submit2( queue, submitCount, pSubmits, fence );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::PresentKHR( vk::Queue queue, const vk::PresentInfoKHR* pPresentInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.presentKHR( pPresentInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_PresentKHR( queue, pPresentInfo );
// #endif
//     }

//     void vkInterface::BeginDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         queue.beginDebugUtilsLabelEXT( pLabelInfo );
// #else
//         s_MockPtr->_BeginDebugUtilsLabelEXT( queue, pLabelInfo );
// #endif
//     }

//     void vkInterface::EndDebugUtilsLabelEXT( vk::Queue queue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         queue.endDebugUtilsLabelEXT();
// #else
//         s_MockPtr->_EndDebugUtilsLabelEXT( queue );
// #endif
//     }

//     void vkInterface::InsertDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         queue.insertDebugUtilsLabelEXT( pLabelInfo );
// #else
//         s_MockPtr->_InsertDebugUtilsLabelEXT( queue, pLabelInfo );
// #endif
//     }

//     void vkInterface::GetCheckpointDataNV( vk::Queue queue, uint32_t* pCheckpointDataCount, vk::CheckpointDataNV* pCheckpointData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         queue.getCheckpointDataNV( pCheckpointDataCount, pCheckpointData );
// #else
//         s_MockPtr->_GetCheckpointDataNV( queue, pCheckpointDataCount, pCheckpointData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::CheckpointDataNV, std::allocator<vk::CheckpointDataNV>>> vkInterface::GetCheckpointDataNV( vk::Queue queue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.getCheckpointDataNV();
//         return ResultValue<vk::Result, std::vector<vk::CheckpointDataNV, std::allocator<vk::CheckpointDataNV>>>( res );
// #else
//         return s_MockPtr->_GetCheckpointDataNV( queue );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPerformanceConfigurationINTEL( vk::Queue queue, vk::PerformanceConfigurationINTEL configuration )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.setPerformanceConfigurationINTEL( configuration );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPerformanceConfigurationINTEL( queue, configuration );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::Submit2KHR( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo2* pSubmits, vk::Fence fence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.submit2KHR( submitCount, pSubmits, fence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_Submit2KHR( queue, submitCount, pSubmits, fence );
// #endif
//     }

//     void vkInterface::GetCheckpointData2NV( vk::Queue queue, uint32_t* pCheckpointDataCount, vk::CheckpointData2NV* pCheckpointData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         queue.getCheckpointData2NV( pCheckpointDataCount, pCheckpointData );
// #else
//         s_MockPtr->_GetCheckpointData2NV( queue, pCheckpointDataCount, pCheckpointData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::CheckpointData2NV, std::allocator<vk::CheckpointData2NV>>> vkInterface::GetCheckpointData2NV( vk::Queue queue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = queue.getCheckpointData2NV();
//         return ResultValue<vk::Result, std::vector<vk::CheckpointData2NV, std::allocator<vk::CheckpointData2NV>>>( res );
// #else
//         return s_MockPtr->_GetCheckpointData2NV( queue );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pAllocator );
// #else
//         s_MockPtr->_Destroy( device, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( allocator );
// #else
//         s_MockPtr->_Destroy( device, allocator );
// #endif
//     }

//     void vkInterface::GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex, vk::Queue* pQueue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getQueue( queueFamilyIndex, queueIndex, pQueue );
// #else
//         s_MockPtr->_GetQueue( device, queueFamilyIndex, queueIndex, pQueue );
// #endif
//     }

//     ResultValue<vk::Result, vk::Queue> vkInterface::GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getQueue( queueFamilyIndex, queueIndex );
//         return ResultValue<vk::Result, vk::Queue>( res );
// #else
//         return s_MockPtr->_GetQueue( device, queueFamilyIndex, queueIndex );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitIdle( vk::Device device )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitIdle();
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitIdle( device );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::AllocateMemory( vk::Device device, const vk::MemoryAllocateInfo* pAllocateInfo, const vk::AllocationCallbacks* pAllocator, vk::DeviceMemory* pMemory )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.allocateMemory( pAllocateInfo, pAllocator, pMemory );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_AllocateMemory( device, pAllocateInfo, pAllocator, pMemory );
#endif
    }

    ResultValue<vk::Result, vk::DeviceMemory> vkInterface::AllocateMemory( vk::Device device, const vk::MemoryAllocateInfo& allocateInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.allocateMemory( allocateInfo, allocator );
        return ResultValue<vk::Result, vk::DeviceMemory>( res );
#else
        return s_MockPtr->_AllocateMemory( device, allocateInfo, allocator );
#endif
    }

//     void vkInterface::FreeMemory( vk::Device device, vk::DeviceMemory memory, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.freeMemory( memory, pAllocator );
// #else
//         s_MockPtr->_FreeMemory( device, memory, pAllocator );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::MapMemory( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize offset, vk::DeviceSize size, vk::MemoryMapFlags flags, void** ppData )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.mapMemory( memory, offset, size, flags, ppData );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_MapMemory( device, memory, offset, size, flags, ppData );
#endif
    }

    ResultValue<vk::Result, void*> vkInterface::MapMemory( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize offset,
                                                     vk::DeviceSize size, vk::MemoryMapFlags flags )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.mapMemory( memory, offset, size, flags );
        return ResultValue<vk::Result, void*>( res );
#else
        return s_MockPtr->_MapMemory( device, memory, offset, size, flags );
#endif
    }
    
    void vkInterface::UnmapMemory( vk::Device device, vk::DeviceMemory memory )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.unmapMemory( memory );
#else
        s_MockPtr->_UnmapMemory( device, memory );
#endif
    }

//     ResultValueType<vk::Result> vkInterface::FlushMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount, const vk::MappedMemoryRange* pMemoryRanges )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.flushMappedMemoryRanges( memoryRangeCount, pMemoryRanges );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_FlushMappedMemoryRanges( device, memoryRangeCount, pMemoryRanges );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::InvalidateMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount, const vk::MappedMemoryRange* pMemoryRanges )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.invalidateMappedMemoryRanges( memoryRangeCount, pMemoryRanges );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_InvalidateMappedMemoryRanges( device, memoryRangeCount, pMemoryRanges );
// #endif
//     }

//     void vkInterface::GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize* pCommittedMemoryInBytes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getMemoryCommitment( memory, pCommittedMemoryInBytes );
// #else
//         s_MockPtr->_GetMemoryCommitment( device, memory, pCommittedMemoryInBytes );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceSize> vkInterface::GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryCommitment( memory );
//         return ResultValue<vk::Result, vk::DeviceSize>( res );
// #else
//         return s_MockPtr->_GetMemoryCommitment( device, memory );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory, vk::DeviceSize memoryOffset )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.bindBufferMemory( buffer, memory, memoryOffset );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_BindBufferMemory( device, buffer, memory, memoryOffset );
#endif
    }

    ResultValueType<vk::Result> vkInterface::BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory, vk::DeviceSize memoryOffset )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.bindImageMemory( image, memory, memoryOffset );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_BindImageMemory( device, image, memory, memoryOffset );
#endif
    }

    void vkInterface::GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer, vk::MemoryRequirements* pMemoryRequirements )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.getBufferMemoryRequirements( buffer, pMemoryRequirements );
#else
        s_MockPtr->_GetBufferMemoryRequirements( device, buffer, pMemoryRequirements );
#endif
    }

    ResultValue<vk::Result, vk::MemoryRequirements> vkInterface::GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.getBufferMemoryRequirements( buffer );
        return ResultValue<vk::Result, vk::MemoryRequirements>( res );
#else
        return s_MockPtr->_GetBufferMemoryRequirements( device, buffer );
#endif
    }

    void vkInterface::GetImageMemoryRequirements( vk::Device device, vk::Image image, vk::MemoryRequirements* pMemoryRequirements )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.getImageMemoryRequirements( image, pMemoryRequirements );
#else
        s_MockPtr->_GetImageMemoryRequirements( device, image, pMemoryRequirements );
#endif
    }

    ResultValue<vk::Result, vk::MemoryRequirements> vkInterface::GetImageMemoryRequirements( vk::Device device, vk::Image image )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.getImageMemoryRequirements( image );
        return ResultValue<vk::Result, vk::MemoryRequirements>( res );
#else
        return s_MockPtr->_GetImageMemoryRequirements( device, image );
#endif
    }

//     void vkInterface::GetImageSparseMemoryRequirements( vk::Device device, vk::Image image, uint32_t* pSparseMemoryRequirementCount, vk::SparseImageMemoryRequirements* pSparseMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSparseMemoryRequirements( image, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #else
//         s_MockPtr->_GetImageSparseMemoryRequirements( device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::SparseImageMemoryRequirements, std::allocator<vk::SparseImageMemoryRequirements>>> vkInterface::GetImageSparseMemoryRequirements( vk::Device device, vk::Image image )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageSparseMemoryRequirements( image );
//         return ResultValue<vk::Result, std::vector<vk::SparseImageMemoryRequirements, std::allocator<vk::SparseImageMemoryRequirements>>>( res );
// #else
//         return s_MockPtr->_GetImageSparseMemoryRequirements( device, image );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateFence( vk::Device device, const vk::FenceCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createFence( pCreateInfo, pAllocator, pFence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateFence( device, pCreateInfo, pAllocator, pFence );
// #endif
//     }

//     ResultValue<vk::Result, vk::Fence> vkInterface::CreateFence( vk::Device device, const vk::FenceCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createFence( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Fence>( res );
// #else
//         return s_MockPtr->_CreateFence( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyFence( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyFence( fence, pAllocator );
// #else
//         s_MockPtr->_DestroyFence( device, fence, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( fence, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, fence, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Fence fence, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( fence, allocator );
// #else
//         s_MockPtr->_Destroy( device, fence, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ResetFences( vk::Device device, uint32_t fenceCount, const vk::Fence* pFences )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.resetFences( fenceCount, pFences );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ResetFences( device, fenceCount, pFences );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetFenceStatus( vk::Device device, vk::Fence fence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getFenceStatus( fence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetFenceStatus( device, fence );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitForFences( vk::Device device, uint32_t fenceCount, const vk::Fence* pFences, vk::Bool32 waitAll, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitForFences( fenceCount, pFences, waitAll, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitForFences( device, fenceCount, pFences, waitAll, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Semaphore* pSemaphore )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSemaphore( pCreateInfo, pAllocator, pSemaphore );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSemaphore( device, pCreateInfo, pAllocator, pSemaphore );
// #endif
//     }

//     ResultValue<vk::Result, vk::Semaphore> vkInterface::CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSemaphore( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Semaphore>( res );
// #else
//         return s_MockPtr->_CreateSemaphore( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroySemaphore( vk::Device device, vk::Semaphore semaphore, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroySemaphore( semaphore, pAllocator );
// #else
//         s_MockPtr->_DestroySemaphore( device, semaphore, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Semaphore semaphore, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( semaphore, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, semaphore, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Semaphore semaphore, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( semaphore, allocator );
// #else
//         s_MockPtr->_Destroy( device, semaphore, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateEvent( vk::Device device, const vk::EventCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Event* pEvent )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createEvent( pCreateInfo, pAllocator, pEvent );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateEvent( device, pCreateInfo, pAllocator, pEvent );
// #endif
//     }

//     ResultValue<vk::Result, vk::Event> vkInterface::CreateEvent( vk::Device device, const vk::EventCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createEvent( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Event>( res );
// #else
//         return s_MockPtr->_CreateEvent( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyEvent( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyEvent( event, pAllocator );
// #else
//         s_MockPtr->_DestroyEvent( device, event, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( event, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, event, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Event event, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( event, allocator );
// #else
//         s_MockPtr->_Destroy( device, event, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetEventStatus( vk::Device device, vk::Event event )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getEventStatus( event );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetEventStatus( device, event );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetEvent( vk::Device device, vk::Event event )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.setEvent( event );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetEvent( device, event );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ResetEvent( vk::Device device, vk::Event event )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.resetEvent( event );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ResetEvent( device, event );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::QueryPool* pQueryPool )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createQueryPool( pCreateInfo, pAllocator, pQueryPool );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateQueryPool( device, pCreateInfo, pAllocator, pQueryPool );
// #endif
//     }

//     ResultValue<vk::Result, vk::QueryPool> vkInterface::CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createQueryPool( createInfo, allocator );
//         return ResultValue<vk::Result, vk::QueryPool>( res );
// #else
//         return s_MockPtr->_CreateQueryPool( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyQueryPool( vk::Device device, vk::QueryPool queryPool, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyQueryPool( queryPool, pAllocator );
// #else
//         s_MockPtr->_DestroyQueryPool( device, queryPool, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::QueryPool queryPool, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( queryPool, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, queryPool, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::QueryPool queryPool, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( queryPool, allocator );
// #else
//         s_MockPtr->_Destroy( device, queryPool, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount, size_t dataSize, void* pData, vk::DeviceSize stride, vk::QueryResultFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getQueryPoolResults( queryPool, firstQuery, queryCount, dataSize, pData, stride, flags );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetQueryPoolResults( device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::CreateBuffer( vk::Device device, const vk::BufferCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Buffer* pBuffer )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createBuffer( pCreateInfo, pAllocator, pBuffer );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_CreateBuffer( device, pCreateInfo, pAllocator, pBuffer );
#endif
    }

    ResultValue<vk::Result, vk::Buffer> vkInterface::CreateBuffer( vk::Device device, const vk::BufferCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createBuffer( createInfo, allocator );
        return ResultValue<vk::Result, vk::Buffer>( res );
#else
        return s_MockPtr->_CreateBuffer( device, createInfo, allocator );
#endif
    }

//     void vkInterface::DestroyBuffer( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyBuffer( buffer, pAllocator );
// #else
//         s_MockPtr->_DestroyBuffer( device, buffer, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( buffer, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, buffer, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Buffer buffer, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( buffer, allocator );
// #else
//         s_MockPtr->_Destroy( device, buffer, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::BufferView* pView )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createBufferView( pCreateInfo, pAllocator, pView );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateBufferView( device, pCreateInfo, pAllocator, pView );
// #endif
//     }

//     ResultValue<vk::Result, vk::BufferView> vkInterface::CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createBufferView( createInfo, allocator );
//         return ResultValue<vk::Result, vk::BufferView>( res );
// #else
//         return s_MockPtr->_CreateBufferView( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyBufferView( vk::Device device, vk::BufferView bufferView, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyBufferView( bufferView, pAllocator );
// #else
//         s_MockPtr->_DestroyBufferView( device, bufferView, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::BufferView bufferView, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( bufferView, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, bufferView, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::BufferView bufferView, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( bufferView, allocator );
// #else
//         s_MockPtr->_Destroy( device, bufferView, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateImage( vk::Device device, const vk::ImageCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Image* pImage )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createImage( pCreateInfo, pAllocator, pImage );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateImage( device, pCreateInfo, pAllocator, pImage );
// #endif
//     }

//     ResultValue<vk::Result, vk::Image> vkInterface::CreateImage( vk::Device device, const vk::ImageCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createImage( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Image>( res );
// #else
//         return s_MockPtr->_CreateImage( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyImage( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyImage( image, pAllocator );
// #else
//         s_MockPtr->_DestroyImage( device, image, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( image, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, image, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Image image, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( image, allocator );
// #else
//         s_MockPtr->_Destroy( device, image, allocator );
// #endif
//     }

//     void vkInterface::GetImageSubresourceLayout( vk::Device device, vk::Image image, const vk::ImageSubresource* pSubresource, vk::SubresourceLayout* pLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSubresourceLayout( image, pSubresource, pLayout );
// #else
//         s_MockPtr->_GetImageSubresourceLayout( device, image, pSubresource, pLayout );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::CreateImageView( vk::Device device, const vk::ImageViewCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::ImageView* pView )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createImageView( pCreateInfo, pAllocator, pView );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_CreateImageView( device, pCreateInfo, pAllocator, pView );
#endif
    }

    ResultValue<vk::Result, vk::ImageView> vkInterface::CreateImageView( vk::Device device, const vk::ImageViewCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createImageView( createInfo, allocator );
        return ResultValue<vk::Result, vk::ImageView>( res );
#else
        return s_MockPtr->_CreateImageView( device, createInfo, allocator );
#endif
    }

    void vkInterface::DestroyImageView( vk::Device device, vk::ImageView imageView, const vk::AllocationCallbacks* pAllocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.destroyImageView( imageView, pAllocator );
#else
        s_MockPtr->_DestroyImageView( device, imageView, pAllocator );
#endif
    }

//     void vkInterface::Destroy( vk::Device device, vk::ImageView imageView, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( imageView, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, imageView, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ImageView imageView, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( imageView, allocator );
// #else
//         s_MockPtr->_Destroy( device, imageView, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::ShaderModule* pShaderModule )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createShaderModule( pCreateInfo, pAllocator, pShaderModule );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateShaderModule( device, pCreateInfo, pAllocator, pShaderModule );
// #endif
//     }

//     ResultValue<vk::Result, vk::ShaderModule> vkInterface::CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createShaderModule( createInfo, allocator );
//         return ResultValue<vk::Result, vk::ShaderModule>( res );
// #else
//         return s_MockPtr->_CreateShaderModule( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyShaderModule( shaderModule, pAllocator );
// #else
//         s_MockPtr->_DestroyShaderModule( device, shaderModule, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ShaderModule shaderModule, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( shaderModule, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, shaderModule, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ShaderModule shaderModule, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( shaderModule, allocator );
// #else
//         s_MockPtr->_Destroy( device, shaderModule, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::PipelineCache* pPipelineCache )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPipelineCache( pCreateInfo, pAllocator, pPipelineCache );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreatePipelineCache( device, pCreateInfo, pAllocator, pPipelineCache );
// #endif
//     }

//     ResultValue<vk::Result, vk::PipelineCache> vkInterface::CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPipelineCache( createInfo, allocator );
//         return ResultValue<vk::Result, vk::PipelineCache>( res );
// #else
//         return s_MockPtr->_CreatePipelineCache( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyPipelineCache( pipelineCache, pAllocator );
// #else
//         s_MockPtr->_DestroyPipelineCache( device, pipelineCache, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PipelineCache pipelineCache, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipelineCache, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, pipelineCache, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PipelineCache pipelineCache, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipelineCache, allocator );
// #else
//         s_MockPtr->_Destroy( device, pipelineCache, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache, size_t* pDataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelineCacheData( pipelineCache, pDataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPipelineCacheData( device, pipelineCache, pDataSize, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::MergePipelineCaches( vk::Device device, vk::PipelineCache dstCache, uint32_t srcCacheCount, const vk::PipelineCache* pSrcCaches )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.mergePipelineCaches( dstCache, srcCacheCount, pSrcCaches );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_MergePipelineCaches( device, dstCache, srcCacheCount, pSrcCaches );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount, const vk::GraphicsPipelineCreateInfo* pCreateInfos, const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createGraphicsPipelines( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateGraphicsPipelines( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
// #endif
//     }

//     ResultValue<vk::Result, vk::Pipeline> vkInterface::CreateGraphicsPipeline( vk::Device device, vk::PipelineCache pipelineCache, const vk::GraphicsPipelineCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createGraphicsPipeline( pipelineCache, createInfo, allocator );
//         return ResultValue<vk::Result, vk::Pipeline>( res );
// #else
//         return s_MockPtr->_CreateGraphicsPipeline( device, pipelineCache, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount, const vk::ComputePipelineCreateInfo* pCreateInfos, const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createComputePipelines( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateComputePipelines( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
// #endif
//     }

//     ResultValue<vk::Result, vk::Pipeline> vkInterface::CreateComputePipeline( vk::Device device, vk::PipelineCache pipelineCache, const vk::ComputePipelineCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createComputePipeline( pipelineCache, createInfo, allocator );
//         return ResultValue<vk::Result, vk::Pipeline>( res );
// #else
//         return s_MockPtr->_CreateComputePipeline( device, pipelineCache, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyPipeline( vk::Device device, vk::Pipeline pipeline, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyPipeline( pipeline, pAllocator );
// #else
//         s_MockPtr->_DestroyPipeline( device, pipeline, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Pipeline pipeline, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipeline, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, pipeline, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Pipeline pipeline, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipeline, allocator );
// #else
//         s_MockPtr->_Destroy( device, pipeline, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::PipelineLayout* pPipelineLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPipelineLayout( pCreateInfo, pAllocator, pPipelineLayout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreatePipelineLayout( device, pCreateInfo, pAllocator, pPipelineLayout );
// #endif
//     }

//     ResultValue<vk::Result, vk::PipelineLayout> vkInterface::CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPipelineLayout( createInfo, allocator );
//         return ResultValue<vk::Result, vk::PipelineLayout>( res );
// #else
//         return s_MockPtr->_CreatePipelineLayout( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyPipelineLayout( pipelineLayout, pAllocator );
// #else
//         s_MockPtr->_DestroyPipelineLayout( device, pipelineLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PipelineLayout pipelineLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipelineLayout, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, pipelineLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PipelineLayout pipelineLayout, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( pipelineLayout, allocator );
// #else
//         s_MockPtr->_Destroy( device, pipelineLayout, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSampler( vk::Device device, const vk::SamplerCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Sampler* pSampler )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSampler( pCreateInfo, pAllocator, pSampler );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSampler( device, pCreateInfo, pAllocator, pSampler );
// #endif
//     }

//     ResultValue<vk::Result, vk::Sampler> vkInterface::CreateSampler( vk::Device device, const vk::SamplerCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSampler( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Sampler>( res );
// #else
//         return s_MockPtr->_CreateSampler( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroySampler( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroySampler( sampler, pAllocator );
// #else
//         s_MockPtr->_DestroySampler( device, sampler, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( sampler, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, sampler, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Sampler sampler, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( sampler, allocator );
// #else
//         s_MockPtr->_Destroy( device, sampler, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DescriptorSetLayout* pSetLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorSetLayout( pCreateInfo, pAllocator, pSetLayout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDescriptorSetLayout( device, pCreateInfo, pAllocator, pSetLayout );
// #endif
//     }

//     ResultValue<vk::Result, vk::DescriptorSetLayout> vkInterface::CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorSetLayout( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DescriptorSetLayout>( res );
// #else
//         return s_MockPtr->_CreateDescriptorSetLayout( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyDescriptorSetLayout( descriptorSetLayout, pAllocator );
// #else
//         s_MockPtr->_DestroyDescriptorSetLayout( device, descriptorSetLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorSetLayout, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorSetLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorSetLayout, allocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorSetLayout, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DescriptorPool* pDescriptorPool )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorPool( pCreateInfo, pAllocator, pDescriptorPool );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDescriptorPool( device, pCreateInfo, pAllocator, pDescriptorPool );
// #endif
//     }

//     ResultValue<vk::Result, vk::DescriptorPool> vkInterface::CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorPool( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DescriptorPool>( res );
// #else
//         return s_MockPtr->_CreateDescriptorPool( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyDescriptorPool( descriptorPool, pAllocator );
// #else
//         s_MockPtr->_DestroyDescriptorPool( device, descriptorPool, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorPool descriptorPool, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorPool, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorPool, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorPool descriptorPool, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorPool, allocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorPool, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ResetDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool, vk::DescriptorPoolResetFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.resetDescriptorPool( descriptorPool, flags );
//         return ResultValueType<vk::Result>( vk::Result::eSuccess );
// #else
//         s_MockPtr->_ResetDescriptorPool( device, descriptorPool, flags );
//         return ResultValueType<vk::Result>( vk::Result::eSuccess );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AllocateDescriptorSets( vk::Device device, const vk::DescriptorSetAllocateInfo* pAllocateInfo, vk::DescriptorSet* pDescriptorSets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.allocateDescriptorSets( pAllocateInfo, pDescriptorSets );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AllocateDescriptorSets( device, pAllocateInfo, pDescriptorSets );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::FreeDescriptorSets( vk::Device device, vk::DescriptorPool descriptorPool, uint32_t descriptorSetCount, const vk::DescriptorSet* pDescriptorSets )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.freeDescriptorSets( descriptorPool, descriptorSetCount, pDescriptorSets );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_FreeDescriptorSets( device, descriptorPool, descriptorSetCount, pDescriptorSets );
// #endif
//     }

//     void vkInterface::UpdateDescriptorSets( vk::Device device, uint32_t descriptorWriteCount, const vk::WriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount, const vk::CopyDescriptorSet* pDescriptorCopies )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.updateDescriptorSets( descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies );
// #else
//         s_MockPtr->_UpdateDescriptorSets( device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Framebuffer* pFramebuffer )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createFramebuffer( pCreateInfo, pAllocator, pFramebuffer );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateFramebuffer( device, pCreateInfo, pAllocator, pFramebuffer );
// #endif
//     }

//     ResultValue<vk::Result, vk::Framebuffer> vkInterface::CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createFramebuffer( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Framebuffer>( res );
// #else
//         return s_MockPtr->_CreateFramebuffer( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyFramebuffer( framebuffer, pAllocator );
// #else
//         s_MockPtr->_DestroyFramebuffer( device, framebuffer, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Framebuffer framebuffer, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( framebuffer, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, framebuffer, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::Framebuffer framebuffer, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( framebuffer, allocator );
// #else
//         s_MockPtr->_Destroy( device, framebuffer, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass( pCreateInfo, pAllocator, pRenderPass );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateRenderPass( device, pCreateInfo, pAllocator, pRenderPass );
// #endif
//     }

//     ResultValue<vk::Result, vk::RenderPass> vkInterface::CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass( createInfo, allocator );
//         return ResultValue<vk::Result, vk::RenderPass>( res );
// #else
//         return s_MockPtr->_CreateRenderPass( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyRenderPass( vk::Device device, vk::RenderPass renderPass, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyRenderPass( renderPass, pAllocator );
// #else
//         s_MockPtr->_DestroyRenderPass( device, renderPass, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::RenderPass renderPass, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( renderPass, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, renderPass, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::RenderPass renderPass, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( renderPass, allocator );
// #else
//         s_MockPtr->_Destroy( device, renderPass, allocator );
// #endif
//     }

//     void vkInterface::GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass, vk::Extent2D* pGranularity )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getRenderAreaGranularity( renderPass, pGranularity );
// #else
//         s_MockPtr->_GetRenderAreaGranularity( device, renderPass, pGranularity );
// #endif
//     }

//     ResultValue<vk::Result, vk::Extent2D> vkInterface::GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRenderAreaGranularity( renderPass );
//         return ResultValue<vk::Result, vk::Extent2D>( res );
// #else
//         return s_MockPtr->_GetRenderAreaGranularity( device, renderPass );
// #endif
//     }

    ResultValueType<vk::Result> vkInterface::CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::CommandPool* pCommandPool )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createCommandPool( pCreateInfo, pAllocator, pCommandPool );
        return ResultValueType<vk::Result>( res );
#else
        return s_MockPtr->_CreateCommandPool( device, pCreateInfo, pAllocator, pCommandPool );
#endif
    }

    ResultValue<vk::Result, vk::CommandPool> vkInterface::CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.createCommandPool( createInfo, allocator );
        return ResultValue<vk::Result, vk::CommandPool>( res );
#else
        return s_MockPtr->_CreateCommandPool( device, createInfo, allocator );
#endif
    }

    void vkInterface::DestroyCommandPool( vk::Device device, vk::CommandPool commandPool, const vk::AllocationCallbacks* pAllocator )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.destroyCommandPool( commandPool, pAllocator );
#else
        s_MockPtr->_DestroyCommandPool( device, commandPool, pAllocator );
#endif
    }

//     void vkInterface::Destroy( vk::Device device, vk::CommandPool commandPool, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( commandPool, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, commandPool, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::CommandPool commandPool, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( commandPool, allocator );
// #else
//         s_MockPtr->_Destroy( device, commandPool, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ResetCommandPool( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolResetFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.resetCommandPool( commandPool, flags );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ResetCommandPool( device, commandPool, flags );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo* pAllocateInfo, vk::CommandBuffer* pCommandBuffers )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.allocateCommandBuffers( pAllocateInfo, pCommandBuffers );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AllocateCommandBuffers( device, pAllocateInfo, pCommandBuffers );
// #endif
//     }

    ResultValue<vk::Result, std::vector<vk::CommandBuffer>> vkInterface::AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = device.allocateCommandBuffers( allocateInfo );
        return ResultValue<vk::Result, std::vector<vk::CommandBuffer>>( res );
#else
        return s_MockPtr->_AllocateCommandBuffers( device, allocateInfo );
#endif
    }

    void vkInterface::FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, uint32_t commandBufferCount, const vk::CommandBuffer* pCommandBuffers )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.freeCommandBuffers( commandPool, commandBufferCount, pCommandBuffers );
#else
        s_MockPtr->_FreeCommandBuffers( device, commandPool, commandBufferCount, pCommandBuffers );
#endif
    }

//     ResultValueType<vk::Result> vkInterface::BindBufferMemory2( vk::Device device, uint32_t bindInfoCount, const vk::BindBufferMemoryInfo* pBindInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindBufferMemory2( bindInfoCount, pBindInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindBufferMemory2( device, bindInfoCount, pBindInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindImageMemory2( vk::Device device, uint32_t bindInfoCount, const vk::BindImageMemoryInfo* pBindInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindImageMemory2( bindInfoCount, pBindInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindImageMemory2( device, bindInfoCount, pBindInfos );
// #endif
//     }

//     void vkInterface::GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getGroupPeerMemoryFeatures( heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
// #else
//         s_MockPtr->_GetGroupPeerMemoryFeatures( device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
// #endif
//     }

//     ResultValue<vk::Result, vk::PeerMemoryFeatureFlags> vkInterface::GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupPeerMemoryFeatures( heapIndex, localDeviceIndex, remoteDeviceIndex );
//         return ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>( res );
// #else
//         return s_MockPtr->_GetGroupPeerMemoryFeatures( device, heapIndex, localDeviceIndex, remoteDeviceIndex );
// #endif
//     }

//     void vkInterface::GetImageMemoryRequirements2( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        // device.getImageMemoryRequirements2( pInfo, pMemoryRequirements );
// #else
        // s_MockPtr->_GetImageMemoryRequirements2( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetBufferMemoryRequirements2( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getBufferMemoryRequirements2( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetBufferMemoryRequirements2( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetImageSparseMemoryRequirements2( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSparseMemoryRequirements2( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #else
//         s_MockPtr->_GetImageSparseMemoryRequirements2( device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #endif
//     }

//     void vkInterface::TrimCommandPool( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolTrimFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.trimCommandPool( commandPool, flags );
// #else
//         s_MockPtr->_TrimCommandPool( device, commandPool, flags );
// #endif
//     }

//     void vkInterface::GetQueue2( vk::Device device, const vk::DeviceQueueInfo2* pQueueInfo, vk::Queue* pQueue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getQueue2( pQueueInfo, pQueue );
// #else
//         s_MockPtr->_GetQueue2( device, pQueueInfo, pQueue );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SamplerYcbcrConversion* pYcbcrConversion )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSamplerYcbcrConversion( pCreateInfo, pAllocator, pYcbcrConversion );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSamplerYcbcrConversion( device, pCreateInfo, pAllocator, pYcbcrConversion );
// #endif
//     }

//     ResultValue<vk::Result, vk::SamplerYcbcrConversion> vkInterface::CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSamplerYcbcrConversion( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SamplerYcbcrConversion>( res );
// #else
//         return s_MockPtr->_CreateSamplerYcbcrConversion( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroySamplerYcbcrConversion( ycbcrConversion, pAllocator );
// #else
//         s_MockPtr->_DestroySamplerYcbcrConversion( device, ycbcrConversion, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( ycbcrConversion, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, ycbcrConversion, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( ycbcrConversion, allocator );
// #else
//         s_MockPtr->_Destroy( device, ycbcrConversion, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorUpdateTemplate( pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDescriptorUpdateTemplate( device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
// #endif
//     }

//     ResultValue<vk::Result, vk::DescriptorUpdateTemplate> vkInterface::CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorUpdateTemplate( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DescriptorUpdateTemplate>( res );
// #else
//         return s_MockPtr->_CreateDescriptorUpdateTemplate( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDescriptorUpdateTemplate( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyDescriptorUpdateTemplate( descriptorUpdateTemplate, pAllocator );
// #else
//         s_MockPtr->_DestroyDescriptorUpdateTemplate( device, descriptorUpdateTemplate, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorUpdateTemplate, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorUpdateTemplate, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( descriptorUpdateTemplate, allocator );
// #else
//         s_MockPtr->_Destroy( device, descriptorUpdateTemplate, allocator );
// #endif
//     }

//     void vkInterface::UpdateDescriptorSetWithTemplate( vk::Device device, vk::DescriptorSet descriptorSet, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.updateDescriptorSetWithTemplate( descriptorSet, descriptorUpdateTemplate, pData );
// #else
//         s_MockPtr->_UpdateDescriptorSetWithTemplate( device, descriptorSet, descriptorUpdateTemplate, pData );
// #endif
//     }

//     void vkInterface::GetDescriptorSetLayoutSupport( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo, vk::DescriptorSetLayoutSupport* pSupport )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetLayoutSupport( pCreateInfo, pSupport );
// #else
//         s_MockPtr->_GetDescriptorSetLayoutSupport( device, pCreateInfo, pSupport );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass2( pCreateInfo, pAllocator, pRenderPass );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateRenderPass2( device, pCreateInfo, pAllocator, pRenderPass );
// #endif
//     }

//     ResultValue<vk::Result, vk::RenderPass> vkInterface::CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass2( createInfo, allocator );
//         return ResultValue<vk::Result, vk::RenderPass>( res );
// #else
//         return s_MockPtr->_CreateRenderPass2( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::ResetQueryPool( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.resetQueryPool( queryPool, firstQuery, queryCount );
// #else
//         s_MockPtr->_ResetQueryPool( device, queryPool, firstQuery, queryCount );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore, uint64_t* pValue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreCounterValue( semaphore, pValue );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSemaphoreCounterValue( device, semaphore, pValue );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreCounterValue( semaphore );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetSemaphoreCounterValue( device, semaphore );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitSemaphores( pWaitInfo, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitSemaphores( device, pWaitInfo, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitSemaphores( waitInfo, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitSemaphores( device, waitInfo, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SignalSemaphore( vk::Device device, const vk::SemaphoreSignalInfo* pSignalInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.signalSemaphore( pSignalInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SignalSemaphore( device, pSignalInfo );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceAddress> vkInterface::GetBufferAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferAddress( pInfo );
//         return ResultValue<vk::Result, vk::DeviceAddress>( res );
// #else
//         return s_MockPtr->_GetBufferAddress( device, pInfo );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetBufferOpaqueCaptureAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferOpaqueCaptureAddress( pInfo );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetBufferOpaqueCaptureAddress( device, pInfo );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetMemoryOpaqueCaptureAddress( vk::Device device, const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryOpaqueCaptureAddress( pInfo );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetMemoryOpaqueCaptureAddress( device, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::PrivateDataSlot* pPrivateDataSlot )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPrivateDataSlot( pCreateInfo, pAllocator, pPrivateDataSlot );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreatePrivateDataSlot( device, pCreateInfo, pAllocator, pPrivateDataSlot );
// #endif
//     }

//     ResultValue<vk::Result, vk::PrivateDataSlot> vkInterface::CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPrivateDataSlot( createInfo, allocator );
//         return ResultValue<vk::Result, vk::PrivateDataSlot>( res );
// #else
//         return s_MockPtr->_CreatePrivateDataSlot( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyPrivateDataSlot( privateDataSlot, pAllocator );
// #else
//         s_MockPtr->_DestroyPrivateDataSlot( device, privateDataSlot, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( privateDataSlot, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, privateDataSlot, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( privateDataSlot, allocator );
// #else
//         s_MockPtr->_Destroy( device, privateDataSlot, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot, uint64_t data )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.setPrivateData( objectType_, objectHandle, privateDataSlot, data );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPrivateData( device, objectType_, objectHandle, privateDataSlot, data );
// #endif
//     }

//     void vkInterface::GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot, uint64_t* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getPrivateData( objectType_, objectHandle, privateDataSlot, pData );
// #else
//         s_MockPtr->_GetPrivateData( device, objectType_, objectHandle, privateDataSlot, pData );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPrivateData( objectType_, objectHandle, privateDataSlot );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetPrivateData( device, objectType_, objectHandle, privateDataSlot );
// #endif
//     }

    void vkInterface::GetBufferMemoryRequirements( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.getBufferMemoryRequirements( pInfo, pMemoryRequirements );
#else
        s_MockPtr->_GetBufferMemoryRequirements( device, pInfo, pMemoryRequirements );
#endif
    }

    void vkInterface::GetImageMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        device.getImageMemoryRequirements( pInfo, pMemoryRequirements );
#else
        s_MockPtr->_GetImageMemoryRequirements( device, pInfo, pMemoryRequirements );
#endif
    }

//     void vkInterface::GetImageSparseMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSparseMemoryRequirements( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #else
//         s_MockPtr->_GetImageSparseMemoryRequirements( device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SwapchainKHR* pSwapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSwapchainKHR( pCreateInfo, pAllocator, pSwapchain );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSwapchainKHR( device, pCreateInfo, pAllocator, pSwapchain );
// #endif
//     }

//     ResultValue<vk::Result, vk::SwapchainKHR> vkInterface::CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSwapchainKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SwapchainKHR>( res );
// #else
//         return s_MockPtr->_CreateSwapchainKHR( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroySwapchainKHR( swapchain, pAllocator );
// #else
//         s_MockPtr->_DestroySwapchainKHR( device, swapchain, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::SwapchainKHR swapchain, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( swapchain, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, swapchain, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::SwapchainKHR swapchain, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( swapchain, allocator );
// #else
//         s_MockPtr->_Destroy( device, swapchain, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain, uint32_t* pSwapchainImageCount, vk::Image* pSwapchainImages )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSwapchainImagesKHR( swapchain, pSwapchainImageCount, pSwapchainImages );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSwapchainImagesKHR( device, swapchain, pSwapchainImageCount, pSwapchainImages );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::Image, std::allocator<vk::Image>>> vkInterface::GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSwapchainImagesKHR( swapchain );
//         return ResultValue<vk::Result, std::vector<vk::Image, std::allocator<vk::Image>>>( res );
// #else
//         return s_MockPtr->_GetSwapchainImagesKHR( device, swapchain );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain, uint64_t timeout, vk::Semaphore semaphore, vk::Fence fence, uint32_t* pImageIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.acquireNextImageKHR( swapchain, timeout, semaphore, fence, pImageIndex );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireNextImageKHR( device, swapchain, timeout, semaphore, fence, pImageIndex );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetGroupPresentCapabilitiesKHR( vk::Device device, vk::DeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupPresentCapabilitiesKHR( pDeviceGroupPresentCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetGroupPresentCapabilitiesKHR( device, pDeviceGroupPresentCapabilities );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceGroupPresentCapabilitiesKHR> vkInterface::GetGroupPresentCapabilitiesKHR( vk::Device device )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupPresentCapabilitiesKHR();
//         return ResultValue<vk::Result, vk::DeviceGroupPresentCapabilitiesKHR>( res );
// #else
//         return s_MockPtr->_GetGroupPresentCapabilitiesKHR( device );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface, vk::DeviceGroupPresentModeFlagsKHR* pModes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupSurfacePresentModesKHR( surface, pModes );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetGroupSurfacePresentModesKHR( device, surface, pModes );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR> vkInterface::GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupSurfacePresentModesKHR( surface );
//         return ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR>( res );
// #else
//         return s_MockPtr->_GetGroupSurfacePresentModesKHR( device, surface );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireNextImage2KHR( vk::Device device, const vk::AcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.acquireNextImage2KHR( pAcquireInfo, pImageIndex );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireNextImage2KHR( device, pAcquireInfo, pImageIndex );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSharedSwapchainsKHR( vk::Device device, uint32_t swapchainCount, const vk::SwapchainCreateInfoKHR* pCreateInfos, const vk::AllocationCallbacks* pAllocator, vk::SwapchainKHR* pSwapchains )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSharedSwapchainsKHR( swapchainCount, pCreateInfos, pAllocator, pSwapchains );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSharedSwapchainsKHR( device, swapchainCount, pCreateInfos, pAllocator, pSwapchains );
// #endif
//     }

//     ResultValue<vk::Result, vk::SwapchainKHR> vkInterface::CreateSharedSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSharedSwapchainKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SwapchainKHR>( res );
// #else
//         return s_MockPtr->_CreateSharedSwapchainKHR( device, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::DebugMarkerSetObjectTagEXT( vk::Device device, const vk::DebugMarkerObjectTagInfoEXT* pTagInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.debugMarkerSetObjectTagEXT( pTagInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_DebugMarkerSetObjectTagEXT( device, pTagInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::DebugMarkerSetObjectNameEXT( vk::Device device, const vk::DebugMarkerObjectNameInfoEXT* pNameInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.debugMarkerSetObjectNameEXT( pNameInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_DebugMarkerSetObjectNameEXT( device, pNameInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::VideoSessionKHR* pVideoSession )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createVideoSessionKHR( pCreateInfo, pAllocator, pVideoSession );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateVideoSessionKHR( device, pCreateInfo, pAllocator, pVideoSession );
// #endif
//     }

//     ResultValue<vk::Result, vk::VideoSessionKHR> vkInterface::CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createVideoSessionKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::VideoSessionKHR>( res );
// #else
//         return s_MockPtr->_CreateVideoSessionKHR( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyVideoSessionKHR( videoSession, pAllocator );
// #else
//         s_MockPtr->_DestroyVideoSessionKHR( device, videoSession, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::VideoSessionKHR videoSession, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( videoSession, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, videoSession, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::VideoSessionKHR videoSession, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( videoSession, allocator );
// #else
//         s_MockPtr->_Destroy( device, videoSession, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindVideoSessionMemoryKHR( vk::Device device, vk::VideoSessionKHR videoSession, uint32_t bindSessionMemoryInfoCount, const vk::BindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindVideoSessionMemoryKHR( videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindVideoSessionMemoryKHR( device, videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::VideoSessionParametersKHR* pVideoSessionParameters )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createVideoSessionParametersKHR( pCreateInfo, pAllocator, pVideoSessionParameters );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateVideoSessionParametersKHR( device, pCreateInfo, pAllocator, pVideoSessionParameters );
// #endif
//     }

//     ResultValue<vk::Result, vk::VideoSessionParametersKHR> vkInterface::CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createVideoSessionParametersKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::VideoSessionParametersKHR>( res );
// #else
//         return s_MockPtr->_CreateVideoSessionParametersKHR( device, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::UpdateVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters, const vk::VideoSessionParametersUpdateInfoKHR* pUpdateInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.updateVideoSessionParametersKHR( videoSessionParameters, pUpdateInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_UpdateVideoSessionParametersKHR( device, videoSessionParameters, pUpdateInfo );
// #endif
//     }

//     void vkInterface::DestroyVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyVideoSessionParametersKHR( videoSessionParameters, pAllocator );
// #else
//         s_MockPtr->_DestroyVideoSessionParametersKHR( device, videoSessionParameters, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( videoSessionParameters, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, videoSessionParameters, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( videoSessionParameters, allocator );
// #else
//         s_MockPtr->_Destroy( device, videoSessionParameters, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::CuModuleNVX* pModule )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createCuModuleNVX( pCreateInfo, pAllocator, pModule );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateCuModuleNVX( device, pCreateInfo, pAllocator, pModule );
// #endif
//     }

//     ResultValue<vk::Result, vk::CuModuleNVX> vkInterface::CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createCuModuleNVX( createInfo, allocator );
//         return ResultValue<vk::Result, vk::CuModuleNVX>( res );
// #else
//         return s_MockPtr->_CreateCuModuleNVX( device, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::CuFunctionNVX* pFunction )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createCuFunctionNVX( pCreateInfo, pAllocator, pFunction );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateCuFunctionNVX( device, pCreateInfo, pAllocator, pFunction );
// #endif
//     }

//     ResultValue<vk::Result, vk::CuFunctionNVX> vkInterface::CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createCuFunctionNVX( createInfo, allocator );
//         return ResultValue<vk::Result, vk::CuFunctionNVX>( res );
// #else
//         return s_MockPtr->_CreateCuFunctionNVX( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyCuModuleNVX( module, pAllocator );
// #else
//         s_MockPtr->_DestroyCuModuleNVX( device, module, pAllocator );
// #endif
//     }

//     void vkInterface::DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyCuModuleNVX( module, allocator );
// #else
//         s_MockPtr->_DestroyCuModuleNVX( device, module, allocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::CuModuleNVX module, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( module, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, module, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::CuModuleNVX module, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( module, allocator );
// #else
//         s_MockPtr->_Destroy( device, module, allocator );
// #endif
//     }

//     void vkInterface::DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyCuFunctionNVX( function, pAllocator );
// #else
//         s_MockPtr->_DestroyCuFunctionNVX( device, function, pAllocator );
// #endif
//     }

//     void vkInterface::DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyCuFunctionNVX( function, allocator );
// #else
//         s_MockPtr->_DestroyCuFunctionNVX( device, function, allocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::CuFunctionNVX function, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( function, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, function, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::CuFunctionNVX function, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( function, allocator );
// #else
//         s_MockPtr->_Destroy( device, function, allocator );
// #endif
//     }

//     ResultValue<vk::Result, uint32_t> vkInterface::GetImageViewHandleNVX( vk::Device device, const vk::ImageViewHandleInfoNVX* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageViewHandleNVX( pInfo );
//         return ResultValue<vk::Result, uint32_t>( res );
// #else
//         return s_MockPtr->_GetImageViewHandleNVX( device, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView, vk::ImageViewAddressPropertiesNVX* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageViewAddressNVX( imageView, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageViewAddressNVX( device, imageView, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::ImageViewAddressPropertiesNVX> vkInterface::GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageViewAddressNVX( imageView );
//         return ResultValue<vk::Result, vk::ImageViewAddressPropertiesNVX>( res );
// #else
//         return s_MockPtr->_GetImageViewAddressNVX( device, imageView );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage, vk::ShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getShaderInfoAMD( pipeline, shaderStage, infoType, pInfoSize, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetShaderInfoAMD( device, pipeline, shaderStage, infoType, pInfoSize, pInfo );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage, vk::ShaderInfoTypeAMD infoType )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getShaderInfoAMD( pipeline, shaderStage, infoType );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetShaderInfoAMD( device, pipeline, shaderStage, infoType );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory, vk::ExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryWin32HandleNV( memory, handleType, pHandle );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryWin32HandleNV( device, memory, handleType, pHandle );
// #endif
//     }

//     ResultValue<vk::Result, HANDLE> vkInterface::GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory, vk::ExternalMemoryHandleTypeFlagsNV handleType )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryWin32HandleNV( memory, handleType );
//         return ResultValue<vk::Result, HANDLE>( res );
// #else
//         return s_MockPtr->_GetMemoryWin32HandleNV( device, memory, handleType );
// #endif
//     }

//     void vkInterface::GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex, vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getGroupPeerMemoryFeaturesKHR( heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
// #else
//         s_MockPtr->_GetGroupPeerMemoryFeaturesKHR( device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
// #endif
//     }

//     ResultValue<vk::Result, vk::PeerMemoryFeatureFlags> vkInterface::GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupPeerMemoryFeaturesKHR( heapIndex, localDeviceIndex, remoteDeviceIndex );
//         return ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>( res );
// #else
//         return s_MockPtr->_GetGroupPeerMemoryFeaturesKHR( device, heapIndex, localDeviceIndex, remoteDeviceIndex );
// #endif
//     }

//     void vkInterface::TrimCommandPoolKHR( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolTrimFlags flags )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.trimCommandPoolKHR( commandPool, flags );
// #else
//         s_MockPtr->_TrimCommandPoolKHR( device, commandPool, flags );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryWin32HandleKHR( vk::Device device, const vk::MemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryWin32HandleKHR( pGetWin32HandleInfo, pHandle );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, HANDLE handle, vk::MemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryWin32HandlePropertiesKHR( handleType, handle, pMemoryWin32HandleProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryWin32HandlePropertiesKHR( device, handleType, handle, pMemoryWin32HandleProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::MemoryWin32HandlePropertiesKHR> vkInterface::GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, HANDLE handle )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryWin32HandlePropertiesKHR( handleType, handle );
//         return ResultValue<vk::Result, vk::MemoryWin32HandlePropertiesKHR>( res );
// #else
//         return s_MockPtr->_GetMemoryWin32HandlePropertiesKHR( device, handleType, handle );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryFdKHR( vk::Device device, const vk::MemoryGetFdInfoKHR* pGetFdInfo, int* pFd )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryFdKHR( pGetFdInfo, pFd );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryFdKHR( device, pGetFdInfo, pFd );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd, vk::MemoryFdPropertiesKHR* pMemoryFdProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryFdPropertiesKHR( handleType, fd, pMemoryFdProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryFdPropertiesKHR( device, handleType, fd, pMemoryFdProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::MemoryFdPropertiesKHR> vkInterface::GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryFdPropertiesKHR( handleType, fd );
//         return ResultValue<vk::Result, vk::MemoryFdPropertiesKHR>( res );
// #else
//         return s_MockPtr->_GetMemoryFdPropertiesKHR( device, handleType, fd );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ImportSemaphoreWin32HandleKHR( vk::Device device, const vk::ImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.importSemaphoreWin32HandleKHR( pImportSemaphoreWin32HandleInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ImportSemaphoreWin32HandleKHR( device, pImportSemaphoreWin32HandleInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSemaphoreWin32HandleKHR( vk::Device device, const vk::SemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreWin32HandleKHR( pGetWin32HandleInfo, pHandle );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSemaphoreWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ImportSemaphoreFdKHR( vk::Device device, const vk::ImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.importSemaphoreFdKHR( pImportSemaphoreFdInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ImportSemaphoreFdKHR( device, pImportSemaphoreFdInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSemaphoreFdKHR( vk::Device device, const vk::SemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreFdKHR( pGetFdInfo, pFd );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSemaphoreFdKHR( device, pGetFdInfo, pFd );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorUpdateTemplateKHR( pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDescriptorUpdateTemplateKHR( device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
// #endif
//     }

//     ResultValue<vk::Result, vk::DescriptorUpdateTemplate> vkInterface::CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDescriptorUpdateTemplateKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DescriptorUpdateTemplate>( res );
// #else
//         return s_MockPtr->_CreateDescriptorUpdateTemplateKHR( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDescriptorUpdateTemplateKHR( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyDescriptorUpdateTemplateKHR( descriptorUpdateTemplate, pAllocator );
// #else
//         s_MockPtr->_DestroyDescriptorUpdateTemplateKHR( device, descriptorUpdateTemplate, pAllocator );
// #endif
//     }

//     void vkInterface::UpdateDescriptorSetWithTemplateKHR( vk::Device device, vk::DescriptorSet descriptorSet, vk::DescriptorUpdateTemplate descriptorUpdateTemplate, const void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.updateDescriptorSetWithTemplateKHR( descriptorSet, descriptorUpdateTemplate, pData );
// #else
//         s_MockPtr->_UpdateDescriptorSetWithTemplateKHR( device, descriptorSet, descriptorUpdateTemplate, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::DisplayPowerControlEXT( vk::Device device, vk::DisplayKHR display, const vk::DisplayPowerInfoEXT* pDisplayPowerInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.displayPowerControlEXT( display, pDisplayPowerInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_DisplayPowerControlEXT( device, display, pDisplayPowerInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT* pDeviceEventInfo, const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.registerEventEXT( pDeviceEventInfo, pAllocator, pFence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_RegisterEventEXT( device, pDeviceEventInfo, pAllocator, pFence );
// #endif
//     }

//     ResultValue<vk::Result, vk::Fence> vkInterface::RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT& deviceEventInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.registerEventEXT( deviceEventInfo, allocator );
//         return ResultValue<vk::Result, vk::Fence>( res );
// #else
//         return s_MockPtr->_RegisterEventEXT( device, deviceEventInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display, const vk::DisplayEventInfoEXT* pDisplayEventInfo, const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.registerDisplayEventEXT( display, pDisplayEventInfo, pAllocator, pFence );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_RegisterDisplayEventEXT( device, display, pDisplayEventInfo, pAllocator, pFence );
// #endif
//     }

//     ResultValue<vk::Result, vk::Fence> vkInterface::RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display, const vk::DisplayEventInfoEXT& displayEventInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.registerDisplayEventEXT( display, displayEventInfo, allocator );
//         return ResultValue<vk::Result, vk::Fence>( res );
// #else
//         return s_MockPtr->_RegisterDisplayEventEXT( device, display, displayEventInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain, vk::SurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSwapchainCounterEXT( swapchain, counter, pCounterValue );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSwapchainCounterEXT( device, swapchain, counter, pCounterValue );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain, vk::SurfaceCounterFlagBitsEXT counter )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSwapchainCounterEXT( swapchain, counter );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetSwapchainCounterEXT( device, swapchain, counter );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain, vk::RefreshCycleDurationGOOGLE* pDisplayTimingProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRefreshCycleDurationGOOGLE( swapchain, pDisplayTimingProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetRefreshCycleDurationGOOGLE( device, swapchain, pDisplayTimingProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::RefreshCycleDurationGOOGLE> vkInterface::GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRefreshCycleDurationGOOGLE( swapchain );
//         return ResultValue<vk::Result, vk::RefreshCycleDurationGOOGLE>( res );
// #else
//         return s_MockPtr->_GetRefreshCycleDurationGOOGLE( device, swapchain );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain, uint32_t* pPresentationTimingCount, vk::PastPresentationTimingGOOGLE* pPresentationTimings )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPastPresentationTimingGOOGLE( swapchain, pPresentationTimingCount, pPresentationTimings );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPastPresentationTimingGOOGLE( device, swapchain, pPresentationTimingCount, pPresentationTimings );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE, std::allocator<vk::PastPresentationTimingGOOGLE>>> vkInterface::GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPastPresentationTimingGOOGLE( swapchain );
//         return ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE, std::allocator<vk::PastPresentationTimingGOOGLE>>>( res );
// #else
//         return s_MockPtr->_GetPastPresentationTimingGOOGLE( device, swapchain );
// #endif
//     }

//     void vkInterface::SetHdrMetadataEXT( vk::Device device, uint32_t swapchainCount, const vk::SwapchainKHR* pSwapchains, const vk::HdrMetadataEXT* pMetadata )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.setHdrMetadataEXT( swapchainCount, pSwapchains, pMetadata );
// #else
//         s_MockPtr->_SetHdrMetadataEXT( device, swapchainCount, pSwapchains, pMetadata );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass2KHR( pCreateInfo, pAllocator, pRenderPass );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateRenderPass2KHR( device, pCreateInfo, pAllocator, pRenderPass );
// #endif
//     }

//     ResultValue<vk::Result, vk::RenderPass> vkInterface::CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRenderPass2KHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::RenderPass>( res );
// #else
//         return s_MockPtr->_CreateRenderPass2KHR( device, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSwapchainStatusKHR( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSwapchainStatusKHR( swapchain );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSwapchainStatusKHR( device, swapchain );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ImportFenceWin32HandleKHR( vk::Device device, const vk::ImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.importFenceWin32HandleKHR( pImportFenceWin32HandleInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ImportFenceWin32HandleKHR( device, pImportFenceWin32HandleInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetFenceWin32HandleKHR( vk::Device device, const vk::FenceGetWin32HandleInfoKHR* pGetWin32HandleInfo, HANDLE* pHandle )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getFenceWin32HandleKHR( pGetWin32HandleInfo, pHandle );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetFenceWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ImportFenceFdKHR( vk::Device device, const vk::ImportFenceFdInfoKHR* pImportFenceFdInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.importFenceFdKHR( pImportFenceFdInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ImportFenceFdKHR( device, pImportFenceFdInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetFenceFdKHR( vk::Device device, const vk::FenceGetFdInfoKHR* pGetFdInfo, int* pFd )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getFenceFdKHR( pGetFdInfo, pFd );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetFenceFdKHR( device, pGetFdInfo, pFd );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireProfilingLockKHR( vk::Device device, const vk::AcquireProfilingLockInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.acquireProfilingLockKHR( pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireProfilingLockKHR( device, pInfo );
// #endif
//     }

//     void vkInterface::ReleaseProfilingLockKHR( vk::Device device )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.releaseProfilingLockKHR();
// #else
//         s_MockPtr->_ReleaseProfilingLockKHR( device );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetDebugUtilsObjectNameEXT( vk::Device device, const vk::DebugUtilsObjectNameInfoEXT* pNameInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.setDebugUtilsObjectNameEXT( pNameInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetDebugUtilsObjectNameEXT( device, pNameInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetDebugUtilsObjectTagEXT( vk::Device device, const vk::DebugUtilsObjectTagInfoEXT* pTagInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.setDebugUtilsObjectTagEXT( pTagInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetDebugUtilsObjectTagEXT( device, pTagInfo );
// #endif
//     }

//     void vkInterface::GetImageMemoryRequirements2KHR( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageMemoryRequirements2KHR( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetImageMemoryRequirements2KHR( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetBufferMemoryRequirements2KHR( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getBufferMemoryRequirements2KHR( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetBufferMemoryRequirements2KHR( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetImageSparseMemoryRequirements2KHR( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo, uint32_t* pSparseMemoryRequirementCount, vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSparseMemoryRequirements2KHR( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #else
//         s_MockPtr->_GetImageSparseMemoryRequirements2KHR( device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::AccelerationStructureKHR* pAccelerationStructure )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createAccelerationStructureKHR( pCreateInfo, pAllocator, pAccelerationStructure );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateAccelerationStructureKHR( device, pCreateInfo, pAllocator, pAccelerationStructure );
// #endif
//     }

//     ResultValue<vk::Result, vk::AccelerationStructureKHR> vkInterface::CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createAccelerationStructureKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::AccelerationStructureKHR>( res );
// #else
//         return s_MockPtr->_CreateAccelerationStructureKHR( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyAccelerationStructureKHR( vk::Device device, vk::AccelerationStructureKHR accelerationStructure, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyAccelerationStructureKHR( accelerationStructure, pAllocator );
// #else
//         s_MockPtr->_DestroyAccelerationStructureKHR( device, accelerationStructure, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( accelerationStructure, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, accelerationStructure, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( accelerationStructure, allocator );
// #else
//         s_MockPtr->_Destroy( device, accelerationStructure, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BuildAccelerationStructuresKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, uint32_t infoCount, const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos, const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.buildAccelerationStructuresKHR( deferredOperation, infoCount, pInfos, ppBuildRangeInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BuildAccelerationStructuresKHR( device, deferredOperation, infoCount, pInfos, ppBuildRangeInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyAccelerationStructureInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyAccelerationStructureKHR( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyAccelerationStructureKHR( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyAccelerationStructureToMemoryKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyAccelerationStructureToMemoryKHR( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyAccelerationStructureToMemoryKHR( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyMemoryToAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyMemoryToAccelerationStructureKHR( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyMemoryToAccelerationStructureKHR( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WriteAccelerationStructuresPropertiesKHR( vk::Device device, uint32_t accelerationStructureCount, const vk::AccelerationStructureKHR* pAccelerationStructures, vk::QueryType queryType, size_t dataSize, void* pData, size_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.writeAccelerationStructuresPropertiesKHR( accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WriteAccelerationStructuresPropertiesKHR( device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceAddress> vkInterface::GetAccelerationStructureAddressKHR( vk::Device device, const vk::AccelerationStructureDeviceAddressInfoKHR* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getAccelerationStructureAddressKHR( pInfo );
//         return ResultValue<vk::Result, vk::DeviceAddress>( res );
// #else
//         return s_MockPtr->_GetAccelerationStructureAddressKHR( device, pInfo );
// #endif
//     }

//     void vkInterface::GetAccelerationStructureCompatibilityKHR( vk::Device device, const vk::AccelerationStructureVersionInfoKHR* pVersionInfo, vk::AccelerationStructureCompatibilityKHR* pCompatibility )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getAccelerationStructureCompatibilityKHR( pVersionInfo, pCompatibility );
// #else
//         s_MockPtr->_GetAccelerationStructureCompatibilityKHR( device, pVersionInfo, pCompatibility );
// #endif
//     }

//     void vkInterface::GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType, const vk::AccelerationStructureBuildGeometryInfoKHR* pBuildInfo, const uint32_t* pMaxPrimitiveCounts, vk::AccelerationStructureBuildSizesInfoKHR* pSizeInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getAccelerationStructureBuildSizesKHR( buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo );
// #else
//         s_MockPtr->_GetAccelerationStructureBuildSizesKHR( device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, vk::PipelineCache pipelineCache, uint32_t createInfoCount, const vk::RayTracingPipelineCreateInfoKHR* pCreateInfos, const vk::AllocationCallbacks* pAllocator,
//                                                                            vk::Pipeline* pPipelines )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRayTracingPipelinesKHR( deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateRayTracingPipelinesKHR( device, deferredOperation, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
// #endif
//     }


//     ResultValue<vk::Result, vk::Pipeline> vkInterface::CreateRayTracingPipelineKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, vk::PipelineCache pipelineCache, const vk::RayTracingPipelineCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRayTracingPipelineKHR( deferredOperation, pipelineCache, createInfo, allocator );
//         return ResultValue<vk::Result, vk::Pipeline>( res );
// #else
//         return s_MockPtr->_CreateRayTracingPipelineKHR( device, deferredOperation, pipelineCache, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize, pData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandlesKHR<uint8_t>( pipeline, firstGroup, groupCount, dataSize );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize );
// #endif
//     }

//     ResultValue<vk::Result, uint8_t> vkInterface::GetRayTracingShaderGroupHandleKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandleKHR<uint8_t>( pipeline, firstGroup, groupCount );
//         return ResultValue<vk::Result, uint8_t>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandleKHR( device, pipeline, firstGroup, groupCount );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingCaptureReplayShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize, pData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingCaptureReplayShaderGroupHandlesKHR<uint8_t>( pipeline, firstGroup, groupCount, dataSize );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize );
// #endif
//     }

//     ResultValue<vk::Result, uint8_t> vkInterface::GetRayTracingCaptureReplayShaderGroupHandleKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingCaptureReplayShaderGroupHandleKHR<uint8_t>( pipeline, firstGroup, groupCount );
//         return ResultValue<vk::Result, uint8_t>( res );
// #else
//         return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandleKHR( device, pipeline, firstGroup, groupCount );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceSize> vkInterface::GetRayTracingShaderGroupStackSizeKHR( vk::Device device, vk::Pipeline pipeline, uint32_t group, vk::ShaderGroupShaderKHR groupShader )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupStackSizeKHR( pipeline, group, groupShader );
//         return ResultValue<vk::Result, vk::DeviceSize>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupStackSizeKHR( device, pipeline, group, groupShader );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SamplerYcbcrConversion* pYcbcrConversion )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSamplerYcbcrConversionKHR( pCreateInfo, pAllocator, pYcbcrConversion );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateSamplerYcbcrConversionKHR( device, pCreateInfo, pAllocator, pYcbcrConversion );
// #endif
//     }

//     ResultValue<vk::Result, vk::SamplerYcbcrConversion> vkInterface::CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createSamplerYcbcrConversionKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SamplerYcbcrConversion>( res );
// #else
//         return s_MockPtr->_CreateSamplerYcbcrConversionKHR( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroySamplerYcbcrConversionKHR( ycbcrConversion, pAllocator );
// #else
//         s_MockPtr->_DestroySamplerYcbcrConversionKHR( device, ycbcrConversion, pAllocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindBufferMemory2KHR( vk::Device device, uint32_t bindInfoCount, const vk::BindBufferMemoryInfo* pBindInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindBufferMemory2KHR( bindInfoCount, pBindInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindBufferMemory2KHR( device, bindInfoCount, pBindInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindImageMemory2KHR( vk::Device device, uint32_t bindInfoCount, const vk::BindImageMemoryInfo* pBindInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindImageMemory2KHR( bindInfoCount, pBindInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindImageMemory2KHR( device, bindInfoCount, pBindInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image, vk::ImageDrmFormatModifierPropertiesEXT* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageDrmFormatModifierPropertiesEXT( image, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageDrmFormatModifierPropertiesEXT( device, image, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::ImageDrmFormatModifierPropertiesEXT> vkInterface::GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageDrmFormatModifierPropertiesEXT( image );
//         return ResultValue<vk::Result, vk::ImageDrmFormatModifierPropertiesEXT>( res );
// #else
//         return s_MockPtr->_GetImageDrmFormatModifierPropertiesEXT( device, image );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::ValidationCacheEXT* pValidationCache )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createValidationCacheEXT( pCreateInfo, pAllocator, pValidationCache );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateValidationCacheEXT( device, pCreateInfo, pAllocator, pValidationCache );
// #endif
//     }

//     ResultValue<vk::Result, vk::ValidationCacheEXT> vkInterface::CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createValidationCacheEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::ValidationCacheEXT>( res );
// #else
//         return s_MockPtr->_CreateValidationCacheEXT( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyValidationCacheEXT( validationCache, pAllocator );
// #else
//         s_MockPtr->_DestroyValidationCacheEXT( device, validationCache, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ValidationCacheEXT validationCache, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( validationCache, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, validationCache, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ValidationCacheEXT validationCache, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( validationCache, allocator );
// #else
//         s_MockPtr->_Destroy( device, validationCache, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::MergeValidationCachesEXT( vk::Device device, vk::ValidationCacheEXT dstCache, uint32_t srcCacheCount, const vk::ValidationCacheEXT* pSrcCaches )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.mergeValidationCachesEXT( dstCache, srcCacheCount, pSrcCaches );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_MergeValidationCachesEXT( device, dstCache, srcCacheCount, pSrcCaches );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache, size_t* pDataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getValidationCacheDataEXT( validationCache, pDataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetValidationCacheDataEXT( device, validationCache, pDataSize, pData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getValidationCacheDataEXT( validationCache );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetValidationCacheDataEXT( device, validationCache );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::AccelerationStructureNV* pAccelerationStructure )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createAccelerationStructureNV( pCreateInfo, pAllocator, pAccelerationStructure );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateAccelerationStructureNV( device, pCreateInfo, pAllocator, pAccelerationStructure );
// #endif
//     }

//     ResultValue<vk::Result, vk::AccelerationStructureNV> vkInterface::CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createAccelerationStructureNV( createInfo, allocator );
//         return ResultValue<vk::Result, vk::AccelerationStructureNV>( res );
// #else
//         return s_MockPtr->_CreateAccelerationStructureNV( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyAccelerationStructureNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyAccelerationStructureNV( accelerationStructure, pAllocator );
// #else
//         s_MockPtr->_DestroyAccelerationStructureNV( device, accelerationStructure, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( accelerationStructure, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, accelerationStructure, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( accelerationStructure, allocator );
// #else
//         s_MockPtr->_Destroy( device, accelerationStructure, allocator );
// #endif
//     }

//     void vkInterface::GetAccelerationStructureMemoryRequirementsNV( vk::Device device, const vk::AccelerationStructureMemoryRequirementsInfoNV* pInfo, vk::MemoryRequirements2KHR* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getAccelerationStructureMemoryRequirementsNV( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetAccelerationStructureMemoryRequirementsNV( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindAccelerationStructureMemoryNV( vk::Device device, uint32_t bindInfoCount, const vk::BindAccelerationStructureMemoryInfoNV* pBindInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindAccelerationStructureMemoryNV( bindInfoCount, pBindInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindAccelerationStructureMemoryNV( device, bindInfoCount, pBindInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount, const vk::RayTracingPipelineCreateInfoNV* pCreateInfos, const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRayTracingPipelinesNV( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateRayTracingPipelinesNV( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
// #endif
//     }

//     ResultValue<vk::Result, vk::Pipeline> vkInterface::CreateRayTracingPipelineNV( vk::Device device, vk::PipelineCache pipelineCache, const vk::RayTracingPipelineCreateInfoNV& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createRayTracingPipelineNV( pipelineCache, createInfo, allocator );
//         return ResultValue<vk::Result, vk::Pipeline>( res );
// #else
//         return s_MockPtr->_CreateRayTracingPipelineNV( device, pipelineCache, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandlesNV( pipeline, firstGroup, groupCount, dataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandlesNV( device, pipeline, firstGroup, groupCount, dataSize, pData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandlesNV<uint8_t>( pipeline, firstGroup, groupCount, dataSize );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandlesNV( device, pipeline, firstGroup, groupCount, dataSize );
// #endif
//     }

//     ResultValue<vk::Result, uint8_t> vkInterface::GetRayTracingShaderGroupHandleNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getRayTracingShaderGroupHandleNV<uint8_t>( pipeline, firstGroup, groupCount );
//         return ResultValue<vk::Result, uint8_t>( res );
// #else
//         return s_MockPtr->_GetRayTracingShaderGroupHandleNV( device, pipeline, firstGroup, groupCount );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure, size_t dataSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getAccelerationStructureHandleNV<uint8_t>( accelerationStructure, dataSize );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetAccelerationStructureHandleNV( device, accelerationStructure, dataSize );
// #endif
//     }

//     ResultValue<vk::Result, uint8_t> vkInterface::GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getAccelerationStructureHandleNV<uint8_t>( accelerationStructure );
//         return ResultValue<vk::Result, uint8_t>( res );
// #else
//         return s_MockPtr->_GetAccelerationStructureHandleNV( device, accelerationStructure );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CompileDeferredNV( vk::Device device, vk::Pipeline pipeline, uint32_t shader )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.compileDeferredNV( pipeline, shader );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CompileDeferredNV( device, pipeline, shader );
// #endif
//     }

//     void vkInterface::GetDescriptorSetLayoutSupportKHR( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo, vk::DescriptorSetLayoutSupport* pSupport )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetLayoutSupportKHR( pCreateInfo, pSupport );
// #else
//         s_MockPtr->_GetDescriptorSetLayoutSupportKHR( device, pCreateInfo, pSupport );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryHostPointerPropertiesEXT( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer, vk::MemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryHostPointerPropertiesEXT( handleType, pHostPointer, pMemoryHostPointerProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryHostPointerPropertiesEXT( device, handleType, pHostPointer, pMemoryHostPointerProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetCalibratedTimestampsEXT( vk::Device device, uint32_t timestampCount, const vk::CalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps, uint64_t* pMaxDeviation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getCalibratedTimestampsEXT( timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetCalibratedTimestampsEXT( device, timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation );
// #endif
//     }

//     ResultValue<vk::Result, std::pair<uint64_t, uint64_t>> vkInterface::GetCalibratedTimestampEXT( vk::Device device, const vk::CalibratedTimestampInfoEXT& timestampInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getCalibratedTimestampEXT( timestampInfo );
//         return ResultValue<vk::Result, std::pair<uint64_t, uint64_t>>( res );
// #else
//         return s_MockPtr->_GetCalibratedTimestampEXT( device, timestampInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore, uint64_t* pValue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreCounterValueKHR( semaphore, pValue );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSemaphoreCounterValueKHR( device, semaphore, pValue );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSemaphoreCounterValueKHR( semaphore );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetSemaphoreCounterValueKHR( device, semaphore );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitSemaphoresKHR( pWaitInfo, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitSemaphoresKHR( device, pWaitInfo, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitSemaphoresKHR( waitInfo, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitSemaphoresKHR( device, waitInfo, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SignalSemaphoreKHR( vk::Device device, const vk::SemaphoreSignalInfo* pSignalInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.signalSemaphoreKHR( pSignalInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SignalSemaphoreKHR( device, pSignalInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::InitializePerformanceApiINTEL( vk::Device device, const vk::InitializePerformanceApiInfoINTEL* pInitializeInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.initializePerformanceApiINTEL( pInitializeInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_InitializePerformanceApiINTEL( device, pInitializeInfo );
// #endif
//     }

//     void vkInterface::UninitializePerformanceApiINTEL( vk::Device device )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.uninitializePerformanceApiINTEL();
// #else
//         s_MockPtr->_UninitializePerformanceApiINTEL( device );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquirePerformanceConfigurationINTEL( vk::Device device, const vk::PerformanceConfigurationAcquireInfoINTEL* pAcquireInfo, vk::PerformanceConfigurationINTEL* pConfiguration )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.acquirePerformanceConfigurationINTEL( pAcquireInfo, pConfiguration );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquirePerformanceConfigurationINTEL( device, pAcquireInfo, pConfiguration );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ReleasePerformanceConfigurationINTEL( vk::Device device, vk::PerformanceConfigurationINTEL configuration )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.releasePerformanceConfigurationINTEL( configuration );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ReleasePerformanceConfigurationINTEL( device, configuration );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::Release( vk::Device device, vk::PerformanceConfigurationINTEL configuration )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.release( configuration );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_Release( device, configuration );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter, vk::PerformanceValueINTEL* pValue )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPerformanceParameterINTEL( parameter, pValue );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPerformanceParameterINTEL( device, parameter, pValue );
// #endif
//     }

//     ResultValue<vk::Result, vk::PerformanceValueINTEL> vkInterface::GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPerformanceParameterINTEL( parameter );
//         return ResultValue<vk::Result, vk::PerformanceValueINTEL>( res );
// #else
//         return s_MockPtr->_GetPerformanceParameterINTEL( device, parameter );
// #endif
//     }

//     void vkInterface::SetLocalDimmingAMD( vk::Device device, vk::SwapchainKHR swapChain, vk::Bool32 localDimmingEnable )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.setLocalDimmingAMD( swapChain, localDimmingEnable );
// #else
//         s_MockPtr->_SetLocalDimmingAMD( device, swapChain, localDimmingEnable );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceAddress> vkInterface::GetBufferAddressEXT( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferAddressEXT( pInfo );
//         return ResultValue<vk::Result, vk::DeviceAddress>( res );
// #else
//         return s_MockPtr->_GetBufferAddressEXT( device, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain, uint64_t presentId, uint64_t timeout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.waitForPresentKHR( swapchain, presentId, timeout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WaitForPresentKHR( device, swapchain, presentId, timeout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.acquireFullScreenExclusiveModeEXT( swapchain );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireFullScreenExclusiveModeEXT( device, swapchain );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ReleaseFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.releaseFullScreenExclusiveModeEXT( swapchain );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ReleaseFullScreenExclusiveModeEXT( device, swapchain );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetGroupSurfacePresentModes2EXT( vk::Device device, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, vk::DeviceGroupPresentModeFlagsKHR* pModes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getGroupSurfacePresentModes2EXT( pSurfaceInfo, pModes );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetGroupSurfacePresentModes2EXT( device, pSurfaceInfo, pModes );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceAddress> vkInterface::GetBufferAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferAddressKHR( pInfo );
//         return ResultValue<vk::Result, vk::DeviceAddress>( res );
// #else
//         return s_MockPtr->_GetBufferAddressKHR( device, pInfo );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetBufferOpaqueCaptureAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferOpaqueCaptureAddressKHR( pInfo );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetBufferOpaqueCaptureAddressKHR( device, pInfo );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetMemoryOpaqueCaptureAddressKHR( vk::Device device, const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryOpaqueCaptureAddressKHR( pInfo );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetMemoryOpaqueCaptureAddressKHR( device, pInfo );
// #endif
//     }

//     void vkInterface::ResetQueryPoolEXT( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.resetQueryPoolEXT( queryPool, firstQuery, queryCount );
// #else
//         s_MockPtr->_ResetQueryPoolEXT( device, queryPool, firstQuery, queryCount );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDeferredOperationKHR( vk::Device device, const vk::AllocationCallbacks* pAllocator, vk::DeferredOperationKHR* pDeferredOperation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDeferredOperationKHR( pAllocator, pDeferredOperation );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDeferredOperationKHR( device, pAllocator, pDeferredOperation );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeferredOperationKHR> vkInterface::CreateDeferredOperationKHR( vk::Device device, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createDeferredOperationKHR( allocator );
//         return ResultValue<vk::Result, vk::DeferredOperationKHR>( res );
// #else
//         return s_MockPtr->_CreateDeferredOperationKHR( device, allocator );
// #endif
//     }

//     void vkInterface::DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyDeferredOperationKHR( operation, pAllocator );
// #else
//         s_MockPtr->_DestroyDeferredOperationKHR( device, operation, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DeferredOperationKHR operation, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( operation, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, operation, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::DeferredOperationKHR operation, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( operation, allocator );
// #else
//         s_MockPtr->_Destroy( device, operation, allocator );
// #endif
//     }

//     ResultValue<vk::Result, uint32_t> vkInterface::GetDeferredOperationMaxConcurrencyKHR( vk::Device device, vk::DeferredOperationKHR operation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDeferredOperationMaxConcurrencyKHR( operation );
//         return ResultValue<vk::Result, uint32_t>( res );
// #else
//         return s_MockPtr->_GetDeferredOperationMaxConcurrencyKHR( device, operation );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDeferredOperationResultKHR( vk::Device device, vk::DeferredOperationKHR operation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDeferredOperationResultKHR( operation );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDeferredOperationResultKHR( device, operation );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::DeferredOperationJoinKHR( vk::Device device, vk::DeferredOperationKHR operation )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.deferredOperationJoinKHR( operation );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_DeferredOperationJoinKHR( device, operation );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPipelineExecutablePropertiesKHR( vk::Device device, const vk::PipelineInfoKHR* pPipelineInfo, uint32_t* pExecutableCount, vk::PipelineExecutablePropertiesKHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelineExecutablePropertiesKHR( pPipelineInfo, pExecutableCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPipelineExecutablePropertiesKHR( device, pPipelineInfo, pExecutableCount, pProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPipelineExecutableStatisticsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pStatisticCount, vk::PipelineExecutableStatisticKHR* pStatistics )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelineExecutableStatisticsKHR( pExecutableInfo, pStatisticCount, pStatistics );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPipelineExecutableStatisticsKHR( device, pExecutableInfo, pStatisticCount, pStatistics );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPipelineExecutableInternalRepresentationsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount, vk::PipelineExecutableInternalRepresentationKHR* pInternalRepresentations )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelineExecutableInternalRepresentationsKHR( pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPipelineExecutableInternalRepresentationsKHR( device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyMemoryToImageEXT( vk::Device device, const vk::CopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyMemoryToImageEXT( pCopyMemoryToImageInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyMemoryToImageEXT( device, pCopyMemoryToImageInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyImageToMemoryEXT( vk::Device device, const vk::CopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyImageToMemoryEXT( pCopyImageToMemoryInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyImageToMemoryEXT( device, pCopyImageToMemoryInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyImageToImageEXT( vk::Device device, const vk::CopyImageToImageInfoEXT* pCopyImageToImageInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyImageToImageEXT( pCopyImageToImageInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyImageToImageEXT( device, pCopyImageToImageInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::TransitionImageLayoutEXT( vk::Device device, uint32_t transitionCount, const vk::HostImageLayoutTransitionInfoEXT* pTransitions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.transitionImageLayoutEXT( transitionCount, pTransitions );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_TransitionImageLayoutEXT( device, transitionCount, pTransitions );
// #endif
//     }

//     void vkInterface::GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image, const vk::ImageSubresource2KHR* pSubresource, vk::SubresourceLayout2KHR* pLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSubresourceLayout2EXT( image, pSubresource, pLayout );
// #else
//         s_MockPtr->_GetImageSubresourceLayout2EXT( device, image, pSubresource, pLayout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::MapMemory2KHR( vk::Device device, const vk::MemoryMapInfoKHR* pMemoryMapInfo, void** ppData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.mapMemory2KHR( pMemoryMapInfo, ppData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_MapMemory2KHR( device, pMemoryMapInfo, ppData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::UnmapMemory2KHR( vk::Device device, const vk::MemoryUnmapInfoKHR* pMemoryUnmapInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.unmapMemory2KHR( pMemoryUnmapInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_UnmapMemory2KHR( device, pMemoryUnmapInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::ReleaseSwapchainImagesEXT( vk::Device device, const vk::ReleaseSwapchainImagesInfoEXT* pReleaseInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.releaseSwapchainImagesEXT( pReleaseInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_ReleaseSwapchainImagesEXT( device, pReleaseInfo );
// #endif
//     }

//     void vkInterface::GetGeneratedCommandsMemoryRequirementsNV( vk::Device device, const vk::GeneratedCommandsMemoryRequirementsInfoNV* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getGeneratedCommandsMemoryRequirementsNV( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetGeneratedCommandsMemoryRequirementsNV( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::IndirectCommandsLayoutNV* pIndirectCommandsLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createIndirectCommandsLayoutNV( pCreateInfo, pAllocator, pIndirectCommandsLayout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateIndirectCommandsLayoutNV( device, pCreateInfo, pAllocator, pIndirectCommandsLayout );
// #endif
//     }

//     ResultValue<vk::Result, vk::IndirectCommandsLayoutNV> vkInterface::CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createIndirectCommandsLayoutNV( createInfo, allocator );
//         return ResultValue<vk::Result, vk::IndirectCommandsLayoutNV>( res );
// #else
//         return s_MockPtr->_CreateIndirectCommandsLayoutNV( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyIndirectCommandsLayoutNV( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyIndirectCommandsLayoutNV( indirectCommandsLayout, pAllocator );
// #else
//         s_MockPtr->_DestroyIndirectCommandsLayoutNV( device, indirectCommandsLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( indirectCommandsLayout, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, indirectCommandsLayout, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( indirectCommandsLayout, allocator );
// #else
//         s_MockPtr->_Destroy( device, indirectCommandsLayout, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::PrivateDataSlot* pPrivateDataSlot )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPrivateDataSlotEXT( pCreateInfo, pAllocator, pPrivateDataSlot );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreatePrivateDataSlotEXT( device, pCreateInfo, pAllocator, pPrivateDataSlot );
// #endif
//     }

//     ResultValue<vk::Result, vk::PrivateDataSlot> vkInterface::CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createPrivateDataSlotEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::PrivateDataSlot>( res );
// #else
//         return s_MockPtr->_CreatePrivateDataSlotEXT( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyPrivateDataSlotEXT( privateDataSlot, pAllocator );
// #else
//         s_MockPtr->_DestroyPrivateDataSlotEXT( device, privateDataSlot, pAllocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot, uint64_t data )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.setPrivateDataEXT( objectType_, objectHandle, privateDataSlot, data );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_SetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot, data );
// #endif
//     }

//     void vkInterface::GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot, uint64_t* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getPrivateDataEXT( objectType_, objectHandle, privateDataSlot, pData );
// #else
//         s_MockPtr->_GetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot, pData );
// #endif
//     }

//     ResultValue<vk::Result, uint64_t> vkInterface::GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPrivateDataEXT( objectType_, objectHandle, privateDataSlot );
//         return ResultValue<vk::Result, uint64_t>( res );
// #else
//         return s_MockPtr->_GetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot );
// #endif
//     }

//     void vkInterface::GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout, vk::DeviceSize* pLayoutSizeInBytes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetLayoutSizeEXT( layout, pLayoutSizeInBytes );
// #else
//         s_MockPtr->_GetDescriptorSetLayoutSizeEXT( device, layout, pLayoutSizeInBytes );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceSize> vkInterface::GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDescriptorSetLayoutSizeEXT( layout );
//         return ResultValue<vk::Result, vk::DeviceSize>( res );
// #else
//         return s_MockPtr->_GetDescriptorSetLayoutSizeEXT( device, layout );
// #endif
//     }

//     void vkInterface::GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout, uint32_t binding, vk::DeviceSize* pOffset )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetLayoutBindingOffsetEXT( layout, binding, pOffset );
// #else
//         s_MockPtr->_GetDescriptorSetLayoutBindingOffsetEXT( device, layout, binding, pOffset );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceSize> vkInterface::GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout, uint32_t binding )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDescriptorSetLayoutBindingOffsetEXT( layout, binding );
//         return ResultValue<vk::Result, vk::DeviceSize>( res );
// #else
//         return s_MockPtr->_GetDescriptorSetLayoutBindingOffsetEXT( device, layout, binding );
// #endif
//     }

//     void vkInterface::GetDescriptorEXT( vk::Device device, const vk::DescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize, void* pDescriptor )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorEXT( pDescriptorInfo, dataSize, pDescriptor );
// #else
//         s_MockPtr->_GetDescriptorEXT( device, pDescriptorInfo, dataSize, pDescriptor );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetBufferOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::BufferCaptureDescriptorDataInfoEXT* pInfo, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getBufferOpaqueCaptureDescriptorDataEXT( pInfo, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetBufferOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetImageOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::ImageCaptureDescriptorDataInfoEXT* pInfo, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getImageOpaqueCaptureDescriptorDataEXT( pInfo, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSamplerOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::SamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSamplerOpaqueCaptureDescriptorDataEXT( pInfo, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSamplerOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetAccelerationStructureOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::AccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getAccelerationStructureOpaqueCaptureDescriptorDataEXT( pInfo, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetFaultInfoEXT( vk::Device device, vk::DeviceFaultCountsEXT* pFaultCounts, vk::DeviceFaultInfoEXT* pFaultInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getFaultInfoEXT( pFaultCounts, pFaultInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetFaultInfoEXT( device, pFaultCounts, pFaultInfo );
// #endif
//     }

//     ResultValue<vk::Result, std::pair<vk::DeviceFaultCountsEXT, vk::DeviceFaultInfoEXT>> vkInterface::GetFaultInfoEXT( vk::Device device )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getFaultInfoEXT();
//         return ResultValue<vk::Result, std::pair<vk::DeviceFaultCountsEXT, vk::DeviceFaultInfoEXT>>( res );
// #else
//         return s_MockPtr->_GetFaultInfoEXT( device );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass, vk::Extent2D* pMaxWorkgroupSize )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSubpassShadingMaxWorkgroupSizeHUAWEI( renderpass, pMaxWorkgroupSize );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSubpassShadingMaxWorkgroupSizeHUAWEI( device, renderpass, pMaxWorkgroupSize );
// #endif
//     }

//     ResultValue<vk::Result, vk::Extent2D> vkInterface::GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getSubpassShadingMaxWorkgroupSizeHUAWEI( renderpass );
//         return ResultValue<vk::Result, vk::Extent2D>( res );
// #else
//         return s_MockPtr->_GetSubpassShadingMaxWorkgroupSizeHUAWEI( device, renderpass );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetMemoryRemoteAddressNV( vk::Device device, const vk::MemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo, vk::RemoteAddressNV* pAddress )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getMemoryRemoteAddressNV( pMemoryGetRemoteAddressInfo, pAddress );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetMemoryRemoteAddressNV( device, pMemoryGetRemoteAddressInfo, pAddress );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPipelinePropertiesEXT( vk::Device device, const vk::PipelineInfoEXT* pPipelineInfo, vk::BaseOutStructure* pPipelineProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelinePropertiesEXT( pPipelineInfo, pPipelineProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPipelinePropertiesEXT( device, pPipelineInfo, pPipelineProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::MicromapEXT* pMicromap )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createMicromapEXT( pCreateInfo, pAllocator, pMicromap );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateMicromapEXT( device, pCreateInfo, pAllocator, pMicromap );
// #endif
//     }

//     ResultValue<vk::Result, vk::MicromapEXT> vkInterface::CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createMicromapEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::MicromapEXT>( res );
// #else
//         return s_MockPtr->_CreateMicromapEXT( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyMicromapEXT( micromap, pAllocator );
// #else
//         s_MockPtr->_DestroyMicromapEXT( device, micromap, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::MicromapEXT micromap, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( micromap, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, micromap, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::MicromapEXT micromap, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( micromap, allocator );
// #else
//         s_MockPtr->_Destroy( device, micromap, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BuildMicromapsEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation, uint32_t infoCount, const vk::MicromapBuildInfoEXT* pInfos )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.buildMicromapsEXT( deferredOperation, infoCount, pInfos );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BuildMicromapsEXT( device, deferredOperation, infoCount, pInfos );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyMicromapInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyMicromapEXT( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyMicromapEXT( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyMicromapToMemoryEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyMicromapToMemoryInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyMicromapToMemoryEXT( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyMicromapToMemoryEXT( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CopyMemoryToMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation, const vk::CopyMemoryToMicromapInfoEXT* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.copyMemoryToMicromapEXT( deferredOperation, pInfo );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CopyMemoryToMicromapEXT( device, deferredOperation, pInfo );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::WriteMicromapsPropertiesEXT( vk::Device device, uint32_t micromapCount, const vk::MicromapEXT* pMicromaps, vk::QueryType queryType, size_t dataSize, void* pData, size_t stride )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.writeMicromapsPropertiesEXT( micromapCount, pMicromaps, queryType, dataSize, pData, stride );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_WriteMicromapsPropertiesEXT( device, micromapCount, pMicromaps, queryType, dataSize, pData, stride );
// #endif
//     }

//     void vkInterface::GetMicromapCompatibilityEXT( vk::Device device, const vk::MicromapVersionInfoEXT* pVersionInfo, vk::AccelerationStructureCompatibilityKHR* pCompatibility )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getMicromapCompatibilityEXT( pVersionInfo, pCompatibility );
// #else
//         s_MockPtr->_GetMicromapCompatibilityEXT( device, pVersionInfo, pCompatibility );
// #endif
//     }

//     void vkInterface::GetMicromapBuildSizesEXT( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType, const vk::MicromapBuildInfoEXT* pBuildInfo, vk::MicromapBuildSizesInfoEXT* pSizeInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getMicromapBuildSizesEXT( buildType, pBuildInfo, pSizeInfo );
// #else
//         s_MockPtr->_GetMicromapBuildSizesEXT( device, buildType, pBuildInfo, pSizeInfo );
// #endif
//     }

//     void vkInterface::SetMemoryPriorityEXT( vk::Device device, vk::DeviceMemory memory, float priority )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.setMemoryPriorityEXT( memory, priority );
// #else
//         s_MockPtr->_SetMemoryPriorityEXT( device, memory, priority );
// #endif
//     }

//     void vkInterface::GetBufferMemoryRequirementsKHR( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getBufferMemoryRequirementsKHR( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetBufferMemoryRequirementsKHR( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetImageMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageMemoryRequirementsKHR( pInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetImageMemoryRequirementsKHR( device, pInfo, pMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetImageSparseMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo, uint32_t* pSparseMemoryRequirementCount, vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSparseMemoryRequirementsKHR( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #else
//         s_MockPtr->_GetImageSparseMemoryRequirementsKHR( device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
// #endif
//     }

//     void vkInterface::GetDescriptorSetLayoutHostMappingInfoVALVE( vk::Device device, const vk::DescriptorSetBindingReferenceVALVE* pBindingReference, vk::DescriptorSetLayoutHostMappingInfoVALVE* pHostMapping )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetLayoutHostMappingInfoVALVE( pBindingReference, pHostMapping );
// #else
//         s_MockPtr->_GetDescriptorSetLayoutHostMappingInfoVALVE( device, pBindingReference, pHostMapping );
// #endif
//     }

//     void vkInterface::GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet, void** ppData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getDescriptorSetHostMappingVALVE( descriptorSet, ppData );
// #else
//         s_MockPtr->_GetDescriptorSetHostMappingVALVE( device, descriptorSet, ppData );
// #endif
//     }

//     ResultValue<vk::Result, void*> vkInterface::GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDescriptorSetHostMappingVALVE( descriptorSet );
//         return ResultValue<vk::Result, void*>( res );
// #else
//         return s_MockPtr->_GetDescriptorSetHostMappingVALVE( device, descriptorSet );
// #endif
//     }

//     void vkInterface::GetPipelineIndirectMemoryRequirementsNV( vk::Device device, const vk::ComputePipelineCreateInfo* pCreateInfo, vk::MemoryRequirements2* pMemoryRequirements )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getPipelineIndirectMemoryRequirementsNV( pCreateInfo, pMemoryRequirements );
// #else
//         s_MockPtr->_GetPipelineIndirectMemoryRequirementsNV( device, pCreateInfo, pMemoryRequirements );
// #endif
//     }

//     ResultValue<vk::Result, vk::DeviceAddress> vkInterface::GetPipelineIndirectAddressNV( vk::Device device, const vk::PipelineIndirectDeviceAddressInfoNV* pInfo )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getPipelineIndirectAddressNV( pInfo );
//         return ResultValue<vk::Result, vk::DeviceAddress>( res );
// #else
//         return s_MockPtr->_GetPipelineIndirectAddressNV( device, pInfo );
// #endif
//     }

//     void vkInterface::GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule, vk::ShaderModuleIdentifierEXT* pIdentifier )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getShaderModuleIdentifierEXT( shaderModule, pIdentifier );
// #else
//         s_MockPtr->_GetShaderModuleIdentifierEXT( device, shaderModule, pIdentifier );
// #endif
//     }

//     ResultValue<vk::Result, vk::ShaderModuleIdentifierEXT> vkInterface::GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getShaderModuleIdentifierEXT( shaderModule );
//         return ResultValue<vk::Result, vk::ShaderModuleIdentifierEXT>( res );
// #else
//         return s_MockPtr->_GetShaderModuleIdentifierEXT( device, shaderModule );
// #endif
//     }

//     void vkInterface::GetShaderModuleCreateInfoIdentifierEXT( vk::Device device, const vk::ShaderModuleCreateInfo* pCreateInfo, vk::ShaderModuleIdentifierEXT* pIdentifier )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getShaderModuleCreateInfoIdentifierEXT( pCreateInfo, pIdentifier );
// #else
//         s_MockPtr->_GetShaderModuleCreateInfoIdentifierEXT( device, pCreateInfo, pIdentifier );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::OpticalFlowSessionNV* pSession )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createOpticalFlowSessionNV( pCreateInfo, pAllocator, pSession );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateOpticalFlowSessionNV( device, pCreateInfo, pAllocator, pSession );
// #endif
//     }

//     ResultValue<vk::Result, vk::OpticalFlowSessionNV> vkInterface::CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createOpticalFlowSessionNV( createInfo, allocator );
//         return ResultValue<vk::Result, vk::OpticalFlowSessionNV>( res );
// #else
//         return s_MockPtr->_CreateOpticalFlowSessionNV( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyOpticalFlowSessionNV( session, pAllocator );
// #else
//         s_MockPtr->_DestroyOpticalFlowSessionNV( device, session, pAllocator );
// #endif
//     }

//     void vkInterface::DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyOpticalFlowSessionNV( session, allocator );
// #else
//         s_MockPtr->_DestroyOpticalFlowSessionNV( device, session, allocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::OpticalFlowSessionNV session, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( session, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, session, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::OpticalFlowSessionNV session, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( session, allocator );
// #else
//         s_MockPtr->_Destroy( device, session, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session, vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view, vk::ImageLayout layout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.bindOpticalFlowSessionImageNV( session, bindingPoint, view, layout );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_BindOpticalFlowSessionImageNV( device, session, bindingPoint, view, layout );
// #endif
//     }

//     void vkInterface::GetRenderingAreaGranularityKHR( vk::Device device, const vk::RenderingAreaInfoKHR* pRenderingAreaInfo, vk::Extent2D* pGranularity )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getRenderingAreaGranularityKHR( pRenderingAreaInfo, pGranularity );
// #else
//         s_MockPtr->_GetRenderingAreaGranularityKHR( device, pRenderingAreaInfo, pGranularity );
// #endif
//     }

//     void vkInterface::GetImageSubresourceLayoutKHR( vk::Device device, const vk::DeviceImageSubresourceInfoKHR* pInfo, vk::SubresourceLayout2KHR* pLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSubresourceLayoutKHR( pInfo, pLayout );
// #else
//         s_MockPtr->_GetImageSubresourceLayoutKHR( device, pInfo, pLayout );
// #endif
//     }

//     void vkInterface::GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image, const vk::ImageSubresource2KHR* pSubresource, vk::SubresourceLayout2KHR* pLayout )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.getImageSubresourceLayout2KHR( image, pSubresource, pLayout );
// #else
//         s_MockPtr->_GetImageSubresourceLayout2KHR( device, image, pSubresource, pLayout );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateShadersEXT( vk::Device device, uint32_t createInfoCount, const vk::ShaderCreateInfoEXT* pCreateInfos, const vk::AllocationCallbacks* pAllocator, vk::ShaderEXT* pShaders )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createShadersEXT( createInfoCount, pCreateInfos, pAllocator, pShaders );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateShadersEXT( device, createInfoCount, pCreateInfos, pAllocator, pShaders );
// #endif
//     }

//     ResultValue<vk::Result, vk::ShaderEXT> vkInterface::CreateShaderEXT( vk::Device device, const vk::ShaderCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.createShaderEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::ShaderEXT>( res );
// #else
//         return s_MockPtr->_CreateShaderEXT( device, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyShaderEXT( shader, pAllocator );
// #else
//         s_MockPtr->_DestroyShaderEXT( device, shader, pAllocator );
// #endif
//     }

//     void vkInterface::DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroyShaderEXT( shader, allocator );
// #else
//         s_MockPtr->_DestroyShaderEXT( device, shader, allocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ShaderEXT shader, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( shader, pAllocator );
// #else
//         s_MockPtr->_Destroy( device, shader, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Device device, vk::ShaderEXT shader, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         device.destroy( shader, allocator );
// #else
//         s_MockPtr->_Destroy( device, shader, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader, size_t* pDataSize, void* pData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getShaderBinaryDataEXT( shader, pDataSize, pData );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetShaderBinaryDataEXT( device, shader, pDataSize, pData );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>> vkInterface::GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getShaderBinaryDataEXT( shader );
//         return ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>( res );
// #else
//         return s_MockPtr->_GetShaderBinaryDataEXT( device, shader );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDynamicRenderingTilePropertiesQCOM( vk::Device device, const vk::RenderingInfo* pRenderingInfo, vk::TilePropertiesQCOM* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = device.getDynamicRenderingTilePropertiesQCOM( pRenderingInfo, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDynamicRenderingTilePropertiesQCOM( device, pRenderingInfo, pProperties );
// #endif
//     }

//     void vkInterface::GetFeatures( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures* pFeatures )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getFeatures( pFeatures );
// #else
//         s_MockPtr->_GetFeatures( physicalDevice, pFeatures );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceFeatures> vkInterface::GetFeatures( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFeatures();
//         return ResultValue<vk::Result, vk::PhysicalDeviceFeatures>( res );
// #else
//         return s_MockPtr->_GetFeatures( physicalDevice );
// #endif
//     }

    void vkInterface::GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::FormatProperties* pFormatProperties )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        physicalDevice.getFormatProperties( format, pFormatProperties );
#else
        s_MockPtr->_GetFormatProperties( physicalDevice, format, pFormatProperties );
#endif
    }

    ResultValue<vk::Result, vk::FormatProperties> vkInterface::GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = physicalDevice.getFormatProperties( format );
        return ResultValue<vk::Result, vk::FormatProperties>( res );
#else
        return s_MockPtr->_GetFormatProperties( physicalDevice, format );
#endif
    }

//     ResultValueType<vk::Result> vkInterface::GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type, vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags, vk::ImageFormatProperties* pImageFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getImageFormatProperties( format, type, tiling, usage, flags, pImageFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageFormatProperties( physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties );
// #endif
//     }

//     void vkInterface::GetProperties( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getProperties( pProperties );
// #else
//         s_MockPtr->_GetProperties( physicalDevice, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceProperties> vkInterface::GetProperties( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getProperties();
//         return ResultValue<vk::Result, vk::PhysicalDeviceProperties>( res );
// #else
//         return s_MockPtr->_GetProperties( physicalDevice );
// #endif
//     }

//     void vkInterface::GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, vk::QueueFamilyProperties* pQueueFamilyProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getQueueFamilyProperties( pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #else
//         s_MockPtr->_GetQueueFamilyProperties( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties, std::allocator<vk::QueueFamilyProperties>>> vkInterface::GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getQueueFamilyProperties();
//         return ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties, std::allocator<vk::QueueFamilyProperties>>>( res );
// #else
//         return s_MockPtr->_GetQueueFamilyProperties( physicalDevice );
// #endif
//     }

    void vkInterface::GetMemoryProperties( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceMemoryProperties* pMemoryProperties )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        physicalDevice.getMemoryProperties( pMemoryProperties );
#else
        s_MockPtr->_GetMemoryProperties( physicalDevice, pMemoryProperties );
#endif
    }

    ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> vkInterface::GetMemoryProperties( vk::PhysicalDevice physicalDevice )
    {
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
        auto res = physicalDevice.getMemoryProperties();
        return ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>( res );
#else
        return s_MockPtr->_GetMemoryProperties( physicalDevice );
#endif
    }

//     ResultValueType<vk::Result> vkInterface::CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Device* pDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.createDevice( pCreateInfo, pAllocator, pDevice );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDevice( physicalDevice, pCreateInfo, pAllocator, pDevice );
// #endif
//     }

//     ResultValue<vk::Result, vk::Device> vkInterface::CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.createDevice( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Device>( res );
// #else
//         return s_MockPtr->_CreateDevice( physicalDevice, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice, const char* pLayerName, uint32_t* pPropertyCount, vk::ExtensionProperties* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.enumerateDeviceExtensionProperties( pLayerName, pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumerateDeviceExtensionProperties( physicalDevice, pLayerName, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>> vkInterface::EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice, vk::Optional<const std::string> layerName )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.enumerateDeviceExtensionProperties( layerName );
//         return ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>>( res );
// #else
//         return s_MockPtr->_EnumerateDeviceExtensionProperties( physicalDevice, layerName );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::LayerProperties* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.enumerateDeviceLayerProperties( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumerateDeviceLayerProperties( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>> vkInterface::EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.enumerateDeviceLayerProperties();
//         return ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>>( res );
// #else
//         return s_MockPtr->_EnumerateDeviceLayerProperties( physicalDevice );
// #endif
//     }

//     void vkInterface::GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type, vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage, vk::ImageTiling tiling, uint32_t* pPropertyCount, vk::SparseImageFormatProperties* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getSparseImageFormatProperties( format, type, samples, usage, tiling, pPropertyCount, pProperties );
// #else
//         s_MockPtr->_GetSparseImageFormatProperties( physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::SparseImageFormatProperties, std::allocator<vk::SparseImageFormatProperties>>> vkInterface::GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type, vk::SampleCountFlagBits samples,
//                                                                                                                                                                         vk::ImageUsageFlags usage, vk::ImageTiling tiling )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSparseImageFormatProperties( format, type, samples, usage, tiling );
//         return ResultValue<vk::Result, std::vector<vk::SparseImageFormatProperties, std::allocator<vk::SparseImageFormatProperties>>>( res );
// #else
//         return s_MockPtr->_GetSparseImageFormatProperties( physicalDevice, format, type, samples, usage, tiling );
// #endif
//     }

//     void vkInterface::GetFeatures2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getFeatures2( pFeatures );
// #else
//         s_MockPtr->_GetFeatures2( physicalDevice, pFeatures );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceFeatures2> vkInterface::GetFeatures2( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFeatures2();
//         return ResultValue<vk::Result, vk::PhysicalDeviceFeatures2>( res );
// #else
//         return s_MockPtr->_GetFeatures2( physicalDevice );
// #endif
//     }

//     void vkInterface::GetProperties2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getProperties2( pProperties );
// #else
//         s_MockPtr->_GetProperties2( physicalDevice, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceProperties2> vkInterface::GetProperties2( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getProperties2();
//         return ResultValue<vk::Result, vk::PhysicalDeviceProperties2>( res );
// #else
//         return s_MockPtr->_GetProperties2( physicalDevice );
// #endif
//     }

//     void vkInterface::GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format, vk::FormatProperties2* pFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getFormatProperties2( format, pFormatProperties );
// #else
//         s_MockPtr->_GetFormatProperties2( physicalDevice, format, pFormatProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::FormatProperties2> vkInterface::GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFormatProperties2( format );
//         return ResultValue<vk::Result, vk::FormatProperties2>( res );
// #else
//         return s_MockPtr->_GetFormatProperties2( physicalDevice, format );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetImageFormatProperties2( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo, vk::ImageFormatProperties2* pImageFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getImageFormatProperties2( pImageFormatInfo, pImageFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageFormatProperties2( physicalDevice, pImageFormatInfo, pImageFormatProperties );
// #endif
//     }

//     void vkInterface::GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, vk::QueueFamilyProperties2* pQueueFamilyProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getQueueFamilyProperties2( pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #else
//         s_MockPtr->_GetQueueFamilyProperties2( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>> vkInterface::GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getQueueFamilyProperties2();
//         return ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>( res );
// #else
//         return s_MockPtr->_GetQueueFamilyProperties2( physicalDevice );
// #endif
//     }

//     void vkInterface::GetMemoryProperties2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceMemoryProperties2* pMemoryProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getMemoryProperties2( pMemoryProperties );
// #else
//         s_MockPtr->_GetMemoryProperties2( physicalDevice, pMemoryProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2> vkInterface::GetMemoryProperties2( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getMemoryProperties2();
//         return ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>( res );
// #else
//         return s_MockPtr->_GetMemoryProperties2( physicalDevice );
// #endif
//     }

//     void vkInterface::GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, vk::SparseImageFormatProperties2* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getSparseImageFormatProperties2( pFormatInfo, pPropertyCount, pProperties );
// #else
//         s_MockPtr->_GetSparseImageFormatProperties2( physicalDevice, pFormatInfo, pPropertyCount, pProperties );
// #endif
//     }

//     void vkInterface::GetExternalBufferProperties( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo, vk::ExternalBufferProperties* pExternalBufferProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalBufferProperties( pExternalBufferInfo, pExternalBufferProperties );
// #else
//         s_MockPtr->_GetExternalBufferProperties( physicalDevice, pExternalBufferInfo, pExternalBufferProperties );
// #endif
//     }

//     void vkInterface::GetExternalFenceProperties( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo, vk::ExternalFenceProperties* pExternalFenceProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalFenceProperties( pExternalFenceInfo, pExternalFenceProperties );
// #else
//         s_MockPtr->_GetExternalFenceProperties( physicalDevice, pExternalFenceInfo, pExternalFenceProperties );
// #endif
//     }

//     void vkInterface::GetExternalSemaphoreProperties( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalSemaphoreProperties( pExternalSemaphoreInfo, pExternalSemaphoreProperties );
// #else
//         s_MockPtr->_GetExternalSemaphoreProperties( physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetToolProperties( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount, vk::PhysicalDeviceToolProperties* pToolProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getToolProperties( pToolCount, pToolProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetToolProperties( physicalDevice, pToolCount, pToolProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, std::allocator<vk::PhysicalDeviceToolProperties>>> vkInterface::GetToolProperties( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getToolProperties();
//         return ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, std::allocator<vk::PhysicalDeviceToolProperties>>>( res );
// #else
//         return s_MockPtr->_GetToolProperties( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, vk::SurfaceKHR surface, vk::Bool32* pSupported )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceSupportKHR( queueFamilyIndex, surface, pSupported );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceSupportKHR( physicalDevice, queueFamilyIndex, surface, pSupported );
// #endif
//     }

//     ResultValue<vk::Result, vk::Bool32> vkInterface::GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, vk::SurfaceKHR surface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceSupportKHR( queueFamilyIndex, surface );
//         return ResultValue<vk::Result, vk::Bool32>( res );
// #else
//         return s_MockPtr->_GetSurfaceSupportKHR( physicalDevice, queueFamilyIndex, surface );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface, vk::SurfaceCapabilitiesKHR* pSurfaceCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceCapabilitiesKHR( surface, pSurfaceCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceCapabilitiesKHR( physicalDevice, surface, pSurfaceCapabilities );
// #endif
//     }

//     ResultValue<vk::Result, vk::SurfaceCapabilitiesKHR> vkInterface::GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceCapabilitiesKHR( surface );
//         return ResultValue<vk::Result, vk::SurfaceCapabilitiesKHR>( res );
// #else
//         return s_MockPtr->_GetSurfaceCapabilitiesKHR( physicalDevice, surface );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface, uint32_t* pSurfaceFormatCount, vk::SurfaceFormatKHR* pSurfaceFormats )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceFormatsKHR( surface, pSurfaceFormatCount, pSurfaceFormats );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceFormatsKHR( physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface, uint32_t* pPresentModeCount, vk::PresentModeKHR* pPresentModes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfacePresentModesKHR( surface, pPresentModeCount, pPresentModes );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfacePresentModesKHR( physicalDevice, surface, pPresentModeCount, pPresentModes );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface, uint32_t* pRectCount, vk::Rect2D* pRects )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getPresentRectanglesKHR( surface, pRectCount, pRects );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetPresentRectanglesKHR( physicalDevice, surface, pRectCount, pRects );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::Rect2D, std::allocator<vk::Rect2D>>> vkInterface::GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getPresentRectanglesKHR( surface );
//         return ResultValue<vk::Result, std::vector<vk::Rect2D, std::allocator<vk::Rect2D>>>( res );
// #else
//         return s_MockPtr->_GetPresentRectanglesKHR( physicalDevice, surface );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::DisplayPropertiesKHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPropertiesKHR( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPropertiesKHR( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, std::allocator<vk::DisplayPropertiesKHR>>> vkInterface::GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPropertiesKHR();
//         return ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, std::allocator<vk::DisplayPropertiesKHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayPropertiesKHR( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::DisplayPlanePropertiesKHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlanePropertiesKHR( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPlanePropertiesKHR( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayPlanePropertiesKHR, std::allocator<vk::DisplayPlanePropertiesKHR>>> vkInterface::GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlanePropertiesKHR();
//         return ResultValue<vk::Result, std::vector<vk::DisplayPlanePropertiesKHR, std::allocator<vk::DisplayPlanePropertiesKHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayPlanePropertiesKHR( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex, uint32_t* pDisplayCount, vk::DisplayKHR* pDisplays )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneSupportedDisplaysKHR( planeIndex, pDisplayCount, pDisplays );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneSupportedDisplaysKHR( physicalDevice, planeIndex, pDisplayCount, pDisplays );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayKHR, std::allocator<vk::DisplayKHR>>> vkInterface::GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneSupportedDisplaysKHR( planeIndex );
//         return ResultValue<vk::Result, std::vector<vk::DisplayKHR, std::allocator<vk::DisplayKHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneSupportedDisplaysKHR( physicalDevice, planeIndex );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display, uint32_t* pPropertyCount, vk::DisplayModePropertiesKHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayModePropertiesKHR( display, pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayModePropertiesKHR( physicalDevice, display, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayModePropertiesKHR, std::allocator<vk::DisplayModePropertiesKHR>>> vkInterface::GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayModePropertiesKHR( display );
//         return ResultValue<vk::Result, std::vector<vk::DisplayModePropertiesKHR, std::allocator<vk::DisplayModePropertiesKHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayModePropertiesKHR( physicalDevice, display );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display, const vk::DisplayModeCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DisplayModeKHR* pMode )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.createDisplayModeKHR( display, pCreateInfo, pAllocator, pMode );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDisplayModeKHR( physicalDevice, display, pCreateInfo, pAllocator, pMode );
// #endif
//     }

//     ResultValue<vk::Result, vk::DisplayModeKHR> vkInterface::CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display, const vk::DisplayModeCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.createDisplayModeKHR( display, createInfo, allocator );
//         return ResultValue<vk::Result, vk::DisplayModeKHR>( res );
// #else
//         return s_MockPtr->_CreateDisplayModeKHR( physicalDevice, display, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode, uint32_t planeIndex, vk::DisplayPlaneCapabilitiesKHR* pCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneCapabilitiesKHR( mode, planeIndex, pCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneCapabilitiesKHR( physicalDevice, mode, planeIndex, pCapabilities );
// #endif
//     }

//     ResultValue<vk::Result, vk::DisplayPlaneCapabilitiesKHR> vkInterface::GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode, uint32_t planeIndex )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneCapabilitiesKHR( mode, planeIndex );
//         return ResultValue<vk::Result, vk::DisplayPlaneCapabilitiesKHR>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneCapabilitiesKHR( physicalDevice, mode, planeIndex );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice, const vk::VideoProfileInfoKHR* pVideoProfile, vk::VideoCapabilitiesKHR* pCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getVideoCapabilitiesKHR( pVideoProfile, pCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetVideoCapabilitiesKHR( physicalDevice, pVideoProfile, pCapabilities );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetVideoFormatPropertiesKHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo, uint32_t* pVideoFormatPropertyCount, vk::VideoFormatPropertiesKHR* pVideoFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getVideoFormatPropertiesKHR( pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetVideoFormatPropertiesKHR( physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount, pVideoFormatProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetExternalImageFormatPropertiesNV( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type, vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags, vk::ExternalMemoryHandleTypeFlagsNV externalHandleType,
//                                                                                  vk::ExternalImageFormatPropertiesNV* pExternalImageFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getExternalImageFormatPropertiesNV( format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetExternalImageFormatPropertiesNV( physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties );
// #endif
//     }

//     void vkInterface::GetFeatures2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getFeatures2KHR( pFeatures );
// #else
//         s_MockPtr->_GetFeatures2KHR( physicalDevice, pFeatures );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceFeatures2> vkInterface::GetFeatures2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFeatures2KHR();
//         return ResultValue<vk::Result, vk::PhysicalDeviceFeatures2>( res );
// #else
//         return s_MockPtr->_GetFeatures2KHR( physicalDevice );
// #endif
//     }

//     void vkInterface::GetProperties2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getProperties2KHR( pProperties );
// #else
//         s_MockPtr->_GetProperties2KHR( physicalDevice, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceProperties2> vkInterface::GetProperties2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getProperties2KHR();
//         return ResultValue<vk::Result, vk::PhysicalDeviceProperties2>( res );
// #else
//         return s_MockPtr->_GetProperties2KHR( physicalDevice );
// #endif
//     }

//     void vkInterface::GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format, vk::FormatProperties2* pFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getFormatProperties2KHR( format, pFormatProperties );
// #else
//         s_MockPtr->_GetFormatProperties2KHR( physicalDevice, format, pFormatProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::FormatProperties2> vkInterface::GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFormatProperties2KHR( format );
//         return ResultValue<vk::Result, vk::FormatProperties2>( res );
// #else
//         return s_MockPtr->_GetFormatProperties2KHR( physicalDevice, format );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo, vk::ImageFormatProperties2* pImageFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getImageFormatProperties2KHR( pImageFormatInfo, pImageFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetImageFormatProperties2KHR( physicalDevice, pImageFormatInfo, pImageFormatProperties );
// #endif
//     }

//     void vkInterface::GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount, vk::QueueFamilyProperties2* pQueueFamilyProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getQueueFamilyProperties2KHR( pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #else
//         s_MockPtr->_GetQueueFamilyProperties2KHR( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>> vkInterface::GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getQueueFamilyProperties2KHR();
//         return ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>( res );
// #else
//         return s_MockPtr->_GetQueueFamilyProperties2KHR( physicalDevice );
// #endif
//     }

//     void vkInterface::GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceMemoryProperties2* pMemoryProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getMemoryProperties2KHR( pMemoryProperties );
// #else
//         s_MockPtr->_GetMemoryProperties2KHR( physicalDevice, pMemoryProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2> vkInterface::GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getMemoryProperties2KHR();
//         return ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>( res );
// #else
//         return s_MockPtr->_GetMemoryProperties2KHR( physicalDevice );
// #endif
//     }

//     void vkInterface::GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo, uint32_t* pPropertyCount, vk::SparseImageFormatProperties2* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getSparseImageFormatProperties2KHR( pFormatInfo, pPropertyCount, pProperties );
// #else
//         s_MockPtr->_GetSparseImageFormatProperties2KHR( physicalDevice, pFormatInfo, pPropertyCount, pProperties );
// #endif
//     }

//     void vkInterface::GetExternalBufferPropertiesKHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo, vk::ExternalBufferProperties* pExternalBufferProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalBufferPropertiesKHR( pExternalBufferInfo, pExternalBufferProperties );
// #else
//         s_MockPtr->_GetExternalBufferPropertiesKHR( physicalDevice, pExternalBufferInfo, pExternalBufferProperties );
// #endif
//     }

//     void vkInterface::GetExternalSemaphorePropertiesKHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo, vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalSemaphorePropertiesKHR( pExternalSemaphoreInfo, pExternalSemaphoreProperties );
// #else
//         s_MockPtr->_GetExternalSemaphorePropertiesKHR( physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties );
// #endif
//     }

//     void vkInterface::ReleaseDisplayEXT( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.releaseDisplayEXT( display );
// #else
//         s_MockPtr->_ReleaseDisplayEXT( physicalDevice, display );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface, vk::SurfaceCapabilities2EXT* pSurfaceCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceCapabilities2EXT( surface, pSurfaceCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceCapabilities2EXT( physicalDevice, surface, pSurfaceCapabilities );
// #endif
//     }

//     ResultValue<vk::Result, vk::SurfaceCapabilities2EXT> vkInterface::GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceCapabilities2EXT( surface );
//         return ResultValue<vk::Result, vk::SurfaceCapabilities2EXT>( res );
// #else
//         return s_MockPtr->_GetSurfaceCapabilities2EXT( physicalDevice, surface );
// #endif
//     }

//     void vkInterface::GetExternalFencePropertiesKHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo, vk::ExternalFenceProperties* pExternalFenceProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getExternalFencePropertiesKHR( pExternalFenceInfo, pExternalFenceProperties );
// #else
//         s_MockPtr->_GetExternalFencePropertiesKHR( physicalDevice, pExternalFenceInfo, pExternalFenceProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumerateQueueFamilyPerformanceQueryCountersKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount, vk::PerformanceCounterKHR* pCounters, vk::PerformanceCounterDescriptionKHR* pCounterDescriptions )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.enumerateQueueFamilyPerformanceQueryCountersKHR( queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumerateQueueFamilyPerformanceQueryCountersKHR( physicalDevice, queueFamilyIndex, pCounterCount, pCounters, pCounterDescriptions );
// #endif
//     }

//     void vkInterface::GetQueueFamilyPerformanceQueryPassesKHR( vk::PhysicalDevice physicalDevice, const vk::QueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getQueueFamilyPerformanceQueryPassesKHR( pPerformanceQueryCreateInfo, pNumPasses );
// #else
//         s_MockPtr->_GetQueueFamilyPerformanceQueryPassesKHR( physicalDevice, pPerformanceQueryCreateInfo, pNumPasses );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, vk::SurfaceCapabilities2KHR* pSurfaceCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceCapabilities2KHR( pSurfaceInfo, pSurfaceCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceCapabilities2KHR( physicalDevice, pSurfaceInfo, pSurfaceCapabilities );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount, vk::SurfaceFormat2KHR* pSurfaceFormats )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfaceFormats2KHR( pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::DisplayProperties2KHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayProperties2KHR( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayProperties2KHR( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayProperties2KHR, std::allocator<vk::DisplayProperties2KHR>>> vkInterface::GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayProperties2KHR();
//         return ResultValue<vk::Result, std::vector<vk::DisplayProperties2KHR, std::allocator<vk::DisplayProperties2KHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayProperties2KHR( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::DisplayPlaneProperties2KHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneProperties2KHR( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneProperties2KHR( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayPlaneProperties2KHR, std::allocator<vk::DisplayPlaneProperties2KHR>>> vkInterface::GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneProperties2KHR();
//         return ResultValue<vk::Result, std::vector<vk::DisplayPlaneProperties2KHR, std::allocator<vk::DisplayPlaneProperties2KHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneProperties2KHR( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display, uint32_t* pPropertyCount, vk::DisplayModeProperties2KHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayModeProperties2KHR( display, pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayModeProperties2KHR( physicalDevice, display, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::DisplayModeProperties2KHR, std::allocator<vk::DisplayModeProperties2KHR>>> vkInterface::GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayModeProperties2KHR( display );
//         return ResultValue<vk::Result, std::vector<vk::DisplayModeProperties2KHR, std::allocator<vk::DisplayModeProperties2KHR>>>( res );
// #else
//         return s_MockPtr->_GetDisplayModeProperties2KHR( physicalDevice, display );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDisplayPlaneCapabilities2KHR( vk::PhysicalDevice physicalDevice, const vk::DisplayPlaneInfo2KHR* pDisplayPlaneInfo, vk::DisplayPlaneCapabilities2KHR* pCapabilities )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDisplayPlaneCapabilities2KHR( pDisplayPlaneInfo, pCapabilities );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDisplayPlaneCapabilities2KHR( physicalDevice, pDisplayPlaneInfo, pCapabilities );
// #endif
//     }

//     void vkInterface::GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples, vk::MultisamplePropertiesEXT* pMultisampleProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         physicalDevice.getMultisamplePropertiesEXT( samples, pMultisampleProperties );
// #else
//         s_MockPtr->_GetMultisamplePropertiesEXT( physicalDevice, samples, pMultisampleProperties );
// #endif
//     }

//     ResultValue<vk::Result, vk::MultisamplePropertiesEXT> vkInterface::GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getMultisamplePropertiesEXT( samples );
//         return ResultValue<vk::Result, vk::MultisamplePropertiesEXT>( res );
// #else
//         return s_MockPtr->_GetMultisamplePropertiesEXT( physicalDevice, samples );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice, uint32_t* pTimeDomainCount, vk::TimeDomainEXT* pTimeDomains )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCalibrateableTimeDomainsEXT( pTimeDomainCount, pTimeDomains );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetCalibrateableTimeDomainsEXT( physicalDevice, pTimeDomainCount, pTimeDomains );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, std::allocator<vk::TimeDomainEXT>>> vkInterface::GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCalibrateableTimeDomainsEXT();
//         return ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, std::allocator<vk::TimeDomainEXT>>>( res );
// #else
//         return s_MockPtr->_GetCalibrateableTimeDomainsEXT( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount, vk::PhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFragmentShadingRatesKHR( pFragmentShadingRateCount, pFragmentShadingRates );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetFragmentShadingRatesKHR( physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PhysicalDeviceFragmentShadingRateKHR, std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>>> vkInterface::GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getFragmentShadingRatesKHR();
//         return ResultValue<vk::Result, std::vector<vk::PhysicalDeviceFragmentShadingRateKHR, std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>>>( res );
// #else
//         return s_MockPtr->_GetFragmentShadingRatesKHR( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount, vk::PhysicalDeviceToolProperties* pToolProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getToolPropertiesEXT( pToolCount, pToolProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetToolPropertiesEXT( physicalDevice, pToolCount, pToolProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, std::allocator<vk::PhysicalDeviceToolProperties>>> vkInterface::GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getToolPropertiesEXT();
//         return ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, std::allocator<vk::PhysicalDeviceToolProperties>>>( res );
// #else
//         return s_MockPtr->_GetToolPropertiesEXT( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::CooperativeMatrixPropertiesNV* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCooperativeMatrixPropertiesNV( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetCooperativeMatrixPropertiesNV( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV, std::allocator<vk::CooperativeMatrixPropertiesNV>>> vkInterface::GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCooperativeMatrixPropertiesNV();
//         return ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV, std::allocator<vk::CooperativeMatrixPropertiesNV>>>( res );
// #else
//         return s_MockPtr->_GetCooperativeMatrixPropertiesNV( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice, uint32_t* pCombinationCount, vk::FramebufferMixedSamplesCombinationNV* pCombinations )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSupportedFramebufferMixedSamplesCombinationsNV( pCombinationCount, pCombinations );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSupportedFramebufferMixedSamplesCombinationsNV( physicalDevice, pCombinationCount, pCombinations );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::FramebufferMixedSamplesCombinationNV, std::allocator<vk::FramebufferMixedSamplesCombinationNV>>> vkInterface::GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSupportedFramebufferMixedSamplesCombinationsNV();
//         return ResultValue<vk::Result, std::vector<vk::FramebufferMixedSamplesCombinationNV, std::allocator<vk::FramebufferMixedSamplesCombinationNV>>>( res );
// #else
//         return s_MockPtr->_GetSupportedFramebufferMixedSamplesCombinationsNV( physicalDevice );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount, vk::PresentModeKHR* pPresentModes )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getSurfacePresentModes2EXT( pSurfaceInfo, pPresentModeCount, pPresentModes );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetSurfacePresentModes2EXT( physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, vk::DisplayKHR display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.acquireDrmDisplayEXT( drmFd, display );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireDrmDisplayEXT( physicalDevice, drmFd, display );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId, vk::DisplayKHR* display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDrmDisplayEXT( drmFd, connectorId, display );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetDrmDisplayEXT( physicalDevice, drmFd, connectorId, display );
// #endif
//     }

//     ResultValue<vk::Result, vk::DisplayKHR> vkInterface::GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getDrmDisplayEXT( drmFd, connectorId );
//         return ResultValue<vk::Result, vk::DisplayKHR>( res );
// #else
//         return s_MockPtr->_GetDrmDisplayEXT( physicalDevice, drmFd, connectorId );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::AcquireWinrtDisplayNV( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.acquireWinrtDisplayNV( display );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_AcquireWinrtDisplayNV( physicalDevice, display );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice, uint32_t deviceRelativeId, vk::DisplayKHR* pDisplay )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getWinrtDisplayNV( deviceRelativeId, pDisplay );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetWinrtDisplayNV( physicalDevice, deviceRelativeId, pDisplay );
// #endif
//     }

//     ResultValue<vk::Result, vk::DisplayKHR> vkInterface::GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice, uint32_t deviceRelativeId )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getWinrtDisplayNV( deviceRelativeId );
//         return ResultValue<vk::Result, vk::DisplayKHR>( res );
// #else
//         return s_MockPtr->_GetWinrtDisplayNV( physicalDevice, deviceRelativeId );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetOpticalFlowImageFormatsNV( vk::PhysicalDevice physicalDevice, const vk::OpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo, uint32_t* pFormatCount, vk::OpticalFlowImageFormatPropertiesNV* pImageFormatProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getOpticalFlowImageFormatsNV( pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetOpticalFlowImageFormatsNV( physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount, pImageFormatProperties );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount, vk::CooperativeMatrixPropertiesKHR* pProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCooperativeMatrixPropertiesKHR( pPropertyCount, pProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_GetCooperativeMatrixPropertiesKHR( physicalDevice, pPropertyCount, pProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR, std::allocator<vk::CooperativeMatrixPropertiesKHR>>> vkInterface::GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = physicalDevice.getCooperativeMatrixPropertiesKHR();
//         return ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR, std::allocator<vk::CooperativeMatrixPropertiesKHR>>>( res );
// #else
//         return s_MockPtr->_GetCooperativeMatrixPropertiesKHR( physicalDevice );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( pAllocator );
// #else
//         s_MockPtr->_Destroy( instance, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( allocator );
// #else
//         s_MockPtr->_Destroy( instance, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumeratePhysicalDevices( vk::Instance instance, uint32_t* pPhysicalDeviceCount, vk::PhysicalDevice* pPhysicalDevices )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.enumeratePhysicalDevices( pPhysicalDeviceCount, pPhysicalDevices );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumeratePhysicalDevices( instance, pPhysicalDeviceCount, pPhysicalDevices );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PhysicalDevice, std::allocator<vk::PhysicalDevice>>> vkInterface::EnumeratePhysicalDevices( vk::Instance instance )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.enumeratePhysicalDevices();
//         return ResultValue<vk::Result, std::vector<vk::PhysicalDevice, std::allocator<vk::PhysicalDevice>>>( res );
// #else
//         return s_MockPtr->_EnumeratePhysicalDevices( instance );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumeratePhysicalDeviceGroups( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount, vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.enumeratePhysicalDeviceGroups( pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumeratePhysicalDeviceGroups( instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
// #endif
//     }

//     void vkInterface::DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroySurfaceKHR( surface, pAllocator );
// #else
//         s_MockPtr->_DestroySurfaceKHR( instance, surface, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::SurfaceKHR surface, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( surface, pAllocator );
// #else
//         s_MockPtr->_Destroy( instance, surface, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::SurfaceKHR surface, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( surface, allocator );
// #else
//         s_MockPtr->_Destroy( instance, surface, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDisplayPlaneSurfaceKHR( pCreateInfo, pAllocator, pSurface );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDisplayPlaneSurfaceKHR( instance, pCreateInfo, pAllocator, pSurface );
// #endif
//     }

//     ResultValue<vk::Result, vk::SurfaceKHR> vkInterface::CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDisplayPlaneSurfaceKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SurfaceKHR>( res );
// #else
//         return s_MockPtr->_CreateDisplayPlaneSurfaceKHR( instance, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createWin32SurfaceKHR( pCreateInfo, pAllocator, pSurface );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateWin32SurfaceKHR( instance, pCreateInfo, pAllocator, pSurface );
// #endif
//     }

//     ResultValue<vk::Result, vk::SurfaceKHR> vkInterface::CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createWin32SurfaceKHR( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SurfaceKHR>( res );
// #else
//         return s_MockPtr->_CreateWin32SurfaceKHR( instance, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DebugReportCallbackEXT* pCallback )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDebugReportCallbackEXT( pCreateInfo, pAllocator, pCallback );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDebugReportCallbackEXT( instance, pCreateInfo, pAllocator, pCallback );
// #endif
//     }

//     ResultValue<vk::Result, vk::DebugReportCallbackEXT> vkInterface::CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDebugReportCallbackEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DebugReportCallbackEXT>( res );
// #else
//         return s_MockPtr->_CreateDebugReportCallbackEXT( instance, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroyDebugReportCallbackEXT( callback, pAllocator );
// #else
//         s_MockPtr->_DestroyDebugReportCallbackEXT( instance, callback, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( callback, pAllocator );
// #else
//         s_MockPtr->_Destroy( instance, callback, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( callback, allocator );
// #else
//         s_MockPtr->_Destroy( instance, callback, allocator );
// #endif
//     }

//     void vkInterface::DebugReportMessageEXT( vk::Instance instance, vk::DebugReportFlagsEXT flags, vk::DebugReportObjectTypeEXT objectType_, uint64_t object, size_t location, int32_t messageCode, const char* pLayerPrefix, const char* pMessage )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.debugReportMessageEXT( flags, objectType_, object, location, messageCode, pLayerPrefix, pMessage );
// #else
//         s_MockPtr->_DebugReportMessageEXT( instance, flags, objectType_, object, location, messageCode, pLayerPrefix, pMessage );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount, vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.enumeratePhysicalDeviceGroupsKHR( pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_EnumeratePhysicalDeviceGroupsKHR( instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
// #endif
//     }

//     ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, std::allocator<vk::PhysicalDeviceGroupProperties>>> vkInterface::EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.enumeratePhysicalDeviceGroupsKHR();
//         return ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, std::allocator<vk::PhysicalDeviceGroupProperties>>>( res );
// #else
//         return s_MockPtr->_EnumeratePhysicalDeviceGroupsKHR( instance );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::DebugUtilsMessengerEXT* pMessenger )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDebugUtilsMessengerEXT( pCreateInfo, pAllocator, pMessenger );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateDebugUtilsMessengerEXT( instance, pCreateInfo, pAllocator, pMessenger );
// #endif
//     }

//     ResultValue<vk::Result, vk::DebugUtilsMessengerEXT> vkInterface::CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createDebugUtilsMessengerEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::DebugUtilsMessengerEXT>( res );
// #else
//         return s_MockPtr->_CreateDebugUtilsMessengerEXT( instance, createInfo, allocator );
// #endif
//     }

//     void vkInterface::DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroyDebugUtilsMessengerEXT( messenger, pAllocator );
// #else
//         s_MockPtr->_DestroyDebugUtilsMessengerEXT( instance, messenger, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger, const vk::AllocationCallbacks* pAllocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( messenger, pAllocator );
// #else
//         s_MockPtr->_Destroy( instance, messenger, pAllocator );
// #endif
//     }

//     void vkInterface::Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.destroy( messenger, allocator );
// #else
//         s_MockPtr->_Destroy( instance, messenger, allocator );
// #endif
//     }

//     void vkInterface::SubmitDebugUtilsMessageEXT( vk::Instance instance, vk::DebugUtilsMessageSeverityFlagBitsEXT messageSeverity, vk::DebugUtilsMessageTypeFlagsEXT messageTypes, const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         instance.submitDebugUtilsMessageEXT( messageSeverity, messageTypes, pCallbackData );
// #else
//         s_MockPtr->_SubmitDebugUtilsMessageEXT( instance, messageSeverity, messageTypes, pCallbackData );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createHeadlessSurfaceEXT( pCreateInfo, pAllocator, pSurface );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateHeadlessSurfaceEXT( instance, pCreateInfo, pAllocator, pSurface );
// #endif
//     }

//     ResultValue<vk::Result, vk::SurfaceKHR> vkInterface::CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = instance.createHeadlessSurfaceEXT( createInfo, allocator );
//         return ResultValue<vk::Result, vk::SurfaceKHR>( res );
// #else
//         return s_MockPtr->_CreateHeadlessSurfaceEXT( instance, createInfo, allocator );
// #endif
//     }

//     ResultValueType<vk::Result> vkInterface::CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo* pCreateInfo, const vk::AllocationCallbacks* pAllocator, vk::Instance* pInstance )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = vk::createInstance( pCreateInfo, pAllocator, pInstance );
//         return ResultValueType<vk::Result>( res );
// #else
//         return s_MockPtr->_CreateInstance( instance, pCreateInfo, pAllocator, pInstance );
// #endif
//     }

//     ResultValue<vk::Result, vk::Instance> vkInterface::CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo& createInfo, vk::Optional<const vk::AllocationCallbacks> allocator )
//     {
// #if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
//         auto res = vk::createInstance( createInfo, allocator );
//         return ResultValue<vk::Result, vk::Instance>( res );
// #else
//         return s_MockPtr->_CreateInstance( instance, createInfo, allocator );
// #endif
//     }

}// namespace FikoEngine

/***********************************************************************************************************************
// clang-format on
***********************************************************************************************************************/