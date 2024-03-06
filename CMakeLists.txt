cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(SHADERC_SKIP_TESTS  ON CACHE BOOL "" FORCE)

set(PROJECT_NAME "FikoEngine")

project(${PROJECT_NAME})

message("Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")
message("C++ standard Version: ${CMAKE_CXX_STANDARD}")
message("System Architecture: ${CMAKE_GENERATOR_PLATFORM}")

message("${PROJECT_NAME}: Adding lwlog")
add_subdirectory(vendor/lwlog)

message("${PROJECT_NAME}: Adding glfw")
add_subdirectory(vendor/glfw-3.3.4)

message("${PROJECT_NAME}: Adding shaderc")
add_subdirectory(vendor/vulkan/shaderc)

message("${PROJECT_NAME}: Adding source files")

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES ./${PROJECT_NAME}Lib/src/*.cpp)
file(GLOB_RECURSE ${PROJECT_NAME}_HEADER_FILES ./${PROJECT_NAME}Lib/src/*.hpp)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

add_library(${PROJECT_NAME}Lib STATIC ${FikoEngine_SOURCE_FILES} )

set(LWLOG_INCLUDE_DIR "./vendor/lwlog/lwlog/src")
set(GLFW_INCLUDE_DIR "./vendor/glfw-3.3.4/include")
set(VULKAN_INCLUDE_DIR         "./vendor/vulkan/include")
set(SHADERC_INCLUDE_DIR         "./vendor/vulkan/shaderc/libshaderc/include")
set(${PROJECT_NAME}_INCLUDE_DIR "./${PROJECT_NAME}Lib/src")

target_compile_definitions(${PROJECT_NAME}Lib PRIVATE VULKAN_HPP_NO_EXCEPTIONS)
if (WIN32)
    target_compile_definitions(${PROJECT_NAME}Lib PRIVATE GLFW_EXPOSE_NATIVE_WIN32)
    target_compile_definitions(${PROJECT_NAME}Lib PRIVATE VK_USE_PLATFORM_WIN32_KHR)
    
else ()
    find_package(X11 REQUIRED)
    link_libraries(${X11_LIBRARIES})

    add_definitions(-D_LINUX)
    add_definitions(-DGLFW_EXPOSE_NATIVE_X11)
endif ()

target_include_directories(${PROJECT_NAME}Lib PUBLIC ${FikoEngine_INCLUDE_DIR} ${LWLOG_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${VULKAN_INCLUDE_DIR}
${SHADERC_INCLUDE_DIR} "./vendor/vulkan")

set_target_properties(${PROJECT_NAME}Lib PROPERTIES LINKER_LANGUAGE CXX)
add_library(${PROJECT_NAME}InterfaceLibrary INTERFACE)

message("${PROJECT_NAME}: Linking libraries")

target_precompile_headers (${PROJECT_NAME}Lib PUBLIC ${PROJECT_NAME}Lib/src/Core/${PROJECT_NAME}.pch.h)

target_link_libraries(${PROJECT_NAME}InterfaceLibrary INTERFACE
        lwlog_lib
        glfw
        C:/VulkanSDK/1.3.261.1/Lib/vulkan-1.lib
        shaderc
        )

target_link_libraries(${PROJECT_NAME}Lib PUBLIC ${PROJECT_NAME}InterfaceLibrary)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(${PROJECT_NAME}Lib PRIVATE -static-libstdc++ -Wall -pedantic)
endif ()

add_subdirectory("./FikoEngineLib")
add_subdirectory("./FikoEngineEditor")
add_subdirectory("./Sandbox")
