#pragma once
#include <Core/Result.hpp>
#include <gtest/gtest.h>

TEST( Result_Tests, Result_Test1 )
{
    FikoEngine::Result<bool,uint32_t> result;
    result.status = false;
    result.returnValue = 10;

    ASSERT_EQ( result.status, false );
    ASSERT_EQ( result.returnValue, 10 );
}

TEST( Result_Tests, Result_Test2 )
{
    FikoEngine::Result<bool, uint32_t> result;
    result.status = true;
    result.returnValue = 3;

    ASSERT_EQ( ( bool ) result, true );
    ASSERT_EQ( ( uint32_t ) result, 3 );
}
