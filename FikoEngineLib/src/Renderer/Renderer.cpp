#include "Renderer.hpp"
#include <Core/Log.hpp>

FikoEngine::Renderer* FikoEngine::Renderer::s_Renderer = nullptr;

namespace FikoEngine
{
    Renderer::Renderer( RendererSpec& rendererSpec ) { LOG_INFO( "Created Renderer" ); }

    Renderer::~Renderer() { LOG_INFO( "Destroyed Renderer" ); }

    void Renderer::Create( RendererSpec& rendererSpec )
    {
        if ( nullptr == Renderer::GetRenderer() ) { Renderer::s_Renderer = new Renderer( rendererSpec ); }
    }

    void Renderer::Destroy()
    {
        if ( nullptr != Renderer::GetRenderer() ) { delete Renderer::s_Renderer; }
    }

    RendererSpec Renderer::GetRendererSpec() { return Renderer::s_Renderer->m_RendererSpec; }

    Renderer* Renderer::GetRenderer() { return Renderer::s_Renderer; }
}// namespace FikoEngine