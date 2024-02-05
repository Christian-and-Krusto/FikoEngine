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
 * Buffer class definition
 */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#ifdef LWLOG
#include <lwlog.h>
#else
#include <iostream>
#endif

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{
    class Logger
    {
    public:
        Logger();
        ~Logger();

    public:
        void Init();
        void Destroy();

    public:
        static void Create();
        static Logger* GetInstance();

#ifdef LWLOG
    public:
        std::shared_ptr<lwlog::logger<
                lwlog::asynchronous_policy<lwlog::default_async_queue_size, lwlog::default_overflow_policy>,
                lwlog::buffered_flush_policy<>, lwlog::single_threaded_policy, lwlog::sinks::stdout_sink>>
                console;
#endif
    private:
        static std::shared_ptr<Logger> s_Logger;
    };

    class mem
    {
    public:
        inline static int memsize = 0;
    };

}// namespace FikoEngine

/***********************************************************************************************************************
Macros definitions
***********************************************************************************************************************/

#ifdef LWLOG
#define LOG( ... )                                                                                                     \
    FikoEngine::Logger::GetInstance()->console->info( __VA_ARGS__ );                                                   \
    std::flush( std::cout );
#define LOG_INFO( ... )                                                                                                \
    FikoEngine::Logger::GetInstance()->console->info( __VA_ARGS__ );                                                   \
    std::flush( std::cout );
#define LOG_ERROR( ... )                                                                                               \
    FikoEngine::Logger::GetInstance()->console->error( __VA_ARGS__ );                                                  \
    std::flush( std::cout );
#define LOG_DEBUG( ... )                                                                                               \
    FikoEngine::Logger::GetInstance()->console->debug( __VA_ARGS__ );                                                  \
    std::flush( std::cout );
#define LOG_WARNING( ... )                                                                                             \
    FikoEngine::Logger::GetInstance()->console->warning( __VA_ARGS__ );                                                \
    std::flush( std::cout );
#define LOG_CRITICAL( ... )                                                                                            \
    FikoEngine::Logger::GetInstance()->console->critical( __VA_ARGS__ );                                               \
    std::flush( std::cout );
#else

#define LOG_INFO( ... )                                                                                                \
    {                                                                                                                  \
        std::cout << ( __VA_ARGS__ ) << '\n';                                                                          \
        fflush( stdout );                                                                                              \
    }
#define LOG_ERROR( ... )                                                                                               \
    {                                                                                                                  \
        std::cout << ( __VA_ARGS__ ) << '\n';                                                                          \
        fflush( stdout );                                                                                              \
    }
#define LOG_DEBUG( ... )                                                                                               \
    {                                                                                                                  \
        std::cout << ( __VA_ARGS__ ) << '\n';                                                                          \
        fflush( stdout );                                                                                              \
    }
#define LOG( ... )                                                                                                     \
    {                                                                                                                  \
        std::cout << ( __VA_ARGS__ ) << '\n';                                                                          \
        fflush( stdout );                                                                                              \
    }
#define LOG_WARNING( ... )                                                                                             \
    {                                                                                                                  \
        std::cout << ( __VA_ARGS__ ) << '\n';                                                                          \
        fflush( stdout );                                                                                              \
    }

#endif