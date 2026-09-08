#pragma once
#include <SFML/Graphics.hpp>
#include "engine/math/Vector2.h"
#include "engine/core/Components.h"
#include <vector>
#include <memory>

/*Object Class*/
class Object {
    private:
        sf::RectangleShape shape;
        std::vector<std::unique_ptr<Component>> components;
    public:
        Object(Vector2 position, Vector2 size, Vector2 AnchorPoint = Vector2(0,0)) : Position(position), Size(size), AnchorPoint(AnchorPoint) {
            shape.setPosition(position);
            shape.setSize(size);
        }
        virtual ~Object() = default;
        Vector2 Position;
        Vector2 AnchorPoint;
        Vector2 Size;
        sf::Color Color = sf::Color::Black;
        virtual void Awake() {};
        virtual void Start() {};
        virtual void Update(float dt) = 0;
        virtual void Render(sf::RenderWindow& window);
};