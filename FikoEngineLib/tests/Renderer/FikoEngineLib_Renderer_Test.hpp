#pragma once
#include "../Core/FikoEngineLib_VkInterfaceMocked.hpp"

#include <Renderer/Renderer.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST( Renderer_Tests, Renderer_Test1 )
{
    using namespace testing;
    using namespace FikoEngine::tests;

    // VKINTERFACE_CREATE_MOCK();

    // FikoEngine::RendererSpec rendererSpec;
    // rendererSpec.WorkingDirectory = "./";
    // rendererSpec.AppName = "UT Renderer";
    // rendererSpec.width = 800;
    // rendererSpec.height = 600;
    
    // FikoEngine::Renderer<> renderer;
    // auto result = renderer.Init(rendererSpec);
    // ASSERT_EQ( result, vk::Result::eSuccess );

    // result = renderer.DeInit();
    auto result = vk::Result::eErrorCompressionExhaustedEXT;
    ASSERT_EQ( result, vk::Result::eSuccess );

    // VKINTERFACE_DESTROY_MOCK();
}
