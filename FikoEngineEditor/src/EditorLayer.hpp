#pragma once
#include <Core/Layer.hpp>
#include <FikoEngine.hpp>

class EditorLayer: public FikoEngine::Layer
{
public:
    EditorLayer() = default;
    virtual ~EditorLayer() = default;

    virtual void Init() override {}

    void Destroy() override {}

    void OnAttach() override {}

    void OnDettach() override {}

    void OnDestroy() override {}

    void OnUpdate() override {}

    void OnMouseClickEvent() override {}

    void OnMouseMoveEvent() override {}

    void OnKeyboardEvent() override {}

    std::string GetName() const override { return "EditorLayer"; }
};