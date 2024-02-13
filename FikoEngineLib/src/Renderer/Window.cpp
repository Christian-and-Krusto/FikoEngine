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
 * Window class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "Window.hpp"
#include <Core/Log.hpp>

#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

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
Window Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    Result<WindowStatus> Window::Init( RendererSpec& rendererSpec )
    {
        glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );
        glfwWindowHint( GLFW_RESIZABLE, GLFW_FALSE );

        m_WindowPtr = glfwCreateWindow( rendererSpec.width, rendererSpec.height, rendererSpec.AppName.data(), nullptr,
                                        nullptr );


        if ( !glfwVulkanSupported() )
        {
            LOG_ERROR( "Vulkan API is not supported" );
            return { WindowStatus::Fail };
        }
        else { LOG_INFO( "Found support for Vulkan API" ); }

        LOG_INFO( "Created Window" );
        return { WindowStatus::Created };
    }

    Window::~Window() { LOG_INFO( "Destroyed Window" ); }

    Result<WindowStatus, Window*> Window::Create( RendererSpec& rendererSpec )
    {
        Window* window = new Window();
        auto result = window->Init( rendererSpec );

        return { result.status, window };
    }

    Result<WindowStatus> Window::Destroy( Window* window )
    {
        if ( nullptr == window ) { return { WindowStatus::Not_Initialized }; }
        else
        {
            if ( nullptr != window->m_WindowPtr ) { glfwDestroyWindow( window->m_WindowPtr ); }
            delete window;
            return { WindowStatus::Destroyed };
        }
    }

    Result<bool, std::vector<std::string>> Window::GetRequiredExtensions()
    {
        uint32_t count;
        const char** extensions = glfwGetRequiredInstanceExtensions( &count );

        std::vector<std::string> output;

        LOG_INFO( "Required instance extensions:" );
        for ( uint32_t i = 0; i < count; i++ )
        {
            LOG_INFO( "    " + std::string( extensions[ i ] ) );
            output.push_back( std::string( extensions[ i ] ) );
        }

        return { true, output };
    }
}// namespace FikoEngine