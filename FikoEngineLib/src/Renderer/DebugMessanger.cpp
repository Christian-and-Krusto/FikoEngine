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
 * Debug Messanger class implementation
 */


/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "DebugMessanger.hpp"
#include <Core/Log.hpp>

#include <vulkan/vulkan.hpp>
#include <vulkan/vulkan_to_string.hpp>

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Type definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Static variables
***********************************************************************************************************************/
PFN_vkCreateDebugUtilsMessengerEXT pfnVkCreateDebugUtilsMessengerEXT;
PFN_vkDestroyDebugUtilsMessengerEXT pfnVkDestroyDebugUtilsMessengerEXT;
FikoEngine::DebugMessanger* FikoEngine::DebugMessanger::s_DebugMessanger = {};

/***********************************************************************************************************************
Static function Prototypes
***********************************************************************************************************************/

VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugUtilsMessengerEXT( VkInstance instance,
                                                               const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                               const VkAllocationCallbacks* pAllocator,
                                                               VkDebugUtilsMessengerEXT* pMessenger )
{
    return pfnVkCreateDebugUtilsMessengerEXT( instance, pCreateInfo, pAllocator, pMessenger );
}

VKAPI_ATTR void VKAPI_CALL vkDestroyDebugUtilsMessengerEXT( VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                                            VkAllocationCallbacks const* pAllocator )
{
    return pfnVkDestroyDebugUtilsMessengerEXT( instance, messenger, pAllocator );
}

VKAPI_ATTR VkBool32 VKAPI_CALL debugMessageFunc( VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                                 VkDebugUtilsMessageTypeFlagsEXT messageTypes,
                                                 VkDebugUtilsMessengerCallbackDataEXT const* pCallbackData,
                                                 void* /*pUserData*/ )
{
    std::ostringstream message;

    message << vk::to_string( static_cast<vk::DebugUtilsMessageSeverityFlagBitsEXT>( messageSeverity ) ) << ": "
            << vk::to_string( static_cast<vk::DebugUtilsMessageTypeFlagsEXT>( messageTypes ) ) << ":\n";
    message << std::string( "\t" ) << "messageIDName   = <" << pCallbackData->pMessageIdName << ">\n";
    message << std::string( "\t" ) << "messageIdNumber = " << pCallbackData->messageIdNumber << "\n";
    message << std::string( "\t" ) << "message         = <" << pCallbackData->pMessage << ">\n";
    if ( 0 < pCallbackData->queueLabelCount )
    {
        message << std::string( "\t" ) << "Queue Labels:\n";
        for ( uint32_t i = 0; i < pCallbackData->queueLabelCount; i++ )
        {
            message << std::string( "\t\t" ) << "labelName = <" << pCallbackData->pQueueLabels[ i ].pLabelName << ">\n";
        }
    }
    if ( 0 < pCallbackData->cmdBufLabelCount )
    {
        message << std::string( "\t" ) << "CommandBuffer Labels:\n";
        for ( uint32_t i = 0; i < pCallbackData->cmdBufLabelCount; i++ )
        {
            message << std::string( "\t\t" ) << "labelName = <" << pCallbackData->pCmdBufLabels[ i ].pLabelName
                    << ">\n";
        }
    }
    if ( 0 < pCallbackData->objectCount )
    {
        message << std::string( "\t" ) << "Objects:\n";
        for ( uint32_t i = 0; i < pCallbackData->objectCount; i++ )
        {
            message << std::string( "\t\t" ) << "Object " << i << "\n";
            message << std::string( "\t\t\t" ) << "objectType   = "
                    << vk::to_string( static_cast<vk::ObjectType>( pCallbackData->pObjects[ i ].objectType ) ) << "\n";
            message << std::string( "\t\t\t" ) << "objectHandle = " << pCallbackData->pObjects[ i ].objectHandle
                    << "\n";
            if ( pCallbackData->pObjects[ i ].pObjectName )
            {
                message << std::string( "\t\t\t" ) << "objectName   = <" << pCallbackData->pObjects[ i ].pObjectName
                        << ">\n";
            }
        }
    }

    switch ( messageSeverity )
    {
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
            LOG_INFO( message.str() );
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
            LOG_INFO( message.str() );
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
            LOG_WARNING( message.str() );
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
            LOG_ERROR( message.str() );
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT:
            LOG_ERROR( message.str() );
            break;
    }

    return false;
}

