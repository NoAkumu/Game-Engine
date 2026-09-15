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

            reference.Start();

            return reference;
        };
        void AwakeAll() {
            for(auto& obj : objects) {
                obj->Awake();
            }
        };
        void FixedUpdateAll() {
            for(auto& obj : objects) {
                obj->FixedUpdate();
            }
        };
        void UpdateAll() {
            for(auto& obj : objects) {
                obj->Update();
            }
        };
        void LateUpdateAll() {
            for(auto& obj : objects) {
                obj->LateUpdate();
            }
        };
        void RenderAll() {
            for(auto& obj : objects) {
                obj->Render();
            }
        };
    private:
        std::vector<std::unique_ptr<Object>> objects;
};

inline ObjectManager gameObjects;