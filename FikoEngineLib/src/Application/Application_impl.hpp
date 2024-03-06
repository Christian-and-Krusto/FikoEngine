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
 * Application class implementation
 */

/***************************************************************************************************************************
Includes
***************************************************************************************************************************/

#include <Core/LayerStack.hpp>
#include <Core/Log.hpp>
#include <Renderer/Renderer.hpp>

#include "Application.hpp"
#include <concepts>


/***************************************************************************************************************************
Macro definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Type definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Static variables
***************************************************************************************************************************/
FikoEngine::Application* FikoEngine::Application::s_Application = nullptr;

namespace FikoEngine
{

    /***************************************************************************************************************************
    Application class static function implementations
    ***************************************************************************************************************************/
    void Application::Run()
    {
        LayerStack::InitLayers();

        while ( !Application::Get()->m_StoppedFlag )
        {
            auto layersStatus = LayerStack::GetLayers();
            for ( auto layer: layersStatus.returnValue )
            {
                layer->OnUpdate();
                Application::Get()->m_StoppedFlag = true;
            }
        }
    }

    Application::Application( ApplicationSpec applicationSpec ) : m_ApplicationSpec( applicationSpec ) {}

    void Application::Init( ApplicationSpec applicationSpec )
    {
        if ( nullptr == Application::s_Application )
        {
            Application::s_Application = new Application( applicationSpec );

            LOG_INFO( "Application initialized!" );
            RendererSpec rendererSpec;
            rendererSpec.AppName = applicationSpec.ApplicationName;
            rendererSpec.WorkingDirectory = Application::GetSpec().WorkingDirectory;
            rendererSpec.width = Application::GetSpec().StartupWidth;
            rendererSpec.height = Application::GetSpec().StartupHeight;
            Renderer::Create( rendererSpec );

            LayerStack::Init();
        }
    }

    void Application::Destroy()
    {

        if ( nullptr != Application::s_Application )
        {
            LayerStack::Destroy();

            Renderer::Destroy();

            delete Application::s_Application;
            LOG_INFO( "Application destroyed!" );
        }
    }

    Application* Application::Get() { return Application::s_Application; }

    ApplicationSpec& Application::GetSpec() { return Application::Get()->m_ApplicationSpec; }

    template <typename T>
    void Application::AddLayer()
    {
        if ( !std::derived_from<T, Layer> ) { LOG_INFO( "Layer type does not have Layer as a Base type!" ); }
        else { LayerStack::AddLayer<T>(); }
    }
}// namespace FikoEngine