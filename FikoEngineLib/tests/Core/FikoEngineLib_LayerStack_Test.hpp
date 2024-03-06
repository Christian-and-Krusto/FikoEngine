#pragma once
#include <Core/LayerStack.hpp>
#include <gtest/gtest.h>

TEST( LayerStack_Tests, LayerStack_Test1 )
{
    using namespace FikoEngine;
    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );
    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test2 )
{
    using namespace FikoEngine;
    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );
    layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Error );

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test3 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Error );
}

TEST( LayerStack_Tests, LayerStack_Test4 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );

    auto layerStackGetResult = LayerStack::Get();
    ASSERT_EQ( layerStackGetResult.status, LayerStackStatus::Success );
    ASSERT_NE( layerStackGetResult.returnValue, nullptr );

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test5 )
{
    using namespace FikoEngine;

    auto layerStackGetResult = LayerStack::Get();
    ASSERT_EQ( layerStackGetResult.status, LayerStackStatus::Error );
    ASSERT_EQ( layerStackGetResult.returnValue, nullptr );
}

TEST( LayerStack_Tests, LayerStack_Test6 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );

    layerStackStatus = LayerStack::InitLayers();
    ASSERT_EQ(layerStackStatus.status, LayerStackStatus::Initialized);

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test7 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::InitLayers();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Error );
}

TEST( LayerStack_Tests, LayerStack_Test8 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );

    layerStackStatus = LayerStack::DestroyLayers();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test9 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::DestroyLayers();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Error );
}

TEST( LayerStack_Tests, LayerStack_Test10 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );

    auto layerStackGetLayerStatus = LayerStack::GetLayer("test");
    ASSERT_EQ( layerStackGetLayerStatus.status, LayerStatus::Error );

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}

TEST( LayerStack_Tests, LayerStack_Test11 )
{
    using namespace FikoEngine;

    auto layerStackGetLayerStatus = LayerStack::GetLayer( "test" );
    ASSERT_EQ( layerStackGetLayerStatus.status, LayerStatus::Error );

}

TEST( LayerStack_Tests, LayerStack_Test12 )
{
    using namespace FikoEngine;

    auto layerStackGetLayersStatus = LayerStack::GetLayers();
    ASSERT_EQ( layerStackGetLayersStatus.status, LayerStatus::Error );
}

TEST( LayerStack_Tests, LayerStack_Test13 )
{
    using namespace FikoEngine;

    auto layerStackStatus = LayerStack::Init();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Initialized );

    auto layerStackGetLayersStatus = LayerStack::GetLayers();
    ASSERT_EQ( layerStackGetLayersStatus.status, LayerStatus::Success );

    layerStackStatus = LayerStack::Destroy();
    ASSERT_EQ( layerStackStatus.status, LayerStackStatus::Destroyed );
}