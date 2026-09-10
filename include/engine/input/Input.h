#pragma once
#include "engine/math/Vector2.h"
#include "SFML/Graphics.hpp"

class Input {
    public:
        Vector2 InputDirection;
        Vector2 MousePosition = Vector2(0,0);
        void Update();
        Input() : InputDirection(Vector2(0,0)) {};
};

inline Input MainInput;