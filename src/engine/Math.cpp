#include "engine/math/Math.hpp"

bool Math::IsBetween(float x, float min, float max) {
    return x > min && x < max;
};