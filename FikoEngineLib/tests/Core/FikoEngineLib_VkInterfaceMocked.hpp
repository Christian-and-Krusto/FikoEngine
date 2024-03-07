#pragma once

#include <Core/VulkanInterface.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vulkan/vulkan.hpp>

namespace FikoEngine::tests
{

    template <typename T>
    constexpr FikoEngine::Result<vk::Result, T> createResult( vk::Result result, T handle )
    {
        return { result, handle };
    }

}// namespace FikoEngine::tests

class MockedVkInterface: public FikoEngine::vkInterface
{
public:
    MockedVkInterface() = default;
    ~MockedVkInterface() = default;

    MOCK_METHOD( ( FikoEngine::Result<vk::Result, vk::CommandPool> ), _CreateCommandPool,
                 ( vk::Device * device, uint32_t graphicsQueueFamilyIndex ), ( override ) );

    MOCK_METHOD( void, _DestroyCommandPool, ( vk::Device * device, vk::CommandPool commandPool ), ( override ) );

    MOCK_METHOD( ( FikoEngine::Result<vk::Result, std::vector<vk::CommandBuffer>> ), _AllocateCommandBuffers,
                 ( vk::Device * device, const vk::CommandBufferAllocateInfo& allocateInfo ), ( override ) );

    MOCK_METHOD( void, _FreeCommandBuffers,
                 ( vk::Device * device, vk::CommandPool commandPool, vk::CommandBuffer buffer ), ( override ) );

    MOCK_METHOD( ( FikoEngine::Result<vk::Result> ), _CommandBufferBegin,
                 ( vk::CommandBuffer buffer, vk::CommandBufferBeginInfo beginInfo ), ( override ) );

    MOCK_METHOD( ( FikoEngine::Result<vk::Result> ), _CommandBufferEnd, ( vk::CommandBuffer buffer ), ( override ) );
};

#define VKINTERFACE_CREATE_MOCK()                                                                                      \
    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();                                                     \
    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>()

#define VKINTERFACE_DESTROY_MOCK() FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>()

#define VKINTERFACE_EXPECT_CREATE_COMMAND_POOL() EXPECT_CALL( *mockRef, _CreateCommandPool )
#define VKINTERFACE_ON_CREATE_COMMAND_POOL( retVal )                                                                   \
    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS() EXPECT_CALL( *mockRef, _AllocateCommandBuffers )
#define VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( func )                                                                \
    ON_CALL( *mockRef, _AllocateCommandBuffers( _, _ ) ).WillByDefault( func );

#define VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN() EXPECT_CALL( *mockRef, _CommandBufferBegin )
#define VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN( retVal )                                                                 \
    ON_CALL( *mockRef, _CommandBufferBegin( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_COMMAND_BUFFER_END() EXPECT_CALL( *mockRef, _CommandBufferEnd )
#define VKINTERFACE_ON_COOMMAND_BUFFER_END( retVal )                                                                 \
    ON_CALL( *mockRef, _CommandBufferEnd( _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL() EXPECT_CALL( *mockRef, _DestroyCommandPool )
#define VKINTERFACE_ON_DESTROY_COMMAND_POOL( retVal )                                                                  \
    ON_CALL( *mockRef, _DestroyCommandPool( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS() EXPECT_CALL( *mockRef, _FreeCommandBuffers )
#define VKINTERFACE_ON_FREE_COMMAND_BUFFERS()                                                                          \
    ON_CALL( *mockRef, _FreeCommandBuffers(_, _, _ ) ).WillByDefault( Return( retVal ) );
