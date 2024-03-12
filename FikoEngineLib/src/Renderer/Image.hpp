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
 * Image class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <Core/Result.hpp>
#include <Core/VulkanInterface.hpp>
#include <Renderer/MemoryBuffer.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class ImageType
    {
        None,
        Depth,
        Color
    };
    enum class ImageStatus
    {
        Fail,
        CanNotChooseTiling,
        CanNotChooseImageFlags,
        CanNotFindMemoryType,
        CanNotAllocateMemory,
        CanNotBindImageMemory,
        CanNotMapImageMemory,
        CanNotCreateImageView,
        Success
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    struct ImageSpec {
        ImageType type;
        vk::Format format;
        vk::Extent2D extent;
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    template< typename T = MemoryBuffer>
    class Image
    {
    public:
        Image() = default;
        ~Image() = default;

    public:
        ResultValueType<ImageStatus> Init( vk::PhysicalDevice physicalDevice, vk::Device device, ImageSpec imageSpec );
        ResultValue<ImageStatus, vk::Image> GetImage();
        ResultValue<ImageStatus, vk::ImageView> GetImageView();
        ResultValue<ImageStatus, ImageSpec> GetImageSpec();
        ResultValueType<ImageStatus> Destroy( vk::Device device );
        T& GetMemoryBuffer();
        
    private:
        ResultValueType<ImageStatus> CreateImageView( vk::Device device, vk::ImageAspectFlags aspectFlags);

    private:
        virtual ResultValue<ImageStatus, vk::ImageTiling> ChooseImageTiling( vk::FormatProperties& formatProperties );
        virtual ResultValueType<ImageStatus> GetImageFlags( ImageType type, vk::ImageUsageFlags& usageFlags,
                                                        vk::ImageAspectFlags& aspectFlags );

    private:
        static ImageStatus BufferStatusToImageStatus(BufferStatus status);
        
    private:
        vk::Image m_Image;
        vk::ImageView m_ImageView;
        ImageSpec m_ImageSpec;
        T m_MemoryBuffer;
        
    };
}// namespace FikoEngine

#include "Image_impl.hpp"