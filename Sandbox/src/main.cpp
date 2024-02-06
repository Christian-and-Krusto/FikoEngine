#include "SandboxLayer.hpp"
#include <FikoEngine.hpp>
#include <iostream>

int main()
{
    LOG_INFO( "Lol" );
    FikoEngine::Application::Init();
    FikoEngine::Application::AddLayer<SandboxLayer>();
    FikoEngine::Application::Destroy();
    return 0;
}