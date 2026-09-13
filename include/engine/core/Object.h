#pragma once
#include <SFML/Graphics.hpp>
#include "engine/math/Vector2.h"
#include "engine/core/Window.h"
#include <vector>
#include <memory>
#include <utility>

class Object;

// Base Components Class (You shouldn't be using this)
class Component
{
    friend class Object;
    private:
        void SetOwner(Object* obj) {
            owner = obj;
        };
    protected:
        bool enabled = true;
        Object* owner;
    public:
        // Declaration
        Component() {};
        // Destructor
        ~Component() = default;
        // Virtual Functions
        virtual void Awake() = 0;
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void LateUpdate() = 0;
        // Functions
        bool IsEnabled();
        void SetEnabled(bool value);
        Object* Owner() {
            return owner;
        };
};

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

        char* Name = "Default";
        Vector2 Position;
        Vector2 AnchorPoint;
        Vector2 Size;
        sf::Color Color = sf::Color::Black;
        // Functions
        virtual void Awake();
        virtual void Start();
        virtual void Update(float dt);
        virtual void Render();
        // Component-related functions
        template <typename T, typename... Args>T& AddComponent(Args&&... args) {
            auto obj = std::make_unique<T>(std::forward<Args>(args)...);

            T& reference = *obj;
            
            reference.SetOwner(this);
            
            components.push_back(std::move(obj));

            reference.Start();

            return reference;
        };
};