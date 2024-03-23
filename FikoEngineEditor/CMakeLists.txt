
file(GLOB_RECURSE FikoEngine_EDITOR_SOURCE_FILES ${CMAKE_SOURCE_DIR}/FikoEngineEditor/src/*.cpp)
file(GLOB_RECURSE FikoEngine_EDITOR_HEADER_FILES ./src/*.hpp)

add_executable(FikoEngineEditor ${FikoEngine_EDITOR_SOURCE_FILES})

target_include_directories(FikoEngineEditor PRIVATE ${FikoEngine_INCLUDE_DIR})
target_link_libraries(FikoEngineEditor PRIVATE 
        C:/VulkanSDK/1.3.261.1/Lib/vulkan-1.lib
 FikoEngineLib)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(FikoEngineEditor PRIVATE -static-libstdc++ -Wall -pedantic)
endif ()