#pragma once
#include "../Core/FikoEngineLib_VkInterfaceMocked.hpp"
#include <Renderer/CommandPool.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST( Renderer_Tests, CommandPool_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eErrorOutOfHostMemory );

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Fail );
    ASSERT_EQ( result.value, nullptr );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test2 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eErrorOutOfDeviceMemory );

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Fail );
    ASSERT_EQ( result.value, nullptr );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test3 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto result = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( result.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( result.value, nullptr );

    delete result.value;

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test4 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test5 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    auto resultDestroy = FikoEngine::CommandPool::Destroy( nullptr );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Fail );
}

TEST( Renderer_Tests, CommandPool_Test6 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN();
    VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN( vk::Result::eSuccess );

    auto resultBegin = resultCreate.value->BeginCommandBuffer( 0 );

    ASSERT_EQ( resultBegin.status, FikoEngine::CommandBufferState::Recording );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test7 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    auto resultBegin = resultCreate.value->BeginCommandBuffer( 0 );

    ASSERT_EQ( resultBegin.status, FikoEngine::CommandBufferState::Invalid );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test9 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN(vk::Result::eErrorOutOfHostMemory );
    VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN();

    auto resultBegin = resultCreate.value->BeginCommandBuffer( 0 );

    ASSERT_EQ( resultBegin.status, FikoEngine::CommandBufferState::Invalid );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test10 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN( vk::Result::eErrorOutOfHostMemory );
    VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN();

    auto resultBegin = resultCreate.value->BeginCommandBuffer( 0 );

    ASSERT_EQ( resultBegin.status, FikoEngine::CommandBufferState::Invalid );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test11 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN( vk::Result::eSuccess );
    VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN();

    auto resultBegin = resultCreate.value->BeginCommandBuffer( 0 );
    ASSERT_EQ( resultBegin.status, FikoEngine::CommandBufferState::Recording );

    VKINTERFACE_ON_COOMMAND_BUFFER_END( vk::Result::eSuccess );
    VKINTERFACE_EXPECT_COMMAND_BUFFER_END();

    auto resultEnd = resultCreate.value->EndCommandBuffer( 0 );

    ASSERT_EQ( resultEnd.status, FikoEngine::CommandBufferState::Executable );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test12 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    auto resultEnd = resultCreate.value->EndCommandBuffer( 0 );

    ASSERT_EQ( resultEnd.status, FikoEngine::CommandBufferState::Invalid );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, CommandPool_Test13 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    VKINTERFACE_ON_CREATE_COMMAND_POOL( vk::Result::eSuccess );

    VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( ( []( vk::Device device,
                                                   const vk::CommandBufferAllocateInfo& allocateInfo ) {
        std::vector<vk::CommandBuffer> buffers;
        buffers.emplace_back( VK_NULL_HANDLE );
        return FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>>{ vk::Result::eSuccess, buffers };
    } ) );
    VKINTERFACE_EXPECT_CREATE_COMMAND_POOL();
    VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS();

    auto resultCreate = FikoEngine::CommandPool::Create( nullptr, 0 );

    ASSERT_EQ( resultCreate.status, FikoEngine::CommandPoolState::Created );
    ASSERT_NE( resultCreate.value, nullptr );

    auto resultEnd = resultCreate.value->EndCommandBuffer( 0 );

    ASSERT_EQ( resultEnd.status, FikoEngine::CommandBufferState::Invalid );

    VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL();
    VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS().Times( AtLeast( 1 ) );

    auto resultDestroy = FikoEngine::CommandPool::Destroy( resultCreate.value );

    ASSERT_EQ( resultDestroy.status, FikoEngine::CommandPoolState::Destroyed );

    VKINTERFACE_DESTROY_MOCK();
}