#pragma once
#include "engine/core/Object.h"
#include <iostream>

class Player : public Object {
    public:
        Player(Vector2 position, Vector2 size) : Object(position, size) {};
        void Update(float dt);
};

class Button : public Object {
    private:
        Vector2 OriginalSize;
        bool pressed = false;
        std::function<void()> clickFunction;
    public:
        float highlight;
        Button(Vector2 position, Vector2 size, float highlight = 0) : Object(position, size), OriginalSize(size), highlight(highlight) {};
        Button(Vector2 position, Vector2 size, Vector2 AnchorPoint = Vector2(0,0), float highlight = 0) : Object(position, size, AnchorPoint), OriginalSize(size), highlight(highlight) {};
        ~Button() = default;
        void Update(float dt) {};
        void SetFunction(std::function<void()> func) {
            std::cout << "Function Set (Button: " << this << ")" << std::endl;
            Button::clickFunction = std::move(func);
        };
};