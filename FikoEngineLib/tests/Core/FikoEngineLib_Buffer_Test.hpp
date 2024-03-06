#pragma once

#include <Core/Buffer.hpp>
#include <gtest/gtest.h>

TEST( Buffer_Tests, Buffer_Test1 )
{
    constexpr size_t bufferSize = 100;
    uint8_t* localBuffer = new uint8_t[ bufferSize ];

    FikoEngine::Buffer buffer( localBuffer, bufferSize );

    ASSERT_EQ( buffer.Data, localBuffer );
    ASSERT_EQ( buffer.Size, bufferSize );

}

TEST( Buffer_Tests, Buffer_Test2 )
{
    constexpr size_t bufferSize = 100;
    uint8_t* localBuffer = new uint8_t[ bufferSize ];

    FikoEngine::Buffer buffer( localBuffer, bufferSize );

    ASSERT_EQ( buffer.As<uint8_t>(), localBuffer );
    ASSERT_EQ( buffer.GetSize(), bufferSize );
}

TEST( Buffer_Tests, Buffer_Test3 )
{
    constexpr size_t bufferSize = 100;
    uint8_t* localBuffer = new uint8_t[ bufferSize ];

    FikoEngine::Buffer buffer( localBuffer, bufferSize );

    ASSERT_EQ( buffer.As<uint8_t>(), localBuffer );
    ASSERT_EQ( buffer.GetSize(), bufferSize );
}

TEST( Buffer_Tests, Buffer_Test4 )
{
    constexpr size_t bufferSize = 5;
    uint8_t localBuffer[ bufferSize ] = { 1, 2, 3, 4, 5 };

    FikoEngine::Buffer buffer = FikoEngine::Buffer::Copy( localBuffer, bufferSize );

    ASSERT_EQ( buffer.GetSize(), bufferSize );

    for ( size_t i = 0; i < bufferSize; ++i ) { ASSERT_EQ( buffer.Read<uint8_t>( i ), localBuffer[ i ] ); }
}

TEST( Buffer_Tests, Buffer_Test5 )
{
    constexpr size_t bufferSize = 5;
    uint8_t localBuffer[ bufferSize ] = { 1, 2, 3, 4, 5 };

    FikoEngine::Buffer buffer = FikoEngine::Buffer::Copy( localBuffer, bufferSize );

    ASSERT_EQ( buffer.GetSize(), bufferSize );

    for ( size_t i = 0; i < bufferSize; ++i ) { ASSERT_EQ( buffer[ i ], localBuffer[ i ] ); }
}

TEST( Buffer_Tests, Buffer_Test6 )
{
    constexpr size_t bufferSize = 5;
    uint8_t localBuffer[ bufferSize ] = { 1, 2, 3, 4, 5 };

    FikoEngine::Buffer buffer = FikoEngine::Buffer::Copy( localBuffer, bufferSize );

    ASSERT_EQ( buffer.GetSize(), bufferSize );

    auto data = buffer.ReadBytes( bufferSize, 0 );

    for ( size_t i = 0; i < bufferSize; ++i ) { ASSERT_EQ( data[ i ], localBuffer[ i ] ); }
}

TEST( Buffer_Tests, Buffer_Test7 )
{
    constexpr size_t bufferSize = 5;
    constexpr size_t offset = 2;
    uint8_t localBuffer[ bufferSize ] = { 1, 2, 3, 4, 5 };

    FikoEngine::Buffer buffer = FikoEngine::Buffer::Copy( localBuffer, bufferSize );

    ASSERT_EQ( buffer.GetSize(), bufferSize );

    auto data = buffer.ReadBytes( bufferSize - offset, offset );

    for ( size_t i = 0; i < bufferSize - offset; ++i ) { ASSERT_EQ( data[ i ], localBuffer[ i + offset ] ); }
}