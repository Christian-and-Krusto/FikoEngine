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
 * UUID class implementation
 */

/***************************************************************************************************************************
Includes
***************************************************************************************************************************/
#include "UUID.hpp"
#include <random>

/***************************************************************************************************************************
Macro definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Type definitions
***************************************************************************************************************************/

/***************************************************************************************************************************
Static variables
***************************************************************************************************************************/
static std::random_device s_RandomDevice;
static std::mt19937_64 eng( s_RandomDevice() );
static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

static std::mt19937 eng32( s_RandomDevice() );
static std::uniform_int_distribution<uint32_t> s_UniformDistribution32;

/***************************************************************************************************************************
Static function Prototypes
***************************************************************************************************************************/


namespace FikoEngine
{
    /***********************************************************************************************************************
    UUID class 64 bit constructor implementation
    ***********************************************************************************************************************/
    UUID::UUID() : m_UUID( s_UniformDistribution( eng ) ) {}
    UUID::UUID( uint64_t uuid ) : m_UUID( uuid ) {}
    UUID::UUID( const UUID& other ) : m_UUID( other.m_UUID ) {}

    /***********************************************************************************************************************
    UUID class 64 bit getters implementation
    ***********************************************************************************************************************/
    uint64_t UUID::GetID() { return m_UUID; }
    uint64_t UUID::GetID() const { return m_UUID; }

    /***********************************************************************************************************************
    UUID class 64 bit operators implementation
    ***********************************************************************************************************************/
    UUID::operator const uint64_t() const { return m_UUID; }
    UUID::operator uint64_t() { return m_UUID; }
}// namespace FikoEngine

namespace FikoEngine
{
    /***********************************************************************************************************************
    UUID class 32 bit constructor implementation
    ***********************************************************************************************************************/
    UUID32::UUID32() : m_UUID( s_UniformDistribution32( eng32 ) ) {}
    UUID32::UUID32( uint32_t uuid ) : m_UUID( uuid ) {}
    UUID32::UUID32( const UUID32& other ) : m_UUID( other.m_UUID ) {}

    /***********************************************************************************************************************
    UUID class 32 bit getters implementation
    ***********************************************************************************************************************/
    uint32_t UUID32::GetID() { return m_UUID; }
    uint32_t UUID32::GetID() const { return m_UUID; }

    /***********************************************************************************************************************
    UUID class 32 bit operators implementation
    ***********************************************************************************************************************/
    UUID32::operator const uint32_t() const { return m_UUID; }
    UUID32::operator uint32_t() { return m_UUID; }
}// namespace FikoEngine