#pragma once
#include <SFML/Graphics.hpp>

class Vector2 {
    public:
        float x, y;
        Vector2(float x, float y) : x(x), y(y) {}
        
        operator sf::Vector2f() const {
            return sf::Vector2f({x,y});
        }
        Vector2 operator+(const Vector2 &v2) const {
            return Vector2(x+v2.x, x+v2.y);
        }
        Vector2& operator+=(const Vector2 &v2) {
            x += v2.x;
            y += v2.y;
            return *this;
        }
        Vector2 operator*(float Scalar) const {
            return Vector2(x* Scalar, y*Scalar);
        }
        Vector2 operator/(float Scalar) const {
            return Vector2(x/Scalar, y/Scalar);
        }
        float length() const {
            return std::sqrt(std::pow(x,2)+std::pow(y,2));
        }
        Vector2 normalized() const {
            return Vector2(x,y)/this->length();
        }
};