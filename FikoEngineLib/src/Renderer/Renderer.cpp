#include "Renderer.hpp"
#include "RendererContext.hpp"
#include <Core/Log.hpp>

FikoEngine::Renderer* FikoEngine::Renderer::s_Renderer = nullptr;

namespace FikoEngine
{
    Renderer::Renderer( RendererSpec& rendererSpec ){ Init( rendererSpec ); }

    Renderer::~Renderer()
    {
        LOG_INFO( "Destroyed Renderer" );
    }

    Result<RendererStatus> Renderer::Init( RendererSpec& rendererSpec )
    {
        auto result = RendererContext::Create( rendererSpec );

        uint32_t tries = 0, maxTries = 3;
        while ( result.status != RendererContextStatus::Initialized && tries < maxTries )
        {
            result = RendererContext::Create( rendererSpec );
            tries++;
        }

        if ( result.status == RendererContextStatus::Initialized )
        {
            LOG_INFO( "Created Renderer" );
            return { RendererStatus::Initialized };
        }
        else { return { RendererStatus::Fail }; }
    }

    Result<RendererStatus> Renderer::Create( RendererSpec& rendererSpec )
    {
        if ( nullptr == Renderer::GetRenderer() )
        {
            Renderer::s_Renderer = new Renderer();
            return Renderer::s_Renderer->Init( rendererSpec );
        }
        return { RendererStatus::Fail };
    }

    Result<RendererStatus> Renderer::Destroy()
    {
        if ( nullptr != Renderer::GetRenderer() )
        {
            auto result = RendererContext::Destroy();
            uint32_t tries = 0, maxTries = 3;
            while ( result.status != RendererContextStatus::Destroyed && tries < maxTries )
            {
                result = RendererContext::Destroy();
                tries++;
            }
            if ( result.status == RendererContextStatus::Destroyed )
            {
                delete Renderer::s_Renderer;
                return { RendererStatus::Destroyed };
            }

            return { RendererStatus::Fail };
        }
        return { RendererStatus::Fail };
    }

    RendererSpec Renderer::GetRendererSpec() { return Renderer::s_Renderer->m_RendererSpec; }

    Renderer* Renderer::GetRenderer() { return Renderer::s_Renderer; }
}// namespace FikoEngine