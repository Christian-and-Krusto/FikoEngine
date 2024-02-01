cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(PROJECT_NAME "FikoEngine")

project(${PROJECT_NAME})

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message("C++ standard Version: ${CMAKE_CXX_STANDARD}")
message("System Architecture: ${CMAKE_GENERATOR_PLATFORM}")

message("${PROJECT_NAME}: Adding lwlog")
add_subdirectory(vendor/lwlog)

message("${PROJECT_NAME}: Adding source files")

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES ./${PROJECT_NAME}Lib/src/*.cpp)
file(GLOB_RECURSE ${PROJECT_NAME}_HEADER_FILES ./${PROJECT_NAME}Lib/src/*.hpp)

file(GLOB_RECURSE ${PROJECT_NAME}_EDITOR_SOURCE_FILES ./${PROJECT_NAME}Editor/src/*.cpp)
file(GLOB_RECURSE ${PROJECT_NAME}_EDITOR_HEADER_FILES ./${PROJECT_NAME}Editor/src/*.hpp)

file(GLOB_RECURSE SANDBOX_SOURCE_FILES ./Sandbox/src/*.cpp)
file(GLOB_RECURSE SANDBOX_HEADER_FILES ./Sandbox/src/*.h)

if (WIN32)
    # for Windows operating system in general
else ()
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})
    add_definitions(-D_LINUX)
endif ()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(${PROJECT_NAME}Lib STATIC ${FikoEngine_SOURCE_FILES} )

set(LWLOG_INCLUDE_DIR "./vendor/lwlog/lwlog/src")
set(${PROJECT_NAME}_INCLUDE_DIR "./${PROJECT_NAME}Lib/src")

target_include_directories(${PROJECT_NAME}Lib PUBLIC ${FikoEngine_INCLUDE_DIR} ${LWLOG_INCLUDE_DIR})

set_target_properties(${PROJECT_NAME}Lib PROPERTIES LINKER_LANGUAGE CXX)
add_library(${PROJECT_NAME}InterfaceLibrary INTERFACE)

message("${PROJECT_NAME}: Linking libraries")

target_precompile_headers (${PROJECT_NAME}Lib PUBLIC ${PROJECT_NAME}Lib/src/Core/${PROJECT_NAME}.pch.h)

target_link_libraries(${PROJECT_NAME}InterfaceLibrary INTERFACE
        LWLOG
        )

target_link_libraries(${PROJECT_NAME}Lib PUBLIC ${PROJECT_NAME}InterfaceLibrary)

add_executable(Sandbox ${SANDBOX_HEADER_FILES} ${SANDBOX_SOURCE_FILES})

target_include_directories(Sandbox PRIVATE ${${PROJECT_NAME}_INCLUDE_DIR})
target_link_libraries(Sandbox PRIVATE ${PROJECT_NAME}Lib)

add_executable(${PROJECT_NAME}Editor ${FikoEngine_EDITOR_SOURCE_FILES})

target_include_directories(${PROJECT_NAME}Editor PRIVATE ${FikoEngine_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}Editor PRIVATE ${PROJECT_NAME}Lib)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME}Lib PRIVATE -static-libstdc++ -Wall -pedantic)
    target_compile_options(${PROJECT_NAME}Editor PRIVATE -static-libstdc++ -Wall -pedantic)
    target_compile_options(Sandbox PRIVATE -static-libstdc++ 
    # -Wall
    # -pedantic
     )
endif ()
