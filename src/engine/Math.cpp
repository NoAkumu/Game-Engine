#include "engine/math/Math.h"

bool Math::IsBetween(float x, float min, float max) {
    return x > min && x < max;
};