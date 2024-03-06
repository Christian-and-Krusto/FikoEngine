#pragma once
#include <Renderer/CommandPool.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace FikoEngine::tests
{

    template <typename T>
    constexpr vk::ResultValue<T> createResult( vk::Result result, T handle )
    {
        return { result, handle };
    }

}// namespace FikoEngine::tests

class MockedVkInterface: public FikoEngine::vkInterface
{
public:
    MockedVkInterface() = default;
    ~MockedVkInterface() = default;
    MOCK_METHOD( vk::ResultValue<vk::CommandPool>, _CreateCommandPool,
                 ( vk::Device * device, uint32_t graphicsQueueFamilyIndex ), ( override ) );

    MOCK_METHOD( void, _DestroyCommandPool, ( vk::Device * device, vk::CommandPool commandPool ), ( override ) );

    MOCK_METHOD( ( vk::ResultValue<std::vector<vk::CommandBuffer>> ), _AllocateCommandBuffers,
                 ( vk::Device * device, const vk::CommandBufferAllocateInfo& allocateInfo ), ( override ) );

    MOCK_METHOD( void, _FreeCommandBuffers,
                 ( vk::Device * device, vk::CommandPool commandPool, vk::CommandBuffer buffer ), ( override ) );
};

TEST( Renderer_Tests, CommandPool_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();

    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>();

    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) )
            .WillByDefault(
                    Return( vk::ResultValue<vk::CommandPool>( vk::Result::eErrorOutOfHostMemory, VK_NULL_HANDLE ) ) );

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Fail );
    ASSERT_EQ( result.returnValue, nullptr );

    FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>();
}

TEST( Renderer_Tests, CommandPool_Test2 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();

    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>();

    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) )
            .WillByDefault(
                    Return( vk::ResultValue<vk::CommandPool>( vk::Result::eErrorOutOfDeviceMemory, VK_NULL_HANDLE ) ) );

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Fail );
    ASSERT_EQ( result.returnValue, nullptr );

    FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>();
}

TEST( Renderer_Tests, CommandPool_Test3 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();

    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>();

    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) )
            .WillByDefault( Return( vk::ResultValue<vk::CommandPool>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    ON_CALL( *mockRef, _AllocateCommandBuffers( _, _ ) )
            .WillByDefault( []( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo ) {
                std::vector<vk::CommandBuffer> buffers;
                buffers.emplace_back(VK_NULL_HANDLE);
                return vk::ResultValue<std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
            } );

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( result.returnValue, nullptr );

    delete result.returnValue;

    FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>();
}

TEST( Renderer_Tests, CommandPool_Test4 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();

    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>();

    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) )
            .WillByDefault( Return( vk::ResultValue<vk::CommandPool>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    ON_CALL( *mockRef, _AllocateCommandBuffers( _, _ ) )
            .WillByDefault( []( vk::Device* device, const vk::CommandBufferAllocateInfo& allocateInfo ) {
                std::vector<vk::CommandBuffer> buffers;
                buffers.emplace_back( VK_NULL_HANDLE );
                return vk::ResultValue<std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
            } );

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.returnValue, nullptr );

    EXPECT_CALL( *mockRef, _DestroyCommandPool );
    EXPECT_CALL( *mockRef, _FreeCommandBuffers ).Times(AtLeast(1));

    auto resultDestroy = FikoEngine::CommandPool::Destroy(resultCreate.returnValue);

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>();
}

TEST( Renderer_Tests, CommandPool_Test5 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    auto resultDestroy = FikoEngine::CommandPool::Destroy( nullptr );

    ASSERT_EQ(resultDestroy.status, FikoEngine::CommandPoolState::Fail);
}