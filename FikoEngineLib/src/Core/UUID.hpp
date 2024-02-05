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
 * UUID class definition
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <cstdint>

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{
    /**
     * @brief 64 bit unique id generator class
     */
    class UUID
    {
    public:
        UUID();
        UUID( uint64_t uuid );
        UUID( const UUID& other );

    public:
        uint64_t GetID();
        uint64_t GetID() const;

    public:
        operator const uint64_t() const;
        operator uint64_t();

    private:
        uint64_t m_UUID;
    };
}// namespace FikoEngine

namespace FikoEngine
{
    /**  
     * @brief 32 bit unique id generator class
     */
    class UUID32
    {
    public:
        UUID32();
        UUID32( uint32_t uuid );
        UUID32( const UUID32& other );

    public:
        uint32_t GetID();
        uint32_t GetID() const;

    public:
        operator const uint32_t() const;
        operator uint32_t();

    private:
        uint32_t m_UUID;
    };

}// namespace FikoEngine

namespace std
{

    template <> struct hash<FikoEngine::UUID> {
        std::size_t operator()( const FikoEngine::UUID& uuid ) const
        {
            return hash<uint64_t>()( ( uint64_t ) uuid.GetID() );
        }
    };

    template <> struct hash<FikoEngine::UUID32> {
        std::size_t operator()( const FikoEngine::UUID32& uuid ) const
        {
            return hash<uint32_t>()( ( uint32_t ) uuid.GetID() );
        }
    };
}// namespace std