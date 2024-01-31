#pragma once

// #include <GLFW/glfw3.h>
// #include <GLFW/glfw3native.h>
#ifdef _WIN32
#include <windows.h>
#include <commdlg.h>
#include <ShlObj.h>
#endif
#include <Core/Core.hpp>

class GLFWwindow;
class FileDialogs {
public:
	static std::filesystem::path OpenFolder(GLFWwindow* window);
    static std::filesystem::path OpenFile(GLFWwindow* window,const char* filter);
    static std::filesystem::path NewFile(const char* filter);
	static std::string SaveFile(const char* filter);
};