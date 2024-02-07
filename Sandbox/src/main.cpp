#include "SandboxLayer.hpp"
#include <FikoEngine.hpp>

int main()
{
    LOG_INFO( "Lol" );
    FikoEngine::Application::Init();
    FikoEngine::Application::Get()->AddLayer<SandboxLayer>();

    FikoEngine::Application::Run();

    FikoEngine::Application::Destroy();
    return 0;
}