#pragma once

// Sprite Component Class
class Renderable
{
    public:
        Renderable() = default;
        ~Renderable() = default;
        virtual void Render() = 0;
};