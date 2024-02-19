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
Image Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    Image::~Image() {}

    Result<ImageStatus> Image::Init( vk::PhysicalDevice physicalDevice, vk::Device device, ImageSpec imageSpec )
    {
        m_ImageSpec = imageSpec;
        vk::FormatProperties formatProperties = physicalDevice.getFormatProperties( imageSpec.format );

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
            return { ImageStatus::Fail };
        }

        vk::ImageUsageFlags usageFlags;
        vk::ImageAspectFlags aspectFlags;
        switch ( imageSpec.type )
        {
            case ImageType::Depth:
                usageFlags = vk::ImageUsageFlagBits::eDepthStencilAttachment;
                aspectFlags = vk::ImageAspectFlagBits::eDepth;
                break;
            default:
                LOG_ERROR( "Wrong Image Type" );
                return { ImageStatus::Fail };
                break;
        }

        vk::ImageCreateInfo imageCreateInfo( vk::ImageCreateFlags(), vk::ImageType::e2D, imageSpec.format,
                                             vk::Extent3D( imageSpec.extent, 1 ), 1, 1, vk::SampleCountFlagBits::e1,
                                             tiling, usageFlags );

        auto imageCreateStatus = device.createImage( imageCreateInfo );

        if ( vk::Result::eSuccess != imageCreateStatus.result )
        {
            LOG_ERROR( "Could Not Create Image!" );
            return { ImageStatus::Fail };
        }
        m_Image = imageCreateStatus.value;

        vk::PhysicalDeviceMemoryProperties memoryProperties = physicalDevice.getMemoryProperties();
        vk::MemoryRequirements memoryRequirements = device.getImageMemoryRequirements( m_Image );
        uint32_t typeBits = memoryRequirements.memoryTypeBits;
        uint32_t typeIndex = uint32_t( ~0 );
        for ( uint32_t i = 0; i < memoryProperties.memoryTypeCount; i++ )
        {
            if ( ( typeBits & 1 ) &&
                 ( ( memoryProperties.memoryTypes[ i ].propertyFlags & vk::MemoryPropertyFlagBits::eDeviceLocal ) ==
                   vk::MemoryPropertyFlagBits::eDeviceLocal ) )
            {
                typeIndex = i;
                break;
            }
            typeBits >>= 1;
        }

        if ( typeIndex == uint32_t( ~0 ) )
        {
            LOG_ERROR( "Can Not Find Correct Memory Type" );
            return { ImageStatus::Fail };
        }

        auto depthMemoryStatus = device.allocateMemory( vk::MemoryAllocateInfo( memoryRequirements.size, typeIndex ) );
        if ( vk::Result::eSuccess != depthMemoryStatus.result )
        {
            LOG_ERROR( "Can Not Allocate Image Memory!" );
            return { ImageStatus::Fail };
        }
        m_Memory = depthMemoryStatus.value;

        auto bindStatus = device.bindImageMemory( m_Image, m_Memory, 0 );
        if ( vk::Result::eSuccess != bindStatus )
        {
            LOG_ERROR( "Can Not Bind Image Memory!" );
            return { ImageStatus::Fail };
        }

        auto imageViewStatus = device.createImageView(
                vk::ImageViewCreateInfo( vk::ImageViewCreateFlags(), m_Image, vk::ImageViewType::e2D, imageSpec.format,
                                         {}, { aspectFlags, 0, 1, 0, 1 } ) );
        if ( vk::Result::eSuccess != imageViewStatus.result )
        {
            LOG_ERROR( "Can Not Create Image View!" );
            return { ImageStatus::Fail };
        }
        m_ImageView = imageViewStatus.value;

        return { ImageStatus::Fail };
    }

    Result<ImageStatus, ImageSpec> Image::GetImageSpec() { return { {}, m_ImageSpec }; }

    Result<ImageStatus, vk::Image> Image::GetImage()
    {
        if ( VK_NULL_HANDLE != m_Image ) { return { ImageStatus::Fail }; }
        return { ImageStatus::Success, m_Image };
    }

    Result<ImageStatus, vk::ImageView> Image::GetImageView()
    {
        if ( VK_NULL_HANDLE != m_ImageView ) { return { ImageStatus::Fail }; }
        return { ImageStatus::Success, m_ImageView };
    }

    Result<ImageStatus> Image::Destroy( vk::Device device )
    {
        if ( VK_NULL_HANDLE != m_Image ) { return { ImageStatus::Fail }; }
        device.destroyImage( m_Image );
        if ( VK_NULL_HANDLE != m_ImageView ) { return { ImageStatus::Fail }; }
        device.destroyImageView( m_ImageView );
        if ( VK_NULL_HANDLE != m_Memory ) { return { ImageStatus::Fail }; }
        device.freeMemory( m_Memory );

        return { ImageStatus::Success };
    }

}// namespace FikoEngine