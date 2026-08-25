#pragma once
#include "engine/core/Object.h"

class Player : public Object {
    public:
        Player(Vector2 position, Vector2 size) : Object(position, size) {};
        void Update(float dt);
};