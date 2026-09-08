#pragma once
#include <SFML/Graphics.hpp>
#include "engine/math/Vector2.h"
#include "engine/core/Components.h"
#include <vector>
#include <memory>

/*Object Class*/
class Object {    
    protected:
        sf::RectangleShape shape;
        std::vector<std::unique_ptr<Component>> components;
    public:
        // Declaration
        Object(Vector2 position, Vector2 size, Vector2 AnchorPoint = Vector2(0,0)) : Position(position), Size(size), AnchorPoint(AnchorPoint) {
            shape.setPosition(position);
            shape.setSize(size);
        }
        // Destructor
        virtual ~Object() = default;
        // Object info
        Vector2 Position;
        Vector2 AnchorPoint;
        Vector2 Size;
        sf::Color Color = sf::Color::Black;
        // Functions
        virtual void Awake();
        virtual void Start();
        virtual void Update(float dt);
        virtual void Render(sf::RenderWindow& window);
        // Component-related functions
};