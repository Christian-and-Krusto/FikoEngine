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
 * Result struct definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <cstdint>
#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{
    template <typename T = vk::Result, typename E = uint32_t>
    struct ResultValue {
        T status;
        E value;

        ResultValue() {}

        explicit ResultValue( T status ) : status( status ) {}

        ResultValue( T status, E& value ) : status( status ), value( value ) {}

        ResultValue( T status, E&& value ) : status( status ), value( std::move( value ) ) {}

        explicit ResultValue( vk::ResultValue<E> res )
        {
            status = res.result;
            value = res.value;
        }

        operator E() { return value; }

        operator const E() const { return value; }

        operator T() { return status; }

        operator const T() const { return status; }
    };

    template <typename StatusType = vk::Result>
    struct ResultValueType {
        StatusType status;

        ResultValueType() {}

        ResultValueType( StatusType status ) : status( status ) {}

        operator StatusType() { return status; }

        operator const StatusType() const { return status; }
    };
}// namespace FikoEngine