#pragma once
#include <Core/Layer.hpp>
#include <FikoEngine.hpp>

class SandboxLayer: public FikoEngine::Layer
{
public:
    SandboxLayer() = default;

    virtual void Init() override {}

    void Destroy() override {}

    void OnAttach() override {}

    void OnDestroy() override {}

    void OnUpdate() override {}

    void OnMouseClickEvent() override {}

    void OnMouseMoveEvent() override {}

    void OnKeyboardEvent() override {}
};