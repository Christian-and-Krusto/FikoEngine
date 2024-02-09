#include "Window.hpp"
#include <Core/Log.hpp>

#include <GLFW/glfw3.h>

namespace FikoEngine
{

    Result<WindowStatus> Window::Init( RendererSpec& rendererSpec ) { 
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_WindowPtr = glfwCreateWindow( rendererSpec.width, rendererSpec.height, rendererSpec.AppName.data(), nullptr,
                                        nullptr );
        LOG_INFO("Created Window");
        return {WindowStatus::Created};
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
            if(nullptr != window->m_WindowPtr)
            {
                glfwDestroyWindow(window->m_WindowPtr);
            }
            delete window;
            return { WindowStatus::Destroyed };
        }
    }

}// namespace FikoEngine