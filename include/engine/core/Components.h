#pragma once
#include "engine/core/Object.h"

// Sprite Component Class
class Sprite : public Component
{
    public:
        Sprite(Object* owner) : Component(owner) {};
        ~Sprite() = default;
        virtual void Awake();
        virtual void Start() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
};

// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
    public:
        ScriptBehavior(Object* owner) : Component(owner) {};
        ~ScriptBehavior() = default;
        virtual void Awake();
        virtual void Start() {};
        virtual void Update() {};
        virtual void LateUpdate() {};
};