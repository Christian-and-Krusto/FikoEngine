
file(GLOB_RECURSE SANDBOX_SOURCE_FILES ./src/*.cpp)
file(GLOB_RECURSE SANDBOX_HEADER_FILES ./src/*.h)

add_executable(Sandbox ${SANDBOX_SOURCE_FILES})

target_include_directories(Sandbox PRIVATE ${FikoEngine_INCLUDE_DIR})
target_link_libraries(Sandbox PRIVATE FikoEngineLib)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Sandbox PRIVATE -static-libstdc++ -Wall -pedantic)
endif ()