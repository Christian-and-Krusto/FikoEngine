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
template <typename RendererContextType>
FikoEngine::Renderer<RendererContextType>* FikoEngine::Renderer<RendererContextType>::s_Renderer = nullptr;

/***********************************************************************************************************************
Renderer Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{
    template <typename RendererContextType>
    Renderer<RendererContextType>::Renderer( RendererSpec& rendererSpec )
    {
        Init( rendererSpec );
    }

    template <typename RendererContextType>
    Renderer<RendererContextType>::~Renderer()
    {
        LOG_INFO( "Destroyed Renderer" );
    }

    template <typename RendererContextType>
    ResultValueType<RendererStatus> Renderer<RendererContextType>::Init( RendererSpec& rendererSpec )
    {
        auto result = RendererContextType::Create( rendererSpec );

        uint32_t tries = 0, maxTries = 3;
        while ( result != RendererContextStatus::Initialized && tries < maxTries )
        {
            result = RendererContextType::Create( rendererSpec );
            tries++;
        }

        if ( result == RendererContextStatus::Initialized )
        {
            LOG_INFO( "Created Renderer" );
            return ResultValueType{ RendererStatus::Initialized };
        }
        else { return ResultValueType{ RendererStatus::Fail }; }
    }

    template <typename RendererContextType>
    ResultValueType<RendererStatus> Renderer<RendererContextType>::Create( RendererSpec& rendererSpec )
    {
        if ( nullptr == Renderer::GetRenderer() )
        {
            Renderer::s_Renderer = new Renderer();
            return Renderer::s_Renderer->Init( rendererSpec );
        }
        return ResultValueType{ RendererStatus::Fail };
    }

    template <typename RendererContextType>
    ResultValueType<RendererStatus> Renderer<RendererContextType>::DeInit()
    {
        if ( nullptr != Renderer::GetRenderer() )
        {
            auto result = RendererContextType::Destroy();
            uint32_t tries = 0, maxTries = 3;
            while ( result != RendererContextStatus::Destroyed && tries < maxTries )
            {
                result = RendererContextType::Destroy();
                tries++;
            }
            if ( result == RendererContextStatus::Destroyed )
            {
                delete Renderer::s_Renderer;
                return ResultValueType{ RendererStatus::Destroyed };
            }

            return ResultValueType{ RendererStatus::Fail };
        }
        return ResultValueType{ RendererStatus::Fail };
    }

    template <typename RendererContextType>
    ResultValueType<RendererStatus> Renderer<RendererContextType>::Destroy()
    {
        if ( nullptr != Renderer::GetRenderer() )
        {
            return Renderer::GetRenderer()->DeInit();
        }
        return ResultValueType{ RendererStatus::Fail };
    }
    template <typename RendererContextType>
    RendererSpec Renderer<RendererContextType>::GetRendererSpec()
    {
        return Renderer::s_Renderer->m_RendererSpec;
    }

    template <typename RendererContextType>
    Renderer<RendererContextType>* Renderer<RendererContextType>::GetRenderer()
    {
        return Renderer::s_Renderer;
    }
}// namespace FikoEngine