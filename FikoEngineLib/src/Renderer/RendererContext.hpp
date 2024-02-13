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
 * RendererContext class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "RendererSpec.hpp"
#include "Window.hpp"
#include <Core/Result.hpp>

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
enum class RendererContextStatus
{
    Success,
    Fail,
    Created,
    Initialized,
    Not_Initialized,
    Destroyed
};

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{

    class RendererContext
    {
    public:
        RendererContext();
        RendererContext( RendererSpec& rendererSpec );
        ~RendererContext();

    public:
        Result<RendererContextStatus> Init( RendererSpec& rendererSpec );

    public:
        static Result<RendererContextStatus> Create( RendererSpec& rendererSpec );

        static Result<RendererContextStatus> Destroy();

        static RendererContext* GetRenderer();

        static RendererSpec GetRendererSpec();

    private:
        static RendererContext* s_RendererContext;

    private:
        Window* m_Window{};
        RendererSpec m_RendererSpec{};
    };
}// namespace FikoEngine