#pragma once
#include "engine/core/Object.h"

// Sprite Component Class
class Renderable
{
    public:
        Renderable() = default;
        ~Renderable() = default;
        virtual void Render() = 0;
};