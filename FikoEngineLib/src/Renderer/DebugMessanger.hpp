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
 * Vulkan Debug Messanger class definitions
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include <Core/Result.hpp>

#include <vulkan/vulkan.hpp>

/***********************************************************************************************************************
Static Variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Enum Class definitions
***********************************************************************************************************************/
namespace FikoEngine
{
    enum class DebugMessangerStatus
    {
        Fail,
        Created,
        Destroyed
    };
}

/***********************************************************************************************************************
Class definitions
***********************************************************************************************************************/

namespace FikoEngine
{
    class DebugMessanger
    {
    public:
        DebugMessanger() = default;
        ~DebugMessanger() = default;

    public:
        static ResultValueType<DebugMessangerStatus> Create( vk::Instance& instance );
        static void Destroy( vk::Instance& instance );
        static DebugMessanger* Get();
        static bool IsDebugExtensionAvailable();

    public:
        ResultValueType<DebugMessangerStatus> Init( vk::Instance& instance );

    private:
        vk::DebugUtilsMessengerEXT m_VkDebugMessanger;

    public:
        static DebugMessanger* s_DebugMessanger;
    };
}// namespace FikoEngine