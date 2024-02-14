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
 * Window class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "RendererSpec.hpp"
#include <Core/Result.hpp>
#include <GLFW/glfw3.h>
#include <vector>
#include <vulkan/vulkan.hpp>


/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
enum class WindowStatus
{
    Success,
    Fail,
    Created,
    Initialized,
    Not_Initialized,
    Destroyed,
    Surface_Created,
    Surface_Destroyed
};

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class Window
    {
    public:
        Window() = default;
        ~Window();

    public:
        Result<WindowStatus> Init( RendererSpec& rendererSpec );
        Result<WindowStatus> CreateSurface( vk::Instance instance );
        Result<WindowStatus> DestroySurface( vk::Instance instance );
        Result<WindowStatus,vk::SurfaceKHR> GetSurface();

    public:
        static Result<WindowStatus, Window*> Create( RendererSpec& rendererSpec );
        static Result<WindowStatus> Destroy( Window* window );

        static Result<bool, std::vector<std::string>> GetRequiredExtensions();

    private: 
        
        RendererSpec m_RendererSpec;
        GLFWwindow* m_WindowPtr;
        vk::SurfaceKHR m_Surface;

    };
}// namespace FikoEngine