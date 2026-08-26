#pragma once

namespace Math {
    bool IsBetween(float x, float min, float max) {
        return x > min && x < max;
    };
};