#pragma once
#include <gtest/gtest.h>
#include <Core/UUID.hpp>

TEST( UUID_Tests, UUID_Test1 )
{
    for ( size_t i = 0; i < 100000; i++ )
    {
        FikoEngine::UUID uuid;

        ASSERT_GT( uuid.GetID(), 0 );
        ASSERT_LT( uuid.GetID(), UINT64_MAX );
    }
}

TEST( UUID_Tests, UUID_Test2 )
{
    for ( size_t i = 0; i < 100000; i++ )
    {
        FikoEngine::UUID uuid;

        ASSERT_GT( uuid, 0 );
        ASSERT_LT( uuid, UINT64_MAX );
    }
}

TEST( UUID_Tests, UUID32_Test1 )
{
    for ( size_t i = 0; i < 100000; i++ )
    {
        FikoEngine::UUID32 uuid;

        ASSERT_GT( uuid.GetID(), 0 );
        ASSERT_LT( uuid.GetID(), UINT32_MAX );
    }
}

TEST( UUID_Tests, UUID32_Test2 )
{
    for ( size_t i = 0; i < 100000; i++ )
    {
        FikoEngine::UUID32 uuid;

        ASSERT_GT( uuid, 0 );
        ASSERT_LT( uuid, UINT32_MAX );
    }
}