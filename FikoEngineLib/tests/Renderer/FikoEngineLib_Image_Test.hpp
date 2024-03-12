#pragma once
#include "../Core/FikoEngineLib_VkInterfaceMocked.hpp"
#include <Renderer/Image.hpp>
#include <Renderer/MemoryBuffer.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockMemoryBuffer: public FikoEngine::MemoryBuffer
{
public:
    MockMemoryBuffer() = default;
    ~MockMemoryBuffer() = default;

public:
    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::BufferStatus> ), InitMemoryBuffer,
                 ( vk::PhysicalDevice physicalDevice, vk::Device device,
                   vk::PhysicalDeviceMemoryProperties& memoryProperties, vk::MemoryRequirements& memoryRequirements,
                   vk::MemoryPropertyFlags flags ),
                 ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::BufferStatus> ), BindBuffer,
                 ( vk::Device device, vk::Buffer buffer ), ( override ) );
    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::BufferStatus> ), BindImage,
                 ( vk::Device device, vk::Image image ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::BufferStatus> ), CopyData,
                 ( vk::Device device, uint8_t* data, size_t size ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::BufferStatus> ), DestroyMemoryBuffer, ( vk::Device device ),
                 ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<FikoEngine::BufferStatus, uint32_t> ), FindMemoryTypeIndex,
                 ( vk::PhysicalDeviceMemoryProperties & memoryProperties, vk::MemoryRequirements& memoryRequirements,
                   vk::MemoryPropertyFlags propertyFlags ),
                 ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValue<FikoEngine::BufferStatus, vk::DeviceMemory> ), AllocateMemory,
                 ( vk::PhysicalDevice physicalDevice, vk::Device device,
                   vk::PhysicalDeviceMemoryProperties& memoryProperties, vk::MemoryRequirements& memoryRequirements,
                   vk::MemoryPropertyFlags memoryMask ),
                 ( override ) );
};

template <typename T = MockMemoryBuffer>
class FikoEngineMockImage: public FikoEngine::Image<T>
{
public:
    FikoEngineMockImage() = default;
    ~FikoEngineMockImage() = default;

public:
    MOCK_METHOD( ( FikoEngine::ResultValue<FikoEngine::ImageStatus, vk::ImageTiling> ), ChooseImageTiling,
                 ( vk::FormatProperties & formatProperties ), ( override ) );

    MOCK_METHOD( ( FikoEngine::ResultValueType<FikoEngine::ImageStatus> ), GetImageFlags,
                 ( FikoEngine::ImageType type, vk::ImageUsageFlags& usageFlags, vk::ImageAspectFlags& aspectFlags ),
                 ( override ) );
};

#define FIKOENGINE_IMAGE_CREATE_MOCK() FikoEngineMockImage* imageMockPtr = new FikoEngineMockImage();

#define FIKOENGINE_IMAGE_DESTROY_MOCK() delete ( FikoEngineMockImage* ) imageMockPtr;

TEST( Renderer_Tests, Image_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );

    vk::FormatProperties dummyProperties{};

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    FikoEngine::Image image;

    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotChooseTiling );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test2 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );

    vk::FormatProperties dummyProperties{};
    dummyProperties.linearTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    FikoEngine::Image image;
    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotChooseImageFlags );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test3 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    FikoEngine::Image image;
    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotChooseImageFlags );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test4 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eErrorOutOfHostMemory, VK_NULL_HANDLE ) ) );

    FikoEngine::Image image;
    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::Fail );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test5 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eErrorOutOfDeviceMemory, VK_NULL_HANDLE ) ) );

    FikoEngine::Image image;
    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::Fail );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test6 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> memoryProperties;
    FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> memoryRequirements;
    VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES();
    VKINTERFACE_ON_GET_MEMORY_PROPERTIES( memoryProperties );
    VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS();
    VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( memoryRequirements );

    VKINTERFACE_ON_CREATE_IMAGE_VIEW( vk::Result::eSuccess );

    FikoEngine::Image<MockMemoryBuffer> image;

    EXPECT_CALL(image.GetMemoryBuffer(),InitMemoryBuffer);
    ON_CALL( image.GetMemoryBuffer(), InitMemoryBuffer( _, _, _, _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::CanNotFindMemoryType ) );

    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotFindMemoryType );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test7 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> memoryProperties;
    FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> memoryRequirements;

    memoryProperties.value.memoryTypeCount = 1;
    memoryRequirements.value.memoryTypeBits = UINT32_MAX;
    memoryProperties.value.memoryTypes[ 0 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES();
    VKINTERFACE_ON_GET_MEMORY_PROPERTIES( memoryProperties );
    VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS();
    VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( memoryRequirements );

    FikoEngine::Image<MockMemoryBuffer> image;

    EXPECT_CALL( image.GetMemoryBuffer(), InitMemoryBuffer );
    ON_CALL( image.GetMemoryBuffer(), InitMemoryBuffer( _, _, _, _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::CanNotAllocateMemory ) );

    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotAllocateMemory );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test8 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> memoryProperties;
    FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> memoryRequirements;

    memoryProperties.value.memoryTypeCount = 1;
    memoryRequirements.value.memoryTypeBits = UINT32_MAX;
    memoryProperties.value.memoryTypes[ 0 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES();
    VKINTERFACE_ON_GET_MEMORY_PROPERTIES( memoryProperties );
    VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS();
    VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( memoryRequirements );

    FikoEngine::Image<MockMemoryBuffer> image;
    EXPECT_CALL( image.GetMemoryBuffer(), InitMemoryBuffer );
    ON_CALL( image.GetMemoryBuffer(), InitMemoryBuffer( _, _, _, _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::Success ) );

    EXPECT_CALL( image.GetMemoryBuffer(), BindImage );
    ON_CALL( image.GetMemoryBuffer(), BindImage( _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::CanNotBindMemory ) );

    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotBindImageMemory );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test9 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> memoryProperties;
    FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> memoryRequirements;

    memoryProperties.value.memoryTypeCount = 1;
    memoryRequirements.value.memoryTypeBits = UINT32_MAX;
    memoryProperties.value.memoryTypes[ 0 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES();
    VKINTERFACE_ON_GET_MEMORY_PROPERTIES( memoryProperties );
    VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS();
    VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( memoryRequirements );

    VKINTERFACE_EXPECT_CREATE_IMAGE_VIEW();
    VKINTERFACE_ON_CREATE_IMAGE_VIEW( ( FikoEngine::ResultValue<vk::Result, vk::ImageView>(
            vk::Result::eErrorOutOfDeviceMemory, VK_NULL_HANDLE ) ) );

    FikoEngine::Image<MockMemoryBuffer> image;
    EXPECT_CALL( image.GetMemoryBuffer(), InitMemoryBuffer );
    ON_CALL( image.GetMemoryBuffer(), InitMemoryBuffer( _, _, _, _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::Success ) );

    EXPECT_CALL( image.GetMemoryBuffer(), BindImage );
    ON_CALL( image.GetMemoryBuffer(), BindImage( _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::Bound ) );

    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::CanNotCreateImageView );

    VKINTERFACE_DESTROY_MOCK();
}

