#pragma once
#include <Renderer/CommandPool.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace FikoEngine::tests
{

    class MockVkInterface: public FikoEngine::vkInterface
    {
    public:
        MOCK_METHOD( ( vk::ResultValue<vk::CommandPool> ), _CreateCommandPool,
                     ( vk::Device * device, uint32_t graphicsQueueFamilyIndex ), ( override ) );

        MOCK_METHOD( void, _DestroyCommandPool, ( vk::Device * device, vk::CommandPool commandPool ), ( override ) );

        MOCK_METHOD( void, _FreeCommandBuffers,
                     ( vk::Device * device, vk::CommandPool commandPool, vk::CommandBuffer buffer ), ( override ) );

        MOCK_METHOD( ( vk::ResultValue<std::vector<vk::CommandBuffer>> ), _AllocateCommandBuffers,
                     ( vk::Device * device, const vk::CommandBufferAllocateInfo& allocateInfo ), ( override ) );
    };

    template <typename T>
    constexpr vk::ResultValue<T> createResult( vk::Result result, T handle )
    {
        return { result, handle };
    }

}// namespace FikoEngine::tests

TEST( Renderer_Tests, CommandPool_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;
    MockVkInterface mockVk;

    ON_CALL( mockVk, _CreateCommandPool( _, _ ) )
            .WillByDefault( Return( createResult<vk::CommandPool>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    ASSERT_EQ( 1, 1 );
    vk::Device device;
    FikoEngine::CommandPool::Create( &device, 0 );
}