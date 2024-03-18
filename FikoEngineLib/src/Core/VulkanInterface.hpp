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
 * VulkanInterface class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <cstdint>
#include <Core/Result.hpp>
#define VULKAN_HPP_DISABLE_ENHANCED_MODE
#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class vkInterface
    {
    public:
        vkInterface() = default;
        ~vkInterface() = default;

        static ResultValueType<vk::Result> Begin( vk::CommandBuffer commandBuffer,
                                                  const vk::CommandBufferBeginInfo pBeginInfo );

        static ResultValueType<vk::Result> End( vk::CommandBuffer commandBuffer);

        static ResultValueType<vk::Result> Reset( vk::CommandBuffer commandBuffer, vk::CommandBufferResetFlags flags );

        static void BindPipeline( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                  vk::Pipeline pipeline );

        static void SetViewport( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                 const vk::Viewport* pViewports );

        static void SetScissor( vk::CommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                const vk::Rect2D* pScissors );

        static void SetLineWidth( vk::CommandBuffer commandBuffer, float lineWidth );

        static void SetDepthBias( vk::CommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                                  float depthBiasSlopeFactor );

        static void SetBlendConstants( vk::CommandBuffer commandBuffer, const float blendConstants[ 4 ] );

        static void SetDepthBounds( vk::CommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds );

        static void SetStencilCompareMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                           uint32_t compareMask );

        static void SetStencilWriteMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                         uint32_t writeMask );

        static void SetStencilReference( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                         uint32_t reference );

        static void BindDescriptorSets( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                        vk::PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                        const vk::DescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                        const uint32_t* pDynamicOffsets );

        static void BindIndexBuffer( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                     vk::IndexType indexType );

        static void BindVertexBuffers( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                       const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets );

        static void Draw( vk::CommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                          uint32_t firstVertex, uint32_t firstInstance );

        static void DrawIndexed( vk::CommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                 uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance );

        static void DrawIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                  uint32_t drawCount, uint32_t stride );

        static void DrawIndexedIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                         uint32_t drawCount, uint32_t stride );

        static void Dispatch( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ );

        static void DispatchIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset );

        static void CopyBuffer( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Buffer dstBuffer,
                                uint32_t regionCount, const vk::BufferCopy* pRegions );

        static void CopyImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                               vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                               const vk::ImageCopy* pRegions );

        static void BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                               vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                               const vk::ImageBlit* pRegions, vk::Filter filter );

        static void BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                               vk::Image dstImage, vk::ImageLayout dstImageLayout,
                               vk::ArrayProxy<const vk::ImageBlit> const& regions, vk::Filter filter );

        static void CopyBufferToImage( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Image dstImage,
                                       vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                       const vk::BufferImageCopy* pRegions );

        static void CopyImageToBuffer( vk::CommandBuffer commandBuffer, vk::Image srcImage,
                                       vk::ImageLayout srcImageLayout, vk::Buffer dstBuffer, uint32_t regionCount,
                                       const vk::BufferImageCopy* pRegions );

        static void UpdateBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                  vk::DeviceSize dataSize, const void* pData );

        static void FillBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                vk::DeviceSize size, uint32_t data );

        static void ClearColorImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                                     const vk::ClearColorValue* pColor, uint32_t rangeCount,
                                     const vk::ImageSubresourceRange* pRanges );

        static void ClearDepthStencilImage( vk::CommandBuffer commandBuffer, vk::Image image,
                                            vk::ImageLayout imageLayout,
                                            const vk::ClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                            const vk::ImageSubresourceRange* pRanges );

        static void ClearAttachments( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                                      const vk::ClearAttachment* pAttachments, uint32_t rectCount,
                                      const vk::ClearRect* pRects );

        static void ResolveImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                                  vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                  const vk::ImageResolve* pRegions );

        static void SetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask );

        static void ResetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask );

        static void WaitEvents( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask,
                                uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                                uint32_t bufferMemoryBarrierCount, const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                                uint32_t imageMemoryBarrierCount, const vk::ImageMemoryBarrier* pImageMemoryBarriers );

        static void PipelineBarrier( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags srcStageMask,
                                     vk::PipelineStageFlags dstStageMask, vk::DependencyFlags dependencyFlags,
                                     uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                                     uint32_t bufferMemoryBarrierCount,
                                     const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                                     uint32_t imageMemoryBarrierCount,
                                     const vk::ImageMemoryBarrier* pImageMemoryBarriers );

        static void BeginQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                vk::QueryControlFlags flags );

        static void EndQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query );

        static void ResetQueryPool( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery,
                                    uint32_t queryCount );

        static void WriteTimestamp( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                                    vk::QueryPool queryPool, uint32_t query );

        static void CopyQueryPoolResults( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                          vk::DeviceSize stride, vk::QueryResultFlags flags );

        static void PushConstants( vk::CommandBuffer commandBuffer, vk::PipelineLayout layout,
                                   vk::ShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                   const void* pValues );

        static void BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                                     vk::SubpassContents contents );

        static void BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo& renderPassBegin,
                                     vk::SubpassContents contents );

        static void NextSubpass( vk::CommandBuffer commandBuffer, vk::SubpassContents contents );

        static void EndRenderPass( vk::CommandBuffer commandBuffer );

        static void ExecuteCommands( vk::CommandBuffer commandBuffer, uint32_t commandBufferCount,
                                     const vk::CommandBuffer* pCommandBuffers );

        static void SetDeviceMask( vk::CommandBuffer commandBuffer, uint32_t deviceMask );

        static void DispatchBase( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                  uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                  uint32_t groupCountZ );

        static void DrawIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                       vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                       uint32_t stride );

        static void DrawIndexedIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                              vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                              uint32_t maxDrawCount, uint32_t stride );

        static void BeginRenderPass2( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                                      const vk::SubpassBeginInfo* pSubpassBeginInfo );

        static void NextSubpass2( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                                  const vk::SubpassEndInfo* pSubpassEndInfo );

        static void EndRenderPass2( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo );

        static void SetEvent2( vk::CommandBuffer commandBuffer, vk::Event event,
                               const vk::DependencyInfo* pDependencyInfo );

        static void ResetEvent2( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags2 stageMask );

        static void WaitEvents2( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                 const vk::DependencyInfo* pDependencyInfos );

        static void PipelineBarrier2( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo );

        static void WriteTimestamp2( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                     vk::QueryPool queryPool, uint32_t query );

        static void CopyBuffer2( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo );

        static void CopyImage2( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo );

        static void CopyBufferToImage2( vk::CommandBuffer commandBuffer,
                                        const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo );

        static void CopyImageToBuffer2( vk::CommandBuffer commandBuffer,
                                        const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo );

        static void BlitImage2( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo );

        static void ResolveImage2( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo );

        static void BeginRendering( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo );

        static void EndRendering( vk::CommandBuffer commandBuffer );

        static void SetCullMode( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode );

        static void SetFrontFace( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace );

        static void SetPrimitiveTopology( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology );

        static void SetViewportWithCount( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                          const vk::Viewport* pViewports );

        static void SetScissorWithCount( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                         const vk::Rect2D* pScissors );

        static void BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                        const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets,
                                        const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides );

        static void BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                        vk::ArrayProxy<const vk::Buffer> const& buffers,
                                        vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                        vk::ArrayProxy<const vk::DeviceSize> const& sizes,
                                        vk::ArrayProxy<const vk::DeviceSize> const& strides );

        static void SetDepthTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable );

        static void SetDepthWriteEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable );

        static void SetDepthCompareOp( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp );

        static void SetDepthBoundsTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable );

        static void SetStencilTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable );

        static void SetStencilOp( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, vk::StencilOp failOp,
                                  vk::StencilOp passOp, vk::StencilOp depthFailOp, vk::CompareOp compareOp );

        static void SetRasterizerDiscardEnable( vk::CommandBuffer commandBuffer, vk::Bool32 rasterizerDiscardEnable );

        static void SetDepthBiasEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable );

        static void SetPrimitiveRestartEnable( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable );

        static void DebugMarkerBeginEXT( vk::CommandBuffer commandBuffer,
                                         const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo );

        static void DebugMarkerEndEXT( vk::CommandBuffer commandBuffer );

        static void DebugMarkerInsertEXT( vk::CommandBuffer commandBuffer,
                                          const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo );

        static void BeginVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                         const vk::VideoBeginCodingInfoKHR* pBeginInfo );

        static void EndVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                       const vk::VideoEndCodingInfoKHR* pEndCodingInfo );

        static void ControlVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                           const vk::VideoCodingControlInfoKHR* pCodingControlInfo );

        static void DecodeVideoKHR( vk::CommandBuffer commandBuffer, const vk::VideoDecodeInfoKHR* pDecodeInfo );

        static void BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                                     uint32_t bindingCount, const vk::Buffer* pBuffers,
                                                     const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes );

        static void BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                                     vk::ArrayProxy<const vk::Buffer> const& buffers,
                                                     vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                                     vk::ArrayProxy<const vk::DeviceSize> const& sizes );

        static void BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                               uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                               const vk::DeviceSize* pCounterBufferOffsets );

        static void BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                               vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                               vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets );

        static void EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                             uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                             const vk::DeviceSize* pCounterBufferOffsets );

        static void EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                             vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                             vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets );

        static void BeginQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                          vk::QueryControlFlags flags, uint32_t index );

        static void EndQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                        uint32_t index );

        static void DrawIndirectByteCountEXT( vk::CommandBuffer commandBuffer, uint32_t instanceCount,
                                              uint32_t firstInstance, vk::Buffer counterBuffer,
                                              vk::DeviceSize counterBufferOffset, uint32_t counterOffset,
                                              uint32_t vertexStride );

        static void CuLaunchKernelNVX( vk::CommandBuffer commandBuffer, const vk::CuLaunchInfoNVX* pLaunchInfo );

        static void DrawIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                          vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                          uint32_t maxDrawCount, uint32_t stride );

        static void DrawIndexedIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                 vk::DeviceSize offset, vk::Buffer countBuffer,
                                                 vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                 uint32_t stride );

        static void BeginRenderingKHR( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo );

        static void EndRenderingKHR( vk::CommandBuffer commandBuffer );

        static void SetDeviceMaskKHR( vk::CommandBuffer commandBuffer, uint32_t deviceMask );

        static void DispatchBaseKHR( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                     uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                     uint32_t groupCountZ );

        static void PushDescriptorSetKHR( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                          vk::PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                          const vk::WriteDescriptorSet* pDescriptorWrites );

        static void PushDescriptorSetWithTemplateKHR( vk::CommandBuffer commandBuffer,
                                                      vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                      vk::PipelineLayout layout, uint32_t set, const void* pData );

        static void
        BeginConditionalRenderingEXT( vk::CommandBuffer commandBuffer,
                                      const vk::ConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin );

        static void EndConditionalRenderingEXT( vk::CommandBuffer commandBuffer );

        static void SetViewportWScalingNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                           uint32_t viewportCount, const vk::ViewportWScalingNV* pViewportWScalings );

        static void SetDiscardRectangleEXT( vk::CommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                            uint32_t discardRectangleCount, const vk::Rect2D* pDiscardRectangles );

        static void SetDiscardRectangleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 discardRectangleEnable );

        static void SetDiscardRectangleModeEXT( vk::CommandBuffer commandBuffer,
                                                vk::DiscardRectangleModeEXT discardRectangleMode );

        static void BeginRenderPass2KHR( vk::CommandBuffer commandBuffer,
                                         const vk::RenderPassBeginInfo* pRenderPassBegin,
                                         const vk::SubpassBeginInfo* pSubpassBeginInfo );

        static void NextSubpass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                                     const vk::SubpassEndInfo* pSubpassEndInfo );

        static void EndRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo );

        static void BeginDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer,
                                             const vk::DebugUtilsLabelEXT* pLabelInfo );

        static void EndDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer );

        static void InsertDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer,
                                              const vk::DebugUtilsLabelEXT* pLabelInfo );

        static void SetSampleLocationsEXT( vk::CommandBuffer commandBuffer,
                                           const vk::SampleLocationsInfoEXT* pSampleLocationsInfo );

        static void
        BuildAccelerationStructuresKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                        const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                        const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos );

        static void BuildAccelerationStructuresIndirectKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                                            const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                            const vk::DeviceAddress* pIndirectDeviceAddresses,
                                                            const uint32_t* pIndirectStrides,
                                                            const uint32_t* const* ppMaxPrimitiveCounts );

        static void CopyAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                                  const vk::CopyAccelerationStructureInfoKHR* pInfo );

        static void CopyAccelerationStructureToMemoryKHR( vk::CommandBuffer commandBuffer,
                                                          const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo );

        static void CopyMemoryToAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                                          const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo );

        static void
        WriteAccelerationStructuresPropertiesKHR( vk::CommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                  const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                  vk::QueryType queryType, vk::QueryPool queryPool,
                                                  uint32_t firstQuery );

        static void WriteAccelerationStructuresPropertiesKHR(
                vk::CommandBuffer commandBuffer,
                vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
                vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery );

        static void TraceRaysKHR( vk::CommandBuffer commandBuffer,
                                  const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                                  uint32_t height, uint32_t depth );

        static void TraceRaysKHR( vk::CommandBuffer commandBuffer,
                                  const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable, uint32_t width,
                                  uint32_t height, uint32_t depth );

        static void TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                          const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                          vk::DeviceAddress indirectDeviceAddress );

        static void TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                          const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                                          const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable,
                                          vk::DeviceAddress indirectDeviceAddress );

        static void SetRayTracingPipelineStackSizeKHR( vk::CommandBuffer commandBuffer, uint32_t pipelineStackSize );

        static void BindShadingRateImageNV( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                            vk::ImageLayout imageLayout );

        static void SetViewportShadingRatePaletteNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                                     uint32_t viewportCount,
                                                     const vk::ShadingRatePaletteNV* pShadingRatePalettes );

        static void SetCoarseSampleOrderNV( vk::CommandBuffer commandBuffer,
                                            vk::CoarseSampleOrderTypeNV sampleOrderType,
                                            uint32_t customSampleOrderCount,
                                            const vk::CoarseSampleOrderCustomNV* pCustomSampleOrders );

        static void BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer,
                                                  const vk::AccelerationStructureInfoNV* pInfo, vk::Buffer instanceData,
                                                  vk::DeviceSize instanceOffset, vk::Bool32 update,
                                                  vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src,
                                                  vk::Buffer scratch, vk::DeviceSize scratchOffset );

        static void BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer,
                                                  const vk::AccelerationStructureInfoNV& info, vk::Buffer instanceData,
                                                  vk::DeviceSize instanceOffset, vk::Bool32 update,
                                                  vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src,
                                                  vk::Buffer scratch, vk::DeviceSize scratchOffset );

        static void CopyAccelerationStructureNV( vk::CommandBuffer commandBuffer, vk::AccelerationStructureNV dst,
                                                 vk::AccelerationStructureNV src,
                                                 vk::CopyAccelerationStructureModeKHR mode );

        static void TraceRaysNV( vk::CommandBuffer commandBuffer, vk::Buffer raygenShaderBindingTableBuffer,
                                 vk::DeviceSize raygenShaderBindingOffset, vk::Buffer missShaderBindingTableBuffer,
                                 vk::DeviceSize missShaderBindingOffset, vk::DeviceSize missShaderBindingStride,
                                 vk::Buffer hitShaderBindingTableBuffer, vk::DeviceSize hitShaderBindingOffset,
                                 vk::DeviceSize hitShaderBindingStride, vk::Buffer callableShaderBindingTableBuffer,
                                 vk::DeviceSize callableShaderBindingOffset, vk::DeviceSize callableShaderBindingStride,
                                 uint32_t width, uint32_t height, uint32_t depth );

        static void WriteAccelerationStructuresPropertiesNV( vk::CommandBuffer commandBuffer,
                                                             uint32_t accelerationStructureCount,
                                                             const vk::AccelerationStructureNV* pAccelerationStructures,
                                                             vk::QueryType queryType, vk::QueryPool queryPool,
                                                             uint32_t firstQuery );

        static void WriteAccelerationStructuresPropertiesNV(
                vk::CommandBuffer commandBuffer,
                vk::ArrayProxy<const vk::AccelerationStructureNV> const& accelerationStructures,
                vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery );

        static void DrawIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                          vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                          uint32_t maxDrawCount, uint32_t stride );

        static void DrawIndexedIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                 vk::DeviceSize offset, vk::Buffer countBuffer,
                                                 vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                 uint32_t stride );

        static void WriteBufferMarkerAMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                                          vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker );

        static void DrawMeshTasksNV( vk::CommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask );

        static void DrawMeshTasksIndirectNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                             uint32_t drawCount, uint32_t stride );

        static void DrawMeshTasksIndirectCountNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                  vk::DeviceSize offset, vk::Buffer countBuffer,
                                                  vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                  uint32_t stride );

        static void SetExclusiveScissorEnableNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                 uint32_t exclusiveScissorCount,
                                                 const vk::Bool32* pExclusiveScissorEnables );

        static void SetExclusiveScissorNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                           uint32_t exclusiveScissorCount, const vk::Rect2D* pExclusiveScissors );

        static void SetCheckpointNV( vk::CommandBuffer commandBuffer, const void* pCheckpointMarker );

        static ResultValueType<vk::Result>
        SetPerformanceMarkerINTEL( vk::CommandBuffer commandBuffer, const vk::PerformanceMarkerInfoINTEL* pMarkerInfo );

        static ResultValueType<vk::Result>
        SetPerformanceStreamMarkerINTEL( vk::CommandBuffer commandBuffer,
                                         const vk::PerformanceStreamMarkerInfoINTEL* pMarkerInfo );

        static ResultValueType<vk::Result>
        SetPerformanceOverrideINTEL( vk::CommandBuffer commandBuffer,
                                     const vk::PerformanceOverrideInfoINTEL* pOverrideInfo );

        static void SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D* pFragmentSize,
                                               const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] );

        static void SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D& fragmentSize,
                                               const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] );

        static void SetLineStippleEXT( vk::CommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                       uint16_t lineStipplePattern );

        static void SetCullModeEXT( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode );

        static void SetFrontFaceEXT( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace );

        static void SetPrimitiveTopologyEXT( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology );

        static void SetViewportWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                             const vk::Viewport* pViewports );

        static void SetScissorWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                            const vk::Rect2D* pScissors );

        static void BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                           uint32_t bindingCount, const vk::Buffer* pBuffers,
                                           const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes,
                                           const vk::DeviceSize* pStrides );

        static void BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                           vk::ArrayProxy<const vk::Buffer> const& buffers,
                                           vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                           vk::ArrayProxy<const vk::DeviceSize> const& sizes,
                                           vk::ArrayProxy<const vk::DeviceSize> const& strides );

        static void SetDepthTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable );

        static void SetDepthWriteEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable );

        static void SetDepthCompareOpEXT( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp );

        static void SetDepthBoundsTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable );

        static void SetStencilTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable );

        static void SetStencilOpEXT( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                     vk::StencilOp failOp, vk::StencilOp passOp, vk::StencilOp depthFailOp,
                                     vk::CompareOp compareOp );

        static void PreprocessGeneratedCommandsNV( vk::CommandBuffer commandBuffer,
                                                   const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo );

        static void ExecuteGeneratedCommandsNV( vk::CommandBuffer commandBuffer, vk::Bool32 isPreprocessed,
                                                const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo );

        static void BindPipelineShaderGroupNV( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                               vk::Pipeline pipeline, uint32_t groupIndex );

        static void SetDepthBias2EXT( vk::CommandBuffer commandBuffer, const vk::DepthBiasInfoEXT* pDepthBiasInfo );

        static void SetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                                  const vk::DependencyInfo* pDependencyInfo );

        static void ResetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                                    vk::PipelineStageFlags2 stageMask );

        static void WaitEvents2KHR( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                    const vk::DependencyInfo* pDependencyInfos );

        static void PipelineBarrier2KHR( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo );

        static void WriteTimestamp2KHR( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                        vk::QueryPool queryPool, uint32_t query );

        static void WriteBufferMarker2AMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                           vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker );

        static void BindDescriptorBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t bufferCount,
                                              const vk::DescriptorBufferBindingInfoEXT* pBindingInfos );

        static void SetDescriptorBufferOffsetsEXT( vk::CommandBuffer commandBuffer,
                                                   vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout,
                                                   uint32_t firstSet, uint32_t setCount, const uint32_t* pBufferIndices,
                                                   const vk::DeviceSize* pOffsets );

        static void BindDescriptorBufferEmbeddedSamplersEXT( vk::CommandBuffer commandBuffer,
                                                             vk::PipelineBindPoint pipelineBindPoint,
                                                             vk::PipelineLayout layout, uint32_t set );

        static void SetFragmentShadingRateEnumNV( vk::CommandBuffer commandBuffer,
                                                  vk::FragmentShadingRateNV shadingRate,
                                                  const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] );

        static void DrawMeshTasksEXT( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                      uint32_t groupCountZ );

        static void DrawMeshTasksIndirectEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                              uint32_t drawCount, uint32_t stride );

        static void DrawMeshTasksIndirectCountEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                   vk::DeviceSize offset, vk::Buffer countBuffer,
                                                   vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                   uint32_t stride );

        static void CopyBuffer2KHR( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo );

        static void CopyImage2KHR( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo );

        static void CopyBufferToImage2KHR( vk::CommandBuffer commandBuffer,
                                           const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo );

        static void CopyImageToBuffer2KHR( vk::CommandBuffer commandBuffer,
                                           const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo );

        static void BlitImage2KHR( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo );

        static void ResolveImage2KHR( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo );

        static void SetVertexInputEXT( vk::CommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                                       const vk::VertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                                       uint32_t vertexAttributeDescriptionCount,
                                       const vk::VertexInputAttributeDescription2EXT* pVertexAttributeDescriptions );

        static void SubpassShadingHUAWEI( vk::CommandBuffer commandBuffer );

        static void BindInvocationMaskHUAWEI( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                              vk::ImageLayout imageLayout );

        static void SetPatchControlPointsEXT( vk::CommandBuffer commandBuffer, uint32_t patchControlPoints );

        static void SetRasterizerDiscardEnableEXT( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 rasterizerDiscardEnable );

        static void SetDepthBiasEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable );

        static void SetLogicOpEXT( vk::CommandBuffer commandBuffer, vk::LogicOp logicOp );

        static void SetPrimitiveRestartEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable );

        static void SetColorWriteEnableEXT( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                                            const vk::Bool32* pColorWriteEnables );

        static void TraceRaysIndirect2KHR( vk::CommandBuffer commandBuffer, vk::DeviceAddress indirectDeviceAddress );

        static void DrawMultiEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount,
                                  const vk::MultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                  uint32_t firstInstance, uint32_t stride );

        static void DrawMultiEXT( vk::CommandBuffer commandBuffer,
                                  vk::StridedArrayProxy<const vk::MultiDrawInfoEXT> const& vertexInfo,
                                  uint32_t instanceCount, uint32_t firstInstance );

        static void DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount,
                                         const vk::MultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                         uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset );

        static void DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer,
                                         vk::StridedArrayProxy<const vk::MultiDrawIndexedInfoEXT> const& indexInfo,
                                         uint32_t instanceCount, uint32_t firstInstance,
                                         vk::Optional<const int32_t> vertexOffset );

        static void BuildMicromapsEXT( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                       const vk::MicromapBuildInfoEXT* pInfos );

        static void CopyMicromapEXT( vk::CommandBuffer commandBuffer, const vk::CopyMicromapInfoEXT* pInfo );

        static void CopyMicromapToMemoryEXT( vk::CommandBuffer commandBuffer,
                                             const vk::CopyMicromapToMemoryInfoEXT* pInfo );

        static void CopyMemoryToMicromapEXT( vk::CommandBuffer commandBuffer,
                                             const vk::CopyMemoryToMicromapInfoEXT* pInfo );

        static void WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer, uint32_t micromapCount,
                                                 const vk::MicromapEXT* pMicromaps, vk::QueryType queryType,
                                                 vk::QueryPool queryPool, uint32_t firstQuery );

        static void WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer,
                                                 vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                                                 vk::QueryType queryType, vk::QueryPool queryPool,
                                                 uint32_t firstQuery );

        static void DrawClusterHUAWEI( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ );

        static void DrawClusterIndirectHUAWEI( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                               vk::DeviceSize offset );

        static void CopyMemoryIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                          uint32_t copyCount, uint32_t stride );

        static void CopyMemoryToImageIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                                 uint32_t copyCount, uint32_t stride, vk::Image dstImage,
                                                 vk::ImageLayout dstImageLayout,
                                                 const vk::ImageSubresourceLayers* pImageSubresources );

        static void DecompressMemoryNV( vk::CommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                        const vk::DecompressMemoryRegionNV* pDecompressMemoryRegions );

        static void DecompressMemoryIndirectCountNV( vk::CommandBuffer commandBuffer,
                                                     vk::DeviceAddress indirectCommandsAddress,
                                                     vk::DeviceAddress indirectCommandsCountAddress, uint32_t stride );

        static void UpdatePipelineIndirectBufferNV( vk::CommandBuffer commandBuffer,
                                                    vk::PipelineBindPoint pipelineBindPoint, vk::Pipeline pipeline );

        static void SetTessellationDomainOriginEXT( vk::CommandBuffer commandBuffer,
                                                    vk::TessellationDomainOrigin domainOrigin );

        static void SetDepthClampEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClampEnable );

        static void SetPolygonModeEXT( vk::CommandBuffer commandBuffer, vk::PolygonMode polygonMode );

        static void SetRasterizationSamplesEXT( vk::CommandBuffer commandBuffer,
                                                vk::SampleCountFlagBits rasterizationSamples );

        static void SetSampleMaskEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits samples,
                                      const vk::SampleMask* pSampleMask );

        static void SetAlphaToCoverageEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToCoverageEnable );

        static void SetAlphaToOneEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToOneEnable );

        static void SetLogicOpEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 logicOpEnable );

        static void SetColorBlendEnableEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                            uint32_t attachmentCount, const vk::Bool32* pColorBlendEnables );

        static void SetColorBlendEquationEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                              uint32_t attachmentCount,
                                              const vk::ColorBlendEquationEXT* pColorBlendEquations );

        static void SetColorWriteMaskEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                          uint32_t attachmentCount, const vk::ColorComponentFlags* pColorWriteMasks );

        static void SetRasterizationStreamEXT( vk::CommandBuffer commandBuffer, uint32_t rasterizationStream );

        static void
        SetConservativeRasterizationModeEXT( vk::CommandBuffer commandBuffer,
                                             vk::ConservativeRasterizationModeEXT conservativeRasterizationMode );

        static void SetExtraPrimitiveOverestimationSizeEXT( vk::CommandBuffer commandBuffer,
                                                            float extraPrimitiveOverestimationSize );

        static void SetDepthClipEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClipEnable );

        static void SetSampleLocationsEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 sampleLocationsEnable );

        static void SetColorBlendAdvancedEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                              uint32_t attachmentCount,
                                              const vk::ColorBlendAdvancedEXT* pColorBlendAdvanced );

        static void SetProvokingVertexModeEXT( vk::CommandBuffer commandBuffer,
                                               vk::ProvokingVertexModeEXT provokingVertexMode );

        static void SetLineRasterizationModeEXT( vk::CommandBuffer commandBuffer,
                                                 vk::LineRasterizationModeEXT lineRasterizationMode );

        static void SetLineStippleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stippledLineEnable );

        static void SetDepthClipNegativeOneToOneEXT( vk::CommandBuffer commandBuffer, vk::Bool32 negativeOneToOne );

        static void SetViewportWScalingEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 viewportWScalingEnable );

        static void SetViewportSwizzleNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                          uint32_t viewportCount, const vk::ViewportSwizzleNV* pViewportSwizzles );

        static void SetCoverageToColorEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 coverageToColorEnable );

        static void SetCoverageToColorLocationNV( vk::CommandBuffer commandBuffer, uint32_t coverageToColorLocation );

        static void SetCoverageModulationModeNV( vk::CommandBuffer commandBuffer,
                                                 vk::CoverageModulationModeNV coverageModulationMode );

        static void SetCoverageModulationTableEnableNV( vk::CommandBuffer commandBuffer,
                                                        vk::Bool32 coverageModulationTableEnable );

        static void SetCoverageModulationTableNV( vk::CommandBuffer commandBuffer,
                                                  uint32_t coverageModulationTableCount,
                                                  const float* pCoverageModulationTable );

        static void SetShadingRateImageEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 shadingRateImageEnable );

        static void SetRepresentativeFragmentTestEnableNV( vk::CommandBuffer commandBuffer,
                                                           vk::Bool32 representativeFragmentTestEnable );

        static void SetCoverageReductionModeNV( vk::CommandBuffer commandBuffer,
                                                vk::CoverageReductionModeNV coverageReductionMode );

        static void OpticalFlowExecuteNV( vk::CommandBuffer commandBuffer, vk::OpticalFlowSessionNV session,
                                          const vk::OpticalFlowExecuteInfoNV* pExecuteInfo );

        static void BindIndexBuffer2KHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                         vk::DeviceSize size, vk::IndexType indexType );

        static void BindShadersEXT( vk::CommandBuffer commandBuffer, uint32_t stageCount,
                                    const vk::ShaderStageFlagBits* pStages, const vk::ShaderEXT* pShaders );

        static void SetAttachmentFeedbackLoopEnableEXT( vk::CommandBuffer commandBuffer,
                                                        vk::ImageAspectFlags aspectMask );

        static ResultValueType<vk::Result> Submit( vk::Queue queue, uint32_t submitCount,
                                                   const vk::SubmitInfo* pSubmits, vk::Fence fence );

        static ResultValueType<vk::Result> WaitIdle( vk::Queue queue );

        static ResultValueType<vk::Result> BindSparse( vk::Queue queue, uint32_t bindInfoCount,
                                                       const vk::BindSparseInfo* pBindInfo, vk::Fence fence );

        static ResultValueType<vk::Result>
        BindSparse( vk::Queue queue, vk::ArrayProxy<const vk::BindSparseInfo> const& bindInfo, vk::Fence fence );

        static ResultValueType<vk::Result> Submit2( vk::Queue queue, uint32_t submitCount,
                                                    const vk::SubmitInfo2* pSubmits, vk::Fence fence );

        static ResultValueType<vk::Result>
        Submit2( vk::Queue queue, vk::ArrayProxy<const vk::SubmitInfo2> const& submits, vk::Fence fence );

        static ResultValueType<vk::Result> PresentKHR( vk::Queue queue, const vk::PresentInfoKHR* pPresentInfo );

        static void BeginDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo );

        static void EndDebugUtilsLabelEXT( vk::Queue queue );

        static void InsertDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo );

        static void GetCheckpointDataNV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                         vk::CheckpointDataNV* pCheckpointData );

        static ResultValue<vk::Result, std::vector<vk::CheckpointDataNV, std::allocator<vk::CheckpointDataNV>>>
        GetCheckpointDataNV( vk::Queue queue );

        static ResultValueType<vk::Result>
        SetPerformanceConfigurationINTEL( vk::Queue queue, vk::PerformanceConfigurationINTEL configuration );

        static ResultValueType<vk::Result> Submit2KHR( vk::Queue queue, uint32_t submitCount,
                                                       const vk::SubmitInfo2* pSubmits, vk::Fence fence );

        static ResultValueType<vk::Result>
        Submit2KHR( vk::Queue queue, vk::ArrayProxy<const vk::SubmitInfo2> const& submits, vk::Fence fence );

        static void GetCheckpointData2NV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                          vk::CheckpointData2NV* pCheckpointData );

        static ResultValue<vk::Result, std::vector<vk::CheckpointData2NV, std::allocator<vk::CheckpointData2NV>>>
        GetCheckpointData2NV( vk::Queue queue );

        static void Destroy( vk::Device device, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex, vk::Queue* pQueue );

        static ResultValue<vk::Result, vk::Queue> GetQueue( vk::Device device, uint32_t queueFamilyIndex,
                                                            uint32_t queueIndex );

        static ResultValueType<vk::Result> WaitIdle( vk::Device device );

        static ResultValueType<vk::Result> AllocateMemory( vk::Device device,
                                                           const vk::MemoryAllocateInfo* pAllocateInfo,
                                                           const vk::AllocationCallbacks* pAllocator,
                                                           vk::DeviceMemory* pMemory );

        static ResultValue<vk::Result, vk::DeviceMemory>
        AllocateMemory( vk::Device device, const vk::MemoryAllocateInfo& allocateInfo,
                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void FreeMemory( vk::Device device, vk::DeviceMemory memory, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void FreeMemory( vk::Device device, vk::DeviceMemory memory,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> MapMemory( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize offset,
                                                      vk::DeviceSize size, vk::MemoryMapFlags flags, void** ppData );

        static ResultValue<vk::Result, void*> MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                         vk::DeviceSize offset, vk::DeviceSize size,
                                                         vk::MemoryMapFlags flags );

        static void UnmapMemory( vk::Device device, vk::DeviceMemory memory );

        static ResultValueType<vk::Result> FlushMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                                                    const vk::MappedMemoryRange* pMemoryRanges );

        static ResultValueType<vk::Result> InvalidateMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                                                         const vk::MappedMemoryRange* pMemoryRanges );

        static void GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory,
                                         vk::DeviceSize* pCommittedMemoryInBytes );

        static ResultValue<vk::Result, vk::DeviceSize> GetMemoryCommitment( vk::Device device,
                                                                            vk::DeviceMemory memory );

        static ResultValueType<vk::Result> BindBufferMemory( vk::Device device, vk::Buffer buffer,
                                                             vk::DeviceMemory memory, vk::DeviceSize memoryOffset );

        static ResultValueType<vk::Result> BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                                            vk::DeviceSize memoryOffset );

        static void GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer,
                                                 vk::MemoryRequirements* pMemoryRequirements );

        static ResultValue<vk::Result, vk::MemoryRequirements> GetBufferMemoryRequirements( vk::Device device,
                                                                                            vk::Buffer buffer );

        static void GetImageMemoryRequirements( vk::Device device, vk::Image image,
                                                vk::MemoryRequirements* pMemoryRequirements );

        static ResultValue<vk::Result, vk::MemoryRequirements> GetImageMemoryRequirements( vk::Device device,
                                                                                           vk::Image image );

        static void GetImageSparseMemoryRequirements( vk::Device device, vk::Image image,
                                                      uint32_t* pSparseMemoryRequirementCount,
                                                      vk::SparseImageMemoryRequirements* pSparseMemoryRequirements );

        static ResultValue<vk::Result, std::vector<vk::SparseImageMemoryRequirements,
                                                   std::allocator<vk::SparseImageMemoryRequirements>>>
        GetImageSparseMemoryRequirements( vk::Device device, vk::Image image );

        static ResultValueType<vk::Result> CreateFence( vk::Device device, const vk::FenceCreateInfo* pCreateInfo,
                                                        const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence );

        static ResultValue<vk::Result, vk::Fence> CreateFence( vk::Device device, const vk::FenceCreateInfo& createInfo,
                                                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyFence( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyFence( vk::Device device, vk::Fence fence,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Fence fence,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> ResetFences( vk::Device device, uint32_t fenceCount,
                                                        const vk::Fence* pFences );

        static ResultValueType<vk::Result> GetFenceStatus( vk::Device device, vk::Fence fence );

        static ResultValueType<vk::Result> WaitForFences( vk::Device device, uint32_t fenceCount,
                                                          const vk::Fence* pFences, vk::Bool32 waitAll,
                                                          uint64_t timeout );

        static ResultValueType<vk::Result> WaitForFences( vk::Device device,
                                                          vk::ArrayProxy<const vk::Fence> const& fences,
                                                          vk::Bool32 waitAll, uint64_t timeout );

        static ResultValueType<vk::Result> CreateSemaphore( vk::Device device,
                                                            const vk::SemaphoreCreateInfo* pCreateInfo,
                                                            const vk::AllocationCallbacks* pAllocator,
                                                            vk::Semaphore* pSemaphore );

        static ResultValue<vk::Result, vk::Semaphore>
        CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo& createInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroySemaphore( vk::Device device, vk::Semaphore semaphore,
                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySemaphore( vk::Device device, vk::Semaphore semaphore,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Semaphore semaphore, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Semaphore semaphore,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateEvent( vk::Device device, const vk::EventCreateInfo* pCreateInfo,
                                                        const vk::AllocationCallbacks* pAllocator, vk::Event* pEvent );

        static ResultValue<vk::Result, vk::Event> CreateEvent( vk::Device device, const vk::EventCreateInfo& createInfo,
                                                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyEvent( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyEvent( vk::Device device, vk::Event event,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Event event,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetEventStatus( vk::Device device, vk::Event event );

        static ResultValueType<vk::Result> SetEvent( vk::Device device, vk::Event event );

        static ResultValueType<vk::Result> ResetEvent( vk::Device device, vk::Event event );

        static ResultValueType<vk::Result> CreateQueryPool( vk::Device device,
                                                            const vk::QueryPoolCreateInfo* pCreateInfo,
                                                            const vk::AllocationCallbacks* pAllocator,
                                                            vk::QueryPool* pQueryPool );

        static ResultValue<vk::Result, vk::QueryPool>
        CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo& createInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyQueryPool( vk::Device device, vk::QueryPool queryPool,
                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyQueryPool( vk::Device device, vk::QueryPool queryPool,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::QueryPool queryPool, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::QueryPool queryPool,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool,
                                                                uint32_t firstQuery, uint32_t queryCount,
                                                                size_t dataSize, void* pData, vk::DeviceSize stride,
                                                                vk::QueryResultFlags flags );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                             size_t dataSize, vk::DeviceSize stride, vk::QueryResultFlags flags );

        static ResultValue<vk::Result, uint8_t> GetQueryPoolResult( vk::Device device, vk::QueryPool queryPool,
                                                                    uint32_t firstQuery, uint32_t queryCount,
                                                                    vk::DeviceSize stride, vk::QueryResultFlags flags );

        static ResultValueType<vk::Result> CreateBuffer( vk::Device device, const vk::BufferCreateInfo* pCreateInfo,
                                                         const vk::AllocationCallbacks* pAllocator,
                                                         vk::Buffer* pBuffer );

        static ResultValue<vk::Result, vk::Buffer>
        CreateBuffer( vk::Device device, const vk::BufferCreateInfo& createInfo,
                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyBuffer( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyBuffer( vk::Device device, vk::Buffer buffer,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Buffer buffer,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateBufferView( vk::Device device,
                                                             const vk::BufferViewCreateInfo* pCreateInfo,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::BufferView* pView );

        static ResultValue<vk::Result, vk::BufferView>
        CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyBufferView( vk::Device device, vk::BufferView bufferView,
                                       const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyBufferView( vk::Device device, vk::BufferView bufferView,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::BufferView bufferView, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::BufferView bufferView,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateImage( vk::Device device, const vk::ImageCreateInfo* pCreateInfo,
                                                        const vk::AllocationCallbacks* pAllocator, vk::Image* pImage );

        static ResultValue<vk::Result, vk::Image> CreateImage( vk::Device device, const vk::ImageCreateInfo& createInfo,
                                                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyImage( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyImage( vk::Device device, vk::Image image,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Image image,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void GetImageSubresourceLayout( vk::Device device, vk::Image image,
                                               const vk::ImageSubresource* pSubresource,
                                               vk::SubresourceLayout* pLayout );

        static ResultValueType<vk::Result> CreateImageView( vk::Device device,
                                                            const vk::ImageViewCreateInfo* pCreateInfo,
                                                            const vk::AllocationCallbacks* pAllocator,
                                                            vk::ImageView* pView );

        static ResultValue<vk::Result, vk::ImageView>
        CreateImageView( vk::Device device, const vk::ImageViewCreateInfo& createInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyImageView( vk::Device device, vk::ImageView imageView,
                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyImageView( vk::Device device, vk::ImageView imageView,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::ImageView imageView, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::ImageView imageView,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateShaderModule( vk::Device device,
                                                               const vk::ShaderModuleCreateInfo* pCreateInfo,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::ShaderModule* pShaderModule );

        static ResultValue<vk::Result, vk::ShaderModule>
        CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule,
                                         const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::ShaderModule shaderModule,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::ShaderModule shaderModule,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreatePipelineCache( vk::Device device,
                                                                const vk::PipelineCacheCreateInfo* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::PipelineCache* pPipelineCache );

        static ResultValue<vk::Result, vk::PipelineCache>
        CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo& createInfo,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache,
                                          const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache,
                                                                 size_t* pDataSize, void* pData );

        static ResultValueType<vk::Result> MergePipelineCaches( vk::Device device, vk::PipelineCache dstCache,
                                                                uint32_t srcCacheCount,
                                                                const vk::PipelineCache* pSrcCaches );

        static ResultValueType<vk::Result> CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                                                    uint32_t createInfoCount,
                                                                    const vk::GraphicsPipelineCreateInfo* pCreateInfos,
                                                                    const vk::AllocationCallbacks* pAllocator,
                                                                    vk::Pipeline* pPipelines );

        static ResultValue<vk::Result, std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                 vk::ArrayProxy<const vk::GraphicsPipelineCreateInfo> const& createInfos,
                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::Pipeline>
        CreateGraphicsPipeline( vk::Device device, vk::PipelineCache pipelineCache,
                                const vk::GraphicsPipelineCreateInfo& createInfo,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                                                   uint32_t createInfoCount,
                                                                   const vk::ComputePipelineCreateInfo* pCreateInfos,
                                                                   const vk::AllocationCallbacks* pAllocator,
                                                                   vk::Pipeline* pPipelines );

        static ResultValue<vk::Result, std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                vk::ArrayProxy<const vk::ComputePipelineCreateInfo> const& createInfos,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::Pipeline>
        CreateComputePipeline( vk::Device device, vk::PipelineCache pipelineCache,
                               const vk::ComputePipelineCreateInfo& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyPipeline( vk::Device device, vk::Pipeline pipeline,
                                     const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyPipeline( vk::Device device, vk::Pipeline pipeline,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Pipeline pipeline, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Pipeline pipeline,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreatePipelineLayout( vk::Device device,
                                                                 const vk::PipelineLayoutCreateInfo* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::PipelineLayout* pPipelineLayout );

        static ResultValue<vk::Result, vk::PipelineLayout>
        CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout,
                                           const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateSampler( vk::Device device, const vk::SamplerCreateInfo* pCreateInfo,
                                                          const vk::AllocationCallbacks* pAllocator,
                                                          vk::Sampler* pSampler );

        static ResultValue<vk::Result, vk::Sampler>
        CreateSampler( vk::Device device, const vk::SamplerCreateInfo& createInfo,
                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroySampler( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySampler( vk::Device device, vk::Sampler sampler,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Sampler sampler,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator, vk::DescriptorSetLayout* pSetLayout );

        static ResultValue<vk::Result, vk::DescriptorSetLayout>
        CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                                                const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateDescriptorPool( vk::Device device,
                                                                 const vk::DescriptorPoolCreateInfo* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::DescriptorPool* pDescriptorPool );

        static ResultValue<vk::Result, vk::DescriptorPool>
        CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                           const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> ResetDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                                                vk::DescriptorPoolResetFlags flags );

        static ResultValueType<vk::Result> AllocateDescriptorSets( vk::Device device,
                                                                   const vk::DescriptorSetAllocateInfo* pAllocateInfo,
                                                                   vk::DescriptorSet* pDescriptorSets );

        static ResultValueType<vk::Result> FreeDescriptorSets( vk::Device device, vk::DescriptorPool descriptorPool,
                                                               uint32_t descriptorSetCount,
                                                               const vk::DescriptorSet* pDescriptorSets );

        static void UpdateDescriptorSets( vk::Device device, uint32_t descriptorWriteCount,
                                          const vk::WriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                          const vk::CopyDescriptorSet* pDescriptorCopies );

        static ResultValueType<vk::Result> CreateFramebuffer( vk::Device device,
                                                              const vk::FramebufferCreateInfo* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::Framebuffer* pFramebuffer );

        static ResultValue<vk::Result, vk::Framebuffer>
        CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer,
                                        const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::Framebuffer framebuffer,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::Framebuffer framebuffer,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateRenderPass( vk::Device device,
                                                             const vk::RenderPassCreateInfo* pCreateInfo,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::RenderPass* pRenderPass );

        static ResultValue<vk::Result, vk::RenderPass>
        CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyRenderPass( vk::Device device, vk::RenderPass renderPass,
                                       const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyRenderPass( vk::Device device, vk::RenderPass renderPass,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::RenderPass renderPass, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::RenderPass renderPass,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass,
                                              vk::Extent2D* pGranularity );

        static ResultValue<vk::Result, vk::Extent2D> GetRenderAreaGranularity( vk::Device device,
                                                                               vk::RenderPass renderPass );

        static ResultValueType<vk::Result> CreateCommandPool( vk::Device device,
                                                              const vk::CommandPoolCreateInfo* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::CommandPool* pCommandPool );

        static ResultValue<vk::Result, vk::CommandPool>
        CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyCommandPool( vk::Device device, vk::CommandPool commandPool,
                                        const vk::AllocationCallbacks* pAllocator);

        static void DestroyCommandPool( vk::Device device, vk::CommandPool commandPool,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::CommandPool commandPool,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::CommandPool commandPool,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> ResetCommandPool( vk::Device device, vk::CommandPool commandPool,
                                                             vk::CommandPoolResetFlags flags );

        static ResultValueType<vk::Result> AllocateCommandBuffers( vk::Device device,
                                                                   const vk::CommandBufferAllocateInfo* pAllocateInfo,
                                                                   vk::CommandBuffer* pCommandBuffers );

        static ResultValue<vk::Result, std::vector<vk::CommandBuffer>>
        AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo );

        static void FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, uint32_t commandBufferCount,
                                        const vk::CommandBuffer* pCommandBuffers );

        static ResultValueType<vk::Result> BindBufferMemory2( vk::Device device, uint32_t bindInfoCount,
                                                              const vk::BindBufferMemoryInfo* pBindInfos );

        static ResultValueType<vk::Result> BindImageMemory2( vk::Device device, uint32_t bindInfoCount,
                                                             const vk::BindImageMemoryInfo* pBindInfos );

        static void GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                uint32_t remoteDeviceIndex,
                                                vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures );

        static ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>
        GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                    uint32_t remoteDeviceIndex );

        static void GetImageMemoryRequirements2( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                                 vk::MemoryRequirements2* pMemoryRequirements );

        static void GetBufferMemoryRequirements2( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo,
                                                  vk::MemoryRequirements2* pMemoryRequirements );

        static void GetImageSparseMemoryRequirements2( vk::Device device,
                                                       const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                                                       uint32_t* pSparseMemoryRequirementCount,
                                                       vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements );

        static void TrimCommandPool( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolTrimFlags flags );

        static void GetQueue2( vk::Device device, const vk::DeviceQueueInfo2* pQueueInfo, vk::Queue* pQueue );

        static ResultValueType<vk::Result>
        CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator,
                                      vk::SamplerYcbcrConversion* pYcbcrConversion );

        static ResultValue<vk::Result, vk::SamplerYcbcrConversion>
        CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                   const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate );

        static ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
        CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDescriptorUpdateTemplate( vk::Device device,
                                                     vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDescriptorUpdateTemplate( vk::Device device,
                                                     vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void UpdateDescriptorSetWithTemplate( vk::Device device, vk::DescriptorSet descriptorSet,
                                                     vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                     const void* pData );

        static void GetDescriptorSetLayoutSupport( vk::Device device,
                                                   const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                                   vk::DescriptorSetLayoutSupport* pSupport );

        static ResultValueType<vk::Result> CreateRenderPass2( vk::Device device,
                                                              const vk::RenderPassCreateInfo2* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::RenderPass* pRenderPass );

        static ResultValue<vk::Result, vk::RenderPass>
        CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void ResetQueryPool( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                                    uint32_t queryCount );

        static ResultValueType<vk::Result> GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore,
                                                                     uint64_t* pValue );

        static ResultValue<vk::Result, uint64_t> GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore );

        static ResultValueType<vk::Result> WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo,
                                                           uint64_t timeout );

        static ResultValueType<vk::Result> WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo,
                                                           uint64_t timeout );

        static ResultValueType<vk::Result> SignalSemaphore( vk::Device device,
                                                            const vk::SemaphoreSignalInfo* pSignalInfo );

        static ResultValue<vk::Result, vk::DeviceAddress> GetBufferAddress( vk::Device device,
                                                                            const vk::BufferDeviceAddressInfo* pInfo );

        static ResultValue<vk::Result, uint64_t>
        GetBufferOpaqueCaptureAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo );

        static ResultValue<vk::Result, uint64_t>
        GetMemoryOpaqueCaptureAddress( vk::Device device, const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo );

        static ResultValueType<vk::Result> CreatePrivateDataSlot( vk::Device device,
                                                                  const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                                                  const vk::AllocationCallbacks* pAllocator,
                                                                  vk::PrivateDataSlot* pPrivateDataSlot );

        static ResultValue<vk::Result, vk::PrivateDataSlot>
        CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                            const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> SetPrivateData( vk::Device device, vk::ObjectType objectType_,
                                                           uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot,
                                                           uint64_t data );

        static void GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                    vk::PrivateDataSlot privateDataSlot, uint64_t* pData );

        static ResultValue<vk::Result, uint64_t> GetPrivateData( vk::Device device, vk::ObjectType objectType_,
                                                                 uint64_t objectHandle,
                                                                 vk::PrivateDataSlot privateDataSlot );

        static void GetBufferMemoryRequirements( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo,
                                                 vk::MemoryRequirements2* pMemoryRequirements );

        static void GetImageMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                vk::MemoryRequirements2* pMemoryRequirements );

        static void GetImageSparseMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                      uint32_t* pSparseMemoryRequirementCount,
                                                      vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements );

        static ResultValueType<vk::Result> CreateSwapchainKHR( vk::Device device,
                                                               const vk::SwapchainCreateInfoKHR* pCreateInfo,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::SwapchainKHR* pSwapchain );

        static ResultValue<vk::Result, vk::SwapchainKHR>
        CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                         const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::SwapchainKHR swapchain, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::SwapchainKHR swapchain,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                                  uint32_t* pSwapchainImageCount,
                                                                  vk::Image* pSwapchainImages );

        static ResultValue<vk::Result, std::vector<vk::Image, std::allocator<vk::Image>>>
        GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain );

        static ResultValueType<vk::Result> AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                                uint64_t timeout, vk::Semaphore semaphore,
                                                                vk::Fence fence, uint32_t* pImageIndex );

        static ResultValue<uint32_t> AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                          uint64_t timeout, vk::Semaphore semaphore, vk::Fence fence );

        static ResultValueType<vk::Result>
        GetGroupPresentCapabilitiesKHR( vk::Device device,
                                        vk::DeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities );

        static ResultValue<vk::Result, vk::DeviceGroupPresentCapabilitiesKHR>
        GetGroupPresentCapabilitiesKHR( vk::Device device );

        static ResultValueType<vk::Result> GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface,
                                                                           vk::DeviceGroupPresentModeFlagsKHR* pModes );

        static ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR>
        GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result> AcquireNextImage2KHR( vk::Device device,
                                                                 const vk::AcquireNextImageInfoKHR* pAcquireInfo,
                                                                 uint32_t* pImageIndex );

        static ResultValueType<vk::Result> CreateSharedSwapchainsKHR( vk::Device device, uint32_t swapchainCount,
                                                                      const vk::SwapchainCreateInfoKHR* pCreateInfos,
                                                                      const vk::AllocationCallbacks* pAllocator,
                                                                      vk::SwapchainKHR* pSwapchains );

        static ResultValue<vk::Result, std::vector<vk::SwapchainKHR, std::allocator<vk::SwapchainKHR>>>
        CreateSharedSwapchainsKHR( vk::Device device,
                                   vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::SwapchainKHR>
        CreateSharedSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        DebugMarkerSetObjectTagEXT( vk::Device device, const vk::DebugMarkerObjectTagInfoEXT* pTagInfo );

        static ResultValueType<vk::Result>
        DebugMarkerSetObjectNameEXT( vk::Device device, const vk::DebugMarkerObjectNameInfoEXT* pNameInfo );

        static ResultValueType<vk::Result> CreateVideoSessionKHR( vk::Device device,
                                                                  const vk::VideoSessionCreateInfoKHR* pCreateInfo,
                                                                  const vk::AllocationCallbacks* pAllocator,
                                                                  vk::VideoSessionKHR* pVideoSession );

        static ResultValue<vk::Result, vk::VideoSessionKHR>
        CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                            const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                              uint32_t* pMemoryRequirementsCount,
                                              vk::VideoSessionMemoryRequirementsKHR* pMemoryRequirements );

        static ResultValue<vk::Result, std::vector<vk::VideoSessionMemoryRequirementsKHR,
                                                   std::allocator<vk::VideoSessionMemoryRequirementsKHR>>>
        GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession );

        static ResultValueType<vk::Result>
        BindVideoSessionMemoryKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                   uint32_t bindSessionMemoryInfoCount,
                                   const vk::BindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos );

        static ResultValueType<vk::Result>
        CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::VideoSessionParametersKHR* pVideoSessionParameters );

        static ResultValue<vk::Result, vk::VideoSessionParametersKHR>
        CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR& createInfo,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        UpdateVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                                         const vk::VideoSessionParametersUpdateInfoKHR* pUpdateInfo );

        static void DestroyVideoSessionParametersKHR( vk::Device device,
                                                      vk::VideoSessionParametersKHR videoSessionParameters,
                                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyVideoSessionParametersKHR( vk::Device device,
                                                      vk::VideoSessionParametersKHR videoSessionParameters,
                                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateCuModuleNVX( vk::Device device,
                                                              const vk::CuModuleCreateInfoNVX* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::CuModuleNVX* pModule );

        static ResultValue<vk::Result, vk::CuModuleNVX>
        CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateCuFunctionNVX( vk::Device device,
                                                                const vk::CuFunctionCreateInfoNVX* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::CuFunctionNVX* pFunction );

        static ResultValue<vk::Result, vk::CuFunctionNVX>
        CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX& createInfo,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                        const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::CuModuleNVX module, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::CuModuleNVX module,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                          const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::CuFunctionNVX function, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::CuFunctionNVX function,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, uint32_t> GetImageViewHandleNVX( vk::Device device,
                                                                        const vk::ImageViewHandleInfoNVX* pInfo );

        static ResultValueType<vk::Result> GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView,
                                                                   vk::ImageViewAddressPropertiesNVX* pProperties );

        static ResultValue<vk::Result, vk::ImageViewAddressPropertiesNVX>
        GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView );

        static ResultValueType<vk::Result> GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline,
                                                             vk::ShaderStageFlagBits shaderStage,
                                                             vk::ShaderInfoTypeAMD infoType, size_t* pInfoSize,
                                                             void* pInfo );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage,
                          vk::ShaderInfoTypeAMD infoType );

        static ResultValueType<vk::Result> GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                                                   vk::ExternalMemoryHandleTypeFlagsNV handleType,
                                                                   HANDLE* pHandle );

        static ResultValue<vk::Result, HANDLE> GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                                                       vk::ExternalMemoryHandleTypeFlagsNV handleType );

        static void GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                   uint32_t remoteDeviceIndex,
                                                   vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures );

        static ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>
        GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                       uint32_t remoteDeviceIndex );

        static void TrimCommandPoolKHR( vk::Device device, vk::CommandPool commandPool,
                                        vk::CommandPoolTrimFlags flags );

        static ResultValueType<vk::Result>
        GetMemoryWin32HandleKHR( vk::Device device, const vk::MemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                 HANDLE* pHandle );

        static ResultValueType<vk::Result>
        GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                           HANDLE handle,
                                           vk::MemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties );

        static ResultValue<vk::Result, vk::MemoryWin32HandlePropertiesKHR>
        GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                           HANDLE handle );

        static ResultValueType<vk::Result> GetMemoryFdKHR( vk::Device device, const vk::MemoryGetFdInfoKHR* pGetFdInfo,
                                                           int* pFd );

        static ResultValueType<vk::Result> GetMemoryFdPropertiesKHR( vk::Device device,
                                                                     vk::ExternalMemoryHandleTypeFlagBits handleType,
                                                                     int fd,
                                                                     vk::MemoryFdPropertiesKHR* pMemoryFdProperties );

        static ResultValue<vk::Result, vk::MemoryFdPropertiesKHR>
        GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd );

        static ResultValueType<vk::Result>
        ImportSemaphoreWin32HandleKHR( vk::Device device,
                                       const vk::ImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo );

        static ResultValueType<vk::Result>
        GetSemaphoreWin32HandleKHR( vk::Device device, const vk::SemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                    HANDLE* pHandle );

        static ResultValueType<vk::Result>
        ImportSemaphoreFdKHR( vk::Device device, const vk::ImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo );

        static ResultValueType<vk::Result> GetSemaphoreFdKHR( vk::Device device,
                                                              const vk::SemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd );

        static ResultValueType<vk::Result>
        CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                           const vk::AllocationCallbacks* pAllocator,
                                           vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate );

        static ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
        CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDescriptorUpdateTemplateKHR( vk::Device device,
                                                        vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDescriptorUpdateTemplateKHR( vk::Device device,
                                                        vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void UpdateDescriptorSetWithTemplateKHR( vk::Device device, vk::DescriptorSet descriptorSet,
                                                        vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        const void* pData );

        static ResultValueType<vk::Result> DisplayPowerControlEXT( vk::Device device, vk::DisplayKHR display,
                                                                   const vk::DisplayPowerInfoEXT* pDisplayPowerInfo );

        static ResultValueType<vk::Result> RegisterEventEXT( vk::Device device,
                                                             const vk::DeviceEventInfoEXT* pDeviceEventInfo,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::Fence* pFence );

        static ResultValue<vk::Result, vk::Fence>
        RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT& deviceEventInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display,
                                                                    const vk::DisplayEventInfoEXT* pDisplayEventInfo,
                                                                    const vk::AllocationCallbacks* pAllocator,
                                                                    vk::Fence* pFence );

        static ResultValue<vk::Result, vk::Fence>
        RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display,
                                 const vk::DisplayEventInfoEXT& displayEventInfo,
                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                                                   vk::SurfaceCounterFlagBitsEXT counter,
                                                                   uint64_t* pCounterValue );

        static ResultValue<vk::Result, uint64_t> GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                                                         vk::SurfaceCounterFlagBitsEXT counter );

        static ResultValueType<vk::Result>
        GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                       vk::RefreshCycleDurationGOOGLE* pDisplayTimingProperties );

        static ResultValue<vk::Result, vk::RefreshCycleDurationGOOGLE>
        GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain );

        static ResultValueType<vk::Result>
        GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                         uint32_t* pPresentationTimingCount,
                                         vk::PastPresentationTimingGOOGLE* pPresentationTimings );

        static ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE,
                                                   std::allocator<vk::PastPresentationTimingGOOGLE>>>
        GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain );

        static void SetHdrMetadataEXT( vk::Device device, uint32_t swapchainCount, const vk::SwapchainKHR* pSwapchains,
                                       const vk::HdrMetadataEXT* pMetadata );

        static ResultValueType<vk::Result> CreateRenderPass2KHR( vk::Device device,
                                                                 const vk::RenderPassCreateInfo2* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::RenderPass* pRenderPass );

        static ResultValue<vk::Result, vk::RenderPass>
        CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetSwapchainStatusKHR( vk::Device device, vk::SwapchainKHR swapchain );

        static ResultValueType<vk::Result>
        ImportFenceWin32HandleKHR( vk::Device device,
                                   const vk::ImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo );

        static ResultValueType<vk::Result>
        GetFenceWin32HandleKHR( vk::Device device, const vk::FenceGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                HANDLE* pHandle );

        static ResultValueType<vk::Result> ImportFenceFdKHR( vk::Device device,
                                                             const vk::ImportFenceFdInfoKHR* pImportFenceFdInfo );

        static ResultValueType<vk::Result> GetFenceFdKHR( vk::Device device, const vk::FenceGetFdInfoKHR* pGetFdInfo,
                                                          int* pFd );

        static ResultValueType<vk::Result> AcquireProfilingLockKHR( vk::Device device,
                                                                    const vk::AcquireProfilingLockInfoKHR* pInfo );

        static void ReleaseProfilingLockKHR( vk::Device device );

        static ResultValueType<vk::Result>
        SetDebugUtilsObjectNameEXT( vk::Device device, const vk::DebugUtilsObjectNameInfoEXT* pNameInfo );

        static ResultValueType<vk::Result> SetDebugUtilsObjectTagEXT( vk::Device device,
                                                                      const vk::DebugUtilsObjectTagInfoEXT* pTagInfo );

        static void GetImageMemoryRequirements2KHR( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                                    vk::MemoryRequirements2* pMemoryRequirements );

        static void GetBufferMemoryRequirements2KHR( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo,
                                                     vk::MemoryRequirements2* pMemoryRequirements );

        static void
        GetImageSparseMemoryRequirements2KHR( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                                              uint32_t* pSparseMemoryRequirementCount,
                                              vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements );

        static ResultValueType<vk::Result>
        CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::AccelerationStructureKHR* pAccelerationStructure );

        static ResultValue<vk::Result, vk::AccelerationStructureKHR>
        CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR& createInfo,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyAccelerationStructureKHR( vk::Device device,
                                                     vk::AccelerationStructureKHR accelerationStructure,
                                                     const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyAccelerationStructureKHR( vk::Device device,
                                                     vk::AccelerationStructureKHR accelerationStructure,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        BuildAccelerationStructuresKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                        uint32_t infoCount, const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                        const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos );

        static ResultValueType<vk::Result>
        CopyAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      const vk::CopyAccelerationStructureInfoKHR* pInfo );

        static ResultValueType<vk::Result>
        CopyAccelerationStructureToMemoryKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                              const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo );

        static ResultValueType<vk::Result>
        CopyMemoryToAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                              const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo );

        static ResultValueType<vk::Result>
        WriteAccelerationStructuresPropertiesKHR( vk::Device device, uint32_t accelerationStructureCount,
                                                  const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                  vk::QueryType queryType, size_t dataSize, void* pData,
                                                  size_t stride );

        static ResultValue<vk::Result, vk::DeviceAddress>
        GetAccelerationStructureAddressKHR( vk::Device device,
                                            const vk::AccelerationStructureDeviceAddressInfoKHR* pInfo );

        static void
        GetAccelerationStructureCompatibilityKHR( vk::Device device,
                                                  const vk::AccelerationStructureVersionInfoKHR* pVersionInfo,
                                                  vk::AccelerationStructureCompatibilityKHR* pCompatibility );

        static void
        GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                               const vk::AccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
                                               const uint32_t* pMaxPrimitiveCounts,
                                               vk::AccelerationStructureBuildSizesInfoKHR* pSizeInfo );

        static ResultValue<vk::Result, vk::AccelerationStructureBuildSizesInfoKHR>
        GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                               const vk::AccelerationStructureBuildGeometryInfoKHR& buildInfo,
                                               vk::ArrayProxy<const uint32_t> const& maxPrimitiveCounts );

        static ResultValueType<vk::Result>
        CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                      const vk::RayTracingPipelineCreateInfoKHR* pCreateInfos,
                                      const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines );

        static ResultValue<vk::Result, std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      vk::PipelineCache pipelineCache,
                                      vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::Pipeline>
        CreateRayTracingPipelineKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                     vk::PipelineCache pipelineCache,
                                     const vk::RayTracingPipelineCreateInfoKHR& createInfo,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline,
                                                                               uint32_t firstGroup, uint32_t groupCount,
                                                                               size_t dataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                            uint32_t groupCount, size_t dataSize );

        static ResultValue<vk::Result, uint8_t> GetRayTracingShaderGroupHandleKHR( vk::Device device,
                                                                                   vk::Pipeline pipeline,
                                                                                   uint32_t firstGroup,
                                                                                   uint32_t groupCount );

        static ResultValueType<vk::Result>
        GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                         uint32_t groupCount, size_t dataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                         uint32_t groupCount, size_t dataSize );

        static ResultValue<vk::Result, uint8_t> GetRayTracingCaptureReplayShaderGroupHandleKHR( vk::Device device,
                                                                                                vk::Pipeline pipeline,
                                                                                                uint32_t firstGroup,
                                                                                                uint32_t groupCount );

        static ResultValue<vk::Result, vk::DeviceSize>
        GetRayTracingShaderGroupStackSizeKHR( vk::Device device, vk::Pipeline pipeline, uint32_t group,
                                              vk::ShaderGroupShaderKHR groupShader );

        static ResultValueType<vk::Result>
        CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::SamplerYcbcrConversion* pYcbcrConversion );

        static ResultValue<vk::Result, vk::SamplerYcbcrConversion>
        CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> BindBufferMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                                                                 const vk::BindBufferMemoryInfo* pBindInfos );

        static ResultValueType<vk::Result> BindImageMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                                                                const vk::BindImageMemoryInfo* pBindInfos );

        static ResultValueType<vk::Result>
        GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image,
                                                vk::ImageDrmFormatModifierPropertiesEXT* pProperties );

        static ResultValue<vk::Result, vk::ImageDrmFormatModifierPropertiesEXT>
        GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image );

        static ResultValueType<vk::Result>
        CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT* pCreateInfo,
                                  const vk::AllocationCallbacks* pAllocator, vk::ValidationCacheEXT* pValidationCache );

        static ResultValue<vk::Result, vk::ValidationCacheEXT>
        CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT& createInfo,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                               const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> MergeValidationCachesEXT( vk::Device device, vk::ValidationCacheEXT dstCache,
                                                                     uint32_t srcCacheCount,
                                                                     const vk::ValidationCacheEXT* pSrcCaches );

        static ResultValueType<vk::Result> GetValidationCacheDataEXT( vk::Device device,
                                                                      vk::ValidationCacheEXT validationCache,
                                                                      size_t* pDataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache );

        static ResultValueType<vk::Result>
        CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator,
                                       vk::AccelerationStructureNV* pAccelerationStructure );

        static ResultValue<vk::Result, vk::AccelerationStructureNV>
        CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV& createInfo,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyAccelerationStructureNV( vk::Device device,
                                                    vk::AccelerationStructureNV accelerationStructure,
                                                    const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyAccelerationStructureNV( vk::Device device,
                                                    vk::AccelerationStructureNV accelerationStructure,
                                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void
        GetAccelerationStructureMemoryRequirementsNV( vk::Device device,
                                                      const vk::AccelerationStructureMemoryRequirementsInfoNV* pInfo,
                                                      vk::MemoryRequirements2KHR* pMemoryRequirements );

        static ResultValueType<vk::Result>
        BindAccelerationStructureMemoryNV( vk::Device device, uint32_t bindInfoCount,
                                           const vk::BindAccelerationStructureMemoryInfoNV* pBindInfos );

        static ResultValueType<vk::Result>
        CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                     const vk::RayTracingPipelineCreateInfoNV* pCreateInfos,
                                     const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines );

        static ResultValue<vk::Result,std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache,
                                     vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::Pipeline>
        CreateRayTracingPipelineNV( vk::Device device, vk::PipelineCache pipelineCache,
                                    const vk::RayTracingPipelineCreateInfoNV& createInfo,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline,
                                                                              uint32_t firstGroup, uint32_t groupCount,
                                                                              size_t dataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                           uint32_t groupCount, size_t dataSize );

        static ResultValue<vk::Result, uint8_t> GetRayTracingShaderGroupHandleNV( vk::Device device,
                                                                                  vk::Pipeline pipeline,
                                                                                  uint32_t firstGroup,
                                                                                  uint32_t groupCount );

        static ResultValueType<vk::Result>
        GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                          size_t dataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                          size_t dataSize );

        static ResultValue<vk::Result, uint8_t>
        GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure );

        static ResultValueType<vk::Result> CompileDeferredNV( vk::Device device, vk::Pipeline pipeline,
                                                              uint32_t shader );

        static void GetDescriptorSetLayoutSupportKHR( vk::Device device,
                                                      const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                                      vk::DescriptorSetLayoutSupport* pSupport );

        static ResultValueType<vk::Result>
        GetMemoryHostPointerPropertiesEXT( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                           const void* pHostPointer,
                                           vk::MemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties );

        static ResultValueType<vk::Result>
        GetCalibratedTimestampsEXT( vk::Device device, uint32_t timestampCount,
                                    const vk::CalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps,
                                    uint64_t* pMaxDeviation );

        static ResultValue<vk::Result, std::pair<uint64_t, uint64_t>>
        GetCalibratedTimestampEXT( vk::Device device, const vk::CalibratedTimestampInfoEXT& timestampInfo );

        static ResultValueType<vk::Result> GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore,
                                                                        uint64_t* pValue );

        static ResultValue<vk::Result, uint64_t> GetSemaphoreCounterValueKHR( vk::Device device,
                                                                              vk::Semaphore semaphore );

        static ResultValueType<vk::Result> WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo,
                                                              uint64_t timeout );

        static ResultValueType<vk::Result> WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo,
                                                              uint64_t timeout );

        static ResultValueType<vk::Result> SignalSemaphoreKHR( vk::Device device,
                                                               const vk::SemaphoreSignalInfo* pSignalInfo );

        static ResultValueType<vk::Result>
        InitializePerformanceApiINTEL( vk::Device device,
                                       const vk::InitializePerformanceApiInfoINTEL* pInitializeInfo );

        static void UninitializePerformanceApiINTEL( vk::Device device );

        static ResultValueType<vk::Result>
        AcquirePerformanceConfigurationINTEL( vk::Device device,
                                              const vk::PerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
                                              vk::PerformanceConfigurationINTEL* pConfiguration );

        static ResultValueType<vk::Result>
        ReleasePerformanceConfigurationINTEL( vk::Device device, vk::PerformanceConfigurationINTEL configuration );

        static ResultValueType<vk::Result> Release( vk::Device device,
                                                    vk::PerformanceConfigurationINTEL configuration );

        static ResultValueType<vk::Result> GetPerformanceParameterINTEL( vk::Device device,
                                                                         vk::PerformanceParameterTypeINTEL parameter,
                                                                         vk::PerformanceValueINTEL* pValue );

        static ResultValue<vk::Result, vk::PerformanceValueINTEL>
        GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter );

        static void SetLocalDimmingAMD( vk::Device device, vk::SwapchainKHR swapChain, vk::Bool32 localDimmingEnable );

        static ResultValue<vk::Result, vk::DeviceAddress>
        GetBufferAddressEXT( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo );

        static ResultValueType<vk::Result> WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                              uint64_t presentId, uint64_t timeout );

        static ResultValueType<vk::Result> AcquireFullScreenExclusiveModeEXT( vk::Device device,
                                                                              vk::SwapchainKHR swapchain );

        static ResultValueType<vk::Result> ReleaseFullScreenExclusiveModeEXT( vk::Device device,
                                                                              vk::SwapchainKHR swapchain );

        static ResultValueType<vk::Result>
        GetGroupSurfacePresentModes2EXT( vk::Device device, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                         vk::DeviceGroupPresentModeFlagsKHR* pModes );

        static ResultValue<vk::Result, vk::DeviceAddress>
        GetBufferAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo );

        static ResultValue<vk::Result, uint64_t>
        GetBufferOpaqueCaptureAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo );

        static ResultValue<vk::Result, uint64_t>
        GetMemoryOpaqueCaptureAddressKHR( vk::Device device, const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo );

        static void ResetQueryPoolEXT( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                                       uint32_t queryCount );

        static ResultValueType<vk::Result> CreateDeferredOperationKHR( vk::Device device,
                                                                       const vk::AllocationCallbacks* pAllocator,
                                                                       vk::DeferredOperationKHR* pDeferredOperation );

        static ResultValue<vk::Result, vk::DeferredOperationKHR>
        CreateDeferredOperationKHR( vk::Device device, vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation,
                                                 const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation,
                                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, uint32_t>
        GetDeferredOperationMaxConcurrencyKHR( vk::Device device, vk::DeferredOperationKHR operation );

        static ResultValueType<vk::Result> GetDeferredOperationResultKHR( vk::Device device,
                                                                          vk::DeferredOperationKHR operation );


        static ResultValueType<vk::Result> DeferredOperationJoinKHR( vk::Device device,
                                                                     vk::DeferredOperationKHR operation );

        static ResultValueType<vk::Result>
        GetPipelineExecutablePropertiesKHR( vk::Device device, const vk::PipelineInfoKHR* pPipelineInfo,
                                            uint32_t* pExecutableCount,
                                            vk::PipelineExecutablePropertiesKHR* pProperties );

        static ResultValueType<vk::Result>
        GetPipelineExecutableStatisticsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo,
                                            uint32_t* pStatisticCount,
                                            vk::PipelineExecutableStatisticKHR* pStatistics );

        static ResultValueType<vk::Result> GetPipelineExecutableInternalRepresentationsKHR(
                vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo,
                uint32_t* pInternalRepresentationCount,
                vk::PipelineExecutableInternalRepresentationKHR* pInternalRepresentations );

        static ResultValueType<vk::Result>
        CopyMemoryToImageEXT( vk::Device device, const vk::CopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo );

        static ResultValueType<vk::Result>
        CopyImageToMemoryEXT( vk::Device device, const vk::CopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo );

        static ResultValueType<vk::Result>
        CopyImageToImageEXT( vk::Device device, const vk::CopyImageToImageInfoEXT* pCopyImageToImageInfo );

        static ResultValueType<vk::Result>
        TransitionImageLayoutEXT( vk::Device device, uint32_t transitionCount,
                                  const vk::HostImageLayoutTransitionInfoEXT* pTransitions );

        static void GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image,
                                                   const vk::ImageSubresource2KHR* pSubresource,
                                                   vk::SubresourceLayout2KHR* pLayout );

        static ResultValueType<vk::Result> MapMemory2KHR( vk::Device device, const vk::MemoryMapInfoKHR* pMemoryMapInfo,
                                                          void** ppData );

        static ResultValueType<vk::Result> UnmapMemory2KHR( vk::Device device,
                                                            const vk::MemoryUnmapInfoKHR* pMemoryUnmapInfo );

        static ResultValueType<vk::Result>
        ReleaseSwapchainImagesEXT( vk::Device device, const vk::ReleaseSwapchainImagesInfoEXT* pReleaseInfo );

        static void
        GetGeneratedCommandsMemoryRequirementsNV( vk::Device device,
                                                  const vk::GeneratedCommandsMemoryRequirementsInfoNV* pInfo,
                                                  vk::MemoryRequirements2* pMemoryRequirements );

        static ResultValueType<vk::Result>
        CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::IndirectCommandsLayoutNV* pIndirectCommandsLayout );

        static ResultValue<vk::Result, vk::IndirectCommandsLayoutNV>
        CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV& createInfo,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyIndirectCommandsLayoutNV( vk::Device device,
                                                     vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                                                     const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyIndirectCommandsLayoutNV( vk::Device device,
                                                     vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreatePrivateDataSlotEXT( vk::Device device,
                                                                     const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                                                     const vk::AllocationCallbacks* pAllocator,
                                                                     vk::PrivateDataSlot* pPrivateDataSlot );

        static ResultValue<vk::Result, vk::PrivateDataSlot>
        CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                               const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_,
                                                              uint64_t objectHandle,
                                                              vk::PrivateDataSlot privateDataSlot, uint64_t data );

        static void GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                       vk::PrivateDataSlot privateDataSlot, uint64_t* pData );

        static ResultValue<vk::Result, uint64_t> GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_,
                                                                    uint64_t objectHandle,
                                                                    vk::PrivateDataSlot privateDataSlot );

        static void GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                   vk::DeviceSize* pLayoutSizeInBytes );

        static ResultValue<vk::Result, vk::DeviceSize> GetDescriptorSetLayoutSizeEXT( vk::Device device,
                                                                                      vk::DescriptorSetLayout layout );

        static void GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                            uint32_t binding, vk::DeviceSize* pOffset );

        static ResultValue<vk::Result, vk::DeviceSize>
        GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout, uint32_t binding );

        static void GetDescriptorEXT( vk::Device device, const vk::DescriptorGetInfoEXT* pDescriptorInfo,
                                      size_t dataSize, void* pDescriptor );

        static ResultValueType<vk::Result>
        GetBufferOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::BufferCaptureDescriptorDataInfoEXT* pInfo,
                                                 void* pData );

        static ResultValueType<vk::Result>
        GetImageOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::ImageCaptureDescriptorDataInfoEXT* pInfo,
                                                void* pData );

        static ResultValueType<vk::Result> GetImageViewOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::ImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData );

        static ResultValueType<vk::Result>
        GetSamplerOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                                  const vk::SamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData );

        static ResultValueType<vk::Result> GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::AccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData );

        static ResultValueType<vk::Result> GetFaultInfoEXT( vk::Device device, vk::DeviceFaultCountsEXT* pFaultCounts,
                                                            vk::DeviceFaultInfoEXT* pFaultInfo );

        static ResultValue<vk::Result,std::pair<vk::DeviceFaultCountsEXT, vk::DeviceFaultInfoEXT>>
        GetFaultInfoEXT( vk::Device device );

        static ResultValueType<vk::Result> GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device,
                                                                                    vk::RenderPass renderpass,
                                                                                    vk::Extent2D* pMaxWorkgroupSize );

        static ResultValue<vk::Result, vk::Extent2D>
        GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass );

        static ResultValueType<vk::Result>
        GetMemoryRemoteAddressNV( vk::Device device,
                                  const vk::MemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo,
                                  vk::RemoteAddressNV* pAddress );

        static ResultValueType<vk::Result> GetPipelinePropertiesEXT( vk::Device device,
                                                                     const vk::PipelineInfoEXT* pPipelineInfo,
                                                                     vk::BaseOutStructure* pPipelineProperties );

        static ResultValueType<vk::Result> CreateMicromapEXT( vk::Device device,
                                                              const vk::MicromapCreateInfoEXT* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::MicromapEXT* pMicromap );

        static ResultValue<vk::Result, vk::MicromapEXT>
        CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap,
                                        const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::MicromapEXT micromap, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::MicromapEXT micromap,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> BuildMicromapsEXT( vk::Device device,
                                                              vk::DeferredOperationKHR deferredOperation,
                                                              uint32_t infoCount,
                                                              const vk::MicromapBuildInfoEXT* pInfos );

        static ResultValueType<vk::Result> CopyMicromapEXT( vk::Device device,
                                                            vk::DeferredOperationKHR deferredOperation,
                                                            const vk::CopyMicromapInfoEXT* pInfo );

        static ResultValueType<vk::Result> CopyMicromapToMemoryEXT( vk::Device device,
                                                                    vk::DeferredOperationKHR deferredOperation,
                                                                    const vk::CopyMicromapToMemoryInfoEXT* pInfo );

        static ResultValueType<vk::Result> CopyMemoryToMicromapEXT( vk::Device device,
                                                                    vk::DeferredOperationKHR deferredOperation,
                                                                    const vk::CopyMemoryToMicromapInfoEXT* pInfo );

        static ResultValueType<vk::Result> WriteMicromapsPropertiesEXT( vk::Device device, uint32_t micromapCount,
                                                                        const vk::MicromapEXT* pMicromaps,
                                                                        vk::QueryType queryType, size_t dataSize,
                                                                        void* pData, size_t stride );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        WriteMicromapsPropertiesEXT( vk::Device device, vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                                     vk::QueryType queryType, size_t dataSize, size_t stride );

        static void GetMicromapCompatibilityEXT( vk::Device device, const vk::MicromapVersionInfoEXT* pVersionInfo,
                                                 vk::AccelerationStructureCompatibilityKHR* pCompatibility );

        static void GetMicromapBuildSizesEXT( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                              const vk::MicromapBuildInfoEXT* pBuildInfo,
                                              vk::MicromapBuildSizesInfoEXT* pSizeInfo );

        static void SetMemoryPriorityEXT( vk::Device device, vk::DeviceMemory memory, float priority );

        static void GetBufferMemoryRequirementsKHR( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo,
                                                    vk::MemoryRequirements2* pMemoryRequirements );

        static void GetImageMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                   vk::MemoryRequirements2* pMemoryRequirements );

        static void
        GetImageSparseMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                             uint32_t* pSparseMemoryRequirementCount,
                                             vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements );

        static void
        GetDescriptorSetLayoutHostMappingInfoVALVE( vk::Device device,
                                                    const vk::DescriptorSetBindingReferenceVALVE* pBindingReference,
                                                    vk::DescriptorSetLayoutHostMappingInfoVALVE* pHostMapping );

        static void GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet,
                                                      void** ppData );

        static ResultValue<vk::Result, void*> GetDescriptorSetHostMappingVALVE( vk::Device device,
                                                                                vk::DescriptorSet descriptorSet );

        static void GetPipelineIndirectMemoryRequirementsNV( vk::Device device,
                                                             const vk::ComputePipelineCreateInfo* pCreateInfo,
                                                             vk::MemoryRequirements2* pMemoryRequirements );

        static ResultValue<vk::Result, vk::DeviceAddress>
        GetPipelineIndirectAddressNV( vk::Device device, const vk::PipelineIndirectDeviceAddressInfoNV* pInfo );

        static void GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule,
                                                  vk::ShaderModuleIdentifierEXT* pIdentifier );

        static ResultValue<vk::Result, vk::ShaderModuleIdentifierEXT>
        GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule );

        static void GetShaderModuleCreateInfoIdentifierEXT( vk::Device device,
                                                            const vk::ShaderModuleCreateInfo* pCreateInfo,
                                                            vk::ShaderModuleIdentifierEXT* pIdentifier );

        static ResultValueType<vk::Result>
        CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV* pCreateInfo,
                                    const vk::AllocationCallbacks* pAllocator, vk::OpticalFlowSessionNV* pSession );

        static ResultValue<vk::Result, vk::OpticalFlowSessionNV>
        CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV& createInfo,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                 const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                       vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view,
                                       vk::ImageLayout layout );

        static void GetRenderingAreaGranularityKHR( vk::Device device,
                                                    const vk::RenderingAreaInfoKHR* pRenderingAreaInfo,
                                                    vk::Extent2D* pGranularity );

        static void GetImageSubresourceLayoutKHR( vk::Device device, const vk::DeviceImageSubresourceInfoKHR* pInfo,
                                                  vk::SubresourceLayout2KHR* pLayout );

        static void GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image,
                                                   const vk::ImageSubresource2KHR* pSubresource,
                                                   vk::SubresourceLayout2KHR* pLayout );

        static ResultValueType<vk::Result> CreateShadersEXT( vk::Device device, uint32_t createInfoCount,
                                                             const vk::ShaderCreateInfoEXT* pCreateInfos,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::ShaderEXT* pShaders );

        static ResultValue<vk::Result, std::vector<vk::ShaderEXT, std::allocator<vk::ShaderEXT>>>
        CreateShadersEXT( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValue<vk::Result, vk::ShaderEXT>
        CreateShaderEXT( vk::Device device, const vk::ShaderCreateInfoEXT& createInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader,
                                      const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Device device, vk::ShaderEXT shader, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Device device, vk::ShaderEXT shader,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader,
                                                                   size_t* pDataSize, void* pData );

        static ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader );

        static ResultValueType<vk::Result> GetFramebufferTilePropertiesQCOM( vk::Device device,
                                                                             vk::Framebuffer framebuffer,
                                                                             uint32_t* pPropertiesCount,
                                                                             vk::TilePropertiesQCOM* pProperties );

        static ResultValue<vk::Result, std::vector<vk::TilePropertiesQCOM, std::allocator<vk::TilePropertiesQCOM>>>
        GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer );

        static ResultValueType<vk::Result>
        GetDynamicRenderingTilePropertiesQCOM( vk::Device device, const vk::RenderingInfo* pRenderingInfo,
                                               vk::TilePropertiesQCOM* pProperties );

        static void GetFeatures( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures* pFeatures );

        static ResultValue<vk::Result, vk::PhysicalDeviceFeatures> GetFeatures( vk::PhysicalDevice physicalDevice );

        static void GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format,
                                         vk::FormatProperties* pFormatProperties );

        static ResultValue<vk::Result, vk::FormatProperties> GetFormatProperties( vk::PhysicalDevice physicalDevice,
                                                                                  vk::Format format );

        static ResultValueType<vk::Result>
        GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                  vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags,
                                  vk::ImageFormatProperties* pImageFormatProperties );

        static ResultValue<vk::Result, vk::ImageFormatProperties>
        GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                  vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags );

        static void GetProperties( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties* pProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceProperties> GetProperties( vk::PhysicalDevice physicalDevice );

        static void GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                              vk::QueueFamilyProperties* pQueueFamilyProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::QueueFamilyProperties, std::allocator<vk::QueueFamilyProperties>>>
        GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice );

        static void GetMemoryProperties( vk::PhysicalDevice physicalDevice,
                                         vk::PhysicalDeviceMemoryProperties* pMemoryProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>
        GetMemoryProperties( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> CreateDevice( vk::PhysicalDevice physicalDevice,
                                                         const vk::DeviceCreateInfo* pCreateInfo,
                                                         const vk::AllocationCallbacks* pAllocator,
                                                         vk::Device* pDevice );

        static ResultValue<vk::Result, vk::Device>
        CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo& createInfo,
                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice,
                                                                               const char* pLayerName,
                                                                               uint32_t* pPropertyCount,
                                                                               vk::ExtensionProperties* pProperties );

        static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>>
        EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice,
                                            vk::Optional<const std::string> layerName );

        static ResultValueType<vk::Result> EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice,
                                                                           uint32_t* pPropertyCount,
                                                                           vk::LayerProperties* pProperties );

        static ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>>
        EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice );

        static void GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format,
                                                    vk::ImageType type, vk::SampleCountFlagBits samples,
                                                    vk::ImageUsageFlags usage, vk::ImageTiling tiling,
                                                    uint32_t* pPropertyCount,
                                                    vk::SparseImageFormatProperties* pProperties );

        static ResultValue<vk::Result, std::vector<vk::SparseImageFormatProperties,
                                                   std::allocator<vk::SparseImageFormatProperties>>>
        GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                        vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage,
                                        vk::ImageTiling tiling );

        static void GetFeatures2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures );

        static ResultValue<vk::Result, vk::PhysicalDeviceFeatures2> GetFeatures2( vk::PhysicalDevice physicalDevice );

        static void GetProperties2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceProperties2>
        GetProperties2( vk::PhysicalDevice physicalDevice );

        static void GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format,
                                          vk::FormatProperties2* pFormatProperties );

        static ResultValue<vk::Result, vk::FormatProperties2> GetFormatProperties2( vk::PhysicalDevice physicalDevice,
                                                                                    vk::Format format );

        static ResultValueType<vk::Result>
        GetImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                   const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                   vk::ImageFormatProperties2* pImageFormatProperties );

        static void GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                               vk::QueueFamilyProperties2* pQueueFamilyProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>
        GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice );

        static void GetMemoryProperties2( vk::PhysicalDevice physicalDevice,
                                          vk::PhysicalDeviceMemoryProperties2* pMemoryProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>
        GetMemoryProperties2( vk::PhysicalDevice physicalDevice );

        static void GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                                     const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                     uint32_t* pPropertyCount,
                                                     vk::SparseImageFormatProperties2* pProperties );

        static void GetExternalBufferProperties( vk::PhysicalDevice physicalDevice,
                                                 const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                 vk::ExternalBufferProperties* pExternalBufferProperties );

        static void GetExternalFenceProperties( vk::PhysicalDevice physicalDevice,
                                                const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                vk::ExternalFenceProperties* pExternalFenceProperties );

        static void
        GetExternalSemaphoreProperties( vk::PhysicalDevice physicalDevice,
                                        const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                        vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties );

        static ResultValueType<vk::Result> GetToolProperties( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount,
                                                              vk::PhysicalDeviceToolProperties* pToolProperties );

        static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties,
                                                   std::allocator<vk::PhysicalDeviceToolProperties>>>
        GetToolProperties( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice,
                                                                 uint32_t queueFamilyIndex, vk::SurfaceKHR surface,
                                                                 vk::Bool32* pSupported );

        static ResultValue<vk::Result, vk::Bool32>
        GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result>
        GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                   vk::SurfaceCapabilitiesKHR* pSurfaceCapabilities );

        static ResultValue<vk::Result, vk::SurfaceCapabilitiesKHR>
        GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result> GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice,
                                                                 vk::SurfaceKHR surface, uint32_t* pSurfaceFormatCount,
                                                                 vk::SurfaceFormatKHR* pSurfaceFormats );

        static ResultValue<vk::Result, std::vector<vk::SurfaceFormatKHR, std::allocator<vk::SurfaceFormatKHR>>>
        GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result> GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice,
                                                                      vk::SurfaceKHR surface,
                                                                      uint32_t* pPresentModeCount,
                                                                      vk::PresentModeKHR* pPresentModes );

        static ResultValue<vk::Result, std::vector<vk::PresentModeKHR, std::allocator<vk::PresentModeKHR>>>
        GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result> GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice,
                                                                    vk::SurfaceKHR surface, uint32_t* pRectCount,
                                                                    vk::Rect2D* pRects );

        static ResultValue<vk::Result, std::vector<vk::Rect2D, std::allocator<vk::Rect2D>>>
        GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface );

        static ResultValueType<vk::Result> GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                                    uint32_t* pPropertyCount,
                                                                    vk::DisplayPropertiesKHR* pProperties );

        static ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, std::allocator<vk::DisplayPropertiesKHR>>>
        GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                                         uint32_t* pPropertyCount,
                                                                         vk::DisplayPlanePropertiesKHR* pProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::DisplayPlanePropertiesKHR, std::allocator<vk::DisplayPlanePropertiesKHR>>>
        GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice,
                                                                                uint32_t planeIndex,
                                                                                uint32_t* pDisplayCount,
                                                                                vk::DisplayKHR* pDisplays );

        static ResultValue<vk::Result, std::vector<vk::DisplayKHR, std::allocator<vk::DisplayKHR>>>
        GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex );

        static ResultValueType<vk::Result> GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                                        vk::DisplayKHR display,
                                                                        uint32_t* pPropertyCount,
                                                                        vk::DisplayModePropertiesKHR* pProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::DisplayModePropertiesKHR, std::allocator<vk::DisplayModePropertiesKHR>>>
        GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display );

        static ResultValueType<vk::Result> CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice,
                                                                 vk::DisplayKHR display,
                                                                 const vk::DisplayModeCreateInfoKHR* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::DisplayModeKHR* pMode );

        static ResultValue<vk::Result, vk::DisplayModeKHR>
        CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                              const vk::DisplayModeCreateInfoKHR& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode, uint32_t planeIndex,
                                        vk::DisplayPlaneCapabilitiesKHR* pCapabilities );

        static ResultValue<vk::Result, vk::DisplayPlaneCapabilitiesKHR>
        GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode,
                                        uint32_t planeIndex );

        static ResultValueType<vk::Result> GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice,
                                                                    const vk::VideoProfileInfoKHR* pVideoProfile,
                                                                    vk::VideoCapabilitiesKHR* pCapabilities );

        static ResultValueType<vk::Result> GetVideoFormatPropertiesKHR(
                vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo,
                uint32_t* pVideoFormatPropertyCount, vk::VideoFormatPropertiesKHR* pVideoFormatProperties );

        static ResultValueType<vk::Result>
        GetExternalImageFormatPropertiesNV( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                            vk::ImageTiling tiling, vk::ImageUsageFlags usage,
                                            vk::ImageCreateFlags flags,
                                            vk::ExternalMemoryHandleTypeFlagsNV externalHandleType,
                                            vk::ExternalImageFormatPropertiesNV* pExternalImageFormatProperties );

        static ResultValue<vk::Result, vk::ExternalImageFormatPropertiesNV>
        GetExternalImageFormatPropertiesNV( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                            vk::ImageTiling tiling, vk::ImageUsageFlags usage,
                                            vk::ImageCreateFlags flags,
                                            vk::ExternalMemoryHandleTypeFlagsNV externalHandleType );

        static void GetFeatures2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures );

        static ResultValue<vk::Result, vk::PhysicalDeviceFeatures2>
        GetFeatures2KHR( vk::PhysicalDevice physicalDevice );

        static void GetProperties2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceProperties2>
        GetProperties2KHR( vk::PhysicalDevice physicalDevice );

        static void GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format,
                                             vk::FormatProperties2* pFormatProperties );

        static ResultValue<vk::Result, vk::FormatProperties2>
        GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format );

        static ResultValueType<vk::Result>
        GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                      const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                      vk::ImageFormatProperties2* pImageFormatProperties );

        static void GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                  uint32_t* pQueueFamilyPropertyCount,
                                                  vk::QueueFamilyProperties2* pQueueFamilyProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>
        GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice );

        static void GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice,
                                             vk::PhysicalDeviceMemoryProperties2* pMemoryProperties );

        static ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>
        GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice );

        static void GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                        const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                        uint32_t* pPropertyCount,
                                                        vk::SparseImageFormatProperties2* pProperties );

        static void GetExternalBufferPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                    const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                    vk::ExternalBufferProperties* pExternalBufferProperties );

        static void
        GetExternalSemaphorePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                           const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                           vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties );

        static void ReleaseDisplayEXT( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display );

        static ResultValueType<vk::Result>
        GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                    vk::SurfaceCapabilities2EXT* pSurfaceCapabilities );

        static ResultValue<vk::Result, vk::SurfaceCapabilities2EXT>
        GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface );

        static void GetExternalFencePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                   const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                   vk::ExternalFenceProperties* pExternalFenceProperties );

        static ResultValueType<vk::Result>
        EnumerateQueueFamilyPerformanceQueryCountersKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                         uint32_t* pCounterCount, vk::PerformanceCounterKHR* pCounters,
                                                         vk::PerformanceCounterDescriptionKHR* pCounterDescriptions );

        static void GetQueueFamilyPerformanceQueryPassesKHR(
                vk::PhysicalDevice physicalDevice,
                const vk::QueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo, uint32_t* pNumPasses );

        static ResultValueType<vk::Result>
        GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                    const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                    vk::SurfaceCapabilities2KHR* pSurfaceCapabilities );

        static ResultValueType<vk::Result> GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice,
                                                                  const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                                  uint32_t* pSurfaceFormatCount,
                                                                  vk::SurfaceFormat2KHR* pSurfaceFormats );

        static ResultValueType<vk::Result> GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                                     uint32_t* pPropertyCount,
                                                                     vk::DisplayProperties2KHR* pProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::DisplayProperties2KHR, std::allocator<vk::DisplayProperties2KHR>>>
        GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                                          uint32_t* pPropertyCount,
                                                                          vk::DisplayPlaneProperties2KHR* pProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::DisplayPlaneProperties2KHR, std::allocator<vk::DisplayPlaneProperties2KHR>>>
        GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                                         vk::DisplayKHR display,
                                                                         uint32_t* pPropertyCount,
                                                                         vk::DisplayModeProperties2KHR* pProperties );

        static ResultValue<vk::Result,
                           std::vector<vk::DisplayModeProperties2KHR, std::allocator<vk::DisplayModeProperties2KHR>>>
        GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display );

        static ResultValueType<vk::Result>
        GetDisplayPlaneCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                         const vk::DisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                         vk::DisplayPlaneCapabilities2KHR* pCapabilities );

        static void GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples,
                                                 vk::MultisamplePropertiesEXT* pMultisampleProperties );

        static ResultValue<vk::Result, vk::MultisamplePropertiesEXT>
        GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples );

        static ResultValueType<vk::Result> GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice,
                                                                           uint32_t* pTimeDomainCount,
                                                                           vk::TimeDomainEXT* pTimeDomains );

        static ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, std::allocator<vk::TimeDomainEXT>>>
        GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result>
        GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                    vk::PhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates );

        static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceFragmentShadingRateKHR,
                                                   std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>>>
        GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result> GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice,
                                                                 uint32_t* pToolCount,
                                                                 vk::PhysicalDeviceToolProperties* pToolProperties );

        static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties,
                                                   std::allocator<vk::PhysicalDeviceToolProperties>>>
        GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result>
        GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                          vk::CooperativeMatrixPropertiesNV* pProperties );

        static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV,
                                                   std::allocator<vk::CooperativeMatrixPropertiesNV>>>
        GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result>
        GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice,
                                                           uint32_t* pCombinationCount,
                                                           vk::FramebufferMixedSamplesCombinationNV* pCombinations );

        static ResultValue<vk::Result, std::vector<vk::FramebufferMixedSamplesCombinationNV,
                                                   std::allocator<vk::FramebufferMixedSamplesCombinationNV>>>
        GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice );

        static ResultValueType<vk::Result>
        GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice,
                                    const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount,
                                    vk::PresentModeKHR* pPresentModes );

        static ResultValueType<vk::Result> AcquireDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd,
                                                                 vk::DisplayKHR display );

        static ResultValueType<vk::Result> GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd,
                                                             uint32_t connectorId, vk::DisplayKHR* display );

        static ResultValue<vk::Result, vk::DisplayKHR> GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice,
                                                                         int32_t drmFd, uint32_t connectorId );

        static ResultValueType<vk::Result> AcquireWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                  vk::DisplayKHR display );

        static ResultValueType<vk::Result> GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                              uint32_t deviceRelativeId, vk::DisplayKHR* pDisplay );

        static ResultValue<vk::Result, vk::DisplayKHR> GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                          uint32_t deviceRelativeId );

        static ResultValueType<vk::Result> GetOpticalFlowImageFormatsNV(
                vk::PhysicalDevice physicalDevice, const vk::OpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo,
                uint32_t* pFormatCount, vk::OpticalFlowImageFormatPropertiesNV* pImageFormatProperties );

        static ResultValueType<vk::Result>
        GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                           vk::CooperativeMatrixPropertiesKHR* pProperties );

        static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR,
                                                   std::allocator<vk::CooperativeMatrixPropertiesKHR>>>
        GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice );

        static void Destroy( vk::Instance instance, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Instance instance, vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> EnumeratePhysicalDevices( vk::Instance instance,
                                                                     uint32_t* pPhysicalDeviceCount,
                                                                     vk::PhysicalDevice* pPhysicalDevices );

        static ResultValue<vk::Result, std::vector<vk::PhysicalDevice, std::allocator<vk::PhysicalDevice>>>
        EnumeratePhysicalDevices( vk::Instance instance );

        static ResultValue<vk::Result, PFN_vkVoidFunction> GetProcAddr( vk::Instance instance, const char* pName );

        static ResultValueType<vk::Result>
        EnumeratePhysicalDeviceGroups( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                                       vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties );

        static void DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface,
                                       const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Instance instance, vk::SurfaceKHR surface, const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Instance instance, vk::SurfaceKHR surface,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface );

        static ResultValue<vk::Result, vk::SurfaceKHR>
        CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR& createInfo,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateWin32SurfaceKHR( vk::Instance instance,
                                                                  const vk::Win32SurfaceCreateInfoKHR* pCreateInfo,
                                                                  const vk::AllocationCallbacks* pAllocator,
                                                                  vk::SurfaceKHR* pSurface );

        static ResultValue<vk::Result, vk::SurfaceKHR>
        CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result>
        CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator,
                                      vk::DebugReportCallbackEXT* pCallback );

        static ResultValue<vk::Result, vk::DebugReportCallbackEXT>
        CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT& createInfo,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                                                   const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DebugReportMessageEXT( vk::Instance instance, vk::DebugReportFlagsEXT flags,
                                           vk::DebugReportObjectTypeEXT objectType_, uint64_t object, size_t location,
                                           int32_t messageCode, const char* pLayerPrefix, const char* pMessage );

        static ResultValueType<vk::Result>
        EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                                          vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties );

        static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties,
                                                   std::allocator<vk::PhysicalDeviceGroupProperties>>>
        EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance );

        static ResultValueType<vk::Result>
        CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator,
                                      vk::DebugUtilsMessengerEXT* pMessenger );

        static ResultValue<vk::Result, vk::DebugUtilsMessengerEXT>
        CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT& createInfo,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                                                   const vk::AllocationCallbacks* pAllocator = nullptr);

        static void DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                             const vk::AllocationCallbacks* pAllocator = nullptr);

        static void Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static void SubmitDebugUtilsMessageEXT( vk::Instance instance,
                                                vk::DebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                vk::DebugUtilsMessageTypeFlagsEXT messageTypes,
                                                const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData );

        static ResultValueType<vk::Result>
        CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                  const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface );

        static ResultValue<vk::Result, vk::SurfaceKHR>
        CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT& createInfo,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> CreateInstance( vk::Instance instance,
                                                           const vk::InstanceCreateInfo* pCreateInfo,
                                                           const vk::AllocationCallbacks* pAllocator,
                                                           vk::Instance* pInstance );

        static ResultValue<vk::Result, vk::Instance>
        CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo& createInfo,
                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr );

        static ResultValueType<vk::Result> EnumerateInstanceExtensionProperties( vk::Instance instance,
                                                                                 const char* pLayerName,
                                                                                 uint32_t* pPropertyCount,
                                                                                 vk::ExtensionProperties* pProperties );

        static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>>
        EnumerateInstanceExtensionProperties( vk::Instance instance, vk::Optional<const std::string> layerName );

        static ResultValueType<vk::Result> EnumerateInstanceLayerProperties( vk::Instance instance,
                                                                             uint32_t* pPropertyCount,
                                                                             vk::LayerProperties* pProperties );

        static ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>>
        EnumerateInstanceLayerProperties( vk::Instance instance );

    protected:
        virtual ResultValueType<vk::Result> _Begin( vk::CommandBuffer commandBuffer,
                                                    const vk::CommandBufferBeginInfo* pBeginInfo ) const = 0;

        virtual ResultValueType<vk::Result> _End( vk::CommandBuffer commandBuffer ) const = 0;

        virtual ResultValueType<vk::Result> _Reset( vk::CommandBuffer commandBuffer,
                                                    vk::CommandBufferResetFlags flags ) const = 0;


        virtual void _BindPipeline( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                    vk::Pipeline pipeline ) const = 0;


        virtual void _SetViewport( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                   const vk::Viewport* pViewports ) const = 0;


        virtual void _SetScissor( vk::CommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                                  const vk::Rect2D* pScissors ) const = 0;


        virtual void _SetLineWidth( vk::CommandBuffer commandBuffer, float lineWidth ) const = 0;


        virtual void _SetDepthBias( vk::CommandBuffer commandBuffer, float depthBiasConstantFactor,
                                    float depthBiasClamp, float depthBiasSlopeFactor ) const = 0;


        virtual void _SetBlendConstants( vk::CommandBuffer commandBuffer, const float blendConstants[ 4 ] ) const = 0;


        virtual void _SetDepthBounds( vk::CommandBuffer commandBuffer, float minDepthBounds,
                                      float maxDepthBounds ) const = 0;


        virtual void _SetStencilCompareMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                             uint32_t compareMask ) const = 0;


        virtual void _SetStencilWriteMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                           uint32_t writeMask ) const = 0;


        virtual void _SetStencilReference( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                           uint32_t reference ) const = 0;


        virtual void _BindDescriptorSets( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                          vk::PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                          const vk::DescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                          const uint32_t* pDynamicOffsets ) const = 0;


        virtual void _BindIndexBuffer( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                       vk::IndexType indexType ) const = 0;


        virtual void _BindVertexBuffers( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                         const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets ) const = 0;


        virtual void _Draw( vk::CommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount,
                            uint32_t firstVertex, uint32_t firstInstance ) const = 0;


        virtual void _DrawIndexed( vk::CommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                                   uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance ) const = 0;


        virtual void _DrawIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                    uint32_t drawCount, uint32_t stride ) const = 0;


        virtual void _DrawIndexedIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                           uint32_t drawCount, uint32_t stride ) const = 0;


        virtual void _Dispatch( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                uint32_t groupCountZ ) const = 0;


        virtual void _DispatchIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                        vk::DeviceSize offset ) const = 0;


        virtual void _CopyBuffer( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Buffer dstBuffer,
                                  uint32_t regionCount, const vk::BufferCopy* pRegions ) const = 0;


        virtual void _CopyImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                                 vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                 const vk::ImageCopy* pRegions ) const = 0;


        virtual void _BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                                 vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                 const vk::ImageBlit* pRegions, vk::Filter filter ) const = 0;


        virtual void _BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                                 vk::Image dstImage, vk::ImageLayout dstImageLayout,
                                 vk::ArrayProxy<const vk::ImageBlit> const& regions, vk::Filter filter ) const = 0;


        virtual void _CopyBufferToImage( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Image dstImage,
                                         vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                         const vk::BufferImageCopy* pRegions ) const = 0;


        virtual void _CopyImageToBuffer( vk::CommandBuffer commandBuffer, vk::Image srcImage,
                                         vk::ImageLayout srcImageLayout, vk::Buffer dstBuffer, uint32_t regionCount,
                                         const vk::BufferImageCopy* pRegions ) const = 0;


        virtual void _UpdateBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                    vk::DeviceSize dataSize, const void* pData ) const = 0;


        virtual void _FillBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                  vk::DeviceSize size, uint32_t data ) const = 0;


        virtual void _ClearColorImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                                       const vk::ClearColorValue* pColor, uint32_t rangeCount,
                                       const vk::ImageSubresourceRange* pRanges ) const = 0;


        virtual void _ClearDepthStencilImage( vk::CommandBuffer commandBuffer, vk::Image image,
                                              vk::ImageLayout imageLayout,
                                              const vk::ClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                              const vk::ImageSubresourceRange* pRanges ) const = 0;


        virtual void _ClearAttachments( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                                        const vk::ClearAttachment* pAttachments, uint32_t rectCount,
                                        const vk::ClearRect* pRects ) const = 0;


        virtual void _ResolveImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                                    vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                                    const vk::ImageResolve* pRegions ) const = 0;


        virtual void _SetEvent( vk::CommandBuffer commandBuffer, vk::Event event,
                                vk::PipelineStageFlags stageMask ) const = 0;


        virtual void _ResetEvent( vk::CommandBuffer commandBuffer, vk::Event event,
                                  vk::PipelineStageFlags stageMask ) const = 0;


        virtual void _WaitEvents( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                  vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask,
                                  uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                                  uint32_t bufferMemoryBarrierCount,
                                  const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                                  uint32_t imageMemoryBarrierCount,
                                  const vk::ImageMemoryBarrier* pImageMemoryBarriers ) const = 0;


        virtual void _PipelineBarrier( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags srcStageMask,
                                       vk::PipelineStageFlags dstStageMask, vk::DependencyFlags dependencyFlags,
                                       uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                                       uint32_t bufferMemoryBarrierCount,
                                       const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                                       uint32_t imageMemoryBarrierCount,
                                       const vk::ImageMemoryBarrier* pImageMemoryBarriers ) const = 0;


        virtual void _BeginQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                  vk::QueryControlFlags flags ) const = 0;


        virtual void _EndQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query ) const = 0;


        virtual void _ResetQueryPool( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery,
                                      uint32_t queryCount ) const = 0;


        virtual void _WriteTimestamp( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                                      vk::QueryPool queryPool, uint32_t query ) const = 0;


        virtual void _CopyQueryPoolResults( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool,
                                            uint32_t firstQuery, uint32_t queryCount, vk::Buffer dstBuffer,
                                            vk::DeviceSize dstOffset, vk::DeviceSize stride,
                                            vk::QueryResultFlags flags ) const = 0;


        virtual void _PushConstants( vk::CommandBuffer commandBuffer, vk::PipelineLayout layout,
                                     vk::ShaderStageFlags stageFlags, uint32_t offset, uint32_t size,
                                     const void* pValues ) const = 0;


        virtual void _BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                                       vk::SubpassContents contents ) const = 0;


        virtual void _BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo& renderPassBegin,
                                       vk::SubpassContents contents ) const = 0;


        virtual void _NextSubpass( vk::CommandBuffer commandBuffer, vk::SubpassContents contents ) const = 0;


        virtual void _EndRenderPass( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _ExecuteCommands( vk::CommandBuffer commandBuffer, uint32_t commandBufferCount,
                                       const vk::CommandBuffer* pCommandBuffers ) const = 0;


        virtual void _SetDeviceMask( vk::CommandBuffer commandBuffer, uint32_t deviceMask ) const = 0;


        virtual void _DispatchBase( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                    uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                    uint32_t groupCountZ ) const = 0;


        virtual void _DrawIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                         vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                         uint32_t maxDrawCount, uint32_t stride ) const = 0;


        virtual void _DrawIndexedIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                vk::DeviceSize offset, vk::Buffer countBuffer,
                                                vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                uint32_t stride ) const = 0;


        virtual void _BeginRenderPass2( vk::CommandBuffer commandBuffer,
                                        const vk::RenderPassBeginInfo* pRenderPassBegin,
                                        const vk::SubpassBeginInfo* pSubpassBeginInfo ) const = 0;


        virtual void _NextSubpass2( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                                    const vk::SubpassEndInfo* pSubpassEndInfo ) const = 0;


        virtual void _EndRenderPass2( vk::CommandBuffer commandBuffer,
                                      const vk::SubpassEndInfo* pSubpassEndInfo ) const = 0;


        virtual void _SetEvent2( vk::CommandBuffer commandBuffer, vk::Event event,
                                 const vk::DependencyInfo* pDependencyInfo ) const = 0;


        virtual void _ResetEvent2( vk::CommandBuffer commandBuffer, vk::Event event,
                                   vk::PipelineStageFlags2 stageMask ) const = 0;


        virtual void _WaitEvents2( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                   const vk::DependencyInfo* pDependencyInfos ) const = 0;


        virtual void _PipelineBarrier2( vk::CommandBuffer commandBuffer,
                                        const vk::DependencyInfo* pDependencyInfo ) const = 0;


        virtual void _WriteTimestamp2( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                       vk::QueryPool queryPool, uint32_t query ) const = 0;


        virtual void _CopyBuffer2( vk::CommandBuffer commandBuffer,
                                   const vk::CopyBufferInfo2* pCopyBufferInfo ) const = 0;


        virtual void _CopyImage2( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo ) const = 0;


        virtual void _CopyBufferToImage2( vk::CommandBuffer commandBuffer,
                                          const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo ) const = 0;


        virtual void _CopyImageToBuffer2( vk::CommandBuffer commandBuffer,
                                          const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo ) const = 0;


        virtual void _BlitImage2( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo ) const = 0;


        virtual void _ResolveImage2( vk::CommandBuffer commandBuffer,
                                     const vk::ResolveImageInfo2* pResolveImageInfo ) const = 0;


        virtual void _BeginRendering( vk::CommandBuffer commandBuffer,
                                      const vk::RenderingInfo* pRenderingInfo ) const = 0;


        virtual void _EndRendering( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _SetCullMode( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode ) const = 0;


        virtual void _SetFrontFace( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace ) const = 0;


        virtual void _SetPrimitiveTopology( vk::CommandBuffer commandBuffer,
                                            vk::PrimitiveTopology primitiveTopology ) const = 0;


        virtual void _SetViewportWithCount( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                            const vk::Viewport* pViewports ) const = 0;


        virtual void _SetScissorWithCount( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                           const vk::Rect2D* pScissors ) const = 0;


        virtual void _BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                          const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets,
                                          const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides ) const = 0;


        virtual void _BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                          vk::ArrayProxy<const vk::Buffer> const& buffers,
                                          vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                          vk::ArrayProxy<const vk::DeviceSize> const& sizes,
                                          vk::ArrayProxy<const vk::DeviceSize> const& strides ) const = 0;


        virtual void _SetDepthTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable ) const = 0;


        virtual void _SetDepthWriteEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable ) const = 0;


        virtual void _SetDepthCompareOp( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp ) const = 0;


        virtual void _SetDepthBoundsTestEnable( vk::CommandBuffer commandBuffer,
                                                vk::Bool32 depthBoundsTestEnable ) const = 0;


        virtual void _SetStencilTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable ) const = 0;


        virtual void _SetStencilOp( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                    vk::StencilOp failOp, vk::StencilOp passOp, vk::StencilOp depthFailOp,
                                    vk::CompareOp compareOp ) const = 0;


        virtual void _SetRasterizerDiscardEnable( vk::CommandBuffer commandBuffer,
                                                  vk::Bool32 rasterizerDiscardEnable ) const = 0;


        virtual void _SetDepthBiasEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable ) const = 0;


        virtual void _SetPrimitiveRestartEnable( vk::CommandBuffer commandBuffer,
                                                 vk::Bool32 primitiveRestartEnable ) const = 0;


        virtual void _DebugMarkerBeginEXT( vk::CommandBuffer commandBuffer,
                                           const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo ) const = 0;


        virtual void _DebugMarkerEndEXT( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _DebugMarkerInsertEXT( vk::CommandBuffer commandBuffer,
                                            const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo ) const = 0;


        virtual void _BeginVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                           const vk::VideoBeginCodingInfoKHR* pBeginInfo ) const = 0;


        virtual void _EndVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                         const vk::VideoEndCodingInfoKHR* pEndCodingInfo ) const = 0;


        virtual void _ControlVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                             const vk::VideoCodingControlInfoKHR* pCodingControlInfo ) const = 0;


        virtual void _DecodeVideoKHR( vk::CommandBuffer commandBuffer,
                                      const vk::VideoDecodeInfoKHR* pDecodeInfo ) const = 0;


        virtual void _BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                                       uint32_t bindingCount, const vk::Buffer* pBuffers,
                                                       const vk::DeviceSize* pOffsets,
                                                       const vk::DeviceSize* pSizes ) const = 0;


        virtual void _BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                                       vk::ArrayProxy<const vk::Buffer> const& buffers,
                                                       vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                                       vk::ArrayProxy<const vk::DeviceSize> const& sizes ) = 0;


        virtual void _BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                 uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                                 const vk::DeviceSize* pCounterBufferOffsets ) const = 0;


        virtual void _BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                                 vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                                 vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets ) = 0;


        virtual void _EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                               uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                               const vk::DeviceSize* pCounterBufferOffsets ) const = 0;


        virtual void _EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                               vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                               vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets ) = 0;


        virtual void _BeginQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                            vk::QueryControlFlags flags, uint32_t index ) const = 0;


        virtual void _EndQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                          uint32_t index ) const = 0;


        virtual void _DrawIndirectByteCountEXT( vk::CommandBuffer commandBuffer, uint32_t instanceCount,
                                                uint32_t firstInstance, vk::Buffer counterBuffer,
                                                vk::DeviceSize counterBufferOffset, uint32_t counterOffset,
                                                uint32_t vertexStride ) const = 0;


        virtual void _CuLaunchKernelNVX( vk::CommandBuffer commandBuffer,
                                         const vk::CuLaunchInfoNVX* pLaunchInfo ) const = 0;


        virtual void _DrawIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                            vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                            uint32_t maxDrawCount, uint32_t stride ) const = 0;


        virtual void _DrawIndexedIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                   vk::DeviceSize offset, vk::Buffer countBuffer,
                                                   vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                   uint32_t stride ) const = 0;


        virtual void _BeginRenderingKHR( vk::CommandBuffer commandBuffer,
                                         const vk::RenderingInfo* pRenderingInfo ) const = 0;


        virtual void _EndRenderingKHR( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _SetDeviceMaskKHR( vk::CommandBuffer commandBuffer, uint32_t deviceMask ) const = 0;


        virtual void _DispatchBaseKHR( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                                       uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                                       uint32_t groupCountZ ) const = 0;


        virtual void _PushDescriptorSetKHR( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                            vk::PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                            const vk::WriteDescriptorSet* pDescriptorWrites ) const = 0;


        virtual void _PushDescriptorSetWithTemplateKHR( vk::CommandBuffer commandBuffer,
                                                        vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                        vk::PipelineLayout layout, uint32_t set,
                                                        const void* pData ) const = 0;


        virtual void _BeginConditionalRenderingEXT(
                vk::CommandBuffer commandBuffer,
                const vk::ConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin ) const = 0;


        virtual void _EndConditionalRenderingEXT( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _SetViewportWScalingNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                             uint32_t viewportCount,
                                             const vk::ViewportWScalingNV* pViewportWScalings ) const = 0;


        virtual void _SetDiscardRectangleEXT( vk::CommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                              uint32_t discardRectangleCount,
                                              const vk::Rect2D* pDiscardRectangles ) const = 0;


        virtual void _SetDiscardRectangleEnableEXT( vk::CommandBuffer commandBuffer,
                                                    vk::Bool32 discardRectangleEnable ) const = 0;


        virtual void _SetDiscardRectangleModeEXT( vk::CommandBuffer commandBuffer,
                                                  vk::DiscardRectangleModeEXT discardRectangleMode ) const = 0;


        virtual void _BeginRenderPass2KHR( vk::CommandBuffer commandBuffer,
                                           const vk::RenderPassBeginInfo* pRenderPassBegin,
                                           const vk::SubpassBeginInfo* pSubpassBeginInfo ) const = 0;


        virtual void _NextSubpass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                                       const vk::SubpassEndInfo* pSubpassEndInfo ) const = 0;


        virtual void _EndRenderPass2KHR( vk::CommandBuffer commandBuffer,
                                         const vk::SubpassEndInfo* pSubpassEndInfo ) const = 0;


        virtual void _BeginDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer,
                                               const vk::DebugUtilsLabelEXT* pLabelInfo ) const = 0;


        virtual void _EndDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _InsertDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer,
                                                const vk::DebugUtilsLabelEXT* pLabelInfo ) const = 0;


        virtual void _SetSampleLocationsEXT( vk::CommandBuffer commandBuffer,
                                             const vk::SampleLocationsInfoEXT* pSampleLocationsInfo ) const = 0;


        virtual void _BuildAccelerationStructuresKHR(
                vk::CommandBuffer commandBuffer, uint32_t infoCount,
                const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos ) const = 0;


        virtual void
        _BuildAccelerationStructuresIndirectKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                                 const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                 const vk::DeviceAddress* pIndirectDeviceAddresses,
                                                 const uint32_t* pIndirectStrides,
                                                 const uint32_t* const* ppMaxPrimitiveCounts ) const = 0;


        virtual void _CopyAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                                    const vk::CopyAccelerationStructureInfoKHR* pInfo ) const = 0;


        virtual void
        _CopyAccelerationStructureToMemoryKHR( vk::CommandBuffer commandBuffer,
                                               const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo ) const = 0;


        virtual void
        _CopyMemoryToAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                               const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo ) const = 0;


        virtual void
        _WriteAccelerationStructuresPropertiesKHR( vk::CommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                   const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                   vk::QueryType queryType, vk::QueryPool queryPool,
                                                   uint32_t firstQuery ) const = 0;


        virtual void _WriteAccelerationStructuresPropertiesKHR(
                vk::CommandBuffer commandBuffer,
                vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
                vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery ) const = 0;


        virtual void _TraceRaysKHR( vk::CommandBuffer commandBuffer,
                                    const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                    uint32_t width, uint32_t height, uint32_t depth ) const = 0;


        virtual void _TraceRaysKHR( vk::CommandBuffer commandBuffer,
                                    const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                                    const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable, uint32_t width,
                                    uint32_t height, uint32_t depth ) const = 0;


        virtual void _TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                            const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                            vk::DeviceAddress indirectDeviceAddress ) const = 0;


        virtual void _TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                            const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                                            const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable,
                                            vk::DeviceAddress indirectDeviceAddress ) const = 0;


        virtual void _SetRayTracingPipelineStackSizeKHR( vk::CommandBuffer commandBuffer,
                                                         uint32_t pipelineStackSize ) const = 0;


        virtual void _BindShadingRateImageNV( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                              vk::ImageLayout imageLayout ) const = 0;


        virtual void _SetViewportShadingRatePaletteNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                                       uint32_t viewportCount,
                                                       const vk::ShadingRatePaletteNV* pShadingRatePalettes ) const = 0;


        virtual void _SetCoarseSampleOrderNV( vk::CommandBuffer commandBuffer,
                                              vk::CoarseSampleOrderTypeNV sampleOrderType,
                                              uint32_t customSampleOrderCount,
                                              const vk::CoarseSampleOrderCustomNV* pCustomSampleOrders ) const = 0;


        virtual void _BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer,
                                                    const vk::AccelerationStructureInfoNV* pInfo,
                                                    vk::Buffer instanceData, vk::DeviceSize instanceOffset,
                                                    vk::Bool32 update, vk::AccelerationStructureNV dst,
                                                    vk::AccelerationStructureNV src, vk::Buffer scratch,
                                                    vk::DeviceSize scratchOffset ) const = 0;


        virtual void _BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer,
                                                    const vk::AccelerationStructureInfoNV& info,
                                                    vk::Buffer instanceData, vk::DeviceSize instanceOffset,
                                                    vk::Bool32 update, vk::AccelerationStructureNV dst,
                                                    vk::AccelerationStructureNV src, vk::Buffer scratch,
                                                    vk::DeviceSize scratchOffset ) const = 0;


        virtual void _CopyAccelerationStructureNV( vk::CommandBuffer commandBuffer, vk::AccelerationStructureNV dst,
                                                   vk::AccelerationStructureNV src,
                                                   vk::CopyAccelerationStructureModeKHR mode ) const = 0;


        virtual void _TraceRaysNV( vk::CommandBuffer commandBuffer, vk::Buffer raygenShaderBindingTableBuffer,
                                   vk::DeviceSize raygenShaderBindingOffset, vk::Buffer missShaderBindingTableBuffer,
                                   vk::DeviceSize missShaderBindingOffset, vk::DeviceSize missShaderBindingStride,
                                   vk::Buffer hitShaderBindingTableBuffer, vk::DeviceSize hitShaderBindingOffset,
                                   vk::DeviceSize hitShaderBindingStride, vk::Buffer callableShaderBindingTableBuffer,
                                   vk::DeviceSize callableShaderBindingOffset,
                                   vk::DeviceSize callableShaderBindingStride, uint32_t width, uint32_t height,
                                   uint32_t depth ) const = 0;


        virtual void
        _WriteAccelerationStructuresPropertiesNV( vk::CommandBuffer commandBuffer, uint32_t accelerationStructureCount,
                                                  const vk::AccelerationStructureNV* pAccelerationStructures,
                                                  vk::QueryType queryType, vk::QueryPool queryPool,
                                                  uint32_t firstQuery ) const = 0;


        virtual void _WriteAccelerationStructuresPropertiesNV(
                vk::CommandBuffer commandBuffer,
                vk::ArrayProxy<const vk::AccelerationStructureNV> const& accelerationStructures,
                vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery ) const = 0;


        virtual void _DrawIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                            vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                            uint32_t maxDrawCount, uint32_t stride ) const = 0;


        virtual void _DrawIndexedIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                   vk::DeviceSize offset, vk::Buffer countBuffer,
                                                   vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                   uint32_t stride ) const = 0;


        virtual void _WriteBufferMarkerAMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                                            vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker ) const = 0;


        virtual void _DrawMeshTasksNV( vk::CommandBuffer commandBuffer, uint32_t taskCount,
                                       uint32_t firstTask ) const = 0;


        virtual void _DrawMeshTasksIndirectNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                               vk::DeviceSize offset, uint32_t drawCount, uint32_t stride ) const = 0;


        virtual void _DrawMeshTasksIndirectCountNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                    vk::DeviceSize offset, vk::Buffer countBuffer,
                                                    vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                    uint32_t stride ) const = 0;


        virtual void _SetExclusiveScissorEnableNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                                   uint32_t exclusiveScissorCount,
                                                   const vk::Bool32* pExclusiveScissorEnables ) const = 0;


        virtual void _SetExclusiveScissorNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                             uint32_t exclusiveScissorCount,
                                             const vk::Rect2D* pExclusiveScissors ) const = 0;


        virtual void _SetCheckpointNV( vk::CommandBuffer commandBuffer, const void* pCheckpointMarker ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetPerformanceMarkerINTEL( vk::CommandBuffer commandBuffer,
                                    const vk::PerformanceMarkerInfoINTEL* pMarkerInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetPerformanceStreamMarkerINTEL( vk::CommandBuffer commandBuffer,
                                          const vk::PerformanceStreamMarkerInfoINTEL* pMarkerInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetPerformanceOverrideINTEL( vk::CommandBuffer commandBuffer,
                                      const vk::PerformanceOverrideInfoINTEL* pOverrideInfo ) const = 0;


        virtual void
        _SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D* pFragmentSize,
                                    const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const = 0;


        virtual void
        _SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D& fragmentSize,
                                    const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const = 0;


        virtual void _SetLineStippleEXT( vk::CommandBuffer commandBuffer, uint32_t lineStippleFactor,
                                         uint16_t lineStipplePattern ) const = 0;


        virtual void _SetCullModeEXT( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode ) const = 0;


        virtual void _SetFrontFaceEXT( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace ) const = 0;


        virtual void _SetPrimitiveTopologyEXT( vk::CommandBuffer commandBuffer,
                                               vk::PrimitiveTopology primitiveTopology ) const = 0;


        virtual void _SetViewportWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                               const vk::Viewport* pViewports ) const = 0;


        virtual void _SetScissorWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                              const vk::Rect2D* pScissors ) const = 0;


        virtual void _BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const vk::Buffer* pBuffers,
                                             const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes,
                                             const vk::DeviceSize* pStrides ) const = 0;


        virtual void _BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                             vk::ArrayProxy<const vk::Buffer> const& buffers,
                                             vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                             vk::ArrayProxy<const vk::DeviceSize> const& sizes,
                                             vk::ArrayProxy<const vk::DeviceSize> const& strides ) const = 0;


        virtual void _SetDepthTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable ) const = 0;


        virtual void _SetDepthWriteEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable ) const = 0;


        virtual void _SetDepthCompareOpEXT( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp ) const = 0;


        virtual void _SetDepthBoundsTestEnableEXT( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 depthBoundsTestEnable ) const = 0;


        virtual void _SetStencilTestEnableEXT( vk::CommandBuffer commandBuffer,
                                               vk::Bool32 stencilTestEnable ) const = 0;


        virtual void _SetStencilOpEXT( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                       vk::StencilOp failOp, vk::StencilOp passOp, vk::StencilOp depthFailOp,
                                       vk::CompareOp compareOp ) const = 0;


        virtual void
        _PreprocessGeneratedCommandsNV( vk::CommandBuffer commandBuffer,
                                        const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo ) const = 0;


        virtual void _ExecuteGeneratedCommandsNV( vk::CommandBuffer commandBuffer, vk::Bool32 isPreprocessed,
                                                  const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo ) const = 0;


        virtual void _BindPipelineShaderGroupNV( vk::CommandBuffer commandBuffer,
                                                 vk::PipelineBindPoint pipelineBindPoint, vk::Pipeline pipeline,
                                                 uint32_t groupIndex ) const = 0;


        virtual void _SetDepthBias2EXT( vk::CommandBuffer commandBuffer,
                                        const vk::DepthBiasInfoEXT* pDepthBiasInfo ) const = 0;


        virtual void _SetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                                    const vk::DependencyInfo* pDependencyInfo ) const = 0;


        virtual void _ResetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                                      vk::PipelineStageFlags2 stageMask ) const = 0;


        virtual void _WaitEvents2KHR( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                                      const vk::DependencyInfo* pDependencyInfos ) const = 0;


        virtual void _PipelineBarrier2KHR( vk::CommandBuffer commandBuffer,
                                           const vk::DependencyInfo* pDependencyInfo ) const = 0;


        virtual void _WriteTimestamp2KHR( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                          vk::QueryPool queryPool, uint32_t query ) const = 0;


        virtual void _WriteBufferMarker2AMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage,
                                             vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                             uint32_t marker ) const = 0;


        virtual void _BindDescriptorBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t bufferCount,
                                                const vk::DescriptorBufferBindingInfoEXT* pBindingInfos ) const = 0;


        virtual void _SetDescriptorBufferOffsetsEXT( vk::CommandBuffer commandBuffer,
                                                     vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout,
                                                     uint32_t firstSet, uint32_t setCount,
                                                     const uint32_t* pBufferIndices,
                                                     const vk::DeviceSize* pOffsets ) const = 0;


        virtual void _BindDescriptorBufferEmbeddedSamplersEXT( vk::CommandBuffer commandBuffer,
                                                               vk::PipelineBindPoint pipelineBindPoint,
                                                               vk::PipelineLayout layout, uint32_t set ) const = 0;


        virtual void
        _SetFragmentShadingRateEnumNV( vk::CommandBuffer commandBuffer, vk::FragmentShadingRateNV shadingRate,
                                       const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const = 0;


        virtual void _DrawMeshTasksEXT( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                        uint32_t groupCountZ ) const = 0;


        virtual void _DrawMeshTasksIndirectEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                vk::DeviceSize offset, uint32_t drawCount, uint32_t stride ) const = 0;


        virtual void _DrawMeshTasksIndirectCountEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                     vk::DeviceSize offset, vk::Buffer countBuffer,
                                                     vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                                     uint32_t stride ) const = 0;


        virtual void _CopyBuffer2KHR( vk::CommandBuffer commandBuffer,
                                      const vk::CopyBufferInfo2* pCopyBufferInfo ) const = 0;


        virtual void _CopyImage2KHR( vk::CommandBuffer commandBuffer,
                                     const vk::CopyImageInfo2* pCopyImageInfo ) const = 0;


        virtual void _CopyBufferToImage2KHR( vk::CommandBuffer commandBuffer,
                                             const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo ) const = 0;


        virtual void _CopyImageToBuffer2KHR( vk::CommandBuffer commandBuffer,
                                             const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo ) const = 0;


        virtual void _BlitImage2KHR( vk::CommandBuffer commandBuffer,
                                     const vk::BlitImageInfo2* pBlitImageInfo ) const = 0;


        virtual void _ResolveImage2KHR( vk::CommandBuffer commandBuffer,
                                        const vk::ResolveImageInfo2* pResolveImageInfo ) const = 0;


        virtual void
        _SetVertexInputEXT( vk::CommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                            const vk::VertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                            uint32_t vertexAttributeDescriptionCount,
                            const vk::VertexInputAttributeDescription2EXT* pVertexAttributeDescriptions ) const = 0;


        virtual void _SubpassShadingHUAWEI( vk::CommandBuffer commandBuffer ) const = 0;


        virtual void _BindInvocationMaskHUAWEI( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                                vk::ImageLayout imageLayout ) const = 0;


        virtual void _SetPatchControlPointsEXT( vk::CommandBuffer commandBuffer,
                                                uint32_t patchControlPoints ) const = 0;


        virtual void _SetRasterizerDiscardEnableEXT( vk::CommandBuffer commandBuffer,
                                                     vk::Bool32 rasterizerDiscardEnable ) const = 0;


        virtual void _SetDepthBiasEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable ) const = 0;


        virtual void _SetLogicOpEXT( vk::CommandBuffer commandBuffer, vk::LogicOp logicOp ) const = 0;


        virtual void _SetPrimitiveRestartEnableEXT( vk::CommandBuffer commandBuffer,
                                                    vk::Bool32 primitiveRestartEnable ) const = 0;


        virtual void _SetColorWriteEnableEXT( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                                              const vk::Bool32* pColorWriteEnables ) const = 0;


        virtual void _TraceRaysIndirect2KHR( vk::CommandBuffer commandBuffer,
                                             vk::DeviceAddress indirectDeviceAddress ) const = 0;


        virtual void _DrawMultiEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount,
                                    const vk::MultiDrawInfoEXT* pVertexInfo, uint32_t instanceCount,
                                    uint32_t firstInstance, uint32_t stride ) const = 0;


        virtual void _DrawMultiEXT( vk::CommandBuffer commandBuffer,
                                    vk::StridedArrayProxy<const vk::MultiDrawInfoEXT> const& vertexInfo,
                                    uint32_t instanceCount, uint32_t firstInstance ) const = 0;


        virtual void _DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount,
                                           const vk::MultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                           uint32_t firstInstance, uint32_t stride,
                                           const int32_t* pVertexOffset ) const = 0;


        virtual void _DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer,
                                           vk::StridedArrayProxy<const vk::MultiDrawIndexedInfoEXT> const& indexInfo,
                                           uint32_t instanceCount, uint32_t firstInstance,
                                           vk::Optional<const int32_t> vertexOffset ) const = 0;


        virtual void _BuildMicromapsEXT( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                         const vk::MicromapBuildInfoEXT* pInfos ) const = 0;


        virtual void _CopyMicromapEXT( vk::CommandBuffer commandBuffer,
                                       const vk::CopyMicromapInfoEXT* pInfo ) const = 0;


        virtual void _CopyMicromapToMemoryEXT( vk::CommandBuffer commandBuffer,
                                               const vk::CopyMicromapToMemoryInfoEXT* pInfo ) const = 0;


        virtual void _CopyMemoryToMicromapEXT( vk::CommandBuffer commandBuffer,
                                               const vk::CopyMemoryToMicromapInfoEXT* pInfo ) const = 0;


        virtual void _WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer, uint32_t micromapCount,
                                                   const vk::MicromapEXT* pMicromaps, vk::QueryType queryType,
                                                   vk::QueryPool queryPool, uint32_t firstQuery ) const = 0;


        virtual void _WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer,
                                                   vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                                                   vk::QueryType queryType, vk::QueryPool queryPool,
                                                   uint32_t firstQuery ) const = 0;


        virtual void _DrawClusterHUAWEI( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                                         uint32_t groupCountZ ) const = 0;


        virtual void _DrawClusterIndirectHUAWEI( vk::CommandBuffer commandBuffer, vk::Buffer buffer,
                                                 vk::DeviceSize offset ) const = 0;


        virtual void _CopyMemoryIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                            uint32_t copyCount, uint32_t stride ) const = 0;


        virtual void _CopyMemoryToImageIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                                   uint32_t copyCount, uint32_t stride, vk::Image dstImage,
                                                   vk::ImageLayout dstImageLayout,
                                                   const vk::ImageSubresourceLayers* pImageSubresources ) const = 0;


        virtual void _DecompressMemoryNV( vk::CommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                          const vk::DecompressMemoryRegionNV* pDecompressMemoryRegions ) const = 0;


        virtual void _DecompressMemoryIndirectCountNV( vk::CommandBuffer commandBuffer,
                                                       vk::DeviceAddress indirectCommandsAddress,
                                                       vk::DeviceAddress indirectCommandsCountAddress,
                                                       uint32_t stride ) const = 0;


        virtual void _UpdatePipelineIndirectBufferNV( vk::CommandBuffer commandBuffer,
                                                      vk::PipelineBindPoint pipelineBindPoint,
                                                      vk::Pipeline pipeline ) const = 0;


        virtual void _SetTessellationDomainOriginEXT( vk::CommandBuffer commandBuffer,
                                                      vk::TessellationDomainOrigin domainOrigin ) const = 0;


        virtual void _SetDepthClampEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClampEnable ) const = 0;


        virtual void _SetPolygonModeEXT( vk::CommandBuffer commandBuffer, vk::PolygonMode polygonMode ) const = 0;


        virtual void _SetRasterizationSamplesEXT( vk::CommandBuffer commandBuffer,
                                                  vk::SampleCountFlagBits rasterizationSamples ) const = 0;


        virtual void _SetSampleMaskEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits samples,
                                        const vk::SampleMask* pSampleMask ) const = 0;


        virtual void _SetAlphaToCoverageEnableEXT( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 alphaToCoverageEnable ) const = 0;


        virtual void _SetAlphaToOneEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToOneEnable ) const = 0;


        virtual void _SetLogicOpEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 logicOpEnable ) const = 0;


        virtual void _SetColorBlendEnableEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                              uint32_t attachmentCount,
                                              const vk::Bool32* pColorBlendEnables ) const = 0;


        virtual void _SetColorBlendEquationEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                                uint32_t attachmentCount,
                                                const vk::ColorBlendEquationEXT* pColorBlendEquations ) const = 0;


        virtual void _SetColorWriteMaskEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                            uint32_t attachmentCount,
                                            const vk::ColorComponentFlags* pColorWriteMasks ) const = 0;


        virtual void _SetRasterizationStreamEXT( vk::CommandBuffer commandBuffer,
                                                 uint32_t rasterizationStream ) const = 0;


        virtual void _SetConservativeRasterizationModeEXT(
                vk::CommandBuffer commandBuffer,
                vk::ConservativeRasterizationModeEXT conservativeRasterizationMode ) const = 0;


        virtual void _SetExtraPrimitiveOverestimationSizeEXT( vk::CommandBuffer commandBuffer,
                                                              float extraPrimitiveOverestimationSize ) const = 0;


        virtual void _SetDepthClipEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClipEnable ) const = 0;


        virtual void _SetSampleLocationsEnableEXT( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 sampleLocationsEnable ) const = 0;


        virtual void _SetColorBlendAdvancedEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                                uint32_t attachmentCount,
                                                const vk::ColorBlendAdvancedEXT* pColorBlendAdvanced ) const = 0;


        virtual void _SetProvokingVertexModeEXT( vk::CommandBuffer commandBuffer,
                                                 vk::ProvokingVertexModeEXT provokingVertexMode ) const = 0;


        virtual void _SetLineRasterizationModeEXT( vk::CommandBuffer commandBuffer,
                                                   vk::LineRasterizationModeEXT lineRasterizationMode ) const = 0;


        virtual void _SetLineStippleEnableEXT( vk::CommandBuffer commandBuffer,
                                               vk::Bool32 stippledLineEnable ) const = 0;


        virtual void _SetDepthClipNegativeOneToOneEXT( vk::CommandBuffer commandBuffer,
                                                       vk::Bool32 negativeOneToOne ) const = 0;


        virtual void _SetViewportWScalingEnableNV( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 viewportWScalingEnable ) const = 0;


        virtual void _SetViewportSwizzleNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                            uint32_t viewportCount,
                                            const vk::ViewportSwizzleNV* pViewportSwizzles ) const = 0;


        virtual void _SetCoverageToColorEnableNV( vk::CommandBuffer commandBuffer,
                                                  vk::Bool32 coverageToColorEnable ) const = 0;


        virtual void _SetCoverageToColorLocationNV( vk::CommandBuffer commandBuffer,
                                                    uint32_t coverageToColorLocation ) const = 0;


        virtual void _SetCoverageModulationModeNV( vk::CommandBuffer commandBuffer,
                                                   vk::CoverageModulationModeNV coverageModulationMode ) const = 0;


        virtual void _SetCoverageModulationTableEnableNV( vk::CommandBuffer commandBuffer,
                                                          vk::Bool32 coverageModulationTableEnable ) const = 0;


        virtual void _SetCoverageModulationTableNV( vk::CommandBuffer commandBuffer,
                                                    uint32_t coverageModulationTableCount,
                                                    const float* pCoverageModulationTable ) const = 0;


        virtual void _SetShadingRateImageEnableNV( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 shadingRateImageEnable ) const = 0;


        virtual void _SetRepresentativeFragmentTestEnableNV( vk::CommandBuffer commandBuffer,
                                                             vk::Bool32 representativeFragmentTestEnable ) const = 0;


        virtual void _SetCoverageReductionModeNV( vk::CommandBuffer commandBuffer,
                                                  vk::CoverageReductionModeNV coverageReductionMode ) const = 0;


        virtual void _OpticalFlowExecuteNV( vk::CommandBuffer commandBuffer, vk::OpticalFlowSessionNV session,
                                            const vk::OpticalFlowExecuteInfoNV* pExecuteInfo ) const = 0;


        virtual void _BindIndexBuffer2KHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                           vk::DeviceSize size, vk::IndexType indexType ) const = 0;


        virtual void _BindShadersEXT( vk::CommandBuffer commandBuffer, uint32_t stageCount,
                                      const vk::ShaderStageFlagBits* pStages, const vk::ShaderEXT* pShaders ) const = 0;


        virtual void _SetAttachmentFeedbackLoopEnableEXT( vk::CommandBuffer commandBuffer,
                                                          vk::ImageAspectFlags aspectMask ) const = 0;


        virtual ResultValueType<vk::Result> _Submit( vk::Queue queue, uint32_t submitCount,
                                                     const vk::SubmitInfo* pSubmits, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result>
        _Submit( vk::Queue queue, vk::ArrayProxy<const vk::SubmitInfo> const& submits, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _WaitIdle( vk::Queue queue ) const = 0;


        virtual ResultValueType<vk::Result> _BindSparse( vk::Queue queue, uint32_t bindInfoCount,
                                                         const vk::BindSparseInfo* pBindInfo,
                                                         vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _BindSparse( vk::Queue queue,
                                                         vk::ArrayProxy<const vk::BindSparseInfo> const& bindInfo,
                                                         vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _Submit2( vk::Queue queue, uint32_t submitCount,
                                                      const vk::SubmitInfo2* pSubmits, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result>
        _Submit2( vk::Queue queue, vk::ArrayProxy<const vk::SubmitInfo2> const& submits, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _PresentKHR( vk::Queue queue,
                                                         const vk::PresentInfoKHR* pPresentInfo ) const = 0;


        virtual void _BeginDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo ) const = 0;


        virtual void _EndDebugUtilsLabelEXT( vk::Queue queue ) const = 0;


        virtual void _InsertDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo ) const = 0;


        virtual void _GetCheckpointDataNV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                           vk::CheckpointDataNV* pCheckpointData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::CheckpointDataNV, std::allocator<vk::CheckpointDataNV>>>
        _GetCheckpointDataNV( vk::Queue queue ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetPerformanceConfigurationINTEL( vk::Queue queue, vk::PerformanceConfigurationINTEL configuration ) const = 0;

        virtual ResultValueType<vk::Result> _Submit2KHR( vk::Queue queue, uint32_t submitCount,
                                                         const vk::SubmitInfo2* pSubmits, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result>
        _Submit2KHR( vk::Queue queue, vk::ArrayProxy<const vk::SubmitInfo2> const& submits, vk::Fence fence ) const = 0;


        virtual void _GetCheckpointData2NV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                            vk::CheckpointData2NV* pCheckpointData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::CheckpointData2NV, std::allocator<vk::CheckpointData2NV>>>
        _GetCheckpointData2NV( vk::Queue queue ) const = 0;


        virtual void _Destroy( vk::Device device, const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex,
                                vk::Queue* pQueue ) const = 0;


        virtual ResultValue<vk::Result, vk::Queue> _GetQueue( vk::Device device, uint32_t queueFamilyIndex,
                                                              uint32_t queueIndex ) const = 0;


        virtual ResultValueType<vk::Result> _WaitIdle( vk::Device device ) const = 0;


        virtual ResultValueType<vk::Result> _AllocateMemory( vk::Device device,
                                                             const vk::MemoryAllocateInfo* pAllocateInfo,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::DeviceMemory* pMemory ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceMemory>
        _AllocateMemory( vk::Device device, const vk::MemoryAllocateInfo& allocateInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _FreeMemory( vk::Device device, vk::DeviceMemory memory,
                                  const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _FreeMemory( vk::Device device, vk::DeviceMemory memory,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                        vk::DeviceSize offset, vk::DeviceSize size,
                                                        vk::MemoryMapFlags flags, void** ppData ) const = 0;


        virtual ResultValue<vk::Result, void*> _MapMemory( vk::Device device, vk::DeviceMemory memory,
                                                           vk::DeviceSize offset, vk::DeviceSize size,
                                                           vk::MemoryMapFlags flags ) const = 0;


        virtual void _UnmapMemory( vk::Device device, vk::DeviceMemory memory ) const = 0;


        virtual ResultValueType<vk::Result>
        _FlushMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                  const vk::MappedMemoryRange* pMemoryRanges ) const = 0;


        virtual ResultValueType<vk::Result>
        _InvalidateMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                       const vk::MappedMemoryRange* pMemoryRanges ) const = 0;


        virtual void _GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory,
                                           vk::DeviceSize* pCommittedMemoryInBytes ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceSize> _GetMemoryCommitment( vk::Device device,
                                                                              vk::DeviceMemory memory ) const = 0;


        virtual ResultValueType<vk::Result> _BindBufferMemory( vk::Device device, vk::Buffer buffer,
                                                               vk::DeviceMemory memory,
                                                               vk::DeviceSize memoryOffset ) const = 0;


        virtual ResultValueType<vk::Result> _BindImageMemory( vk::Device device, vk::Image image,
                                                              vk::DeviceMemory memory,
                                                              vk::DeviceSize memoryOffset ) const = 0;

        virtual void _GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer,
                                                   vk::MemoryRequirements* pMemoryRequirements ) const = 0;


        virtual ResultValue<vk::Result, vk::MemoryRequirements>
        _GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer ) const = 0;


        virtual void _GetImageMemoryRequirements( vk::Device device, vk::Image image,
                                                  vk::MemoryRequirements* pMemoryRequirements ) const = 0;


        virtual ResultValue<vk::Result, vk::MemoryRequirements>
        _GetImageMemoryRequirements( vk::Device device, vk::Image image ) const = 0;


        virtual void
        _GetImageSparseMemoryRequirements( vk::Device device, vk::Image image, uint32_t* pSparseMemoryRequirementCount,
                                           vk::SparseImageMemoryRequirements* pSparseMemoryRequirements ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::SparseImageMemoryRequirements,
                                                    std::allocator<vk::SparseImageMemoryRequirements>>>
        _GetImageSparseMemoryRequirements( vk::Device device, vk::Image image ) const = 0;


        virtual ResultValueType<vk::Result> _CreateFence( vk::Device device, const vk::FenceCreateInfo* pCreateInfo,
                                                          const vk::AllocationCallbacks* pAllocator,
                                                          vk::Fence* pFence ) const = 0;


        virtual ResultValue<vk::Result, vk::Fence>
        _CreateFence( vk::Device device, const vk::FenceCreateInfo& createInfo,
                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyFence( vk::Device device, vk::Fence fence,
                                    const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyFence( vk::Device device, vk::Fence fence,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Fence fence,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Fence fence,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _ResetFences( vk::Device device, uint32_t fenceCount,
                                                          const vk::Fence* pFences ) const = 0;


        virtual ResultValueType<vk::Result> _GetFenceStatus( vk::Device device, vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _WaitForFences( vk::Device device, uint32_t fenceCount,
                                                            const vk::Fence* pFences, vk::Bool32 waitAll,
                                                            uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result> _WaitForFences( vk::Device device,
                                                            vk::ArrayProxy<const vk::Fence> const& fences,
                                                            vk::Bool32 waitAll, uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result> _CreateSemaphore( vk::Device device,
                                                              const vk::SemaphoreCreateInfo* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::Semaphore* pSemaphore ) const = 0;


        virtual ResultValue<vk::Result, vk::Semaphore>
        _CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroySemaphore( vk::Device device, vk::Semaphore semaphore,
                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroySemaphore( vk::Device device, vk::Semaphore semaphore,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Semaphore semaphore,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Semaphore semaphore,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateEvent( vk::Device device, const vk::EventCreateInfo* pCreateInfo,
                                                          const vk::AllocationCallbacks* pAllocator,
                                                          vk::Event* pEvent ) const = 0;


        virtual ResultValue<vk::Result, vk::Event>
        _CreateEvent( vk::Device device, const vk::EventCreateInfo& createInfo,
                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyEvent( vk::Device device, vk::Event event,
                                    const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyEvent( vk::Device device, vk::Event event,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Event event,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Event event,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetEventStatus( vk::Device device, vk::Event event ) const = 0;


        virtual ResultValueType<vk::Result> _SetEvent( vk::Device device, vk::Event event ) const = 0;


        virtual ResultValueType<vk::Result> _ResetEvent( vk::Device device, vk::Event event ) const = 0;


        virtual ResultValueType<vk::Result> _CreateQueryPool( vk::Device device,
                                                              const vk::QueryPoolCreateInfo* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::QueryPool* pQueryPool ) const = 0;


        virtual ResultValue<vk::Result, vk::QueryPool>
        _CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyQueryPool( vk::Device device, vk::QueryPool queryPool,
                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyQueryPool( vk::Device device, vk::QueryPool queryPool,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::QueryPool queryPool,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::QueryPool queryPool,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool,
                                                                  uint32_t firstQuery, uint32_t queryCount,
                                                                  size_t dataSize, void* pData, vk::DeviceSize stride,
                                                                  vk::QueryResultFlags flags ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                              size_t dataSize, vk::DeviceSize stride, vk::QueryResultFlags flags ) const = 0;


        virtual ResultValue<vk::Result, uint8_t> _GetQueryPoolResult( vk::Device device, vk::QueryPool queryPool,
                                                                      uint32_t firstQuery, uint32_t queryCount,
                                                                      vk::DeviceSize stride,
                                                                      vk::QueryResultFlags flags ) const = 0;


        virtual ResultValueType<vk::Result> _CreateBuffer( vk::Device device, const vk::BufferCreateInfo* pCreateInfo,
                                                           const vk::AllocationCallbacks* pAllocator,
                                                           vk::Buffer* pBuffer ) const = 0;


        virtual ResultValue<vk::Result, vk::Buffer>
        _CreateBuffer( vk::Device device, const vk::BufferCreateInfo& createInfo,
                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyBuffer( vk::Device device, vk::Buffer buffer,
                                     const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyBuffer( vk::Device device, vk::Buffer buffer,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Buffer buffer,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Buffer buffer,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateBufferView( vk::Device device,
                                                               const vk::BufferViewCreateInfo* pCreateInfo,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::BufferView* pView ) const = 0;


        virtual ResultValue<vk::Result, vk::BufferView>
        _CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyBufferView( vk::Device device, vk::BufferView bufferView,
                                         const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyBufferView( vk::Device device, vk::BufferView bufferView,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::BufferView bufferView,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::BufferView bufferView,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateImage( vk::Device device, const vk::ImageCreateInfo* pCreateInfo,
                                                          const vk::AllocationCallbacks* pAllocator,
                                                          vk::Image* pImage ) const = 0;


        virtual ResultValue<vk::Result, vk::Image>
        _CreateImage( vk::Device device, const vk::ImageCreateInfo& createInfo,
                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyImage( vk::Device device, vk::Image image,
                                    const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyImage( vk::Device device, vk::Image image,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Image image,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Image image,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _GetImageSubresourceLayout( vk::Device device, vk::Image image,
                                                 const vk::ImageSubresource* pSubresource,
                                                 vk::SubresourceLayout* pLayout ) const = 0;


        virtual ResultValueType<vk::Result> _CreateImageView( vk::Device device,
                                                              const vk::ImageViewCreateInfo* pCreateInfo,
                                                              const vk::AllocationCallbacks* pAllocator,
                                                              vk::ImageView* pView ) const = 0;


        virtual ResultValue<vk::Result, vk::ImageView>
        _CreateImageView( vk::Device device, const vk::ImageViewCreateInfo& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyImageView( vk::Device device, vk::ImageView imageView,
                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyImageView( vk::Device device, vk::ImageView imageView,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ImageView imageView,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ImageView imageView,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateShaderModule( vk::Device device,
                                                                 const vk::ShaderModuleCreateInfo* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::ShaderModule* pShaderModule ) const = 0;


        virtual ResultValue<vk::Result, vk::ShaderModule>
        _CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo& createInfo,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule,
                                           const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ShaderModule shaderModule,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ShaderModule shaderModule,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreatePipelineCache( vk::Device device,
                                                                  const vk::PipelineCacheCreateInfo* pCreateInfo,
                                                                  const vk::AllocationCallbacks* pAllocator,
                                                                  vk::PipelineCache* pPipelineCache ) const = 0;


        virtual ResultValue<vk::Result, vk::PipelineCache>
        _CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache,
                                            const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache,
                                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache,
                                                                   size_t* pDataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache ) const = 0;


        virtual ResultValueType<vk::Result> _MergePipelineCaches( vk::Device device, vk::PipelineCache dstCache,
                                                                  uint32_t srcCacheCount,
                                                                  const vk::PipelineCache* pSrcCaches ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                  const vk::GraphicsPipelineCreateInfo* pCreateInfos,
                                  const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        _CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                  vk::ArrayProxy<const vk::GraphicsPipelineCreateInfo> const& createInfos,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::Pipeline>
        _CreateGraphicsPipeline( vk::Device device, vk::PipelineCache pipelineCache,
                                 const vk::GraphicsPipelineCreateInfo& createInfo,
                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                                                     uint32_t createInfoCount,
                                                                     const vk::ComputePipelineCreateInfo* pCreateInfos,
                                                                     const vk::AllocationCallbacks* pAllocator,
                                                                     vk::Pipeline* pPipelines ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        _CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                                 vk::ArrayProxy<const vk::ComputePipelineCreateInfo> const& createInfos,
                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::Pipeline>
        _CreateComputePipeline( vk::Device device, vk::PipelineCache pipelineCache,
                                const vk::ComputePipelineCreateInfo& createInfo,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyPipeline( vk::Device device, vk::Pipeline pipeline,
                                       const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyPipeline( vk::Device device, vk::Pipeline pipeline,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Pipeline pipeline,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Pipeline pipeline,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreatePipelineLayout( vk::Device device,
                                                                   const vk::PipelineLayoutCreateInfo* pCreateInfo,
                                                                   const vk::AllocationCallbacks* pAllocator,
                                                                   vk::PipelineLayout* pPipelineLayout ) const = 0;


        virtual ResultValue<vk::Result, vk::PipelineLayout>
        _CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout,
                                             const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout,
                                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateSampler( vk::Device device, const vk::SamplerCreateInfo* pCreateInfo,
                                                            const vk::AllocationCallbacks* pAllocator,
                                                            vk::Sampler* pSampler ) const = 0;


        virtual ResultValue<vk::Result, vk::Sampler>
        _CreateSampler( vk::Device device, const vk::SamplerCreateInfo& createInfo,
                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroySampler( vk::Device device, vk::Sampler sampler,
                                      const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroySampler( vk::Device device, vk::Sampler sampler,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Sampler sampler,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Sampler sampler,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                    const vk::AllocationCallbacks* pAllocator,
                                    vk::DescriptorSetLayout* pSetLayout ) const = 0;


        virtual ResultValue<vk::Result, vk::DescriptorSetLayout>
        _CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                                                  const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateDescriptorPool( vk::Device device,
                                                                   const vk::DescriptorPoolCreateInfo* pCreateInfo,
                                                                   const vk::AllocationCallbacks* pAllocator,
                                                                   vk::DescriptorPool* pDescriptorPool ) const = 0;


        virtual ResultValue<vk::Result, vk::DescriptorPool>
        _CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                             const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _ResetDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                                                  vk::DescriptorPoolResetFlags flags ) const = 0;


        virtual ResultValueType<vk::Result> _AllocateDescriptorSets( vk::Device device,
                                                                     const vk::DescriptorSetAllocateInfo* pAllocateInfo,
                                                                     vk::DescriptorSet* pDescriptorSets ) const = 0;


        virtual ResultValueType<vk::Result> _FreeDescriptorSets( vk::Device device, vk::DescriptorPool descriptorPool,
                                                                 uint32_t descriptorSetCount,
                                                                 const vk::DescriptorSet* pDescriptorSets ) const = 0;


        virtual void _UpdateDescriptorSets( vk::Device device, uint32_t descriptorWriteCount,
                                            const vk::WriteDescriptorSet* pDescriptorWrites,
                                            uint32_t descriptorCopyCount,
                                            const vk::CopyDescriptorSet* pDescriptorCopies ) const = 0;


        virtual ResultValueType<vk::Result> _CreateFramebuffer( vk::Device device,
                                                                const vk::FramebufferCreateInfo* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::Framebuffer* pFramebuffer ) const = 0;


        virtual ResultValue<vk::Result, vk::Framebuffer>
        _CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer,
                                          const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Framebuffer framebuffer,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::Framebuffer framebuffer,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateRenderPass( vk::Device device,
                                                               const vk::RenderPassCreateInfo* pCreateInfo,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::RenderPass* pRenderPass ) const = 0;


        virtual ResultValue<vk::Result, vk::RenderPass>
        _CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo& createInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyRenderPass( vk::Device device, vk::RenderPass renderPass,
                                         const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyRenderPass( vk::Device device, vk::RenderPass renderPass,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::RenderPass renderPass,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::RenderPass renderPass,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass,
                                                vk::Extent2D* pGranularity ) const = 0;


        virtual ResultValue<vk::Result, vk::Extent2D> _GetRenderAreaGranularity( vk::Device device,
                                                                                 vk::RenderPass renderPass ) const = 0;


        virtual ResultValueType<vk::Result> _CreateCommandPool( vk::Device device,
                                                                const vk::CommandPoolCreateInfo* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::CommandPool* pCommandPool ) const = 0;


        virtual ResultValue<vk::Result, vk::CommandPool>
        _CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyCommandPool( vk::Device device, vk::CommandPool commandPool,
                                          const vk::AllocationCallbacks* pAllocator = nullptr ) const = 0;


        virtual void _DestroyCommandPool( vk::Device device, vk::CommandPool commandPool,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CommandPool commandPool,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CommandPool commandPool,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _ResetCommandPool( vk::Device device, vk::CommandPool commandPool,
                                                               vk::CommandPoolResetFlags flags ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::CommandBuffer>>
        _AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo ) const = 0;


        virtual ResultValueType<vk::Result> _AllocateCommandBuffers( vk::Device device,
                                                                     const vk::CommandBufferAllocateInfo* pAllocateInfo,
                                                                     vk::CommandBuffer* pCommandBuffers ) const = 0;


        virtual void _FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, uint32_t commandBufferCount,
                                          const vk::CommandBuffer* pCommandBuffers ) const = 0;


        virtual ResultValueType<vk::Result> _BindBufferMemory2( vk::Device device, uint32_t bindInfoCount,
                                                                const vk::BindBufferMemoryInfo* pBindInfos ) const = 0;


        virtual ResultValueType<vk::Result> _BindImageMemory2( vk::Device device, uint32_t bindInfoCount,
                                                               const vk::BindImageMemoryInfo* pBindInfos ) const = 0;


        virtual void _GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                  uint32_t remoteDeviceIndex,
                                                  vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures ) const = 0;


        virtual ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>
        _GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                     uint32_t remoteDeviceIndex ) const = 0;


        virtual void _GetImageMemoryRequirements2( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                                   vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void _GetBufferMemoryRequirements2( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo,
                                                    vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void
        _GetImageSparseMemoryRequirements2( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                                            uint32_t* pSparseMemoryRequirementCount,
                                            vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const = 0;


        virtual void _TrimCommandPool( vk::Device device, vk::CommandPool commandPool,
                                       vk::CommandPoolTrimFlags flags ) const = 0;


        virtual void _GetQueue2( vk::Device device, const vk::DeviceQueueInfo2* pQueueInfo,
                                 vk::Queue* pQueue ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator,
                                       vk::SamplerYcbcrConversion* pYcbcrConversion ) const = 0;


        virtual ResultValue<vk::Result, vk::SamplerYcbcrConversion>
        _CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                     const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate ) const = 0;


        virtual ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
        _CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDescriptorUpdateTemplate( vk::Device device,
                                                       vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                       const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroyDescriptorUpdateTemplate( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _UpdateDescriptorSetWithTemplate( vk::Device device, vk::DescriptorSet descriptorSet,
                                                       vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                       const void* pData ) const = 0;


        virtual void _GetDescriptorSetLayoutSupport( vk::Device device,
                                                     const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                                     vk::DescriptorSetLayoutSupport* pSupport ) const = 0;


        virtual ResultValueType<vk::Result> _CreateRenderPass2( vk::Device device,
                                                                const vk::RenderPassCreateInfo2* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::RenderPass* pRenderPass ) const = 0;


        virtual ResultValue<vk::Result, vk::RenderPass>
        _CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _ResetQueryPool( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                                      uint32_t queryCount ) const = 0;


        virtual ResultValueType<vk::Result> _GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore,
                                                                       uint64_t* pValue ) const = 0;


        virtual ResultValue<vk::Result, uint64_t> _GetSemaphoreCounterValue( vk::Device device,
                                                                             vk::Semaphore semaphore ) const = 0;


        virtual ResultValueType<vk::Result> _WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo,
                                                             uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result> _WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo,
                                                             uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result> _SignalSemaphore( vk::Device device,
                                                              const vk::SemaphoreSignalInfo* pSignalInfo ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceAddress>
        _GetBufferAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const = 0;


        virtual ResultValue<vk::Result, uint64_t>
        _GetBufferOpaqueCaptureAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const = 0;


        virtual ResultValue<vk::Result, uint64_t>
        _GetMemoryOpaqueCaptureAddress( vk::Device device,
                                        const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo ) const = 0;


        virtual ResultValueType<vk::Result> _CreatePrivateDataSlot( vk::Device device,
                                                                    const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                                                    const vk::AllocationCallbacks* pAllocator,
                                                                    vk::PrivateDataSlot* pPrivateDataSlot ) const = 0;


        virtual ResultValue<vk::Result, vk::PrivateDataSlot>
        _CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                              const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _SetPrivateData( vk::Device device, vk::ObjectType objectType_,
                                                             uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot,
                                                             uint64_t data ) const = 0;


        // virtual ResultValueType<vk::Result> _SetPrivateData( vk::Device device, vk::ObjectType objectType_,
        //  uint64_t objectHandle, vk::PrivateDataSlot privateDataSlot,
        //  uint64_t data ) const = 0;


        virtual void _GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                      vk::PrivateDataSlot privateDataSlot, uint64_t* pData ) const = 0;


        virtual ResultValue<vk::Result, uint64_t> _GetPrivateData( vk::Device device, vk::ObjectType objectType_,
                                                                   uint64_t objectHandle,
                                                                   vk::PrivateDataSlot privateDataSlot ) const = 0;


        virtual void _GetBufferMemoryRequirements( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo,
                                                   vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void _GetImageMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                  vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void
        _GetImageSparseMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                           uint32_t* pSparseMemoryRequirementCount,
                                           vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const = 0;


        virtual ResultValueType<vk::Result> _CreateSwapchainKHR( vk::Device device,
                                                                 const vk::SwapchainCreateInfoKHR* pCreateInfo,
                                                                 const vk::AllocationCallbacks* pAllocator,
                                                                 vk::SwapchainKHR* pSwapchain ) const = 0;


        virtual ResultValue<vk::Result, vk::SwapchainKHR>
        _CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                           const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::SwapchainKHR swapchain,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::SwapchainKHR swapchain,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                                    uint32_t* pSwapchainImageCount,
                                                                    vk::Image* pSwapchainImages ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::Image, std::allocator<vk::Image>>>
        _GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result> _AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                                  uint64_t timeout, vk::Semaphore semaphore,
                                                                  vk::Fence fence, uint32_t* pImageIndex ) const = 0;


        virtual ResultValue<uint32_t> _AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                            uint64_t timeout, vk::Semaphore semaphore,
                                                            vk::Fence fence ) const = 0;


        virtual ResultValueType<vk::Result> _GetGroupPresentCapabilitiesKHR(
                vk::Device device, vk::DeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceGroupPresentCapabilitiesKHR>
        _GetGroupPresentCapabilitiesKHR( vk::Device device ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface,
                                         vk::DeviceGroupPresentModeFlagsKHR* pModes ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR>
        _GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result> _AcquireNextImage2KHR( vk::Device device,
                                                                   const vk::AcquireNextImageInfoKHR* pAcquireInfo,
                                                                   uint32_t* pImageIndex ) const = 0;


        virtual ResultValueType<vk::Result> _CreateSharedSwapchainsKHR( vk::Device device, uint32_t swapchainCount,
                                                                        const vk::SwapchainCreateInfoKHR* pCreateInfos,
                                                                        const vk::AllocationCallbacks* pAllocator,
                                                                        vk::SwapchainKHR* pSwapchains ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::SwapchainKHR, std::allocator<vk::SwapchainKHR>>>
        _CreateSharedSwapchainsKHR( vk::Device device,
                                    vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                                    vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::SwapchainKHR>
        _CreateSharedSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _DebugMarkerSetObjectTagEXT( vk::Device device, const vk::DebugMarkerObjectTagInfoEXT* pTagInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _DebugMarkerSetObjectNameEXT( vk::Device device, const vk::DebugMarkerObjectNameInfoEXT* pNameInfo ) const = 0;


        virtual ResultValueType<vk::Result> _CreateVideoSessionKHR( vk::Device device,
                                                                    const vk::VideoSessionCreateInfoKHR* pCreateInfo,
                                                                    const vk::AllocationCallbacks* pAllocator,
                                                                    vk::VideoSessionKHR* pVideoSession ) const = 0;


        virtual ResultValue<vk::Result, vk::VideoSessionKHR>
        _CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR& createInfo,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                              const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                               uint32_t* pMemoryRequirementsCount,
                                               vk::VideoSessionMemoryRequirementsKHR* pMemoryRequirements ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::VideoSessionMemoryRequirementsKHR,
                                                    std::allocator<vk::VideoSessionMemoryRequirementsKHR>>>
        _GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession ) const = 0;


        virtual ResultValueType<vk::Result>
        _BindVideoSessionMemoryKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                    uint32_t bindSessionMemoryInfoCount,
                                    const vk::BindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR* pCreateInfo,
                                          const vk::AllocationCallbacks* pAllocator,
                                          vk::VideoSessionParametersKHR* pVideoSessionParameters ) const = 0;


        virtual ResultValue<vk::Result, vk::VideoSessionParametersKHR>
        _CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR& createInfo,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _UpdateVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                                          const vk::VideoSessionParametersUpdateInfoKHR* pUpdateInfo ) const = 0;


        virtual void _DestroyVideoSessionParametersKHR( vk::Device device,
                                                        vk::VideoSessionParametersKHR videoSessionParameters,
                                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroyVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateCuModuleNVX( vk::Device device,
                                                                const vk::CuModuleCreateInfoNVX* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::CuModuleNVX* pModule ) const = 0;


        virtual ResultValue<vk::Result, vk::CuModuleNVX>
        _CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateCuFunctionNVX( vk::Device device,
                                                                  const vk::CuFunctionCreateInfoNVX* pCreateInfo,
                                                                  const vk::AllocationCallbacks* pAllocator,
                                                                  vk::CuFunctionNVX* pFunction ) const = 0;


        virtual ResultValue<vk::Result, vk::CuFunctionNVX>
        _CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX& createInfo,
                              vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                          const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CuModuleNVX module,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CuModuleNVX module,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                            const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CuFunctionNVX function,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::CuFunctionNVX function,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, uint32_t>
        _GetImageViewHandleNVX( vk::Device device, const vk::ImageViewHandleInfoNVX* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView,
                                 vk::ImageViewAddressPropertiesNVX* pProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::ImageViewAddressPropertiesNVX>
        _GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView ) const = 0;


        virtual ResultValueType<vk::Result> _GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline,
                                                               vk::ShaderStageFlagBits shaderStage,
                                                               vk::ShaderInfoTypeAMD infoType, size_t* pInfoSize,
                                                               void* pInfo ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage,
                           vk::ShaderInfoTypeAMD infoType ) const = 0;


        virtual ResultValueType<vk::Result> _GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                                                     vk::ExternalMemoryHandleTypeFlagsNV handleType,
                                                                     HANDLE* pHandle ) const = 0;


        virtual ResultValue<vk::Result, HANDLE>
        _GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                 vk::ExternalMemoryHandleTypeFlagsNV handleType ) const = 0;


        virtual void _GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                                     uint32_t remoteDeviceIndex,
                                                     vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures ) const = 0;


        virtual ResultValue<vk::Result, vk::PeerMemoryFeatureFlags>
        _GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                        uint32_t remoteDeviceIndex ) const = 0;


        virtual void _TrimCommandPoolKHR( vk::Device device, vk::CommandPool commandPool,
                                          vk::CommandPoolTrimFlags flags ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetMemoryWin32HandleKHR( vk::Device device, const vk::MemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                  HANDLE* pHandle ) const = 0;


        virtual ResultValueType<vk::Result> _GetMemoryWin32HandlePropertiesKHR(
                vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, HANDLE handle,
                vk::MemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::MemoryWin32HandlePropertiesKHR>
        _GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                            HANDLE handle ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetMemoryFdKHR( vk::Device device, const vk::MemoryGetFdInfoKHR* pGetFdInfo, int* pFd ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd,
                                   vk::MemoryFdPropertiesKHR* pMemoryFdProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::MemoryFdPropertiesKHR>
        _GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                   int fd ) const = 0;


        virtual ResultValueType<vk::Result> _ImportSemaphoreWin32HandleKHR(
                vk::Device device,
                const vk::ImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSemaphoreWin32HandleKHR( vk::Device device, const vk::SemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                     HANDLE* pHandle ) const = 0;


        virtual ResultValueType<vk::Result>
        _ImportSemaphoreFdKHR( vk::Device device,
                               const vk::ImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSemaphoreFdKHR( vk::Device device, const vk::SemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDescriptorUpdateTemplateKHR( vk::Device device,
                                            const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                            const vk::AllocationCallbacks* pAllocator,
                                            vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate ) const = 0;


        virtual ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
        _CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDescriptorUpdateTemplateKHR( vk::Device device,
                                                          vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                          const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroyDescriptorUpdateTemplateKHR( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                             vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _UpdateDescriptorSetWithTemplateKHR( vk::Device device, vk::DescriptorSet descriptorSet,
                                                          vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                          const void* pData ) const = 0;


        virtual ResultValueType<vk::Result>
        _DisplayPowerControlEXT( vk::Device device, vk::DisplayKHR display,
                                 const vk::DisplayPowerInfoEXT* pDisplayPowerInfo ) const = 0;


        virtual ResultValueType<vk::Result> _RegisterEventEXT( vk::Device device,
                                                               const vk::DeviceEventInfoEXT* pDeviceEventInfo,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::Fence* pFence ) const = 0;


        virtual ResultValue<vk::Result, vk::Fence>
        _RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT& deviceEventInfo,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display,
                                                                      const vk::DisplayEventInfoEXT* pDisplayEventInfo,
                                                                      const vk::AllocationCallbacks* pAllocator,
                                                                      vk::Fence* pFence ) const = 0;


        virtual ResultValue<vk::Result, vk::Fence>
        _RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display,
                                  const vk::DisplayEventInfoEXT& displayEventInfo,
                                  vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                                                     vk::SurfaceCounterFlagBitsEXT counter,
                                                                     uint64_t* pCounterValue ) const = 0;


        virtual ResultValue<vk::Result, uint64_t>
        _GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                 vk::SurfaceCounterFlagBitsEXT counter ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                        vk::RefreshCycleDurationGOOGLE* pDisplayTimingProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::RefreshCycleDurationGOOGLE>
        _GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                          uint32_t* pPresentationTimingCount,
                                          vk::PastPresentationTimingGOOGLE* pPresentationTimings ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE,
                                                    std::allocator<vk::PastPresentationTimingGOOGLE>>>
        _GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain ) const = 0;


        virtual void _SetHdrMetadataEXT( vk::Device device, uint32_t swapchainCount,
                                         const vk::SwapchainKHR* pSwapchains,
                                         const vk::HdrMetadataEXT* pMetadata ) const = 0;


        virtual ResultValueType<vk::Result> _CreateRenderPass2KHR( vk::Device device,
                                                                   const vk::RenderPassCreateInfo2* pCreateInfo,
                                                                   const vk::AllocationCallbacks* pAllocator,
                                                                   vk::RenderPass* pRenderPass ) const = 0;


        virtual ResultValue<vk::Result, vk::RenderPass>
        _CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetSwapchainStatusKHR( vk::Device device,
                                                                    vk::SwapchainKHR swapchain ) const = 0;


        // virtual ResultValueType<vk::Result> _GetSwapchainStatusKHR( vk::Device device,
        // vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result>
        _ImportFenceWin32HandleKHR( vk::Device device,
                                    const vk::ImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetFenceWin32HandleKHR( vk::Device device, const vk::FenceGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                 HANDLE* pHandle ) const = 0;


        virtual ResultValueType<vk::Result>
        _ImportFenceFdKHR( vk::Device device, const vk::ImportFenceFdInfoKHR* pImportFenceFdInfo ) const = 0;


        virtual ResultValueType<vk::Result> _GetFenceFdKHR( vk::Device device, const vk::FenceGetFdInfoKHR* pGetFdInfo,
                                                            int* pFd ) const = 0;


        virtual ResultValueType<vk::Result>
        _AcquireProfilingLockKHR( vk::Device device, const vk::AcquireProfilingLockInfoKHR* pInfo ) const = 0;


        virtual void _ReleaseProfilingLockKHR( vk::Device device ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetDebugUtilsObjectNameEXT( vk::Device device, const vk::DebugUtilsObjectNameInfoEXT* pNameInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _SetDebugUtilsObjectTagEXT( vk::Device device, const vk::DebugUtilsObjectTagInfoEXT* pTagInfo ) const = 0;


        virtual void _GetImageMemoryRequirements2KHR( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                                      vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void _GetBufferMemoryRequirements2KHR( vk::Device device,
                                                       const vk::BufferMemoryRequirementsInfo2* pInfo,
                                                       vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void _GetImageSparseMemoryRequirements2KHR(
                vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                uint32_t* pSparseMemoryRequirementCount,
                vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::AccelerationStructureKHR* pAccelerationStructure ) const = 0;


        virtual ResultValue<vk::Result, vk::AccelerationStructureKHR>
        _CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR& createInfo,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyAccelerationStructureKHR( vk::Device device,
                                                       vk::AccelerationStructureKHR accelerationStructure,
                                                       const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroyAccelerationStructureKHR( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _BuildAccelerationStructuresKHR(
                vk::Device device, vk::DeferredOperationKHR deferredOperation, uint32_t infoCount,
                const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                       const vk::CopyAccelerationStructureInfoKHR* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyAccelerationStructureToMemoryKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                               const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyMemoryToAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                               const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _WriteAccelerationStructuresPropertiesKHR( vk::Device device, uint32_t accelerationStructureCount,
                                                   const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                   vk::QueryType queryType, size_t dataSize, void* pData,
                                                   size_t stride ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _WriteAccelerationStructuresPropertiesKHR(
                vk::Device device, vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
                vk::QueryType queryType, size_t dataSize, size_t stride ) const = 0;


        virtual ResultValue<vk::Result, uint8_t> _WriteAccelerationStructuresPropertyKHR(
                vk::Device device, vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
                vk::QueryType queryType, size_t stride ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceAddress>
        _GetAccelerationStructureAddressKHR( vk::Device device,
                                             const vk::AccelerationStructureDeviceAddressInfoKHR* pInfo ) const = 0;


        virtual void _GetAccelerationStructureCompatibilityKHR(
                vk::Device device, const vk::AccelerationStructureVersionInfoKHR* pVersionInfo,
                vk::AccelerationStructureCompatibilityKHR* pCompatibility ) const = 0;


        virtual void
        _GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                                const vk::AccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
                                                const uint32_t* pMaxPrimitiveCounts,
                                                vk::AccelerationStructureBuildSizesInfoKHR* pSizeInfo ) const = 0;


        virtual ResultValue<vk::Result, vk::AccelerationStructureBuildSizesInfoKHR>
        _GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                                const vk::AccelerationStructureBuildGeometryInfoKHR& buildInfo,
                                                vk::ArrayProxy<const uint32_t> const& maxPrimitiveCounts ) = 0;


        virtual ResultValueType<vk::Result>
        _CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                       vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                       const vk::RayTracingPipelineCreateInfoKHR* pCreateInfos,
                                       const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines ) const = 0;


        virtual ResultValue<std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        _CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                       vk::PipelineCache pipelineCache,
                                       vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::Pipeline>
        _CreateRayTracingPipelineKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      vk::PipelineCache pipelineCache,
                                      const vk::RayTracingPipelineCreateInfoKHR& createInfo,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                             uint32_t groupCount, size_t dataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                             uint32_t groupCount, size_t dataSize ) const = 0;


        virtual ResultValue<vk::Result, uint8_t> _GetRayTracingShaderGroupHandleKHR( vk::Device device,
                                                                                     vk::Pipeline pipeline,
                                                                                     uint32_t firstGroup,
                                                                                     uint32_t groupCount ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                          uint32_t groupCount, size_t dataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                          uint32_t groupCount, size_t dataSize ) const = 0;


        virtual ResultValue<vk::Result, uint8_t>
        _GetRayTracingCaptureReplayShaderGroupHandleKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                         uint32_t groupCount ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceSize>
        _GetRayTracingShaderGroupStackSizeKHR( vk::Device device, vk::Pipeline pipeline, uint32_t group,
                                               vk::ShaderGroupShaderKHR groupShader ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                          const vk::AllocationCallbacks* pAllocator,
                                          vk::SamplerYcbcrConversion* pYcbcrConversion ) const = 0;


        virtual ResultValue<vk::Result, vk::SamplerYcbcrConversion>
        _CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _BindBufferMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                               const vk::BindBufferMemoryInfo* pBindInfos ) const = 0;


        virtual ResultValueType<vk::Result> _BindImageMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                                                                  const vk::BindImageMemoryInfo* pBindInfos ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image,
                                                 vk::ImageDrmFormatModifierPropertiesEXT* pProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::ImageDrmFormatModifierPropertiesEXT>
        _GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator,
                                   vk::ValidationCacheEXT* pValidationCache ) const = 0;


        virtual ResultValue<vk::Result, vk::ValidationCacheEXT>
        _CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT& createInfo,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                                 const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _MergeValidationCachesEXT( vk::Device device, vk::ValidationCacheEXT dstCache, uint32_t srcCacheCount,
                                   const vk::ValidationCacheEXT* pSrcCaches ) const = 0;


        virtual ResultValueType<vk::Result> _GetValidationCacheDataEXT( vk::Device device,
                                                                        vk::ValidationCacheEXT validationCache,
                                                                        size_t* pDataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::AccelerationStructureNV* pAccelerationStructure ) const = 0;


        virtual ResultValue<vk::Result, vk::AccelerationStructureNV>
        _CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV& createInfo,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyAccelerationStructureNV( vk::Device device,
                                                      vk::AccelerationStructureNV accelerationStructure,
                                                      const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyAccelerationStructureNV( vk::Device device,
                                                      vk::AccelerationStructureNV accelerationStructure,
                                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void
        _GetAccelerationStructureMemoryRequirementsNV( vk::Device device,
                                                       const vk::AccelerationStructureMemoryRequirementsInfoNV* pInfo,
                                                       vk::MemoryRequirements2KHR* pMemoryRequirements ) const = 0;


        virtual ResultValueType<vk::Result>
        _BindAccelerationStructureMemoryNV( vk::Device device, uint32_t bindInfoCount,
                                            const vk::BindAccelerationStructureMemoryInfoNV* pBindInfos ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                      const vk::RayTracingPipelineCreateInfoNV* pCreateInfos,
                                      const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines ) const = 0;


        virtual ResultValue<std::vector<vk::Pipeline, std::allocator<vk::Pipeline>>>
        _CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache,
                                      vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                                      vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::Pipeline>
        _CreateRayTracingPipelineNV( vk::Device device, vk::PipelineCache pipelineCache,
                                     const vk::RayTracingPipelineCreateInfoNV& createInfo,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                            uint32_t groupCount, size_t dataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                            uint32_t groupCount, size_t dataSize ) const = 0;


        virtual ResultValue<vk::Result, uint8_t> _GetRayTracingShaderGroupHandleNV( vk::Device device,
                                                                                    vk::Pipeline pipeline,
                                                                                    uint32_t firstGroup,
                                                                                    uint32_t groupCount ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                           size_t dataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                           size_t dataSize ) const = 0;


        virtual ResultValue<vk::Result, uint8_t>
        _GetAccelerationStructureHandleNV( vk::Device device,
                                           vk::AccelerationStructureNV accelerationStructure ) const = 0;


        virtual ResultValueType<vk::Result> _CompileDeferredNV( vk::Device device, vk::Pipeline pipeline,
                                                                uint32_t shader ) const = 0;


        // virtual ResultValueType<vk::Result> _CompileDeferredNV( vk::Device device, vk::Pipeline pipeline,
        // uint32_t shader ) const = 0;


        virtual void _GetDescriptorSetLayoutSupportKHR( vk::Device device,
                                                        const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                                        vk::DescriptorSetLayoutSupport* pSupport ) const = 0;


        virtual ResultValueType<vk::Result> _GetMemoryHostPointerPropertiesEXT(
                vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, const void* pHostPointer,
                vk::MemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetCalibratedTimestampsEXT( vk::Device device, uint32_t timestampCount,
                                     const vk::CalibratedTimestampInfoEXT* pTimestampInfos, uint64_t* pTimestamps,
                                     uint64_t* pMaxDeviation ) const = 0;


        virtual ResultValue<vk::Result, std::pair<uint64_t, uint64_t>>
        _GetCalibratedTimestampEXT( vk::Device device, const vk::CalibratedTimestampInfoEXT& timestampInfo ) const = 0;


        virtual ResultValueType<vk::Result> _GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore,
                                                                          uint64_t* pValue ) const = 0;


        virtual ResultValue<vk::Result, uint64_t> _GetSemaphoreCounterValueKHR( vk::Device device,
                                                                                vk::Semaphore semaphore ) const = 0;


        virtual ResultValueType<vk::Result>
        _WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo, uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result>
        _WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo, uint64_t timeout ) const = 0;


        virtual ResultValueType<vk::Result> _SignalSemaphoreKHR( vk::Device device,
                                                                 const vk::SemaphoreSignalInfo* pSignalInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _InitializePerformanceApiINTEL( vk::Device device,
                                        const vk::InitializePerformanceApiInfoINTEL* pInitializeInfo ) const = 0;


        virtual void _UninitializePerformanceApiINTEL( vk::Device device ) const = 0;


        virtual ResultValueType<vk::Result>
        _AcquirePerformanceConfigurationINTEL( vk::Device device,
                                               const vk::PerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
                                               vk::PerformanceConfigurationINTEL* pConfiguration ) const = 0;


        virtual ResultValueType<vk::Result>
        _ReleasePerformanceConfigurationINTEL( vk::Device device,
                                               vk::PerformanceConfigurationINTEL configuration ) const = 0;


        // virtual ResultValueType<vk::Result>
        // _ReleasePerformanceConfigurationINTEL( vk::Device device,
        //    vk::PerformanceConfigurationINTEL configuration ) const = 0;


        // virtual ResultValueType<vk::Result> _Release( vk::Device device,
        //   vk::PerformanceConfigurationINTEL configuration ) const = 0;


        virtual ResultValueType<vk::Result> _Release( vk::Device device,
                                                      vk::PerformanceConfigurationINTEL configuration ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter,
                                       vk::PerformanceValueINTEL* pValue ) const = 0;


        virtual ResultValue<vk::Result, vk::PerformanceValueINTEL>
        _GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter ) const = 0;


        virtual void _SetLocalDimmingAMD( vk::Device device, vk::SwapchainKHR swapChain,
                                          vk::Bool32 localDimmingEnable ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceAddress>
        _GetBufferAddressEXT( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const = 0;


        virtual ResultValueType<vk::Result> _WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                                                uint64_t presentId, uint64_t timeout ) const = 0;

        //
        // virtual ResultValueType<vk::Result> _WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain,
        // uint64_t presentId, uint64_t timeout ) const = 0;


        // virtual ResultValueType<vk::Result> _AcquireFullScreenExclusiveModeEXT( vk::Device device,
        // vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result> _AcquireFullScreenExclusiveModeEXT( vk::Device device,
                                                                                vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result> _ReleaseFullScreenExclusiveModeEXT( vk::Device device,
                                                                                vk::SwapchainKHR swapchain ) const = 0;


        // virtual ResultValueType<vk::Result> _ReleaseFullScreenExclusiveModeEXT( vk::Device device,
        // vk::SwapchainKHR swapchain ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetGroupSurfacePresentModes2EXT( vk::Device device, const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                          vk::DeviceGroupPresentModeFlagsKHR* pModes ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceAddress>
        _GetBufferAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const = 0;


        virtual ResultValue<vk::Result, uint64_t>
        _GetBufferOpaqueCaptureAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const = 0;


        virtual ResultValue<vk::Result, uint64_t>
        _GetMemoryOpaqueCaptureAddressKHR( vk::Device device,
                                           const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo ) const = 0;


        virtual void _ResetQueryPoolEXT( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDeferredOperationKHR( vk::Device device, const vk::AllocationCallbacks* pAllocator,
                                     vk::DeferredOperationKHR* pDeferredOperation ) const = 0;


        virtual ResultValue<vk::Result, vk::DeferredOperationKHR>
        _CreateDeferredOperationKHR( vk::Device device,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation,
                                                   const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation,
                                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, uint32_t>
        _GetDeferredOperationMaxConcurrencyKHR( vk::Device device, vk::DeferredOperationKHR operation ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDeferredOperationResultKHR( vk::Device device, vk::DeferredOperationKHR operation ) const = 0;

        virtual ResultValueType<vk::Result> _DeferredOperationJoinKHR( vk::Device device,
                                                                       vk::DeferredOperationKHR operation ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetPipelineExecutablePropertiesKHR( vk::Device device, const vk::PipelineInfoKHR* pPipelineInfo,
                                             uint32_t* pExecutableCount,
                                             vk::PipelineExecutablePropertiesKHR* pProperties ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetPipelineExecutableStatisticsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo,
                                             uint32_t* pStatisticCount,
                                             vk::PipelineExecutableStatisticKHR* pStatistics ) const = 0;


        virtual ResultValueType<vk::Result> _GetPipelineExecutableInternalRepresentationsKHR(
                vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo,
                uint32_t* pInternalRepresentationCount,
                vk::PipelineExecutableInternalRepresentationKHR* pInternalRepresentations ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyMemoryToImageEXT( vk::Device device,
                               const vk::CopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyImageToMemoryEXT( vk::Device device,
                               const vk::CopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyImageToImageEXT( vk::Device device, const vk::CopyImageToImageInfoEXT* pCopyImageToImageInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _TransitionImageLayoutEXT( vk::Device device, uint32_t transitionCount,
                                   const vk::HostImageLayoutTransitionInfoEXT* pTransitions ) const = 0;


        virtual void _GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image,
                                                     const vk::ImageSubresource2KHR* pSubresource,
                                                     vk::SubresourceLayout2KHR* pLayout ) const = 0;


        virtual ResultValueType<vk::Result>
        _MapMemory2KHR( vk::Device device, const vk::MemoryMapInfoKHR* pMemoryMapInfo, void** ppData ) const = 0;


        virtual ResultValueType<vk::Result>
        _UnmapMemory2KHR( vk::Device device, const vk::MemoryUnmapInfoKHR* pMemoryUnmapInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _ReleaseSwapchainImagesEXT( vk::Device device,
                                    const vk::ReleaseSwapchainImagesInfoEXT* pReleaseInfo ) const = 0;


        virtual void
        _GetGeneratedCommandsMemoryRequirementsNV( vk::Device device,
                                                   const vk::GeneratedCommandsMemoryRequirementsInfoNV* pInfo,
                                                   vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::IndirectCommandsLayoutNV* pIndirectCommandsLayout ) const = 0;


        virtual ResultValue<vk::Result, vk::IndirectCommandsLayoutNV>
        _CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV& createInfo,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyIndirectCommandsLayoutNV( vk::Device device,
                                                       vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                                                       const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void
        _DestroyIndirectCommandsLayoutNV( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator,
                                   vk::PrivateDataSlot* pPrivateDataSlot ) const = 0;


        virtual ResultValue<vk::Result, vk::PrivateDataSlot>
        _CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                                 const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                                 vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_,
                                                                uint64_t objectHandle,
                                                                vk::PrivateDataSlot privateDataSlot,
                                                                uint64_t data ) const = 0;


        // virtual ResultValueType<vk::Result> _SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_,
        // uint64_t objectHandle,
        // vk::PrivateDataSlot privateDataSlot,
        // uint64_t data ) const = 0;


        // virtual void _GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
        //  vk::PrivateDataSlot privateDataSlot, uint64_t* pData ) const = 0;


        virtual ResultValue<vk::Result, uint64_t> _GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_,
                                                                      uint64_t objectHandle,
                                                                      vk::PrivateDataSlot privateDataSlot ) const = 0;


        virtual void _GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                     vk::DeviceSize* pLayoutSizeInBytes ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceSize>
        _GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout ) const = 0;


        virtual void _GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                              uint32_t binding, vk::DeviceSize* pOffset ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceSize>
        _GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                 uint32_t binding ) const = 0;


        virtual void _GetDescriptorEXT( vk::Device device, const vk::DescriptorGetInfoEXT* pDescriptorInfo,
                                        size_t dataSize, void* pDescriptor ) const = 0;


        virtual ResultValueType<vk::Result> _GetBufferOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::BufferCaptureDescriptorDataInfoEXT* pInfo, void* pData ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::ImageCaptureDescriptorDataInfoEXT* pInfo,
                                                 void* pData ) const = 0;


        virtual ResultValueType<vk::Result> _GetImageViewOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::ImageViewCaptureDescriptorDataInfoEXT* pInfo, void* pData ) const = 0;


        virtual ResultValueType<vk::Result> _GetSamplerOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::SamplerCaptureDescriptorDataInfoEXT* pInfo, void* pData ) const = 0;


        virtual ResultValueType<vk::Result> _GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
                vk::Device device, const vk::AccelerationStructureCaptureDescriptorDataInfoEXT* pInfo,
                void* pData ) const = 0;


        virtual ResultValueType<vk::Result> _GetFaultInfoEXT( vk::Device device, vk::DeviceFaultCountsEXT* pFaultCounts,
                                                              vk::DeviceFaultInfoEXT* pFaultInfo ) const = 0;


        virtual ResultValue<std::pair<vk::DeviceFaultCountsEXT, vk::DeviceFaultInfoEXT>>
        _GetFaultInfoEXT( vk::Device device ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass,
                                                  vk::Extent2D* pMaxWorkgroupSize ) const = 0;


        virtual ResultValue<vk::Result, vk::Extent2D>
        _GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetMemoryRemoteAddressNV( vk::Device device,
                                   const vk::MemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo,
                                   vk::RemoteAddressNV* pAddress ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetPipelinePropertiesEXT( vk::Device device, const vk::PipelineInfoEXT* pPipelineInfo,
                                   vk::BaseOutStructure* pPipelineProperties ) const = 0;


        virtual ResultValueType<vk::Result> _CreateMicromapEXT( vk::Device device,
                                                                const vk::MicromapCreateInfoEXT* pCreateInfo,
                                                                const vk::AllocationCallbacks* pAllocator,
                                                                vk::MicromapEXT* pMicromap ) const = 0;


        virtual ResultValue<vk::Result, vk::MicromapEXT>
        _CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT& createInfo,
                            vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap,
                                          const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap,
                                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::MicromapEXT micromap,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::MicromapEXT micromap,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _BuildMicromapsEXT( vk::Device device,
                                                                vk::DeferredOperationKHR deferredOperation,
                                                                uint32_t infoCount,
                                                                const vk::MicromapBuildInfoEXT* pInfos ) const = 0;


        virtual ResultValueType<vk::Result> _CopyMicromapEXT( vk::Device device,
                                                              vk::DeferredOperationKHR deferredOperation,
                                                              const vk::CopyMicromapInfoEXT* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyMicromapToMemoryEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                  const vk::CopyMicromapToMemoryInfoEXT* pInfo ) const = 0;


        virtual ResultValueType<vk::Result>
        _CopyMemoryToMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                  const vk::CopyMemoryToMicromapInfoEXT* pInfo ) const = 0;


        virtual ResultValueType<vk::Result> _WriteMicromapsPropertiesEXT( vk::Device device, uint32_t micromapCount,
                                                                          const vk::MicromapEXT* pMicromaps,
                                                                          vk::QueryType queryType, size_t dataSize,
                                                                          void* pData, size_t stride ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _WriteMicromapsPropertiesEXT( vk::Device device, vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                                      vk::QueryType queryType, size_t dataSize, size_t stride ) const = 0;


        virtual void
        _GetMicromapCompatibilityEXT( vk::Device device, const vk::MicromapVersionInfoEXT* pVersionInfo,
                                      vk::AccelerationStructureCompatibilityKHR* pCompatibility ) const = 0;


        virtual void _GetMicromapBuildSizesEXT( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                                const vk::MicromapBuildInfoEXT* pBuildInfo,
                                                vk::MicromapBuildSizesInfoEXT* pSizeInfo ) const = 0;


        virtual void _SetMemoryPriorityEXT( vk::Device device, vk::DeviceMemory memory, float priority ) const = 0;


        virtual void _GetBufferMemoryRequirementsKHR( vk::Device device,
                                                      const vk::DeviceBufferMemoryRequirements* pInfo,
                                                      vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void _GetImageMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                     vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual void
        _GetImageSparseMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                              uint32_t* pSparseMemoryRequirementCount,
                                              vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const = 0;


        virtual void _GetDescriptorSetLayoutHostMappingInfoVALVE(
                vk::Device device, const vk::DescriptorSetBindingReferenceVALVE* pBindingReference,
                vk::DescriptorSetLayoutHostMappingInfoVALVE* pHostMapping ) const = 0;


        virtual void _GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet,
                                                        void** ppData ) const = 0;


        virtual ResultValue<vk::Result, void*>
        _GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet ) const = 0;


        virtual void _GetPipelineIndirectMemoryRequirementsNV( vk::Device device,
                                                               const vk::ComputePipelineCreateInfo* pCreateInfo,
                                                               vk::MemoryRequirements2* pMemoryRequirements ) const = 0;


        virtual ResultValue<vk::Result, vk::DeviceAddress>
        _GetPipelineIndirectAddressNV( vk::Device device,
                                       const vk::PipelineIndirectDeviceAddressInfoNV* pInfo ) const = 0;


        virtual void _GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule,
                                                    vk::ShaderModuleIdentifierEXT* pIdentifier ) const = 0;


        virtual ResultValue<vk::Result, vk::ShaderModuleIdentifierEXT>
        _GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule ) const = 0;


        virtual void _GetShaderModuleCreateInfoIdentifierEXT( vk::Device device,
                                                              const vk::ShaderModuleCreateInfo* pCreateInfo,
                                                              vk::ShaderModuleIdentifierEXT* pIdentifier ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator,
                                     vk::OpticalFlowSessionNV* pSession ) const = 0;


        virtual ResultValue<vk::Result, vk::OpticalFlowSessionNV>
        _CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV& createInfo,
                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                   const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                        vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view,
                                        vk::ImageLayout layout ) const = 0;


        // virtual ResultValueType<vk::Result>
        // _BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session,
        // vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view,
        // vk::ImageLayout layout ) const = 0;


        virtual void _GetRenderingAreaGranularityKHR( vk::Device device,
                                                      const vk::RenderingAreaInfoKHR* pRenderingAreaInfo,
                                                      vk::Extent2D* pGranularity ) const = 0;


        virtual void _GetImageSubresourceLayoutKHR( vk::Device device, const vk::DeviceImageSubresourceInfoKHR* pInfo,
                                                    vk::SubresourceLayout2KHR* pLayout ) const = 0;


        virtual void _GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image,
                                                     const vk::ImageSubresource2KHR* pSubresource,
                                                     vk::SubresourceLayout2KHR* pLayout ) const = 0;


        virtual ResultValueType<vk::Result> _CreateShadersEXT( vk::Device device, uint32_t createInfoCount,
                                                               const vk::ShaderCreateInfoEXT* pCreateInfos,
                                                               const vk::AllocationCallbacks* pAllocator,
                                                               vk::ShaderEXT* pShaders ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::ShaderEXT, std::allocator<vk::ShaderEXT>>>
        _CreateShadersEXT( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                           vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValue<vk::Result, vk::ShaderEXT>
        _CreateShaderEXT( vk::Device device, const vk::ShaderCreateInfoEXT& createInfo,
                          vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader,
                                        const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader,
                                        vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ShaderEXT shader,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Device device, vk::ShaderEXT shader,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader,
                                                                     size_t* pDataSize, void* pData ) const = 0;


        virtual ResultValue<vk::Result, std::vector<uint8_t, std::allocator<uint8_t>>>
        _GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer, uint32_t* pPropertiesCount,
                                           vk::TilePropertiesQCOM* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::TilePropertiesQCOM, std::allocator<vk::TilePropertiesQCOM>>>
        _GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDynamicRenderingTilePropertiesQCOM( vk::Device device, const vk::RenderingInfo* pRenderingInfo,
                                                vk::TilePropertiesQCOM* pProperties ) const = 0;


        virtual void _GetFeatures( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures* pFeatures ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceFeatures>
        _GetFeatures( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format,
                                           vk::FormatProperties* pFormatProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::FormatProperties> _GetFormatProperties( vk::PhysicalDevice physicalDevice,
                                                                                    vk::Format format ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                   vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags,
                                   vk::ImageFormatProperties* pImageFormatProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::ImageFormatProperties>
        _GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                   vk::ImageTiling tiling, vk::ImageUsageFlags usage,
                                   vk::ImageCreateFlags flags ) const = 0;


        virtual void _GetProperties( vk::PhysicalDevice physicalDevice,
                                     vk::PhysicalDeviceProperties* pProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceProperties>
        _GetProperties( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                                vk::QueueFamilyProperties* pQueueFamilyProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::QueueFamilyProperties, std::allocator<vk::QueueFamilyProperties>>>
        _GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetMemoryProperties( vk::PhysicalDevice physicalDevice,
                                           vk::PhysicalDeviceMemoryProperties* pMemoryProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties>
        _GetMemoryProperties( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result> _CreateDevice( vk::PhysicalDevice physicalDevice,
                                                           const vk::DeviceCreateInfo* pCreateInfo,
                                                           const vk::AllocationCallbacks* pAllocator,
                                                           vk::Device* pDevice ) const = 0;


        virtual ResultValue<vk::Result, vk::Device>
        _CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo& createInfo,
                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice, const char* pLayerName,
                                             uint32_t* pPropertyCount, vk::ExtensionProperties* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>>
        _EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice,
                                             vk::Optional<const std::string> layerName ) const = 0;


        virtual ResultValueType<vk::Result>
        _EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                         vk::LayerProperties* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>>
        _EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format,
                                                      vk::ImageType type, vk::SampleCountFlagBits samples,
                                                      vk::ImageUsageFlags usage, vk::ImageTiling tiling,
                                                      uint32_t* pPropertyCount,
                                                      vk::SparseImageFormatProperties* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::SparseImageFormatProperties,
                                                    std::allocator<vk::SparseImageFormatProperties>>>
        _GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                         vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage,
                                         vk::ImageTiling tiling ) const = 0;


        virtual void _GetFeatures2( vk::PhysicalDevice physicalDevice,
                                    vk::PhysicalDeviceFeatures2* pFeatures ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceFeatures2>
        _GetFeatures2( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetProperties2( vk::PhysicalDevice physicalDevice,
                                      vk::PhysicalDeviceProperties2* pProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceProperties2>
        _GetProperties2( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format,
                                            vk::FormatProperties2* pFormatProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::FormatProperties2> _GetFormatProperties2( vk::PhysicalDevice physicalDevice,
                                                                                      vk::Format format ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                    const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                    vk::ImageFormatProperties2* pImageFormatProperties ) const = 0;


        virtual void _GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                                 vk::QueueFamilyProperties2* pQueueFamilyProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>
        _GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice ) const = 0;


        // virtual ResultValue<vk::Result, std::vector<vk::QueueFamilyProperties2, vk::QueueFamilyProperties2Allocator>>
        // _GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice,
        // vk::QueueFamilyProperties2Allocator& queueFamilyProperties2Allocator ) const = 0;

        virtual void _GetMemoryProperties2( vk::PhysicalDevice physicalDevice,
                                            vk::PhysicalDeviceMemoryProperties2* pMemoryProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>
        _GetMemoryProperties2( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                                       const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                       uint32_t* pPropertyCount,
                                                       vk::SparseImageFormatProperties2* pProperties ) const = 0;


        virtual void _GetExternalBufferProperties( vk::PhysicalDevice physicalDevice,
                                                   const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                                   vk::ExternalBufferProperties* pExternalBufferProperties ) const = 0;


        virtual void _GetExternalFenceProperties( vk::PhysicalDevice physicalDevice,
                                                  const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                  vk::ExternalFenceProperties* pExternalFenceProperties ) const = 0;


        virtual void
        _GetExternalSemaphoreProperties( vk::PhysicalDevice physicalDevice,
                                         const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                         vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetToolProperties( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount,
                            vk::PhysicalDeviceToolProperties* pToolProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties,
                                                    std::allocator<vk::PhysicalDeviceToolProperties>>>
        _GetToolProperties( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result> _GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice,
                                                                   uint32_t queueFamilyIndex, vk::SurfaceKHR surface,
                                                                   vk::Bool32* pSupported ) const = 0;


        virtual ResultValue<vk::Result, vk::Bool32> _GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice,
                                                                           uint32_t queueFamilyIndex,
                                                                           vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                    vk::SurfaceCapabilitiesKHR* pSurfaceCapabilities ) const = 0;


        virtual ResultValue<vk::Result, vk::SurfaceCapabilitiesKHR>
        _GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result> _GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice,
                                                                   vk::SurfaceKHR surface,
                                                                   uint32_t* pSurfaceFormatCount,
                                                                   vk::SurfaceFormatKHR* pSurfaceFormats ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::SurfaceFormatKHR, std::allocator<vk::SurfaceFormatKHR>>>
        _GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result> _GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice,
                                                                        vk::SurfaceKHR surface,
                                                                        uint32_t* pPresentModeCount,
                                                                        vk::PresentModeKHR* pPresentModes ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PresentModeKHR, std::allocator<vk::PresentModeKHR>>>
        _GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result> _GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice,
                                                                      vk::SurfaceKHR surface, uint32_t* pRectCount,
                                                                      vk::Rect2D* pRects ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::Rect2D, std::allocator<vk::Rect2D>>>
        _GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const = 0;


        virtual ResultValueType<vk::Result> _GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                                      uint32_t* pPropertyCount,
                                                                      vk::DisplayPropertiesKHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, std::allocator<vk::DisplayPropertiesKHR>>>
        _GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                       vk::DisplayPlanePropertiesKHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::DisplayPlanePropertiesKHR, std::allocator<vk::DisplayPlanePropertiesKHR>>>
        _GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result> _GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice,
                                                                                  uint32_t planeIndex,
                                                                                  uint32_t* pDisplayCount,
                                                                                  vk::DisplayKHR* pDisplays ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::DisplayKHR, std::allocator<vk::DisplayKHR>>>
        _GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                                      uint32_t* pPropertyCount, vk::DisplayModePropertiesKHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::DisplayModePropertiesKHR, std::allocator<vk::DisplayModePropertiesKHR>>>
        _GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const = 0;


        virtual ResultValueType<vk::Result> _CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice,
                                                                   vk::DisplayKHR display,
                                                                   const vk::DisplayModeCreateInfoKHR* pCreateInfo,
                                                                   const vk::AllocationCallbacks* pAllocator,
                                                                   vk::DisplayModeKHR* pMode ) const = 0;


        virtual ResultValue<vk::Result, vk::DisplayModeKHR>
        _CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                               const vk::DisplayModeCreateInfoKHR& createInfo,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode,
                                         uint32_t planeIndex,
                                         vk::DisplayPlaneCapabilitiesKHR* pCapabilities ) const = 0;


        virtual ResultValue<vk::Result, vk::DisplayPlaneCapabilitiesKHR>
        _GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode,
                                         uint32_t planeIndex ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice, const vk::VideoProfileInfoKHR* pVideoProfile,
                                  vk::VideoCapabilitiesKHR* pCapabilities ) const = 0;


        virtual ResultValueType<vk::Result> _GetVideoFormatPropertiesKHR(
                vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo,
                uint32_t* pVideoFormatPropertyCount, vk::VideoFormatPropertiesKHR* pVideoFormatProperties ) const = 0;


        virtual ResultValueType<vk::Result> _GetExternalImageFormatPropertiesNV(
                vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type, vk::ImageTiling tiling,
                vk::ImageUsageFlags usage, vk::ImageCreateFlags flags,
                vk::ExternalMemoryHandleTypeFlagsNV externalHandleType,
                vk::ExternalImageFormatPropertiesNV* pExternalImageFormatProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::ExternalImageFormatPropertiesNV>
        _GetExternalImageFormatPropertiesNV( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                             vk::ImageTiling tiling, vk::ImageUsageFlags usage,
                                             vk::ImageCreateFlags flags,
                                             vk::ExternalMemoryHandleTypeFlagsNV externalHandleType ) const = 0;


        virtual void _GetFeatures2KHR( vk::PhysicalDevice physicalDevice,
                                       vk::PhysicalDeviceFeatures2* pFeatures ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceFeatures2>
        _GetFeatures2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetProperties2KHR( vk::PhysicalDevice physicalDevice,
                                         vk::PhysicalDeviceProperties2* pProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceProperties2>
        _GetProperties2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format,
                                               vk::FormatProperties2* pFormatProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::FormatProperties2>
        _GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                       const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                       vk::ImageFormatProperties2* pImageFormatProperties ) const = 0;


        virtual void _GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                    uint32_t* pQueueFamilyPropertyCount,
                                                    vk::QueueFamilyProperties2* pQueueFamilyProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::QueueFamilyProperties2, std::allocator<vk::QueueFamilyProperties2>>>
        _GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice,
                                               vk::PhysicalDeviceMemoryProperties2* pMemoryProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties2>
        _GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                          const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                          uint32_t* pPropertyCount,
                                                          vk::SparseImageFormatProperties2* pProperties ) const = 0;


        virtual void
        _GetExternalBufferPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                         const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                         vk::ExternalBufferProperties* pExternalBufferProperties ) const = 0;


        virtual void
        _GetExternalSemaphorePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                            const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                            vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties ) const = 0;


        virtual ResultValueType<vk::Result> _ReleaseDisplayEXT( vk::PhysicalDevice physicalDevice,
                                                                vk::DisplayKHR display ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                     vk::SurfaceCapabilities2EXT* pSurfaceCapabilities ) const = 0;


        virtual ResultValue<vk::Result, vk::SurfaceCapabilities2EXT>
        _GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const = 0;


        virtual void _GetExternalFencePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                                     const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                                     vk::ExternalFenceProperties* pExternalFenceProperties ) const = 0;


        virtual ResultValueType<vk::Result> _EnumerateQueueFamilyPerformanceQueryCountersKHR(
                vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, uint32_t* pCounterCount,
                vk::PerformanceCounterKHR* pCounters,
                vk::PerformanceCounterDescriptionKHR* pCounterDescriptions ) const = 0;


        virtual void _GetQueueFamilyPerformanceQueryPassesKHR(
                vk::PhysicalDevice physicalDevice,
                const vk::QueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo,
                uint32_t* pNumPasses ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                     const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                     vk::SurfaceCapabilities2KHR* pSurfaceCapabilities ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice,
                                const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pSurfaceFormatCount,
                                vk::SurfaceFormat2KHR* pSurfaceFormats ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                   vk::DisplayProperties2KHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::DisplayProperties2KHR, std::allocator<vk::DisplayProperties2KHR>>>
        _GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                        vk::DisplayPlaneProperties2KHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::DisplayPlaneProperties2KHR, std::allocator<vk::DisplayPlaneProperties2KHR>>>
        _GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                                       uint32_t* pPropertyCount, vk::DisplayModeProperties2KHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result,
                            std::vector<vk::DisplayModeProperties2KHR, std::allocator<vk::DisplayModeProperties2KHR>>>
        _GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetDisplayPlaneCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                          const vk::DisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                          vk::DisplayPlaneCapabilities2KHR* pCapabilities ) const = 0;


        virtual void _GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples,
                                                   vk::MultisamplePropertiesEXT* pMultisampleProperties ) const = 0;


        virtual ResultValue<vk::Result, vk::MultisamplePropertiesEXT>
        _GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice, uint32_t* pTimeDomainCount,
                                         vk::TimeDomainEXT* pTimeDomains ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, std::allocator<vk::TimeDomainEXT>>>
        _GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                     vk::PhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDeviceFragmentShadingRateKHR,
                                                    std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>>>
        _GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount,
                               vk::PhysicalDeviceToolProperties* pToolProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties,
                                                    std::allocator<vk::PhysicalDeviceToolProperties>>>
        _GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                           vk::CooperativeMatrixPropertiesNV* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV,
                                                    std::allocator<vk::CooperativeMatrixPropertiesNV>>>
        _GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result> _GetSupportedFramebufferMixedSamplesCombinationsNV(
                vk::PhysicalDevice physicalDevice, uint32_t* pCombinationCount,
                vk::FramebufferMixedSamplesCombinationNV* pCombinations ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::FramebufferMixedSamplesCombinationNV,
                                                    std::allocator<vk::FramebufferMixedSamplesCombinationNV>>>
        _GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice,
                                     const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo, uint32_t* pPresentModeCount,
                                     vk::PresentModeKHR* pPresentModes ) const = 0;


        virtual ResultValueType<vk::Result> _AcquireDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd,
                                                                   vk::DisplayKHR display ) const = 0;


        virtual ResultValueType<vk::Result> _GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd,
                                                               uint32_t connectorId,
                                                               vk::DisplayKHR* display ) const = 0;


        virtual ResultValue<vk::Result, vk::DisplayKHR>
        _GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId ) const = 0;


        virtual ResultValueType<vk::Result> _AcquireWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                    vk::DisplayKHR display ) const = 0;


        virtual ResultValueType<vk::Result> _GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                uint32_t deviceRelativeId,
                                                                vk::DisplayKHR* pDisplay ) const = 0;


        virtual ResultValue<vk::Result, vk::DisplayKHR> _GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                            uint32_t deviceRelativeId ) const = 0;


        virtual ResultValueType<vk::Result> _GetOpticalFlowImageFormatsNV(
                vk::PhysicalDevice physicalDevice, const vk::OpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo,
                uint32_t* pFormatCount, vk::OpticalFlowImageFormatPropertiesNV* pImageFormatProperties ) const = 0;


        virtual ResultValueType<vk::Result>
        _GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                            vk::CooperativeMatrixPropertiesKHR* pProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR,
                                                    std::allocator<vk::CooperativeMatrixPropertiesKHR>>>
        _GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice ) const = 0;


        virtual void _Destroy( vk::Instance instance, const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _EnumeratePhysicalDevices( vk::Instance instance,
                                                                       uint32_t* pPhysicalDeviceCount,
                                                                       vk::PhysicalDevice* pPhysicalDevices ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDevice, std::allocator<vk::PhysicalDevice>>>
        _EnumeratePhysicalDevices( vk::Instance instance ) const = 0;


        virtual ResultValue<vk::Result, PFN_vkVoidFunction> _GetProcAddr( vk::Instance instance,
                                                                          const char* pName ) const = 0;


        virtual ResultValueType<vk::Result>
        _EnumeratePhysicalDeviceGroups( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                                        vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties,
                                                    std::allocator<vk::PhysicalDeviceGroupProperties>>>
        _EnumeratePhysicalDeviceGroups( vk::Instance instance ) const = 0;


        virtual void _DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface,
                                         const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface,
                                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::SurfaceKHR surface,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::SurfaceKHR surface,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface ) const = 0;


        virtual ResultValue<vk::Result, vk::SurfaceKHR>
        _CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR& createInfo,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateWin32SurfaceKHR( vk::Instance instance,
                                                                    const vk::Win32SurfaceCreateInfoKHR* pCreateInfo,
                                                                    const vk::AllocationCallbacks* pAllocator,
                                                                    vk::SurfaceKHR* pSurface ) const = 0;


        virtual ResultValue<vk::Result, vk::SurfaceKHR>
        _CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR& createInfo,
                                vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator,
                                       vk::DebugReportCallbackEXT* pCallback ) const = 0;


        virtual ResultValue<vk::Result, vk::DebugReportCallbackEXT>
        _CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT& createInfo,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                                                     const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DebugReportMessageEXT( vk::Instance instance, vk::DebugReportFlagsEXT flags,
                                             vk::DebugReportObjectTypeEXT objectType_, uint64_t object, size_t location,
                                             int32_t messageCode, const char* pLayerPrefix,
                                             const char* pMessage ) const = 0;


        virtual ResultValueType<vk::Result> _EnumeratePhysicalDeviceGroupsKHR(
                vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties ) const = 0;


        virtual ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties,
                                                    std::allocator<vk::PhysicalDeviceGroupProperties>>>
        _EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator,
                                       vk::DebugUtilsMessengerEXT* pMessenger ) const = 0;


        virtual ResultValue<vk::Result, vk::DebugUtilsMessengerEXT>
        _CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT& createInfo,
                                       vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                                                     const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                                                     vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                               const vk::AllocationCallbacks* pAllocator ) const = 0;


        virtual void _Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                               vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual void
        _SubmitDebugUtilsMessageEXT( vk::Instance instance, vk::DebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                     vk::DebugUtilsMessageTypeFlagsEXT messageTypes,
                                     const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData ) const = 0;


        virtual ResultValueType<vk::Result>
        _CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface ) const = 0;


        virtual ResultValue<vk::Result, vk::SurfaceKHR>
        _CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT& createInfo,
                                   vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) const = 0;


        virtual ResultValueType<vk::Result> _CreateInstance( vk::Instance instance,
                                                             const vk::InstanceCreateInfo* pCreateInfo,
                                                             const vk::AllocationCallbacks* pAllocator,
                                                             vk::Instance* pInstance ) = 0;


        virtual ResultValue<vk::Result, vk::Instance>
        _CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo& createInfo,
                         vk::Optional<const vk::AllocationCallbacks> allocator = nullptr ) = 0;


        virtual ResultValueType<vk::Result>
        _EnumerateInstanceExtensionProperties( vk::Instance instance, const char* pLayerName, uint32_t* pPropertyCount,
                                               vk::ExtensionProperties* pProperties ) = 0;


        virtual ResultValue<vk::Result, std::vector<vk::ExtensionProperties, std::allocator<vk::ExtensionProperties>>>
        _EnumerateInstanceExtensionProperties( vk::Instance instance, vk::Optional<const std::string> layerName ) = 0;


        virtual ResultValueType<vk::Result> _EnumerateInstanceLayerProperties( vk::Instance instance,
                                                                               uint32_t* pPropertyCount,
                                                                               vk::LayerProperties* pProperties ) = 0;


        virtual ResultValue<vk::Result, std::vector<vk::LayerProperties, std::allocator<vk::LayerProperties>>>
        _EnumerateInstanceLayerProperties( vk::Instance instance ) = 0;

    public:
        template <typename T>
        static void RegisterMockPtr()
        {
            if ( s_EnableTest ) s_MockPtr = new T();
        }

        template <typename T>
        static void DestroyMockPtr()
        {
            if ( s_EnableTest && s_MockPtr ) delete ( T* ) s_MockPtr;
        }

        template <typename T>
        static T* GetMockPtr()
        {
            return ( T* ) s_MockPtr;
        }

    public:
        inline static vkInterface* s_MockPtr = nullptr;

#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 1
        constexpr inline static bool s_EnableTest = true;
#else
        constexpr inline static bool s_EnableTest = false;
#endif
    };
}// namespace FikoEngine

#include "VulkanInterface_impl.hpp"