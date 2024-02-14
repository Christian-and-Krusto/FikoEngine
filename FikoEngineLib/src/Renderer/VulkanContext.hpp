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
 * VulkanInstance class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "CommandPool.hpp"
#include "VulkanSpec.hpp"


#include <Core/Result.hpp>
#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class VulkanContextStatus
    {
        Fail,
        Created,
        Destroyed
    };
    enum class VulkanDeviceStatus
    {
        Fail,
        Created,
        Destroyed
    };
    enum class VulkanPhysicalDeviceStatus
    {
        Unknown,
        Selected,
        Not_Found
    };
    enum class VulkanInstanceStatus
    {
        Success,
        Fail,
        Created,
        Destroyed
    };
    enum class VulkanQueueFamilyStatus
    {
        Found,
        Not_Found,
    };
}// namespace FikoEngine

/***********************************************************************************************************************
Structure definitions
***********************************************************************************************************************/

namespace FikoEngine
{
    class Window;

    class VulkanContext
    {
    public:
        VulkanContext() = default;
        VulkanContext( VulkanSpec spec, Window* windowPtr );

        Result<VulkanInstanceStatus> CreateInstance();
        Result<VulkanPhysicalDeviceStatus> SelectPhysicalDevice();
        Result<VulkanDeviceStatus> CreateDevice();
        Result<VulkanQueueFamilyStatus> SelectQueueFamily();

    private:
        Window* m_WindowPtr{};
        VulkanSpec m_Spec{};
        vk::Instance m_Instance{};
        vk::PhysicalDevice m_PhysicalDevice{};
        vk::Device m_Device{};
        vk::SurfaceKHR m_Surface{};
        CommandPool* m_CommandPool{};
        uint32_t m_GraphicsQueueIndex{};
        uint32_t m_PresentQueueIndex{};

    public:
        static Result<VulkanContextStatus> Create( VulkanSpec spec, Window* windowPtr );
        static Result<VulkanContextStatus> Destroy();
        static VulkanContext* Get();

    private:
        static VulkanContext* s_VulkanContext;
    };
}// namespace FikoEngine