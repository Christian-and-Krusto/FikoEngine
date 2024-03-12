#pragma once

#include <Core/VulkanInterface.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vulkan/vulkan.hpp>

namespace FikoEngine::tests
{


}// namespace FikoEngine::tests

class MockedVkInterface: public FikoEngine::vkInterface
{
public:
    MockedVkInterface() = default;
    ~MockedVkInterface() = default;

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::CommandPool> ), _CreateCommandPool,
                 ( vk::Device device, uint32_t graphicsQueueFamilyIndex ), ( override ) );

    MOCK_METHOD( void, _DestroyCommandPool, ( vk::Device device, vk::CommandPool commandPool ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, std::vector<vk::CommandBuffer>> ), _AllocateCommandBuffers,
                 ( vk::Device device, const vk::CommandBufferAllocateInfo& allocateInfo ), ( override ) );

    MOCK_METHOD( void, _FreeCommandBuffers,
                 ( vk::Device device, vk::CommandPool commandPool, vk::CommandBuffer buffer ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<> ), _CommandBufferBegin,
                 ( vk::CommandBuffer buffer, vk::CommandBufferBeginInfo beginInfo ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<> ), _CommandBufferEnd, ( vk::CommandBuffer buffer ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::FormatProperties> ), _GetFormatProperties,
                 ( vk::PhysicalDevice physicalDevice, vk::Format format ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::Image> ), _CreateImage,
                 ( vk::Device device, vk::ImageCreateInfo& imageCreateInfo ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> ), _GetMemoryProperties,
                 ( vk::PhysicalDevice physicalDevice ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> ), _GetImageMemoryRequirements,
                 ( vk::Device device, vk::Image image ), ( override ) );

    MOCK_METHOD((FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements>), _GetBufferMemoryRequirements,( vk::Device device,
                                                                                          vk::Buffer buffer ),(override));

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::DeviceMemory> ), _AllocateMemory,
                 ( vk::Device device, vk::MemoryAllocateInfo& memoryAllocateInfo ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::ImageView> ), _CreateImageView,
                 ( vk::Device device, vk::ImageViewCreateInfo& imageViewCreateInfo ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<> ), _BindImageMemory,
                 ( vk::Device device, vk::Image image, vk::DeviceMemory memory, vk::DeviceSize memoryOffset ),
                 ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<> ), _BindBufferMemory,
                 ( vk::Device device, vk::Buffer buffer, vk::DeviceMemory memory, vk::DeviceSize memoryOffset ),
                 ( override ) );
    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, void*> ), _MapMemory,
                 ( vk::Device device, vk::DeviceMemory memory, vk::DeviceSize offset, vk::DeviceSize size,
                   vk::MemoryMapFlags flags ),
                 ( override ) );

    MOCK_METHOD( ( void ), _UnmapMemory, ( vk::Device device, vk::DeviceMemory memory ), ( override ) );
    MOCK_METHOD( ( FikoEngine::ResultValue<vk::Result, vk::Buffer> ), _CreateBuffer,
                 ( vk::Device device, vk::BufferCreateInfo bufferCreateInfo ), ( override ) );
};

#define VKRESULT( type, res ) FikoEngine::ResultValue<vk::Result, decltype( type() )>( res )

#define VKINTERFACE_CREATE_MOCK()                                                                                      \
    FikoEngine::vkInterface::RegisterMockPtr<MockedVkInterface>();                                                     \
    MockedVkInterface* mockRef = FikoEngine::vkInterface::GetMockPtr<MockedVkInterface>()

#define VKINTERFACE_DESTROY_MOCK() FikoEngine::vkInterface::DestroyMockPtr<MockedVkInterface>()

#define VKINTERFACE_EXPECT_CREATE_COMMAND_POOL() EXPECT_CALL( *mockRef, _CreateCommandPool )
#define VKINTERFACE_ON_CREATE_COMMAND_POOL( retVal )                                                                   \
    ON_CALL( *mockRef, _CreateCommandPool( _, _ ) ).WillByDefault( Return( VKRESULT( vk::CommandPool, retVal ) ) );

