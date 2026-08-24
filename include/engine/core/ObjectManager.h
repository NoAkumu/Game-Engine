#pragma once
#include "engine/core/Object.h"
#include <vector>
#include <memory>

class  ObjectManager {
    public:
        template <typename T> T& create();
    private:
        std::vector<std::unique_ptr<Object>> objects;
};