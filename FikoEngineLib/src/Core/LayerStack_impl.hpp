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
 * LayerStack class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "LayerStack.hpp"
#include "Log.hpp"

/***********************************************************************************************************************
Static variable declaration
***********************************************************************************************************************/
FikoEngine::LayerStack* FikoEngine::LayerStack::s_LayerStack = nullptr;

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    inline Result<LayerStackStatus> LayerStack::Init()
    {
        if ( LayerStack::s_LayerStack ) { return { LayerStackStatus::Error }; }

        s_LayerStack = new LayerStack();
        return { LayerStackStatus::Initialized };
    }

    template <typename T>
    inline Result<LayerStatus> LayerStack::AddLayer()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStatus::Error }; }

        LayerStack::s_LayerStack->m_Layers.emplace_back( new T() );
        LOG_INFO( "Layer " + LayerStack::s_LayerStack->m_Layers.back()->GetName() + " added!" );

        LayerStack::s_LayerStack->m_Layers.back()->OnAttach();
        LOG_INFO( "Layer " + LayerStack::s_LayerStack->m_Layers.back()->GetName() + " attached!" );

        return { LayerStatus::Added };
    }

    Result<LayerStatus> LayerStack::RemoveLayer( std::string_view name )
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStatus::Error }; }

        uint32_t index = 0;
        for ( auto& layer: LayerStack::s_LayerStack->m_Layers )
        {
            if ( layer->GetName() == std::string( name ) )
            {
                delete layer;
                layer->OnDettach();
                layer->OnDestroy();
                LayerStack::s_LayerStack->m_Layers.erase( LayerStack::s_LayerStack->m_Layers.begin() + index );
                break;
            }
            index++;
        }
        return { LayerStatus::Removed };
    }

    inline Result<LayerStackStatus> LayerStack::Destroy()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStackStatus::Error }; }

        auto status = LayerStack::DestroyLayers();
        if ( LayerStackStatus::Destroyed != status ) { return { LayerStackStatus::Error }; }

        for ( auto& layer: LayerStack::s_LayerStack->m_Layers )
        {
            LOG_INFO( "Layer " + layer->GetName() + " removed!" );
            delete layer;
        }
        LayerStack::s_LayerStack->m_Layers.clear();
        delete LayerStack::s_LayerStack;
        LayerStack::s_LayerStack = nullptr;

        return { LayerStackStatus::Destroyed };
    }

    inline Result<LayerStackStatus, LayerStack*> LayerStack::Get()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStackStatus::Error, nullptr }; }

        return { LayerStackStatus::Success, s_LayerStack };
    }

    Result<LayerStatus, Layer*> LayerStack::GetLayer( std::string_view name )
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStatus::Error, nullptr }; }

        for ( auto& layer: LayerStack::s_LayerStack->m_Layers )
        {
            if ( layer->GetName() == std::string( name ) ) { return { LayerStatus::Success, layer }; }
        }
        return { LayerStatus::Error, nullptr };
    }

    inline Result<LayerStatus, const std::vector<Layer*>&> LayerStack::GetLayers()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStatus::Error, {} }; }

        return { LayerStatus::Success, LayerStack::s_LayerStack->m_Layers };
    }

    inline Result<LayerStackStatus> LayerStack::InitLayers()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStackStatus::Error }; }

        for ( auto& layer: LayerStack::s_LayerStack->m_Layers )
        {
            layer->Init();
            LOG_INFO( "Layer " + LayerStack::s_LayerStack->m_Layers.back()->GetName() + " initialized!" );
        }
        return { LayerStackStatus::Initialized };
    }

    inline Result<LayerStackStatus> LayerStack::DestroyLayers()
    {
        if ( !LayerStack::s_LayerStack ) { return { LayerStackStatus::Error }; }
        for ( auto& layer: LayerStack::s_LayerStack->m_Layers )
        {
            layer->Destroy();
            LOG_INFO( "Layer " + LayerStack::s_LayerStack->m_Layers.back()->GetName() + " destroyed!" );

            layer->OnDettach();
            LOG_INFO( "Layer " + LayerStack::s_LayerStack->m_Layers.back()->GetName() + " dettached!" );
        }
        return { LayerStackStatus::Destroyed };
    }

}// namespace FikoEngine