#pragma once
#include "engine/math/Vector2.h"

class Input {
    public:
        Vector2 InputDirection;
        void Update();
        Input() : InputDirection(Vector2(0,0)) {};
};
