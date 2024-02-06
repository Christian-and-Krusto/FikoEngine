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

#include "Application.hpp"
#include "../Core/Layer.hpp"
#include "../Core/Log.hpp"
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

/***************************************************************************************************************************
Static function Prototypes
***************************************************************************************************************************/
namespace FikoEngine
{
    void Application::Init()
    {
        if ( nullptr == Application::s_Application )
        {
            Application::s_Application = new Application();

            LOG_INFO( "Application initialized!" );
        }
    }

    void Application::Destroy()
    {
        if ( nullptr != Application::s_Application )
        {
            delete Application::s_Application;
            LOG_INFO( "Application destroyed!" );
        }
    }

    Application* Application::Get() { return Application::s_Application; }

    template <typename T>
    void Application::AddLayer()
    {
        bool derived = std::derived_from<T, Layer>;
        if ( derived ) { LOG_INFO( "Layer type does not have Layer as a Base type!" ); }
        else { LOG_INFO( "Layer added!" ); }
    }

}// namespace FikoEngine