#pragma once
#include "engine/math/Vector2.h"

class Object {
    public:
        Vector2 Position, Size;
        sf::Color Color = sf::Color::Black;
        void Render(sf::RenderWindow *window);
        Object(Vector2 Pos, Vector2 Size) : Position(Pos), Size(Size) {}
};