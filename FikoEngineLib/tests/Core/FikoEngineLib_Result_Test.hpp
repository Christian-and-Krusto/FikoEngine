#pragma once
#include <Core/Result.hpp>
#include <gtest/gtest.h>

TEST( Result_Tests, Result_Test1 )
{
    FikoEngine::ResultValue<bool,uint32_t> result;
    result.status = false;
    result.value = 10;

    ASSERT_EQ( result.status, false );
    ASSERT_EQ( result.value, 10 );
}

TEST( Result_Tests, Result_Test2 )
{
    FikoEngine::ResultValue<bool, uint32_t> result;
    result.status = true;
    result.value = 3;

    ASSERT_EQ( ( bool ) result, true );
    ASSERT_EQ( ( uint32_t ) result, 3 );
}