TEST( Renderer_Tests, Image_Test10 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    VKINTERFACE_CREATE_MOCK();

    FikoEngine::ImageSpec imageSpec;
    imageSpec.extent = vk::Extent2D( 1280, 720 );
    imageSpec.type = FikoEngine::ImageType::Depth;

    vk::FormatProperties dummyProperties{};
    dummyProperties.optimalTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;
    dummyProperties.linearTilingFeatures = vk::FormatFeatureFlagBits::eDepthStencilAttachment;

    VKINTERFACE_EXPECT_GET_FORMAT_PROPERTIES();
    VKINTERFACE_ON_GET_FORMAT_PROPERTIES( ( FikoEngine::ResultValue( vk::Result::eSuccess, dummyProperties ) ) );

    VKINTERFACE_EXPECT_CREATE_IMAGE();
    VKINTERFACE_ON_CREATE_IMAGE(
            ( FikoEngine::ResultValue<vk::Result, vk::Image>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::ResultValue<vk::Result, vk::PhysicalDeviceMemoryProperties> memoryProperties;
    FikoEngine::ResultValue<vk::Result, vk::MemoryRequirements> memoryRequirements;

    memoryProperties.value.memoryTypeCount = 1;
    memoryRequirements.value.memoryTypeBits = UINT32_MAX;
    memoryProperties.value.memoryTypes[ 0 ].propertyFlags = vk::MemoryPropertyFlagBits::eDeviceLocal;

    VKINTERFACE_EXPECT_GET_MEMORY_PROPERTIES();
    VKINTERFACE_ON_GET_MEMORY_PROPERTIES( memoryProperties );
    VKINTERFACE_EXPECT_GET_IMAGE_MEMORY_REQUIREMENTS();
    VKINTERFACE_ON_GET_IMAGE_MEMORY_REQUIREMENTS( memoryRequirements );

    VKINTERFACE_EXPECT_CREATE_IMAGE_VIEW();
    VKINTERFACE_ON_CREATE_IMAGE_VIEW(
            ( FikoEngine::ResultValue<vk::Result, vk::ImageView>( vk::Result::eSuccess, VK_NULL_HANDLE ) ) );

    FikoEngine::Image<MockMemoryBuffer> image;
    EXPECT_CALL( image.GetMemoryBuffer(), InitMemoryBuffer );
    ON_CALL( image.GetMemoryBuffer(), InitMemoryBuffer( _, _, _, _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::Success ) );

    EXPECT_CALL( image.GetMemoryBuffer(), BindImage );
    ON_CALL( image.GetMemoryBuffer(), BindImage( _, _ ) )
            .WillByDefault( Return( FikoEngine::BufferStatus::Bound ) );
    auto result = image.Init( VK_NULL_HANDLE, VK_NULL_HANDLE, imageSpec );

    ASSERT_EQ( result.status, FikoEngine::ImageStatus::Success );

    VKINTERFACE_DESTROY_MOCK();
}
