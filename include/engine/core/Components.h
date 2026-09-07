#pragma once
#include "engine/core/Object.h"

class Component
{
    protected:
        Object* owner;
        bool enabled = true;
    public:
        // Declarations
        explicit Component();
        virtual ~Component() = default;
        // Virtual Functions
        virtual void Awake();
        virtual void Start();
        virtual void Update();
        virtual void LateUpdate();
        // Functions
        bool IsEnabled();
        void SetEnabled(bool value);
};