#pragma once
#include "engine/core/Object.h"
#include <vector>
#include <memory>

class  ObjectManager {
    public:
        template <typename T, typename... Args> T& create(Args&&... args) {
            auto obj = std::make_unique<T>(std::forward<Args>(args)...);
            
            T& reference = *obj;

            objects.push_back(std::move(obj));

            return reference;
        };
        void UpdateAll(float dt) {
            for(auto& obj : objects) {
                obj->Update(dt);
            }
        };
        void RenderAll(sf::RenderWindow& window) {
            for(auto& obj : objects) {
                obj->Render(window);
            }
        };
    private:
        std::vector<std::unique_ptr<Object>> objects;
};

inline ObjectManager gameObjects;