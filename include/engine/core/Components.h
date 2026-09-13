#pragma once
#include "engine/core/Object.h"
#include "engine/core/ComponentParts.h"

// Sprite Component Class
class Sprite : public Component, public Renderable
{
    public:
        Sprite() = default ;
        ~Sprite() = default;
        void Render() override;
        virtual void Awake() {};
        virtual void Start() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
};

// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
    public:
        ScriptBehavior() = default;
        ~ScriptBehavior() = default;
        virtual void Awake();
        virtual void Start() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
};