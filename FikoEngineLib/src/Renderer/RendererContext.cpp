#include "RendererContext.hpp"
#include <Core/Log.hpp>
#include <GLFW/glfw3.h>

FikoEngine::RendererContext* FikoEngine::RendererContext::s_RendererContext = nullptr;

namespace FikoEngine
{
    RendererContext::RendererContext() {}

    RendererContext::RendererContext( RendererSpec& rendererSpec ) { Init( rendererSpec ); }

    RendererContext::~RendererContext() { LOG_INFO( "Destroyed RendererContext" ); }

    Result<RendererContextStatus> RendererContext::Init( RendererSpec& rendererSpec )
    {
        glfwInit();
        LOG_INFO( "Created RendererContext" );
        auto result = Window::Create( rendererSpec );
        uint32_t tries = 0, maxTries = 3;
        while ( result.status != WindowStatus::Created && tries < maxTries )
        {
            result = Window::Create( rendererSpec );
            tries++;
        }

        if ( result.status == WindowStatus::Created )
        {
            m_Window = result.returnValue;
            return { RendererContextStatus::Initialized };
        }
        else { return { RendererContextStatus::Fail }; }
    }

    Result<RendererContextStatus> RendererContext::Create( RendererSpec& rendererSpec )
    {
        if ( nullptr == RendererContext::GetRenderer() )
        {
            RendererContext::s_RendererContext = new RendererContext();
            auto result = RendererContext::s_RendererContext->Init( rendererSpec );

            uint32_t tries = 0, maxTries = 3;
            while ( result.status != RendererContextStatus::Initialized && tries < maxTries )
            {
                result = RendererContext::s_RendererContext->Init( rendererSpec );
                tries++;
            }

            if ( result.status == RendererContextStatus::Initialized )
            {
                return { RendererContextStatus::Initialized };
            }
            else { return { RendererContextStatus::Fail }; }
        }
        return { RendererContextStatus::Not_Initialized };
    }

    Result<RendererContextStatus> RendererContext::Destroy()
    {
        Window::Destroy( RendererContext::GetRenderer()->m_Window );
        glfwTerminate();
        if ( nullptr != RendererContext::GetRenderer() )
        {
            delete RendererContext::s_RendererContext;
            return { RendererContextStatus::Destroyed };
        }
        return { RendererContextStatus::Not_Initialized };
    }

    RendererSpec RendererContext::GetRendererSpec() { return RendererContext::s_RendererContext->m_RendererSpec; }

    RendererContext* RendererContext::GetRenderer() { return RendererContext::s_RendererContext; }
}// namespace FikoEngine