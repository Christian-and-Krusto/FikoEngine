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
 * Image class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "Image.hpp"
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
Image Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    template <typename T>
    ResultValueType<ImageStatus> Image<T>::Init( vk::PhysicalDevice physicalDevice, vk::Device device,
                                                 ImageSpec imageSpec )
    {
        m_ImageSpec = imageSpec;
        vk::FormatProperties formatProperties = vkInterface::GetFormatProperties( physicalDevice, imageSpec.format );

        auto tiling = ChooseImageTiling( formatProperties );
        if ( ImageStatus::Success != tiling ) { return ResultValueType{ tiling.status }; }

        vk::ImageUsageFlags usageFlags;
        vk::ImageAspectFlags aspectFlags;

        auto imageFlagsStatus = GetImageFlags( imageSpec.type, usageFlags, aspectFlags );
        if ( ImageStatus::Success != imageFlagsStatus ) { return imageFlagsStatus; }

        vk::ImageCreateInfo imageCreateInfo( vk::ImageCreateFlags(), vk::ImageType::e2D, imageSpec.format,
                                             vk::Extent3D( imageSpec.extent, 1 ), 1, 1, vk::SampleCountFlagBits::e1,
                                             tiling, usageFlags );

        auto imageCreateStatus = vkInterface::CreateImage( device, imageCreateInfo );

        if ( vk::Result::eSuccess != imageCreateStatus )
        {
            LOG_ERROR( "Could Not Create Image!" );
            return ResultValueType{ ImageStatus::Fail };
        }
        m_Image = imageCreateStatus;

        auto memoryProperties = vkInterface::GetMemoryProperties( physicalDevice ).value;
        auto memoryRequirements = vkInterface::GetImageMemoryRequirements( device, m_Image ).value;

        auto allocateBufferStatus = m_MemoryBuffer.InitMemoryBuffer( physicalDevice, device, memoryProperties, memoryRequirements,
                                                      ( vk::MemoryPropertyFlagBits::eDeviceLocal ) );

        if ( BufferStatus::Success != allocateBufferStatus )
        {
            return BufferStatusToImageStatus( allocateBufferStatus );
        }

        auto bindStatus = m_MemoryBuffer.BindImage( device, m_Image );
        if ( BufferStatus::Bound != bindStatus ) { return BufferStatusToImageStatus( bindStatus ); }

        auto imageViewStatus = CreateImageView( device, aspectFlags );
        if ( ImageStatus::Success != imageViewStatus ) { return { imageViewStatus }; }

        return ResultValueType{ ImageStatus::Success };
    }

    template <typename T>
    ResultValue<ImageStatus, ImageSpec> Image<T>::GetImageSpec()
    {
        return ResultValue<ImageStatus, ImageSpec>{ {}, m_ImageSpec };
    }

    template <typename T>
    ResultValue<ImageStatus, vk::Image> Image<T>::GetImage()
    {
        if ( VK_NULL_HANDLE != m_Image ) { return ResultValue<ImageStatus, vk::Image>{ ImageStatus::Fail }; }
        return ResultValue<ImageStatus, vk::Image>{ ImageStatus::Success, m_Image };
    }

    template <typename T>
    ResultValue<ImageStatus, vk::ImageView> Image<T>::GetImageView()
    {
        if ( VK_NULL_HANDLE != m_ImageView ) { return ResultValue<ImageStatus, vk::ImageView>{ ImageStatus::Fail }; }
        return ResultValue<ImageStatus, vk::ImageView>{ ImageStatus::Success, m_ImageView };
    }

    template <typename T>
    ResultValueType<ImageStatus> Image<T>::Destroy( vk::Device device )
    {
        if ( VK_NULL_HANDLE != m_Image ) { return ResultValueType{ ImageStatus::Fail }; }
        device.destroyImage( m_Image );
        if ( VK_NULL_HANDLE != m_ImageView ) { return ResultValueType{ ImageStatus::Fail }; }
        device.destroyImageView( m_ImageView );

        auto destroyStatus = m_MemoryBuffer.DestroyMemoryBuffer( device );
        if ( BufferStatus::Success != destroyStatus ) { return BufferStatusToImageStatus( destroyStatus ); }

        return { ImageStatus::Success };
    }

    template<typename T>
    inline T& Image<T>::GetMemoryBuffer()
    {
        return m_MemoryBuffer;
    }

    template <typename T>
    ResultValue<ImageStatus, vk::ImageTiling> Image<T>::ChooseImageTiling( vk::FormatProperties& formatProperties )
    {
        vk::ImageTiling tiling;

        if ( formatProperties.linearTilingFeatures & vk::FormatFeatureFlagBits::eDepthStencilAttachment )
        {
            tiling = vk::ImageTiling::eLinear;
        }
        else if ( formatProperties.optimalTilingFeatures & vk::FormatFeatureFlagBits::eDepthStencilAttachment )
        {
            tiling = vk::ImageTiling::eOptimal;
        }
        else
        {
            LOG_ERROR( "DepthStencilAttachment is not supported for D16Unorm depth format." );
            return ResultValue<ImageStatus, vk::ImageTiling>{ ImageStatus::CanNotChooseTiling };
        }
        return ResultValue<ImageStatus, vk::ImageTiling>{ ImageStatus::Success, tiling };
    }

    template <typename T>
    ResultValueType<ImageStatus> Image<T>::GetImageFlags( ImageType type, vk::ImageUsageFlags& usageFlags,
                                                       vk::ImageAspectFlags& aspectFlags )
    {
        switch ( type )
        {
            case ImageType::Depth:
                usageFlags = vk::ImageUsageFlagBits::eDepthStencilAttachment;
                aspectFlags = vk::ImageAspectFlagBits::eDepth;
                break;
            default:
                LOG_ERROR( "Wrong Image Type" );
                return ResultValueType{ ImageStatus::CanNotChooseImageFlags };
                break;
        }
        return ResultValueType{ ImageStatus::Success };
    }

    template <typename T>
    ResultValueType<ImageStatus> Image<T>::CreateImageView( vk::Device device, vk::ImageAspectFlags aspectFlags )
    {

        vk::ImageViewCreateInfo imageViewCreateInfo( vk::ImageViewCreateFlags(), m_Image, vk::ImageViewType::e2D,
                                                     m_ImageSpec.format, {}, { aspectFlags, 0, 1, 0, 1 } );

        auto imageViewStatus = vkInterface::CreateImageView( device, imageViewCreateInfo );
        if ( vk::Result::eSuccess != imageViewStatus )
        {
            LOG_ERROR( "Can Not Create Image View!" );
            return { ImageStatus::CanNotCreateImageView };
        }
        m_ImageView = imageViewStatus.value;

        return { ImageStatus::Success };
    }

    template <typename T>
    ImageStatus Image<T>::BufferStatusToImageStatus( BufferStatus status )
    {
        switch ( status )
        {
            case BufferStatus::Fail:
                return ImageStatus::Fail;
                break;
            case BufferStatus::CanNotFindMemoryType:
                return ImageStatus::CanNotFindMemoryType;
                break;
            case BufferStatus::CanNotAllocateMemory:
                return ImageStatus::CanNotAllocateMemory;
                break;
            case BufferStatus::CanNotBindMemory:
                return ImageStatus::CanNotBindImageMemory;
                break;
            case BufferStatus::CanNotMapMemory:
                return ImageStatus::CanNotMapImageMemory;
                break;
            case BufferStatus::Bound:
                return ImageStatus::Success;
            case BufferStatus::Success:
                return ImageStatus::Success;
                break;
            default:
                return ImageStatus::Fail;
                break;
        }
    }

}// namespace FikoEngine