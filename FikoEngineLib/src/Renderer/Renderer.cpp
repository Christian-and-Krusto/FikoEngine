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
 * Renderer class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "Renderer.hpp"
#include "RendererContext.hpp"
#include <Core/Log.hpp>

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Type definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Static variables
***********************************************************************************************************************/
FikoEngine::Renderer* FikoEngine::Renderer::s_Renderer = nullptr;

/***********************************************************************************************************************
Renderer Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{
    Renderer::Renderer( RendererSpec& rendererSpec ) { Init( rendererSpec ); }

    Renderer::~Renderer() { LOG_INFO( "Destroyed Renderer" ); }

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