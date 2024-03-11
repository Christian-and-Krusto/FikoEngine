#include "Core/FikoEngineLib_Buffer_Test.hpp"
#include "Core/FikoEngineLib_LayerStack_Test.hpp"
#include "Core/FikoEngineLib_Ref_Test.hpp"
#include "Core/FikoEngineLib_Result_Test.hpp"
#include "Core/FikoEngineLib_Timestep_Test.hpp"
#include "Core/FikoEngineLib_UUID_Test.hpp"
#include "Renderer/FikoEngineLib_CommandPool_Test.hpp"
#include "Renderer/FikoEngineLib_GraphicsPipeline_Test.hpp"
#include "Renderer/FikoEngineLib_Image_Test.hpp"
#include "Renderer/FikoEngineLib_MemoryBuffer_Test.hpp"

#include <gtest/gtest.h>

int main( int argc, char** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}