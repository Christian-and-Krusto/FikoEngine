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
    inline void LayerStack::Init() { s_LayerStack = new LayerStack(); }

    template <typename T>
    inline LayerStatus LayerStack::AddLayer()
    {
        LayerStack::Get()->m_Layers.emplace_back( new T() );
        LOG_INFO( "Layer " + LayerStack::Get()->m_Layers.back()->GetName() + " added!" );
        return LayerStatus::LayerAdded;
    }

    LayerStatus LayerStack::RemoveLayer( std::string_view name )
    {
        uint32_t index = 0;
        for ( auto& layer: LayerStack::Get()->m_Layers )
        {
            if ( layer->GetName() == std::string( name ) )
            {
                delete layer;
                LayerStack::Get()->m_Layers.erase( LayerStack::Get()->m_Layers.begin() + index );
                break;
            }
            index++;
        }
        return LayerStatus::LayerRemoved;
    }

    inline void LayerStack::Destroy()
    {
        for ( auto& layer: LayerStack::Get()->m_Layers )
        {
            LOG_INFO( "Layer " + layer->GetName() + " removed!" );
            delete layer;
        }
        LayerStack::Get()->m_Layers.clear();
        delete s_LayerStack;
    }

    inline LayerStack* LayerStack::Get() { return s_LayerStack; }

    Layer* LayerStack::GetLayer( std::string_view name )
    {
        for ( auto& layer: LayerStack::Get()->m_Layers )
        {
            if ( layer->GetName() == std::string( name ) ) { return layer; }
        }
        return nullptr;
    }

    inline const auto& LayerStack::GetLayers() { return LayerStack::Get()->m_Layers; }

}// namespace FikoEngine