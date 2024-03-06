#pragma once
#include <Core/Timestep.hpp>

#include <gtest/gtest.h>

TEST( Timestep_Tests, Timestep_Test1 )
{
    FikoEngine::Timestep timestep( 10 );

    ASSERT_EQ( timestep.Time(), 10 );
}

TEST( Timestep_Tests, Timestep_Test2 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 50 );
    ASSERT_EQ( timestep.Time(), 50 );
}

TEST( Timestep_Tests, Timestep_Test3 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 3 );
    ASSERT_EQ( timestep.ToMillis(), 3000 );
}

TEST( Timestep_Tests, Timestep_Test4 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 3 );
    ASSERT_EQ( timestep.ToMicros(), 3000000 );
}

TEST( Timestep_Tests, Timestep_Test5 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 3 );
    timestep = timestep - FikoEngine::Timestep(1);

    ASSERT_EQ( timestep.Time(), 2 );
}

TEST( Timestep_Tests, Timestep_Test6 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 1 );
    timestep = timestep + FikoEngine::Timestep( 3 );

    ASSERT_EQ( timestep.Time(), 4 );
}

TEST( Timestep_Tests, Timestep_Test7 )
{
    FikoEngine::Timestep timestep;
    timestep.SetTime( 1 );

    ASSERT_EQ( timestep, 1 );
}
