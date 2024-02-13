#include "SandboxLayer.hpp"
#include <FikoEngine.hpp>

int main()
{
    FikoEngine::Application::Init( FikoEngine::ApplicationSpec{ .ApplicationName = "Sandbox Application",
                                                                .WorkingDirectory = std::filesystem::current_path(),
                                                                .StartupWidth = 1280,
                                                                .StartupHeight = 720 } );
    FikoEngine::Application::AddLayer<SandboxLayer>();

    FikoEngine::Application::Run();

    FikoEngine::Application::Destroy();
    return 0;
}