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
#include <vulkan/vulkan.hpp>
#include <Core/Result.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class ImageType{
        None,
        Depth,
        Color
    };
    enum class ImageStatus
    {
        Fail,
        Success
    };
}

/***********************************************************************************************************************
Struct definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    struct ImageSpec
    {
        ImageType type;
        vk::Format format;
        vk::Extent2D extent;
    };
}
/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class Image
    {
    public:
        Image() = default;
        ~Image();

    public:
        Result<ImageStatus> Init( vk::PhysicalDevice physicalDevice, vk::Device device, ImageSpec imageSpec );
        Result<ImageStatus, vk::Image> GetImage();
        Result<ImageStatus, vk::ImageView> GetImageView();
        Result<ImageStatus, ImageSpec> GetImageSpec();
        Result<ImageStatus> Destroy(vk::Device device);

    private:
        vk::Image m_Image;
        vk::ImageView m_ImageView;
        vk::DeviceMemory m_Memory;

        ImageSpec m_ImageSpec;
    };
}// namespace FikoEngine