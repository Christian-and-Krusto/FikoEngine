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
 * Log class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "Log.hpp"
#include <memory>

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Type definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Static variables
***********************************************************************************************************************/
std::shared_ptr<FikoEngine::Logger> FikoEngine::Logger::s_Logger;

/***********************************************************************************************************************
Static function Prototypes
***********************************************************************************************************************/

/***********************************************************************************************************************
Logger Class Implementation
***********************************************************************************************************************/

namespace FikoEngine
{

    Logger::Logger() { Init(); }
    Logger::~Logger() { Destroy(); }

    void Logger::Create() { Logger::s_Logger = std::make_shared<Logger>(); }

#ifdef LWLOG
    void Logger::Init()
    {
        console = std::make_shared<lwlog::logger<
                lwlog::asynchronous_policy<lwlog::default_async_queue_size, lwlog::default_overflow_policy>,
                lwlog::buffered_flush_policy<>, lwlog::single_threaded_policy, lwlog::sinks::stdout_sink>>( "CONSOLE" );
        console->set_pattern( ".br_red([%T]) .green([%l]): .br_cyan(%v)" );
        console->set_level_filter( lwlog::level::info | lwlog::level::debug | lwlog::level::critical );

        {
#ifdef _WIN32
            // Set output mode to handle virtual terminal sequences
            HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
            if ( hOut == INVALID_HANDLE_VALUE ) { console->error( "INVALID_HANDLE_VALUE" ); }

            DWORD dwMode = 0;
            if ( !GetConsoleMode( hOut, &dwMode ) ) { console->error( "GetConsoleMode" ); }

            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            if ( !SetConsoleMode( hOut, dwMode ) )
            {
                console->error( "SetConsoleMode ENABLE_VIRTUAL_TERMINAL_PROCESSING" );
            }
#endif
        }
    }

    void Logger::Destroy() { console.reset(); }

    Logger* Logger::GetInstance() { return s_Logger.get(); }

#else
    void Logger::Init() {}
    void Logger::Destroy() {}
    Logger* Logger::GetInstance() { return s_Logger.get(); }
#endif
}// namespace FikoEngine