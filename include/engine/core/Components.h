#pragma once
#include <SFML/Graphics.hpp>
#include "engine/core/Object.h"
#include "engine/core/ComponentParts.h"
#include "engine/core/Utils.h"
#include <iostream>
#include <string>
using namespace std;

// Sprite Component Class
class Sprite : public Component, public Renderable
{
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        string texturePath = "Debug.png";
    public:
        Sprite(string texturePath) : texturePath(texturePath), texture(LoadTexture(texturePath)), sprite(texture) {};
        ~Sprite() = default;
        void Render() override;
};

class Physics : public Component
{
    protected:
        Vector2 velocity;
        Vector2 acceleration;
        float gravity = 9.81f;
    public:
        bool EnableGravity = true;
        Physics() = default ;
        ~Physics() = default;
        virtual void FixedUpdate();
};

// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
    public:
        ScriptBehavior() = default;
        ~ScriptBehavior() = default;
};