namespace FikoEngine
{
    Result<DebugMessangerStatus> DebugMessanger::Create( vk::Instance& instance )
    {
        Result<DebugMessangerStatus> result;
#if !defined( NDEBUG )
        DebugMessanger::s_DebugMessanger = new DebugMessanger();
        result = DebugMessanger::Get()->Init( instance );
#else
        result = { DebugMessangerStatus::Created };
#endif

        return result;
    }

    void DebugMessanger::Destroy( vk::Instance& instance )
    {
        if ( DebugMessanger::Get() )
        {
            instance.destroyDebugUtilsMessengerEXT( DebugMessanger::Get()->m_VkDebugMessanger );
            delete DebugMessanger::Get();
            LOG_INFO( "Debug Messanger Destroyed" );
        }
    }

    DebugMessanger* DebugMessanger::Get() { return DebugMessanger::s_DebugMessanger; }

    bool DebugMessanger::IsDebugExtensionAvailable()
    {
        std::vector<vk::ExtensionProperties> props = vk::enumerateInstanceExtensionProperties().value;

        auto propertyIterator = std::find_if( props.begin(), props.end(), []( vk::ExtensionProperties const& ep ) {
            return strcmp( ep.extensionName, VK_EXT_DEBUG_UTILS_EXTENSION_NAME ) == 0;
        } );
        if ( propertyIterator == props.end() )
        {
            LOG_ERROR( "Something went very wrong, cannot find " + std::string( VK_EXT_DEBUG_UTILS_EXTENSION_NAME ) +
                       " extension" );
            return false;
        }

        return true;
    }
}// namespace FikoEngine

/***********************************************************************************************************************
Class function Prototypes
***********************************************************************************************************************/

namespace FikoEngine
{
    Result<DebugMessangerStatus> DebugMessanger::Init( vk::Instance& instance )
    {
        pfnVkCreateDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(
                instance.getProcAddr( "vkCreateDebugUtilsMessengerEXT" ) );
        if ( !pfnVkCreateDebugUtilsMessengerEXT )
        {
            LOG_INFO( "GetInstanceProcAddr: Unable to find pfnVkCreateDebugUtilsMessengerEXT function." );
            return { DebugMessangerStatus::Fail };
        }

        pfnVkDestroyDebugUtilsMessengerEXT = reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(
                instance.getProcAddr( "vkDestroyDebugUtilsMessengerEXT" ) );
        if ( !pfnVkDestroyDebugUtilsMessengerEXT )
        {
            LOG_INFO( "GetInstanceProcAddr: Unable to find pfnVkDestroyDebugUtilsMessengerEXT function." );
            return { DebugMessangerStatus::Fail };
        }

        vk::DebugUtilsMessageSeverityFlagsEXT severityFlags( vk::DebugUtilsMessageSeverityFlagBitsEXT::eWarning |
                                                             vk::DebugUtilsMessageSeverityFlagBitsEXT::eError );

        vk::DebugUtilsMessageTypeFlagsEXT messageTypeFlags( vk::DebugUtilsMessageTypeFlagBitsEXT::eGeneral |
                                                            vk::DebugUtilsMessageTypeFlagBitsEXT::ePerformance |
                                                            vk::DebugUtilsMessageTypeFlagBitsEXT::eValidation );

        m_VkDebugMessanger = instance
                                     .createDebugUtilsMessengerEXT( vk::DebugUtilsMessengerCreateInfoEXT(
                                             {}, severityFlags, messageTypeFlags, &debugMessageFunc ) )
                                     .value;

        LOG_INFO( "Debug Messanger Created" );
        return { DebugMessangerStatus::Created };
    }


}// namespace FikoEngine