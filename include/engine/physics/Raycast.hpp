#pragma once
#include "engine/core/ObjectManager.hpp"

struct Ray
{
    Vector2 origin;
    Vector2 direction;
    Ray(Vector2 origin, Vector2 direction) : origin(origin), direction(direction) {};
};

bool CheckLineCast(Ray ray, float maxDist);