#pragma once
#include "../Core/FikoEngineLib_VkInterfaceMocked.hpp"

#include <Renderer/GraphicsPipeline.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// TEST( Renderer_Tests, Image_Test1 )
// {
//     using namespace testing;
//     using namespace FikoEngine::tests;

//     VKINTERFACE_CREATE_MOCK();

//     FikoEngine::GraphicsPipelineSpec graphicsPipelineSpec;
//     graphicsPipelineSpec.extent = vk::Extent2D(1280,720);    

//     FikoEngine::GraphicsPipeline graphicsPipeline;

    // auto result = graphicsPipeline.Init(vk::Device(),graphicsPipelineSpec);

    // ASSERT_EQ( result.status, FikoEngine:: );

//     VKINTERFACE_DESTROY_MOCK();
// }
