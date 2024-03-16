#include <vulkan/vulkan.hpp>

static vk::Result Begin( vk::CommandBuffer commandBuffer, const vk::CommandBufferBeginInfo* pBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.begin( pBeginInfo );
#else
    return s_MockPtr->_Begin( commandBuffer, pBeginInfo );
#endif
}

static vk::Result Begin( vk::CommandBuffer commandBuffer, const vk::CommandBufferBeginInfo& beginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.begin( beginInfo );
#else
    return s_MockPtr->_Begin( commandBuffer, beginInfo );
#endif
}

static vk::Result Reset( vk::CommandBuffer commandBuffer, vk::CommandBufferResetFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.reset( flags );
#else
    return s_MockPtr->_Reset( commandBuffer, flags );
#endif
}

static void BindPipeline( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                          vk::Pipeline pipeline ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindPipeline( pipelineBindPoint, pipeline );
#else
    s_MockPtr->_BindPipeline( commandBuffer, pipelineBindPoint, pipeline );
#endif
}

static void SetViewport( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                         const vk::Viewport* pViewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewport( firstViewport, viewportCount, pViewports );
#else
    s_MockPtr->_SetViewport( commandBuffer, firstViewport, viewportCount, pViewports );
#endif
}

static void SetViewport( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                         vk::ArrayProxy<const vk::Viewport> const& viewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewport( firstViewport, viewports );
#else
    s_MockPtr->_SetViewport( commandBuffer, firstViewport, viewports );
#endif
}

static void SetScissor( vk::CommandBuffer commandBuffer, uint32_t firstScissor, uint32_t scissorCount,
                        const vk::Rect2D* pScissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissor( firstScissor, scissorCount, pScissors );
#else
    s_MockPtr->_SetScissor( commandBuffer, firstScissor, scissorCount, pScissors );
#endif
}

static void SetScissor( vk::CommandBuffer commandBuffer, uint32_t firstScissor,
                        vk::ArrayProxy<const vk::Rect2D> const& scissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissor( firstScissor, scissors );
#else
    s_MockPtr->_SetScissor( commandBuffer, firstScissor, scissors );
#endif
}

static void SetLineWidth( vk::CommandBuffer commandBuffer, float lineWidth ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLineWidth( lineWidth );
#else
    s_MockPtr->_SetLineWidth( commandBuffer, lineWidth );
#endif
}

static void SetDepthBias( vk::CommandBuffer commandBuffer, float depthBiasConstantFactor, float depthBiasClamp,
                          float depthBiasSlopeFactor ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBias( depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor );
#else
    s_MockPtr->_SetDepthBias( commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor );
#endif
}

static void SetBlendConstants( vk::CommandBuffer commandBuffer, const float blendConstants[ 4 ] ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setBlendConstants( blendConstants );
#else
    s_MockPtr->_SetBlendConstants( commandBuffer, blendConstants );
#endif
}

static void SetDepthBounds( vk::CommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBounds( minDepthBounds, maxDepthBounds );
#else
    s_MockPtr->_SetDepthBounds( commandBuffer, minDepthBounds, maxDepthBounds );
#endif
}

static void SetStencilCompareMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                   uint32_t compareMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilCompareMask( faceMask, compareMask );
#else
    s_MockPtr->_SetStencilCompareMask( commandBuffer, faceMask, compareMask );
#endif
}

static void SetStencilWriteMask( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                 uint32_t writeMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilWriteMask( faceMask, writeMask );
#else
    s_MockPtr->_SetStencilWriteMask( commandBuffer, faceMask, writeMask );
#endif
}

static void SetStencilReference( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask,
                                 uint32_t reference ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilReference( faceMask, reference );
#else
    s_MockPtr->_SetStencilReference( commandBuffer, faceMask, reference );
#endif
}

static void BindDescriptorSets( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                vk::PipelineLayout layout, uint32_t firstSet, uint32_t descriptorSetCount,
                                const vk::DescriptorSet* pDescriptorSets, uint32_t dynamicOffsetCount,
                                const uint32_t* pDynamicOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindDescriptorSets( pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets,
                                      dynamicOffsetCount, pDynamicOffsets );
#else
    s_MockPtr->_BindDescriptorSets( commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                                    pDescriptorSets, dynamicOffsetCount, pDynamicOffsets );
#endif
}

static void BindDescriptorSets( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                vk::PipelineLayout layout, uint32_t firstSet,
                                vk::ArrayProxy<const vk::DescriptorSet> const& descriptorSets,
                                vk::ArrayProxy<const uint32_t> const& dynamicOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindDescriptorSets( pipelineBindPoint, layout, firstSet, descriptorSets, dynamicOffsets );
#else
    s_MockPtr->_BindDescriptorSets( commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSets,
                                    dynamicOffsets );
#endif
}

static void BindIndexBuffer( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                             vk::IndexType indexType ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindIndexBuffer( buffer, offset, indexType );
#else
    s_MockPtr->_BindIndexBuffer( commandBuffer, buffer, offset, indexType );
#endif
}

static void BindVertexBuffers( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                               const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers( firstBinding, bindingCount, pBuffers, pOffsets );
#else
    s_MockPtr->_BindVertexBuffers( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets );
#endif
}

static void BindVertexBuffers( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                               vk::ArrayProxy<const vk::Buffer> const& buffers,
                               vk::ArrayProxy<const vk::DeviceSize> const& offsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers( firstBinding, buffers, offsets );
#else
    s_MockPtr->_BindVertexBuffers( commandBuffer, firstBinding, buffers, offsets );
#endif
}

static void Draw( vk::CommandBuffer commandBuffer, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                  uint32_t firstInstance ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.draw( vertexCount, instanceCount, firstVertex, firstInstance );
#else
    s_MockPtr->_Draw( commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance );
#endif
}

static void DrawIndexed( vk::CommandBuffer commandBuffer, uint32_t indexCount, uint32_t instanceCount,
                         uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndexed( indexCount, instanceCount, firstIndex, vertexOffset, firstInstance );
#else
    s_MockPtr->_DrawIndexed( commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance );
#endif
}

static void DrawIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset, uint32_t drawCount,
                          uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndirect( buffer, offset, drawCount, stride );
#else
    s_MockPtr->_DrawIndirect( commandBuffer, buffer, offset, drawCount, stride );
#endif
}

static void DrawIndexedIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                 uint32_t drawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndexedIndirect( buffer, offset, drawCount, stride );
#else
    s_MockPtr->_DrawIndexedIndirect( commandBuffer, buffer, offset, drawCount, stride );
#endif
}

static void Dispatch( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                      uint32_t groupCountZ ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.dispatch( groupCountX, groupCountY, groupCountZ );
#else
    s_MockPtr->_Dispatch( commandBuffer, groupCountX, groupCountY, groupCountZ );
#endif
}

static void DispatchIndirect( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.dispatchIndirect( buffer, offset );
#else
    s_MockPtr->_DispatchIndirect( commandBuffer, buffer, offset );
#endif
}

static void CopyBuffer( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Buffer dstBuffer,
                        uint32_t regionCount, const vk::BufferCopy* pRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer( srcBuffer, dstBuffer, regionCount, pRegions );
#else
    s_MockPtr->_CopyBuffer( commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions );
#endif
}

static void CopyBuffer( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Buffer dstBuffer,
                        vk::ArrayProxy<const vk::BufferCopy> const& regions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer( srcBuffer, dstBuffer, regions );
#else
    s_MockPtr->_CopyBuffer( commandBuffer, srcBuffer, dstBuffer, regions );
#endif
}

static void CopyImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                       vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                       const vk::ImageCopy* pRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
#else
    s_MockPtr->_CopyImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
#endif
}

static void CopyImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                       vk::Image dstImage, vk::ImageLayout dstImageLayout,
                       vk::ArrayProxy<const vk::ImageCopy> const& regions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regions );
#else
    s_MockPtr->_CopyImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regions );
#endif
}

static void BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                       vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                       const vk::ImageBlit* pRegions, vk::Filter filter ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter );
#else
    s_MockPtr->_BlitImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions,
                           filter );
#endif
}

static void BlitImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                       vk::Image dstImage, vk::ImageLayout dstImageLayout,
                       vk::ArrayProxy<const vk::ImageBlit> const& regions, vk::Filter filter ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regions, filter );
#else
    s_MockPtr->_BlitImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regions, filter );
#endif
}

static void CopyBufferToImage( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Image dstImage,
                               vk::ImageLayout dstImageLayout, uint32_t regionCount,
                               const vk::BufferImageCopy* pRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage( srcBuffer, dstImage, dstImageLayout, regionCount, pRegions );
#else
    s_MockPtr->_CopyBufferToImage( commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions );
#endif
}

static void CopyBufferToImage( vk::CommandBuffer commandBuffer, vk::Buffer srcBuffer, vk::Image dstImage,
                               vk::ImageLayout dstImageLayout,
                               vk::ArrayProxy<const vk::BufferImageCopy> const& regions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage( srcBuffer, dstImage, dstImageLayout, regions );
#else
    s_MockPtr->_CopyBufferToImage( commandBuffer, srcBuffer, dstImage, dstImageLayout, regions );
#endif
}

static void CopyImageToBuffer( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                               vk::Buffer dstBuffer, uint32_t regionCount, const vk::BufferImageCopy* pRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer( srcImage, srcImageLayout, dstBuffer, regionCount, pRegions );
#else
    s_MockPtr->_CopyImageToBuffer( commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions );
#endif
}

static void CopyImageToBuffer( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                               vk::Buffer dstBuffer, vk::ArrayProxy<const vk::BufferImageCopy> const& regions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer( srcImage, srcImageLayout, dstBuffer, regions );
#else
    s_MockPtr->_CopyImageToBuffer( commandBuffer, srcImage, srcImageLayout, dstBuffer, regions );
#endif
}

static void UpdateBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                          vk::DeviceSize dataSize, const void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.updateBuffer( dstBuffer, dstOffset, dataSize, pData );
#else
    s_MockPtr->_UpdateBuffer( commandBuffer, dstBuffer, dstOffset, dataSize, pData );
#endif
}

template <typename DataType>
static void UpdateBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                          vk::ArrayProxy<const DataType> const& data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.updateBuffer( dstBuffer, dstOffset, data );
#else
    s_MockPtr->_UpdateBuffer( commandBuffer, dstBuffer, dstOffset, data );
#endif
}

static void FillBuffer( vk::CommandBuffer commandBuffer, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                        vk::DeviceSize size, uint32_t data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.fillBuffer( dstBuffer, dstOffset, size, data );
#else
    s_MockPtr->_FillBuffer( commandBuffer, dstBuffer, dstOffset, size, data );
#endif
}

static void ClearColorImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                             const vk::ClearColorValue* pColor, uint32_t rangeCount,
                             const vk::ImageSubresourceRange* pRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearColorImage( image, imageLayout, pColor, rangeCount, pRanges );
#else
    s_MockPtr->_ClearColorImage( commandBuffer, image, imageLayout, pColor, rangeCount, pRanges );
#endif
}

static void ClearColorImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                             const vk::ClearColorValue& color,
                             vk::ArrayProxy<const vk::ImageSubresourceRange> const& ranges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearColorImage( image, imageLayout, color, ranges );
#else
    s_MockPtr->_ClearColorImage( commandBuffer, image, imageLayout, color, ranges );
#endif
}

static void ClearDepthStencilImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                                    const vk::ClearDepthStencilValue* pDepthStencil, uint32_t rangeCount,
                                    const vk::ImageSubresourceRange* pRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearDepthStencilImage( image, imageLayout, pDepthStencil, rangeCount, pRanges );
#else
    s_MockPtr->_ClearDepthStencilImage( commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges );
#endif
}

static void ClearDepthStencilImage( vk::CommandBuffer commandBuffer, vk::Image image, vk::ImageLayout imageLayout,
                                    const vk::ClearDepthStencilValue& depthStencil,
                                    vk::ArrayProxy<const vk::ImageSubresourceRange> const& ranges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearDepthStencilImage( image, imageLayout, depthStencil, ranges );
#else
    s_MockPtr->_ClearDepthStencilImage( commandBuffer, image, imageLayout, depthStencil, ranges );
#endif
}

static void ClearAttachments( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                              const vk::ClearAttachment* pAttachments, uint32_t rectCount,
                              const vk::ClearRect* pRects ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearAttachments( attachmentCount, pAttachments, rectCount, pRects );
#else
    s_MockPtr->_ClearAttachments( commandBuffer, attachmentCount, pAttachments, rectCount, pRects );
#endif
}

static void ClearAttachments( vk::CommandBuffer commandBuffer,
                              vk::ArrayProxy<const vk::ClearAttachment> const& attachments,
                              vk::ArrayProxy<const vk::ClearRect> const& rects ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.clearAttachments( attachments, rects );
#else
    s_MockPtr->_ClearAttachments( commandBuffer, attachments, rects );
#endif
}

static void ResolveImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                          vk::Image dstImage, vk::ImageLayout dstImageLayout, uint32_t regionCount,
                          const vk::ImageResolve* pRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions );
#else
    s_MockPtr->_ResolveImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount,
                              pRegions );
#endif
}

static void ResolveImage( vk::CommandBuffer commandBuffer, vk::Image srcImage, vk::ImageLayout srcImageLayout,
                          vk::Image dstImage, vk::ImageLayout dstImageLayout,
                          vk::ArrayProxy<const vk::ImageResolve> const& regions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage( srcImage, srcImageLayout, dstImage, dstImageLayout, regions );
#else
    s_MockPtr->_ResolveImage( commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regions );
#endif
}

static void SetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setEvent( event, stageMask );
#else
    s_MockPtr->_SetEvent( commandBuffer, event, stageMask );
#endif
}

static void ResetEvent( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags stageMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resetEvent( event, stageMask );
#else
    s_MockPtr->_ResetEvent( commandBuffer, event, stageMask );
#endif
}

static void WaitEvents( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                        vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask,
                        uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                        uint32_t bufferMemoryBarrierCount, const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                        uint32_t imageMemoryBarrierCount, const vk::ImageMemoryBarrier* pImageMemoryBarriers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents( eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers,
                              bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                              pImageMemoryBarriers );
#else
    s_MockPtr->_WaitEvents( commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount,
                            pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                            pImageMemoryBarriers );
#endif
}

static void WaitEvents( vk::CommandBuffer commandBuffer, vk::ArrayProxy<const vk::Event> const& events,
                        vk::PipelineStageFlags srcStageMask, vk::PipelineStageFlags dstStageMask,
                        vk::ArrayProxy<const vk::MemoryBarrier> const& memoryBarriers,
                        vk::ArrayProxy<const vk::BufferMemoryBarrier> const& bufferMemoryBarriers,
                        vk::ArrayProxy<const vk::ImageMemoryBarrier> const& imageMemoryBarriers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents( events, srcStageMask, dstStageMask, memoryBarriers, bufferMemoryBarriers,
                              imageMemoryBarriers );
#else
    s_MockPtr->_WaitEvents( commandBuffer, events, srcStageMask, dstStageMask, memoryBarriers, bufferMemoryBarriers,
                            imageMemoryBarriers );
#endif
}

static void PipelineBarrier( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags srcStageMask,
                             vk::PipelineStageFlags dstStageMask, vk::DependencyFlags dependencyFlags,
                             uint32_t memoryBarrierCount, const vk::MemoryBarrier* pMemoryBarriers,
                             uint32_t bufferMemoryBarrierCount, const vk::BufferMemoryBarrier* pBufferMemoryBarriers,
                             uint32_t imageMemoryBarrierCount,
                             const vk::ImageMemoryBarrier* pImageMemoryBarriers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier( srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers,
                                   bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount,
                                   pImageMemoryBarriers );
#else
    s_MockPtr->_PipelineBarrier( commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                                 pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                                 imageMemoryBarrierCount, pImageMemoryBarriers );
#endif
}

static void PipelineBarrier( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags srcStageMask,
                             vk::PipelineStageFlags dstStageMask, vk::DependencyFlags dependencyFlags,
                             vk::ArrayProxy<const vk::MemoryBarrier> const& memoryBarriers,
                             vk::ArrayProxy<const vk::BufferMemoryBarrier> const& bufferMemoryBarriers,
                             vk::ArrayProxy<const vk::ImageMemoryBarrier> const& imageMemoryBarriers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier( srcStageMask, dstStageMask, dependencyFlags, memoryBarriers, bufferMemoryBarriers,
                                   imageMemoryBarriers );
#else
    s_MockPtr->_PipelineBarrier( commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarriers,
                                 bufferMemoryBarriers, imageMemoryBarriers );
#endif
}

static void BeginQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                        vk::QueryControlFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginQuery( queryPool, query, flags );
#else
    s_MockPtr->_BeginQuery( commandBuffer, queryPool, query, flags );
#endif
}

static void EndQuery( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endQuery( queryPool, query );
#else
    s_MockPtr->_EndQuery( commandBuffer, queryPool, query );
#endif
}

static void ResetQueryPool( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery,
                            uint32_t queryCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resetQueryPool( queryPool, firstQuery, queryCount );
#else
    s_MockPtr->_ResetQueryPool( commandBuffer, queryPool, firstQuery, queryCount );
#endif
}

static void WriteTimestamp( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                            vk::QueryPool queryPool, uint32_t query ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeTimestamp( pipelineStage, queryPool, query );
#else
    s_MockPtr->_WriteTimestamp( commandBuffer, pipelineStage, queryPool, query );
#endif
}

static void CopyQueryPoolResults( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t firstQuery,
                                  uint32_t queryCount, vk::Buffer dstBuffer, vk::DeviceSize dstOffset,
                                  vk::DeviceSize stride, vk::QueryResultFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyQueryPoolResults( queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags );
#else
    s_MockPtr->_CopyQueryPoolResults( commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride,
                                      flags );
#endif
}

static void PushConstants( vk::CommandBuffer commandBuffer, vk::PipelineLayout layout, vk::ShaderStageFlags stageFlags,
                           uint32_t offset, uint32_t size, const void* pValues ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushConstants( layout, stageFlags, offset, size, pValues );
#else
    s_MockPtr->_PushConstants( commandBuffer, layout, stageFlags, offset, size, pValues );
#endif
}

template <typename ValuesType>
static void PushConstants( vk::CommandBuffer commandBuffer, vk::PipelineLayout layout, vk::ShaderStageFlags stageFlags,
                           uint32_t offset, vk::ArrayProxy<const ValuesType> const& values ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushConstants( layout, stageFlags, offset, values );
#else
    s_MockPtr->_PushConstants( commandBuffer, layout, stageFlags, offset, values );
#endif
}

static void BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                             vk::SubpassContents contents ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass( pRenderPassBegin, contents );
#else
    s_MockPtr->_BeginRenderPass( commandBuffer, pRenderPassBegin, contents );
#endif
}

static void BeginRenderPass( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo& renderPassBegin,
                             vk::SubpassContents contents ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass( renderPassBegin, contents );
#else
    s_MockPtr->_BeginRenderPass( commandBuffer, renderPassBegin, contents );
#endif
}

static void NextSubpass( vk::CommandBuffer commandBuffer, vk::SubpassContents contents ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.nextSubpass( contents );
#else
    s_MockPtr->_NextSubpass( commandBuffer, contents );
#endif
}

static void EndRenderPass( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderPass();
#else
    s_MockPtr->_EndRenderPass();
#endif
}

static void ExecuteCommands( vk::CommandBuffer commandBuffer, uint32_t commandBufferCount,
                             const vk::CommandBuffer* pCommandBuffers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.executeCommands( commandBufferCount, pCommandBuffers );
#else
    s_MockPtr->_ExecuteCommands( commandBuffer, commandBufferCount, pCommandBuffers );
#endif
}

static void ExecuteCommands( vk::CommandBuffer commandBuffer,
                             vk::ArrayProxy<const vk::CommandBuffer> const& commandBuffers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.executeCommands( commandBuffers );
#else
    s_MockPtr->_ExecuteCommands( commandBuffer, commandBuffers );
#endif
}

static void SetDeviceMask( vk::CommandBuffer commandBuffer, uint32_t deviceMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDeviceMask( deviceMask );
#else
    s_MockPtr->_SetDeviceMask( commandBuffer, deviceMask );
#endif
}

static void DispatchBase( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                          uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.dispatchBase( baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
#else
    s_MockPtr->_DispatchBase( commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                              groupCountZ );
#endif
}

static void DrawIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                               vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                               uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndirectCount( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndirectCount( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                   stride );
#endif
}

static void DrawIndexedIndirectCount( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                      vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                      uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndexedIndirectCount( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndexedIndirectCount( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                          stride );
#endif
}

static void BeginRenderPass2( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                              const vk::SubpassBeginInfo* pSubpassBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass2( pRenderPassBegin, pSubpassBeginInfo );
#else
    s_MockPtr->_BeginRenderPass2( commandBuffer, pRenderPassBegin, pSubpassBeginInfo );
#endif
}

static void BeginRenderPass2( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo& renderPassBegin,
                              const vk::SubpassBeginInfo& subpassBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass2( renderPassBegin, subpassBeginInfo );
#else
    s_MockPtr->_BeginRenderPass2( commandBuffer, renderPassBegin, subpassBeginInfo );
#endif
}

static void NextSubpass2( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                          const vk::SubpassEndInfo* pSubpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.nextSubpass2( pSubpassBeginInfo, pSubpassEndInfo );
#else
    s_MockPtr->_NextSubpass2( commandBuffer, pSubpassBeginInfo, pSubpassEndInfo );
#endif
}

static void NextSubpass2( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo& subpassBeginInfo,
                          const vk::SubpassEndInfo& subpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.nextSubpass2( subpassBeginInfo, subpassEndInfo );
#else
    s_MockPtr->_NextSubpass2( commandBuffer, subpassBeginInfo, subpassEndInfo );
#endif
}

static void EndRenderPass2( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderPass2( pSubpassEndInfo );
#else
    s_MockPtr->_EndRenderPass2( commandBuffer, pSubpassEndInfo );
#endif
}

static void EndRenderPass2( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo& subpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderPass2( subpassEndInfo );
#else
    s_MockPtr->_EndRenderPass2( commandBuffer, subpassEndInfo );
#endif
}

static void SetEvent2( vk::CommandBuffer commandBuffer, vk::Event event,
                       const vk::DependencyInfo* pDependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setEvent2( event, pDependencyInfo );
#else
    s_MockPtr->_SetEvent2( commandBuffer, event, pDependencyInfo );
#endif
}

static void SetEvent2( vk::CommandBuffer commandBuffer, vk::Event event,
                       const vk::DependencyInfo& dependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setEvent2( event, dependencyInfo );
#else
    s_MockPtr->_SetEvent2( commandBuffer, event, dependencyInfo );
#endif
}

static void ResetEvent2( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags2 stageMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resetEvent2( event, stageMask );
#else
    s_MockPtr->_ResetEvent2( commandBuffer, event, stageMask );
#endif
}

static void WaitEvents2( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                         const vk::DependencyInfo* pDependencyInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents2( eventCount, pEvents, pDependencyInfos );
#else
    s_MockPtr->_WaitEvents2( commandBuffer, eventCount, pEvents, pDependencyInfos );
#endif
}

static void WaitEvents2( vk::CommandBuffer commandBuffer, vk::ArrayProxy<const vk::Event> const& events,
                         vk::ArrayProxy<const vk::DependencyInfo> const& dependencyInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents2( events, dependencyInfos );
#else
    s_MockPtr->_WaitEvents2( commandBuffer, events, dependencyInfos );
#endif
}

static void PipelineBarrier2( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier2( pDependencyInfo );
#else
    s_MockPtr->_PipelineBarrier2( commandBuffer, pDependencyInfo );
#endif
}

static void PipelineBarrier2( vk::CommandBuffer commandBuffer, const vk::DependencyInfo& dependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier2( dependencyInfo );
#else
    s_MockPtr->_PipelineBarrier2( commandBuffer, dependencyInfo );
#endif
}

static void WriteTimestamp2( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::QueryPool queryPool,
                             uint32_t query ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeTimestamp2( stage, queryPool, query );
#else
    s_MockPtr->_WriteTimestamp2( commandBuffer, stage, queryPool, query );
#endif
}

static void CopyBuffer2( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer2( pCopyBufferInfo );
#else
    s_MockPtr->_CopyBuffer2( commandBuffer, pCopyBufferInfo );
#endif
}

static void CopyBuffer2( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2& copyBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer2( copyBufferInfo );
#else
    s_MockPtr->_CopyBuffer2( commandBuffer, copyBufferInfo );
#endif
}

static void CopyImage2( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage2( pCopyImageInfo );
#else
    s_MockPtr->_CopyImage2( commandBuffer, pCopyImageInfo );
#endif
}

static void CopyImage2( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2& copyImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage2( copyImageInfo );
#else
    s_MockPtr->_CopyImage2( commandBuffer, copyImageInfo );
#endif
}

static void CopyBufferToImage2( vk::CommandBuffer commandBuffer,
                                const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage2( pCopyBufferToImageInfo );
#else
    s_MockPtr->_CopyBufferToImage2( commandBuffer, pCopyBufferToImageInfo );
#endif
}

static void CopyBufferToImage2( vk::CommandBuffer commandBuffer,
                                const vk::CopyBufferToImageInfo2& copyBufferToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage2( copyBufferToImageInfo );
#else
    s_MockPtr->_CopyBufferToImage2( commandBuffer, copyBufferToImageInfo );
#endif
}

static void CopyImageToBuffer2( vk::CommandBuffer commandBuffer,
                                const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer2( pCopyImageToBufferInfo );
#else
    s_MockPtr->_CopyImageToBuffer2( commandBuffer, pCopyImageToBufferInfo );
#endif
}

static void CopyImageToBuffer2( vk::CommandBuffer commandBuffer,
                                const vk::CopyImageToBufferInfo2& copyImageToBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer2( copyImageToBufferInfo );
#else
    s_MockPtr->_CopyImageToBuffer2( commandBuffer, copyImageToBufferInfo );
#endif
}

static void BlitImage2( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage2( pBlitImageInfo );
#else
    s_MockPtr->_BlitImage2( commandBuffer, pBlitImageInfo );
#endif
}

static void BlitImage2( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2& blitImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage2( blitImageInfo );
#else
    s_MockPtr->_BlitImage2( commandBuffer, blitImageInfo );
#endif
}

static void ResolveImage2( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage2( pResolveImageInfo );
#else
    s_MockPtr->_ResolveImage2( commandBuffer, pResolveImageInfo );
#endif
}

static void ResolveImage2( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2& resolveImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage2( resolveImageInfo );
#else
    s_MockPtr->_ResolveImage2( commandBuffer, resolveImageInfo );
#endif
}

static void BeginRendering( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRendering( pRenderingInfo );
#else
    s_MockPtr->_BeginRendering( commandBuffer, pRenderingInfo );
#endif
}

static void BeginRendering( vk::CommandBuffer commandBuffer, const vk::RenderingInfo& renderingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRendering( renderingInfo );
#else
    s_MockPtr->_BeginRendering( commandBuffer, renderingInfo );
#endif
}

static void EndRendering( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRendering();
#else
    s_MockPtr->_EndRendering();
#endif
}

static void SetCullMode( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCullMode( cullMode );
#else
    s_MockPtr->_SetCullMode( commandBuffer, cullMode );
#endif
}

static void SetFrontFace( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setFrontFace( frontFace );
#else
    s_MockPtr->_SetFrontFace( commandBuffer, frontFace );
#endif
}

static void SetPrimitiveTopology( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPrimitiveTopology( primitiveTopology );
#else
    s_MockPtr->_SetPrimitiveTopology( commandBuffer, primitiveTopology );
#endif
}

static void SetViewportWithCount( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                  const vk::Viewport* pViewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWithCount( viewportCount, pViewports );
#else
    s_MockPtr->_SetViewportWithCount( commandBuffer, viewportCount, pViewports );
#endif
}

static void SetViewportWithCount( vk::CommandBuffer commandBuffer,
                                  vk::ArrayProxy<const vk::Viewport> const& viewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWithCount( viewports );
#else
    s_MockPtr->_SetViewportWithCount( commandBuffer, viewports );
#endif
}

static void SetScissorWithCount( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                 const vk::Rect2D* pScissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissorWithCount( scissorCount, pScissors );
#else
    s_MockPtr->_SetScissorWithCount( commandBuffer, scissorCount, pScissors );
#endif
}

static void SetScissorWithCount( vk::CommandBuffer commandBuffer,
                                 vk::ArrayProxy<const vk::Rect2D> const& scissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissorWithCount( scissors );
#else
    s_MockPtr->_SetScissorWithCount( commandBuffer, scissors );
#endif
}

static void BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets,
                                const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers2( firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
#else
    s_MockPtr->_BindVertexBuffers2( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
#endif
}

static void BindVertexBuffers2( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                vk::ArrayProxy<const vk::Buffer> const& buffers,
                                vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                vk::ArrayProxy<const vk::DeviceSize> const& sizes = nullptr,
                                vk::ArrayProxy<const vk::DeviceSize> const& strides = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers2( firstBinding, buffers, offsets, nullptr, nullptr );
#else
    s_MockPtr->_BindVertexBuffers2( commandBuffer, firstBinding, buffers, offsets, nullptr, nullptr );
#endif
}

static void SetDepthTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthTestEnable( depthTestEnable );
#else
    s_MockPtr->_SetDepthTestEnable( commandBuffer, depthTestEnable );
#endif
}

static void SetDepthWriteEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthWriteEnable( depthWriteEnable );
#else
    s_MockPtr->_SetDepthWriteEnable( commandBuffer, depthWriteEnable );
#endif
}

static void SetDepthCompareOp( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthCompareOp( depthCompareOp );
#else
    s_MockPtr->_SetDepthCompareOp( commandBuffer, depthCompareOp );
#endif
}

static void SetDepthBoundsTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBoundsTestEnable( depthBoundsTestEnable );
#else
    s_MockPtr->_SetDepthBoundsTestEnable( commandBuffer, depthBoundsTestEnable );
#endif
}

static void SetStencilTestEnable( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilTestEnable( stencilTestEnable );
#else
    s_MockPtr->_SetStencilTestEnable( commandBuffer, stencilTestEnable );
#endif
}

static void SetStencilOp( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, vk::StencilOp failOp,
                          vk::StencilOp passOp, vk::StencilOp depthFailOp, vk::CompareOp compareOp ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilOp( faceMask, failOp, passOp, depthFailOp, compareOp );
#else
    s_MockPtr->_SetStencilOp( commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp );
#endif
}

static void SetRasterizerDiscardEnable( vk::CommandBuffer commandBuffer, vk::Bool32 rasterizerDiscardEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRasterizerDiscardEnable( rasterizerDiscardEnable );
#else
    s_MockPtr->_SetRasterizerDiscardEnable( commandBuffer, rasterizerDiscardEnable );
#endif
}

static void SetDepthBiasEnable( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBiasEnable( depthBiasEnable );
#else
    s_MockPtr->_SetDepthBiasEnable( commandBuffer, depthBiasEnable );
#endif
}

static void SetPrimitiveRestartEnable( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPrimitiveRestartEnable( primitiveRestartEnable );
#else
    s_MockPtr->_SetPrimitiveRestartEnable( commandBuffer, primitiveRestartEnable );
#endif
}

static void DebugMarkerBeginEXT( vk::CommandBuffer commandBuffer,
                                 const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.debugMarkerBeginEXT( pMarkerInfo );
#else
    s_MockPtr->_DebugMarkerBeginEXT( commandBuffer, pMarkerInfo );
#endif
}

static void DebugMarkerBeginEXT( vk::CommandBuffer commandBuffer, const vk::DebugMarkerMarkerInfoEXT& markerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.debugMarkerBeginEXT( markerInfo );
#else
    s_MockPtr->_DebugMarkerBeginEXT( commandBuffer, markerInfo );
#endif
}

static void DebugMarkerEndEXT( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.debugMarkerEndEXT();
#else
    s_MockPtr->_DebugMarkerEndEXT();
#endif
}

static void DebugMarkerInsertEXT( vk::CommandBuffer commandBuffer,
                                  const vk::DebugMarkerMarkerInfoEXT* pMarkerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.debugMarkerInsertEXT( pMarkerInfo );
#else
    s_MockPtr->_DebugMarkerInsertEXT( commandBuffer, pMarkerInfo );
#endif
}

static void DebugMarkerInsertEXT( vk::CommandBuffer commandBuffer,
                                  const vk::DebugMarkerMarkerInfoEXT& markerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.debugMarkerInsertEXT( markerInfo );
#else
    s_MockPtr->_DebugMarkerInsertEXT( commandBuffer, markerInfo );
#endif
}

static void BeginVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoBeginCodingInfoKHR* pBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginVideoCodingKHR( pBeginInfo );
#else
    s_MockPtr->_BeginVideoCodingKHR( commandBuffer, pBeginInfo );
#endif
}

static void BeginVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoBeginCodingInfoKHR& beginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginVideoCodingKHR( beginInfo );
#else
    s_MockPtr->_BeginVideoCodingKHR( commandBuffer, beginInfo );
#endif
}

static void EndVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoEndCodingInfoKHR* pEndCodingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endVideoCodingKHR( pEndCodingInfo );
#else
    s_MockPtr->_EndVideoCodingKHR( commandBuffer, pEndCodingInfo );
#endif
}

static void EndVideoCodingKHR( vk::CommandBuffer commandBuffer, const vk::VideoEndCodingInfoKHR& endCodingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endVideoCodingKHR( endCodingInfo );
#else
    s_MockPtr->_EndVideoCodingKHR( commandBuffer, endCodingInfo );
#endif
}

static void ControlVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                   const vk::VideoCodingControlInfoKHR* pCodingControlInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.controlVideoCodingKHR( pCodingControlInfo );
#else
    s_MockPtr->_ControlVideoCodingKHR( commandBuffer, pCodingControlInfo );
#endif
}

static void ControlVideoCodingKHR( vk::CommandBuffer commandBuffer,
                                   const vk::VideoCodingControlInfoKHR& codingControlInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.controlVideoCodingKHR( codingControlInfo );
#else
    s_MockPtr->_ControlVideoCodingKHR( commandBuffer, codingControlInfo );
#endif
}

static void DecodeVideoKHR( vk::CommandBuffer commandBuffer, const vk::VideoDecodeInfoKHR* pDecodeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.decodeVideoKHR( pDecodeInfo );
#else
    s_MockPtr->_DecodeVideoKHR( commandBuffer, pDecodeInfo );
#endif
}

static void DecodeVideoKHR( vk::CommandBuffer commandBuffer, const vk::VideoDecodeInfoKHR& decodeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.decodeVideoKHR( decodeInfo );
#else
    s_MockPtr->_DecodeVideoKHR( commandBuffer, decodeInfo );
#endif
}

static void BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                             uint32_t bindingCount, const vk::Buffer* pBuffers,
                                             const vk::DeviceSize* pOffsets, const vk::DeviceSize* pSizes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindTransformFeedbackBuffersEXT( firstBinding, bindingCount, pBuffers, pOffsets, pSizes );
#else
    s_MockPtr->_BindTransformFeedbackBuffersEXT( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets,
                                                 pSizes );
#endif
}

static void BindTransformFeedbackBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                             vk::ArrayProxy<const vk::Buffer> const& buffers,
                                             vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                             vk::ArrayProxy<const vk::DeviceSize> const& sizes = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindTransformFeedbackBuffersEXT( firstBinding, buffers, offsets, nullptr );
#else
    s_MockPtr->_BindTransformFeedbackBuffersEXT( commandBuffer, firstBinding, buffers, offsets, nullptr );
#endif
}

static void BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                       uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                       const vk::DeviceSize* pCounterBufferOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginTransformFeedbackEXT( firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                             pCounterBufferOffsets );
#else
    s_MockPtr->_BeginTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                           pCounterBufferOffsets );
#endif
}

static void BeginTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                       vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                       vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginTransformFeedbackEXT( firstCounterBuffer, counterBuffers, nullptr );
#else
    s_MockPtr->_BeginTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBuffers, nullptr );
#endif
}

static void EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                     uint32_t counterBufferCount, const vk::Buffer* pCounterBuffers,
                                     const vk::DeviceSize* pCounterBufferOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endTransformFeedbackEXT( firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                           pCounterBufferOffsets );
#else
    s_MockPtr->_EndTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBufferCount, pCounterBuffers,
                                         pCounterBufferOffsets );
#endif
}

static void EndTransformFeedbackEXT( vk::CommandBuffer commandBuffer, uint32_t firstCounterBuffer,
                                     vk::ArrayProxy<const vk::Buffer> const& counterBuffers,
                                     vk::ArrayProxy<const vk::DeviceSize> const& counterBufferOffsets = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endTransformFeedbackEXT( firstCounterBuffer, counterBuffers, nullptr );
#else
    s_MockPtr->_EndTransformFeedbackEXT( commandBuffer, firstCounterBuffer, counterBuffers, nullptr );
#endif
}

static void BeginQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                  vk::QueryControlFlags flags, uint32_t index ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginQueryIndexedEXT( queryPool, query, flags, index );
#else
    s_MockPtr->_BeginQueryIndexedEXT( commandBuffer, queryPool, query, flags, index );
#endif
}

static void EndQueryIndexedEXT( vk::CommandBuffer commandBuffer, vk::QueryPool queryPool, uint32_t query,
                                uint32_t index ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endQueryIndexedEXT( queryPool, query, index );
#else
    s_MockPtr->_EndQueryIndexedEXT( commandBuffer, queryPool, query, index );
#endif
}

static void DrawIndirectByteCountEXT( vk::CommandBuffer commandBuffer, uint32_t instanceCount, uint32_t firstInstance,
                                      vk::Buffer counterBuffer, vk::DeviceSize counterBufferOffset,
                                      uint32_t counterOffset, uint32_t vertexStride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndirectByteCountEXT( instanceCount, firstInstance, counterBuffer, counterBufferOffset,
                                            counterOffset, vertexStride );
#else
    s_MockPtr->_DrawIndirectByteCountEXT( commandBuffer, instanceCount, firstInstance, counterBuffer,
                                          counterBufferOffset, counterOffset, vertexStride );
#endif
}

static void CuLaunchKernelNVX( vk::CommandBuffer commandBuffer, const vk::CuLaunchInfoNVX* pLaunchInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.cuLaunchKernelNVX( pLaunchInfo );
#else
    s_MockPtr->_CuLaunchKernelNVX( commandBuffer, pLaunchInfo );
#endif
}

static void CuLaunchKernelNVX( vk::CommandBuffer commandBuffer, const vk::CuLaunchInfoNVX& launchInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.cuLaunchKernelNVX( launchInfo );
#else
    s_MockPtr->_CuLaunchKernelNVX( commandBuffer, launchInfo );
#endif
}

static void DrawIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                  vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                  uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndirectCountAMD( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndirectCountAMD( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                      stride );
#endif
}

static void DrawIndexedIndirectCountAMD( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                         vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                         uint32_t maxDrawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndexedIndirectCountAMD( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndexedIndirectCountAMD( commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride );
#endif
}

static void BeginRenderingKHR( vk::CommandBuffer commandBuffer, const vk::RenderingInfo* pRenderingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderingKHR( pRenderingInfo );
#else
    s_MockPtr->_BeginRenderingKHR( commandBuffer, pRenderingInfo );
#endif
}

static void BeginRenderingKHR( vk::CommandBuffer commandBuffer, const vk::RenderingInfo& renderingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderingKHR( renderingInfo );
#else
    s_MockPtr->_BeginRenderingKHR( commandBuffer, renderingInfo );
#endif
}

static void EndRenderingKHR( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderingKHR();
#else
    s_MockPtr->_EndRenderingKHR();
#endif
}

static void SetDeviceMaskKHR( vk::CommandBuffer commandBuffer, uint32_t deviceMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDeviceMaskKHR( deviceMask );
#else
    s_MockPtr->_SetDeviceMaskKHR( commandBuffer, deviceMask );
#endif
}

static void DispatchBaseKHR( vk::CommandBuffer commandBuffer, uint32_t baseGroupX, uint32_t baseGroupY,
                             uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.dispatchBaseKHR( baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ );
#else
    s_MockPtr->_DispatchBaseKHR( commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY,
                                 groupCountZ );
#endif
}

static void PushDescriptorSetKHR( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                  vk::PipelineLayout layout, uint32_t set, uint32_t descriptorWriteCount,
                                  const vk::WriteDescriptorSet* pDescriptorWrites ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushDescriptorSetKHR( pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites );
#else
    s_MockPtr->_PushDescriptorSetKHR( commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount,
                                      pDescriptorWrites );
#endif
}

static void PushDescriptorSetKHR( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                  vk::PipelineLayout layout, uint32_t set,
                                  vk::ArrayProxy<const vk::WriteDescriptorSet> const& descriptorWrites ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushDescriptorSetKHR( pipelineBindPoint, layout, set, descriptorWrites );
#else
    s_MockPtr->_PushDescriptorSetKHR( commandBuffer, pipelineBindPoint, layout, set, descriptorWrites );
#endif
}

static void PushDescriptorSetWithTemplateKHR( vk::CommandBuffer commandBuffer,
                                              vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                              vk::PipelineLayout layout, uint32_t set, const void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushDescriptorSetWithTemplateKHR( descriptorUpdateTemplate, layout, set, pData );
#else
    s_MockPtr->_PushDescriptorSetWithTemplateKHR( commandBuffer, descriptorUpdateTemplate, layout, set, pData );
#endif
}

template <typename DataType>
static void PushDescriptorSetWithTemplateKHR( vk::CommandBuffer commandBuffer,
                                              vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                              vk::PipelineLayout layout, uint32_t set, DataType const& data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pushDescriptorSetWithTemplateKHR( descriptorUpdateTemplate, layout, set, data );
#else
    s_MockPtr->_PushDescriptorSetWithTemplateKHR( commandBuffer, descriptorUpdateTemplate, layout, set, data );
#endif
}

static void BeginConditionalRenderingEXT( vk::CommandBuffer commandBuffer,
                                          const vk::ConditionalRenderingBeginInfoEXT* pConditionalRenderingBegin ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginConditionalRenderingEXT( pConditionalRenderingBegin );
#else
    s_MockPtr->_BeginConditionalRenderingEXT( commandBuffer, pConditionalRenderingBegin );
#endif
}

static void BeginConditionalRenderingEXT( vk::CommandBuffer commandBuffer,
                                          const vk::ConditionalRenderingBeginInfoEXT& conditionalRenderingBegin ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginConditionalRenderingEXT( conditionalRenderingBegin );
#else
    s_MockPtr->_BeginConditionalRenderingEXT( commandBuffer, conditionalRenderingBegin );
#endif
}

static void EndConditionalRenderingEXT( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endConditionalRenderingEXT();
#else
    s_MockPtr->_EndConditionalRenderingEXT();
#endif
}

static void SetViewportWScalingNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                   const vk::ViewportWScalingNV* pViewportWScalings ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWScalingNV( firstViewport, viewportCount, pViewportWScalings );
#else
    s_MockPtr->_SetViewportWScalingNV( commandBuffer, firstViewport, viewportCount, pViewportWScalings );
#endif
}

static void SetViewportWScalingNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                   vk::ArrayProxy<const vk::ViewportWScalingNV> const& viewportWScalings ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWScalingNV( firstViewport, viewportWScalings );
#else
    s_MockPtr->_SetViewportWScalingNV( commandBuffer, firstViewport, viewportWScalings );
#endif
}

static void SetDiscardRectangleEXT( vk::CommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                    uint32_t discardRectangleCount, const vk::Rect2D* pDiscardRectangles ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDiscardRectangleEXT( firstDiscardRectangle, discardRectangleCount, pDiscardRectangles );
#else
    s_MockPtr->_SetDiscardRectangleEXT( commandBuffer, firstDiscardRectangle, discardRectangleCount,
                                        pDiscardRectangles );
#endif
}

static void SetDiscardRectangleEXT( vk::CommandBuffer commandBuffer, uint32_t firstDiscardRectangle,
                                    vk::ArrayProxy<const vk::Rect2D> const& discardRectangles ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDiscardRectangleEXT( firstDiscardRectangle, discardRectangles );
#else
    s_MockPtr->_SetDiscardRectangleEXT( commandBuffer, firstDiscardRectangle, discardRectangles );
#endif
}

static void SetDiscardRectangleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 discardRectangleEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDiscardRectangleEnableEXT( discardRectangleEnable );
#else
    s_MockPtr->_SetDiscardRectangleEnableEXT( commandBuffer, discardRectangleEnable );
#endif
}

static void SetDiscardRectangleModeEXT( vk::CommandBuffer commandBuffer,
                                        vk::DiscardRectangleModeEXT discardRectangleMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDiscardRectangleModeEXT( discardRectangleMode );
#else
    s_MockPtr->_SetDiscardRectangleModeEXT( commandBuffer, discardRectangleMode );
#endif
}

static void BeginRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo* pRenderPassBegin,
                                 const vk::SubpassBeginInfo* pSubpassBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass2KHR( pRenderPassBegin, pSubpassBeginInfo );
#else
    s_MockPtr->_BeginRenderPass2KHR( commandBuffer, pRenderPassBegin, pSubpassBeginInfo );
#endif
}

static void BeginRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::RenderPassBeginInfo& renderPassBegin,
                                 const vk::SubpassBeginInfo& subpassBeginInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginRenderPass2KHR( renderPassBegin, subpassBeginInfo );
#else
    s_MockPtr->_BeginRenderPass2KHR( commandBuffer, renderPassBegin, subpassBeginInfo );
#endif
}

static void NextSubpass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo* pSubpassBeginInfo,
                             const vk::SubpassEndInfo* pSubpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.nextSubpass2KHR( pSubpassBeginInfo, pSubpassEndInfo );
#else
    s_MockPtr->_NextSubpass2KHR( commandBuffer, pSubpassBeginInfo, pSubpassEndInfo );
#endif
}

static void NextSubpass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassBeginInfo& subpassBeginInfo,
                             const vk::SubpassEndInfo& subpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.nextSubpass2KHR( subpassBeginInfo, subpassEndInfo );
#else
    s_MockPtr->_NextSubpass2KHR( commandBuffer, subpassBeginInfo, subpassEndInfo );
#endif
}

static void EndRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo* pSubpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderPass2KHR( pSubpassEndInfo );
#else
    s_MockPtr->_EndRenderPass2KHR( commandBuffer, pSubpassEndInfo );
#endif
}

static void EndRenderPass2KHR( vk::CommandBuffer commandBuffer, const vk::SubpassEndInfo& subpassEndInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endRenderPass2KHR( subpassEndInfo );
#else
    s_MockPtr->_EndRenderPass2KHR( commandBuffer, subpassEndInfo );
#endif
}

static void BeginDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT* pLabelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginDebugUtilsLabelEXT( pLabelInfo );
#else
    s_MockPtr->_BeginDebugUtilsLabelEXT( commandBuffer, pLabelInfo );
#endif
}

static void BeginDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT& labelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.beginDebugUtilsLabelEXT( labelInfo );
#else
    s_MockPtr->_BeginDebugUtilsLabelEXT( commandBuffer, labelInfo );
#endif
}

static void EndDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.endDebugUtilsLabelEXT();
#else
    s_MockPtr->_EndDebugUtilsLabelEXT();
#endif
}

static void InsertDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT* pLabelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.insertDebugUtilsLabelEXT( pLabelInfo );
#else
    s_MockPtr->_InsertDebugUtilsLabelEXT( commandBuffer, pLabelInfo );
#endif
}

static void InsertDebugUtilsLabelEXT( vk::CommandBuffer commandBuffer, const vk::DebugUtilsLabelEXT& labelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.insertDebugUtilsLabelEXT( labelInfo );
#else
    s_MockPtr->_InsertDebugUtilsLabelEXT( commandBuffer, labelInfo );
#endif
}

static void SetSampleLocationsEXT( vk::CommandBuffer commandBuffer,
                                   const vk::SampleLocationsInfoEXT* pSampleLocationsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setSampleLocationsEXT( pSampleLocationsInfo );
#else
    s_MockPtr->_SetSampleLocationsEXT( commandBuffer, pSampleLocationsInfo );
#endif
}

static void SetSampleLocationsEXT( vk::CommandBuffer commandBuffer,
                                   const vk::SampleLocationsInfoEXT& sampleLocationsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setSampleLocationsEXT( sampleLocationsInfo );
#else
    s_MockPtr->_SetSampleLocationsEXT( commandBuffer, sampleLocationsInfo );
#endif
}

static void
BuildAccelerationStructuresKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructuresKHR( infoCount, pInfos, ppBuildRangeInfos );
#else
    s_MockPtr->_BuildAccelerationStructuresKHR( commandBuffer, infoCount, pInfos, ppBuildRangeInfos );
#endif
}

static void BuildAccelerationStructuresKHR(
        vk::CommandBuffer commandBuffer,
        vk::ArrayProxy<const vk::AccelerationStructureBuildGeometryInfoKHR> const& infos,
        vk::ArrayProxy<const vk::AccelerationStructureBuildRangeInfoKHR* const> const& pBuildRangeInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructuresKHR( infos, pBuildRangeInfos );
#else
    s_MockPtr->_BuildAccelerationStructuresKHR( commandBuffer, infos, pBuildRangeInfos );
#endif
}

static void BuildAccelerationStructuresIndirectKHR( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                                                    const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                                    const vk::DeviceAddress* pIndirectDeviceAddresses,
                                                    const uint32_t* pIndirectStrides,
                                                    const uint32_t* const* ppMaxPrimitiveCounts ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructuresIndirectKHR( infoCount, pInfos, pIndirectDeviceAddresses, pIndirectStrides,
                                                          ppMaxPrimitiveCounts );
#else
    s_MockPtr->_BuildAccelerationStructuresIndirectKHR( commandBuffer, infoCount, pInfos, pIndirectDeviceAddresses,
                                                        pIndirectStrides, ppMaxPrimitiveCounts );
#endif
}

static void BuildAccelerationStructuresIndirectKHR(
        vk::CommandBuffer commandBuffer,
        vk::ArrayProxy<const vk::AccelerationStructureBuildGeometryInfoKHR> const& infos,
        vk::ArrayProxy<const vk::DeviceAddress> const& indirectDeviceAddresses,
        vk::ArrayProxy<const uint32_t> const& indirectStrides,
        vk::ArrayProxy<const uint32_t* const> const& pMaxPrimitiveCounts ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructuresIndirectKHR( infos, indirectDeviceAddresses, indirectStrides,
                                                          pMaxPrimitiveCounts );
#else
    s_MockPtr->_BuildAccelerationStructuresIndirectKHR( commandBuffer, infos, indirectDeviceAddresses, indirectStrides,
                                                        pMaxPrimitiveCounts );
#endif
}

static void CopyAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                          const vk::CopyAccelerationStructureInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyAccelerationStructureKHR( pInfo );
#else
    s_MockPtr->_CopyAccelerationStructureKHR( commandBuffer, pInfo );
#endif
}

static void CopyAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                          const vk::CopyAccelerationStructureInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyAccelerationStructureKHR( info );
#else
    s_MockPtr->_CopyAccelerationStructureKHR( commandBuffer, info );
#endif
}

static void CopyAccelerationStructureToMemoryKHR( vk::CommandBuffer commandBuffer,
                                                  const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyAccelerationStructureToMemoryKHR( pInfo );
#else
    s_MockPtr->_CopyAccelerationStructureToMemoryKHR( commandBuffer, pInfo );
#endif
}

static void CopyAccelerationStructureToMemoryKHR( vk::CommandBuffer commandBuffer,
                                                  const vk::CopyAccelerationStructureToMemoryInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyAccelerationStructureToMemoryKHR( info );
#else
    s_MockPtr->_CopyAccelerationStructureToMemoryKHR( commandBuffer, info );
#endif
}

static void CopyMemoryToAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                                  const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToAccelerationStructureKHR( pInfo );
#else
    s_MockPtr->_CopyMemoryToAccelerationStructureKHR( commandBuffer, pInfo );
#endif
}

static void CopyMemoryToAccelerationStructureKHR( vk::CommandBuffer commandBuffer,
                                                  const vk::CopyMemoryToAccelerationStructureInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToAccelerationStructureKHR( info );
#else
    s_MockPtr->_CopyMemoryToAccelerationStructureKHR( commandBuffer, info );
#endif
}

static void WriteAccelerationStructuresPropertiesKHR( vk::CommandBuffer commandBuffer,
                                                      uint32_t accelerationStructureCount,
                                                      const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                      vk::QueryType queryType, vk::QueryPool queryPool,
                                                      uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeAccelerationStructuresPropertiesKHR( accelerationStructureCount, pAccelerationStructures,
                                                            queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteAccelerationStructuresPropertiesKHR( commandBuffer, accelerationStructureCount,
                                                          pAccelerationStructures, queryType, queryPool, firstQuery );
#endif
}

static void WriteAccelerationStructuresPropertiesKHR(
        vk::CommandBuffer commandBuffer,
        vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures, vk::QueryType queryType,
        vk::QueryPool queryPool, uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeAccelerationStructuresPropertiesKHR( accelerationStructures, queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteAccelerationStructuresPropertiesKHR( commandBuffer, accelerationStructures, queryType, queryPool,
                                                          firstQuery );
#endif
}

static void TraceRaysKHR( vk::CommandBuffer commandBuffer,
                          const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable, uint32_t width,
                          uint32_t height, uint32_t depth ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysKHR( pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
                                pCallableShaderBindingTable, width, height, depth );
#else
    s_MockPtr->_TraceRaysKHR( commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
                              pCallableShaderBindingTable, width, height, depth );
#endif
}

static void TraceRaysKHR( vk::CommandBuffer commandBuffer,
                          const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                          const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable, uint32_t width,
                          uint32_t height, uint32_t depth ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysKHR( raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable,
                                callableShaderBindingTable, width, height, depth );
#else
    s_MockPtr->_TraceRaysKHR( commandBuffer, raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable,
                              callableShaderBindingTable, width, height, depth );
#endif
}

static void TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                  const vk::StridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
                                  vk::DeviceAddress indirectDeviceAddress ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysIndirectKHR( pRaygenShaderBindingTable, pMissShaderBindingTable, pHitShaderBindingTable,
                                        pCallableShaderBindingTable, indirectDeviceAddress );
#else
    s_MockPtr->_TraceRaysIndirectKHR( commandBuffer, pRaygenShaderBindingTable, pMissShaderBindingTable,
                                      pHitShaderBindingTable, pCallableShaderBindingTable, indirectDeviceAddress );
#endif
}

static void TraceRaysIndirectKHR( vk::CommandBuffer commandBuffer,
                                  const vk::StridedDeviceAddressRegionKHR& raygenShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& missShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& hitShaderBindingTable,
                                  const vk::StridedDeviceAddressRegionKHR& callableShaderBindingTable,
                                  vk::DeviceAddress indirectDeviceAddress ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysIndirectKHR( raygenShaderBindingTable, missShaderBindingTable, hitShaderBindingTable,
                                        callableShaderBindingTable, indirectDeviceAddress );
#else
    s_MockPtr->_TraceRaysIndirectKHR( commandBuffer, raygenShaderBindingTable, missShaderBindingTable,
                                      hitShaderBindingTable, callableShaderBindingTable, indirectDeviceAddress );
#endif
}

static void SetRayTracingPipelineStackSizeKHR( vk::CommandBuffer commandBuffer, uint32_t pipelineStackSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRayTracingPipelineStackSizeKHR( pipelineStackSize );
#else
    s_MockPtr->_SetRayTracingPipelineStackSizeKHR( commandBuffer, pipelineStackSize );
#endif
}

static void BindShadingRateImageNV( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                    vk::ImageLayout imageLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindShadingRateImageNV( imageView, imageLayout );
#else
    s_MockPtr->_BindShadingRateImageNV( commandBuffer, imageView, imageLayout );
#endif
}

static void SetViewportShadingRatePaletteNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                             uint32_t viewportCount,
                                             const vk::ShadingRatePaletteNV* pShadingRatePalettes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportShadingRatePaletteNV( firstViewport, viewportCount, pShadingRatePalettes );
#else
    s_MockPtr->_SetViewportShadingRatePaletteNV( commandBuffer, firstViewport, viewportCount, pShadingRatePalettes );
#endif
}

static void
SetViewportShadingRatePaletteNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                 vk::ArrayProxy<const vk::ShadingRatePaletteNV> const& shadingRatePalettes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportShadingRatePaletteNV( firstViewport, shadingRatePalettes );
#else
    s_MockPtr->_SetViewportShadingRatePaletteNV( commandBuffer, firstViewport, shadingRatePalettes );
#endif
}

static void SetCoarseSampleOrderNV( vk::CommandBuffer commandBuffer, vk::CoarseSampleOrderTypeNV sampleOrderType,
                                    uint32_t customSampleOrderCount,
                                    const vk::CoarseSampleOrderCustomNV* pCustomSampleOrders ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoarseSampleOrderNV( sampleOrderType, customSampleOrderCount, pCustomSampleOrders );
#else
    s_MockPtr->_SetCoarseSampleOrderNV( commandBuffer, sampleOrderType, customSampleOrderCount, pCustomSampleOrders );
#endif
}

static void
SetCoarseSampleOrderNV( vk::CommandBuffer commandBuffer, vk::CoarseSampleOrderTypeNV sampleOrderType,
                        vk::ArrayProxy<const vk::CoarseSampleOrderCustomNV> const& customSampleOrders ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoarseSampleOrderNV( sampleOrderType, customSampleOrders );
#else
    s_MockPtr->_SetCoarseSampleOrderNV( commandBuffer, sampleOrderType, customSampleOrders );
#endif
}

static void BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer, const vk::AccelerationStructureInfoNV* pInfo,
                                          vk::Buffer instanceData, vk::DeviceSize instanceOffset, vk::Bool32 update,
                                          vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src,
                                          vk::Buffer scratch, vk::DeviceSize scratchOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructureNV( pInfo, instanceData, instanceOffset, update, dst, src, scratch,
                                                scratchOffset );
#else
    s_MockPtr->_BuildAccelerationStructureNV( commandBuffer, pInfo, instanceData, instanceOffset, update, dst, src,
                                              scratch, scratchOffset );
#endif
}

static void BuildAccelerationStructureNV( vk::CommandBuffer commandBuffer, const vk::AccelerationStructureInfoNV& info,
                                          vk::Buffer instanceData, vk::DeviceSize instanceOffset, vk::Bool32 update,
                                          vk::AccelerationStructureNV dst, vk::AccelerationStructureNV src,
                                          vk::Buffer scratch, vk::DeviceSize scratchOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildAccelerationStructureNV( info, instanceData, instanceOffset, update, dst, src, scratch,
                                                scratchOffset );
#else
    s_MockPtr->_BuildAccelerationStructureNV( commandBuffer, info, instanceData, instanceOffset, update, dst, src,
                                              scratch, scratchOffset );
#endif
}

static void CopyAccelerationStructureNV( vk::CommandBuffer commandBuffer, vk::AccelerationStructureNV dst,
                                         vk::AccelerationStructureNV src,
                                         vk::CopyAccelerationStructureModeKHR mode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyAccelerationStructureNV( dst, src, mode );
#else
    s_MockPtr->_CopyAccelerationStructureNV( commandBuffer, dst, src, mode );
#endif
}

static void TraceRaysNV( vk::CommandBuffer commandBuffer, vk::Buffer raygenShaderBindingTableBuffer,
                         vk::DeviceSize raygenShaderBindingOffset, vk::Buffer missShaderBindingTableBuffer,
                         vk::DeviceSize missShaderBindingOffset, vk::DeviceSize missShaderBindingStride,
                         vk::Buffer hitShaderBindingTableBuffer, vk::DeviceSize hitShaderBindingOffset,
                         vk::DeviceSize hitShaderBindingStride, vk::Buffer callableShaderBindingTableBuffer,
                         vk::DeviceSize callableShaderBindingOffset, vk::DeviceSize callableShaderBindingStride,
                         uint32_t width, uint32_t height, uint32_t depth ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysNV( raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer,
                               missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer,
                               hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer,
                               callableShaderBindingOffset, callableShaderBindingStride, width, height, depth );
#else
    s_MockPtr->_TraceRaysNV( commandBuffer, raygenShaderBindingTableBuffer, raygenShaderBindingOffset,
                             missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride,
                             hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride,
                             callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride,
                             width, height, depth );
#endif
}

static void WriteAccelerationStructuresPropertiesNV( vk::CommandBuffer commandBuffer,
                                                     uint32_t accelerationStructureCount,
                                                     const vk::AccelerationStructureNV* pAccelerationStructures,
                                                     vk::QueryType queryType, vk::QueryPool queryPool,
                                                     uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeAccelerationStructuresPropertiesNV( accelerationStructureCount, pAccelerationStructures,
                                                           queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteAccelerationStructuresPropertiesNV( commandBuffer, accelerationStructureCount,
                                                         pAccelerationStructures, queryType, queryPool, firstQuery );
#endif
}

static void WriteAccelerationStructuresPropertiesNV(
        vk::CommandBuffer commandBuffer,
        vk::ArrayProxy<const vk::AccelerationStructureNV> const& accelerationStructures, vk::QueryType queryType,
        vk::QueryPool queryPool, uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeAccelerationStructuresPropertiesNV( accelerationStructures, queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteAccelerationStructuresPropertiesNV( commandBuffer, accelerationStructures, queryType, queryPool,
                                                         firstQuery );
#endif
}

static void DrawIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                  vk::Buffer countBuffer, vk::DeviceSize countBufferOffset, uint32_t maxDrawCount,
                                  uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndirectCountKHR( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndirectCountKHR( commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount,
                                      stride );
#endif
}

static void DrawIndexedIndirectCountKHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                         vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                         uint32_t maxDrawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawIndexedIndirectCountKHR( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawIndexedIndirectCountKHR( commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                             maxDrawCount, stride );
#endif
}

static void WriteBufferMarkerAMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlagBits pipelineStage,
                                  vk::Buffer dstBuffer, vk::DeviceSize dstOffset, uint32_t marker ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeBufferMarkerAMD( pipelineStage, dstBuffer, dstOffset, marker );
#else
    s_MockPtr->_WriteBufferMarkerAMD( commandBuffer, pipelineStage, dstBuffer, dstOffset, marker );
#endif
}

static void DrawMeshTasksNV( vk::CommandBuffer commandBuffer, uint32_t taskCount, uint32_t firstTask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksNV( taskCount, firstTask );
#else
    s_MockPtr->_DrawMeshTasksNV( commandBuffer, taskCount, firstTask );
#endif
}

static void DrawMeshTasksIndirectNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                     uint32_t drawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksIndirectNV( buffer, offset, drawCount, stride );
#else
    s_MockPtr->_DrawMeshTasksIndirectNV( commandBuffer, buffer, offset, drawCount, stride );
#endif
}

static void DrawMeshTasksIndirectCountNV( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                          vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                          uint32_t maxDrawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksIndirectCountNV( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawMeshTasksIndirectCountNV( commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                              maxDrawCount, stride );
#endif
}

static void SetExclusiveScissorEnableNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                         uint32_t exclusiveScissorCount,
                                         const vk::Bool32* pExclusiveScissorEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setExclusiveScissorEnableNV( firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissorEnables );
#else
    s_MockPtr->_SetExclusiveScissorEnableNV( commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                             pExclusiveScissorEnables );
#endif
}

static void SetExclusiveScissorEnableNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                         vk::ArrayProxy<const vk::Bool32> const& exclusiveScissorEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setExclusiveScissorEnableNV( firstExclusiveScissor, exclusiveScissorEnables );
#else
    s_MockPtr->_SetExclusiveScissorEnableNV( commandBuffer, firstExclusiveScissor, exclusiveScissorEnables );
#endif
}

static void SetExclusiveScissorNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                   uint32_t exclusiveScissorCount, const vk::Rect2D* pExclusiveScissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setExclusiveScissorNV( firstExclusiveScissor, exclusiveScissorCount, pExclusiveScissors );
#else
    s_MockPtr->_SetExclusiveScissorNV( commandBuffer, firstExclusiveScissor, exclusiveScissorCount,
                                       pExclusiveScissors );
#endif
}

static void SetExclusiveScissorNV( vk::CommandBuffer commandBuffer, uint32_t firstExclusiveScissor,
                                   vk::ArrayProxy<const vk::Rect2D> const& exclusiveScissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setExclusiveScissorNV( firstExclusiveScissor, exclusiveScissors );
#else
    s_MockPtr->_SetExclusiveScissorNV( commandBuffer, firstExclusiveScissor, exclusiveScissors );
#endif
}

static void SetCheckpointNV( vk::CommandBuffer commandBuffer, const void* pCheckpointMarker ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCheckpointNV( pCheckpointMarker );
#else
    s_MockPtr->_SetCheckpointNV( commandBuffer, pCheckpointMarker );
#endif
}

template <typename CheckpointMarkerType>
static void SetCheckpointNV( vk::CommandBuffer commandBuffer, CheckpointMarkerType const& checkpointMarker ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCheckpointNV( checkpointMarker );
#else
    s_MockPtr->_SetCheckpointNV( commandBuffer, checkpointMarker );
#endif
}

static vk::Result SetPerformanceMarkerINTEL( vk::CommandBuffer commandBuffer,
                                             const vk::PerformanceMarkerInfoINTEL* pMarkerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceMarkerINTEL( pMarkerInfo );
#else
    return s_MockPtr->_SetPerformanceMarkerINTEL( commandBuffer, pMarkerInfo );
#endif
}

static vk::Result SetPerformanceMarkerINTEL( vk::CommandBuffer commandBuffer,
                                             const vk::PerformanceMarkerInfoINTEL& markerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceMarkerINTEL( markerInfo );
#else
    return s_MockPtr->_SetPerformanceMarkerINTEL( commandBuffer, markerInfo );
#endif
}

static vk::Result SetPerformanceStreamMarkerINTEL( vk::CommandBuffer commandBuffer,
                                                   const vk::PerformanceStreamMarkerInfoINTEL* pMarkerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceStreamMarkerINTEL( pMarkerInfo );
#else
    return s_MockPtr->_SetPerformanceStreamMarkerINTEL( commandBuffer, pMarkerInfo );
#endif
}

static vk::Result SetPerformanceStreamMarkerINTEL( vk::CommandBuffer commandBuffer,
                                                   const vk::PerformanceStreamMarkerInfoINTEL& markerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceStreamMarkerINTEL( markerInfo );
#else
    return s_MockPtr->_SetPerformanceStreamMarkerINTEL( commandBuffer, markerInfo );
#endif
}

static vk::Result SetPerformanceOverrideINTEL( vk::CommandBuffer commandBuffer,
                                               const vk::PerformanceOverrideInfoINTEL* pOverrideInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceOverrideINTEL( pOverrideInfo );
#else
    return s_MockPtr->_SetPerformanceOverrideINTEL( commandBuffer, pOverrideInfo );
#endif
}

static vk::Result SetPerformanceOverrideINTEL( vk::CommandBuffer commandBuffer,
                                               const vk::PerformanceOverrideInfoINTEL& overrideInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return commandBuffer.setPerformanceOverrideINTEL( overrideInfo );
#else
    return s_MockPtr->_SetPerformanceOverrideINTEL( commandBuffer, overrideInfo );
#endif
}

static void SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D* pFragmentSize,
                                       const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setFragmentShadingRateKHR( pFragmentSize, combinerOps );
#else
    s_MockPtr->_SetFragmentShadingRateKHR( commandBuffer, pFragmentSize, combinerOps );
#endif
}

static void SetFragmentShadingRateKHR( vk::CommandBuffer commandBuffer, const vk::Extent2D& fragmentSize,
                                       const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setFragmentShadingRateKHR( fragmentSize, combinerOps );
#else
    s_MockPtr->_SetFragmentShadingRateKHR( commandBuffer, fragmentSize, combinerOps );
#endif
}

static void SetLineStippleEXT( vk::CommandBuffer commandBuffer, uint32_t lineStippleFactor,
                               uint16_t lineStipplePattern ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLineStippleEXT( lineStippleFactor, lineStipplePattern );
#else
    s_MockPtr->_SetLineStippleEXT( commandBuffer, lineStippleFactor, lineStipplePattern );
#endif
}

static void SetCullModeEXT( vk::CommandBuffer commandBuffer, vk::CullModeFlags cullMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCullModeEXT( cullMode );
#else
    s_MockPtr->_SetCullModeEXT( commandBuffer, cullMode );
#endif
}

static void SetFrontFaceEXT( vk::CommandBuffer commandBuffer, vk::FrontFace frontFace ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setFrontFaceEXT( frontFace );
#else
    s_MockPtr->_SetFrontFaceEXT( commandBuffer, frontFace );
#endif
}

static void SetPrimitiveTopologyEXT( vk::CommandBuffer commandBuffer, vk::PrimitiveTopology primitiveTopology ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPrimitiveTopologyEXT( primitiveTopology );
#else
    s_MockPtr->_SetPrimitiveTopologyEXT( commandBuffer, primitiveTopology );
#endif
}

static void SetViewportWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t viewportCount,
                                     const vk::Viewport* pViewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWithCountEXT( viewportCount, pViewports );
#else
    s_MockPtr->_SetViewportWithCountEXT( commandBuffer, viewportCount, pViewports );
#endif
}

static void SetViewportWithCountEXT( vk::CommandBuffer commandBuffer,
                                     vk::ArrayProxy<const vk::Viewport> const& viewports ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWithCountEXT( viewports );
#else
    s_MockPtr->_SetViewportWithCountEXT( commandBuffer, viewports );
#endif
}

static void SetScissorWithCountEXT( vk::CommandBuffer commandBuffer, uint32_t scissorCount,
                                    const vk::Rect2D* pScissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissorWithCountEXT( scissorCount, pScissors );
#else
    s_MockPtr->_SetScissorWithCountEXT( commandBuffer, scissorCount, pScissors );
#endif
}

static void SetScissorWithCountEXT( vk::CommandBuffer commandBuffer,
                                    vk::ArrayProxy<const vk::Rect2D> const& scissors ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setScissorWithCountEXT( scissors );
#else
    s_MockPtr->_SetScissorWithCountEXT( commandBuffer, scissors );
#endif
}

static void BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding, uint32_t bindingCount,
                                   const vk::Buffer* pBuffers, const vk::DeviceSize* pOffsets,
                                   const vk::DeviceSize* pSizes, const vk::DeviceSize* pStrides ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers2EXT( firstBinding, bindingCount, pBuffers, pOffsets, pSizes, pStrides );
#else
    s_MockPtr->_BindVertexBuffers2EXT( commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets, pSizes,
                                       pStrides );
#endif
}

static void BindVertexBuffers2EXT( vk::CommandBuffer commandBuffer, uint32_t firstBinding,
                                   vk::ArrayProxy<const vk::Buffer> const& buffers,
                                   vk::ArrayProxy<const vk::DeviceSize> const& offsets,
                                   vk::ArrayProxy<const vk::DeviceSize> const& sizes = nullptr,
                                   vk::ArrayProxy<const vk::DeviceSize> const& strides = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindVertexBuffers2EXT( firstBinding, buffers, offsets, nullptr, nullptr );
#else
    s_MockPtr->_BindVertexBuffers2EXT( commandBuffer, firstBinding, buffers, offsets, nullptr, nullptr );
#endif
}

static void SetDepthTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthTestEnableEXT( depthTestEnable );
#else
    s_MockPtr->_SetDepthTestEnableEXT( commandBuffer, depthTestEnable );
#endif
}

static void SetDepthWriteEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthWriteEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthWriteEnableEXT( depthWriteEnable );
#else
    s_MockPtr->_SetDepthWriteEnableEXT( commandBuffer, depthWriteEnable );
#endif
}

static void SetDepthCompareOpEXT( vk::CommandBuffer commandBuffer, vk::CompareOp depthCompareOp ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthCompareOpEXT( depthCompareOp );
#else
    s_MockPtr->_SetDepthCompareOpEXT( commandBuffer, depthCompareOp );
#endif
}

static void SetDepthBoundsTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBoundsTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBoundsTestEnableEXT( depthBoundsTestEnable );
#else
    s_MockPtr->_SetDepthBoundsTestEnableEXT( commandBuffer, depthBoundsTestEnable );
#endif
}

static void SetStencilTestEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stencilTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilTestEnableEXT( stencilTestEnable );
#else
    s_MockPtr->_SetStencilTestEnableEXT( commandBuffer, stencilTestEnable );
#endif
}

static void SetStencilOpEXT( vk::CommandBuffer commandBuffer, vk::StencilFaceFlags faceMask, vk::StencilOp failOp,
                             vk::StencilOp passOp, vk::StencilOp depthFailOp, vk::CompareOp compareOp ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setStencilOpEXT( faceMask, failOp, passOp, depthFailOp, compareOp );
#else
    s_MockPtr->_SetStencilOpEXT( commandBuffer, faceMask, failOp, passOp, depthFailOp, compareOp );
#endif
}

static void PreprocessGeneratedCommandsNV( vk::CommandBuffer commandBuffer,
                                           const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.preprocessGeneratedCommandsNV( pGeneratedCommandsInfo );
#else
    s_MockPtr->_PreprocessGeneratedCommandsNV( commandBuffer, pGeneratedCommandsInfo );
#endif
}

static void PreprocessGeneratedCommandsNV( vk::CommandBuffer commandBuffer,
                                           const vk::GeneratedCommandsInfoNV& generatedCommandsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.preprocessGeneratedCommandsNV( generatedCommandsInfo );
#else
    s_MockPtr->_PreprocessGeneratedCommandsNV( commandBuffer, generatedCommandsInfo );
#endif
}

static void ExecuteGeneratedCommandsNV( vk::CommandBuffer commandBuffer, vk::Bool32 isPreprocessed,
                                        const vk::GeneratedCommandsInfoNV* pGeneratedCommandsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.executeGeneratedCommandsNV( isPreprocessed, pGeneratedCommandsInfo );
#else
    s_MockPtr->_ExecuteGeneratedCommandsNV( commandBuffer, isPreprocessed, pGeneratedCommandsInfo );
#endif
}

static void ExecuteGeneratedCommandsNV( vk::CommandBuffer commandBuffer, vk::Bool32 isPreprocessed,
                                        const vk::GeneratedCommandsInfoNV& generatedCommandsInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.executeGeneratedCommandsNV( isPreprocessed, generatedCommandsInfo );
#else
    s_MockPtr->_ExecuteGeneratedCommandsNV( commandBuffer, isPreprocessed, generatedCommandsInfo );
#endif
}

static void BindPipelineShaderGroupNV( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                       vk::Pipeline pipeline, uint32_t groupIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindPipelineShaderGroupNV( pipelineBindPoint, pipeline, groupIndex );
#else
    s_MockPtr->_BindPipelineShaderGroupNV( commandBuffer, pipelineBindPoint, pipeline, groupIndex );
#endif
}

static void SetDepthBias2EXT( vk::CommandBuffer commandBuffer, const vk::DepthBiasInfoEXT* pDepthBiasInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBias2EXT( pDepthBiasInfo );
#else
    s_MockPtr->_SetDepthBias2EXT( commandBuffer, pDepthBiasInfo );
#endif
}

static void SetDepthBias2EXT( vk::CommandBuffer commandBuffer, const vk::DepthBiasInfoEXT& depthBiasInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBias2EXT( depthBiasInfo );
#else
    s_MockPtr->_SetDepthBias2EXT( commandBuffer, depthBiasInfo );
#endif
}

static void SetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                          const vk::DependencyInfo* pDependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setEvent2KHR( event, pDependencyInfo );
#else
    s_MockPtr->_SetEvent2KHR( commandBuffer, event, pDependencyInfo );
#endif
}

static void SetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event,
                          const vk::DependencyInfo& dependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setEvent2KHR( event, dependencyInfo );
#else
    s_MockPtr->_SetEvent2KHR( commandBuffer, event, dependencyInfo );
#endif
}

static void ResetEvent2KHR( vk::CommandBuffer commandBuffer, vk::Event event, vk::PipelineStageFlags2 stageMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resetEvent2KHR( event, stageMask );
#else
    s_MockPtr->_ResetEvent2KHR( commandBuffer, event, stageMask );
#endif
}

static void WaitEvents2KHR( vk::CommandBuffer commandBuffer, uint32_t eventCount, const vk::Event* pEvents,
                            const vk::DependencyInfo* pDependencyInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents2KHR( eventCount, pEvents, pDependencyInfos );
#else
    s_MockPtr->_WaitEvents2KHR( commandBuffer, eventCount, pEvents, pDependencyInfos );
#endif
}

static void WaitEvents2KHR( vk::CommandBuffer commandBuffer, vk::ArrayProxy<const vk::Event> const& events,
                            vk::ArrayProxy<const vk::DependencyInfo> const& dependencyInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.waitEvents2KHR( events, dependencyInfos );
#else
    s_MockPtr->_WaitEvents2KHR( commandBuffer, events, dependencyInfos );
#endif
}

static void PipelineBarrier2KHR( vk::CommandBuffer commandBuffer, const vk::DependencyInfo* pDependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier2KHR( pDependencyInfo );
#else
    s_MockPtr->_PipelineBarrier2KHR( commandBuffer, pDependencyInfo );
#endif
}

static void PipelineBarrier2KHR( vk::CommandBuffer commandBuffer, const vk::DependencyInfo& dependencyInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.pipelineBarrier2KHR( dependencyInfo );
#else
    s_MockPtr->_PipelineBarrier2KHR( commandBuffer, dependencyInfo );
#endif
}

static void WriteTimestamp2KHR( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::QueryPool queryPool,
                                uint32_t query ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeTimestamp2KHR( stage, queryPool, query );
#else
    s_MockPtr->_WriteTimestamp2KHR( commandBuffer, stage, queryPool, query );
#endif
}

static void WriteBufferMarker2AMD( vk::CommandBuffer commandBuffer, vk::PipelineStageFlags2 stage, vk::Buffer dstBuffer,
                                   vk::DeviceSize dstOffset, uint32_t marker ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeBufferMarker2AMD( stage, dstBuffer, dstOffset, marker );
#else
    s_MockPtr->_WriteBufferMarker2AMD( commandBuffer, stage, dstBuffer, dstOffset, marker );
#endif
}

static void BindDescriptorBuffersEXT( vk::CommandBuffer commandBuffer, uint32_t bufferCount,
                                      const vk::DescriptorBufferBindingInfoEXT* pBindingInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindDescriptorBuffersEXT( bufferCount, pBindingInfos );
#else
    s_MockPtr->_BindDescriptorBuffersEXT( commandBuffer, bufferCount, pBindingInfos );
#endif
}

static void
BindDescriptorBuffersEXT( vk::CommandBuffer commandBuffer,
                          vk::ArrayProxy<const vk::DescriptorBufferBindingInfoEXT> const& bindingInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindDescriptorBuffersEXT( bindingInfos );
#else
    s_MockPtr->_BindDescriptorBuffersEXT( commandBuffer, bindingInfos );
#endif
}

static void SetDescriptorBufferOffsetsEXT( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                           vk::PipelineLayout layout, uint32_t firstSet, uint32_t setCount,
                                           const uint32_t* pBufferIndices, const vk::DeviceSize* pOffsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDescriptorBufferOffsetsEXT( pipelineBindPoint, layout, firstSet, setCount, pBufferIndices,
                                                 pOffsets );
#else
    s_MockPtr->_SetDescriptorBufferOffsetsEXT( commandBuffer, pipelineBindPoint, layout, firstSet, setCount,
                                               pBufferIndices, pOffsets );
#endif
}

static void SetDescriptorBufferOffsetsEXT( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                           vk::PipelineLayout layout, uint32_t firstSet,
                                           vk::ArrayProxy<const uint32_t> const& bufferIndices,
                                           vk::ArrayProxy<const vk::DeviceSize> const& offsets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDescriptorBufferOffsetsEXT( pipelineBindPoint, layout, firstSet, bufferIndices, offsets );
#else
    s_MockPtr->_SetDescriptorBufferOffsetsEXT( commandBuffer, pipelineBindPoint, layout, firstSet, bufferIndices,
                                               offsets );
#endif
}

static void BindDescriptorBufferEmbeddedSamplersEXT( vk::CommandBuffer commandBuffer,
                                                     vk::PipelineBindPoint pipelineBindPoint, vk::PipelineLayout layout,
                                                     uint32_t set ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindDescriptorBufferEmbeddedSamplersEXT( pipelineBindPoint, layout, set );
#else
    s_MockPtr->_BindDescriptorBufferEmbeddedSamplersEXT( commandBuffer, pipelineBindPoint, layout, set );
#endif
}

static void SetFragmentShadingRateEnumNV( vk::CommandBuffer commandBuffer, vk::FragmentShadingRateNV shadingRate,
                                          const vk::FragmentShadingRateCombinerOpKHR combinerOps[ 2 ] ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setFragmentShadingRateEnumNV( shadingRate, combinerOps );
#else
    s_MockPtr->_SetFragmentShadingRateEnumNV( commandBuffer, shadingRate, combinerOps );
#endif
}

static void DrawMeshTasksEXT( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                              uint32_t groupCountZ ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksEXT( groupCountX, groupCountY, groupCountZ );
#else
    s_MockPtr->_DrawMeshTasksEXT( commandBuffer, groupCountX, groupCountY, groupCountZ );
#endif
}

static void DrawMeshTasksIndirectEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                      uint32_t drawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksIndirectEXT( buffer, offset, drawCount, stride );
#else
    s_MockPtr->_DrawMeshTasksIndirectEXT( commandBuffer, buffer, offset, drawCount, stride );
#endif
}

static void DrawMeshTasksIndirectCountEXT( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                           vk::Buffer countBuffer, vk::DeviceSize countBufferOffset,
                                           uint32_t maxDrawCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMeshTasksIndirectCountEXT( buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride );
#else
    s_MockPtr->_DrawMeshTasksIndirectCountEXT( commandBuffer, buffer, offset, countBuffer, countBufferOffset,
                                               maxDrawCount, stride );
#endif
}

static void CopyBuffer2KHR( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2* pCopyBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer2KHR( pCopyBufferInfo );
#else
    s_MockPtr->_CopyBuffer2KHR( commandBuffer, pCopyBufferInfo );
#endif
}

static void CopyBuffer2KHR( vk::CommandBuffer commandBuffer, const vk::CopyBufferInfo2& copyBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBuffer2KHR( copyBufferInfo );
#else
    s_MockPtr->_CopyBuffer2KHR( commandBuffer, copyBufferInfo );
#endif
}

static void CopyImage2KHR( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2* pCopyImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage2KHR( pCopyImageInfo );
#else
    s_MockPtr->_CopyImage2KHR( commandBuffer, pCopyImageInfo );
#endif
}

static void CopyImage2KHR( vk::CommandBuffer commandBuffer, const vk::CopyImageInfo2& copyImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImage2KHR( copyImageInfo );
#else
    s_MockPtr->_CopyImage2KHR( commandBuffer, copyImageInfo );
#endif
}

static void CopyBufferToImage2KHR( vk::CommandBuffer commandBuffer,
                                   const vk::CopyBufferToImageInfo2* pCopyBufferToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage2KHR( pCopyBufferToImageInfo );
#else
    s_MockPtr->_CopyBufferToImage2KHR( commandBuffer, pCopyBufferToImageInfo );
#endif
}

static void CopyBufferToImage2KHR( vk::CommandBuffer commandBuffer,
                                   const vk::CopyBufferToImageInfo2& copyBufferToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyBufferToImage2KHR( copyBufferToImageInfo );
#else
    s_MockPtr->_CopyBufferToImage2KHR( commandBuffer, copyBufferToImageInfo );
#endif
}

static void CopyImageToBuffer2KHR( vk::CommandBuffer commandBuffer,
                                   const vk::CopyImageToBufferInfo2* pCopyImageToBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer2KHR( pCopyImageToBufferInfo );
#else
    s_MockPtr->_CopyImageToBuffer2KHR( commandBuffer, pCopyImageToBufferInfo );
#endif
}

static void CopyImageToBuffer2KHR( vk::CommandBuffer commandBuffer,
                                   const vk::CopyImageToBufferInfo2& copyImageToBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyImageToBuffer2KHR( copyImageToBufferInfo );
#else
    s_MockPtr->_CopyImageToBuffer2KHR( commandBuffer, copyImageToBufferInfo );
#endif
}

static void BlitImage2KHR( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2* pBlitImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage2KHR( pBlitImageInfo );
#else
    s_MockPtr->_BlitImage2KHR( commandBuffer, pBlitImageInfo );
#endif
}

static void BlitImage2KHR( vk::CommandBuffer commandBuffer, const vk::BlitImageInfo2& blitImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.blitImage2KHR( blitImageInfo );
#else
    s_MockPtr->_BlitImage2KHR( commandBuffer, blitImageInfo );
#endif
}

static void ResolveImage2KHR( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2* pResolveImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage2KHR( pResolveImageInfo );
#else
    s_MockPtr->_ResolveImage2KHR( commandBuffer, pResolveImageInfo );
#endif
}

static void ResolveImage2KHR( vk::CommandBuffer commandBuffer, const vk::ResolveImageInfo2& resolveImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.resolveImage2KHR( resolveImageInfo );
#else
    s_MockPtr->_ResolveImage2KHR( commandBuffer, resolveImageInfo );
#endif
}

static void SetVertexInputEXT( vk::CommandBuffer commandBuffer, uint32_t vertexBindingDescriptionCount,
                               const vk::VertexInputBindingDescription2EXT* pVertexBindingDescriptions,
                               uint32_t vertexAttributeDescriptionCount,
                               const vk::VertexInputAttributeDescription2EXT* pVertexAttributeDescriptions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setVertexInputEXT( vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                     vertexAttributeDescriptionCount, pVertexAttributeDescriptions );
#else
    s_MockPtr->_SetVertexInputEXT( commandBuffer, vertexBindingDescriptionCount, pVertexBindingDescriptions,
                                   vertexAttributeDescriptionCount, pVertexAttributeDescriptions );
#endif
}

static void SetVertexInputEXT(
        vk::CommandBuffer commandBuffer,
        vk::ArrayProxy<const vk::VertexInputBindingDescription2EXT> const& vertexBindingDescriptions,
        vk::ArrayProxy<const vk::VertexInputAttributeDescription2EXT> const& vertexAttributeDescriptions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setVertexInputEXT( vertexBindingDescriptions, vertexAttributeDescriptions );
#else
    s_MockPtr->_SetVertexInputEXT( commandBuffer, vertexBindingDescriptions, vertexAttributeDescriptions );
#endif
}

static void SubpassShadingHUAWEI( vk::CommandBuffer commandBuffer, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.subpassShadingHUAWEI();
#else
    s_MockPtr->_SubpassShadingHUAWEI();
#endif
}

static void BindInvocationMaskHUAWEI( vk::CommandBuffer commandBuffer, vk::ImageView imageView,
                                      vk::ImageLayout imageLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindInvocationMaskHUAWEI( imageView, imageLayout );
#else
    s_MockPtr->_BindInvocationMaskHUAWEI( commandBuffer, imageView, imageLayout );
#endif
}

static void SetPatchControlPointsEXT( vk::CommandBuffer commandBuffer, uint32_t patchControlPoints ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPatchControlPointsEXT( patchControlPoints );
#else
    s_MockPtr->_SetPatchControlPointsEXT( commandBuffer, patchControlPoints );
#endif
}

static void SetRasterizerDiscardEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 rasterizerDiscardEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRasterizerDiscardEnableEXT( rasterizerDiscardEnable );
#else
    s_MockPtr->_SetRasterizerDiscardEnableEXT( commandBuffer, rasterizerDiscardEnable );
#endif
}

static void SetDepthBiasEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthBiasEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthBiasEnableEXT( depthBiasEnable );
#else
    s_MockPtr->_SetDepthBiasEnableEXT( commandBuffer, depthBiasEnable );
#endif
}

static void SetLogicOpEXT( vk::CommandBuffer commandBuffer, vk::LogicOp logicOp ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLogicOpEXT( logicOp );
#else
    s_MockPtr->_SetLogicOpEXT( commandBuffer, logicOp );
#endif
}

static void SetPrimitiveRestartEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 primitiveRestartEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPrimitiveRestartEnableEXT( primitiveRestartEnable );
#else
    s_MockPtr->_SetPrimitiveRestartEnableEXT( commandBuffer, primitiveRestartEnable );
#endif
}

static void SetColorWriteEnableEXT( vk::CommandBuffer commandBuffer, uint32_t attachmentCount,
                                    const vk::Bool32* pColorWriteEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorWriteEnableEXT( attachmentCount, pColorWriteEnables );
#else
    s_MockPtr->_SetColorWriteEnableEXT( commandBuffer, attachmentCount, pColorWriteEnables );
#endif
}

static void SetColorWriteEnableEXT( vk::CommandBuffer commandBuffer,
                                    vk::ArrayProxy<const vk::Bool32> const& colorWriteEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorWriteEnableEXT( colorWriteEnables );
#else
    s_MockPtr->_SetColorWriteEnableEXT( commandBuffer, colorWriteEnables );
#endif
}

static void TraceRaysIndirect2KHR( vk::CommandBuffer commandBuffer, vk::DeviceAddress indirectDeviceAddress ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.traceRaysIndirect2KHR( indirectDeviceAddress );
#else
    s_MockPtr->_TraceRaysIndirect2KHR( commandBuffer, indirectDeviceAddress );
#endif
}

static void DrawMultiEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount, const vk::MultiDrawInfoEXT* pVertexInfo,
                          uint32_t instanceCount, uint32_t firstInstance, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMultiEXT( drawCount, pVertexInfo, instanceCount, firstInstance, stride );
#else
    s_MockPtr->_DrawMultiEXT( commandBuffer, drawCount, pVertexInfo, instanceCount, firstInstance, stride );
#endif
}

static void DrawMultiEXT( vk::CommandBuffer commandBuffer,
                          vk::StridedArrayProxy<const vk::MultiDrawInfoEXT> const& vertexInfo, uint32_t instanceCount,
                          uint32_t firstInstance ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMultiEXT( vertexInfo, instanceCount, firstInstance );
#else
    s_MockPtr->_DrawMultiEXT( commandBuffer, vertexInfo, instanceCount, firstInstance );
#endif
}

static void DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer, uint32_t drawCount,
                                 const vk::MultiDrawIndexedInfoEXT* pIndexInfo, uint32_t instanceCount,
                                 uint32_t firstInstance, uint32_t stride, const int32_t* pVertexOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMultiIndexedEXT( drawCount, pIndexInfo, instanceCount, firstInstance, stride, pVertexOffset );
#else
    s_MockPtr->_DrawMultiIndexedEXT( commandBuffer, drawCount, pIndexInfo, instanceCount, firstInstance, stride,
                                     pVertexOffset );
#endif
}

static void DrawMultiIndexedEXT( vk::CommandBuffer commandBuffer,
                                 vk::StridedArrayProxy<const vk::MultiDrawIndexedInfoEXT> const& indexInfo,
                                 uint32_t instanceCount, uint32_t firstInstance,
                                 Optional<const int32_t> vertexOffset = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawMultiIndexedEXT( indexInfo, instanceCount, firstInstance, nullptr );
#else
    s_MockPtr->_DrawMultiIndexedEXT( commandBuffer, indexInfo, instanceCount, firstInstance, nullptr );
#endif
}

static void BuildMicromapsEXT( vk::CommandBuffer commandBuffer, uint32_t infoCount,
                               const vk::MicromapBuildInfoEXT* pInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildMicromapsEXT( infoCount, pInfos );
#else
    s_MockPtr->_BuildMicromapsEXT( commandBuffer, infoCount, pInfos );
#endif
}

static void BuildMicromapsEXT( vk::CommandBuffer commandBuffer,
                               vk::ArrayProxy<const vk::MicromapBuildInfoEXT> const& infos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.buildMicromapsEXT( infos );
#else
    s_MockPtr->_BuildMicromapsEXT( commandBuffer, infos );
#endif
}

static void CopyMicromapEXT( vk::CommandBuffer commandBuffer, const vk::CopyMicromapInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMicromapEXT( pInfo );
#else
    s_MockPtr->_CopyMicromapEXT( commandBuffer, pInfo );
#endif
}

static void CopyMicromapEXT( vk::CommandBuffer commandBuffer, const vk::CopyMicromapInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMicromapEXT( info );
#else
    s_MockPtr->_CopyMicromapEXT( commandBuffer, info );
#endif
}

static void CopyMicromapToMemoryEXT( vk::CommandBuffer commandBuffer,
                                     const vk::CopyMicromapToMemoryInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMicromapToMemoryEXT( pInfo );
#else
    s_MockPtr->_CopyMicromapToMemoryEXT( commandBuffer, pInfo );
#endif
}

static void CopyMicromapToMemoryEXT( vk::CommandBuffer commandBuffer,
                                     const vk::CopyMicromapToMemoryInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMicromapToMemoryEXT( info );
#else
    s_MockPtr->_CopyMicromapToMemoryEXT( commandBuffer, info );
#endif
}

static void CopyMemoryToMicromapEXT( vk::CommandBuffer commandBuffer,
                                     const vk::CopyMemoryToMicromapInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToMicromapEXT( pInfo );
#else
    s_MockPtr->_CopyMemoryToMicromapEXT( commandBuffer, pInfo );
#endif
}

static void CopyMemoryToMicromapEXT( vk::CommandBuffer commandBuffer,
                                     const vk::CopyMemoryToMicromapInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToMicromapEXT( info );
#else
    s_MockPtr->_CopyMemoryToMicromapEXT( commandBuffer, info );
#endif
}

static void WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer, uint32_t micromapCount,
                                         const vk::MicromapEXT* pMicromaps, vk::QueryType queryType,
                                         vk::QueryPool queryPool, uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeMicromapsPropertiesEXT( micromapCount, pMicromaps, queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteMicromapsPropertiesEXT( commandBuffer, micromapCount, pMicromaps, queryType, queryPool,
                                             firstQuery );
#endif
}

static void WriteMicromapsPropertiesEXT( vk::CommandBuffer commandBuffer,
                                         vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                                         vk::QueryType queryType, vk::QueryPool queryPool, uint32_t firstQuery ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.writeMicromapsPropertiesEXT( micromaps, queryType, queryPool, firstQuery );
#else
    s_MockPtr->_WriteMicromapsPropertiesEXT( commandBuffer, micromaps, queryType, queryPool, firstQuery );
#endif
}

static void DrawClusterHUAWEI( vk::CommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY,
                               uint32_t groupCountZ ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawClusterHUAWEI( groupCountX, groupCountY, groupCountZ );
#else
    s_MockPtr->_DrawClusterHUAWEI( commandBuffer, groupCountX, groupCountY, groupCountZ );
#endif
}

static void DrawClusterIndirectHUAWEI( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.drawClusterIndirectHUAWEI( buffer, offset );
#else
    s_MockPtr->_DrawClusterIndirectHUAWEI( commandBuffer, buffer, offset );
#endif
}

static void CopyMemoryIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                  uint32_t copyCount, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryIndirectNV( copyBufferAddress, copyCount, stride );
#else
    s_MockPtr->_CopyMemoryIndirectNV( commandBuffer, copyBufferAddress, copyCount, stride );
#endif
}

static void CopyMemoryToImageIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress,
                                         uint32_t copyCount, uint32_t stride, vk::Image dstImage,
                                         vk::ImageLayout dstImageLayout,
                                         const vk::ImageSubresourceLayers* pImageSubresources ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToImageIndirectNV( copyBufferAddress, copyCount, stride, dstImage, dstImageLayout,
                                               pImageSubresources );
#else
    s_MockPtr->_CopyMemoryToImageIndirectNV( commandBuffer, copyBufferAddress, copyCount, stride, dstImage,
                                             dstImageLayout, pImageSubresources );
#endif
}

static void
CopyMemoryToImageIndirectNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress copyBufferAddress, uint32_t stride,
                             vk::Image dstImage, vk::ImageLayout dstImageLayout,
                             vk::ArrayProxy<const vk::ImageSubresourceLayers> const& imageSubresources ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.copyMemoryToImageIndirectNV( copyBufferAddress, stride, dstImage, dstImageLayout, imageSubresources );
#else
    s_MockPtr->_CopyMemoryToImageIndirectNV( commandBuffer, copyBufferAddress, stride, dstImage, dstImageLayout,
                                             imageSubresources );
#endif
}

static void DecompressMemoryNV( vk::CommandBuffer commandBuffer, uint32_t decompressRegionCount,
                                const vk::DecompressMemoryRegionNV* pDecompressMemoryRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.decompressMemoryNV( decompressRegionCount, pDecompressMemoryRegions );
#else
    s_MockPtr->_DecompressMemoryNV( commandBuffer, decompressRegionCount, pDecompressMemoryRegions );
#endif
}

static void
DecompressMemoryNV( vk::CommandBuffer commandBuffer,
                    vk::ArrayProxy<const vk::DecompressMemoryRegionNV> const& decompressMemoryRegions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.decompressMemoryNV( decompressMemoryRegions );
#else
    s_MockPtr->_DecompressMemoryNV( commandBuffer, decompressMemoryRegions );
#endif
}

static void DecompressMemoryIndirectCountNV( vk::CommandBuffer commandBuffer, vk::DeviceAddress indirectCommandsAddress,
                                             vk::DeviceAddress indirectCommandsCountAddress, uint32_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.decompressMemoryIndirectCountNV( indirectCommandsAddress, indirectCommandsCountAddress, stride );
#else
    s_MockPtr->_DecompressMemoryIndirectCountNV( commandBuffer, indirectCommandsAddress, indirectCommandsCountAddress,
                                                 stride );
#endif
}

static void UpdatePipelineIndirectBufferNV( vk::CommandBuffer commandBuffer, vk::PipelineBindPoint pipelineBindPoint,
                                            vk::Pipeline pipeline ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.updatePipelineIndirectBufferNV( pipelineBindPoint, pipeline );
#else
    s_MockPtr->_UpdatePipelineIndirectBufferNV( commandBuffer, pipelineBindPoint, pipeline );
#endif
}

static void SetTessellationDomainOriginEXT( vk::CommandBuffer commandBuffer,
                                            vk::TessellationDomainOrigin domainOrigin ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setTessellationDomainOriginEXT( domainOrigin );
#else
    s_MockPtr->_SetTessellationDomainOriginEXT( commandBuffer, domainOrigin );
#endif
}

static void SetDepthClampEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClampEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthClampEnableEXT( depthClampEnable );
#else
    s_MockPtr->_SetDepthClampEnableEXT( commandBuffer, depthClampEnable );
#endif
}

static void SetPolygonModeEXT( vk::CommandBuffer commandBuffer, vk::PolygonMode polygonMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setPolygonModeEXT( polygonMode );
#else
    s_MockPtr->_SetPolygonModeEXT( commandBuffer, polygonMode );
#endif
}

static void SetRasterizationSamplesEXT( vk::CommandBuffer commandBuffer,
                                        vk::SampleCountFlagBits rasterizationSamples ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRasterizationSamplesEXT( rasterizationSamples );
#else
    s_MockPtr->_SetRasterizationSamplesEXT( commandBuffer, rasterizationSamples );
#endif
}

static void SetSampleMaskEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits samples,
                              const vk::SampleMask* pSampleMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setSampleMaskEXT( samples, pSampleMask );
#else
    s_MockPtr->_SetSampleMaskEXT( commandBuffer, samples, pSampleMask );
#endif
}

static void SetSampleMaskEXT( vk::CommandBuffer commandBuffer, vk::SampleCountFlagBits samples,
                              vk::ArrayProxy<const vk::SampleMask> const& sampleMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setSampleMaskEXT( samples, sampleMask );
#else
    s_MockPtr->_SetSampleMaskEXT( commandBuffer, samples, sampleMask );
#endif
}

static void SetAlphaToCoverageEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToCoverageEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setAlphaToCoverageEnableEXT( alphaToCoverageEnable );
#else
    s_MockPtr->_SetAlphaToCoverageEnableEXT( commandBuffer, alphaToCoverageEnable );
#endif
}

static void SetAlphaToOneEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 alphaToOneEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setAlphaToOneEnableEXT( alphaToOneEnable );
#else
    s_MockPtr->_SetAlphaToOneEnableEXT( commandBuffer, alphaToOneEnable );
#endif
}

static void SetLogicOpEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 logicOpEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLogicOpEnableEXT( logicOpEnable );
#else
    s_MockPtr->_SetLogicOpEnableEXT( commandBuffer, logicOpEnable );
#endif
}

static void SetColorBlendEnableEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                    const vk::Bool32* pColorBlendEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendEnableEXT( firstAttachment, attachmentCount, pColorBlendEnables );
#else
    s_MockPtr->_SetColorBlendEnableEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendEnables );
#endif
}

static void SetColorBlendEnableEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                    vk::ArrayProxy<const vk::Bool32> const& colorBlendEnables ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendEnableEXT( firstAttachment, colorBlendEnables );
#else
    s_MockPtr->_SetColorBlendEnableEXT( commandBuffer, firstAttachment, colorBlendEnables );
#endif
}

static void SetColorBlendEquationEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                      uint32_t attachmentCount,
                                      const vk::ColorBlendEquationEXT* pColorBlendEquations ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendEquationEXT( firstAttachment, attachmentCount, pColorBlendEquations );
#else
    s_MockPtr->_SetColorBlendEquationEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendEquations );
#endif
}

static void SetColorBlendEquationEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                      vk::ArrayProxy<const vk::ColorBlendEquationEXT> const& colorBlendEquations ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendEquationEXT( firstAttachment, colorBlendEquations );
#else
    s_MockPtr->_SetColorBlendEquationEXT( commandBuffer, firstAttachment, colorBlendEquations );
#endif
}

static void SetColorWriteMaskEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment, uint32_t attachmentCount,
                                  const vk::ColorComponentFlags* pColorWriteMasks ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorWriteMaskEXT( firstAttachment, attachmentCount, pColorWriteMasks );
#else
    s_MockPtr->_SetColorWriteMaskEXT( commandBuffer, firstAttachment, attachmentCount, pColorWriteMasks );
#endif
}

static void SetColorWriteMaskEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                  vk::ArrayProxy<const vk::ColorComponentFlags> const& colorWriteMasks ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorWriteMaskEXT( firstAttachment, colorWriteMasks );
#else
    s_MockPtr->_SetColorWriteMaskEXT( commandBuffer, firstAttachment, colorWriteMasks );
#endif
}

static void SetRasterizationStreamEXT( vk::CommandBuffer commandBuffer, uint32_t rasterizationStream ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRasterizationStreamEXT( rasterizationStream );
#else
    s_MockPtr->_SetRasterizationStreamEXT( commandBuffer, rasterizationStream );
#endif
}

static void
SetConservativeRasterizationModeEXT( vk::CommandBuffer commandBuffer,
                                     vk::ConservativeRasterizationModeEXT conservativeRasterizationMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setConservativeRasterizationModeEXT( conservativeRasterizationMode );
#else
    s_MockPtr->_SetConservativeRasterizationModeEXT( commandBuffer, conservativeRasterizationMode );
#endif
}

static void SetExtraPrimitiveOverestimationSizeEXT( vk::CommandBuffer commandBuffer,
                                                    float extraPrimitiveOverestimationSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setExtraPrimitiveOverestimationSizeEXT( extraPrimitiveOverestimationSize );
#else
    s_MockPtr->_SetExtraPrimitiveOverestimationSizeEXT( commandBuffer, extraPrimitiveOverestimationSize );
#endif
}

static void SetDepthClipEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 depthClipEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthClipEnableEXT( depthClipEnable );
#else
    s_MockPtr->_SetDepthClipEnableEXT( commandBuffer, depthClipEnable );
#endif
}

static void SetSampleLocationsEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 sampleLocationsEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setSampleLocationsEnableEXT( sampleLocationsEnable );
#else
    s_MockPtr->_SetSampleLocationsEnableEXT( commandBuffer, sampleLocationsEnable );
#endif
}

static void SetColorBlendAdvancedEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                      uint32_t attachmentCount,
                                      const vk::ColorBlendAdvancedEXT* pColorBlendAdvanced ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendAdvancedEXT( firstAttachment, attachmentCount, pColorBlendAdvanced );
#else
    s_MockPtr->_SetColorBlendAdvancedEXT( commandBuffer, firstAttachment, attachmentCount, pColorBlendAdvanced );
#endif
}

static void SetColorBlendAdvancedEXT( vk::CommandBuffer commandBuffer, uint32_t firstAttachment,
                                      vk::ArrayProxy<const vk::ColorBlendAdvancedEXT> const& colorBlendAdvanced ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setColorBlendAdvancedEXT( firstAttachment, colorBlendAdvanced );
#else
    s_MockPtr->_SetColorBlendAdvancedEXT( commandBuffer, firstAttachment, colorBlendAdvanced );
#endif
}

static void SetProvokingVertexModeEXT( vk::CommandBuffer commandBuffer,
                                       vk::ProvokingVertexModeEXT provokingVertexMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setProvokingVertexModeEXT( provokingVertexMode );
#else
    s_MockPtr->_SetProvokingVertexModeEXT( commandBuffer, provokingVertexMode );
#endif
}

static void SetLineRasterizationModeEXT( vk::CommandBuffer commandBuffer,
                                         vk::LineRasterizationModeEXT lineRasterizationMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLineRasterizationModeEXT( lineRasterizationMode );
#else
    s_MockPtr->_SetLineRasterizationModeEXT( commandBuffer, lineRasterizationMode );
#endif
}

static void SetLineStippleEnableEXT( vk::CommandBuffer commandBuffer, vk::Bool32 stippledLineEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setLineStippleEnableEXT( stippledLineEnable );
#else
    s_MockPtr->_SetLineStippleEnableEXT( commandBuffer, stippledLineEnable );
#endif
}

static void SetDepthClipNegativeOneToOneEXT( vk::CommandBuffer commandBuffer, vk::Bool32 negativeOneToOne ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setDepthClipNegativeOneToOneEXT( negativeOneToOne );
#else
    s_MockPtr->_SetDepthClipNegativeOneToOneEXT( commandBuffer, negativeOneToOne );
#endif
}

static void SetViewportWScalingEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 viewportWScalingEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportWScalingEnableNV( viewportWScalingEnable );
#else
    s_MockPtr->_SetViewportWScalingEnableNV( commandBuffer, viewportWScalingEnable );
#endif
}

static void SetViewportSwizzleNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport, uint32_t viewportCount,
                                  const vk::ViewportSwizzleNV* pViewportSwizzles ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportSwizzleNV( firstViewport, viewportCount, pViewportSwizzles );
#else
    s_MockPtr->_SetViewportSwizzleNV( commandBuffer, firstViewport, viewportCount, pViewportSwizzles );
#endif
}

static void SetViewportSwizzleNV( vk::CommandBuffer commandBuffer, uint32_t firstViewport,
                                  vk::ArrayProxy<const vk::ViewportSwizzleNV> const& viewportSwizzles ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setViewportSwizzleNV( firstViewport, viewportSwizzles );
#else
    s_MockPtr->_SetViewportSwizzleNV( commandBuffer, firstViewport, viewportSwizzles );
#endif
}

static void SetCoverageToColorEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 coverageToColorEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageToColorEnableNV( coverageToColorEnable );
#else
    s_MockPtr->_SetCoverageToColorEnableNV( commandBuffer, coverageToColorEnable );
#endif
}

static void SetCoverageToColorLocationNV( vk::CommandBuffer commandBuffer, uint32_t coverageToColorLocation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageToColorLocationNV( coverageToColorLocation );
#else
    s_MockPtr->_SetCoverageToColorLocationNV( commandBuffer, coverageToColorLocation );
#endif
}

static void SetCoverageModulationModeNV( vk::CommandBuffer commandBuffer,
                                         vk::CoverageModulationModeNV coverageModulationMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageModulationModeNV( coverageModulationMode );
#else
    s_MockPtr->_SetCoverageModulationModeNV( commandBuffer, coverageModulationMode );
#endif
}

static void SetCoverageModulationTableEnableNV( vk::CommandBuffer commandBuffer,
                                                vk::Bool32 coverageModulationTableEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageModulationTableEnableNV( coverageModulationTableEnable );
#else
    s_MockPtr->_SetCoverageModulationTableEnableNV( commandBuffer, coverageModulationTableEnable );
#endif
}

static void SetCoverageModulationTableNV( vk::CommandBuffer commandBuffer, uint32_t coverageModulationTableCount,
                                          const float* pCoverageModulationTable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageModulationTableNV( coverageModulationTableCount, pCoverageModulationTable );
#else
    s_MockPtr->_SetCoverageModulationTableNV( commandBuffer, coverageModulationTableCount, pCoverageModulationTable );
#endif
}

static void SetCoverageModulationTableNV( vk::CommandBuffer commandBuffer,
                                          vk::ArrayProxy<const float> const& coverageModulationTable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageModulationTableNV( coverageModulationTable );
#else
    s_MockPtr->_SetCoverageModulationTableNV( commandBuffer, coverageModulationTable );
#endif
}

static void SetShadingRateImageEnableNV( vk::CommandBuffer commandBuffer, vk::Bool32 shadingRateImageEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setShadingRateImageEnableNV( shadingRateImageEnable );
#else
    s_MockPtr->_SetShadingRateImageEnableNV( commandBuffer, shadingRateImageEnable );
#endif
}

static void SetRepresentativeFragmentTestEnableNV( vk::CommandBuffer commandBuffer,
                                                   vk::Bool32 representativeFragmentTestEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setRepresentativeFragmentTestEnableNV( representativeFragmentTestEnable );
#else
    s_MockPtr->_SetRepresentativeFragmentTestEnableNV( commandBuffer, representativeFragmentTestEnable );
#endif
}

static void SetCoverageReductionModeNV( vk::CommandBuffer commandBuffer,
                                        vk::CoverageReductionModeNV coverageReductionMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setCoverageReductionModeNV( coverageReductionMode );
#else
    s_MockPtr->_SetCoverageReductionModeNV( commandBuffer, coverageReductionMode );
#endif
}

static void OpticalFlowExecuteNV( vk::CommandBuffer commandBuffer, vk::OpticalFlowSessionNV session,
                                  const vk::OpticalFlowExecuteInfoNV* pExecuteInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.opticalFlowExecuteNV( session, pExecuteInfo );
#else
    s_MockPtr->_OpticalFlowExecuteNV( commandBuffer, session, pExecuteInfo );
#endif
}

static void OpticalFlowExecuteNV( vk::CommandBuffer commandBuffer, vk::OpticalFlowSessionNV session,
                                  const vk::OpticalFlowExecuteInfoNV& executeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.opticalFlowExecuteNV( session, executeInfo );
#else
    s_MockPtr->_OpticalFlowExecuteNV( commandBuffer, session, executeInfo );
#endif
}

static void BindIndexBuffer2KHR( vk::CommandBuffer commandBuffer, vk::Buffer buffer, vk::DeviceSize offset,
                                 vk::DeviceSize size, vk::IndexType indexType ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindIndexBuffer2KHR( buffer, offset, size, indexType );
#else
    s_MockPtr->_BindIndexBuffer2KHR( commandBuffer, buffer, offset, size, indexType );
#endif
}

static void BindShadersEXT( vk::CommandBuffer commandBuffer, uint32_t stageCount,
                            const vk::ShaderStageFlagBits* pStages, const vk::ShaderEXT* pShaders ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindShadersEXT( stageCount, pStages, pShaders );
#else
    s_MockPtr->_BindShadersEXT( commandBuffer, stageCount, pStages, pShaders );
#endif
}

static void BindShadersEXT( vk::CommandBuffer commandBuffer,
                            vk::ArrayProxy<const vk::ShaderStageFlagBits> const& stages,
                            vk::ArrayProxy<const vk::ShaderEXT> const& shaders )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.bindShadersEXT( stages, shaders );
#else
    s_MockPtr->_BindShadersEXT( commandBuffer, stages, shaders );
#endif
}

static void SetAttachmentFeedbackLoopEnableEXT( vk::CommandBuffer commandBuffer, vk::ImageAspectFlags aspectMask ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    commandBuffer.setAttachmentFeedbackLoopEnableEXT( aspectMask );
#else
    s_MockPtr->_SetAttachmentFeedbackLoopEnableEXT( commandBuffer, aspectMask );
#endif
}

static vk::Result Submit( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo* pSubmits, vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.submit( submitCount, pSubmits, fence );
#else
    return s_MockPtr->_Submit( queue, submitCount, pSubmits, fence );
#endif
}

static vk::Result WaitIdle( vk::Queue queue, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.waitIdle();
#else
    return s_MockPtr->_WaitIdle();
#endif
}

static vk::Result WaitIdle( vk::Queue queue, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.waitIdle();
#else
    return s_MockPtr->_WaitIdle();
#endif
}

static vk::Result BindSparse( vk::Queue queue, uint32_t bindInfoCount, const vk::BindSparseInfo* pBindInfo,
                              vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.bindSparse( bindInfoCount, pBindInfo, fence );
#else
    return s_MockPtr->_BindSparse( queue, bindInfoCount, pBindInfo, fence );
#endif
}

static vk::Result Submit2( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo2* pSubmits,
                           vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.submit2( submitCount, pSubmits, fence );
#else
    return s_MockPtr->_Submit2( queue, submitCount, pSubmits, fence );
#endif
}

static vk::Result PresentKHR( vk::Queue queue, const vk::PresentInfoKHR* pPresentInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.presentKHR( pPresentInfo );
#else
    return s_MockPtr->_PresentKHR( queue, pPresentInfo );
#endif
}

static vk::Result PresentKHR( vk::Queue queue, const vk::PresentInfoKHR& presentInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.presentKHR( presentInfo );
#else
    return s_MockPtr->_PresentKHR( queue, presentInfo );
#endif
}

static void BeginDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.beginDebugUtilsLabelEXT( pLabelInfo );
#else
    s_MockPtr->_BeginDebugUtilsLabelEXT( queue, pLabelInfo );
#endif
}

static void BeginDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT& labelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.beginDebugUtilsLabelEXT( labelInfo );
#else
    s_MockPtr->_BeginDebugUtilsLabelEXT( queue, labelInfo );
#endif
}

static void EndDebugUtilsLabelEXT( vk::Queue queue, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.endDebugUtilsLabelEXT();
#else
    s_MockPtr->_EndDebugUtilsLabelEXT();
#endif
}

static void InsertDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT* pLabelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.insertDebugUtilsLabelEXT( pLabelInfo );
#else
    s_MockPtr->_InsertDebugUtilsLabelEXT( queue, pLabelInfo );
#endif
}

static void InsertDebugUtilsLabelEXT( vk::Queue queue, const vk::DebugUtilsLabelEXT& labelInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.insertDebugUtilsLabelEXT( labelInfo );
#else
    s_MockPtr->_InsertDebugUtilsLabelEXT( queue, labelInfo );
#endif
}

static void GetCheckpointDataNV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                 vk::CheckpointDataNV* pCheckpointData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.getCheckpointDataNV( pCheckpointDataCount, pCheckpointData );
#else
    s_MockPtr->_GetCheckpointDataNV( queue, pCheckpointDataCount, pCheckpointData );
#endif
}

template <typename CheckpointDataNVAllocator = std::allocator<vk::CheckpointDataNV>>
static std::vector<vk::CheckpointDataNV, CheckpointDataNVAllocator> GetCheckpointDataNV( vk::Queue queue, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.getCheckpointDataNV();
#else
    return s_MockPtr->_GetCheckpointDataNV();
#endif
}

template <typename CheckpointDataNVAllocator = std::allocator<vk::CheckpointDataNV>,
          typename B1 = CheckpointDataNVAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, CheckpointDataNV>::value, int>::type = 0>
static std::vector<vk::CheckpointDataNV, CheckpointDataNVAllocator>
GetCheckpointDataNV( vk::Queue queue, CheckpointDataNVAllocator& checkpointDataNVAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.getCheckpointDataNV( checkpointDataNVAllocator );
#else
    return s_MockPtr->_GetCheckpointDataNV( queue, checkpointDataNVAllocator );
#endif
}

static vk::Result SetPerformanceConfigurationINTEL( vk::Queue queue,
                                                    vk::PerformanceConfigurationINTEL configuration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.setPerformanceConfigurationINTEL( configuration );
#else
    return s_MockPtr->_SetPerformanceConfigurationINTEL( queue, configuration );
#endif
}

static vk::Result SetPerformanceConfigurationINTEL( vk::Queue queue,
                                                    vk::PerformanceConfigurationINTEL configuration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.setPerformanceConfigurationINTEL( configuration );
#else
    return s_MockPtr->_SetPerformanceConfigurationINTEL( queue, configuration );
#endif
}

static vk::Result Submit2KHR( vk::Queue queue, uint32_t submitCount, const vk::SubmitInfo2* pSubmits,
                              vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.submit2KHR( submitCount, pSubmits, fence );
#else
    return s_MockPtr->_Submit2KHR( queue, submitCount, pSubmits, fence );
#endif
}

static void GetCheckpointData2NV( vk::Queue queue, uint32_t* pCheckpointDataCount,
                                  vk::CheckpointData2NV* pCheckpointData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    queue.getCheckpointData2NV( pCheckpointDataCount, pCheckpointData );
#else
    s_MockPtr->_GetCheckpointData2NV( queue, pCheckpointDataCount, pCheckpointData );
#endif
}

template <typename CheckpointData2NVAllocator = std::allocator<vk::CheckpointData2NV>>
static std::vector<vk::CheckpointData2NV, CheckpointData2NVAllocator> GetCheckpointData2NV( vk::Queue queue, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.getCheckpointData2NV();
#else
    return s_MockPtr->_GetCheckpointData2NV();
#endif
}

template <typename CheckpointData2NVAllocator = std::allocator<vk::CheckpointData2NV>,
          typename B1 = CheckpointData2NVAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, CheckpointData2NV>::value, int>::type = 0>
static std::vector<vk::CheckpointData2NV, CheckpointData2NVAllocator>
GetCheckpointData2NV( vk::Queue queue, CheckpointData2NVAllocator& checkpointData2NVAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return queue.getCheckpointData2NV( checkpointData2NVAllocator );
#else
    return s_MockPtr->_GetCheckpointData2NV( queue, checkpointData2NVAllocator );
#endif
}

static void Destroy( vk::Device device, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pAllocator );
#else
    s_MockPtr->_Destroy( device, pAllocator );
#endif
}

static void GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex, vk::Queue* pQueue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getQueue( queueFamilyIndex, queueIndex, pQueue );
#else
    s_MockPtr->_GetQueue( device, queueFamilyIndex, queueIndex, pQueue );
#endif
}

static vk::Queue GetQueue( vk::Device device, uint32_t queueFamilyIndex, uint32_t queueIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getQueue( queueFamilyIndex, queueIndex );
#else
    return s_MockPtr->_GetQueue( device, queueFamilyIndex, queueIndex );
#endif
}

static vk::Result WaitIdle( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitIdle();
#else
    return s_MockPtr->_WaitIdle();
#endif
}

static vk::Result WaitIdle( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitIdle();
#else
    return s_MockPtr->_WaitIdle();
#endif
}

static vk::Result AllocateMemory( vk::Device device, const vk::MemoryAllocateInfo* pAllocateInfo,
                                  const vk::AllocationCallbacks* pAllocator, vk::DeviceMemory* pMemory ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateMemory( pAllocateInfo, pAllocator, pMemory );
#else
    return s_MockPtr->_AllocateMemory( device, pAllocateInfo, pAllocator, pMemory );
#endif
}

static void FreeMemory( vk::Device device, vk::DeviceMemory memory, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.freeMemory( memory, pAllocator );
#else
    s_MockPtr->_FreeMemory( device, memory, pAllocator );
#endif
}

static vk::Result MapMemory( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize offset, vk::DeviceSize size,
                             vk::MemoryMapFlags flags, void** ppData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mapMemory( memory, offset, size, flags, ppData );
#else
    return s_MockPtr->_MapMemory( device, memory, offset, size, flags, ppData );
#endif
}

static void UnmapMemory( vk::Device device, vk::DeviceMemory memory ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.unmapMemory( memory );
#else
    s_MockPtr->_UnmapMemory( device, memory );
#endif
}

static vk::Result FlushMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                           const vk::MappedMemoryRange* pMemoryRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.flushMappedMemoryRanges( memoryRangeCount, pMemoryRanges );
#else
    return s_MockPtr->_FlushMappedMemoryRanges( device, memoryRangeCount, pMemoryRanges );
#endif
}

static vk::Result FlushMappedMemoryRanges( vk::Device device,
                                           vk::ArrayProxy<const vk::MappedMemoryRange> const& memoryRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.flushMappedMemoryRanges( memoryRanges );
#else
    return s_MockPtr->_FlushMappedMemoryRanges( device, memoryRanges );
#endif
}

static vk::Result InvalidateMappedMemoryRanges( vk::Device device, uint32_t memoryRangeCount,
                                                const vk::MappedMemoryRange* pMemoryRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.invalidateMappedMemoryRanges( memoryRangeCount, pMemoryRanges );
#else
    return s_MockPtr->_InvalidateMappedMemoryRanges( device, memoryRangeCount, pMemoryRanges );
#endif
}

static vk::Result InvalidateMappedMemoryRanges( vk::Device device,
                                                vk::ArrayProxy<const vk::MappedMemoryRange> const& memoryRanges ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.invalidateMappedMemoryRanges( memoryRanges );
#else
    return s_MockPtr->_InvalidateMappedMemoryRanges( device, memoryRanges );
#endif
}

static void GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory,
                                 vk::DeviceSize* pCommittedMemoryInBytes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getMemoryCommitment( memory, pCommittedMemoryInBytes );
#else
    s_MockPtr->_GetMemoryCommitment( device, memory, pCommittedMemoryInBytes );
#endif
}

static vk::DeviceSize GetMemoryCommitment( vk::Device device, vk::DeviceMemory memory ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryCommitment( memory );
#else
    return s_MockPtr->_GetMemoryCommitment( device, memory );
#endif
}

static vk::Result BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory,
                                    vk::DeviceSize memoryOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory( buffer, memory, memoryOffset );
#else
    return s_MockPtr->_BindBufferMemory( device, buffer, memory, memoryOffset );
#endif
}

static vk::Result BindBufferMemory( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory,
                                    vk::DeviceSize memoryOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory( buffer, memory, memoryOffset );
#else
    return s_MockPtr->_BindBufferMemory( device, buffer, memory, memoryOffset );
#endif
}

static vk::Result BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                   vk::DeviceSize memoryOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory( image, memory, memoryOffset );
#else
    return s_MockPtr->_BindImageMemory( device, image, memory, memoryOffset );
#endif
}

static vk::Result BindImageMemory( vk::Device device, vk::Image image, vk::DeviceMemory memory,
                                   vk::DeviceSize memoryOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory( image, memory, memoryOffset );
#else
    return s_MockPtr->_BindImageMemory( device, image, memory, memoryOffset );
#endif
}

static void GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer,
                                         vk::MemoryRequirements* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getBufferMemoryRequirements( buffer, pMemoryRequirements );
#else
    s_MockPtr->_GetBufferMemoryRequirements( device, buffer, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements GetBufferMemoryRequirements( vk::Device device, vk::Buffer buffer ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements( buffer );
#else
    return s_MockPtr->_GetBufferMemoryRequirements( device, buffer );
#endif
}

static void GetImageMemoryRequirements( vk::Device device, vk::Image image,
                                        vk::MemoryRequirements* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageMemoryRequirements( image, pMemoryRequirements );
#else
    s_MockPtr->_GetImageMemoryRequirements( device, image, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements GetImageMemoryRequirements( vk::Device device, vk::Image image ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements( image );
#else
    return s_MockPtr->_GetImageMemoryRequirements( device, image );
#endif
}

static void GetImageSparseMemoryRequirements( vk::Device device, vk::Image image,
                                              uint32_t* pSparseMemoryRequirementCount,
                                              vk::SparseImageMemoryRequirements* pSparseMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSparseMemoryRequirements( image, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
#else
    s_MockPtr->_GetImageSparseMemoryRequirements( device, image, pSparseMemoryRequirementCount,
                                                  pSparseMemoryRequirements );
#endif
}

template <typename SparseImageMemoryRequirementsAllocator = std::allocator<vk::SparseImageMemoryRequirements>>
static std::vector<vk::SparseImageMemoryRequirements, SparseImageMemoryRequirementsAllocator>
GetImageSparseMemoryRequirements( vk::Device device, vk::Image image ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements( image );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements( device, image );
#endif
}

template <typename SparseImageMemoryRequirementsAllocator = std::allocator<vk::SparseImageMemoryRequirements>,
          typename B1 = SparseImageMemoryRequirementsAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageMemoryRequirements>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageMemoryRequirements, SparseImageMemoryRequirementsAllocator>
GetImageSparseMemoryRequirements( vk::Device device, vk::Image image,
                                  SparseImageMemoryRequirementsAllocator& sparseImageMemoryRequirementsAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements( image, sparseImageMemoryRequirementsAllocator );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements( device, image, sparseImageMemoryRequirementsAllocator );
#endif
}

static vk::Result CreateFence( vk::Device device, const vk::FenceCreateInfo* pCreateInfo,
                               const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createFence( pCreateInfo, pAllocator, pFence );
#else
    return s_MockPtr->_CreateFence( device, pCreateInfo, pAllocator, pFence );
#endif
}

static ResultValue<vk::Result, vk::Fence>
CreateFence( vk::Device device, const vk::FenceCreateInfo& createInfo,
             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createFence( createInfo, nullptr );
#else
    return s_MockPtr->_CreateFence( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, vk::UniqueHandle<vk::Fence, vk::Dispatch>>
CreateFenceUnique( vk::Device device, const vk::FenceCreateInfo& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createFenceUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateFenceUnique( device, createInfo, nullptr );
#endif
}

static void DestroyFence( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyFence( fence, pAllocator );
#else
    s_MockPtr->_DestroyFence( device, fence, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Fence fence, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( fence, pAllocator );
#else
    s_MockPtr->_Destroy( device, fence, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Fence fence,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( fence, nullptr );
#else
    s_MockPtr->_Destroy( device, fence, nullptr );
#endif
}

static vk::Result ResetFences( vk::Device device, uint32_t fenceCount, const vk::Fence* pFences ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetFences( fenceCount, pFences );
#else
    return s_MockPtr->_ResetFences( device, fenceCount, pFences );
#endif
}

static vk::Result ResetFences( vk::Device device, vk::ArrayProxy<const vk::Fence> const& fences ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetFences( fences );
#else
    return s_MockPtr->_ResetFences( device, fences );
#endif
}

static vk::Result GetFenceStatus( vk::Device device, vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceStatus( fence );
#else
    return s_MockPtr->_GetFenceStatus( device, fence );
#endif
}

static vk::Result GetFenceStatus( vk::Device device, vk::Fence fence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceStatus( fence );
#else
    return s_MockPtr->_GetFenceStatus( device, fence );
#endif
}

static vk::Result WaitForFences( vk::Device device, uint32_t fenceCount, const vk::Fence* pFences, vk::Bool32 waitAll,
                                 uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitForFences( fenceCount, pFences, waitAll, timeout );
#else
    return s_MockPtr->_WaitForFences( device, fenceCount, pFences, waitAll, timeout );
#endif
}

static vk::Result WaitForFences( vk::Device device, vk::ArrayProxy<const vk::Fence> const& fences, vk::Bool32 waitAll,
                                 uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitForFences( fences, waitAll, timeout );
#else
    return s_MockPtr->_WaitForFences( device, fences, waitAll, timeout );
#endif
}

static vk::Result CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator, vk::Semaphore* pSemaphore ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSemaphore( pCreateInfo, pAllocator, pSemaphore );
#else
    return s_MockPtr->_CreateSemaphore( device, pCreateInfo, pAllocator, pSemaphore );
#endif
}

static ResultValue<vk::Result, vk::Semaphore>
CreateSemaphore( vk::Device device, const vk::SemaphoreCreateInfo& createInfo,
                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSemaphore( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSemaphore( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, vk::UniqueHandle<vk::Semaphore, vk::Dispatch>>
CreateSemaphoreUnique( vk::Device device, const vk::SemaphoreCreateInfo& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSemaphoreUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSemaphoreUnique( device, createInfo, nullptr );
#endif
}

static void DestroySemaphore( vk::Device device, vk::Semaphore semaphore,
                              const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroySemaphore( semaphore, pAllocator );
#else
    s_MockPtr->_DestroySemaphore( device, semaphore, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Semaphore semaphore, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( semaphore, pAllocator );
#else
    s_MockPtr->_Destroy( device, semaphore, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Semaphore semaphore,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( semaphore, nullptr );
#else
    s_MockPtr->_Destroy( device, semaphore, nullptr );
#endif
}

static vk::Result CreateEvent( vk::Device device, const vk::EventCreateInfo* pCreateInfo,
                               const vk::AllocationCallbacks* pAllocator, vk::Event* pEvent ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createEvent( pCreateInfo, pAllocator, pEvent );
#else
    return s_MockPtr->_CreateEvent( device, pCreateInfo, pAllocator, pEvent );
#endif
}

static ResultValue<vk::Result, vk::Event>
CreateEvent( vk::Device device, const vk::EventCreateInfo& createInfo,
             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createEvent( createInfo, nullptr );
#else
    return s_MockPtr->_CreateEvent( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, vk::UniqueHandle<vk::Event, vk::Dispatch>>
CreateEventUnique( vk::Device device, const vk::EventCreateInfo& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createEventUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateEventUnique( device, createInfo, nullptr );
#endif
}

static void DestroyEvent( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyEvent( event, pAllocator );
#else
    s_MockPtr->_DestroyEvent( device, event, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Event event, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( event, pAllocator );
#else
    s_MockPtr->_Destroy( device, event, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Event event,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( event, nullptr );
#else
    s_MockPtr->_Destroy( device, event, nullptr );
#endif
}

static vk::Result GetEventStatus( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getEventStatus( event );
#else
    return s_MockPtr->_GetEventStatus( device, event );
#endif
}

static vk::Result GetEventStatus( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getEventStatus( event );
#else
    return s_MockPtr->_GetEventStatus( device, event );
#endif
}

static vk::Result SetEvent( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setEvent( event );
#else
    return s_MockPtr->_SetEvent( device, event );
#endif
}

static vk::Result SetEvent( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setEvent( event );
#else
    return s_MockPtr->_SetEvent( device, event );
#endif
}

static vk::Result ResetEvent( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetEvent( event );
#else
    return s_MockPtr->_ResetEvent( device, event );
#endif
}

static vk::Result ResetEvent( vk::Device device, vk::Event event ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetEvent( event );
#else
    return s_MockPtr->_ResetEvent( device, event );
#endif
}

static vk::Result CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator, vk::QueryPool* pQueryPool ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createQueryPool( pCreateInfo, pAllocator, pQueryPool );
#else
    return s_MockPtr->_CreateQueryPool( device, pCreateInfo, pAllocator, pQueryPool );
#endif
}

static ResultValue<vk::Result, vk::QueryPool>
CreateQueryPool( vk::Device device, const vk::QueryPoolCreateInfo& createInfo,
                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createQueryPool( createInfo, nullptr );
#else
    return s_MockPtr->_CreateQueryPool( device, createInfo, nullptr );
#endif
}

static void DestroyQueryPool( vk::Device device, vk::QueryPool queryPool,
                              const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyQueryPool( queryPool, pAllocator );
#else
    s_MockPtr->_DestroyQueryPool( device, queryPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::QueryPool queryPool, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( queryPool, pAllocator );
#else
    s_MockPtr->_Destroy( device, queryPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::QueryPool queryPool,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( queryPool, nullptr );
#else
    s_MockPtr->_Destroy( device, queryPool, nullptr );
#endif
}

static vk::Result GetQueryPoolResults( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                                       uint32_t queryCount, size_t dataSize, void* pData, vk::DeviceSize stride,
                                       vk::QueryResultFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getQueryPoolResults( queryPool, firstQuery, queryCount, dataSize, pData, stride, flags );
#else
    return s_MockPtr->_GetQueryPoolResults( device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>

template <typename DataType>

static vk::Result CreateBuffer( vk::Device device, const vk::BufferCreateInfo* pCreateInfo,
                                const vk::AllocationCallbacks* pAllocator, vk::Buffer* pBuffer ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createBuffer( pCreateInfo, pAllocator, pBuffer );
#else
    return s_MockPtr->_CreateBuffer( device, pCreateInfo, pAllocator, pBuffer );
#endif
}

static ResultValue<vk::Result, vk::Buffer>
CreateBuffer( vk::Device device, const vk::BufferCreateInfo& createInfo,
              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createBuffer( createInfo, nullptr );
#else
    return s_MockPtr->_CreateBuffer( device, createInfo, nullptr );
#endif
}

static void DestroyBuffer( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyBuffer( buffer, pAllocator );
#else
    s_MockPtr->_DestroyBuffer( device, buffer, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Buffer buffer, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( buffer, pAllocator );
#else
    s_MockPtr->_Destroy( device, buffer, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Buffer buffer,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( buffer, nullptr );
#else
    s_MockPtr->_Destroy( device, buffer, nullptr );
#endif
}

static vk::Result CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo* pCreateInfo,
                                    const vk::AllocationCallbacks* pAllocator, vk::BufferView* pView ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createBufferView( pCreateInfo, pAllocator, pView );
#else
    return s_MockPtr->_CreateBufferView( device, pCreateInfo, pAllocator, pView );
#endif
}

static ResultValueType<vk::Result, vk::BufferView>
CreateBufferView( vk::Device device, const vk::BufferViewCreateInfo& createInfo,
                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createBufferView( createInfo, nullptr );
#else
    return s_MockPtr->_CreateBufferView( device, createInfo, nullptr );
#endif
}

static void DestroyBufferView( vk::Device device, vk::BufferView bufferView,
                               const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyBufferView( bufferView, pAllocator );
#else
    s_MockPtr->_DestroyBufferView( device, bufferView, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::BufferView bufferView, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( bufferView, pAllocator );
#else
    s_MockPtr->_Destroy( device, bufferView, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::BufferView bufferView,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( bufferView, nullptr );
#else
    s_MockPtr->_Destroy( device, bufferView, nullptr );
#endif
}

static vk::Result CreateImage( vk::Device device, const vk::ImageCreateInfo* pCreateInfo,
                               const vk::AllocationCallbacks* pAllocator, vk::Image* pImage ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createImage( pCreateInfo, pAllocator, pImage );
#else
    return s_MockPtr->_CreateImage( device, pCreateInfo, pAllocator, pImage );
#endif
}

static ResultValue<vk::Result, vk::Image>
CreateImage( vk::Device device, const vk::ImageCreateInfo& createInfo,
             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createImage( createInfo, nullptr );
#else
    return s_MockPtr->_CreateImage( device, createInfo, nullptr );
#endif
}

static void DestroyImage( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyImage( image, pAllocator );
#else
    s_MockPtr->_DestroyImage( device, image, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Image image, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( image, pAllocator );
#else
    s_MockPtr->_Destroy( device, image, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Image image,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( image, nullptr );
#else
    s_MockPtr->_Destroy( device, image, nullptr );
#endif
}

static void GetImageSubresourceLayout( vk::Device device, vk::Image image, const vk::ImageSubresource* pSubresource,
                                       vk::SubresourceLayout* pLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSubresourceLayout( image, pSubresource, pLayout );
#else
    s_MockPtr->_GetImageSubresourceLayout( device, image, pSubresource, pLayout );
#endif
}

static vk::SubresourceLayout GetImageSubresourceLayout( vk::Device device, vk::Image image,
                                                        const vk::ImageSubresource& subresource ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayout( image, subresource );
#else
    return s_MockPtr->_GetImageSubresourceLayout( device, image, subresource );
#endif
}

static vk::Result CreateImageView( vk::Device device, const vk::ImageViewCreateInfo* pCreateInfo,
                                   const vk::AllocationCallbacks* pAllocator, vk::ImageView* pView ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createImageView( pCreateInfo, pAllocator, pView );
#else
    return s_MockPtr->_CreateImageView( device, pCreateInfo, pAllocator, pView );
#endif
}

static ResultValue<vk::Result, vk::ImageView>
CreateImageView( vk::Device device, const vk::ImageViewCreateInfo& createInfo,
                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createImageView( createInfo, nullptr );
#else
    return s_MockPtr->_CreateImageView( device, createInfo, nullptr );
#endif
}

static void DestroyImageView( vk::Device device, vk::ImageView imageView,
                              const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyImageView( imageView, pAllocator );
#else
    s_MockPtr->_DestroyImageView( device, imageView, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ImageView imageView, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( imageView, pAllocator );
#else
    s_MockPtr->_Destroy( device, imageView, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ImageView imageView,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( imageView, nullptr );
#else
    s_MockPtr->_Destroy( device, imageView, nullptr );
#endif
}

static vk::Result CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator, vk::ShaderModule* pShaderModule ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShaderModule( pCreateInfo, pAllocator, pShaderModule );
#else
    return s_MockPtr->_CreateShaderModule( device, pCreateInfo, pAllocator, pShaderModule );
#endif
}

static ResultValue<vk::Result, vk::ShaderModule>
CreateShaderModule( vk::Device device, const vk::ShaderModuleCreateInfo& createInfo,
                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShaderModule( createInfo, nullptr );
#else
    return s_MockPtr->_CreateShaderModule( device, createInfo, nullptr );
#endif
}

static void DestroyShaderModule( vk::Device device, vk::ShaderModule shaderModule,
                                 const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyShaderModule( shaderModule, pAllocator );
#else
    s_MockPtr->_DestroyShaderModule( device, shaderModule, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ShaderModule shaderModule, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( shaderModule, pAllocator );
#else
    s_MockPtr->_Destroy( device, shaderModule, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ShaderModule shaderModule,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( shaderModule, nullptr );
#else
    s_MockPtr->_Destroy( device, shaderModule, nullptr );
#endif
}

static vk::Result CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator,
                                       vk::PipelineCache* pPipelineCache ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPipelineCache( pCreateInfo, pAllocator, pPipelineCache );
#else
    return s_MockPtr->_CreatePipelineCache( device, pCreateInfo, pAllocator, pPipelineCache );
#endif
}

static ResultValue<vk::Result, vk::PipelineCache>
CreatePipelineCache( vk::Device device, const vk::PipelineCacheCreateInfo& createInfo,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPipelineCache( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePipelineCache( device, createInfo, nullptr );
#endif
}

static void DestroyPipelineCache( vk::Device device, vk::PipelineCache pipelineCache,
                                  const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyPipelineCache( pipelineCache, pAllocator );
#else
    s_MockPtr->_DestroyPipelineCache( device, pipelineCache, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipelineCache, pAllocator );
#else
    s_MockPtr->_Destroy( device, pipelineCache, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PipelineCache pipelineCache,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipelineCache, nullptr );
#else
    s_MockPtr->_Destroy( device, pipelineCache, nullptr );
#endif
}

static vk::Result GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache, size_t* pDataSize,
                                        void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineCacheData( pipelineCache, pDataSize, pData );
#else
    return s_MockPtr->_GetPipelineCacheData( device, pipelineCache, pDataSize, pData );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineCacheData( pipelineCache );
#else
    return s_MockPtr->_GetPipelineCacheData( device, pipelineCache );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>, typename B1 = Uint8_tAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, uint8_t>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetPipelineCacheData( vk::Device device, vk::PipelineCache pipelineCache, Uint8_tAllocator& uint8_tAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineCacheData( pipelineCache, uint8_tAllocator );
#else
    return s_MockPtr->_GetPipelineCacheData( device, pipelineCache, uint8_tAllocator );
#endif
}

static vk::Result MergePipelineCaches( vk::Device device, vk::PipelineCache dstCache, uint32_t srcCacheCount,
                                       const vk::PipelineCache* pSrcCaches ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mergePipelineCaches( dstCache, srcCacheCount, pSrcCaches );
#else
    return s_MockPtr->_MergePipelineCaches( device, dstCache, srcCacheCount, pSrcCaches );
#endif
}

static vk::Result MergePipelineCaches( vk::Device device, vk::PipelineCache dstCache,
                                       vk::ArrayProxy<const vk::PipelineCache> const& srcCaches ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mergePipelineCaches( dstCache, srcCaches );
#else
    return s_MockPtr->_MergePipelineCaches( device, dstCache, srcCaches );
#endif
}

static vk::Result CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                           const vk::GraphicsPipelineCreateInfo* pCreateInfos,
                                           const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createGraphicsPipelines( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
#else
    return s_MockPtr->_CreateGraphicsPipelines( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                pPipelines );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>>
static ResultValue<vk::Result, std::vector<vk::Pipeline, PipelineAllocator>>
CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache,
                         vk::ArrayProxy<const vk::GraphicsPipelineCreateInfo> const& createInfos,
                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createGraphicsPipelines( pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateGraphicsPipelines( device, pipelineCache, createInfos, nullptr );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>, typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, Pipeline>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::Pipeline, PipelineAllocator>>
CreateGraphicsPipelines( vk::Device device, vk::PipelineCache pipelineCache,
                         vk::ArrayProxy<const vk::GraphicsPipelineCreateInfo> const& createInfos,
                         Optional<const vk::AllocationCallbacks> allocator, PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createGraphicsPipelines( pipelineCache, createInfos, allocator, pipelineAllocator );
#else
    return s_MockPtr->_CreateGraphicsPipelines( device, pipelineCache, createInfos, allocator, pipelineAllocator );
#endif
}

static ResultValue<vk::Result, vk::Pipeline>
CreateGraphicsPipeline( vk::Device device, vk::PipelineCache pipelineCache,
                        const vk::GraphicsPipelineCreateInfo& createInfo,
                        Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createGraphicsPipeline( pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateGraphicsPipeline( device, pipelineCache, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::Pipeline, Dispatch>>
CreateGraphicsPipelineUnique( vk::Device device, vk::PipelineCache pipelineCache,
                              const vk::GraphicsPipelineCreateInfo& createInfo,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createGraphicsPipelineUnique( pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateGraphicsPipelineUnique( device, pipelineCache, createInfo, nullptr );
#endif
}

static vk::Result CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                          const vk::ComputePipelineCreateInfo* pCreateInfos,
                                          const vk::AllocationCallbacks* pAllocator, vk::Pipeline* pPipelines ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createComputePipelines( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
#else
    return s_MockPtr->_CreateComputePipelines( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                               pPipelines );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>>
static ResultValue<vk::Result, std::vector<vk::Pipeline, PipelineAllocator>>
CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                        vk::ArrayProxy<const vk::ComputePipelineCreateInfo> const& createInfos,
                        Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createComputePipelines( pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateComputePipelines( device, pipelineCache, createInfos, nullptr );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>, typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, Pipeline>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::Pipeline, PipelineAllocator>>
CreateComputePipelines( vk::Device device, vk::PipelineCache pipelineCache,
                        vk::ArrayProxy<const vk::ComputePipelineCreateInfo> const& createInfos,
                        Optional<const vk::AllocationCallbacks> allocator, PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createComputePipelines( pipelineCache, createInfos, allocator, pipelineAllocator );
#else
    return s_MockPtr->_CreateComputePipelines( device, pipelineCache, createInfos, allocator, pipelineAllocator );
#endif
}

static ResultValue<vk::Result, vk::Pipeline>
CreateComputePipeline( vk::Device device, vk::PipelineCache pipelineCache,
                       const vk::ComputePipelineCreateInfo& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createComputePipeline( pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateComputePipeline( device, pipelineCache, createInfo, nullptr );
#endif
}

static void DestroyPipeline( vk::Device device, vk::Pipeline pipeline, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyPipeline( pipeline, pAllocator );
#else
    s_MockPtr->_DestroyPipeline( device, pipeline, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Pipeline pipeline, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipeline, pAllocator );
#else
    s_MockPtr->_Destroy( device, pipeline, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Pipeline pipeline,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipeline, nullptr );
#else
    s_MockPtr->_Destroy( device, pipeline, nullptr );
#endif
}

static vk::Result CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::PipelineLayout* pPipelineLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPipelineLayout( pCreateInfo, pAllocator, pPipelineLayout );
#else
    return s_MockPtr->_CreatePipelineLayout( device, pCreateInfo, pAllocator, pPipelineLayout );
#endif
}

static ResultValue<vk::Result, vk::PipelineLayout>
CreatePipelineLayout( vk::Device device, const vk::PipelineLayoutCreateInfo& createInfo,
                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPipelineLayout( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePipelineLayout( device, createInfo, nullptr );
#endif
}

static void DestroyPipelineLayout( vk::Device device, vk::PipelineLayout pipelineLayout,
                                   const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyPipelineLayout( pipelineLayout, pAllocator );
#else
    s_MockPtr->_DestroyPipelineLayout( device, pipelineLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipelineLayout, pAllocator );
#else
    s_MockPtr->_Destroy( device, pipelineLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PipelineLayout pipelineLayout,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( pipelineLayout, nullptr );
#else
    s_MockPtr->_Destroy( device, pipelineLayout, nullptr );
#endif
}

static vk::Result CreateSampler( vk::Device device, const vk::SamplerCreateInfo* pCreateInfo,
                                 const vk::AllocationCallbacks* pAllocator, vk::Sampler* pSampler ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSampler( pCreateInfo, pAllocator, pSampler );
#else
    return s_MockPtr->_CreateSampler( device, pCreateInfo, pAllocator, pSampler );
#endif
}

static ResultValue<vk::Sampler> CreateSampler( vk::Device device, const vk::SamplerCreateInfo& createInfo,
                                               Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSampler( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSampler( device, createInfo, nullptr );
#endif
}

static void DestroySampler( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroySampler( sampler, pAllocator );
#else
    s_MockPtr->_DestroySampler( device, sampler, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Sampler sampler, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( sampler, pAllocator );
#else
    s_MockPtr->_Destroy( device, sampler, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Sampler sampler,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( sampler, nullptr );
#else
    s_MockPtr->_Destroy( device, sampler, nullptr );
#endif
}

static vk::Result CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                             const vk::AllocationCallbacks* pAllocator,
                                             vk::DescriptorSetLayout* pSetLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorSetLayout( pCreateInfo, pAllocator, pSetLayout );
#else
    return s_MockPtr->_CreateDescriptorSetLayout( device, pCreateInfo, pAllocator, pSetLayout );
#endif
}

static ResultValue<vk::Result, vk::DescriptorSetLayout>
CreateDescriptorSetLayout( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo,
                           Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorSetLayout( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorSetLayout( device, createInfo, nullptr );
#endif
}

static void DestroyDescriptorSetLayout( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                                        const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyDescriptorSetLayout( descriptorSetLayout, pAllocator );
#else
    s_MockPtr->_DestroyDescriptorSetLayout( device, descriptorSetLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorSetLayout, pAllocator );
#else
    s_MockPtr->_Destroy( device, descriptorSetLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorSetLayout descriptorSetLayout,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorSetLayout, nullptr );
#else
    s_MockPtr->_Destroy( device, descriptorSetLayout, nullptr );
#endif
}

static vk::Result CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator,
                                        vk::DescriptorPool* pDescriptorPool ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorPool( pCreateInfo, pAllocator, pDescriptorPool );
#else
    return s_MockPtr->_CreateDescriptorPool( device, pCreateInfo, pAllocator, pDescriptorPool );
#endif
}

static ResultValue<vk::Result, vk::DescriptorPool>
CreateDescriptorPool( vk::Device device, const vk::DescriptorPoolCreateInfo& createInfo,
                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorPool( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorPool( device, createInfo, nullptr );
#endif
}

static void DestroyDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                   const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyDescriptorPool( descriptorPool, pAllocator );
#else
    s_MockPtr->_DestroyDescriptorPool( device, descriptorPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorPool, pAllocator );
#else
    s_MockPtr->_Destroy( device, descriptorPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorPool descriptorPool,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorPool, nullptr );
#else
    s_MockPtr->_Destroy( device, descriptorPool, nullptr );
#endif
}

static vk::Result ResetDescriptorPool( vk::Device device, vk::DescriptorPool descriptorPool,
                                       vk::DescriptorPoolResetFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetDescriptorPool( descriptorPool, flags );
#else
    return s_MockPtr->_ResetDescriptorPool( device, descriptorPool, flags );
#endif
}

static vk::Result AllocateDescriptorSets( vk::Device device, const vk::DescriptorSetAllocateInfo* pAllocateInfo,
                                          vk::DescriptorSet* pDescriptorSets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateDescriptorSets( pAllocateInfo, pDescriptorSets );
#else
    return s_MockPtr->_AllocateDescriptorSets( device, pAllocateInfo, pDescriptorSets );
#endif
}

template <typename DescriptorSetAllocator = std::allocator<vk::DescriptorSet>>
static ResultValue<vk::Result, std::vector<vk::DescriptorSet, DescriptorSetAllocator>>
AllocateDescriptorSets( vk::Device device, const vk::DescriptorSetAllocateInfo& allocateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateDescriptorSets( allocateInfo );
#else
    return s_MockPtr->_AllocateDescriptorSets( device, allocateInfo );
#endif
}

template <typename DescriptorSetAllocator = std::allocator<vk::DescriptorSet>, typename B0 = DescriptorSetAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, DescriptorSet>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DescriptorSet, DescriptorSetAllocator>>
AllocateDescriptorSets( vk::Device device, const vk::DescriptorSetAllocateInfo& allocateInfo,
                        DescriptorSetAllocator& descriptorSetAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateDescriptorSets( allocateInfo, descriptorSetAllocator );
#else
    return s_MockPtr->_AllocateDescriptorSets( device, allocateInfo, descriptorSetAllocator );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename DescriptorSetAllocator = std::allocator<UniqueHandle<vk::DescriptorSet, Dispatch>>>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::DescriptorSet, Dispatch>, DescriptorSetAllocator>>
AllocateDescriptorSetsUnique( vk::Device device, const vk::DescriptorSetAllocateInfo& allocateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateDescriptorSetsUnique( allocateInfo );
#else
    return s_MockPtr->_AllocateDescriptorSetsUnique( device, allocateInfo );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename DescriptorSetAllocator = std::allocator<UniqueHandle<vk::DescriptorSet, Dispatch>>,
          typename B0 = DescriptorSetAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, UniqueHandle<DescriptorSet, Dispatch>>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::DescriptorSet, Dispatch>, DescriptorSetAllocator>>
AllocateDescriptorSetsUnique( vk::Device device, const vk::DescriptorSetAllocateInfo& allocateInfo,
                              DescriptorSetAllocator& descriptorSetAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateDescriptorSetsUnique( allocateInfo, descriptorSetAllocator );
#else
    return s_MockPtr->_AllocateDescriptorSetsUnique( device, allocateInfo, descriptorSetAllocator );
#endif
}

static vk::Result FreeDescriptorSets( vk::Device device, vk::DescriptorPool descriptorPool, uint32_t descriptorSetCount,
                                      const vk::DescriptorSet* pDescriptorSets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.freeDescriptorSets( descriptorPool, descriptorSetCount, pDescriptorSets );
#else
    return s_MockPtr->_FreeDescriptorSets( device, descriptorPool, descriptorSetCount, pDescriptorSets );
#endif
}

static void FreeDescriptorSets( vk::Device device, vk::DescriptorPool descriptorPool,
                                vk::ArrayProxy<const vk::DescriptorSet> const& descriptorSets ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.freeDescriptorSets( descriptorPool, descriptorSets );
#else
    s_MockPtr->_FreeDescriptorSets( device, descriptorPool, descriptorSets );
#endif
}

static void UpdateDescriptorSets( vk::Device device, uint32_t descriptorWriteCount,
                                  const vk::WriteDescriptorSet* pDescriptorWrites, uint32_t descriptorCopyCount,
                                  const vk::CopyDescriptorSet* pDescriptorCopies ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSets( descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies );
#else
    s_MockPtr->_UpdateDescriptorSets( device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                                      pDescriptorCopies );
#endif
}

static void UpdateDescriptorSets( vk::Device device,
                                  vk::ArrayProxy<const vk::WriteDescriptorSet> const& descriptorWrites,
                                  vk::ArrayProxy<const vk::CopyDescriptorSet> const& descriptorCopies ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSets( descriptorWrites, descriptorCopies );
#else
    s_MockPtr->_UpdateDescriptorSets( device, descriptorWrites, descriptorCopies );
#endif
}

static vk::Result CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator, vk::Framebuffer* pFramebuffer ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createFramebuffer( pCreateInfo, pAllocator, pFramebuffer );
#else
    return s_MockPtr->_CreateFramebuffer( device, pCreateInfo, pAllocator, pFramebuffer );
#endif
}

static ResultValue<vk::Result, vk::Framebuffer>
CreateFramebuffer( vk::Device device, const vk::FramebufferCreateInfo& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createFramebuffer( createInfo, nullptr );
#else
    return s_MockPtr->_CreateFramebuffer( device, createInfo, nullptr );
#endif
}

static void DestroyFramebuffer( vk::Device device, vk::Framebuffer framebuffer,
                                const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyFramebuffer( framebuffer, pAllocator );
#else
    s_MockPtr->_DestroyFramebuffer( device, framebuffer, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::Framebuffer framebuffer, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( framebuffer, pAllocator );
#else
    s_MockPtr->_Destroy( device, framebuffer, pAllocator );
#endif
}

static vk::Result CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo* pCreateInfo,
                                    const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass( pCreateInfo, pAllocator, pRenderPass );
#else
    return s_MockPtr->_CreateRenderPass( device, pCreateInfo, pAllocator, pRenderPass );
#endif
}

static ResultValue<vk::Result, vk::RenderPass>
CreateRenderPass( vk::Device device, const vk::RenderPassCreateInfo& createInfo,
                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass( createInfo, nullptr );
#else
    return s_MockPtr->_CreateRenderPass( device, createInfo, nullptr );
#endif
}

static void DestroyRenderPass( vk::Device device, vk::RenderPass renderPass,
                               const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyRenderPass( renderPass, pAllocator );
#else
    s_MockPtr->_DestroyRenderPass( device, renderPass, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::RenderPass renderPass, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( renderPass, pAllocator );
#else
    s_MockPtr->_Destroy( device, renderPass, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::RenderPass renderPass,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( renderPass, nullptr );
#else
    s_MockPtr->_Destroy( device, renderPass, nullptr );
#endif
}

static void GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass, vk::Extent2D* pGranularity ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getRenderAreaGranularity( renderPass, pGranularity );
#else
    s_MockPtr->_GetRenderAreaGranularity( device, renderPass, pGranularity );
#endif
}

static vk::Extent2D GetRenderAreaGranularity( vk::Device device, vk::RenderPass renderPass ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRenderAreaGranularity( renderPass );
#else
    return s_MockPtr->_GetRenderAreaGranularity( device, renderPass );
#endif
}

static vk::Result CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator, vk::CommandPool* pCommandPool ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCommandPool( pCreateInfo, pAllocator, pCommandPool );
#else
    return s_MockPtr->_CreateCommandPool( device, pCreateInfo, pAllocator, pCommandPool );
#endif
}

static ResultValue<vk::Result, vk::CommandPool>
CreateCommandPool( vk::Device device, const vk::CommandPoolCreateInfo& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCommandPool( createInfo, nullptr );
#else
    return s_MockPtr->_CreateCommandPool( device, createInfo, nullptr );
#endif
}

static void DestroyCommandPool( vk::Device device, vk::CommandPool commandPool,
                                const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyCommandPool( commandPool, pAllocator );
#else
    s_MockPtr->_DestroyCommandPool( device, commandPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::CommandPool commandPool, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( commandPool, pAllocator );
#else
    s_MockPtr->_Destroy( device, commandPool, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::CommandPool commandPool,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( commandPool, nullptr );
#else
    s_MockPtr->_Destroy( device, commandPool, nullptr );
#endif
}

static vk::Result ResetCommandPool( vk::Device device, vk::CommandPool commandPool,
                                    vk::CommandPoolResetFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.resetCommandPool( commandPool, flags );
#else
    return s_MockPtr->_ResetCommandPool( device, commandPool, flags );
#endif
}

static vk::Result AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo* pAllocateInfo,
                                          vk::CommandBuffer* pCommandBuffers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateCommandBuffers( pAllocateInfo, pCommandBuffers );
#else
    return s_MockPtr->_AllocateCommandBuffers( device, pAllocateInfo, pCommandBuffers );
#endif
}

template <typename CommandBufferAllocator = std::allocator<vk::CommandBuffer>>
static ResultValue<vk::Result, std::vector<vk::CommandBuffer, CommandBufferAllocator>>
AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateCommandBuffers( allocateInfo );
#else
    return s_MockPtr->_AllocateCommandBuffers( device, allocateInfo );
#endif
}

template <typename CommandBufferAllocator = std::allocator<vk::CommandBuffer>, typename B0 = CommandBufferAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, CommandBuffer>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::CommandBuffer, CommandBufferAllocator>>
AllocateCommandBuffers( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo,
                        CommandBufferAllocator& commandBufferAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.allocateCommandBuffers( allocateInfo, commandBufferAllocator );
#else
    return s_MockPtr->_AllocateCommandBuffers( device, allocateInfo, commandBufferAllocator );
#endif
}

static void FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool, uint32_t commandBufferCount,
                                const vk::CommandBuffer* pCommandBuffers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.freeCommandBuffers( commandPool, commandBufferCount, pCommandBuffers );
#else
    s_MockPtr->_FreeCommandBuffers( device, commandPool, commandBufferCount, pCommandBuffers );
#endif
}

static void FreeCommandBuffers( vk::Device device, vk::CommandPool commandPool,
                                vk::ArrayProxy<const vk::CommandBuffer> const& commandBuffers ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.freeCommandBuffers( commandPool, commandBuffers );
#else
    s_MockPtr->_FreeCommandBuffers( device, commandPool, commandBuffers );
#endif
}

static vk::Result BindBufferMemory2( vk::Device device, uint32_t bindInfoCount,
                                     const vk::BindBufferMemoryInfo* pBindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory2( bindInfoCount, pBindInfos );
#else
    return s_MockPtr->_BindBufferMemory2( device, bindInfoCount, pBindInfos );
#endif
}

static vk::Result BindBufferMemory2( vk::Device device,
                                     vk::ArrayProxy<const vk::BindBufferMemoryInfo> const& bindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory2( bindInfos );
#else
    return s_MockPtr->_BindBufferMemory2( device, bindInfos );
#endif
}

static vk::Result BindImageMemory2( vk::Device device, uint32_t bindInfoCount,
                                    const vk::BindImageMemoryInfo* pBindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory2( bindInfoCount, pBindInfos );
#else
    return s_MockPtr->_BindImageMemory2( device, bindInfoCount, pBindInfos );
#endif
}

static vk::Result BindImageMemory2( vk::Device device,
                                    vk::ArrayProxy<const vk::BindImageMemoryInfo> const& bindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory2( bindInfos );
#else
    return s_MockPtr->_BindImageMemory2( device, bindInfos );
#endif
}

static void GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                        uint32_t remoteDeviceIndex,
                                        vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getGroupPeerMemoryFeatures( heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
#else
    s_MockPtr->_GetGroupPeerMemoryFeatures( device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                            pPeerMemoryFeatures );
#endif
}

static vk::PeerMemoryFeatureFlags GetGroupPeerMemoryFeatures( vk::Device device, uint32_t heapIndex,
                                                              uint32_t localDeviceIndex,
                                                              uint32_t remoteDeviceIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupPeerMemoryFeatures( heapIndex, localDeviceIndex, remoteDeviceIndex );
#else
    return s_MockPtr->_GetGroupPeerMemoryFeatures( device, heapIndex, localDeviceIndex, remoteDeviceIndex );
#endif
}

static void GetImageMemoryRequirements2( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                         vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageMemoryRequirements2( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetImageMemoryRequirements2( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetImageMemoryRequirements2( vk::Device device,
                                                            const vk::ImageMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements2( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements2( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetImageMemoryRequirements2( vk::Device device,
                                                                   const vk::ImageMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements2( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements2( device, info );
#endif
}

static void GetBufferMemoryRequirements2( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo,
                                          vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getBufferMemoryRequirements2( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetBufferMemoryRequirements2( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetBufferMemoryRequirements2( vk::Device device,
                                                             const vk::BufferMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements2( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements2( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetBufferMemoryRequirements2( vk::Device device, const vk::BufferMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements2( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements2( device, info );
#endif
}

static void GetImageSparseMemoryRequirements2( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                                               uint32_t* pSparseMemoryRequirementCount,
                                               vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSparseMemoryRequirements2( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
#else
    s_MockPtr->_GetImageSparseMemoryRequirements2( device, pInfo, pSparseMemoryRequirementCount,
                                                   pSparseMemoryRequirements );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements2( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements2( info );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements2( device, info );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>,
          typename B1 = SparseImageMemoryRequirements2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageMemoryRequirements2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements2(
        vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2& info,
        SparseImageMemoryRequirements2Allocator& sparseImageMemoryRequirements2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements2( info, sparseImageMemoryRequirements2Allocator );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements2( device, info, sparseImageMemoryRequirements2Allocator );
#endif
}

static void TrimCommandPool( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolTrimFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.trimCommandPool( commandPool, flags );
#else
    s_MockPtr->_TrimCommandPool( device, commandPool, flags );
#endif
}

static void GetQueue2( vk::Device device, const vk::DeviceQueueInfo2* pQueueInfo, vk::Queue* pQueue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getQueue2( pQueueInfo, pQueue );
#else
    s_MockPtr->_GetQueue2( device, pQueueInfo, pQueue );
#endif
}

static vk::Queue GetQueue2( vk::Device device, const vk::DeviceQueueInfo2& queueInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getQueue2( queueInfo );
#else
    return s_MockPtr->_GetQueue2( device, queueInfo );
#endif
}

static vk::Result CreateSamplerYcbcrConversion( vk::Device device,
                                                const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                const vk::AllocationCallbacks* pAllocator,
                                                vk::SamplerYcbcrConversion* pYcbcrConversion ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversion( pCreateInfo, pAllocator, pYcbcrConversion );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversion( device, pCreateInfo, pAllocator, pYcbcrConversion );
#endif
}

static ResultValue<vk::Result, vk::SamplerYcbcrConversion>
CreateSamplerYcbcrConversion( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversion( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversion( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SamplerYcbcrConversion, Dispatch>>
CreateSamplerYcbcrConversionUnique( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversionUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversionUnique( device, createInfo, nullptr );
#endif
}

static void DestroySamplerYcbcrConversion( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                           const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroySamplerYcbcrConversion( ycbcrConversion, pAllocator );
#else
    s_MockPtr->_DestroySamplerYcbcrConversion( device, ycbcrConversion, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( ycbcrConversion, pAllocator );
#else
    s_MockPtr->_Destroy( device, ycbcrConversion, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( ycbcrConversion, nullptr );
#else
    s_MockPtr->_Destroy( device, ycbcrConversion, nullptr );
#endif
}

static vk::Result CreateDescriptorUpdateTemplate( vk::Device device,
                                                  const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                  const vk::AllocationCallbacks* pAllocator,
                                                  vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplate( pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplate( device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
#endif
}

static ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
CreateDescriptorUpdateTemplate( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplate( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplate( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DescriptorUpdateTemplate, Dispatch>>
CreateDescriptorUpdateTemplateUnique( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplateUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplateUnique( device, createInfo, nullptr );
#endif
}

static void DestroyDescriptorUpdateTemplate( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                             const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyDescriptorUpdateTemplate( descriptorUpdateTemplate, pAllocator );
#else
    s_MockPtr->_DestroyDescriptorUpdateTemplate( device, descriptorUpdateTemplate, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorUpdateTemplate, pAllocator );
#else
    s_MockPtr->_Destroy( device, descriptorUpdateTemplate, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( descriptorUpdateTemplate, nullptr );
#else
    s_MockPtr->_Destroy( device, descriptorUpdateTemplate, nullptr );
#endif
}

static void UpdateDescriptorSetWithTemplate( vk::Device device, vk::DescriptorSet descriptorSet,
                                             vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                             const void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSetWithTemplate( descriptorSet, descriptorUpdateTemplate, pData );
#else
    s_MockPtr->_UpdateDescriptorSetWithTemplate( device, descriptorSet, descriptorUpdateTemplate, pData );
#endif
}

template <typename DataType>
static void UpdateDescriptorSetWithTemplate( vk::Device device, vk::DescriptorSet descriptorSet,
                                             vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                             DataType const& data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSetWithTemplate( descriptorSet, descriptorUpdateTemplate, data );
#else
    s_MockPtr->_UpdateDescriptorSetWithTemplate( device, descriptorSet, descriptorUpdateTemplate, data );
#endif
}

static void GetDescriptorSetLayoutSupport( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                           vk::DescriptorSetLayoutSupport* pSupport ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetLayoutSupport( pCreateInfo, pSupport );
#else
    s_MockPtr->_GetDescriptorSetLayoutSupport( device, pCreateInfo, pSupport );
#endif
}

static vk::DescriptorSetLayoutSupport
GetDescriptorSetLayoutSupport( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutSupport( createInfo );
#else
    return s_MockPtr->_GetDescriptorSetLayoutSupport( device, createInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetDescriptorSetLayoutSupport( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutSupport( createInfo );
#else
    return s_MockPtr->_GetDescriptorSetLayoutSupport( device, createInfo );
#endif
}

static vk::Result CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2( pCreateInfo, pAllocator, pRenderPass );
#else
    return s_MockPtr->_CreateRenderPass2( device, pCreateInfo, pAllocator, pRenderPass );
#endif
}

static ResultValue<vk::Result, vk::RenderPass>
CreateRenderPass2( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2( createInfo, nullptr );
#else
    return s_MockPtr->_CreateRenderPass2( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::RenderPass, Dispatch>>
CreateRenderPass2Unique( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2Unique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateRenderPass2Unique( device, createInfo, nullptr );
#endif
}

static void ResetQueryPool( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery, uint32_t queryCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.resetQueryPool( queryPool, firstQuery, queryCount );
#else
    s_MockPtr->_ResetQueryPool( device, queryPool, firstQuery, queryCount );
#endif
}

static vk::Result GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore, uint64_t* pValue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreCounterValue( semaphore, pValue );
#else
    return s_MockPtr->_GetSemaphoreCounterValue( device, semaphore, pValue );
#endif
}

static ResultValue<vk::Result, uint64_t> GetSemaphoreCounterValue( vk::Device device, vk::Semaphore semaphore ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreCounterValue( semaphore );
#else
    return s_MockPtr->_GetSemaphoreCounterValue( device, semaphore );
#endif
}

static vk::Result WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo, uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitSemaphores( pWaitInfo, timeout );
#else
    return s_MockPtr->_WaitSemaphores( device, pWaitInfo, timeout );
#endif
}

static vk::Result WaitSemaphores( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo, uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitSemaphores( waitInfo, timeout );
#else
    return s_MockPtr->_WaitSemaphores( device, waitInfo, timeout );
#endif
}

static vk::Result SignalSemaphore( vk::Device device, const vk::SemaphoreSignalInfo* pSignalInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.signalSemaphore( pSignalInfo );
#else
    return s_MockPtr->_SignalSemaphore( device, pSignalInfo );
#endif
}

static vk::Result SignalSemaphore( vk::Device device, const vk::SemaphoreSignalInfo& signalInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.signalSemaphore( signalInfo );
#else
    return s_MockPtr->_SignalSemaphore( device, signalInfo );
#endif
}

static DeviceAddress GetBufferAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddress( pInfo );
#else
    return s_MockPtr->_GetBufferAddress( device, pInfo );
#endif
}

static vk::DeviceAddress GetBufferAddress( vk::Device device, const vk::BufferDeviceAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddress( info );
#else
    return s_MockPtr->_GetBufferAddress( device, info );
#endif
}

static uint64_t GetBufferOpaqueCaptureAddress( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureAddress( pInfo );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureAddress( device, pInfo );
#endif
}

static uint64_t GetBufferOpaqueCaptureAddress( vk::Device device, const vk::BufferDeviceAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureAddress( info );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureAddress( device, info );
#endif
}

static uint64_t GetMemoryOpaqueCaptureAddress( vk::Device device,
                                               const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryOpaqueCaptureAddress( pInfo );
#else
    return s_MockPtr->_GetMemoryOpaqueCaptureAddress( device, pInfo );
#endif
}

static uint64_t GetMemoryOpaqueCaptureAddress( vk::Device device,
                                               const vk::DeviceMemoryOpaqueCaptureAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryOpaqueCaptureAddress( info );
#else
    return s_MockPtr->_GetMemoryOpaqueCaptureAddress( device, info );
#endif
}

static vk::Result CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::PrivateDataSlot* pPrivateDataSlot ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlot( pCreateInfo, pAllocator, pPrivateDataSlot );
#else
    return s_MockPtr->_CreatePrivateDataSlot( device, pCreateInfo, pAllocator, pPrivateDataSlot );
#endif
}

static ResultValue<vk::Result, vk::PrivateDataSlot>
CreatePrivateDataSlot( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlot( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePrivateDataSlot( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::PrivateDataSlot, Dispatch>>
CreatePrivateDataSlotUnique( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlotUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePrivateDataSlotUnique( device, createInfo, nullptr );
#endif
}

static void DestroyPrivateDataSlot( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                    const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyPrivateDataSlot( privateDataSlot, pAllocator );
#else
    s_MockPtr->_DestroyPrivateDataSlot( device, privateDataSlot, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( privateDataSlot, pAllocator );
#else
    s_MockPtr->_Destroy( device, privateDataSlot, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( privateDataSlot, nullptr );
#else
    s_MockPtr->_Destroy( device, privateDataSlot, nullptr );
#endif
}

static vk::Result SetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                  vk::PrivateDataSlot privateDataSlot, uint64_t data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setPrivateData( objectType_, objectHandle, privateDataSlot, data );
#else
    return s_MockPtr->_SetPrivateData( device, objectType_, objectHandle, privateDataSlot, data );
#endif
}

static vk::Result SetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                  vk::PrivateDataSlot privateDataSlot, uint64_t data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setPrivateData( objectType_, objectHandle, privateDataSlot, data );
#else
    return s_MockPtr->_SetPrivateData( device, objectType_, objectHandle, privateDataSlot, data );
#endif
}

static void GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                            vk::PrivateDataSlot privateDataSlot, uint64_t* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getPrivateData( objectType_, objectHandle, privateDataSlot, pData );
#else
    s_MockPtr->_GetPrivateData( device, objectType_, objectHandle, privateDataSlot, pData );
#endif
}

static uint64_t GetPrivateData( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                vk::PrivateDataSlot privateDataSlot ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPrivateData( objectType_, objectHandle, privateDataSlot );
#else
    return s_MockPtr->_GetPrivateData( device, objectType_, objectHandle, privateDataSlot );
#endif
}

static void GetBufferMemoryRequirements( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo,
                                         vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getBufferMemoryRequirements( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetBufferMemoryRequirements( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetBufferMemoryRequirements( vk::Device device,
                                                            const vk::DeviceBufferMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetBufferMemoryRequirements( vk::Device device, const vk::DeviceBufferMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements( device, info );
#endif
}

static void GetImageMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                        vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageMemoryRequirements( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetImageMemoryRequirements( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetImageMemoryRequirements( vk::Device device,
                                                           const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetImageMemoryRequirements( vk::Device device,
                                                                  const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements( device, info );
#endif
}

static void GetImageSparseMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                              uint32_t* pSparseMemoryRequirementCount,
                                              vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSparseMemoryRequirements( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
#else
    s_MockPtr->_GetImageSparseMemoryRequirements( device, pInfo, pSparseMemoryRequirementCount,
                                                  pSparseMemoryRequirements );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements( vk::Device device, const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements( info );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements( device, info );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>,
          typename B1 = SparseImageMemoryRequirements2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageMemoryRequirements2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements(
        vk::Device device, const vk::DeviceImageMemoryRequirements& info,
        SparseImageMemoryRequirements2Allocator& sparseImageMemoryRequirements2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements( info, sparseImageMemoryRequirements2Allocator );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements( device, info, sparseImageMemoryRequirements2Allocator );
#endif
}

static vk::Result CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR* pCreateInfo,
                                      const vk::AllocationCallbacks* pAllocator, vk::SwapchainKHR* pSwapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSwapchainKHR( pCreateInfo, pAllocator, pSwapchain );
#else
    return s_MockPtr->_CreateSwapchainKHR( device, pCreateInfo, pAllocator, pSwapchain );
#endif
}

static ResultValue<vk::Result, vk::SwapchainKHR>
CreateSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSwapchainKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSwapchainKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SwapchainKHR, Dispatch>>
CreateSwapchainKHRUnique( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                          Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSwapchainKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSwapchainKHRUnique( device, createInfo, nullptr );
#endif
}

static void DestroySwapchainKHR( vk::Device device, vk::SwapchainKHR swapchain,
                                 const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroySwapchainKHR( swapchain, pAllocator );
#else
    s_MockPtr->_DestroySwapchainKHR( device, swapchain, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::SwapchainKHR swapchain, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( swapchain, pAllocator );
#else
    s_MockPtr->_Destroy( device, swapchain, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::SwapchainKHR swapchain,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( swapchain, nullptr );
#else
    s_MockPtr->_Destroy( device, swapchain, nullptr );
#endif
}

static vk::Result GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain, uint32_t* pSwapchainImageCount,
                                         vk::Image* pSwapchainImages ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainImagesKHR( swapchain, pSwapchainImageCount, pSwapchainImages );
#else
    return s_MockPtr->_GetSwapchainImagesKHR( device, swapchain, pSwapchainImageCount, pSwapchainImages );
#endif
}

template <typename ImageAllocator = std::allocator<vk::Image>>
static ResultValue<vk::Result, std::vector<vk::Image, ImageAllocator>>
GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainImagesKHR( swapchain );
#else
    return s_MockPtr->_GetSwapchainImagesKHR( device, swapchain );
#endif
}

template <typename ImageAllocator = std::allocator<vk::Image>, typename B1 = ImageAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, Image>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::Image, ImageAllocator>>
GetSwapchainImagesKHR( vk::Device device, vk::SwapchainKHR swapchain, ImageAllocator& imageAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainImagesKHR( swapchain, imageAllocator );
#else
    return s_MockPtr->_GetSwapchainImagesKHR( device, swapchain, imageAllocator );
#endif
}

static vk::Result AcquireNextImageKHR( vk::Device device, vk::SwapchainKHR swapchain, uint64_t timeout,
                                       vk::Semaphore semaphore, vk::Fence fence, uint32_t* pImageIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireNextImageKHR( swapchain, timeout, semaphore, fence, pImageIndex );
#else
    return s_MockPtr->_AcquireNextImageKHR( device, swapchain, timeout, semaphore, fence, pImageIndex );
#endif
}

static vk::Result
GetGroupPresentCapabilitiesKHR( vk::Device device,
                                vk::DeviceGroupPresentCapabilitiesKHR* pDeviceGroupPresentCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupPresentCapabilitiesKHR( pDeviceGroupPresentCapabilities );
#else
    return s_MockPtr->_GetGroupPresentCapabilitiesKHR( device, pDeviceGroupPresentCapabilities );
#endif
}

static ResultValue<vk::Result, vk::DeviceGroupPresentCapabilitiesKHR>
GetGroupPresentCapabilitiesKHR( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupPresentCapabilitiesKHR();
#else
    return s_MockPtr->_GetGroupPresentCapabilitiesKHR();
#endif
}

static vk::Result GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface,
                                                  vk::DeviceGroupPresentModeFlagsKHR* pModes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupSurfacePresentModesKHR( surface, pModes );
#else
    return s_MockPtr->_GetGroupSurfacePresentModesKHR( device, surface, pModes );
#endif
}

static ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR>
GetGroupSurfacePresentModesKHR( vk::Device device, vk::SurfaceKHR surface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupSurfacePresentModesKHR( surface );
#else
    return s_MockPtr->_GetGroupSurfacePresentModesKHR( device, surface );
#endif
}

static vk::Result AcquireNextImage2KHR( vk::Device device, const vk::AcquireNextImageInfoKHR* pAcquireInfo,
                                        uint32_t* pImageIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireNextImage2KHR( pAcquireInfo, pImageIndex );
#else
    return s_MockPtr->_AcquireNextImage2KHR( device, pAcquireInfo, pImageIndex );
#endif
}

static ResultValue<uint32_t> AcquireNextImage2KHR( vk::Device device,
                                                   const vk::AcquireNextImageInfoKHR& acquireInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireNextImage2KHR( acquireInfo );
#else
    return s_MockPtr->_AcquireNextImage2KHR( device, acquireInfo );
#endif
}

static vk::Result CreateSharedSwapchainsKHR( vk::Device device, uint32_t swapchainCount,
                                             const vk::SwapchainCreateInfoKHR* pCreateInfos,
                                             const vk::AllocationCallbacks* pAllocator,
                                             vk::SwapchainKHR* pSwapchains ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainsKHR( swapchainCount, pCreateInfos, pAllocator, pSwapchains );
#else
    return s_MockPtr->_CreateSharedSwapchainsKHR( device, swapchainCount, pCreateInfos, pAllocator, pSwapchains );
#endif
}

template <typename SwapchainKHRAllocator = std::allocator<vk::SwapchainKHR>>
static ResultValue<vk::Result, std::vector<vk::SwapchainKHR, SwapchainKHRAllocator>>
CreateSharedSwapchainsKHR( vk::Device device, vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                           Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainsKHR( createInfos, nullptr );
#else
    return s_MockPtr->_CreateSharedSwapchainsKHR( device, createInfos, nullptr );
#endif
}

template <typename SwapchainKHRAllocator = std::allocator<vk::SwapchainKHR>, typename B0 = SwapchainKHRAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, SwapchainKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::SwapchainKHR, SwapchainKHRAllocator>>
CreateSharedSwapchainsKHR( vk::Device device, vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                           Optional<const vk::AllocationCallbacks> allocator,
                           SwapchainKHRAllocator& swapchainKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainsKHR( createInfos, allocator, swapchainKHRAllocator );
#else
    return s_MockPtr->_CreateSharedSwapchainsKHR( device, createInfos, allocator, swapchainKHRAllocator );
#endif
}

static ResultValue<vk::Result, vk::SwapchainKHR>
CreateSharedSwapchainKHR( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                          Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSharedSwapchainKHR( device, createInfo, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename SwapchainKHRAllocator = std::allocator<UniqueHandle<vk::SwapchainKHR, Dispatch>>>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::SwapchainKHR, Dispatch>, SwapchainKHRAllocator>>
CreateSharedSwapchainsKHRUnique( vk::Device device, vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainsKHRUnique( createInfos, nullptr );
#else
    return s_MockPtr->_CreateSharedSwapchainsKHRUnique( device, createInfos, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename SwapchainKHRAllocator = std::allocator<UniqueHandle<vk::SwapchainKHR, Dispatch>>,
          typename B0 = SwapchainKHRAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, UniqueHandle<SwapchainKHR, Dispatch>>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::SwapchainKHR, Dispatch>, SwapchainKHRAllocator>>
CreateSharedSwapchainsKHRUnique( vk::Device device, vk::ArrayProxy<const vk::SwapchainCreateInfoKHR> const& createInfos,
                                 Optional<const vk::AllocationCallbacks> allocator,
                                 SwapchainKHRAllocator& swapchainKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainsKHRUnique( createInfos, allocator, swapchainKHRAllocator );
#else
    return s_MockPtr->_CreateSharedSwapchainsKHRUnique( device, createInfos, allocator, swapchainKHRAllocator );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SwapchainKHR, Dispatch>>
CreateSharedSwapchainKHRUnique( vk::Device device, const vk::SwapchainCreateInfoKHR& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSharedSwapchainKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSharedSwapchainKHRUnique( device, createInfo, nullptr );
#endif
}

static vk::Result DebugMarkerSetObjectTagEXT( vk::Device device, const vk::DebugMarkerObjectTagInfoEXT* pTagInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.debugMarkerSetObjectTagEXT( pTagInfo );
#else
    return s_MockPtr->_DebugMarkerSetObjectTagEXT( device, pTagInfo );
#endif
}

static vk::Result DebugMarkerSetObjectTagEXT( vk::Device device, const vk::DebugMarkerObjectTagInfoEXT& tagInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.debugMarkerSetObjectTagEXT( tagInfo );
#else
    return s_MockPtr->_DebugMarkerSetObjectTagEXT( device, tagInfo );
#endif
}

static vk::Result DebugMarkerSetObjectNameEXT( vk::Device device,
                                               const vk::DebugMarkerObjectNameInfoEXT* pNameInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.debugMarkerSetObjectNameEXT( pNameInfo );
#else
    return s_MockPtr->_DebugMarkerSetObjectNameEXT( device, pNameInfo );
#endif
}

static vk::Result DebugMarkerSetObjectNameEXT( vk::Device device,
                                               const vk::DebugMarkerObjectNameInfoEXT& nameInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.debugMarkerSetObjectNameEXT( nameInfo );
#else
    return s_MockPtr->_DebugMarkerSetObjectNameEXT( device, nameInfo );
#endif
}

static vk::Result CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator,
                                         vk::VideoSessionKHR* pVideoSession ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionKHR( pCreateInfo, pAllocator, pVideoSession );
#else
    return s_MockPtr->_CreateVideoSessionKHR( device, pCreateInfo, pAllocator, pVideoSession );
#endif
}

static ResultValue<vk::Result, vk::VideoSessionKHR>
CreateVideoSessionKHR( vk::Device device, const vk::VideoSessionCreateInfoKHR& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateVideoSessionKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::VideoSessionKHR, Dispatch>>
CreateVideoSessionKHRUnique( vk::Device device, const vk::VideoSessionCreateInfoKHR& createInfo,
                             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateVideoSessionKHRUnique( device, createInfo, nullptr );
#endif
}

static void DestroyVideoSessionKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                    const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyVideoSessionKHR( videoSession, pAllocator );
#else
    s_MockPtr->_DestroyVideoSessionKHR( device, videoSession, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( videoSession, pAllocator );
#else
    s_MockPtr->_Destroy( device, videoSession, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::VideoSessionKHR videoSession,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( videoSession, nullptr );
#else
    s_MockPtr->_Destroy( device, videoSession, nullptr );
#endif
}

static vk::Result
GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                      uint32_t* pMemoryRequirementsCount,
                                      vk::VideoSessionMemoryRequirementsKHR* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getVideoSessionMemoryRequirementsKHR( videoSession, pMemoryRequirementsCount, pMemoryRequirements );
#else
    return s_MockPtr->_GetVideoSessionMemoryRequirementsKHR( device, videoSession, pMemoryRequirementsCount,
                                                             pMemoryRequirements );
#endif
}

template <typename VideoSessionMemoryRequirementsKHRAllocator = std::allocator<vk::VideoSessionMemoryRequirementsKHR>>
static ResultValue<vk::Result,
                   std::vector<vk::VideoSessionMemoryRequirementsKHR, VideoSessionMemoryRequirementsKHRAllocator>>
GetVideoSessionMemoryRequirementsKHR( vk::Device device, vk::VideoSessionKHR videoSession ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getVideoSessionMemoryRequirementsKHR( videoSession );
#else
    return s_MockPtr->_GetVideoSessionMemoryRequirementsKHR( device, videoSession );
#endif
}

template <typename VideoSessionMemoryRequirementsKHRAllocator = std::allocator<vk::VideoSessionMemoryRequirementsKHR>,
          typename B1 = VideoSessionMemoryRequirementsKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, VideoSessionMemoryRequirementsKHR>::value,
                                  int>::type = 0>
static ResultValue<vk::Result,
                   std::vector<vk::VideoSessionMemoryRequirementsKHR, VideoSessionMemoryRequirementsKHRAllocator>>
GetVideoSessionMemoryRequirementsKHR(
        vk::Device device, vk::VideoSessionKHR videoSession,
        VideoSessionMemoryRequirementsKHRAllocator& videoSessionMemoryRequirementsKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getVideoSessionMemoryRequirementsKHR( videoSession, videoSessionMemoryRequirementsKHRAllocator );
#else
    return s_MockPtr->_GetVideoSessionMemoryRequirementsKHR( device, videoSession,
                                                             videoSessionMemoryRequirementsKHRAllocator );
#endif
}

static vk::Result BindVideoSessionMemoryKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                                             uint32_t bindSessionMemoryInfoCount,
                                             const vk::BindVideoSessionMemoryInfoKHR* pBindSessionMemoryInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindVideoSessionMemoryKHR( videoSession, bindSessionMemoryInfoCount, pBindSessionMemoryInfos );
#else
    return s_MockPtr->_BindVideoSessionMemoryKHR( device, videoSession, bindSessionMemoryInfoCount,
                                                  pBindSessionMemoryInfos );
#endif
}

static vk::Result
BindVideoSessionMemoryKHR( vk::Device device, vk::VideoSessionKHR videoSession,
                           vk::ArrayProxy<const vk::BindVideoSessionMemoryInfoKHR> const& bindSessionMemoryInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindVideoSessionMemoryKHR( videoSession, bindSessionMemoryInfos );
#else
    return s_MockPtr->_BindVideoSessionMemoryKHR( device, videoSession, bindSessionMemoryInfos );
#endif
}

static vk::Result CreateVideoSessionParametersKHR( vk::Device device,
                                                   const vk::VideoSessionParametersCreateInfoKHR* pCreateInfo,
                                                   const vk::AllocationCallbacks* pAllocator,
                                                   vk::VideoSessionParametersKHR* pVideoSessionParameters ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionParametersKHR( pCreateInfo, pAllocator, pVideoSessionParameters );
#else
    return s_MockPtr->_CreateVideoSessionParametersKHR( device, pCreateInfo, pAllocator, pVideoSessionParameters );
#endif
}

static ResultValue<vk::Result, vk::VideoSessionParametersKHR>
CreateVideoSessionParametersKHR( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR& createInfo,
                                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionParametersKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateVideoSessionParametersKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::VideoSessionParametersKHR, Dispatch>>
CreateVideoSessionParametersKHRUnique( vk::Device device, const vk::VideoSessionParametersCreateInfoKHR& createInfo,
                                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createVideoSessionParametersKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateVideoSessionParametersKHRUnique( device, createInfo, nullptr );
#endif
}

static vk::Result UpdateVideoSessionParametersKHR( vk::Device device,
                                                   vk::VideoSessionParametersKHR videoSessionParameters,
                                                   const vk::VideoSessionParametersUpdateInfoKHR* pUpdateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.updateVideoSessionParametersKHR( videoSessionParameters, pUpdateInfo );
#else
    return s_MockPtr->_UpdateVideoSessionParametersKHR( device, videoSessionParameters, pUpdateInfo );
#endif
}

static vk::Result UpdateVideoSessionParametersKHR( vk::Device device,
                                                   vk::VideoSessionParametersKHR videoSessionParameters,
                                                   const vk::VideoSessionParametersUpdateInfoKHR& updateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.updateVideoSessionParametersKHR( videoSessionParameters, updateInfo );
#else
    return s_MockPtr->_UpdateVideoSessionParametersKHR( device, videoSessionParameters, updateInfo );
#endif
}

static void DestroyVideoSessionParametersKHR( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                                              const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyVideoSessionParametersKHR( videoSessionParameters, pAllocator );
#else
    s_MockPtr->_DestroyVideoSessionParametersKHR( device, videoSessionParameters, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( videoSessionParameters, pAllocator );
#else
    s_MockPtr->_Destroy( device, videoSessionParameters, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::VideoSessionParametersKHR videoSessionParameters,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( videoSessionParameters, nullptr );
#else
    s_MockPtr->_Destroy( device, videoSessionParameters, nullptr );
#endif
}

static vk::Result CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator, vk::CuModuleNVX* pModule ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuModuleNVX( pCreateInfo, pAllocator, pModule );
#else
    return s_MockPtr->_CreateCuModuleNVX( device, pCreateInfo, pAllocator, pModule );
#endif
}

static ResultValue<vk::Result, vk::CuModuleNVX>
CreateCuModuleNVX( vk::Device device, const vk::CuModuleCreateInfoNVX& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuModuleNVX( createInfo, nullptr );
#else
    return s_MockPtr->_CreateCuModuleNVX( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::CuModuleNVX, Dispatch>>
CreateCuModuleNVXUnique( vk::Device device, const vk::CuModuleCreateInfoNVX& createInfo,
                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuModuleNVXUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateCuModuleNVXUnique( device, createInfo, nullptr );
#endif
}

static vk::Result CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX* pCreateInfo,
                                       const vk::AllocationCallbacks* pAllocator, vk::CuFunctionNVX* pFunction ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuFunctionNVX( pCreateInfo, pAllocator, pFunction );
#else
    return s_MockPtr->_CreateCuFunctionNVX( device, pCreateInfo, pAllocator, pFunction );
#endif
}

static ResultValue<vk::Result, vk::CuFunctionNVX>
CreateCuFunctionNVX( vk::Device device, const vk::CuFunctionCreateInfoNVX& createInfo,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuFunctionNVX( createInfo, nullptr );
#else
    return s_MockPtr->_CreateCuFunctionNVX( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::CuFunctionNVX, Dispatch>>
CreateCuFunctionNVXUnique( vk::Device device, const vk::CuFunctionCreateInfoNVX& createInfo,
                           Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createCuFunctionNVXUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateCuFunctionNVXUnique( device, createInfo, nullptr );
#endif
}

static void DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyCuModuleNVX( module, pAllocator );
#else
    s_MockPtr->_DestroyCuModuleNVX( device, module, pAllocator );
#endif
}

static void DestroyCuModuleNVX( vk::Device device, vk::CuModuleNVX module,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyCuModuleNVX( module, nullptr );
#else
    s_MockPtr->_DestroyCuModuleNVX( device, module, nullptr );
#endif
}

static void Destroy( vk::Device device, vk::CuModuleNVX module, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( module, pAllocator );
#else
    s_MockPtr->_Destroy( device, module, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::CuModuleNVX module,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( module, nullptr );
#else
    s_MockPtr->_Destroy( device, module, nullptr );
#endif
}

static void DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                  const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyCuFunctionNVX( function, pAllocator );
#else
    s_MockPtr->_DestroyCuFunctionNVX( device, function, pAllocator );
#endif
}

static void DestroyCuFunctionNVX( vk::Device device, vk::CuFunctionNVX function,
                                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyCuFunctionNVX( function, nullptr );
#else
    s_MockPtr->_DestroyCuFunctionNVX( device, function, nullptr );
#endif
}

static void Destroy( vk::Device device, vk::CuFunctionNVX function, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( function, pAllocator );
#else
    s_MockPtr->_Destroy( device, function, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::CuFunctionNVX function,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( function, nullptr );
#else
    s_MockPtr->_Destroy( device, function, nullptr );
#endif
}

static uint32_t GetImageViewHandleNVX( vk::Device device, const vk::ImageViewHandleInfoNVX* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewHandleNVX( pInfo );
#else
    return s_MockPtr->_GetImageViewHandleNVX( device, pInfo );
#endif
}

static uint32_t GetImageViewHandleNVX( vk::Device device, const vk::ImageViewHandleInfoNVX& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewHandleNVX( info );
#else
    return s_MockPtr->_GetImageViewHandleNVX( device, info );
#endif
}

static vk::Result GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView,
                                          vk::ImageViewAddressPropertiesNVX* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewAddressNVX( imageView, pProperties );
#else
    return s_MockPtr->_GetImageViewAddressNVX( device, imageView, pProperties );
#endif
}

static ResultValue<vk::Result, vk::ImageViewAddressPropertiesNVX>
GetImageViewAddressNVX( vk::Device device, vk::ImageView imageView ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewAddressNVX( imageView );
#else
    return s_MockPtr->_GetImageViewAddressNVX( device, imageView );
#endif
}

static vk::Result GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage,
                                    vk::ShaderInfoTypeAMD infoType, size_t* pInfoSize, void* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderInfoAMD( pipeline, shaderStage, infoType, pInfoSize, pInfo );
#else
    return s_MockPtr->_GetShaderInfoAMD( device, pipeline, shaderStage, infoType, pInfoSize, pInfo );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage,
                  vk::ShaderInfoTypeAMD infoType ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderInfoAMD( pipeline, shaderStage, infoType );
#else
    return s_MockPtr->_GetShaderInfoAMD( device, pipeline, shaderStage, infoType );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>, typename B1 = Uint8_tAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, uint8_t>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetShaderInfoAMD( vk::Device device, vk::Pipeline pipeline, vk::ShaderStageFlagBits shaderStage,
                  vk::ShaderInfoTypeAMD infoType, Uint8_tAllocator& uint8_tAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderInfoAMD( pipeline, shaderStage, infoType, uint8_tAllocator );
#else
    return s_MockPtr->_GetShaderInfoAMD( device, pipeline, shaderStage, infoType, uint8_tAllocator );
#endif
}

static vk::Result GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                          vk::ExternalMemoryHandleTypeFlagsNV handleType, HANDLE* pHandle ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandleNV( memory, handleType, pHandle );
#else
    return s_MockPtr->_GetMemoryWin32HandleNV( device, memory, handleType, pHandle );
#endif
}

static ResultValue<vk::Result, HANDLE> GetMemoryWin32HandleNV( vk::Device device, vk::DeviceMemory memory,
                                                               vk::ExternalMemoryHandleTypeFlagsNV handleType ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandleNV( memory, handleType );
#else
    return s_MockPtr->_GetMemoryWin32HandleNV( device, memory, handleType );
#endif
}

static void GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex, uint32_t localDeviceIndex,
                                           uint32_t remoteDeviceIndex,
                                           vk::PeerMemoryFeatureFlags* pPeerMemoryFeatures ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getGroupPeerMemoryFeaturesKHR( heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures );
#else
    s_MockPtr->_GetGroupPeerMemoryFeaturesKHR( device, heapIndex, localDeviceIndex, remoteDeviceIndex,
                                               pPeerMemoryFeatures );
#endif
}

static vk::PeerMemoryFeatureFlags GetGroupPeerMemoryFeaturesKHR( vk::Device device, uint32_t heapIndex,
                                                                 uint32_t localDeviceIndex,
                                                                 uint32_t remoteDeviceIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupPeerMemoryFeaturesKHR( heapIndex, localDeviceIndex, remoteDeviceIndex );
#else
    return s_MockPtr->_GetGroupPeerMemoryFeaturesKHR( device, heapIndex, localDeviceIndex, remoteDeviceIndex );
#endif
}

static void TrimCommandPoolKHR( vk::Device device, vk::CommandPool commandPool, vk::CommandPoolTrimFlags flags ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.trimCommandPoolKHR( commandPool, flags );
#else
    s_MockPtr->_TrimCommandPoolKHR( device, commandPool, flags );
#endif
}

static vk::Result GetMemoryWin32HandleKHR( vk::Device device,
                                           const vk::MemoryGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                           HANDLE* pHandle ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandleKHR( pGetWin32HandleInfo, pHandle );
#else
    return s_MockPtr->_GetMemoryWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
#endif
}

static ResultValue<vk::Result, HANDLE>
GetMemoryWin32HandleKHR( vk::Device device, const vk::MemoryGetWin32HandleInfoKHR& getWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandleKHR( getWin32HandleInfo );
#else
    return s_MockPtr->_GetMemoryWin32HandleKHR( device, getWin32HandleInfo );
#endif
}

static vk::Result
GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, HANDLE handle,
                                   vk::MemoryWin32HandlePropertiesKHR* pMemoryWin32HandleProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandlePropertiesKHR( handleType, handle, pMemoryWin32HandleProperties );
#else
    return s_MockPtr->_GetMemoryWin32HandlePropertiesKHR( device, handleType, handle, pMemoryWin32HandleProperties );
#endif
}

static ResultValue<vk::Result, vk::MemoryWin32HandlePropertiesKHR>
GetMemoryWin32HandlePropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                   HANDLE handle ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryWin32HandlePropertiesKHR( handleType, handle );
#else
    return s_MockPtr->_GetMemoryWin32HandlePropertiesKHR( device, handleType, handle );
#endif
}

static vk::Result GetMemoryFdKHR( vk::Device device, const vk::MemoryGetFdInfoKHR* pGetFdInfo, int* pFd ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryFdKHR( pGetFdInfo, pFd );
#else
    return s_MockPtr->_GetMemoryFdKHR( device, pGetFdInfo, pFd );
#endif
}

static ResultValue<vk::Result, int> GetMemoryFdKHR( vk::Device device, const vk::MemoryGetFdInfoKHR& getFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryFdKHR( getFdInfo );
#else
    return s_MockPtr->_GetMemoryFdKHR( device, getFdInfo );
#endif
}

static vk::Result GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd,
                                            vk::MemoryFdPropertiesKHR* pMemoryFdProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryFdPropertiesKHR( handleType, fd, pMemoryFdProperties );
#else
    return s_MockPtr->_GetMemoryFdPropertiesKHR( device, handleType, fd, pMemoryFdProperties );
#endif
}

static ResultValue<vk::Result, vk::MemoryFdPropertiesKHR>
GetMemoryFdPropertiesKHR( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType, int fd ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryFdPropertiesKHR( handleType, fd );
#else
    return s_MockPtr->_GetMemoryFdPropertiesKHR( device, handleType, fd );
#endif
}

static vk::Result
ImportSemaphoreWin32HandleKHR( vk::Device device,
                               const vk::ImportSemaphoreWin32HandleInfoKHR* pImportSemaphoreWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importSemaphoreWin32HandleKHR( pImportSemaphoreWin32HandleInfo );
#else
    return s_MockPtr->_ImportSemaphoreWin32HandleKHR( device, pImportSemaphoreWin32HandleInfo );
#endif
}

static vk::Result
ImportSemaphoreWin32HandleKHR( vk::Device device,
                               const vk::ImportSemaphoreWin32HandleInfoKHR& importSemaphoreWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importSemaphoreWin32HandleKHR( importSemaphoreWin32HandleInfo );
#else
    return s_MockPtr->_ImportSemaphoreWin32HandleKHR( device, importSemaphoreWin32HandleInfo );
#endif
}

static vk::Result GetSemaphoreWin32HandleKHR( vk::Device device,
                                              const vk::SemaphoreGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                              HANDLE* pHandle ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreWin32HandleKHR( pGetWin32HandleInfo, pHandle );
#else
    return s_MockPtr->_GetSemaphoreWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
#endif
}

static ResultValue<vk::Result, HANDLE>
GetSemaphoreWin32HandleKHR( vk::Device device, const vk::SemaphoreGetWin32HandleInfoKHR& getWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreWin32HandleKHR( getWin32HandleInfo );
#else
    return s_MockPtr->_GetSemaphoreWin32HandleKHR( device, getWin32HandleInfo );
#endif
}

static vk::Result ImportSemaphoreFdKHR( vk::Device device,
                                        const vk::ImportSemaphoreFdInfoKHR* pImportSemaphoreFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importSemaphoreFdKHR( pImportSemaphoreFdInfo );
#else
    return s_MockPtr->_ImportSemaphoreFdKHR( device, pImportSemaphoreFdInfo );
#endif
}

static vk::Result ImportSemaphoreFdKHR( vk::Device device,
                                        const vk::ImportSemaphoreFdInfoKHR& importSemaphoreFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importSemaphoreFdKHR( importSemaphoreFdInfo );
#else
    return s_MockPtr->_ImportSemaphoreFdKHR( device, importSemaphoreFdInfo );
#endif
}

static vk::Result GetSemaphoreFdKHR( vk::Device device, const vk::SemaphoreGetFdInfoKHR* pGetFdInfo, int* pFd ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreFdKHR( pGetFdInfo, pFd );
#else
    return s_MockPtr->_GetSemaphoreFdKHR( device, pGetFdInfo, pFd );
#endif
}

static ResultValue<vk::Result, int> GetSemaphoreFdKHR( vk::Device device,
                                                       const vk::SemaphoreGetFdInfoKHR& getFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreFdKHR( getFdInfo );
#else
    return s_MockPtr->_GetSemaphoreFdKHR( device, getFdInfo );
#endif
}

static vk::Result CreateDescriptorUpdateTemplateKHR( vk::Device device,
                                                     const vk::DescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                     const vk::AllocationCallbacks* pAllocator,
                                                     vk::DescriptorUpdateTemplate* pDescriptorUpdateTemplate ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplateKHR( pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplateKHR( device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate );
#endif
}

static ResultValue<vk::Result, vk::DescriptorUpdateTemplate>
CreateDescriptorUpdateTemplateKHR( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplateKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplateKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DescriptorUpdateTemplate, Dispatch>>
CreateDescriptorUpdateTemplateKHRUnique( vk::Device device, const vk::DescriptorUpdateTemplateCreateInfo& createInfo,
                                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDescriptorUpdateTemplateKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDescriptorUpdateTemplateKHRUnique( device, createInfo, nullptr );
#endif
}

static void DestroyDescriptorUpdateTemplateKHR( vk::Device device,
                                                vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyDescriptorUpdateTemplateKHR( descriptorUpdateTemplate, pAllocator );
#else
    s_MockPtr->_DestroyDescriptorUpdateTemplateKHR( device, descriptorUpdateTemplate, pAllocator );
#endif
}

static void UpdateDescriptorSetWithTemplateKHR( vk::Device device, vk::DescriptorSet descriptorSet,
                                                vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                const void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSetWithTemplateKHR( descriptorSet, descriptorUpdateTemplate, pData );
#else
    s_MockPtr->_UpdateDescriptorSetWithTemplateKHR( device, descriptorSet, descriptorUpdateTemplate, pData );
#endif
}

template <typename DataType>
static void UpdateDescriptorSetWithTemplateKHR( vk::Device device, vk::DescriptorSet descriptorSet,
                                                vk::DescriptorUpdateTemplate descriptorUpdateTemplate,
                                                DataType const& data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.updateDescriptorSetWithTemplateKHR( descriptorSet, descriptorUpdateTemplate, data );
#else
    s_MockPtr->_UpdateDescriptorSetWithTemplateKHR( device, descriptorSet, descriptorUpdateTemplate, data );
#endif
}

static vk::Result DisplayPowerControlEXT( vk::Device device, vk::DisplayKHR display,
                                          const vk::DisplayPowerInfoEXT* pDisplayPowerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.displayPowerControlEXT( display, pDisplayPowerInfo );
#else
    return s_MockPtr->_DisplayPowerControlEXT( device, display, pDisplayPowerInfo );
#endif
}

static vk::Result DisplayPowerControlEXT( vk::Device device, vk::DisplayKHR display,
                                          const vk::DisplayPowerInfoEXT& displayPowerInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.displayPowerControlEXT( display, displayPowerInfo );
#else
    return s_MockPtr->_DisplayPowerControlEXT( device, display, displayPowerInfo );
#endif
}

static vk::Result RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT* pDeviceEventInfo,
                                    const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerEventEXT( pDeviceEventInfo, pAllocator, pFence );
#else
    return s_MockPtr->_RegisterEventEXT( device, pDeviceEventInfo, pAllocator, pFence );
#endif
}

static ResultValue<vk::Result, vk::Fence>
RegisterEventEXT( vk::Device device, const vk::DeviceEventInfoEXT& deviceEventInfo,
                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerEventEXT( deviceEventInfo, nullptr );
#else
    return s_MockPtr->_RegisterEventEXT( device, deviceEventInfo, nullptr );
#endif
}

static ResultValue<vk::Result, vk::UniqueHandle<vk::Fence, vk::Dispatch>>
RegisterEventEXTUnique( vk::Device device, const vk::DeviceEventInfoEXT& deviceEventInfo,
                        Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerEventEXTUnique( deviceEventInfo, nullptr );
#else
    return s_MockPtr->_RegisterEventEXTUnique( device, deviceEventInfo, nullptr );
#endif
}

static vk::Result RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display,
                                           const vk::DisplayEventInfoEXT* pDisplayEventInfo,
                                           const vk::AllocationCallbacks* pAllocator, vk::Fence* pFence ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerDisplayEventEXT( display, pDisplayEventInfo, pAllocator, pFence );
#else
    return s_MockPtr->_RegisterDisplayEventEXT( device, display, pDisplayEventInfo, pAllocator, pFence );
#endif
}

static ResultValue<vk::Result, vk::Fence>
RegisterDisplayEventEXT( vk::Device device, vk::DisplayKHR display, const vk::DisplayEventInfoEXT& displayEventInfo,
                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerDisplayEventEXT( display, displayEventInfo, nullptr );
#else
    return s_MockPtr->_RegisterDisplayEventEXT( device, display, displayEventInfo, nullptr );
#endif
}

static ResultValue<vk::Result, vk::UniqueHandle<vk::Fence, vk::Dispatch>>
RegisterDisplayEventEXTUnique( vk::Device device, vk::DisplayKHR display,
                               const vk::DisplayEventInfoEXT& displayEventInfo,
                               Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.registerDisplayEventEXTUnique( display, displayEventInfo, nullptr );
#else
    return s_MockPtr->_RegisterDisplayEventEXTUnique( device, display, displayEventInfo, nullptr );
#endif
}

static vk::Result GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                          vk::SurfaceCounterFlagBitsEXT counter, uint64_t* pCounterValue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainCounterEXT( swapchain, counter, pCounterValue );
#else
    return s_MockPtr->_GetSwapchainCounterEXT( device, swapchain, counter, pCounterValue );
#endif
}

static ResultValue<vk::Result, uint64_t> GetSwapchainCounterEXT( vk::Device device, vk::SwapchainKHR swapchain,
                                                                 vk::SurfaceCounterFlagBitsEXT counter ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainCounterEXT( swapchain, counter );
#else
    return s_MockPtr->_GetSwapchainCounterEXT( device, swapchain, counter );
#endif
}

static vk::Result GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                                 vk::RefreshCycleDurationGOOGLE* pDisplayTimingProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRefreshCycleDurationGOOGLE( swapchain, pDisplayTimingProperties );
#else
    return s_MockPtr->_GetRefreshCycleDurationGOOGLE( device, swapchain, pDisplayTimingProperties );
#endif
}

static ResultValue<vk::Result, vk::RefreshCycleDurationGOOGLE>
GetRefreshCycleDurationGOOGLE( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRefreshCycleDurationGOOGLE( swapchain );
#else
    return s_MockPtr->_GetRefreshCycleDurationGOOGLE( device, swapchain );
#endif
}

static vk::Result GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                                   uint32_t* pPresentationTimingCount,
                                                   vk::PastPresentationTimingGOOGLE* pPresentationTimings ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPastPresentationTimingGOOGLE( swapchain, pPresentationTimingCount, pPresentationTimings );
#else
    return s_MockPtr->_GetPastPresentationTimingGOOGLE( device, swapchain, pPresentationTimingCount,
                                                        pPresentationTimings );
#endif
}

template <typename PastPresentationTimingGOOGLEAllocator = std::allocator<vk::PastPresentationTimingGOOGLE>>
static ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE, PastPresentationTimingGOOGLEAllocator>>
GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPastPresentationTimingGOOGLE( swapchain );
#else
    return s_MockPtr->_GetPastPresentationTimingGOOGLE( device, swapchain );
#endif
}

template <typename PastPresentationTimingGOOGLEAllocator = std::allocator<vk::PastPresentationTimingGOOGLE>,
          typename B1 = PastPresentationTimingGOOGLEAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PastPresentationTimingGOOGLE>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PastPresentationTimingGOOGLE, PastPresentationTimingGOOGLEAllocator>>
GetPastPresentationTimingGOOGLE( vk::Device device, vk::SwapchainKHR swapchain,
                                 PastPresentationTimingGOOGLEAllocator& pastPresentationTimingGOOGLEAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPastPresentationTimingGOOGLE( swapchain, pastPresentationTimingGOOGLEAllocator );
#else
    return s_MockPtr->_GetPastPresentationTimingGOOGLE( device, swapchain, pastPresentationTimingGOOGLEAllocator );
#endif
}

static void SetHdrMetadataEXT( vk::Device device, uint32_t swapchainCount, const vk::SwapchainKHR* pSwapchains,
                               const vk::HdrMetadataEXT* pMetadata ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.setHdrMetadataEXT( swapchainCount, pSwapchains, pMetadata );
#else
    s_MockPtr->_SetHdrMetadataEXT( device, swapchainCount, pSwapchains, pMetadata );
#endif
}

static void SetHdrMetadataEXT( vk::Device device, vk::ArrayProxy<const vk::SwapchainKHR> const& swapchains,
                               vk::ArrayProxy<const vk::HdrMetadataEXT> const& metadata ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.setHdrMetadataEXT( swapchains, metadata );
#else
    s_MockPtr->_SetHdrMetadataEXT( device, swapchains, metadata );
#endif
}

static vk::Result CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator, vk::RenderPass* pRenderPass ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2KHR( pCreateInfo, pAllocator, pRenderPass );
#else
    return s_MockPtr->_CreateRenderPass2KHR( device, pCreateInfo, pAllocator, pRenderPass );
#endif
}

static ResultValue<vk::Result, vk::RenderPass>
CreateRenderPass2KHR( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2KHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateRenderPass2KHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::RenderPass, Dispatch>>
CreateRenderPass2KHRUnique( vk::Device device, const vk::RenderPassCreateInfo2& createInfo,
                            Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRenderPass2KHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateRenderPass2KHRUnique( device, createInfo, nullptr );
#endif
}

static vk::Result GetSwapchainStatusKHR( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainStatusKHR( swapchain );
#else
    return s_MockPtr->_GetSwapchainStatusKHR( device, swapchain );
#endif
}

static vk::Result GetSwapchainStatusKHR( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSwapchainStatusKHR( swapchain );
#else
    return s_MockPtr->_GetSwapchainStatusKHR( device, swapchain );
#endif
}

static vk::Result
ImportFenceWin32HandleKHR( vk::Device device,
                           const vk::ImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importFenceWin32HandleKHR( pImportFenceWin32HandleInfo );
#else
    return s_MockPtr->_ImportFenceWin32HandleKHR( device, pImportFenceWin32HandleInfo );
#endif
}

static vk::Result ImportFenceWin32HandleKHR( vk::Device device,
                                             const vk::ImportFenceWin32HandleInfoKHR& importFenceWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importFenceWin32HandleKHR( importFenceWin32HandleInfo );
#else
    return s_MockPtr->_ImportFenceWin32HandleKHR( device, importFenceWin32HandleInfo );
#endif
}

static vk::Result GetFenceWin32HandleKHR( vk::Device device, const vk::FenceGetWin32HandleInfoKHR* pGetWin32HandleInfo,
                                          HANDLE* pHandle ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceWin32HandleKHR( pGetWin32HandleInfo, pHandle );
#else
    return s_MockPtr->_GetFenceWin32HandleKHR( device, pGetWin32HandleInfo, pHandle );
#endif
}

static ResultValue<vk::Result, HANDLE>
GetFenceWin32HandleKHR( vk::Device device, const vk::FenceGetWin32HandleInfoKHR& getWin32HandleInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceWin32HandleKHR( getWin32HandleInfo );
#else
    return s_MockPtr->_GetFenceWin32HandleKHR( device, getWin32HandleInfo );
#endif
}

static vk::Result ImportFenceFdKHR( vk::Device device, const vk::ImportFenceFdInfoKHR* pImportFenceFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importFenceFdKHR( pImportFenceFdInfo );
#else
    return s_MockPtr->_ImportFenceFdKHR( device, pImportFenceFdInfo );
#endif
}

static vk::Result ImportFenceFdKHR( vk::Device device, const vk::ImportFenceFdInfoKHR& importFenceFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.importFenceFdKHR( importFenceFdInfo );
#else
    return s_MockPtr->_ImportFenceFdKHR( device, importFenceFdInfo );
#endif
}

static vk::Result GetFenceFdKHR( vk::Device device, const vk::FenceGetFdInfoKHR* pGetFdInfo, int* pFd ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceFdKHR( pGetFdInfo, pFd );
#else
    return s_MockPtr->_GetFenceFdKHR( device, pGetFdInfo, pFd );
#endif
}

static ResultValue<vk::Result, int> GetFenceFdKHR( vk::Device device, const vk::FenceGetFdInfoKHR& getFdInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFenceFdKHR( getFdInfo );
#else
    return s_MockPtr->_GetFenceFdKHR( device, getFdInfo );
#endif
}

static vk::Result AcquireProfilingLockKHR( vk::Device device, const vk::AcquireProfilingLockInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireProfilingLockKHR( pInfo );
#else
    return s_MockPtr->_AcquireProfilingLockKHR( device, pInfo );
#endif
}

static vk::Result AcquireProfilingLockKHR( vk::Device device, const vk::AcquireProfilingLockInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireProfilingLockKHR( info );
#else
    return s_MockPtr->_AcquireProfilingLockKHR( device, info );
#endif
}

static void ReleaseProfilingLockKHR( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.releaseProfilingLockKHR();
#else
    s_MockPtr->_ReleaseProfilingLockKHR();
#endif
}

static vk::Result SetDebugUtilsObjectNameEXT( vk::Device device,
                                              const vk::DebugUtilsObjectNameInfoEXT* pNameInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setDebugUtilsObjectNameEXT( pNameInfo );
#else
    return s_MockPtr->_SetDebugUtilsObjectNameEXT( device, pNameInfo );
#endif
}

static vk::Result SetDebugUtilsObjectNameEXT( vk::Device device, const vk::DebugUtilsObjectNameInfoEXT& nameInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setDebugUtilsObjectNameEXT( nameInfo );
#else
    return s_MockPtr->_SetDebugUtilsObjectNameEXT( device, nameInfo );
#endif
}

static vk::Result SetDebugUtilsObjectTagEXT( vk::Device device, const vk::DebugUtilsObjectTagInfoEXT* pTagInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setDebugUtilsObjectTagEXT( pTagInfo );
#else
    return s_MockPtr->_SetDebugUtilsObjectTagEXT( device, pTagInfo );
#endif
}

static vk::Result SetDebugUtilsObjectTagEXT( vk::Device device, const vk::DebugUtilsObjectTagInfoEXT& tagInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setDebugUtilsObjectTagEXT( tagInfo );
#else
    return s_MockPtr->_SetDebugUtilsObjectTagEXT( device, tagInfo );
#endif
}

static void GetImageMemoryRequirements2KHR( vk::Device device, const vk::ImageMemoryRequirementsInfo2* pInfo,
                                            vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageMemoryRequirements2KHR( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetImageMemoryRequirements2KHR( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetImageMemoryRequirements2KHR( vk::Device device,
                                                               const vk::ImageMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements2KHR( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements2KHR( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetImageMemoryRequirements2KHR( vk::Device device, const vk::ImageMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirements2KHR( info );
#else
    return s_MockPtr->_GetImageMemoryRequirements2KHR( device, info );
#endif
}

static void GetBufferMemoryRequirements2KHR( vk::Device device, const vk::BufferMemoryRequirementsInfo2* pInfo,
                                             vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getBufferMemoryRequirements2KHR( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetBufferMemoryRequirements2KHR( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetBufferMemoryRequirements2KHR( vk::Device device,
                                                                const vk::BufferMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements2KHR( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements2KHR( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetBufferMemoryRequirements2KHR( vk::Device device, const vk::BufferMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirements2KHR( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirements2KHR( device, info );
#endif
}

static void GetImageSparseMemoryRequirements2KHR( vk::Device device,
                                                  const vk::ImageSparseMemoryRequirementsInfo2* pInfo,
                                                  uint32_t* pSparseMemoryRequirementCount,
                                                  vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSparseMemoryRequirements2KHR( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
#else
    s_MockPtr->_GetImageSparseMemoryRequirements2KHR( device, pInfo, pSparseMemoryRequirementCount,
                                                      pSparseMemoryRequirements );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements2KHR( vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements2KHR( info );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements2KHR( device, info );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>,
          typename B1 = SparseImageMemoryRequirements2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageMemoryRequirements2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirements2KHR(
        vk::Device device, const vk::ImageSparseMemoryRequirementsInfo2& info,
        SparseImageMemoryRequirements2Allocator& sparseImageMemoryRequirements2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirements2KHR( info, sparseImageMemoryRequirements2Allocator );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirements2KHR( device, info, sparseImageMemoryRequirements2Allocator );
#endif
}

static vk::Result CreateAccelerationStructureKHR( vk::Device device,
                                                  const vk::AccelerationStructureCreateInfoKHR* pCreateInfo,
                                                  const vk::AllocationCallbacks* pAllocator,
                                                  vk::AccelerationStructureKHR* pAccelerationStructure ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureKHR( pCreateInfo, pAllocator, pAccelerationStructure );
#else
    return s_MockPtr->_CreateAccelerationStructureKHR( device, pCreateInfo, pAllocator, pAccelerationStructure );
#endif
}

static ResultValue<vk::Result, vk::AccelerationStructureKHR>
CreateAccelerationStructureKHR( vk::Device device, const vk::AccelerationStructureCreateInfoKHR& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateAccelerationStructureKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::AccelerationStructureKHR, Dispatch>>
CreateAccelerationStructureKHRUnique( vk::Device device, const vk::AccelerationStructureCreateInfoKHR& createInfo,
                                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateAccelerationStructureKHRUnique( device, createInfo, nullptr );
#endif
}

static void DestroyAccelerationStructureKHR( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                                             const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyAccelerationStructureKHR( accelerationStructure, pAllocator );
#else
    s_MockPtr->_DestroyAccelerationStructureKHR( device, accelerationStructure, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( accelerationStructure, pAllocator );
#else
    s_MockPtr->_Destroy( device, accelerationStructure, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::AccelerationStructureKHR accelerationStructure,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( accelerationStructure, nullptr );
#else
    s_MockPtr->_Destroy( device, accelerationStructure, nullptr );
#endif
}

static vk::Result
BuildAccelerationStructuresKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation, uint32_t infoCount,
                                const vk::AccelerationStructureBuildGeometryInfoKHR* pInfos,
                                const vk::AccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.buildAccelerationStructuresKHR( deferredOperation, infoCount, pInfos, ppBuildRangeInfos );
#else
    return s_MockPtr->_BuildAccelerationStructuresKHR( device, deferredOperation, infoCount, pInfos,
                                                       ppBuildRangeInfos );
#endif
}

static vk::Result BuildAccelerationStructuresKHR(
        vk::Device device, vk::DeferredOperationKHR deferredOperation,
        vk::ArrayProxy<const vk::AccelerationStructureBuildGeometryInfoKHR> const& infos,
        vk::ArrayProxy<const vk::AccelerationStructureBuildRangeInfoKHR* const> const& pBuildRangeInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.buildAccelerationStructuresKHR( deferredOperation, infos, pBuildRangeInfos );
#else
    return s_MockPtr->_BuildAccelerationStructuresKHR( device, deferredOperation, infos, pBuildRangeInfos );
#endif
}

static vk::Result CopyAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                                const vk::CopyAccelerationStructureInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyAccelerationStructureKHR( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyAccelerationStructureKHR( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                                const vk::CopyAccelerationStructureInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyAccelerationStructureKHR( deferredOperation, info );
#else
    return s_MockPtr->_CopyAccelerationStructureKHR( device, deferredOperation, info );
#endif
}

static vk::Result
CopyAccelerationStructureToMemoryKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      const vk::CopyAccelerationStructureToMemoryInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyAccelerationStructureToMemoryKHR( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyAccelerationStructureToMemoryKHR( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyAccelerationStructureToMemoryKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                                        const vk::CopyAccelerationStructureToMemoryInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyAccelerationStructureToMemoryKHR( deferredOperation, info );
#else
    return s_MockPtr->_CopyAccelerationStructureToMemoryKHR( device, deferredOperation, info );
#endif
}

static vk::Result
CopyMemoryToAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                      const vk::CopyMemoryToAccelerationStructureInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToAccelerationStructureKHR( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyMemoryToAccelerationStructureKHR( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyMemoryToAccelerationStructureKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                                        const vk::CopyMemoryToAccelerationStructureInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToAccelerationStructureKHR( deferredOperation, info );
#else
    return s_MockPtr->_CopyMemoryToAccelerationStructureKHR( device, deferredOperation, info );
#endif
}

static vk::Result WriteAccelerationStructuresPropertiesKHR( vk::Device device, uint32_t accelerationStructureCount,
                                                            const vk::AccelerationStructureKHR* pAccelerationStructures,
                                                            vk::QueryType queryType, size_t dataSize, void* pData,
                                                            size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeAccelerationStructuresPropertiesKHR( accelerationStructureCount, pAccelerationStructures,
                                                            queryType, dataSize, pData, stride );
#else
    return s_MockPtr->_WriteAccelerationStructuresPropertiesKHR(
            device, accelerationStructureCount, pAccelerationStructures, queryType, dataSize, pData, stride );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>> WriteAccelerationStructuresPropertiesKHR(
        vk::Device device, vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
        vk::QueryType queryType, size_t dataSize, size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeAccelerationStructuresPropertiesKHR( accelerationStructures, queryType, dataSize, stride );
#else
    return s_MockPtr->_WriteAccelerationStructuresPropertiesKHR( device, accelerationStructures, queryType, dataSize,
                                                                 stride );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType> WriteAccelerationStructuresPropertyKHR(
        vk::Device device, vk::ArrayProxy<const vk::AccelerationStructureKHR> const& accelerationStructures,
        vk::QueryType queryType, size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeAccelerationStructuresPropertyKHR( accelerationStructures, queryType, stride );
#else
    return s_MockPtr->_WriteAccelerationStructuresPropertyKHR( device, accelerationStructures, queryType, stride );
#endif
}

static DeviceAddress
GetAccelerationStructureAddressKHR( vk::Device device,
                                    const vk::AccelerationStructureDeviceAddressInfoKHR* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureAddressKHR( pInfo );
#else
    return s_MockPtr->_GetAccelerationStructureAddressKHR( device, pInfo );
#endif
}

static vk::DeviceAddress
GetAccelerationStructureAddressKHR( vk::Device device, const vk::AccelerationStructureDeviceAddressInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureAddressKHR( info );
#else
    return s_MockPtr->_GetAccelerationStructureAddressKHR( device, info );
#endif
}

static void GetAccelerationStructureCompatibilityKHR( vk::Device device,
                                                      const vk::AccelerationStructureVersionInfoKHR* pVersionInfo,
                                                      vk::AccelerationStructureCompatibilityKHR* pCompatibility ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getAccelerationStructureCompatibilityKHR( pVersionInfo, pCompatibility );
#else
    s_MockPtr->_GetAccelerationStructureCompatibilityKHR( device, pVersionInfo, pCompatibility );
#endif
}

static vk::AccelerationStructureCompatibilityKHR
GetAccelerationStructureCompatibilityKHR( vk::Device device,
                                          const vk::AccelerationStructureVersionInfoKHR& versionInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureCompatibilityKHR( versionInfo );
#else
    return s_MockPtr->_GetAccelerationStructureCompatibilityKHR( device, versionInfo );
#endif
}

static void GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                                   const vk::AccelerationStructureBuildGeometryInfoKHR* pBuildInfo,
                                                   const uint32_t* pMaxPrimitiveCounts,
                                                   vk::AccelerationStructureBuildSizesInfoKHR* pSizeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getAccelerationStructureBuildSizesKHR( buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo );
#else
    s_MockPtr->_GetAccelerationStructureBuildSizesKHR( device, buildType, pBuildInfo, pMaxPrimitiveCounts, pSizeInfo );
#endif
}

static vk::AccelerationStructureBuildSizesInfoKHR
GetAccelerationStructureBuildSizesKHR( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                       const vk::AccelerationStructureBuildGeometryInfoKHR& buildInfo,
                                       vk::ArrayProxy<const uint32_t> const& maxPrimitiveCounts = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureBuildSizesKHR( buildType, buildInfo, nullptr );
#else
    return s_MockPtr->_GetAccelerationStructureBuildSizesKHR( device, buildType, buildInfo, nullptr );
#endif
}

static vk::Result CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                                vk::PipelineCache pipelineCache, uint32_t createInfoCount,
                                                const vk::RayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                const vk::AllocationCallbacks* pAllocator,
                                                vk::Pipeline* pPipelines ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesKHR( deferredOperation, pipelineCache, createInfoCount, pCreateInfos,
                                                pAllocator, pPipelines );
#else
    return s_MockPtr->_CreateRayTracingPipelinesKHR( device, deferredOperation, pipelineCache, createInfoCount,
                                                     pCreateInfos, pAllocator, pPipelines );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>>
static ResultValue<std::vector<vk::Pipeline, PipelineAllocator>>
CreateRayTracingPipelinesKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                              vk::PipelineCache pipelineCache,
                              vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesKHR( deferredOperation, pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelinesKHR( device, deferredOperation, pipelineCache, createInfos, nullptr );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>, typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, Pipeline>::value, int>::type = 0>
static ResultValue<std::vector<vk::Pipeline, PipelineAllocator>> CreateRayTracingPipelinesKHR(
        vk::Device device, vk::DeferredOperationKHR deferredOperation, vk::PipelineCache pipelineCache,
        vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
        Optional<const vk::AllocationCallbacks> allocator, PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesKHR( deferredOperation, pipelineCache, createInfos, allocator,
                                                pipelineAllocator );
#else
    return s_MockPtr->_CreateRayTracingPipelinesKHR( device, deferredOperation, pipelineCache, createInfos, allocator,
                                                     pipelineAllocator );
#endif
}

static ResultValue<vk::Pipeline>
CreateRayTracingPipelineKHR( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                             vk::PipelineCache pipelineCache, const vk::RayTracingPipelineCreateInfoKHR& createInfo,
                             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelineKHR( deferredOperation, pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelineKHR( device, deferredOperation, pipelineCache, createInfo, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename PipelineAllocator = std::allocator<UniqueHandle<vk::Pipeline, Dispatch>>>
static ResultValue<std::vector<UniqueHandle<vk::Pipeline, Dispatch>, PipelineAllocator>>
CreateRayTracingPipelinesKHRUnique( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                    vk::PipelineCache pipelineCache,
                                    vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
                                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesKHRUnique( deferredOperation, pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelinesKHRUnique( device, deferredOperation, pipelineCache, createInfos,
                                                           nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename PipelineAllocator = std::allocator<UniqueHandle<vk::Pipeline, Dispatch>>,
          typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, UniqueHandle<Pipeline, Dispatch>>::value,
                                  int>::type = 0>
static ResultValue<std::vector<UniqueHandle<vk::Pipeline, Dispatch>, PipelineAllocator>>
CreateRayTracingPipelinesKHRUnique( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                    vk::PipelineCache pipelineCache,
                                    vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoKHR> const& createInfos,
                                    Optional<const vk::AllocationCallbacks> allocator,
                                    PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesKHRUnique( deferredOperation, pipelineCache, createInfos, allocator,
                                                      pipelineAllocator );
#else
    return s_MockPtr->_CreateRayTracingPipelinesKHRUnique( device, deferredOperation, pipelineCache, createInfos,
                                                           allocator, pipelineAllocator );
#endif
}

static ResultValue<UniqueHandle<vk::Pipeline, Dispatch>>
CreateRayTracingPipelineKHRUnique( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                   vk::PipelineCache pipelineCache,
                                   const vk::RayTracingPipelineCreateInfoKHR& createInfo,
                                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelineKHRUnique( deferredOperation, pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelineKHRUnique( device, deferredOperation, pipelineCache, createInfo,
                                                          nullptr );
#endif
}

static vk::Result GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                      uint32_t groupCount, size_t dataSize, void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize, pData );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize, pData );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>>
GetRayTracingShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount,
                                    size_t dataSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount, dataSize );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType> GetRayTracingShaderGroupHandleKHR( vk::Device device, vk::Pipeline pipeline,
                                                                            uint32_t firstGroup,
                                                                            uint32_t groupCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandleKHR( pipeline, firstGroup, groupCount );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandleKHR( device, pipeline, firstGroup, groupCount );
#endif
}

static vk::Result GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline,
                                                                   uint32_t firstGroup, uint32_t groupCount,
                                                                   size_t dataSize, void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingCaptureReplayShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize, pData );
#else
    return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount,
                                                                        dataSize, pData );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>>
GetRayTracingCaptureReplayShaderGroupHandlesKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                 uint32_t groupCount, size_t dataSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingCaptureReplayShaderGroupHandlesKHR( pipeline, firstGroup, groupCount, dataSize );
#else
    return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandlesKHR( device, pipeline, firstGroup, groupCount,
                                                                        dataSize );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetRayTracingCaptureReplayShaderGroupHandleKHR( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                uint32_t groupCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingCaptureReplayShaderGroupHandleKHR( pipeline, firstGroup, groupCount );
#else
    return s_MockPtr->_GetRayTracingCaptureReplayShaderGroupHandleKHR( device, pipeline, firstGroup, groupCount );
#endif
}

static DeviceSize GetRayTracingShaderGroupStackSizeKHR( vk::Device device, vk::Pipeline pipeline, uint32_t group,
                                                        vk::ShaderGroupShaderKHR groupShader ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupStackSizeKHR( pipeline, group, groupShader );
#else
    return s_MockPtr->_GetRayTracingShaderGroupStackSizeKHR( device, pipeline, group, groupShader );
#endif
}

static vk::Result CreateSamplerYcbcrConversionKHR( vk::Device device,
                                                   const vk::SamplerYcbcrConversionCreateInfo* pCreateInfo,
                                                   const vk::AllocationCallbacks* pAllocator,
                                                   vk::SamplerYcbcrConversion* pYcbcrConversion ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversionKHR( pCreateInfo, pAllocator, pYcbcrConversion );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversionKHR( device, pCreateInfo, pAllocator, pYcbcrConversion );
#endif
}

static ResultValue<vk::Result, vk::SamplerYcbcrConversion>
CreateSamplerYcbcrConversionKHR( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversionKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversionKHR( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SamplerYcbcrConversion, Dispatch>>
CreateSamplerYcbcrConversionKHRUnique( vk::Device device, const vk::SamplerYcbcrConversionCreateInfo& createInfo,
                                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createSamplerYcbcrConversionKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateSamplerYcbcrConversionKHRUnique( device, createInfo, nullptr );
#endif
}

static void DestroySamplerYcbcrConversionKHR( vk::Device device, vk::SamplerYcbcrConversion ycbcrConversion,
                                              const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroySamplerYcbcrConversionKHR( ycbcrConversion, pAllocator );
#else
    s_MockPtr->_DestroySamplerYcbcrConversionKHR( device, ycbcrConversion, pAllocator );
#endif
}

static vk::Result BindBufferMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                                        const vk::BindBufferMemoryInfo* pBindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory2KHR( bindInfoCount, pBindInfos );
#else
    return s_MockPtr->_BindBufferMemory2KHR( device, bindInfoCount, pBindInfos );
#endif
}

static vk::Result BindBufferMemory2KHR( vk::Device device,
                                        vk::ArrayProxy<const vk::BindBufferMemoryInfo> const& bindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindBufferMemory2KHR( bindInfos );
#else
    return s_MockPtr->_BindBufferMemory2KHR( device, bindInfos );
#endif
}

static vk::Result BindImageMemory2KHR( vk::Device device, uint32_t bindInfoCount,
                                       const vk::BindImageMemoryInfo* pBindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory2KHR( bindInfoCount, pBindInfos );
#else
    return s_MockPtr->_BindImageMemory2KHR( device, bindInfoCount, pBindInfos );
#endif
}

static vk::Result BindImageMemory2KHR( vk::Device device,
                                       vk::ArrayProxy<const vk::BindImageMemoryInfo> const& bindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindImageMemory2KHR( bindInfos );
#else
    return s_MockPtr->_BindImageMemory2KHR( device, bindInfos );
#endif
}

static vk::Result GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image,
                                                          vk::ImageDrmFormatModifierPropertiesEXT* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageDrmFormatModifierPropertiesEXT( image, pProperties );
#else
    return s_MockPtr->_GetImageDrmFormatModifierPropertiesEXT( device, image, pProperties );
#endif
}

static ResultValue<vk::Result, vk::ImageDrmFormatModifierPropertiesEXT>
GetImageDrmFormatModifierPropertiesEXT( vk::Device device, vk::Image image ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageDrmFormatModifierPropertiesEXT( image );
#else
    return s_MockPtr->_GetImageDrmFormatModifierPropertiesEXT( device, image );
#endif
}

static vk::Result CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT* pCreateInfo,
                                            const vk::AllocationCallbacks* pAllocator,
                                            vk::ValidationCacheEXT* pValidationCache ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createValidationCacheEXT( pCreateInfo, pAllocator, pValidationCache );
#else
    return s_MockPtr->_CreateValidationCacheEXT( device, pCreateInfo, pAllocator, pValidationCache );
#endif
}

static ResultValue<vk::Result, vk::ValidationCacheEXT>
CreateValidationCacheEXT( vk::Device device, const vk::ValidationCacheCreateInfoEXT& createInfo,
                          Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createValidationCacheEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateValidationCacheEXT( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::ValidationCacheEXT, Dispatch>>
CreateValidationCacheEXTUnique( vk::Device device, const vk::ValidationCacheCreateInfoEXT& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createValidationCacheEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateValidationCacheEXTUnique( device, createInfo, nullptr );
#endif
}

static void DestroyValidationCacheEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                       const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyValidationCacheEXT( validationCache, pAllocator );
#else
    s_MockPtr->_DestroyValidationCacheEXT( device, validationCache, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( validationCache, pAllocator );
#else
    s_MockPtr->_Destroy( device, validationCache, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ValidationCacheEXT validationCache,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( validationCache, nullptr );
#else
    s_MockPtr->_Destroy( device, validationCache, nullptr );
#endif
}

static vk::Result MergeValidationCachesEXT( vk::Device device, vk::ValidationCacheEXT dstCache, uint32_t srcCacheCount,
                                            const vk::ValidationCacheEXT* pSrcCaches ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mergeValidationCachesEXT( dstCache, srcCacheCount, pSrcCaches );
#else
    return s_MockPtr->_MergeValidationCachesEXT( device, dstCache, srcCacheCount, pSrcCaches );
#endif
}

static vk::Result MergeValidationCachesEXT( vk::Device device, vk::ValidationCacheEXT dstCache,
                                            vk::ArrayProxy<const vk::ValidationCacheEXT> const& srcCaches ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mergeValidationCachesEXT( dstCache, srcCaches );
#else
    return s_MockPtr->_MergeValidationCachesEXT( device, dstCache, srcCaches );
#endif
}

static vk::Result GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                                             size_t* pDataSize, void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getValidationCacheDataEXT( validationCache, pDataSize, pData );
#else
    return s_MockPtr->_GetValidationCacheDataEXT( device, validationCache, pDataSize, pData );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getValidationCacheDataEXT( validationCache );
#else
    return s_MockPtr->_GetValidationCacheDataEXT( device, validationCache );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>, typename B1 = Uint8_tAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, uint8_t>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetValidationCacheDataEXT( vk::Device device, vk::ValidationCacheEXT validationCache,
                           Uint8_tAllocator& uint8_tAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getValidationCacheDataEXT( validationCache, uint8_tAllocator );
#else
    return s_MockPtr->_GetValidationCacheDataEXT( device, validationCache, uint8_tAllocator );
#endif
}

static vk::Result CreateAccelerationStructureNV( vk::Device device,
                                                 const vk::AccelerationStructureCreateInfoNV* pCreateInfo,
                                                 const vk::AllocationCallbacks* pAllocator,
                                                 vk::AccelerationStructureNV* pAccelerationStructure ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureNV( pCreateInfo, pAllocator, pAccelerationStructure );
#else
    return s_MockPtr->_CreateAccelerationStructureNV( device, pCreateInfo, pAllocator, pAccelerationStructure );
#endif
}

static ResultValue<vk::Result, vk::AccelerationStructureNV>
CreateAccelerationStructureNV( vk::Device device, const vk::AccelerationStructureCreateInfoNV& createInfo,
                               Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureNV( createInfo, nullptr );
#else
    return s_MockPtr->_CreateAccelerationStructureNV( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::AccelerationStructureNV, Dispatch>>
CreateAccelerationStructureNVUnique( vk::Device device, const vk::AccelerationStructureCreateInfoNV& createInfo,
                                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createAccelerationStructureNVUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateAccelerationStructureNVUnique( device, createInfo, nullptr );
#endif
}

static void DestroyAccelerationStructureNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                            const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyAccelerationStructureNV( accelerationStructure, pAllocator );
#else
    s_MockPtr->_DestroyAccelerationStructureNV( device, accelerationStructure, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( accelerationStructure, pAllocator );
#else
    s_MockPtr->_Destroy( device, accelerationStructure, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( accelerationStructure, nullptr );
#else
    s_MockPtr->_Destroy( device, accelerationStructure, nullptr );
#endif
}

static void
GetAccelerationStructureMemoryRequirementsNV( vk::Device device,
                                              const vk::AccelerationStructureMemoryRequirementsInfoNV* pInfo,
                                              vk::MemoryRequirements2KHR* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getAccelerationStructureMemoryRequirementsNV( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetAccelerationStructureMemoryRequirementsNV( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2KHR
GetAccelerationStructureMemoryRequirementsNV( vk::Device device,
                                              const vk::AccelerationStructureMemoryRequirementsInfoNV& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureMemoryRequirementsNV( info );
#else
    return s_MockPtr->_GetAccelerationStructureMemoryRequirementsNV( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetAccelerationStructureMemoryRequirementsNV( vk::Device device,
                                              const vk::AccelerationStructureMemoryRequirementsInfoNV& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureMemoryRequirementsNV( info );
#else
    return s_MockPtr->_GetAccelerationStructureMemoryRequirementsNV( device, info );
#endif
}

static vk::Result BindAccelerationStructureMemoryNV( vk::Device device, uint32_t bindInfoCount,
                                                     const vk::BindAccelerationStructureMemoryInfoNV* pBindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindAccelerationStructureMemoryNV( bindInfoCount, pBindInfos );
#else
    return s_MockPtr->_BindAccelerationStructureMemoryNV( device, bindInfoCount, pBindInfos );
#endif
}

static vk::Result BindAccelerationStructureMemoryNV(
        vk::Device device, vk::ArrayProxy<const vk::BindAccelerationStructureMemoryInfoNV> const& bindInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindAccelerationStructureMemoryNV( bindInfos );
#else
    return s_MockPtr->_BindAccelerationStructureMemoryNV( device, bindInfos );
#endif
}

static vk::Result CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache,
                                               uint32_t createInfoCount,
                                               const vk::RayTracingPipelineCreateInfoNV* pCreateInfos,
                                               const vk::AllocationCallbacks* pAllocator,
                                               vk::Pipeline* pPipelines ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesNV( pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines );
#else
    return s_MockPtr->_CreateRayTracingPipelinesNV( device, pipelineCache, createInfoCount, pCreateInfos, pAllocator,
                                                    pPipelines );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>>
static ResultValue<std::vector<vk::Pipeline, PipelineAllocator>>
CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache,
                             vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesNV( pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelinesNV( device, pipelineCache, createInfos, nullptr );
#endif
}

template <typename PipelineAllocator = std::allocator<vk::Pipeline>, typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, Pipeline>::value, int>::type = 0>
static ResultValue<std::vector<vk::Pipeline, PipelineAllocator>>
CreateRayTracingPipelinesNV( vk::Device device, vk::PipelineCache pipelineCache,
                             vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                             Optional<const vk::AllocationCallbacks> allocator,
                             PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesNV( pipelineCache, createInfos, allocator, pipelineAllocator );
#else
    return s_MockPtr->_CreateRayTracingPipelinesNV( device, pipelineCache, createInfos, allocator, pipelineAllocator );
#endif
}

static ResultValue<vk::Pipeline>
CreateRayTracingPipelineNV( vk::Device device, vk::PipelineCache pipelineCache,
                            const vk::RayTracingPipelineCreateInfoNV& createInfo,
                            Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelineNV( pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelineNV( device, pipelineCache, createInfo, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename PipelineAllocator = std::allocator<UniqueHandle<vk::Pipeline, Dispatch>>>
static ResultValue<std::vector<UniqueHandle<vk::Pipeline, Dispatch>, PipelineAllocator>>
CreateRayTracingPipelinesNVUnique( vk::Device device, vk::PipelineCache pipelineCache,
                                   vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesNVUnique( pipelineCache, createInfos, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelinesNVUnique( device, pipelineCache, createInfos, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename PipelineAllocator = std::allocator<UniqueHandle<vk::Pipeline, Dispatch>>,
          typename B0 = PipelineAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, UniqueHandle<Pipeline, Dispatch>>::value,
                                  int>::type = 0>
static ResultValue<std::vector<UniqueHandle<vk::Pipeline, Dispatch>, PipelineAllocator>>
CreateRayTracingPipelinesNVUnique( vk::Device device, vk::PipelineCache pipelineCache,
                                   vk::ArrayProxy<const vk::RayTracingPipelineCreateInfoNV> const& createInfos,
                                   Optional<const vk::AllocationCallbacks> allocator,
                                   PipelineAllocator& pipelineAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelinesNVUnique( pipelineCache, createInfos, allocator, pipelineAllocator );
#else
    return s_MockPtr->_CreateRayTracingPipelinesNVUnique( device, pipelineCache, createInfos, allocator,
                                                          pipelineAllocator );
#endif
}

static ResultValue<UniqueHandle<vk::Pipeline, Dispatch>>
CreateRayTracingPipelineNVUnique( vk::Device device, vk::PipelineCache pipelineCache,
                                  const vk::RayTracingPipelineCreateInfoNV& createInfo,
                                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createRayTracingPipelineNVUnique( pipelineCache, createInfo, nullptr );
#else
    return s_MockPtr->_CreateRayTracingPipelineNVUnique( device, pipelineCache, createInfo, nullptr );
#endif
}

static vk::Result GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup,
                                                     uint32_t groupCount, size_t dataSize, void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandlesNV( pipeline, firstGroup, groupCount, dataSize, pData );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandlesNV( device, pipeline, firstGroup, groupCount, dataSize, pData );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>>
GetRayTracingShaderGroupHandlesNV( vk::Device device, vk::Pipeline pipeline, uint32_t firstGroup, uint32_t groupCount,
                                   size_t dataSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandlesNV( pipeline, firstGroup, groupCount, dataSize );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandlesNV( device, pipeline, firstGroup, groupCount, dataSize );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType> GetRayTracingShaderGroupHandleNV( vk::Device device, vk::Pipeline pipeline,
                                                                           uint32_t firstGroup,
                                                                           uint32_t groupCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRayTracingShaderGroupHandleNV( pipeline, firstGroup, groupCount );
#else
    return s_MockPtr->_GetRayTracingShaderGroupHandleNV( device, pipeline, firstGroup, groupCount );
#endif
}

static vk::Result GetAccelerationStructureHandleNV( vk::Device device,
                                                    vk::AccelerationStructureNV accelerationStructure, size_t dataSize,
                                                    f void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureHandleNV( accelerationStructure, dataSize, pData );
#else
    return s_MockPtr->_GetAccelerationStructureHandleNV( device, accelerationStructure, dataSize, pData );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>>
GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure,
                                  size_t dataSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureHandleNV( accelerationStructure, dataSize );
#else
    return s_MockPtr->_GetAccelerationStructureHandleNV( device, accelerationStructure, dataSize );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetAccelerationStructureHandleNV( vk::Device device, vk::AccelerationStructureNV accelerationStructure ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureHandleNV( accelerationStructure );
#else
    return s_MockPtr->_GetAccelerationStructureHandleNV( device, accelerationStructure );
#endif
}

static vk::Result CompileDeferredNV( vk::Device device, vk::Pipeline pipeline, uint32_t shader ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.compileDeferredNV( pipeline, shader );
#else
    return s_MockPtr->_CompileDeferredNV( device, pipeline, shader );
#endif
}

static vk::Result CompileDeferredNV( vk::Device device, vk::Pipeline pipeline, uint32_t shader ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.compileDeferredNV( pipeline, shader );
#else
    return s_MockPtr->_CompileDeferredNV( device, pipeline, shader );
#endif
}

static void GetDescriptorSetLayoutSupportKHR( vk::Device device, const vk::DescriptorSetLayoutCreateInfo* pCreateInfo,
                                              vk::DescriptorSetLayoutSupport* pSupport ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetLayoutSupportKHR( pCreateInfo, pSupport );
#else
    s_MockPtr->_GetDescriptorSetLayoutSupportKHR( device, pCreateInfo, pSupport );
#endif
}

static vk::DescriptorSetLayoutSupport
GetDescriptorSetLayoutSupportKHR( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutSupportKHR( createInfo );
#else
    return s_MockPtr->_GetDescriptorSetLayoutSupportKHR( device, createInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetDescriptorSetLayoutSupportKHR( vk::Device device, const vk::DescriptorSetLayoutCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutSupportKHR( createInfo );
#else
    return s_MockPtr->_GetDescriptorSetLayoutSupportKHR( device, createInfo );
#endif
}

static vk::Result
GetMemoryHostPointerPropertiesEXT( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                   const void* pHostPointer,
                                   vk::MemoryHostPointerPropertiesEXT* pMemoryHostPointerProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryHostPointerPropertiesEXT( handleType, pHostPointer, pMemoryHostPointerProperties );
#else
    return s_MockPtr->_GetMemoryHostPointerPropertiesEXT( device, handleType, pHostPointer,
                                                          pMemoryHostPointerProperties );
#endif
}

static ResultValue<vk::Result, vk::MemoryHostPointerPropertiesEXT>
GetMemoryHostPointerPropertiesEXT( vk::Device device, vk::ExternalMemoryHandleTypeFlagBits handleType,
                                   const void* pHostPointer ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryHostPointerPropertiesEXT( handleType, pHostPointer );
#else
    return s_MockPtr->_GetMemoryHostPointerPropertiesEXT( device, handleType, pHostPointer );
#endif
}

static vk::Result GetCalibratedTimestampsEXT( vk::Device device, uint32_t timestampCount,
                                              const vk::CalibratedTimestampInfoEXT* pTimestampInfos,
                                              uint64_t* pTimestamps, uint64_t* pMaxDeviation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getCalibratedTimestampsEXT( timestampCount, pTimestampInfos, pTimestamps, pMaxDeviation );
#else
    return s_MockPtr->_GetCalibratedTimestampsEXT( device, timestampCount, pTimestampInfos, pTimestamps,
                                                   pMaxDeviation );
#endif
}

template <typename Uint64_tAllocator = std::allocator<uint64_t>>
static ResultValue<vk::Result, std::pair<std::vector<uint64_t, Uint64_tAllocator>, uint64_t>>
GetCalibratedTimestampsEXT( vk::Device device,
                            vk::ArrayProxy<const vk::CalibratedTimestampInfoEXT> const& timestampInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getCalibratedTimestampsEXT( timestampInfos );
#else
    return s_MockPtr->_GetCalibratedTimestampsEXT( device, timestampInfos );
#endif
}

template <typename Uint64_tAllocator = std::allocator<uint64_t>, typename B0 = Uint64_tAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, uint64_t>::value, int>::type = 0>
static ResultValue<vk::Result, std::pair<std::vector<uint64_t, Uint64_tAllocator>, uint64_t>>
GetCalibratedTimestampsEXT( vk::Device device,
                            vk::ArrayProxy<const vk::CalibratedTimestampInfoEXT> const& timestampInfos,
                            Uint64_tAllocator& uint64_tAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getCalibratedTimestampsEXT( timestampInfos, uint64_tAllocator );
#else
    return s_MockPtr->_GetCalibratedTimestampsEXT( device, timestampInfos, uint64_tAllocator );
#endif
}

static ResultValue<vk::Result, std::pair<uint64_t, uint64_t>>
GetCalibratedTimestampEXT( vk::Device device, const vk::CalibratedTimestampInfoEXT& timestampInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getCalibratedTimestampEXT( timestampInfo );
#else
    return s_MockPtr->_GetCalibratedTimestampEXT( device, timestampInfo );
#endif
}

static vk::Result GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore, uint64_t* pValue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreCounterValueKHR( semaphore, pValue );
#else
    return s_MockPtr->_GetSemaphoreCounterValueKHR( device, semaphore, pValue );
#endif
}

static ResultValue<vk::Result, uint64_t> GetSemaphoreCounterValueKHR( vk::Device device, vk::Semaphore semaphore ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSemaphoreCounterValueKHR( semaphore );
#else
    return s_MockPtr->_GetSemaphoreCounterValueKHR( device, semaphore );
#endif
}

static vk::Result WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo* pWaitInfo, uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitSemaphoresKHR( pWaitInfo, timeout );
#else
    return s_MockPtr->_WaitSemaphoresKHR( device, pWaitInfo, timeout );
#endif
}

static vk::Result WaitSemaphoresKHR( vk::Device device, const vk::SemaphoreWaitInfo& waitInfo, uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitSemaphoresKHR( waitInfo, timeout );
#else
    return s_MockPtr->_WaitSemaphoresKHR( device, waitInfo, timeout );
#endif
}

static vk::Result SignalSemaphoreKHR( vk::Device device, const vk::SemaphoreSignalInfo* pSignalInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.signalSemaphoreKHR( pSignalInfo );
#else
    return s_MockPtr->_SignalSemaphoreKHR( device, pSignalInfo );
#endif
}

static vk::Result SignalSemaphoreKHR( vk::Device device, const vk::SemaphoreSignalInfo& signalInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.signalSemaphoreKHR( signalInfo );
#else
    return s_MockPtr->_SignalSemaphoreKHR( device, signalInfo );
#endif
}

static vk::Result InitializePerformanceApiINTEL( vk::Device device,
                                                 const vk::InitializePerformanceApiInfoINTEL* pInitializeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.initializePerformanceApiINTEL( pInitializeInfo );
#else
    return s_MockPtr->_InitializePerformanceApiINTEL( device, pInitializeInfo );
#endif
}

static vk::Result InitializePerformanceApiINTEL( vk::Device device,
                                                 const vk::InitializePerformanceApiInfoINTEL& initializeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.initializePerformanceApiINTEL( initializeInfo );
#else
    return s_MockPtr->_InitializePerformanceApiINTEL( device, initializeInfo );
#endif
}

static void UninitializePerformanceApiINTEL( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.uninitializePerformanceApiINTEL();
#else
    s_MockPtr->_UninitializePerformanceApiINTEL();
#endif
}

static vk::Result
AcquirePerformanceConfigurationINTEL( vk::Device device,
                                      const vk::PerformanceConfigurationAcquireInfoINTEL* pAcquireInfo,
                                      vk::PerformanceConfigurationINTEL* pConfiguration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquirePerformanceConfigurationINTEL( pAcquireInfo, pConfiguration );
#else
    return s_MockPtr->_AcquirePerformanceConfigurationINTEL( device, pAcquireInfo, pConfiguration );
#endif
}

static ResultValue<vk::Result, vk::PerformanceConfigurationINTEL>
AcquirePerformanceConfigurationINTEL( vk::Device device,
                                      const vk::PerformanceConfigurationAcquireInfoINTEL& acquireInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquirePerformanceConfigurationINTEL( acquireInfo );
#else
    return s_MockPtr->_AcquirePerformanceConfigurationINTEL( device, acquireInfo );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::PerformanceConfigurationINTEL, Dispatch>>
AcquirePerformanceConfigurationINTELUnique( vk::Device device,
                                            const vk::PerformanceConfigurationAcquireInfoINTEL& acquireInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquirePerformanceConfigurationINTELUnique( acquireInfo );
#else
    return s_MockPtr->_AcquirePerformanceConfigurationINTELUnique( device, acquireInfo );
#endif
}

static vk::Result ReleasePerformanceConfigurationINTEL( vk::Device device,
                                                        vk::PerformanceConfigurationINTEL configuration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.releasePerformanceConfigurationINTEL( configuration );
#else
    return s_MockPtr->_ReleasePerformanceConfigurationINTEL( device, configuration );
#endif
}

static vk::Result Release( vk::Device device, vk::PerformanceConfigurationINTEL configuration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.release( configuration );
#else
    return s_MockPtr->_Release( device, configuration );
#endif
}

static vk::Result Release( vk::Device device, vk::PerformanceConfigurationINTEL configuration ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.release( configuration );
#else
    return s_MockPtr->_Release( device, configuration );
#endif
}

static vk::Result GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter,
                                                vk::PerformanceValueINTEL* pValue ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPerformanceParameterINTEL( parameter, pValue );
#else
    return s_MockPtr->_GetPerformanceParameterINTEL( device, parameter, pValue );
#endif
}

static ResultValue<vk::Result, vk::PerformanceValueINTEL>
GetPerformanceParameterINTEL( vk::Device device, vk::PerformanceParameterTypeINTEL parameter ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPerformanceParameterINTEL( parameter );
#else
    return s_MockPtr->_GetPerformanceParameterINTEL( device, parameter );
#endif
}

static void SetLocalDimmingAMD( vk::Device device, vk::SwapchainKHR swapChain, vk::Bool32 localDimmingEnable ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.setLocalDimmingAMD( swapChain, localDimmingEnable );
#else
    s_MockPtr->_SetLocalDimmingAMD( device, swapChain, localDimmingEnable );
#endif
}

static DeviceAddress GetBufferAddressEXT( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddressEXT( pInfo );
#else
    return s_MockPtr->_GetBufferAddressEXT( device, pInfo );
#endif
}

static vk::DeviceAddress GetBufferAddressEXT( vk::Device device, const vk::BufferDeviceAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddressEXT( info );
#else
    return s_MockPtr->_GetBufferAddressEXT( device, info );
#endif
}

static vk::Result WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain, uint64_t presentId,
                                     uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitForPresentKHR( swapchain, presentId, timeout );
#else
    return s_MockPtr->_WaitForPresentKHR( device, swapchain, presentId, timeout );
#endif
}

static vk::Result WaitForPresentKHR( vk::Device device, vk::SwapchainKHR swapchain, uint64_t presentId,
                                     uint64_t timeout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.waitForPresentKHR( swapchain, presentId, timeout );
#else
    return s_MockPtr->_WaitForPresentKHR( device, swapchain, presentId, timeout );
#endif
}

static vk::Result AcquireFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireFullScreenExclusiveModeEXT( swapchain );
#else
    return s_MockPtr->_AcquireFullScreenExclusiveModeEXT( device, swapchain );
#endif
}

static vk::Result AcquireFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.acquireFullScreenExclusiveModeEXT( swapchain );
#else
    return s_MockPtr->_AcquireFullScreenExclusiveModeEXT( device, swapchain );
#endif
}

static vk::Result ReleaseFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.releaseFullScreenExclusiveModeEXT( swapchain );
#else
    return s_MockPtr->_ReleaseFullScreenExclusiveModeEXT( device, swapchain );
#endif
}

static vk::Result ReleaseFullScreenExclusiveModeEXT( vk::Device device, vk::SwapchainKHR swapchain ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.releaseFullScreenExclusiveModeEXT( swapchain );
#else
    return s_MockPtr->_ReleaseFullScreenExclusiveModeEXT( device, swapchain );
#endif
}

static vk::Result GetGroupSurfacePresentModes2EXT( vk::Device device,
                                                   const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                                   vk::DeviceGroupPresentModeFlagsKHR* pModes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupSurfacePresentModes2EXT( pSurfaceInfo, pModes );
#else
    return s_MockPtr->_GetGroupSurfacePresentModes2EXT( device, pSurfaceInfo, pModes );
#endif
}

static ResultValue<vk::Result, vk::DeviceGroupPresentModeFlagsKHR>
GetGroupSurfacePresentModes2EXT( vk::Device device, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGroupSurfacePresentModes2EXT( surfaceInfo );
#else
    return s_MockPtr->_GetGroupSurfacePresentModes2EXT( device, surfaceInfo );
#endif
}

static DeviceAddress GetBufferAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddressKHR( pInfo );
#else
    return s_MockPtr->_GetBufferAddressKHR( device, pInfo );
#endif
}

static vk::DeviceAddress GetBufferAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferAddressKHR( info );
#else
    return s_MockPtr->_GetBufferAddressKHR( device, info );
#endif
}

static uint64_t GetBufferOpaqueCaptureAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureAddressKHR( pInfo );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureAddressKHR( device, pInfo );
#endif
}

static uint64_t GetBufferOpaqueCaptureAddressKHR( vk::Device device, const vk::BufferDeviceAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureAddressKHR( info );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureAddressKHR( device, info );
#endif
}

static uint64_t GetMemoryOpaqueCaptureAddressKHR( vk::Device device,
                                                  const vk::DeviceMemoryOpaqueCaptureAddressInfo* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryOpaqueCaptureAddressKHR( pInfo );
#else
    return s_MockPtr->_GetMemoryOpaqueCaptureAddressKHR( device, pInfo );
#endif
}

static uint64_t GetMemoryOpaqueCaptureAddressKHR( vk::Device device,
                                                  const vk::DeviceMemoryOpaqueCaptureAddressInfo& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryOpaqueCaptureAddressKHR( info );
#else
    return s_MockPtr->_GetMemoryOpaqueCaptureAddressKHR( device, info );
#endif
}

static void ResetQueryPoolEXT( vk::Device device, vk::QueryPool queryPool, uint32_t firstQuery,
                               uint32_t queryCount ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.resetQueryPoolEXT( queryPool, firstQuery, queryCount );
#else
    s_MockPtr->_ResetQueryPoolEXT( device, queryPool, firstQuery, queryCount );
#endif
}

static vk::Result CreateDeferredOperationKHR( vk::Device device, const vk::AllocationCallbacks* pAllocator,
                                              vk::DeferredOperationKHR* pDeferredOperation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDeferredOperationKHR( pAllocator, pDeferredOperation );
#else
    return s_MockPtr->_CreateDeferredOperationKHR( device, pAllocator, pDeferredOperation );
#endif
}

static ResultValue<vk::Result, vk::DeferredOperationKHR>
CreateDeferredOperationKHR( vk::Device device, Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDeferredOperationKHR( nullptr );
#else
    return s_MockPtr->_CreateDeferredOperationKHR( device, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DeferredOperationKHR, Dispatch>>
CreateDeferredOperationKHRUnique( vk::Device device, Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createDeferredOperationKHRUnique( nullptr );
#else
    return s_MockPtr->_CreateDeferredOperationKHRUnique( device, nullptr );
#endif
}

static void DestroyDeferredOperationKHR( vk::Device device, vk::DeferredOperationKHR operation,
                                         const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyDeferredOperationKHR( operation, pAllocator );
#else
    s_MockPtr->_DestroyDeferredOperationKHR( device, operation, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( operation, pAllocator );
#else
    s_MockPtr->_Destroy( device, operation, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::DeferredOperationKHR operation,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( operation, nullptr );
#else
    s_MockPtr->_Destroy( device, operation, nullptr );
#endif
}

static uint32_t GetDeferredOperationMaxConcurrencyKHR( vk::Device device, vk::DeferredOperationKHR operation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDeferredOperationMaxConcurrencyKHR( operation );
#else
    return s_MockPtr->_GetDeferredOperationMaxConcurrencyKHR( device, operation );
#endif
}

static vk::Result GetDeferredOperationResultKHR( vk::Device device, vk::DeferredOperationKHR operation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDeferredOperationResultKHR( operation );
#else
    return s_MockPtr->_GetDeferredOperationResultKHR( device, operation );
#endif
}

static vk::Result GetDeferredOperationResultKHR( vk::Device device, vk::DeferredOperationKHR operation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDeferredOperationResultKHR( operation );
#else
    return s_MockPtr->_GetDeferredOperationResultKHR( device, operation );
#endif
}

static vk::Result DeferredOperationJoinKHR( vk::Device device, vk::DeferredOperationKHR operation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.deferredOperationJoinKHR( operation );
#else
    return s_MockPtr->_DeferredOperationJoinKHR( device, operation );
#endif
}

static vk::Result DeferredOperationJoinKHR( vk::Device device, vk::DeferredOperationKHR operation ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.deferredOperationJoinKHR( operation );
#else
    return s_MockPtr->_DeferredOperationJoinKHR( device, operation );
#endif
}

static vk::Result GetPipelineExecutablePropertiesKHR( vk::Device device, const vk::PipelineInfoKHR* pPipelineInfo,
                                                      uint32_t* pExecutableCount,
                                                      vk::PipelineExecutablePropertiesKHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutablePropertiesKHR( pPipelineInfo, pExecutableCount, pProperties );
#else
    return s_MockPtr->_GetPipelineExecutablePropertiesKHR( device, pPipelineInfo, pExecutableCount, pProperties );
#endif
}

template <typename PipelineExecutablePropertiesKHRAllocator = std::allocator<vk::PipelineExecutablePropertiesKHR>>
static ResultValue<vk::Result,
                   std::vector<vk::PipelineExecutablePropertiesKHR, PipelineExecutablePropertiesKHRAllocator>>
GetPipelineExecutablePropertiesKHR( vk::Device device, const vk::PipelineInfoKHR& pipelineInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutablePropertiesKHR( pipelineInfo );
#else
    return s_MockPtr->_GetPipelineExecutablePropertiesKHR( device, pipelineInfo );
#endif
}

template <typename PipelineExecutablePropertiesKHRAllocator = std::allocator<vk::PipelineExecutablePropertiesKHR>,
          typename B1 = PipelineExecutablePropertiesKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PipelineExecutablePropertiesKHR>::value,
                                  int>::type = 0>
static ResultValue<vk::Result,
                   std::vector<vk::PipelineExecutablePropertiesKHR, PipelineExecutablePropertiesKHRAllocator>>
GetPipelineExecutablePropertiesKHR(
        vk::Device device, const vk::PipelineInfoKHR& pipelineInfo,
        PipelineExecutablePropertiesKHRAllocator& pipelineExecutablePropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutablePropertiesKHR( pipelineInfo, pipelineExecutablePropertiesKHRAllocator );
#else
    return s_MockPtr->_GetPipelineExecutablePropertiesKHR( device, pipelineInfo,
                                                           pipelineExecutablePropertiesKHRAllocator );
#endif
}

static vk::Result GetPipelineExecutableStatisticsKHR( vk::Device device,
                                                      const vk::PipelineExecutableInfoKHR* pExecutableInfo,
                                                      uint32_t* pStatisticCount,
                                                      vk::PipelineExecutableStatisticKHR* pStatistics ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableStatisticsKHR( pExecutableInfo, pStatisticCount, pStatistics );
#else
    return s_MockPtr->_GetPipelineExecutableStatisticsKHR( device, pExecutableInfo, pStatisticCount, pStatistics );
#endif
}

template <typename PipelineExecutableStatisticKHRAllocator = std::allocator<vk::PipelineExecutableStatisticKHR>>
static ResultValue<vk::Result, std::vector<vk::PipelineExecutableStatisticKHR, PipelineExecutableStatisticKHRAllocator>>
GetPipelineExecutableStatisticsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR& executableInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableStatisticsKHR( executableInfo );
#else
    return s_MockPtr->_GetPipelineExecutableStatisticsKHR( device, executableInfo );
#endif
}

template <typename PipelineExecutableStatisticKHRAllocator = std::allocator<vk::PipelineExecutableStatisticKHR>,
          typename B1 = PipelineExecutableStatisticKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PipelineExecutableStatisticKHR>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PipelineExecutableStatisticKHR, PipelineExecutableStatisticKHRAllocator>>
GetPipelineExecutableStatisticsKHR(
        vk::Device device, const vk::PipelineExecutableInfoKHR& executableInfo,
        PipelineExecutableStatisticKHRAllocator& pipelineExecutableStatisticKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableStatisticsKHR( executableInfo, pipelineExecutableStatisticKHRAllocator );
#else
    return s_MockPtr->_GetPipelineExecutableStatisticsKHR( device, executableInfo,
                                                           pipelineExecutableStatisticKHRAllocator );
#endif
}

static vk::Result GetPipelineExecutableInternalRepresentationsKHR(
        vk::Device device, const vk::PipelineExecutableInfoKHR* pExecutableInfo, uint32_t* pInternalRepresentationCount,
        vk::PipelineExecutableInternalRepresentationKHR* pInternalRepresentations ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableInternalRepresentationsKHR( pExecutableInfo, pInternalRepresentationCount,
                                                                   pInternalRepresentations );
#else
    return s_MockPtr->_GetPipelineExecutableInternalRepresentationsKHR(
            device, pExecutableInfo, pInternalRepresentationCount, pInternalRepresentations );
#endif
}

template <typename PipelineExecutableInternalRepresentationKHRAllocator =
                  std::allocator<vk::PipelineExecutableInternalRepresentationKHR>>
static ResultValue<vk::Result, std::vector<vk::PipelineExecutableInternalRepresentationKHR,
                                           PipelineExecutableInternalRepresentationKHRAllocator>>
GetPipelineExecutableInternalRepresentationsKHR( vk::Device device,
                                                 const vk::PipelineExecutableInfoKHR& executableInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableInternalRepresentationsKHR( executableInfo );
#else
    return s_MockPtr->_GetPipelineExecutableInternalRepresentationsKHR( device, executableInfo );
#endif
}

template <typename PipelineExecutableInternalRepresentationKHRAllocator =
                  std::allocator<vk::PipelineExecutableInternalRepresentationKHR>,
          typename B1 = PipelineExecutableInternalRepresentationKHRAllocator,
          typename std::enable_if<
                  std::is_same<typename B1::value_type, PipelineExecutableInternalRepresentationKHR>::value,
                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PipelineExecutableInternalRepresentationKHR,
                                           PipelineExecutableInternalRepresentationKHRAllocator>>
GetPipelineExecutableInternalRepresentationsKHR( vk::Device device, const vk::PipelineExecutableInfoKHR& executableInfo,
                                                 PipelineExecutableInternalRepresentationKHRAllocator&
                                                         pipelineExecutableInternalRepresentationKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineExecutableInternalRepresentationsKHR(
            executableInfo, pipelineExecutableInternalRepresentationKHRAllocator );
#else
    return s_MockPtr->_GetPipelineExecutableInternalRepresentationsKHR(
            device, executableInfo, pipelineExecutableInternalRepresentationKHRAllocator );
#endif
}

static vk::Result CopyMemoryToImageEXT( vk::Device device,
                                        const vk::CopyMemoryToImageInfoEXT* pCopyMemoryToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToImageEXT( pCopyMemoryToImageInfo );
#else
    return s_MockPtr->_CopyMemoryToImageEXT( device, pCopyMemoryToImageInfo );
#endif
}

static vk::Result CopyMemoryToImageEXT( vk::Device device,
                                        const vk::CopyMemoryToImageInfoEXT& copyMemoryToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToImageEXT( copyMemoryToImageInfo );
#else
    return s_MockPtr->_CopyMemoryToImageEXT( device, copyMemoryToImageInfo );
#endif
}

static vk::Result CopyImageToMemoryEXT( vk::Device device,
                                        const vk::CopyImageToMemoryInfoEXT* pCopyImageToMemoryInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyImageToMemoryEXT( pCopyImageToMemoryInfo );
#else
    return s_MockPtr->_CopyImageToMemoryEXT( device, pCopyImageToMemoryInfo );
#endif
}

static vk::Result CopyImageToMemoryEXT( vk::Device device,
                                        const vk::CopyImageToMemoryInfoEXT& copyImageToMemoryInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyImageToMemoryEXT( copyImageToMemoryInfo );
#else
    return s_MockPtr->_CopyImageToMemoryEXT( device, copyImageToMemoryInfo );
#endif
}

static vk::Result CopyImageToImageEXT( vk::Device device,
                                       const vk::CopyImageToImageInfoEXT* pCopyImageToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyImageToImageEXT( pCopyImageToImageInfo );
#else
    return s_MockPtr->_CopyImageToImageEXT( device, pCopyImageToImageInfo );
#endif
}

static vk::Result CopyImageToImageEXT( vk::Device device,
                                       const vk::CopyImageToImageInfoEXT& copyImageToImageInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyImageToImageEXT( copyImageToImageInfo );
#else
    return s_MockPtr->_CopyImageToImageEXT( device, copyImageToImageInfo );
#endif
}

static vk::Result TransitionImageLayoutEXT( vk::Device device, uint32_t transitionCount,
                                            const vk::HostImageLayoutTransitionInfoEXT* pTransitions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.transitionImageLayoutEXT( transitionCount, pTransitions );
#else
    return s_MockPtr->_TransitionImageLayoutEXT( device, transitionCount, pTransitions );
#endif
}

static vk::Result
TransitionImageLayoutEXT( vk::Device device,
                          vk::ArrayProxy<const vk::HostImageLayoutTransitionInfoEXT> const& transitions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.transitionImageLayoutEXT( transitions );
#else
    return s_MockPtr->_TransitionImageLayoutEXT( device, transitions );
#endif
}

static void GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image,
                                           const vk::ImageSubresource2KHR* pSubresource,
                                           vk::SubresourceLayout2KHR* pLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSubresourceLayout2EXT( image, pSubresource, pLayout );
#else
    s_MockPtr->_GetImageSubresourceLayout2EXT( device, image, pSubresource, pLayout );
#endif
}

static vk::SubresourceLayout2KHR GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image,
                                                                const vk::ImageSubresource2KHR& subresource ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayout2EXT( image, subresource );
#else
    return s_MockPtr->_GetImageSubresourceLayout2EXT( device, image, subresource );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetImageSubresourceLayout2EXT( vk::Device device, vk::Image image,
                                                                     const vk::ImageSubresource2KHR& subresource ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayout2EXT( image, subresource );
#else
    return s_MockPtr->_GetImageSubresourceLayout2EXT( device, image, subresource );
#endif
}

static vk::Result MapMemory2KHR( vk::Device device, const vk::MemoryMapInfoKHR* pMemoryMapInfo, void** ppData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mapMemory2KHR( pMemoryMapInfo, ppData );
#else
    return s_MockPtr->_MapMemory2KHR( device, pMemoryMapInfo, ppData );
#endif
}

static ResultValue<vk::Result, void*> MapMemory2KHR( vk::Device device,
                                                     const vk::MemoryMapInfoKHR& memoryMapInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.mapMemory2KHR( memoryMapInfo );
#else
    return s_MockPtr->_MapMemory2KHR( device, memoryMapInfo );
#endif
}

static vk::Result UnmapMemory2KHR( vk::Device device, const vk::MemoryUnmapInfoKHR* pMemoryUnmapInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.unmapMemory2KHR( pMemoryUnmapInfo );
#else
    return s_MockPtr->_UnmapMemory2KHR( device, pMemoryUnmapInfo );
#endif
}

static void UnmapMemory2KHR( vk::Device device, const vk::MemoryUnmapInfoKHR& memoryUnmapInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.unmapMemory2KHR( memoryUnmapInfo );
#else
    s_MockPtr->_UnmapMemory2KHR( device, memoryUnmapInfo );
#endif
}

static vk::Result ReleaseSwapchainImagesEXT( vk::Device device,
                                             const vk::ReleaseSwapchainImagesInfoEXT* pReleaseInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.releaseSwapchainImagesEXT( pReleaseInfo );
#else
    return s_MockPtr->_ReleaseSwapchainImagesEXT( device, pReleaseInfo );
#endif
}

static vk::Result ReleaseSwapchainImagesEXT( vk::Device device,
                                             const vk::ReleaseSwapchainImagesInfoEXT& releaseInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.releaseSwapchainImagesEXT( releaseInfo );
#else
    return s_MockPtr->_ReleaseSwapchainImagesEXT( device, releaseInfo );
#endif
}

static void GetGeneratedCommandsMemoryRequirementsNV( vk::Device device,
                                                      const vk::GeneratedCommandsMemoryRequirementsInfoNV* pInfo,
                                                      vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getGeneratedCommandsMemoryRequirementsNV( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetGeneratedCommandsMemoryRequirementsNV( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2
GetGeneratedCommandsMemoryRequirementsNV( vk::Device device,
                                          const vk::GeneratedCommandsMemoryRequirementsInfoNV& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGeneratedCommandsMemoryRequirementsNV( info );
#else
    return s_MockPtr->_GetGeneratedCommandsMemoryRequirementsNV( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetGeneratedCommandsMemoryRequirementsNV( vk::Device device,
                                          const vk::GeneratedCommandsMemoryRequirementsInfoNV& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getGeneratedCommandsMemoryRequirementsNV( info );
#else
    return s_MockPtr->_GetGeneratedCommandsMemoryRequirementsNV( device, info );
#endif
}

static vk::Result CreateIndirectCommandsLayoutNV( vk::Device device,
                                                  const vk::IndirectCommandsLayoutCreateInfoNV* pCreateInfo,
                                                  const vk::AllocationCallbacks* pAllocator,
                                                  vk::IndirectCommandsLayoutNV* pIndirectCommandsLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createIndirectCommandsLayoutNV( pCreateInfo, pAllocator, pIndirectCommandsLayout );
#else
    return s_MockPtr->_CreateIndirectCommandsLayoutNV( device, pCreateInfo, pAllocator, pIndirectCommandsLayout );
#endif
}

static ResultValue<vk::Result, vk::IndirectCommandsLayoutNV>
CreateIndirectCommandsLayoutNV( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createIndirectCommandsLayoutNV( createInfo, nullptr );
#else
    return s_MockPtr->_CreateIndirectCommandsLayoutNV( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::IndirectCommandsLayoutNV, Dispatch>>
CreateIndirectCommandsLayoutNVUnique( vk::Device device, const vk::IndirectCommandsLayoutCreateInfoNV& createInfo,
                                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createIndirectCommandsLayoutNVUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateIndirectCommandsLayoutNVUnique( device, createInfo, nullptr );
#endif
}

static void DestroyIndirectCommandsLayoutNV( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                                             const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyIndirectCommandsLayoutNV( indirectCommandsLayout, pAllocator );
#else
    s_MockPtr->_DestroyIndirectCommandsLayoutNV( device, indirectCommandsLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( indirectCommandsLayout, pAllocator );
#else
    s_MockPtr->_Destroy( device, indirectCommandsLayout, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::IndirectCommandsLayoutNV indirectCommandsLayout,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( indirectCommandsLayout, nullptr );
#else
    s_MockPtr->_Destroy( device, indirectCommandsLayout, nullptr );
#endif
}

static vk::Result CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo* pCreateInfo,
                                            const vk::AllocationCallbacks* pAllocator,
                                            vk::PrivateDataSlot* pPrivateDataSlot ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlotEXT( pCreateInfo, pAllocator, pPrivateDataSlot );
#else
    return s_MockPtr->_CreatePrivateDataSlotEXT( device, pCreateInfo, pAllocator, pPrivateDataSlot );
#endif
}

static ResultValue<vk::Result, vk::PrivateDataSlot>
CreatePrivateDataSlotEXT( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                          Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlotEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePrivateDataSlotEXT( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::PrivateDataSlot, Dispatch>>
CreatePrivateDataSlotEXTUnique( vk::Device device, const vk::PrivateDataSlotCreateInfo& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createPrivateDataSlotEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreatePrivateDataSlotEXTUnique( device, createInfo, nullptr );
#endif
}

static void DestroyPrivateDataSlotEXT( vk::Device device, vk::PrivateDataSlot privateDataSlot,
                                       const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyPrivateDataSlotEXT( privateDataSlot, pAllocator );
#else
    s_MockPtr->_DestroyPrivateDataSlotEXT( device, privateDataSlot, pAllocator );
#endif
}

static vk::Result SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                     vk::PrivateDataSlot privateDataSlot, uint64_t data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setPrivateDataEXT( objectType_, objectHandle, privateDataSlot, data );
#else
    return s_MockPtr->_SetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot, data );
#endif
}

static vk::Result SetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                     vk::PrivateDataSlot privateDataSlot, uint64_t data ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.setPrivateDataEXT( objectType_, objectHandle, privateDataSlot, data );
#else
    return s_MockPtr->_SetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot, data );
#endif
}

static void GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                               vk::PrivateDataSlot privateDataSlot, uint64_t* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getPrivateDataEXT( objectType_, objectHandle, privateDataSlot, pData );
#else
    s_MockPtr->_GetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot, pData );
#endif
}

static uint64_t GetPrivateDataEXT( vk::Device device, vk::ObjectType objectType_, uint64_t objectHandle,
                                   vk::PrivateDataSlot privateDataSlot ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPrivateDataEXT( objectType_, objectHandle, privateDataSlot );
#else
    return s_MockPtr->_GetPrivateDataEXT( device, objectType_, objectHandle, privateDataSlot );
#endif
}

static void GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                           vk::DeviceSize* pLayoutSizeInBytes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetLayoutSizeEXT( layout, pLayoutSizeInBytes );
#else
    s_MockPtr->_GetDescriptorSetLayoutSizeEXT( device, layout, pLayoutSizeInBytes );
#endif
}

static vk::DeviceSize GetDescriptorSetLayoutSizeEXT( vk::Device device, vk::DescriptorSetLayout layout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutSizeEXT( layout );
#else
    return s_MockPtr->_GetDescriptorSetLayoutSizeEXT( device, layout );
#endif
}

static void GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout, uint32_t binding,
                                                    vk::DeviceSize* pOffset ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetLayoutBindingOffsetEXT( layout, binding, pOffset );
#else
    s_MockPtr->_GetDescriptorSetLayoutBindingOffsetEXT( device, layout, binding, pOffset );
#endif
}

static vk::DeviceSize GetDescriptorSetLayoutBindingOffsetEXT( vk::Device device, vk::DescriptorSetLayout layout,
                                                              uint32_t binding ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutBindingOffsetEXT( layout, binding );
#else
    return s_MockPtr->_GetDescriptorSetLayoutBindingOffsetEXT( device, layout, binding );
#endif
}

static void GetDescriptorEXT( vk::Device device, const vk::DescriptorGetInfoEXT* pDescriptorInfo, size_t dataSize,
                              void* pDescriptor ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorEXT( pDescriptorInfo, dataSize, pDescriptor );
#else
    s_MockPtr->_GetDescriptorEXT( device, pDescriptorInfo, dataSize, pDescriptor );
#endif
}

template <typename DescriptorType>
static DescriptorType GetDescriptorEXT( vk::Device device, const vk::DescriptorGetInfoEXT& descriptorInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorEXT( descriptorInfo );
#else
    return s_MockPtr->_GetDescriptorEXT( device, descriptorInfo );
#endif
}

static vk::Result GetBufferOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                                           const vk::BufferCaptureDescriptorDataInfoEXT* pInfo,
                                                           void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureDescriptorDataEXT( pInfo, pData );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetBufferOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::BufferCaptureDescriptorDataInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferOpaqueCaptureDescriptorDataEXT( info );
#else
    return s_MockPtr->_GetBufferOpaqueCaptureDescriptorDataEXT( device, info );
#endif
}

static vk::Result GetImageOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                                          const vk::ImageCaptureDescriptorDataInfoEXT* pInfo,
                                                          void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageOpaqueCaptureDescriptorDataEXT( pInfo, pData );
#else
    return s_MockPtr->_GetImageOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetImageOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::ImageCaptureDescriptorDataInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageOpaqueCaptureDescriptorDataEXT( info );
#else
    return s_MockPtr->_GetImageOpaqueCaptureDescriptorDataEXT( device, info );
#endif
}

static vk::Result GetImageViewOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                                              const vk::ImageViewCaptureDescriptorDataInfoEXT* pInfo,
                                                              f void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewOpaqueCaptureDescriptorDataEXT( pInfo, pData );
#else
    return s_MockPtr->_GetImageViewOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetImageViewOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                            const vk::ImageViewCaptureDescriptorDataInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageViewOpaqueCaptureDescriptorDataEXT( info );
#else
    return s_MockPtr->_GetImageViewOpaqueCaptureDescriptorDataEXT( device, info );
#endif
}

static vk::Result GetSamplerOpaqueCaptureDescriptorDataEXT( vk::Device device,
                                                            const vk::SamplerCaptureDescriptorDataInfoEXT* pInfo,
                                                            void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSamplerOpaqueCaptureDescriptorDataEXT( pInfo, pData );
#else
    return s_MockPtr->_GetSamplerOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
GetSamplerOpaqueCaptureDescriptorDataEXT( vk::Device device, const vk::SamplerCaptureDescriptorDataInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSamplerOpaqueCaptureDescriptorDataEXT( info );
#else
    return s_MockPtr->_GetSamplerOpaqueCaptureDescriptorDataEXT( device, info );
#endif
}

static vk::Result GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
        vk::Device device, const vk::AccelerationStructureCaptureDescriptorDataInfoEXT* pInfo, void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureOpaqueCaptureDescriptorDataEXT( pInfo, pData );
#else
    return s_MockPtr->_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT( device, pInfo, pData );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType> GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
        vk::Device device, const vk::AccelerationStructureCaptureDescriptorDataInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getAccelerationStructureOpaqueCaptureDescriptorDataEXT( info );
#else
    return s_MockPtr->_GetAccelerationStructureOpaqueCaptureDescriptorDataEXT( device, info );
#endif
}

static vk::Result GetFaultInfoEXT( vk::Device device, vk::DeviceFaultCountsEXT* pFaultCounts,
                                   vk::DeviceFaultInfoEXT* pFaultInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFaultInfoEXT( pFaultCounts, pFaultInfo );
#else
    return s_MockPtr->_GetFaultInfoEXT( device, pFaultCounts, pFaultInfo );
#endif
}

static ResultValue<std::pair<vk::DeviceFaultCountsEXT, vk::DeviceFaultInfoEXT>>
GetFaultInfoEXT( vk::Device device, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFaultInfoEXT();
#else
    return s_MockPtr->_GetFaultInfoEXT();
#endif
}

static vk::Result GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device, vk::RenderPass renderpass,
                                                           vk::Extent2D* pMaxWorkgroupSize ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSubpassShadingMaxWorkgroupSizeHUAWEI( renderpass, pMaxWorkgroupSize );
#else
    return s_MockPtr->_GetSubpassShadingMaxWorkgroupSizeHUAWEI( device, renderpass, pMaxWorkgroupSize );
#endif
}

static ResultValue<vk::Extent2D> GetSubpassShadingMaxWorkgroupSizeHUAWEI( vk::Device device,
                                                                          vk::RenderPass renderpass ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getSubpassShadingMaxWorkgroupSizeHUAWEI( renderpass );
#else
    return s_MockPtr->_GetSubpassShadingMaxWorkgroupSizeHUAWEI( device, renderpass );
#endif
}

static vk::Result GetMemoryRemoteAddressNV( vk::Device device,
                                            const vk::MemoryGetRemoteAddressInfoNV* pMemoryGetRemoteAddressInfo,
                                            vk::RemoteAddressNV* pAddress ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryRemoteAddressNV( pMemoryGetRemoteAddressInfo, pAddress );
#else
    return s_MockPtr->_GetMemoryRemoteAddressNV( device, pMemoryGetRemoteAddressInfo, pAddress );
#endif
}

static ResultValue<vk::Result, vk::RemoteAddressNV>
GetMemoryRemoteAddressNV( vk::Device device, const vk::MemoryGetRemoteAddressInfoNV& memoryGetRemoteAddressInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMemoryRemoteAddressNV( memoryGetRemoteAddressInfo );
#else
    return s_MockPtr->_GetMemoryRemoteAddressNV( device, memoryGetRemoteAddressInfo );
#endif
}

static vk::Result GetPipelinePropertiesEXT( vk::Device device, const vk::PipelineInfoEXT* pPipelineInfo,
                                            vk::BaseOutStructure* pPipelineProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelinePropertiesEXT( pPipelineInfo, pPipelineProperties );
#else
    return s_MockPtr->_GetPipelinePropertiesEXT( device, pPipelineInfo, pPipelineProperties );
#endif
}

static ResultValue<vk::Result, vk::BaseOutStructure>
GetPipelinePropertiesEXT( vk::Device device, const vk::PipelineInfoEXT& pipelineInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelinePropertiesEXT( pipelineInfo );
#else
    return s_MockPtr->_GetPipelinePropertiesEXT( device, pipelineInfo );
#endif
}

static vk::Result CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT* pCreateInfo,
                                     const vk::AllocationCallbacks* pAllocator, vk::MicromapEXT* pMicromap ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createMicromapEXT( pCreateInfo, pAllocator, pMicromap );
#else
    return s_MockPtr->_CreateMicromapEXT( device, pCreateInfo, pAllocator, pMicromap );
#endif
}

static ResultValue<vk::Result, vk::MicromapEXT>
CreateMicromapEXT( vk::Device device, const vk::MicromapCreateInfoEXT& createInfo,
                   Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createMicromapEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateMicromapEXT( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::MicromapEXT, Dispatch>>
CreateMicromapEXTUnique( vk::Device device, const vk::MicromapCreateInfoEXT& createInfo,
                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createMicromapEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateMicromapEXTUnique( device, createInfo, nullptr );
#endif
}

static void DestroyMicromapEXT( vk::Device device, vk::MicromapEXT micromap,
                                const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyMicromapEXT( micromap, pAllocator );
#else
    s_MockPtr->_DestroyMicromapEXT( device, micromap, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::MicromapEXT micromap, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( micromap, pAllocator );
#else
    s_MockPtr->_Destroy( device, micromap, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::MicromapEXT micromap,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( micromap, nullptr );
#else
    s_MockPtr->_Destroy( device, micromap, nullptr );
#endif
}

static vk::Result BuildMicromapsEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation, uint32_t infoCount,
                                     const vk::MicromapBuildInfoEXT* pInfos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.buildMicromapsEXT( deferredOperation, infoCount, pInfos );
#else
    return s_MockPtr->_BuildMicromapsEXT( device, deferredOperation, infoCount, pInfos );
#endif
}

static vk::Result BuildMicromapsEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                     vk::ArrayProxy<const vk::MicromapBuildInfoEXT> const& infos ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.buildMicromapsEXT( deferredOperation, infos );
#else
    return s_MockPtr->_BuildMicromapsEXT( device, deferredOperation, infos );
#endif
}

static vk::Result CopyMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                   const vk::CopyMicromapInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMicromapEXT( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyMicromapEXT( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                   const vk::CopyMicromapInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMicromapEXT( deferredOperation, info );
#else
    return s_MockPtr->_CopyMicromapEXT( device, deferredOperation, info );
#endif
}

static vk::Result CopyMicromapToMemoryEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                           const vk::CopyMicromapToMemoryInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMicromapToMemoryEXT( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyMicromapToMemoryEXT( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyMicromapToMemoryEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                           const vk::CopyMicromapToMemoryInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMicromapToMemoryEXT( deferredOperation, info );
#else
    return s_MockPtr->_CopyMicromapToMemoryEXT( device, deferredOperation, info );
#endif
}

static vk::Result CopyMemoryToMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                           const vk::CopyMemoryToMicromapInfoEXT* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToMicromapEXT( deferredOperation, pInfo );
#else
    return s_MockPtr->_CopyMemoryToMicromapEXT( device, deferredOperation, pInfo );
#endif
}

static vk::Result CopyMemoryToMicromapEXT( vk::Device device, vk::DeferredOperationKHR deferredOperation,
                                           const vk::CopyMemoryToMicromapInfoEXT& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.copyMemoryToMicromapEXT( deferredOperation, info );
#else
    return s_MockPtr->_CopyMemoryToMicromapEXT( device, deferredOperation, info );
#endif
}

static vk::Result WriteMicromapsPropertiesEXT( vk::Device device, uint32_t micromapCount,
                                               const vk::MicromapEXT* pMicromaps, vk::QueryType queryType,
                                               size_t dataSize, void* pData, size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeMicromapsPropertiesEXT( micromapCount, pMicromaps, queryType, dataSize, pData, stride );
#else
    return s_MockPtr->_WriteMicromapsPropertiesEXT( device, micromapCount, pMicromaps, queryType, dataSize, pData,
                                                    stride );
#endif
}

template <typename DataType, typename DataTypeAllocator = std::allocator<DataType>>
static ResultValue<vk::Result, std::vector<DataType, DataTypeAllocator>>
WriteMicromapsPropertiesEXT( vk::Device device, vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                             vk::QueryType queryType, size_t dataSize, size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeMicromapsPropertiesEXT( micromaps, queryType, dataSize, stride );
#else
    return s_MockPtr->_WriteMicromapsPropertiesEXT( device, micromaps, queryType, dataSize, stride );
#endif
}

template <typename DataType>
static ResultValue<vk::Result, DataType>
WriteMicromapsPropertyEXT( vk::Device device, vk::ArrayProxy<const vk::MicromapEXT> const& micromaps,
                           vk::QueryType queryType, size_t stride ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.writeMicromapsPropertyEXT( micromaps, queryType, stride );
#else
    return s_MockPtr->_WriteMicromapsPropertyEXT( device, micromaps, queryType, stride );
#endif
}

static void GetMicromapCompatibilityEXT( vk::Device device, const vk::MicromapVersionInfoEXT* pVersionInfo,
                                         vk::AccelerationStructureCompatibilityKHR* pCompatibility ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getMicromapCompatibilityEXT( pVersionInfo, pCompatibility );
#else
    s_MockPtr->_GetMicromapCompatibilityEXT( device, pVersionInfo, pCompatibility );
#endif
}

static vk::AccelerationStructureCompatibilityKHR
GetMicromapCompatibilityEXT( vk::Device device, const vk::MicromapVersionInfoEXT& versionInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMicromapCompatibilityEXT( versionInfo );
#else
    return s_MockPtr->_GetMicromapCompatibilityEXT( device, versionInfo );
#endif
}

static void GetMicromapBuildSizesEXT( vk::Device device, vk::AccelerationStructureBuildTypeKHR buildType,
                                      const vk::MicromapBuildInfoEXT* pBuildInfo,
                                      vk::MicromapBuildSizesInfoEXT* pSizeInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getMicromapBuildSizesEXT( buildType, pBuildInfo, pSizeInfo );
#else
    s_MockPtr->_GetMicromapBuildSizesEXT( device, buildType, pBuildInfo, pSizeInfo );
#endif
}

static vk::MicromapBuildSizesInfoEXT GetMicromapBuildSizesEXT( vk::Device device,
                                                               vk::AccelerationStructureBuildTypeKHR buildType,
                                                               const vk::MicromapBuildInfoEXT& buildInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getMicromapBuildSizesEXT( buildType, buildInfo );
#else
    return s_MockPtr->_GetMicromapBuildSizesEXT( device, buildType, buildInfo );
#endif
}

static void SetMemoryPriorityEXT( vk::Device device, vk::DeviceMemory memory, float priority ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.setMemoryPriorityEXT( memory, priority );
#else
    s_MockPtr->_SetMemoryPriorityEXT( device, memory, priority );
#endif
}

static void GetBufferMemoryRequirementsKHR( vk::Device device, const vk::DeviceBufferMemoryRequirements* pInfo,
                                            vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getBufferMemoryRequirementsKHR( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetBufferMemoryRequirementsKHR( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetBufferMemoryRequirementsKHR( vk::Device device,
                                                               const vk::DeviceBufferMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirementsKHR( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirementsKHR( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetBufferMemoryRequirementsKHR( vk::Device device, const vk::DeviceBufferMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getBufferMemoryRequirementsKHR( info );
#else
    return s_MockPtr->_GetBufferMemoryRequirementsKHR( device, info );
#endif
}

static void GetImageMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                           vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageMemoryRequirementsKHR( pInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetImageMemoryRequirementsKHR( device, pInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2 GetImageMemoryRequirementsKHR( vk::Device device,
                                                              const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirementsKHR( info );
#else
    return s_MockPtr->_GetImageMemoryRequirementsKHR( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetImageMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageMemoryRequirementsKHR( info );
#else
    return s_MockPtr->_GetImageMemoryRequirementsKHR( device, info );
#endif
}

static void GetImageSparseMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements* pInfo,
                                                 uint32_t* pSparseMemoryRequirementCount,
                                                 vk::SparseImageMemoryRequirements2* pSparseMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSparseMemoryRequirementsKHR( pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements );
#else
    s_MockPtr->_GetImageSparseMemoryRequirementsKHR( device, pInfo, pSparseMemoryRequirementCount,
                                                     pSparseMemoryRequirements );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirementsKHR( vk::Device device, const vk::DeviceImageMemoryRequirements& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirementsKHR( info );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirementsKHR( device, info );
#endif
}

template <typename SparseImageMemoryRequirements2Allocator = std::allocator<vk::SparseImageMemoryRequirements2>,
          typename B1 = SparseImageMemoryRequirements2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageMemoryRequirements2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageMemoryRequirements2, SparseImageMemoryRequirements2Allocator>
GetImageSparseMemoryRequirementsKHR(
        vk::Device device, const vk::DeviceImageMemoryRequirements& info,
        SparseImageMemoryRequirements2Allocator& sparseImageMemoryRequirements2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSparseMemoryRequirementsKHR( info, sparseImageMemoryRequirements2Allocator );
#else
    return s_MockPtr->_GetImageSparseMemoryRequirementsKHR( device, info, sparseImageMemoryRequirements2Allocator );
#endif
}

static void
GetDescriptorSetLayoutHostMappingInfoVALVE( vk::Device device,
                                            const vk::DescriptorSetBindingReferenceVALVE* pBindingReference,
                                            vk::DescriptorSetLayoutHostMappingInfoVALVE* pHostMapping ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetLayoutHostMappingInfoVALVE( pBindingReference, pHostMapping );
#else
    s_MockPtr->_GetDescriptorSetLayoutHostMappingInfoVALVE( device, pBindingReference, pHostMapping );
#endif
}

static vk::DescriptorSetLayoutHostMappingInfoVALVE
GetDescriptorSetLayoutHostMappingInfoVALVE( vk::Device device,
                                            const vk::DescriptorSetBindingReferenceVALVE& bindingReference ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDescriptorSetLayoutHostMappingInfoVALVE( bindingReference );
#else
    return s_MockPtr->_GetDescriptorSetLayoutHostMappingInfoVALVE( device, bindingReference );
#endif
}

static void GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet, void** ppData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetHostMappingVALVE( descriptorSet, ppData );
#else
    s_MockPtr->_GetDescriptorSetHostMappingVALVE( device, descriptorSet, ppData );
#endif
}

static void* GetDescriptorSetHostMappingVALVE( vk::Device device, vk::DescriptorSet descriptorSet ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getDescriptorSetHostMappingVALVE( descriptorSet );
#else
    s_MockPtr->_GetDescriptorSetHostMappingVALVE( device, descriptorSet );
#endif
}

static void GetPipelineIndirectMemoryRequirementsNV( vk::Device device,
                                                     const vk::ComputePipelineCreateInfo* pCreateInfo,
                                                     vk::MemoryRequirements2* pMemoryRequirements ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getPipelineIndirectMemoryRequirementsNV( pCreateInfo, pMemoryRequirements );
#else
    s_MockPtr->_GetPipelineIndirectMemoryRequirementsNV( device, pCreateInfo, pMemoryRequirements );
#endif
}

static vk::MemoryRequirements2
GetPipelineIndirectMemoryRequirementsNV( vk::Device device, const vk::ComputePipelineCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineIndirectMemoryRequirementsNV( createInfo );
#else
    return s_MockPtr->_GetPipelineIndirectMemoryRequirementsNV( device, createInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetPipelineIndirectMemoryRequirementsNV( vk::Device device, const vk::ComputePipelineCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineIndirectMemoryRequirementsNV( createInfo );
#else
    return s_MockPtr->_GetPipelineIndirectMemoryRequirementsNV( device, createInfo );
#endif
}

static DeviceAddress GetPipelineIndirectAddressNV( vk::Device device,
                                                   const vk::PipelineIndirectDeviceAddressInfoNV* pInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineIndirectAddressNV( pInfo );
#else
    return s_MockPtr->_GetPipelineIndirectAddressNV( device, pInfo );
#endif
}

static vk::DeviceAddress GetPipelineIndirectAddressNV( vk::Device device,
                                                       const vk::PipelineIndirectDeviceAddressInfoNV& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getPipelineIndirectAddressNV( info );
#else
    return s_MockPtr->_GetPipelineIndirectAddressNV( device, info );
#endif
}

static void GetShaderModuleIdentifierEXT( vk::Device device, vk::ShaderModule shaderModule,
                                          vk::ShaderModuleIdentifierEXT* pIdentifier ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getShaderModuleIdentifierEXT( shaderModule, pIdentifier );
#else
    s_MockPtr->_GetShaderModuleIdentifierEXT( device, shaderModule, pIdentifier );
#endif
}

static vk::ShaderModuleIdentifierEXT GetShaderModuleIdentifierEXT( vk::Device device,
                                                                   vk::ShaderModule shaderModule ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderModuleIdentifierEXT( shaderModule );
#else
    return s_MockPtr->_GetShaderModuleIdentifierEXT( device, shaderModule );
#endif
}

static void GetShaderModuleCreateInfoIdentifierEXT( vk::Device device, const vk::ShaderModuleCreateInfo* pCreateInfo,
                                                    vk::ShaderModuleIdentifierEXT* pIdentifier ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getShaderModuleCreateInfoIdentifierEXT( pCreateInfo, pIdentifier );
#else
    s_MockPtr->_GetShaderModuleCreateInfoIdentifierEXT( device, pCreateInfo, pIdentifier );
#endif
}

static vk::ShaderModuleIdentifierEXT
GetShaderModuleCreateInfoIdentifierEXT( vk::Device device, const vk::ShaderModuleCreateInfo& createInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderModuleCreateInfoIdentifierEXT( createInfo );
#else
    return s_MockPtr->_GetShaderModuleCreateInfoIdentifierEXT( device, createInfo );
#endif
}

static vk::Result CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV* pCreateInfo,
                                              const vk::AllocationCallbacks* pAllocator,
                                              vk::OpticalFlowSessionNV* pSession ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createOpticalFlowSessionNV( pCreateInfo, pAllocator, pSession );
#else
    return s_MockPtr->_CreateOpticalFlowSessionNV( device, pCreateInfo, pAllocator, pSession );
#endif
}

static ResultValue<vk::Result, vk::OpticalFlowSessionNV>
CreateOpticalFlowSessionNV( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV& createInfo,
                            Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createOpticalFlowSessionNV( createInfo, nullptr );
#else
    return s_MockPtr->_CreateOpticalFlowSessionNV( device, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::OpticalFlowSessionNV, Dispatch>>
CreateOpticalFlowSessionNVUnique( vk::Device device, const vk::OpticalFlowSessionCreateInfoNV& createInfo,
                                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createOpticalFlowSessionNVUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateOpticalFlowSessionNVUnique( device, createInfo, nullptr );
#endif
}

static void DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                         const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyOpticalFlowSessionNV( session, pAllocator );
#else
    s_MockPtr->_DestroyOpticalFlowSessionNV( device, session, pAllocator );
#endif
}

static void DestroyOpticalFlowSessionNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                         Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyOpticalFlowSessionNV( session, nullptr );
#else
    s_MockPtr->_DestroyOpticalFlowSessionNV( device, session, nullptr );
#endif
}

static void Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( session, pAllocator );
#else
    s_MockPtr->_Destroy( device, session, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::OpticalFlowSessionNV session,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( session, nullptr );
#else
    s_MockPtr->_Destroy( device, session, nullptr );
#endif
}

static vk::Result BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                 vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view,
                                                 vk::ImageLayout layout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindOpticalFlowSessionImageNV( session, bindingPoint, view, layout );
#else
    return s_MockPtr->_BindOpticalFlowSessionImageNV( device, session, bindingPoint, view, layout );
#endif
}

static vk::Result BindOpticalFlowSessionImageNV( vk::Device device, vk::OpticalFlowSessionNV session,
                                                 vk::OpticalFlowSessionBindingPointNV bindingPoint, vk::ImageView view,
                                                 vk::ImageLayout layout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.bindOpticalFlowSessionImageNV( session, bindingPoint, view, layout );
#else
    return s_MockPtr->_BindOpticalFlowSessionImageNV( device, session, bindingPoint, view, layout );
#endif
}

static void GetRenderingAreaGranularityKHR( vk::Device device, const vk::RenderingAreaInfoKHR* pRenderingAreaInfo,
                                            vk::Extent2D* pGranularity ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getRenderingAreaGranularityKHR( pRenderingAreaInfo, pGranularity );
#else
    s_MockPtr->_GetRenderingAreaGranularityKHR( device, pRenderingAreaInfo, pGranularity );
#endif
}

static vk::Extent2D GetRenderingAreaGranularityKHR( vk::Device device,
                                                    const vk::RenderingAreaInfoKHR& renderingAreaInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getRenderingAreaGranularityKHR( renderingAreaInfo );
#else
    return s_MockPtr->_GetRenderingAreaGranularityKHR( device, renderingAreaInfo );
#endif
}

static void GetImageSubresourceLayoutKHR( vk::Device device, const vk::DeviceImageSubresourceInfoKHR* pInfo,
                                          vk::SubresourceLayout2KHR* pLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSubresourceLayoutKHR( pInfo, pLayout );
#else
    s_MockPtr->_GetImageSubresourceLayoutKHR( device, pInfo, pLayout );
#endif
}

static vk::SubresourceLayout2KHR GetImageSubresourceLayoutKHR( vk::Device device,
                                                               const vk::DeviceImageSubresourceInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayoutKHR( info );
#else
    return s_MockPtr->_GetImageSubresourceLayoutKHR( device, info );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...>
GetImageSubresourceLayoutKHR( vk::Device device, const vk::DeviceImageSubresourceInfoKHR& info ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayoutKHR( info );
#else
    return s_MockPtr->_GetImageSubresourceLayoutKHR( device, info );
#endif
}

static void GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image,
                                           const vk::ImageSubresource2KHR* pSubresource,
                                           vk::SubresourceLayout2KHR* pLayout ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.getImageSubresourceLayout2KHR( image, pSubresource, pLayout );
#else
    s_MockPtr->_GetImageSubresourceLayout2KHR( device, image, pSubresource, pLayout );
#endif
}

static vk::SubresourceLayout2KHR GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image,
                                                                const vk::ImageSubresource2KHR& subresource ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayout2KHR( image, subresource );
#else
    return s_MockPtr->_GetImageSubresourceLayout2KHR( device, image, subresource );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetImageSubresourceLayout2KHR( vk::Device device, vk::Image image,
                                                                     const vk::ImageSubresource2KHR& subresource ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getImageSubresourceLayout2KHR( image, subresource );
#else
    return s_MockPtr->_GetImageSubresourceLayout2KHR( device, image, subresource );
#endif
}

static vk::Result CreateShadersEXT( vk::Device device, uint32_t createInfoCount,
                                    const vk::ShaderCreateInfoEXT* pCreateInfos,
                                    const vk::AllocationCallbacks* pAllocator, vk::ShaderEXT* pShaders ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShadersEXT( createInfoCount, pCreateInfos, pAllocator, pShaders );
#else
    return s_MockPtr->_CreateShadersEXT( device, createInfoCount, pCreateInfos, pAllocator, pShaders );
#endif
}

template <typename ShaderEXTAllocator = std::allocator<vk::ShaderEXT>>
static ResultValue<vk::Result, std::vector<vk::ShaderEXT, ShaderEXTAllocator>>
CreateShadersEXT( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                  Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShadersEXT( createInfos, nullptr );
#else
    return s_MockPtr->_CreateShadersEXT( device, createInfos, nullptr );
#endif
}

template <typename ShaderEXTAllocator = std::allocator<vk::ShaderEXT>, typename B0 = ShaderEXTAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, ShaderEXT>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::ShaderEXT, ShaderEXTAllocator>>
CreateShadersEXT( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                  Optional<const vk::AllocationCallbacks> allocator, ShaderEXTAllocator& shaderEXTAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShadersEXT( createInfos, allocator, shaderEXTAllocator );
#else
    return s_MockPtr->_CreateShadersEXT( device, createInfos, allocator, shaderEXTAllocator );
#endif
}

static ResultValue<vk::Result, vk::ShaderEXT>
CreateShaderEXT( vk::Device device, const vk::ShaderCreateInfoEXT& createInfo,
                 Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShaderEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateShaderEXT( device, createInfo, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename ShaderEXTAllocator = std::allocator<UniqueHandle<vk::ShaderEXT, Dispatch>>>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::ShaderEXT, Dispatch>, ShaderEXTAllocator>>
CreateShadersEXTUnique( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                        Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShadersEXTUnique( createInfos, nullptr );
#else
    return s_MockPtr->_CreateShadersEXTUnique( device, createInfos, nullptr );
#endif
}

template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE,
          typename ShaderEXTAllocator = std::allocator<UniqueHandle<vk::ShaderEXT, Dispatch>>,
          typename B0 = ShaderEXTAllocator,
          typename std::enable_if<std::is_same<typename B0::value_type, UniqueHandle<ShaderEXT, Dispatch>>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<UniqueHandle<vk::ShaderEXT, Dispatch>, ShaderEXTAllocator>>
CreateShadersEXTUnique( vk::Device device, vk::ArrayProxy<const vk::ShaderCreateInfoEXT> const& createInfos,
                        Optional<const vk::AllocationCallbacks> allocator,
                        ShaderEXTAllocator& shaderEXTAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShadersEXTUnique( createInfos, allocator, shaderEXTAllocator );
#else
    return s_MockPtr->_CreateShadersEXTUnique( device, createInfos, allocator, shaderEXTAllocator );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::ShaderEXT, Dispatch>>
CreateShaderEXTUnique( vk::Device device, const vk::ShaderCreateInfoEXT& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.createShaderEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateShaderEXTUnique( device, createInfo, nullptr );
#endif
}

static void DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyShaderEXT( shader, pAllocator );
#else
    s_MockPtr->_DestroyShaderEXT( device, shader, pAllocator );
#endif
}

static void DestroyShaderEXT( vk::Device device, vk::ShaderEXT shader,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroyShaderEXT( shader, nullptr );
#else
    s_MockPtr->_DestroyShaderEXT( device, shader, nullptr );
#endif
}

static void Destroy( vk::Device device, vk::ShaderEXT shader, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( shader, pAllocator );
#else
    s_MockPtr->_Destroy( device, shader, pAllocator );
#endif
}

static void Destroy( vk::Device device, vk::ShaderEXT shader,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    device.destroy( shader, nullptr );
#else
    s_MockPtr->_Destroy( device, shader, nullptr );
#endif
}

static vk::Result GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader, size_t* pDataSize,
                                          void* pData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderBinaryDataEXT( shader, pDataSize, pData );
#else
    return s_MockPtr->_GetShaderBinaryDataEXT( device, shader, pDataSize, pData );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderBinaryDataEXT( shader );
#else
    return s_MockPtr->_GetShaderBinaryDataEXT( device, shader );
#endif
}

template <typename Uint8_tAllocator = std::allocator<uint8_t>, typename B1 = Uint8_tAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, uint8_t>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<uint8_t, Uint8_tAllocator>>
GetShaderBinaryDataEXT( vk::Device device, vk::ShaderEXT shader, Uint8_tAllocator& uint8_tAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getShaderBinaryDataEXT( shader, uint8_tAllocator );
#else
    return s_MockPtr->_GetShaderBinaryDataEXT( device, shader, uint8_tAllocator );
#endif
}

static vk::Result GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer,
                                                    uint32_t* pPropertiesCount,
                                                    vk::TilePropertiesQCOM* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFramebufferTilePropertiesQCOM( framebuffer, pPropertiesCount, pProperties );
#else
    return s_MockPtr->_GetFramebufferTilePropertiesQCOM( device, framebuffer, pPropertiesCount, pProperties );
#endif
}

template <typename TilePropertiesQCOMAllocator = std::allocator<vk::TilePropertiesQCOM>>
static ResultValue<vk::Result, std::vector<vk::TilePropertiesQCOM, TilePropertiesQCOMAllocator>>
GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFramebufferTilePropertiesQCOM( framebuffer );
#else
    return s_MockPtr->_GetFramebufferTilePropertiesQCOM( device, framebuffer );
#endif
}

template <typename TilePropertiesQCOMAllocator = std::allocator<vk::TilePropertiesQCOM>,
          typename B1 = TilePropertiesQCOMAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, TilePropertiesQCOM>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::TilePropertiesQCOM, TilePropertiesQCOMAllocator>>
GetFramebufferTilePropertiesQCOM( vk::Device device, vk::Framebuffer framebuffer,
                                  TilePropertiesQCOMAllocator& tilePropertiesQCOMAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getFramebufferTilePropertiesQCOM( framebuffer, tilePropertiesQCOMAllocator );
#else
    return s_MockPtr->_GetFramebufferTilePropertiesQCOM( device, framebuffer, tilePropertiesQCOMAllocator );
#endif
}

static vk::Result GetDynamicRenderingTilePropertiesQCOM( vk::Device device, const vk::RenderingInfo* pRenderingInfo,
                                                         vk::TilePropertiesQCOM* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDynamicRenderingTilePropertiesQCOM( pRenderingInfo, pProperties );
#else
    return s_MockPtr->_GetDynamicRenderingTilePropertiesQCOM( device, pRenderingInfo, pProperties );
#endif
}

static vk::TilePropertiesQCOM GetDynamicRenderingTilePropertiesQCOM( vk::Device device,
                                                                     const vk::RenderingInfo& renderingInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return device.getDynamicRenderingTilePropertiesQCOM( renderingInfo );
#else
    return s_MockPtr->_GetDynamicRenderingTilePropertiesQCOM( device, renderingInfo );
#endif
}

static void GetFeatures( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures* pFeatures ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFeatures( pFeatures );
#else
    s_MockPtr->_GetFeatures( physicalDevice, pFeatures );
#endif
}

static vk::PhysicalDeviceFeatures GetFeatures( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFeatures();
#else
    return s_MockPtr->_GetFeatures();
#endif
}

static void GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format,
                                 vk::FormatProperties* pFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFormatProperties( format, pFormatProperties );
#else
    s_MockPtr->_GetFormatProperties( physicalDevice, format, pFormatProperties );
#endif
}

static vk::FormatProperties GetFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFormatProperties( format );
#else
    return s_MockPtr->_GetFormatProperties( physicalDevice, format );
#endif
}

static vk::Result GetImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                            vk::ImageTiling tiling, vk::ImageUsageFlags usage,
                                            vk::ImageCreateFlags flags,
                                            vk::ImageFormatProperties* pImageFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties( format, type, tiling, usage, flags, pImageFormatProperties );
#else
    return s_MockPtr->_GetImageFormatProperties( physicalDevice, format, type, tiling, usage, flags,
                                                 pImageFormatProperties );
#endif
}

static void GetProperties( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getProperties( pProperties );
#else
    s_MockPtr->_GetProperties( physicalDevice, pProperties );
#endif
}

static vk::PhysicalDeviceProperties GetProperties( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getProperties();
#else
    return s_MockPtr->_GetProperties();
#endif
}

static void GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                      vk::QueueFamilyProperties* pQueueFamilyProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getQueueFamilyProperties( pQueueFamilyPropertyCount, pQueueFamilyProperties );
#else
    s_MockPtr->_GetQueueFamilyProperties( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
#endif
}

template <typename QueueFamilyPropertiesAllocator = std::allocator<vk::QueueFamilyProperties>>
static std::vector<vk::QueueFamilyProperties, QueueFamilyPropertiesAllocator>
GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties();
#else
    return s_MockPtr->_GetQueueFamilyProperties();
#endif
}

template <typename QueueFamilyPropertiesAllocator = std::allocator<vk::QueueFamilyProperties>,
          typename B1 = QueueFamilyPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, QueueFamilyProperties>::value, int>::type = 0>
static std::vector<vk::QueueFamilyProperties, QueueFamilyPropertiesAllocator>
GetQueueFamilyProperties( vk::PhysicalDevice physicalDevice,
                          QueueFamilyPropertiesAllocator& queueFamilyPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties( queueFamilyPropertiesAllocator );
#else
    return s_MockPtr->_GetQueueFamilyProperties( physicalDevice, queueFamilyPropertiesAllocator );
#endif
}

static void GetMemoryProperties( vk::PhysicalDevice physicalDevice,
                                 vk::PhysicalDeviceMemoryProperties* pMemoryProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getMemoryProperties( pMemoryProperties );
#else
    s_MockPtr->_GetMemoryProperties( physicalDevice, pMemoryProperties );
#endif
}

static vk::PhysicalDeviceMemoryProperties GetMemoryProperties( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMemoryProperties();
#else
    return s_MockPtr->_GetMemoryProperties();
#endif
}

static vk::Result CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo* pCreateInfo,
                                const vk::AllocationCallbacks* pAllocator, vk::Device* pDevice ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDevice( pCreateInfo, pAllocator, pDevice );
#else
    return s_MockPtr->_CreateDevice( physicalDevice, pCreateInfo, pAllocator, pDevice );
#endif
}

static ResultValue<vk::Result, vk::Device>
CreateDevice( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo& createInfo,
              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDevice( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDevice( physicalDevice, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::Device, Dispatch>>
CreateDeviceUnique( vk::PhysicalDevice physicalDevice, const vk::DeviceCreateInfo& createInfo,
                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDeviceUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDeviceUnique( physicalDevice, createInfo, nullptr );
#endif
}

static vk::Result EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice, const char* pLayerName,
                                                      uint32_t* pPropertyCount,
                                                      vk::ExtensionProperties* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceExtensionProperties( pLayerName, pPropertyCount, pProperties );
#else
    return s_MockPtr->_EnumerateDeviceExtensionProperties( physicalDevice, pLayerName, pPropertyCount, pProperties );
#endif
}

template <typename ExtensionPropertiesAllocator = std::allocator<vk::ExtensionProperties>>
static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, ExtensionPropertiesAllocator>>
EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice,
                                    Optional<const std::string> layerName = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceExtensionProperties( nullptr );
#else
    return s_MockPtr->_EnumerateDeviceExtensionProperties( physicalDevice, nullptr );
#endif
}

template <typename ExtensionPropertiesAllocator = std::allocator<vk::ExtensionProperties>,
          typename B1 = ExtensionPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, ExtensionProperties>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, ExtensionPropertiesAllocator>>
EnumerateDeviceExtensionProperties( vk::PhysicalDevice physicalDevice, Optional<const std::string> layerName,
                                    ExtensionPropertiesAllocator& extensionPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceExtensionProperties( layerName, extensionPropertiesAllocator );
#else
    return s_MockPtr->_EnumerateDeviceExtensionProperties( physicalDevice, layerName, extensionPropertiesAllocator );
#endif
}

static vk::Result EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                  vk::LayerProperties* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceLayerProperties( pPropertyCount, pProperties );
#else
    return s_MockPtr->_EnumerateDeviceLayerProperties( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename LayerPropertiesAllocator = std::allocator<vk::LayerProperties>>
static ResultValue<vk::Result, std::vector<vk::LayerProperties, LayerPropertiesAllocator>>
EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceLayerProperties();
#else
    return s_MockPtr->_EnumerateDeviceLayerProperties();
#endif
}

template <typename LayerPropertiesAllocator = std::allocator<vk::LayerProperties>,
          typename B1 = LayerPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, LayerProperties>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::LayerProperties, LayerPropertiesAllocator>>
EnumerateDeviceLayerProperties( vk::PhysicalDevice physicalDevice,
                                LayerPropertiesAllocator& layerPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateDeviceLayerProperties( layerPropertiesAllocator );
#else
    return s_MockPtr->_EnumerateDeviceLayerProperties( physicalDevice, layerPropertiesAllocator );
#endif
}

static void GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                            vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage,
                                            vk::ImageTiling tiling, uint32_t* pPropertyCount,
                                            vk::SparseImageFormatProperties* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getSparseImageFormatProperties( format, type, samples, usage, tiling, pPropertyCount, pProperties );
#else
    s_MockPtr->_GetSparseImageFormatProperties( physicalDevice, format, type, samples, usage, tiling, pPropertyCount,
                                                pProperties );
#endif
}

template <typename SparseImageFormatPropertiesAllocator = std::allocator<vk::SparseImageFormatProperties>>
static std::vector<vk::SparseImageFormatProperties, SparseImageFormatPropertiesAllocator>
GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage,
                                vk::ImageTiling tiling ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties( format, type, samples, usage, tiling );
#else
    return s_MockPtr->_GetSparseImageFormatProperties( physicalDevice, format, type, samples, usage, tiling );
#endif
}

template <typename SparseImageFormatPropertiesAllocator = std::allocator<vk::SparseImageFormatProperties>,
          typename B1 = SparseImageFormatPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageFormatProperties>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageFormatProperties, SparseImageFormatPropertiesAllocator>
GetSparseImageFormatProperties( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                vk::SampleCountFlagBits samples, vk::ImageUsageFlags usage, vk::ImageTiling tiling,
                                SparseImageFormatPropertiesAllocator& sparseImageFormatPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties( format, type, samples, usage, tiling,
                                                          sparseImageFormatPropertiesAllocator );
#else
    return s_MockPtr->_GetSparseImageFormatProperties( physicalDevice, format, type, samples, usage, tiling,
                                                       sparseImageFormatPropertiesAllocator );
#endif
}

static void GetFeatures2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFeatures2( pFeatures );
#else
    s_MockPtr->_GetFeatures2( physicalDevice, pFeatures );
#endif
}

static vk::PhysicalDeviceFeatures2 GetFeatures2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFeatures2();
#else
    return s_MockPtr->_GetFeatures2();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetFeatures2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFeatures2();
#else
    return s_MockPtr->_GetFeatures2();
#endif
}

static void GetProperties2( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getProperties2( pProperties );
#else
    s_MockPtr->_GetProperties2( physicalDevice, pProperties );
#endif
}

static vk::PhysicalDeviceProperties2 GetProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getProperties2();
#else
    return s_MockPtr->_GetProperties2();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getProperties2();
#else
    return s_MockPtr->_GetProperties2();
#endif
}

static void GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format,
                                  vk::FormatProperties2* pFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFormatProperties2( format, pFormatProperties );
#else
    s_MockPtr->_GetFormatProperties2( physicalDevice, format, pFormatProperties );
#endif
}

static vk::FormatProperties2 GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFormatProperties2( format );
#else
    return s_MockPtr->_GetFormatProperties2( physicalDevice, format );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetFormatProperties2( vk::PhysicalDevice physicalDevice, vk::Format format ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFormatProperties2( format );
#else
    return s_MockPtr->_GetFormatProperties2( physicalDevice, format );
#endif
}

static vk::Result GetImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                             const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                             vk::ImageFormatProperties2* pImageFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2( pImageFormatInfo, pImageFormatProperties );
#else
    return s_MockPtr->_GetImageFormatProperties2( physicalDevice, pImageFormatInfo, pImageFormatProperties );
#endif
}

static ResultValue<vk::Result, vk::ImageFormatProperties2>
GetImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                           const vk::PhysicalDeviceImageFormatInfo2& imageFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2( imageFormatInfo );
#else
    return s_MockPtr->_GetImageFormatProperties2( physicalDevice, imageFormatInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static ResultValue<vk::Result, vk::StructureChain<X, Y, Z...>>
GetImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                           const vk::PhysicalDeviceImageFormatInfo2& imageFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2( imageFormatInfo );
#else
    return s_MockPtr->_GetImageFormatProperties2( physicalDevice, imageFormatInfo );
#endif
}

static void GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                       vk::QueueFamilyProperties2* pQueueFamilyProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getQueueFamilyProperties2( pQueueFamilyPropertyCount, pQueueFamilyProperties );
#else
    s_MockPtr->_GetQueueFamilyProperties2( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
#endif
}

template <typename QueueFamilyProperties2Allocator = std::allocator<vk::QueueFamilyProperties2>>
static std::vector<vk::QueueFamilyProperties2, QueueFamilyProperties2Allocator>
GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2();
#else
    return s_MockPtr->_GetQueueFamilyProperties2();
#endif
}

template <typename QueueFamilyProperties2Allocator = std::allocator<vk::QueueFamilyProperties2>,
          typename B1 = QueueFamilyProperties2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, QueueFamilyProperties2>::value, int>::type =
                  static std::vector<vk::QueueFamilyProperties2, QueueFamilyProperties2Allocator>
                          GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice,
                                                     QueueFamilyProperties2Allocator& queueFamilyProperties2Allocator )
                                  const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2( queueFamilyProperties2Allocator );
#else
    return s_MockPtr->_GetQueueFamilyProperties2( physicalDevice, queueFamilyProperties2Allocator );
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>>
static std::vector<StructureChain, StructureChainAllocator>
GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2();
#else
    return s_MockPtr->_GetQueueFamilyProperties2();
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>,
          typename B1 = StructureChainAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, StructureChain>::value, int>::type = 0>
static std::vector<StructureChain, StructureChainAllocator>
GetQueueFamilyProperties2( vk::PhysicalDevice physicalDevice, StructureChainAllocator& structureChainAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2( structureChainAllocator );
#else
    return s_MockPtr->_GetQueueFamilyProperties2( physicalDevice, structureChainAllocator );
#endif
}

static void GetMemoryProperties2( vk::PhysicalDevice physicalDevice,
                                  vk::PhysicalDeviceMemoryProperties2* pMemoryProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getMemoryProperties2( pMemoryProperties );
#else
    s_MockPtr->_GetMemoryProperties2( physicalDevice, pMemoryProperties );
#endif
}

static vk::PhysicalDeviceMemoryProperties2 GetMemoryProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMemoryProperties2();
#else
    return s_MockPtr->_GetMemoryProperties2();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetMemoryProperties2( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMemoryProperties2();
#else
    return s_MockPtr->_GetMemoryProperties2();
#endif
}

static void GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                             const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                             uint32_t* pPropertyCount,
                                             vk::SparseImageFormatProperties2* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getSparseImageFormatProperties2( pFormatInfo, pPropertyCount, pProperties );
#else
    s_MockPtr->_GetSparseImageFormatProperties2( physicalDevice, pFormatInfo, pPropertyCount, pProperties );
#endif
}

template <typename SparseImageFormatProperties2Allocator = std::allocator<vk::SparseImageFormatProperties2>>
static std::vector<vk::SparseImageFormatProperties2, SparseImageFormatProperties2Allocator>
GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                 const vk::PhysicalDeviceSparseImageFormatInfo2& formatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties2( formatInfo );
#else
    return s_MockPtr->_GetSparseImageFormatProperties2( physicalDevice, formatInfo );
#endif
}

template <typename SparseImageFormatProperties2Allocator = std::allocator<vk::SparseImageFormatProperties2>,
          typename B1 = SparseImageFormatProperties2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageFormatProperties2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageFormatProperties2, SparseImageFormatProperties2Allocator>
GetSparseImageFormatProperties2( vk::PhysicalDevice physicalDevice,
                                 const vk::PhysicalDeviceSparseImageFormatInfo2& formatInfo,
                                 SparseImageFormatProperties2Allocator& sparseImageFormatProperties2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties2( formatInfo, sparseImageFormatProperties2Allocator );
#else
    return s_MockPtr->_GetSparseImageFormatProperties2( physicalDevice, formatInfo,
                                                        sparseImageFormatProperties2Allocator );
#endif
}

static void GetExternalBufferProperties( vk::PhysicalDevice physicalDevice,
                                         const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                         vk::ExternalBufferProperties* pExternalBufferProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalBufferProperties( pExternalBufferInfo, pExternalBufferProperties );
#else
    s_MockPtr->_GetExternalBufferProperties( physicalDevice, pExternalBufferInfo, pExternalBufferProperties );
#endif
}

static vk::ExternalBufferProperties
GetExternalBufferProperties( vk::PhysicalDevice physicalDevice,
                             const vk::PhysicalDeviceExternalBufferInfo& externalBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalBufferProperties( externalBufferInfo );
#else
    return s_MockPtr->_GetExternalBufferProperties( physicalDevice, externalBufferInfo );
#endif
}

static void GetExternalFenceProperties( vk::PhysicalDevice physicalDevice,
                                        const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                        vk::ExternalFenceProperties* pExternalFenceProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalFenceProperties( pExternalFenceInfo, pExternalFenceProperties );
#else
    s_MockPtr->_GetExternalFenceProperties( physicalDevice, pExternalFenceInfo, pExternalFenceProperties );
#endif
}

static vk::ExternalFenceProperties
GetExternalFenceProperties( vk::PhysicalDevice physicalDevice,
                            const vk::PhysicalDeviceExternalFenceInfo& externalFenceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalFenceProperties( externalFenceInfo );
#else
    return s_MockPtr->_GetExternalFenceProperties( physicalDevice, externalFenceInfo );
#endif
}

static void GetExternalSemaphoreProperties( vk::PhysicalDevice physicalDevice,
                                            const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                            vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalSemaphoreProperties( pExternalSemaphoreInfo, pExternalSemaphoreProperties );
#else
    s_MockPtr->_GetExternalSemaphoreProperties( physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties );
#endif
}

static vk::ExternalSemaphoreProperties
GetExternalSemaphoreProperties( vk::PhysicalDevice physicalDevice,
                                const vk::PhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalSemaphoreProperties( externalSemaphoreInfo );
#else
    return s_MockPtr->_GetExternalSemaphoreProperties( physicalDevice, externalSemaphoreInfo );
#endif
}

static vk::Result GetToolProperties( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount,
                                     vk::PhysicalDeviceToolProperties* pToolProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolProperties( pToolCount, pToolProperties );
#else
    return s_MockPtr->_GetToolProperties( physicalDevice, pToolCount, pToolProperties );
#endif
}

template <typename PhysicalDeviceToolPropertiesAllocator = std::allocator<vk::PhysicalDeviceToolProperties>>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, PhysicalDeviceToolPropertiesAllocator>>
GetToolProperties( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolProperties();
#else
    return s_MockPtr->_GetToolProperties();
#endif
}

template <typename PhysicalDeviceToolPropertiesAllocator = std::allocator<vk::PhysicalDeviceToolProperties>,
          typename B1 = PhysicalDeviceToolPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDeviceToolProperties>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, PhysicalDeviceToolPropertiesAllocator>>
GetToolProperties( vk::PhysicalDevice physicalDevice,
                   PhysicalDeviceToolPropertiesAllocator& physicalDeviceToolPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolProperties( physicalDeviceToolPropertiesAllocator );
#else
    return s_MockPtr->_GetToolProperties( physicalDevice, physicalDeviceToolPropertiesAllocator );
#endif
}

static vk::Result GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                        vk::SurfaceKHR surface, vk::Bool32* pSupported ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceSupportKHR( queueFamilyIndex, surface, pSupported );
#else
    return s_MockPtr->_GetSurfaceSupportKHR( physicalDevice, queueFamilyIndex, surface, pSupported );
#endif
}

static ResultValue<vk::Result, vk::Bool32>
GetSurfaceSupportKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex, vk::SurfaceKHR surface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceSupportKHR( queueFamilyIndex, surface );
#else
    return s_MockPtr->_GetSurfaceSupportKHR( physicalDevice, queueFamilyIndex, surface );
#endif
}

static vk::Result GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                             vk::SurfaceCapabilitiesKHR* pSurfaceCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilitiesKHR( surface, pSurfaceCapabilities );
#else
    return s_MockPtr->_GetSurfaceCapabilitiesKHR( physicalDevice, surface, pSurfaceCapabilities );
#endif
}

static ResultValue<vk::Result, vk::SurfaceCapabilitiesKHR> GetSurfaceCapabilitiesKHR( vk::PhysicalDevice physicalDevice,
                                                                                      vk::SurfaceKHR surface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilitiesKHR( surface );
#else
    return s_MockPtr->_GetSurfaceCapabilitiesKHR( physicalDevice, surface );
#endif
}

static vk::Result GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                        uint32_t* pSurfaceFormatCount, vk::SurfaceFormatKHR* pSurfaceFormats ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormatsKHR( surface, pSurfaceFormatCount, pSurfaceFormats );
#else
    return s_MockPtr->_GetSurfaceFormatsKHR( physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats );
#endif
}

template <typename SurfaceFormatKHRAllocator = std::allocator<vk::SurfaceFormatKHR>>

template <typename SurfaceFormatKHRAllocator = std::allocator<vk::SurfaceFormatKHR>,
          typename B1 = SurfaceFormatKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SurfaceFormatKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::SurfaceFormatKHR, SurfaceFormatKHRAllocator>>
GetSurfaceFormatsKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                      SurfaceFormatKHRAllocator& surfaceFormatKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormatsKHR( surface, surfaceFormatKHRAllocator );
#else
    return s_MockPtr->_GetSurfaceFormatsKHR( physicalDevice, surface, surfaceFormatKHRAllocator );
#endif
}

static vk::Result GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                             uint32_t* pPresentModeCount, vk::PresentModeKHR* pPresentModes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfacePresentModesKHR( surface, pPresentModeCount, pPresentModes );
#else
    return s_MockPtr->_GetSurfacePresentModesKHR( physicalDevice, surface, pPresentModeCount, pPresentModes );
#endif
}

template <typename PresentModeKHRAllocator = std::allocator<vk::PresentModeKHR>>

template <typename PresentModeKHRAllocator = std::allocator<vk::PresentModeKHR>, typename B1 = PresentModeKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PresentModeKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PresentModeKHR, PresentModeKHRAllocator>>
GetSurfacePresentModesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                           PresentModeKHRAllocator& presentModeKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfacePresentModesKHR( surface, presentModeKHRAllocator );
#else
    return s_MockPtr->_GetSurfacePresentModesKHR( physicalDevice, surface, presentModeKHRAllocator );
#endif
}

static vk::Result GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                           uint32_t* pRectCount, vk::Rect2D* pRects ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getPresentRectanglesKHR( surface, pRectCount, pRects );
#else
    return s_MockPtr->_GetPresentRectanglesKHR( physicalDevice, surface, pRectCount, pRects );
#endif
}

template <typename Rect2DAllocator = std::allocator<vk::Rect2D>>
static ResultValue<vk::Result, std::vector<vk::Rect2D, Rect2DAllocator>>
GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getPresentRectanglesKHR( surface );
#else
    return s_MockPtr->_GetPresentRectanglesKHR( physicalDevice, surface );
#endif
}

template <typename Rect2DAllocator = std::allocator<vk::Rect2D>, typename B1 = Rect2DAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, Rect2D>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::Rect2D, Rect2DAllocator>>
GetPresentRectanglesKHR( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                         Rect2DAllocator& rect2DAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getPresentRectanglesKHR( surface, rect2DAllocator );
#else
    return s_MockPtr->_GetPresentRectanglesKHR( physicalDevice, surface, rect2DAllocator );
#endif
}

static vk::Result GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                           vk::DisplayPropertiesKHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPropertiesKHR( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayPropertiesKHR( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename DisplayPropertiesKHRAllocator = std::allocator<vk::DisplayPropertiesKHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, DisplayPropertiesKHRAllocator>>
GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPropertiesKHR();
#else
    return s_MockPtr->_GetDisplayPropertiesKHR();
#endif
}

template <typename DisplayPropertiesKHRAllocator = std::allocator<vk::DisplayPropertiesKHR>,
          typename B1 = DisplayPropertiesKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, DisplayPropertiesKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayPropertiesKHR, DisplayPropertiesKHRAllocator>>
GetDisplayPropertiesKHR( vk::PhysicalDevice physicalDevice,
                         DisplayPropertiesKHRAllocator& displayPropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPropertiesKHR( displayPropertiesKHRAllocator );
#else
    return s_MockPtr->_GetDisplayPropertiesKHR( physicalDevice, displayPropertiesKHRAllocator );
#endif
}

static vk::Result GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                vk::DisplayPlanePropertiesKHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlanePropertiesKHR( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayPlanePropertiesKHR( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename DisplayPlanePropertiesKHRAllocator = std::allocator<vk::DisplayPlanePropertiesKHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayPlanePropertiesKHR, DisplayPlanePropertiesKHRAllocator>>
GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlanePropertiesKHR();
#else
    return s_MockPtr->_GetDisplayPlanePropertiesKHR();
#endif
}

template <
        typename DisplayPlanePropertiesKHRAllocator = std::allocator<vk::DisplayPlanePropertiesKHR>,
        typename B1 = DisplayPlanePropertiesKHRAllocator,
        typename std::enable_if<std::is_same<typename B1::value_type, DisplayPlanePropertiesKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayPlanePropertiesKHR, DisplayPlanePropertiesKHRAllocator>>
GetDisplayPlanePropertiesKHR( vk::PhysicalDevice physicalDevice,
                              DisplayPlanePropertiesKHRAllocator& displayPlanePropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlanePropertiesKHR( displayPlanePropertiesKHRAllocator );
#else
    return s_MockPtr->_GetDisplayPlanePropertiesKHR( physicalDevice, displayPlanePropertiesKHRAllocator );
#endif
}

static vk::Result GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex,
                                                       uint32_t* pDisplayCount, vk::DisplayKHR* pDisplays ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneSupportedDisplaysKHR( planeIndex, pDisplayCount, pDisplays );
#else
    return s_MockPtr->_GetDisplayPlaneSupportedDisplaysKHR( physicalDevice, planeIndex, pDisplayCount, pDisplays );
#endif
}

template <typename DisplayKHRAllocator = std::allocator<vk::DisplayKHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayKHR, DisplayKHRAllocator>>
GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneSupportedDisplaysKHR( planeIndex );
#else
    return s_MockPtr->_GetDisplayPlaneSupportedDisplaysKHR( physicalDevice, planeIndex );
#endif
}

template <typename DisplayKHRAllocator = std::allocator<vk::DisplayKHR>, typename B1 = DisplayKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, DisplayKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayKHR, DisplayKHRAllocator>>
GetDisplayPlaneSupportedDisplaysKHR( vk::PhysicalDevice physicalDevice, uint32_t planeIndex,
                                     DisplayKHRAllocator& displayKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneSupportedDisplaysKHR( planeIndex, displayKHRAllocator );
#else
    return s_MockPtr->_GetDisplayPlaneSupportedDisplaysKHR( physicalDevice, planeIndex, displayKHRAllocator );
#endif
}

static vk::Result GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                                               uint32_t* pPropertyCount,
                                               vk::DisplayModePropertiesKHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModePropertiesKHR( display, pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayModePropertiesKHR( physicalDevice, display, pPropertyCount, pProperties );
#endif
}

template <typename DisplayModePropertiesKHRAllocator = std::allocator<vk::DisplayModePropertiesKHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayModePropertiesKHR, DisplayModePropertiesKHRAllocator>>
GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModePropertiesKHR( display );
#else
    return s_MockPtr->_GetDisplayModePropertiesKHR( physicalDevice, display );
#endif
}

template <
        typename DisplayModePropertiesKHRAllocator = std::allocator<vk::DisplayModePropertiesKHR>,
        typename B1 = DisplayModePropertiesKHRAllocator,
        typename std::enable_if<std::is_same<typename B1::value_type, DisplayModePropertiesKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayModePropertiesKHR, DisplayModePropertiesKHRAllocator>>
GetDisplayModePropertiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                             DisplayModePropertiesKHRAllocator& displayModePropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModePropertiesKHR( display, displayModePropertiesKHRAllocator );
#else
    return s_MockPtr->_GetDisplayModePropertiesKHR( physicalDevice, display, displayModePropertiesKHRAllocator );
#endif
}

static vk::Result CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                                        const vk::DisplayModeCreateInfoKHR* pCreateInfo,
                                        const vk::AllocationCallbacks* pAllocator, vk::DisplayModeKHR* pMode ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDisplayModeKHR( display, pCreateInfo, pAllocator, pMode );
#else
    return s_MockPtr->_CreateDisplayModeKHR( physicalDevice, display, pCreateInfo, pAllocator, pMode );
#endif
}

static ResultValue<vk::Result, vk::DisplayModeKHR>
CreateDisplayModeKHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                      const vk::DisplayModeCreateInfoKHR& createInfo,
                      Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDisplayModeKHR( display, createInfo, nullptr );
#else
    return s_MockPtr->_CreateDisplayModeKHR( physicalDevice, display, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DisplayModeKHR, Dispatch>>
CreateDisplayModeKHRUnique( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                            const vk::DisplayModeCreateInfoKHR& createInfo,
                            Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.createDisplayModeKHRUnique( display, createInfo, nullptr );
#else
    return s_MockPtr->_CreateDisplayModeKHRUnique( physicalDevice, display, createInfo, nullptr );
#endif
}

static vk::Result GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode,
                                                  uint32_t planeIndex,
                                                  vk::DisplayPlaneCapabilitiesKHR* pCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneCapabilitiesKHR( mode, planeIndex, pCapabilities );
#else
    return s_MockPtr->_GetDisplayPlaneCapabilitiesKHR( physicalDevice, mode, planeIndex, pCapabilities );
#endif
}

static ResultValue<vk::Result, vk::DisplayPlaneCapabilitiesKHR>
GetDisplayPlaneCapabilitiesKHR( vk::PhysicalDevice physicalDevice, vk::DisplayModeKHR mode, uint32_t planeIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneCapabilitiesKHR( mode, planeIndex );
#else
    return s_MockPtr->_GetDisplayPlaneCapabilitiesKHR( physicalDevice, mode, planeIndex );
#endif
}

static vk::Result GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice,
                                           const vk::VideoProfileInfoKHR* pVideoProfile,
                                           vk::VideoCapabilitiesKHR* pCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoCapabilitiesKHR( pVideoProfile, pCapabilities );
#else
    return s_MockPtr->_GetVideoCapabilitiesKHR( physicalDevice, pVideoProfile, pCapabilities );
#endif
}

static ResultValue<vk::Result, vk::VideoCapabilitiesKHR>
GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice, const vk::VideoProfileInfoKHR& videoProfile ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoCapabilitiesKHR( videoProfile );
#else
    return s_MockPtr->_GetVideoCapabilitiesKHR( physicalDevice, videoProfile );
#endif
}

template <typename X, typename Y, typename... Z>
static ResultValue<vk::Result, vk::StructureChain<X, Y, Z...>>
GetVideoCapabilitiesKHR( vk::PhysicalDevice physicalDevice, const vk::VideoProfileInfoKHR& videoProfile ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoCapabilitiesKHR( videoProfile );
#else
    return s_MockPtr->_GetVideoCapabilitiesKHR( physicalDevice, videoProfile );
#endif
}

static vk::Result GetVideoFormatPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                               const vk::PhysicalDeviceVideoFormatInfoKHR* pVideoFormatInfo,
                                               uint32_t* pVideoFormatPropertyCount,
                                               vk::VideoFormatPropertiesKHR* pVideoFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoFormatPropertiesKHR( pVideoFormatInfo, pVideoFormatPropertyCount,
                                                       pVideoFormatProperties );
#else
    return s_MockPtr->_GetVideoFormatPropertiesKHR( physicalDevice, pVideoFormatInfo, pVideoFormatPropertyCount,
                                                    pVideoFormatProperties );
#endif
}

template <typename VideoFormatPropertiesKHRAllocator = std::allocator<vk::VideoFormatPropertiesKHR>>
static ResultValue<vk::Result, std::vector<vk::VideoFormatPropertiesKHR, VideoFormatPropertiesKHRAllocator>>
GetVideoFormatPropertiesKHR( vk::PhysicalDevice physicalDevice,
                             const vk::PhysicalDeviceVideoFormatInfoKHR& videoFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoFormatPropertiesKHR( videoFormatInfo );
#else
    return s_MockPtr->_GetVideoFormatPropertiesKHR( physicalDevice, videoFormatInfo );
#endif
}

template <
        typename VideoFormatPropertiesKHRAllocator = std::allocator<vk::VideoFormatPropertiesKHR>,
        typename B1 = VideoFormatPropertiesKHRAllocator,
        typename std::enable_if<std::is_same<typename B1::value_type, VideoFormatPropertiesKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::VideoFormatPropertiesKHR, VideoFormatPropertiesKHRAllocator>>
GetVideoFormatPropertiesKHR( vk::PhysicalDevice physicalDevice,
                             const vk::PhysicalDeviceVideoFormatInfoKHR& videoFormatInfo,
                             VideoFormatPropertiesKHRAllocator& videoFormatPropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getVideoFormatPropertiesKHR( videoFormatInfo, videoFormatPropertiesKHRAllocator );
#else
    return s_MockPtr->_GetVideoFormatPropertiesKHR( physicalDevice, videoFormatInfo,
                                                    videoFormatPropertiesKHRAllocator );
#endif
}

static vk::Result
GetExternalImageFormatPropertiesNV( vk::PhysicalDevice physicalDevice, vk::Format format, vk::ImageType type,
                                    vk::ImageTiling tiling, vk::ImageUsageFlags usage, vk::ImageCreateFlags flags,
                                    vk::ExternalMemoryHandleTypeFlagsNV externalHandleType,
                                    vk::ExternalImageFormatPropertiesNV* pExternalImageFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalImageFormatPropertiesNV( format, type, tiling, usage, flags, externalHandleType,
                                                              pExternalImageFormatProperties );
#else
    return s_MockPtr->_GetExternalImageFormatPropertiesNV( physicalDevice, format, type, tiling, usage, flags,
                                                           externalHandleType, pExternalImageFormatProperties );
#endif
}

static void GetFeatures2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceFeatures2* pFeatures ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFeatures2KHR( pFeatures );
#else
    s_MockPtr->_GetFeatures2KHR( physicalDevice, pFeatures );
#endif
}

static vk::PhysicalDeviceFeatures2 GetFeatures2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFeatures2KHR();
#else
    return s_MockPtr->_GetFeatures2KHR();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetFeatures2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFeatures2KHR();
#else
    return s_MockPtr->_GetFeatures2KHR();
#endif
}

static void GetProperties2KHR( vk::PhysicalDevice physicalDevice, vk::PhysicalDeviceProperties2* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getProperties2KHR( pProperties );
#else
    s_MockPtr->_GetProperties2KHR( physicalDevice, pProperties );
#endif
}

static vk::PhysicalDeviceProperties2 GetProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getProperties2KHR();
#else
    return s_MockPtr->_GetProperties2KHR();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getProperties2KHR();
#else
    return s_MockPtr->_GetProperties2KHR();
#endif
}

static void GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format,
                                     vk::FormatProperties2* pFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getFormatProperties2KHR( format, pFormatProperties );
#else
    s_MockPtr->_GetFormatProperties2KHR( physicalDevice, format, pFormatProperties );
#endif
}

static vk::FormatProperties2 GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice, vk::Format format ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFormatProperties2KHR( format );
#else
    return s_MockPtr->_GetFormatProperties2KHR( physicalDevice, format );
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                               vk::Format format ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFormatProperties2KHR( format );
#else
    return s_MockPtr->_GetFormatProperties2KHR( physicalDevice, format );
#endif
}

static vk::Result GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                const vk::PhysicalDeviceImageFormatInfo2* pImageFormatInfo,
                                                vk::ImageFormatProperties2* pImageFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2KHR( pImageFormatInfo, pImageFormatProperties );
#else
    return s_MockPtr->_GetImageFormatProperties2KHR( physicalDevice, pImageFormatInfo, pImageFormatProperties );
#endif
}

static ResultValue<vk::Result, vk::ImageFormatProperties2>
GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                              const vk::PhysicalDeviceImageFormatInfo2& imageFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2KHR( imageFormatInfo );
#else
    return s_MockPtr->_GetImageFormatProperties2KHR( physicalDevice, imageFormatInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static ResultValue<vk::Result, vk::StructureChain<X, Y, Z...>>
GetImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                              const vk::PhysicalDeviceImageFormatInfo2& imageFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getImageFormatProperties2KHR( imageFormatInfo );
#else
    return s_MockPtr->_GetImageFormatProperties2KHR( physicalDevice, imageFormatInfo );
#endif
}

static void GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pQueueFamilyPropertyCount,
                                          vk::QueueFamilyProperties2* pQueueFamilyProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getQueueFamilyProperties2KHR( pQueueFamilyPropertyCount, pQueueFamilyProperties );
#else
    s_MockPtr->_GetQueueFamilyProperties2KHR( physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties );
#endif
}

template <typename QueueFamilyProperties2Allocator = std::allocator<vk::QueueFamilyProperties2>>
static std::vector<vk::QueueFamilyProperties2, QueueFamilyProperties2Allocator>
GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2KHR();
#else
    return s_MockPtr->_GetQueueFamilyProperties2KHR();
#endif
}

template <typename QueueFamilyProperties2Allocator = std::allocator<vk::QueueFamilyProperties2>,
          typename B1 = QueueFamilyProperties2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, QueueFamilyProperties2>::value, int>::type =
                  static std::vector<vk::QueueFamilyProperties2, QueueFamilyProperties2Allocator>
                          GetQueueFamilyProperties2KHR(
                                  vk::PhysicalDevice physicalDevice,
                                  QueueFamilyProperties2Allocator& queueFamilyProperties2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2KHR( queueFamilyProperties2Allocator );
#else
    return s_MockPtr->_GetQueueFamilyProperties2KHR( physicalDevice, queueFamilyProperties2Allocator );
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>>
static std::vector<StructureChain, StructureChainAllocator>
GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2KHR();
#else
    return s_MockPtr->_GetQueueFamilyProperties2KHR();
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>,
          typename B1 = StructureChainAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, StructureChain>::value, int>::type = 0>
static std::vector<StructureChain, StructureChainAllocator>
GetQueueFamilyProperties2KHR( vk::PhysicalDevice physicalDevice,
                              StructureChainAllocator& structureChainAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyProperties2KHR( structureChainAllocator );
#else
    return s_MockPtr->_GetQueueFamilyProperties2KHR( physicalDevice, structureChainAllocator );
#endif
}

static void GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice,
                                     vk::PhysicalDeviceMemoryProperties2* pMemoryProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getMemoryProperties2KHR( pMemoryProperties );
#else
    s_MockPtr->_GetMemoryProperties2KHR( physicalDevice, pMemoryProperties );
#endif
}

static vk::PhysicalDeviceMemoryProperties2 GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMemoryProperties2KHR();
#else
    return s_MockPtr->_GetMemoryProperties2KHR();
#endif
}

template <typename X, typename Y, typename... Z>
static vk::StructureChain<X, Y, Z...> GetMemoryProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMemoryProperties2KHR();
#else
    return s_MockPtr->_GetMemoryProperties2KHR();
#endif
}

static void GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                                const vk::PhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
                                                uint32_t* pPropertyCount,
                                                vk::SparseImageFormatProperties2* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getSparseImageFormatProperties2KHR( pFormatInfo, pPropertyCount, pProperties );
#else
    s_MockPtr->_GetSparseImageFormatProperties2KHR( physicalDevice, pFormatInfo, pPropertyCount, pProperties );
#endif
}

template <typename SparseImageFormatProperties2Allocator = std::allocator<vk::SparseImageFormatProperties2>>
static std::vector<vk::SparseImageFormatProperties2, SparseImageFormatProperties2Allocator>
GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                    const vk::PhysicalDeviceSparseImageFormatInfo2& formatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties2KHR( formatInfo );
#else
    return s_MockPtr->_GetSparseImageFormatProperties2KHR( physicalDevice, formatInfo );
#endif
}

template <typename SparseImageFormatProperties2Allocator = std::allocator<vk::SparseImageFormatProperties2>,
          typename B1 = SparseImageFormatProperties2Allocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SparseImageFormatProperties2>::value,
                                  int>::type = 0>
static std::vector<vk::SparseImageFormatProperties2, SparseImageFormatProperties2Allocator>
GetSparseImageFormatProperties2KHR( vk::PhysicalDevice physicalDevice,
                                    const vk::PhysicalDeviceSparseImageFormatInfo2& formatInfo,
                                    SparseImageFormatProperties2Allocator& sparseImageFormatProperties2Allocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSparseImageFormatProperties2KHR( formatInfo, sparseImageFormatProperties2Allocator );
#else
    return s_MockPtr->_GetSparseImageFormatProperties2KHR( physicalDevice, formatInfo,
                                                           sparseImageFormatProperties2Allocator );
#endif
}

static void GetExternalBufferPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                            const vk::PhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
                                            vk::ExternalBufferProperties* pExternalBufferProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalBufferPropertiesKHR( pExternalBufferInfo, pExternalBufferProperties );
#else
    s_MockPtr->_GetExternalBufferPropertiesKHR( physicalDevice, pExternalBufferInfo, pExternalBufferProperties );
#endif
}

static vk::ExternalBufferProperties
GetExternalBufferPropertiesKHR( vk::PhysicalDevice physicalDevice,
                                const vk::PhysicalDeviceExternalBufferInfo& externalBufferInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalBufferPropertiesKHR( externalBufferInfo );
#else
    return s_MockPtr->_GetExternalBufferPropertiesKHR( physicalDevice, externalBufferInfo );
#endif
}

static void GetExternalSemaphorePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                               const vk::PhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
                                               vk::ExternalSemaphoreProperties* pExternalSemaphoreProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalSemaphorePropertiesKHR( pExternalSemaphoreInfo, pExternalSemaphoreProperties );
#else
    s_MockPtr->_GetExternalSemaphorePropertiesKHR( physicalDevice, pExternalSemaphoreInfo,
                                                   pExternalSemaphoreProperties );
#endif
}

static vk::ExternalSemaphoreProperties
GetExternalSemaphorePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                   const vk::PhysicalDeviceExternalSemaphoreInfo& externalSemaphoreInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalSemaphorePropertiesKHR( externalSemaphoreInfo );
#else
    return s_MockPtr->_GetExternalSemaphorePropertiesKHR( physicalDevice, externalSemaphoreInfo );
#endif
}

static vk::Result ReleaseDisplayEXT( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.releaseDisplayEXT( display );
#else
    return s_MockPtr->_ReleaseDisplayEXT( physicalDevice, display );
#endif
}

static void ReleaseDisplayEXT( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.releaseDisplayEXT( display );
#else
    s_MockPtr->_ReleaseDisplayEXT( physicalDevice, display );
#endif
}

static vk::Result GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface,
                                              vk::SurfaceCapabilities2EXT* pSurfaceCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilities2EXT( surface, pSurfaceCapabilities );
#else
    return s_MockPtr->_GetSurfaceCapabilities2EXT( physicalDevice, surface, pSurfaceCapabilities );
#endif
}

static ResultValue<vk::Result, vk::SurfaceCapabilities2EXT>
GetSurfaceCapabilities2EXT( vk::PhysicalDevice physicalDevice, vk::SurfaceKHR surface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilities2EXT( surface );
#else
    return s_MockPtr->_GetSurfaceCapabilities2EXT( physicalDevice, surface );
#endif
}

static void GetExternalFencePropertiesKHR( vk::PhysicalDevice physicalDevice,
                                           const vk::PhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
                                           vk::ExternalFenceProperties* pExternalFenceProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getExternalFencePropertiesKHR( pExternalFenceInfo, pExternalFenceProperties );
#else
    s_MockPtr->_GetExternalFencePropertiesKHR( physicalDevice, pExternalFenceInfo, pExternalFenceProperties );
#endif
}

static vk::ExternalFenceProperties
GetExternalFencePropertiesKHR( vk::PhysicalDevice physicalDevice,
                               const vk::PhysicalDeviceExternalFenceInfo& externalFenceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getExternalFencePropertiesKHR( externalFenceInfo );
#else
    return s_MockPtr->_GetExternalFencePropertiesKHR( physicalDevice, externalFenceInfo );
#endif
}

static vk::Result
EnumerateQueueFamilyPerformanceQueryCountersKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
                                                 uint32_t* pCounterCount, vk::PerformanceCounterKHR* pCounters,
                                                 vk::PerformanceCounterDescriptionKHR* pCounterDescriptions ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateQueueFamilyPerformanceQueryCountersKHR( queueFamilyIndex, pCounterCount, pCounters,
                                                                           pCounterDescriptions );
#else
    return s_MockPtr->_EnumerateQueueFamilyPerformanceQueryCountersKHR( physicalDevice, queueFamilyIndex, pCounterCount,
                                                                        pCounters, pCounterDescriptions );
#endif
}

template <typename PerformanceCounterKHRAllocator = std::allocator<vk::PerformanceCounterKHR>,
          typename PerformanceCounterDescriptionKHRAllocator = std::allocator<vk::PerformanceCounterDescriptionKHR>>
static ResultValue<
        vk::Result,
        std::pair<std::vector<vk::PerformanceCounterKHR, PerformanceCounterKHRAllocator>,
                  std::vector<vk::PerformanceCounterDescriptionKHR, PerformanceCounterDescriptionKHRAllocator>>>
EnumerateQueueFamilyPerformanceQueryCountersKHR( vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateQueueFamilyPerformanceQueryCountersKHR( queueFamilyIndex );
#else
    return s_MockPtr->_EnumerateQueueFamilyPerformanceQueryCountersKHR( physicalDevice, queueFamilyIndex );
#endif
}

template <
        typename PerformanceCounterKHRAllocator = std::allocator<vk::PerformanceCounterKHR>,
        typename PerformanceCounterDescriptionKHRAllocator = std::allocator<vk::PerformanceCounterDescriptionKHR>,
        typename B1 = PerformanceCounterKHRAllocator, typename B2 = PerformanceCounterDescriptionKHRAllocator,
        typename std::enable_if<std::is_same<typename B1::value_type, PerformanceCounterKHR>::value &&
                                        std::is_same<typename B2::value_type, PerformanceCounterDescriptionKHR>::value,
                                int>::type = 0>
static ResultValue<
        vk::Result,
        std::pair<std::vector<vk::PerformanceCounterKHR, PerformanceCounterKHRAllocator>,
                  std::vector<vk::PerformanceCounterDescriptionKHR, PerformanceCounterDescriptionKHRAllocator>>>
EnumerateQueueFamilyPerformanceQueryCountersKHR(
        vk::PhysicalDevice physicalDevice, uint32_t queueFamilyIndex,
        PerformanceCounterKHRAllocator& performanceCounterKHRAllocator,
        PerformanceCounterDescriptionKHRAllocator& performanceCounterDescriptionKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.enumerateQueueFamilyPerformanceQueryCountersKHR(
            queueFamilyIndex, performanceCounterKHRAllocator, performanceCounterDescriptionKHRAllocator );
#else
    return s_MockPtr->_EnumerateQueueFamilyPerformanceQueryCountersKHR( physicalDevice, queueFamilyIndex,
                                                                        performanceCounterKHRAllocator,
                                                                        performanceCounterDescriptionKHRAllocator );
#endif
}

static void
GetQueueFamilyPerformanceQueryPassesKHR( vk::PhysicalDevice physicalDevice,
                                         const vk::QueryPoolPerformanceCreateInfoKHR* pPerformanceQueryCreateInfo,
                                         uint32_t* pNumPasses ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getQueueFamilyPerformanceQueryPassesKHR( pPerformanceQueryCreateInfo, pNumPasses );
#else
    s_MockPtr->_GetQueueFamilyPerformanceQueryPassesKHR( physicalDevice, pPerformanceQueryCreateInfo, pNumPasses );
#endif
}

static uint32_t
GetQueueFamilyPerformanceQueryPassesKHR( vk::PhysicalDevice physicalDevice,
                                         const vk::QueryPoolPerformanceCreateInfoKHR& performanceQueryCreateInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getQueueFamilyPerformanceQueryPassesKHR( performanceQueryCreateInfo );
#else
    return s_MockPtr->_GetQueueFamilyPerformanceQueryPassesKHR( physicalDevice, performanceQueryCreateInfo );
#endif
}

static vk::Result GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                              const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                              vk::SurfaceCapabilities2KHR* pSurfaceCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilities2KHR( pSurfaceInfo, pSurfaceCapabilities );
#else
    return s_MockPtr->_GetSurfaceCapabilities2KHR( physicalDevice, pSurfaceInfo, pSurfaceCapabilities );
#endif
}

static ResultValue<vk::Result, vk::SurfaceCapabilities2KHR>
GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                            const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilities2KHR( surfaceInfo );
#else
    return s_MockPtr->_GetSurfaceCapabilities2KHR( physicalDevice, surfaceInfo );
#endif
}

template <typename X, typename Y, typename... Z>
static ResultValue<vk::Result, vk::StructureChain<X, Y, Z...>>
GetSurfaceCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                            const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceCapabilities2KHR( surfaceInfo );
#else
    return s_MockPtr->_GetSurfaceCapabilities2KHR( physicalDevice, surfaceInfo );
#endif
}

static vk::Result GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice,
                                         const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                         uint32_t* pSurfaceFormatCount, vk::SurfaceFormat2KHR* pSurfaceFormats ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormats2KHR( pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats );
#else
    return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats );
#endif
}

template <typename SurfaceFormat2KHRAllocator = std::allocator<vk::SurfaceFormat2KHR>>
static ResultValue<vk::Result, std::vector<vk::SurfaceFormat2KHR, SurfaceFormat2KHRAllocator>>
GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormats2KHR( surfaceInfo );
#else
    return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, surfaceInfo );
#endif
}

template <typename SurfaceFormat2KHRAllocator = std::allocator<vk::SurfaceFormat2KHR>,
          typename B1 = SurfaceFormat2KHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, SurfaceFormat2KHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::SurfaceFormat2KHR, SurfaceFormat2KHRAllocator>>
GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo,
                       SurfaceFormat2KHRAllocator& surfaceFormat2KHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormats2KHR( surfaceInfo, surfaceFormat2KHRAllocator );
#else
    return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, surfaceInfo, surfaceFormat2KHRAllocator );
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>>
static ResultValue<vk::Result, std::vector<StructureChain, StructureChainAllocator>>
GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormats2KHR( surfaceInfo );
#else
    return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, surfaceInfo );
#endif
}

template <typename StructureChain, typename StructureChainAllocator = std::allocator<StructureChain>,
          typename B1 = StructureChainAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, StructureChain>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<StructureChain, StructureChainAllocator>>
GetSurfaceFormats2KHR( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo,
                       StructureChainAllocator& structureChainAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfaceFormats2KHR( surfaceInfo, structureChainAllocator );
#else
    return s_MockPtr->_GetSurfaceFormats2KHR( physicalDevice, surfaceInfo, structureChainAllocator );
#endif
}

static vk::Result GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                            vk::DisplayProperties2KHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayProperties2KHR( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayProperties2KHR( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename DisplayProperties2KHRAllocator = std::allocator<vk::DisplayProperties2KHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayProperties2KHR, DisplayProperties2KHRAllocator>>
GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayProperties2KHR();
#else
    return s_MockPtr->_GetDisplayProperties2KHR();
#endif
}

template <typename DisplayProperties2KHRAllocator = std::allocator<vk::DisplayProperties2KHR>,
          typename B1 = DisplayProperties2KHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, DisplayProperties2KHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayProperties2KHR, DisplayProperties2KHRAllocator>>
GetDisplayProperties2KHR( vk::PhysicalDevice physicalDevice,
                          DisplayProperties2KHRAllocator& displayProperties2KHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayProperties2KHR( displayProperties2KHRAllocator );
#else
    return s_MockPtr->_GetDisplayProperties2KHR( physicalDevice, displayProperties2KHRAllocator );
#endif
}

static vk::Result GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                 vk::DisplayPlaneProperties2KHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneProperties2KHR( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayPlaneProperties2KHR( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename DisplayPlaneProperties2KHRAllocator = std::allocator<vk::DisplayPlaneProperties2KHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayPlaneProperties2KHR, DisplayPlaneProperties2KHRAllocator>>
GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneProperties2KHR();
#else
    return s_MockPtr->_GetDisplayPlaneProperties2KHR();
#endif
}

template <typename DisplayPlaneProperties2KHRAllocator = std::allocator<vk::DisplayPlaneProperties2KHR>,
          typename B1 = DisplayPlaneProperties2KHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, DisplayPlaneProperties2KHR>::value, int>::type =
                  0>
static ResultValue<vk::Result, std::vector<vk::DisplayPlaneProperties2KHR, DisplayPlaneProperties2KHRAllocator>>
GetDisplayPlaneProperties2KHR( vk::PhysicalDevice physicalDevice,
                               DisplayPlaneProperties2KHRAllocator& displayPlaneProperties2KHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneProperties2KHR( displayPlaneProperties2KHRAllocator );
#else
    return s_MockPtr->_GetDisplayPlaneProperties2KHR( physicalDevice, displayPlaneProperties2KHRAllocator );
#endif
}

static vk::Result GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                                                uint32_t* pPropertyCount,
                                                vk::DisplayModeProperties2KHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModeProperties2KHR( display, pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetDisplayModeProperties2KHR( physicalDevice, display, pPropertyCount, pProperties );
#endif
}

template <typename DisplayModeProperties2KHRAllocator = std::allocator<vk::DisplayModeProperties2KHR>>
static ResultValue<vk::Result, std::vector<vk::DisplayModeProperties2KHR, DisplayModeProperties2KHRAllocator>>
GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModeProperties2KHR( display );
#else
    return s_MockPtr->_GetDisplayModeProperties2KHR( physicalDevice, display );
#endif
}

template <
        typename DisplayModeProperties2KHRAllocator = std::allocator<vk::DisplayModeProperties2KHR>,
        typename B1 = DisplayModeProperties2KHRAllocator,
        typename std::enable_if<std::is_same<typename B1::value_type, DisplayModeProperties2KHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::DisplayModeProperties2KHR, DisplayModeProperties2KHRAllocator>>
GetDisplayModeProperties2KHR( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display,
                              DisplayModeProperties2KHRAllocator& displayModeProperties2KHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayModeProperties2KHR( display, displayModeProperties2KHRAllocator );
#else
    return s_MockPtr->_GetDisplayModeProperties2KHR( physicalDevice, display, displayModeProperties2KHRAllocator );
#endif
}

static vk::Result GetDisplayPlaneCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                                   const vk::DisplayPlaneInfo2KHR* pDisplayPlaneInfo,
                                                   vk::DisplayPlaneCapabilities2KHR* pCapabilities ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneCapabilities2KHR( pDisplayPlaneInfo, pCapabilities );
#else
    return s_MockPtr->_GetDisplayPlaneCapabilities2KHR( physicalDevice, pDisplayPlaneInfo, pCapabilities );
#endif
}

static ResultValue<vk::Result, vk::DisplayPlaneCapabilities2KHR>
GetDisplayPlaneCapabilities2KHR( vk::PhysicalDevice physicalDevice,
                                 const vk::DisplayPlaneInfo2KHR& displayPlaneInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDisplayPlaneCapabilities2KHR( displayPlaneInfo );
#else
    return s_MockPtr->_GetDisplayPlaneCapabilities2KHR( physicalDevice, displayPlaneInfo );
#endif
}

static void GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice, vk::SampleCountFlagBits samples,
                                         vk::MultisamplePropertiesEXT* pMultisampleProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    physicalDevice.getMultisamplePropertiesEXT( samples, pMultisampleProperties );
#else
    s_MockPtr->_GetMultisamplePropertiesEXT( physicalDevice, samples, pMultisampleProperties );
#endif
}

static vk::MultisamplePropertiesEXT GetMultisamplePropertiesEXT( vk::PhysicalDevice physicalDevice,
                                                                 vk::SampleCountFlagBits samples ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getMultisamplePropertiesEXT( samples );
#else
    return s_MockPtr->_GetMultisamplePropertiesEXT( physicalDevice, samples );
#endif
}

static vk::Result GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice, uint32_t* pTimeDomainCount,
                                                  vk::TimeDomainEXT* pTimeDomains ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCalibrateableTimeDomainsEXT( pTimeDomainCount, pTimeDomains );
#else
    return s_MockPtr->_GetCalibrateableTimeDomainsEXT( physicalDevice, pTimeDomainCount, pTimeDomains );
#endif
}

template <typename TimeDomainEXTAllocator = std::allocator<vk::TimeDomainEXT>>
static ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, TimeDomainEXTAllocator>>
GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCalibrateableTimeDomainsEXT();
#else
    return s_MockPtr->_GetCalibrateableTimeDomainsEXT();
#endif
}

template <typename TimeDomainEXTAllocator = std::allocator<vk::TimeDomainEXT>, typename B1 = TimeDomainEXTAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, TimeDomainEXT>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::TimeDomainEXT, TimeDomainEXTAllocator>>
GetCalibrateableTimeDomainsEXT( vk::PhysicalDevice physicalDevice,
                                TimeDomainEXTAllocator& timeDomainEXTAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCalibrateableTimeDomainsEXT( timeDomainEXTAllocator );
#else
    return s_MockPtr->_GetCalibrateableTimeDomainsEXT( physicalDevice, timeDomainEXTAllocator );
#endif
}

static vk::Result GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pFragmentShadingRateCount,
                                              vk::PhysicalDeviceFragmentShadingRateKHR* pFragmentShadingRates ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFragmentShadingRatesKHR( pFragmentShadingRateCount, pFragmentShadingRates );
#else
    return s_MockPtr->_GetFragmentShadingRatesKHR( physicalDevice, pFragmentShadingRateCount, pFragmentShadingRates );
#endif
}

template <typename PhysicalDeviceFragmentShadingRateKHRAllocator =
                  std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>>
static ResultValue<vk::Result,
                   std::vector<vk::PhysicalDeviceFragmentShadingRateKHR, PhysicalDeviceFragmentShadingRateKHRAllocator>>
GetFragmentShadingRatesKHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFragmentShadingRatesKHR();
#else
    return s_MockPtr->_GetFragmentShadingRatesKHR();
#endif
}

template <typename PhysicalDeviceFragmentShadingRateKHRAllocator =
                  std::allocator<vk::PhysicalDeviceFragmentShadingRateKHR>,
          typename B1 = PhysicalDeviceFragmentShadingRateKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDeviceFragmentShadingRateKHR>::value,
                                  int>::type = 0>
static ResultValue<vk::Result,
                   std::vector<vk::PhysicalDeviceFragmentShadingRateKHR, PhysicalDeviceFragmentShadingRateKHRAllocator>>
GetFragmentShadingRatesKHR(
        vk::PhysicalDevice physicalDevice,
        PhysicalDeviceFragmentShadingRateKHRAllocator& physicalDeviceFragmentShadingRateKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getFragmentShadingRatesKHR( &physicalDeviceFragmentShadingRateKHRAllocator );
#else
    return s_MockPtr->_GetFragmentShadingRatesKHR( physicalDevice, &physicalDeviceFragmentShadingRateKHRAllocator );
#endif
}

static vk::Result GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice, uint32_t* pToolCount,
                                        vk::PhysicalDeviceToolProperties* pToolProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolPropertiesEXT( pToolCount, pToolProperties );
#else
    return s_MockPtr->_GetToolPropertiesEXT( physicalDevice, pToolCount, pToolProperties );
#endif
}

template <typename PhysicalDeviceToolPropertiesAllocator = std::allocator<vk::PhysicalDeviceToolProperties>>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, PhysicalDeviceToolPropertiesAllocator>>
GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolPropertiesEXT();
#else
    return s_MockPtr->_GetToolPropertiesEXT();
#endif
}

template <typename PhysicalDeviceToolPropertiesAllocator = std::allocator<vk::PhysicalDeviceToolProperties>,
          typename B1 = PhysicalDeviceToolPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDeviceToolProperties>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceToolProperties, PhysicalDeviceToolPropertiesAllocator>>
GetToolPropertiesEXT( vk::PhysicalDevice physicalDevice,
                      PhysicalDeviceToolPropertiesAllocator& physicalDeviceToolPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getToolPropertiesEXT( physicalDeviceToolPropertiesAllocator );
#else
    return s_MockPtr->_GetToolPropertiesEXT( physicalDevice, physicalDeviceToolPropertiesAllocator );
#endif
}

static vk::Result GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                    vk::CooperativeMatrixPropertiesNV* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesNV( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesNV( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename CooperativeMatrixPropertiesNVAllocator = std::allocator<vk::CooperativeMatrixPropertiesNV>>
static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV, CooperativeMatrixPropertiesNVAllocator>>
GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesNV();
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesNV();
#endif
}

template <typename CooperativeMatrixPropertiesNVAllocator = std::allocator<vk::CooperativeMatrixPropertiesNV>,
          typename B1 = CooperativeMatrixPropertiesNVAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, CooperativeMatrixPropertiesNV>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesNV, CooperativeMatrixPropertiesNVAllocator>>
GetCooperativeMatrixPropertiesNV( vk::PhysicalDevice physicalDevice,
                                  CooperativeMatrixPropertiesNVAllocator& cooperativeMatrixPropertiesNVAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesNV( &cooperativeMatrixPropertiesNVAllocator );
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesNV( physicalDevice, &cooperativeMatrixPropertiesNVAllocator );
#endif
}

static vk::Result
GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice, uint32_t* pCombinationCount,
                                                   vk::FramebufferMixedSamplesCombinationNV* pCombinations ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSupportedFramebufferMixedSamplesCombinationsNV( pCombinationCount, pCombinations );
#else
    return s_MockPtr->_GetSupportedFramebufferMixedSamplesCombinationsNV( physicalDevice, pCombinationCount,
                                                                          pCombinations );
#endif
}

template <typename FramebufferMixedSamplesCombinationNVAllocator =
                  std::allocator<vk::FramebufferMixedSamplesCombinationNV>>
static ResultValue<vk::Result,
                   std::vector<vk::FramebufferMixedSamplesCombinationNV, FramebufferMixedSamplesCombinationNVAllocator>>
GetSupportedFramebufferMixedSamplesCombinationsNV( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSupportedFramebufferMixedSamplesCombinationsNV();
#else
    return s_MockPtr->_GetSupportedFramebufferMixedSamplesCombinationsNV();
#endif
}

template <typename FramebufferMixedSamplesCombinationNVAllocator =
                  std::allocator<vk::FramebufferMixedSamplesCombinationNV>,
          typename B1 = FramebufferMixedSamplesCombinationNVAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, FramebufferMixedSamplesCombinationNV>::value,
                                  int>::type = 0>
static ResultValue<vk::Result,
                   std::vector<vk::FramebufferMixedSamplesCombinationNV, FramebufferMixedSamplesCombinationNVAllocator>>
GetSupportedFramebufferMixedSamplesCombinationsNV(
        vk::PhysicalDevice physicalDevice,
        FramebufferMixedSamplesCombinationNVAllocator& framebufferMixedSamplesCombinationNVAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSupportedFramebufferMixedSamplesCombinationsNV(
            &framebufferMixedSamplesCombinationNVAllocator );
#else
    return s_MockPtr->_GetSupportedFramebufferMixedSamplesCombinationsNV(
            physicalDevice, &framebufferMixedSamplesCombinationNVAllocator );
#endif
}

static vk::Result GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice,
                                              const vk::PhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
                                              uint32_t* pPresentModeCount, vk::PresentModeKHR* pPresentModes ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfacePresentModes2EXT( pSurfaceInfo, pPresentModeCount, pPresentModes );
#else
    return s_MockPtr->_GetSurfacePresentModes2EXT( physicalDevice, pSurfaceInfo, pPresentModeCount, pPresentModes );
#endif
}

template <typename PresentModeKHRAllocator = std::allocator<vk::PresentModeKHR>>
static ResultValue<vk::Result, std::vector<vk::PresentModeKHR, PresentModeKHRAllocator>>
GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice,
                            const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfacePresentModes2EXT( surfaceInfo );
#else
    return s_MockPtr->_GetSurfacePresentModes2EXT( physicalDevice, surfaceInfo );
#endif
}

template <typename PresentModeKHRAllocator = std::allocator<vk::PresentModeKHR>, typename B1 = PresentModeKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PresentModeKHR>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PresentModeKHR, PresentModeKHRAllocator>>
GetSurfacePresentModes2EXT( vk::PhysicalDevice physicalDevice, const vk::PhysicalDeviceSurfaceInfo2KHR& surfaceInfo,
                            PresentModeKHRAllocator& presentModeKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getSurfacePresentModes2EXT( surfaceInfo, presentModeKHRAllocator );
#else
    return s_MockPtr->_GetSurfacePresentModes2EXT( physicalDevice, surfaceInfo, presentModeKHRAllocator );
#endif
}

static vk::Result AcquireDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.acquireDrmDisplayEXT( drmFd, display );
#else
    return s_MockPtr->_AcquireDrmDisplayEXT( physicalDevice, drmFd, display );
#endif
}

static vk::Result AcquireDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.acquireDrmDisplayEXT( drmFd, display );
#else
    return s_MockPtr->_AcquireDrmDisplayEXT( physicalDevice, drmFd, display );
#endif
}

static vk::Result GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId,
                                    vk::DisplayKHR* display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDrmDisplayEXT( drmFd, connectorId, display );
#else
    return s_MockPtr->_GetDrmDisplayEXT( physicalDevice, drmFd, connectorId, display );
#endif
}

static ResultValue<vk::Result, vk::DisplayKHR> GetDrmDisplayEXT( vk::PhysicalDevice physicalDevice, int32_t drmFd,
                                                                 uint32_t connectorId ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDrmDisplayEXT( drmFd, connectorId );
#else
    return s_MockPtr->_GetDrmDisplayEXT( physicalDevice, drmFd, connectorId );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DisplayKHR, Dispatch>>
GetDrmDisplayEXTUnique( vk::PhysicalDevice physicalDevice, int32_t drmFd, uint32_t connectorId ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getDrmDisplayEXTUnique( drmFd, connectorId );
#else
    return s_MockPtr->_GetDrmDisplayEXTUnique( physicalDevice, drmFd, connectorId );
#endif
}

static vk::Result AcquireWinrtDisplayNV( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.acquireWinrtDisplayNV( display );
#else
    return s_MockPtr->_AcquireWinrtDisplayNV( physicalDevice, display );
#endif
}

static vk::Result AcquireWinrtDisplayNV( vk::PhysicalDevice physicalDevice, vk::DisplayKHR display ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.acquireWinrtDisplayNV( display );
#else
    return s_MockPtr->_AcquireWinrtDisplayNV( physicalDevice, display );
#endif
}

static vk::Result GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice, uint32_t deviceRelativeId,
                                     vk::DisplayKHR* pDisplay ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getWinrtDisplayNV( deviceRelativeId, pDisplay );
#else
    return s_MockPtr->_GetWinrtDisplayNV( physicalDevice, deviceRelativeId, pDisplay );
#endif
}

static ResultValue<vk::Result, vk::DisplayKHR> GetWinrtDisplayNV( vk::PhysicalDevice physicalDevice,
                                                                  uint32_t deviceRelativeId ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getWinrtDisplayNV( deviceRelativeId );
#else
    return s_MockPtr->_GetWinrtDisplayNV( physicalDevice, deviceRelativeId );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DisplayKHR, Dispatch>>
GetWinrtDisplayNVUnique( vk::PhysicalDevice physicalDevice, uint32_t deviceRelativeId ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getWinrtDisplayNVUnique( deviceRelativeId );
#else
    return s_MockPtr->_GetWinrtDisplayNVUnique( physicalDevice, deviceRelativeId );
#endif
}

static vk::Result GetOpticalFlowImageFormatsNV( vk::PhysicalDevice physicalDevice,
                                                const vk::OpticalFlowImageFormatInfoNV* pOpticalFlowImageFormatInfo,
                                                uint32_t* pFormatCount,
                                                vk::OpticalFlowImageFormatPropertiesNV* pImageFormatProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getOpticalFlowImageFormatsNV( pOpticalFlowImageFormatInfo, pFormatCount,
                                                        pImageFormatProperties );
#else
    return s_MockPtr->_GetOpticalFlowImageFormatsNV( physicalDevice, pOpticalFlowImageFormatInfo, pFormatCount,
                                                     pImageFormatProperties );
#endif
}

template <typename OpticalFlowImageFormatPropertiesNVAllocator = std::allocator<vk::OpticalFlowImageFormatPropertiesNV>>
static ResultValue<vk::Result,
                   std::vector<vk::OpticalFlowImageFormatPropertiesNV, OpticalFlowImageFormatPropertiesNVAllocator>>
GetOpticalFlowImageFormatsNV( vk::PhysicalDevice physicalDevice,
                              const vk::OpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getOpticalFlowImageFormatsNV( opticalFlowImageFormatInfo );
#else
    return s_MockPtr->_GetOpticalFlowImageFormatsNV( physicalDevice, opticalFlowImageFormatInfo );
#endif
}

template <typename OpticalFlowImageFormatPropertiesNVAllocator = std::allocator<vk::OpticalFlowImageFormatPropertiesNV>,
          typename B1 = OpticalFlowImageFormatPropertiesNVAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, OpticalFlowImageFormatPropertiesNV>::value,
                                  int>::type = 0>
static ResultValue<vk::Result,
                   std::vector<vk::OpticalFlowImageFormatPropertiesNV, OpticalFlowImageFormatPropertiesNVAllocator>>
GetOpticalFlowImageFormatsNV(
        vk::PhysicalDevice physicalDevice, const vk::OpticalFlowImageFormatInfoNV& opticalFlowImageFormatInfo,
        OpticalFlowImageFormatPropertiesNVAllocator& opticalFlowImageFormatPropertiesNVAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getOpticalFlowImageFormatsNV( opticalFlowImageFormatInfo,
                                                        opticalFlowImageFormatPropertiesNVAllocator );
#else
    return s_MockPtr->_GetOpticalFlowImageFormatsNV( physicalDevice, opticalFlowImageFormatInfo,
                                                     opticalFlowImageFormatPropertiesNVAllocator );
#endif
}

static vk::Result GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice, uint32_t* pPropertyCount,
                                                     vk::CooperativeMatrixPropertiesKHR* pProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesKHR( pPropertyCount, pProperties );
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesKHR( physicalDevice, pPropertyCount, pProperties );
#endif
}

template <typename CooperativeMatrixPropertiesKHRAllocator = std::allocator<vk::CooperativeMatrixPropertiesKHR>>
static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR, CooperativeMatrixPropertiesKHRAllocator>>
GetCooperativeMatrixPropertiesKHR( vk::PhysicalDevice physicalDevice, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesKHR();
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesKHR();
#endif
}

template <typename CooperativeMatrixPropertiesKHRAllocator = std::allocator<vk::CooperativeMatrixPropertiesKHR>,
          typename B1 = CooperativeMatrixPropertiesKHRAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, CooperativeMatrixPropertiesKHR>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::CooperativeMatrixPropertiesKHR, CooperativeMatrixPropertiesKHRAllocator>>
GetCooperativeMatrixPropertiesKHR(
        vk::PhysicalDevice physicalDevice,
        CooperativeMatrixPropertiesKHRAllocator& cooperativeMatrixPropertiesKHRAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return physicalDevice.getCooperativeMatrixPropertiesKHR( cooperativeMatrixPropertiesKHRAllocator );
#else
    return s_MockPtr->_GetCooperativeMatrixPropertiesKHR( physicalDevice, cooperativeMatrixPropertiesKHRAllocator );
#endif
}

static void Destroy( vk::Instance instance, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( pAllocator );
#else
    s_MockPtr->_Destroy( instance, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( nullptr );
#else
    s_MockPtr->_Destroy( instance, nullptr );
#endif
}

static vk::Result EnumeratePhysicalDevices( vk::Instance instance, uint32_t* pPhysicalDeviceCount,
                                            vk::PhysicalDevice* pPhysicalDevices ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDevices( pPhysicalDeviceCount, pPhysicalDevices );
#else
    return s_MockPtr->_EnumeratePhysicalDevices( instance, pPhysicalDeviceCount, pPhysicalDevices );
#endif
}

template <typename PhysicalDeviceAllocator = std::allocator<vk::PhysicalDevice>>
static ResultValue<vk::Result, std::vector<vk::PhysicalDevice, PhysicalDeviceAllocator>>
EnumeratePhysicalDevices( vk::Instance instance, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDevices();
#else
    return s_MockPtr->_EnumeratePhysicalDevices();
#endif
}

template <typename PhysicalDeviceAllocator = std::allocator<vk::PhysicalDevice>, typename B1 = PhysicalDeviceAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDevice>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PhysicalDevice, PhysicalDeviceAllocator>>
EnumeratePhysicalDevices( vk::Instance instance, PhysicalDeviceAllocator& physicalDeviceAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDevices( physicalDeviceAllocator );
#else
    return s_MockPtr->_EnumeratePhysicalDevices( instance, physicalDeviceAllocator );
#endif
}

static PFN_vkVoidFunction GetProcAddr( vk::Instance instance, const char* pName ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.getProcAddr( pName );
#else
    return s_MockPtr->_GetProcAddr( instance, pName );
#endif
}

static PFN_vkVoidFunction GetProcAddr( vk::Instance instance, const std::string& name ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.getProcAddr( name );
#else
    return s_MockPtr->_GetProcAddr( instance, name );
#endif
}

static vk::Result
EnumeratePhysicalDeviceGroups( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                               vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroups( pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroups( instance, pPhysicalDeviceGroupCount,
                                                      pPhysicalDeviceGroupProperties );
#endif
}

template <typename PhysicalDeviceGroupPropertiesAllocator = std::allocator<vk::PhysicalDeviceGroupProperties>>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, PhysicalDeviceGroupPropertiesAllocator>>
EnumeratePhysicalDeviceGroups( vk::Instance instance, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroups();
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroups();
#endif
}

template <typename PhysicalDeviceGroupPropertiesAllocator = std::allocator<vk::PhysicalDeviceGroupProperties>,
          typename B1 = PhysicalDeviceGroupPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDeviceGroupProperties>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, PhysicalDeviceGroupPropertiesAllocator>>
EnumeratePhysicalDeviceGroups( vk::Instance instance,
                               PhysicalDeviceGroupPropertiesAllocator& physicalDeviceGroupPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroups( physicalDeviceGroupPropertiesAllocator );
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroups( instance, physicalDeviceGroupPropertiesAllocator );
#endif
}

static void DestroySurfaceKHR( vk::Instance instance, vk::SurfaceKHR surface,
                               const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroySurfaceKHR( surface, pAllocator );
#else
    s_MockPtr->_DestroySurfaceKHR( instance, surface, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::SurfaceKHR surface, const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( surface, pAllocator );
#else
    s_MockPtr->_Destroy( instance, surface, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::SurfaceKHR surface,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( surface, nullptr );
#else
    s_MockPtr->_Destroy( instance, surface, nullptr );
#endif
}

static vk::Result CreateDisplayPlaneSurfaceKHR( vk::Instance instance,
                                                const vk::DisplaySurfaceCreateInfoKHR* pCreateInfo,
                                                const vk::AllocationCallbacks* pAllocator,
                                                vk::SurfaceKHR* pSurface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDisplayPlaneSurfaceKHR( pCreateInfo, pAllocator, pSurface );
#else
    return s_MockPtr->_CreateDisplayPlaneSurfaceKHR( instance, pCreateInfo, pAllocator, pSurface );
#endif
}

static ResultValue<vk::Result, vk::SurfaceKHR>
CreateDisplayPlaneSurfaceKHR( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR& createInfo,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDisplayPlaneSurfaceKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDisplayPlaneSurfaceKHR( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SurfaceKHR, Dispatch>>
CreateDisplayPlaneSurfaceKHRUnique( vk::Instance instance, const vk::DisplaySurfaceCreateInfoKHR& createInfo,
                                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDisplayPlaneSurfaceKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDisplayPlaneSurfaceKHRUnique( instance, createInfo, nullptr );
#endif
}

static vk::Result CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR* pCreateInfo,
                                         const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createWin32SurfaceKHR( pCreateInfo, pAllocator, pSurface );
#else
    return s_MockPtr->_CreateWin32SurfaceKHR( instance, pCreateInfo, pAllocator, pSurface );
#endif
}

static ResultValue<vk::Result, vk::SurfaceKHR>
CreateWin32SurfaceKHR( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR& createInfo,
                       Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createWin32SurfaceKHR( createInfo, nullptr );
#else
    return s_MockPtr->_CreateWin32SurfaceKHR( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SurfaceKHR, Dispatch>>
CreateWin32SurfaceKHRUnique( vk::Instance instance, const vk::Win32SurfaceCreateInfoKHR& createInfo,
                             Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createWin32SurfaceKHRUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateWin32SurfaceKHRUnique( instance, createInfo, nullptr );
#endif
}

static vk::Result CreateDebugReportCallbackEXT( vk::Instance instance,
                                                const vk::DebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                const vk::AllocationCallbacks* pAllocator,
                                                vk::DebugReportCallbackEXT* pCallback ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugReportCallbackEXT( pCreateInfo, pAllocator, pCallback );
#else
    return s_MockPtr->_CreateDebugReportCallbackEXT( instance, pCreateInfo, pAllocator, pCallback );
#endif
}

static ResultValue<vk::Result, vk::DebugReportCallbackEXT>
CreateDebugReportCallbackEXT( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT& createInfo,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugReportCallbackEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDebugReportCallbackEXT( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DebugReportCallbackEXT, Dispatch>>
CreateDebugReportCallbackEXTUnique( vk::Instance instance, const vk::DebugReportCallbackCreateInfoEXT& createInfo,
                                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugReportCallbackEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDebugReportCallbackEXTUnique( instance, createInfo, nullptr );
#endif
}

static void DestroyDebugReportCallbackEXT( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                                           const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroyDebugReportCallbackEXT( callback, pAllocator );
#else
    s_MockPtr->_DestroyDebugReportCallbackEXT( instance, callback, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( callback, pAllocator );
#else
    s_MockPtr->_Destroy( instance, callback, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::DebugReportCallbackEXT callback,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( callback, nullptr );
#else
    s_MockPtr->_Destroy( instance, callback, nullptr );
#endif
}

static void DebugReportMessageEXT( vk::Instance instance, vk::DebugReportFlagsEXT flags,
                                   vk::DebugReportObjectTypeEXT objectType_, uint64_t object, size_t location,
                                   int32_t messageCode, const char* pLayerPrefix, const char* pMessage ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.debugReportMessageEXT( flags, objectType_, object, location, messageCode, pLayerPrefix, pMessage );
#else
    s_MockPtr->_DebugReportMessageEXT( instance, flags, objectType_, object, location, messageCode, pLayerPrefix,
                                       pMessage );
#endif
}

static void DebugReportMessageEXT( vk::Instance instance, vk::DebugReportFlagsEXT flags,
                                   vk::DebugReportObjectTypeEXT objectType_, uint64_t object, size_t location,
                                   int32_t messageCode, const std::string& layerPrefix,
                                   const std::string& message ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.debugReportMessageEXT( flags, objectType_, object, location, messageCode, layerPrefix, message );
#else
    s_MockPtr->_DebugReportMessageEXT( instance, flags, objectType_, object, location, messageCode, layerPrefix,
                                       message );
#endif
}

static vk::Result
EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance, uint32_t* pPhysicalDeviceGroupCount,
                                  vk::PhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroupsKHR( pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties );
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroupsKHR( instance, pPhysicalDeviceGroupCount,
                                                         pPhysicalDeviceGroupProperties );
#endif
}

template <typename PhysicalDeviceGroupPropertiesAllocator = std::allocator<vk::PhysicalDeviceGroupProperties>>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, PhysicalDeviceGroupPropertiesAllocator>>
EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance, ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroupsKHR();
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroupsKHR();
#endif
}

template <typename PhysicalDeviceGroupPropertiesAllocator = std::allocator<vk::PhysicalDeviceGroupProperties>,
          typename B1 = PhysicalDeviceGroupPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, PhysicalDeviceGroupProperties>::value,
                                  int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::PhysicalDeviceGroupProperties, PhysicalDeviceGroupPropertiesAllocator>>
EnumeratePhysicalDeviceGroupsKHR( vk::Instance instance,
                                  PhysicalDeviceGroupPropertiesAllocator& physicalDeviceGroupPropertiesAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumeratePhysicalDeviceGroupsKHR( physicalDeviceGroupPropertiesAllocator );
#else
    return s_MockPtr->_EnumeratePhysicalDeviceGroupsKHR( instance, physicalDeviceGroupPropertiesAllocator );
#endif
}

static vk::Result CreateDebugUtilsMessengerEXT( vk::Instance instance,
                                                const vk::DebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                const vk::AllocationCallbacks* pAllocator,
                                                vk::DebugUtilsMessengerEXT* pMessenger ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugUtilsMessengerEXT( pCreateInfo, pAllocator, pMessenger );
#else
    return s_MockPtr->_CreateDebugUtilsMessengerEXT( instance, pCreateInfo, pAllocator, pMessenger );
#endif
}

static ResultValue<vk::Result, vk::DebugUtilsMessengerEXT>
CreateDebugUtilsMessengerEXT( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT& createInfo,
                              Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugUtilsMessengerEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDebugUtilsMessengerEXT( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::DebugUtilsMessengerEXT, Dispatch>>
CreateDebugUtilsMessengerEXTUnique( vk::Instance instance, const vk::DebugUtilsMessengerCreateInfoEXT& createInfo,
                                    Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createDebugUtilsMessengerEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateDebugUtilsMessengerEXTUnique( instance, createInfo, nullptr );
#endif
}

static void DestroyDebugUtilsMessengerEXT( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                                           const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroyDebugUtilsMessengerEXT( messenger, pAllocator );
#else
    s_MockPtr->_DestroyDebugUtilsMessengerEXT( instance, messenger, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                     const vk::AllocationCallbacks* pAllocator ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( messenger, pAllocator );
#else
    s_MockPtr->_Destroy( instance, messenger, pAllocator );
#endif
}

static void Destroy( vk::Instance instance, vk::DebugUtilsMessengerEXT messenger,
                     Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.destroy( messenger, nullptr );
#else
    s_MockPtr->_Destroy( instance, messenger, nullptr );
#endif
}

static void SubmitDebugUtilsMessageEXT( vk::Instance instance, vk::DebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                        vk::DebugUtilsMessageTypeFlagsEXT messageTypes,
                                        const vk::DebugUtilsMessengerCallbackDataEXT* pCallbackData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.submitDebugUtilsMessageEXT( messageSeverity, messageTypes, pCallbackData );
#else
    s_MockPtr->_SubmitDebugUtilsMessageEXT( instance, messageSeverity, messageTypes, pCallbackData );
#endif
}

static void SubmitDebugUtilsMessageEXT( vk::Instance instance, vk::DebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                        vk::DebugUtilsMessageTypeFlagsEXT messageTypes,
                                        const vk::DebugUtilsMessengerCallbackDataEXT& callbackData ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    instance.submitDebugUtilsMessageEXT( messageSeverity, messageTypes, callbackData );
#else
    s_MockPtr->_SubmitDebugUtilsMessageEXT( instance, messageSeverity, messageTypes, callbackData );
#endif
}

static vk::Result CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT* pCreateInfo,
                                            const vk::AllocationCallbacks* pAllocator, vk::SurfaceKHR* pSurface ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createHeadlessSurfaceEXT( pCreateInfo, pAllocator, pSurface );
#else
    return s_MockPtr->_CreateHeadlessSurfaceEXT( instance, pCreateInfo, pAllocator, pSurface );
#endif
}

static ResultValue<vk::Result, vk::SurfaceKHR>
CreateHeadlessSurfaceEXT( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT& createInfo,
                          Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createHeadlessSurfaceEXT( createInfo, nullptr );
#else
    return s_MockPtr->_CreateHeadlessSurfaceEXT( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::SurfaceKHR, Dispatch>>
CreateHeadlessSurfaceEXTUnique( vk::Instance instance, const vk::HeadlessSurfaceCreateInfoEXT& createInfo,
                                Optional<const vk::AllocationCallbacks> allocator = nullptr ) const
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createHeadlessSurfaceEXTUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateHeadlessSurfaceEXTUnique( instance, createInfo, nullptr );
#endif
}

static vk::Result CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo* pCreateInfo,
                                  const vk::AllocationCallbacks* pAllocator, vk::Instance* pInstance )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createInstance( pCreateInfo, pAllocator, pInstance );
#else
    return s_MockPtr->_CreateInstance( instance, pCreateInfo, pAllocator, pInstance );
#endif
}

static ResultValue<vk::Result, vk::Instance>
CreateInstance( vk::Instance instance, const vk::InstanceCreateInfo& createInfo,
                Optional<const vk::AllocationCallbacks> allocator = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createInstance( createInfo, nullptr );
#else
    return s_MockPtr->_CreateInstance( instance, createInfo, nullptr );
#endif
}

static ResultValue<vk::Result, UniqueHandle<vk::Instance, Dispatch>>
CreateInstanceUnique( vk::Instance instance, const vk::InstanceCreateInfo& createInfo,
                      Optional<const vk::AllocationCallbacks> allocator = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.createInstanceUnique( createInfo, nullptr );
#else
    return s_MockPtr->_CreateInstanceUnique( instance, createInfo, nullptr );
#endif
}

static vk::Result EnumerateInstanceExtensionProperties( vk::Instance instance, const char* pLayerName,
                                                        uint32_t* pPropertyCount, vk::ExtensionProperties* pProperties )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceExtensionProperties( pLayerName, pPropertyCount, pProperties );
#else
    return s_MockPtr->_EnumerateInstanceExtensionProperties( instance, pLayerName, pPropertyCount, pProperties );
#endif
}

template <typename ExtensionPropertiesAllocator = std::allocator<vk::ExtensionProperties>>
static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, ExtensionPropertiesAllocator>>
EnumerateInstanceExtensionProperties( vk::Instance instance, Optional<const std::string> layerName = nullptr )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceExtensionProperties( nullptr );
#else
    return s_MockPtr->_EnumerateInstanceExtensionProperties( instance, nullptr );
#endif
}

template <typename ExtensionPropertiesAllocator = std::allocator<vk::ExtensionProperties>,
          typename B1 = ExtensionPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, ExtensionProperties>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::ExtensionProperties, ExtensionPropertiesAllocator>>
EnumerateInstanceExtensionProperties( vk::Instance instance, Optional<const std::string> layerName,
                                      ExtensionPropertiesAllocator& extensionPropertiesAllocator )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceExtensionProperties( layerName, extensionPropertiesAllocator );
#else
    return s_MockPtr->_EnumerateInstanceExtensionProperties( instance, layerName, extensionPropertiesAllocator );
#endif
}

static vk::Result EnumerateInstanceLayerProperties( vk::Instance instance, uint32_t* pPropertyCount,
                                                    vk::LayerProperties* pProperties )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceLayerProperties( pPropertyCount, pProperties );
#else
    return s_MockPtr->_EnumerateInstanceLayerProperties( instance, pPropertyCount, pProperties );
#endif
}

template <typename LayerPropertiesAllocator = std::allocator<vk::LayerProperties>>
static ResultValue<vk::Result, std::vector<vk::LayerProperties, LayerPropertiesAllocator>>
EnumerateInstanceLayerProperties( vk::Instance instance, )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceLayerProperties();
#else
    return s_MockPtr->_EnumerateInstanceLayerProperties();
#endif
}

template <typename LayerPropertiesAllocator = std::allocator<vk::LayerProperties>,
          typename B1 = LayerPropertiesAllocator,
          typename std::enable_if<std::is_same<typename B1::value_type, LayerProperties>::value, int>::type = 0>
static ResultValue<vk::Result, std::vector<vk::LayerProperties, LayerPropertiesAllocator>>
EnumerateInstanceLayerProperties( vk::Instance instance, LayerPropertiesAllocator& layerPropertiesAllocator )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceLayerProperties( layerPropertiesAllocator );
#else
    return s_MockPtr->_EnumerateInstanceLayerProperties( instance, layerPropertiesAllocator );
#endif
}

static vk::Result EnumerateInstanceVersion( vk::Instance instance, uint32_t* pApiVersion )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceVersion( pApiVersion );
#else
    return s_MockPtr->_EnumerateInstanceVersion( instance, pApiVersion );
#endif
}

static ResultValue<vk::Result, uint32_t> EnumerateInstanceVersion( vk::Instance instance )
{
#if FIKO_ENGINE_VK_INTERFACE_ENABLE_TESTING == 0
    return instance.enumerateInstanceVersion();
#else
    return s_MockPtr->_EnumerateInstanceVersion();
#endif
}
