#pragma once
#include "../Core/FikoEngineLib_VkInterfaceMocked.hpp"

#include <Renderer/MemoryBuffer.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockedMemoryBuffer: public FikoEngine::MemoryBuffer
{
public:
    MockedMemoryBuffer() = default;
    ~MockedMemoryBuffer() = default;
};

TEST( Renderer_Tests, MemoryBuffer_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    vk::MemoryRequirements memoryRequirements;
    memoryRequirements.size = 0;
    vk::PhysicalDeviceMemoryProperties memoryProperties;
    MockedMemoryBuffer memoryBuffer;

    auto result = memoryBuffer.InitMemoryBuffer( VK_NULL_HANDLE, VK_NULL_HANDLE, memoryProperties, memoryRequirements,
                                                 vk::MemoryPropertyFlagBits::eDeviceLocal );

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::CanNotAllocateMemory );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, MemoryBuffer_Test2 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    vk::MemoryRequirements memoryRequirements;
    memoryRequirements.size = 10;
    memoryRequirements.memoryTypeBits = UINT32_MAX;
    vk::PhysicalDeviceMemoryProperties memoryProperties;
    
    MockedMemoryBuffer memoryBuffer;

    auto result = memoryBuffer.InitMemoryBuffer( VK_NULL_HANDLE, VK_NULL_HANDLE, memoryProperties, memoryRequirements,
                                                 vk::MemoryPropertyFlagBits::eDeviceLocal );

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::CanNotFindMemoryType );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, MemoryBuffer_Test3 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    vk::MemoryRequirements memoryRequirements;
    memoryRequirements.size = 10;
    memoryRequirements.memoryTypeBits = UINT32_MAX;
    vk::PhysicalDeviceMemoryProperties memoryProperties;
    memoryProperties.memoryTypeCount = 3;
    memoryProperties.memoryTypes[ 1 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_ALLOCATE_MEMORY();
    VKINTERFACE_ON_ALLOCATE_MEMORY(vk::Result::eErrorOutOfDeviceMemory);

    MockedMemoryBuffer memoryBuffer;
    auto result = memoryBuffer.InitMemoryBuffer( VK_NULL_HANDLE, VK_NULL_HANDLE, memoryProperties, memoryRequirements,
                                                 vk::MemoryPropertyFlagBits::eDeviceLocal );

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::CanNotAllocateMemory );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, MemoryBuffer_Test4 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    vk::MemoryRequirements memoryRequirements;
    memoryRequirements.size = 10;
    memoryRequirements.memoryTypeBits = UINT32_MAX;
    vk::PhysicalDeviceMemoryProperties memoryProperties;
    memoryProperties.memoryTypeCount = 3;
    memoryProperties.memoryTypes[ 1 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_ALLOCATE_MEMORY();
    VKINTERFACE_ON_ALLOCATE_MEMORY( vk::Result::eSuccess );

    MockedMemoryBuffer memoryBuffer;
    auto result = memoryBuffer.InitMemoryBuffer( VK_NULL_HANDLE, VK_NULL_HANDLE, memoryProperties, memoryRequirements,
                                                 vk::MemoryPropertyFlagBits::eDeviceLocal );

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::Success );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, MemoryBuffer_Test5 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();
    VKINTERFACE_EXPECT_BIND_BUFFER_MEMORY();
    VKINTERFACE_ON_BIND_BUFFER_MEMORY(FikoEngine::ResultValueType(vk::Result::eSuccess));
    MockedMemoryBuffer memoryBuffer;
    auto result = memoryBuffer.BindBuffer(VK_NULL_HANDLE,VK_NULL_HANDLE);

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::Bound );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, MemoryBuffer_Test6 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();
    VKINTERFACE_EXPECT_BIND_BUFFER_MEMORY();
    VKINTERFACE_ON_BIND_BUFFER_MEMORY( FikoEngine::ResultValueType( vk::Result::eErrorOutOfDeviceMemory ) );

    MockedMemoryBuffer memoryBuffer;
    auto result = memoryBuffer.BindBuffer( VK_NULL_HANDLE, VK_NULL_HANDLE );

    ASSERT_EQ( result.status, FikoEngine::BufferStatus::CanNotBindMemory );

    VKINTERFACE_DESTROY_MOCK();
}