#define VKITNERFACE_EXPECT_ALLOCATE_COMMAND_BUFFERS() EXPECT_CALL( *mockRef, _AllocateCommandBuffers )
#define VKINTERFACE_ON_ALLOCATE_COMMAND_BUFFERS( func )                                                                \
    ON_CALL( *mockRef, _AllocateCommandBuffers( _, _ ) ).WillByDefault( func );

#define VKINTERFACE_EXPECT_COMMAND_BUFFER_BEGIN() EXPECT_CALL( *mockRef, _CommandBufferBegin )
#define VKINTERFACE_ON_COOMMAND_BUFFER_BEGIN( retVal )                                                                 \
    ON_CALL( *mockRef, _CommandBufferBegin( _, _ ) )                                                                   \
            .WillByDefault( Return( ( FikoEngine::ResultValueType{ retVal } ) ) );

#define VKINTERFACE_EXPECT_COMMAND_BUFFER_END() EXPECT_CALL( *mockRef, _CommandBufferEnd )
#define VKINTERFACE_ON_COOMMAND_BUFFER_END( retVal )                                                                   \
    ON_CALL( *mockRef, _CommandBufferEnd( _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_DESTROY_COMMAND_POOL() EXPECT_CALL( *mockRef, _DestroyCommandPool )
#define VKINTERFACE_ON_DESTROY_COMMAND_POOL( retVal )                                                                  \
    ON_CALL( *mockRef, _DestroyCommandPool( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_FREE_COMMAND_BUFFERS() EXPECT_CALL( *mockRef, _FreeCommandBuffers )
#define VKINTERFACE_ON_FREE_COMMAND_BUFFERS()                                                                          \
    ON_CALL( *mockRef, _FreeCommandBuffers( _, _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES() EXPECT_CALL( *mockRef, _GetFormatProperties )
#define VKINTERFACE_ON_GET_FORMAT_PROPERTIES( retVal )                                                                 \
    ON_CALL( *mockRef, _GetFormatProperties( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_CREATE_IMAGE() EXPECT_CALL( *mockRef, _CreateImage )
#define VKINTERFACE_ON_CREATE_IMAGE( retVal )                                                                          \
    ON_CALL( *mockRef, _CreateImage( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES() EXPECT_CALL( *mockRef, _GetMemoryProperties )
#define VKINTERFACE_ON_GET_MEMORY_PROPERTIES( retVal )                                                                 \
    ON_CALL( *mockRef, _GetMemoryProperties( _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS() EXPECT_CALL( *mockRef, _GetImageMemoryRequirements )
#define VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( retVal )                                                         \
    ON_CALL( *mockRef, _GetImageMemoryRequirements( _, _ ) ).WillByDefault( Return( retVal ) );

#define VKINTERFACE_EXPECT_ALLOCATE_MEMORY() EXPECT_CALL( *mockRef, _AllocateMemory )
#define VKINTERFACE_ON_ALLOCATE_MEMORY( retVal )                                                                       \
    ON_CALL( *mockRef, _AllocateMemory( _, _ ) ).WillByDefault( Return( VKRESULT( vk::DeviceMemory, retVal ) ) );

#define VKINTERFACE_EXPECT_CREATE_IMAGE_VIEW() EXPECT_CALL( *mockRef, _CreateImageView )
#define VKINTERFACE_ON_CREATE_IMAGE_VIEW( retVal )                                                                     \
    ON_CALL( *mockRef, _CreateImageView( _, _ ) ).WillByDefault( Return( VKRESULT( vk::ImageView, retVal ) ) );

#define VKINTERFACE_EXPECT_BIND_IMAGE_MEMORY() EXPECT_CALL( *mockRef, _BindImageMemory )
#define VKINTERFACE_ON_BIND_IMAGE_MEMORY( retVal )                                                                     \
    ON_CALL( *mockRef, _BindImageMemory( _, _, _, _ ) ).WillByDefault( Return( retVal ) );


#define VKINTERFACE_EXPECT_BIND_BUFFER_MEMORY() EXPECT_CALL( *mockRef, _BindBufferMemory )
#define VKINTERFACE_ON_BIND_BUFFER_MEMORY( retVal )                                                                     \
    ON_CALL( *mockRef, _BindBufferMemory( _, _, _, _ ) ).WillByDefault( Return( retVal ) );
