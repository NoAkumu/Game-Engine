#pragma once
#include "engine/core/Object.h"
#include "engine/core/Utils.h"
#include "engine/core/Components.h"
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
            //This collision check is probably ass, but i can't think of a better alternative at 5 AM
            for (std::size_t i = 0; i < objects.size(); i++)
            {
                Collision* a = objects[i].get()->GetComponent<Collision>();
                if (!(a != nullptr && a->IsEnabled())){
                    continue;
                }
                for (std::size_t j = 0; j < objects.size(); j++)
                {
                    if (objects[i] == objects[j]) {
                        continue;
                    }
                    Collision* b = objects[j].get()->GetComponent<Collision>();
                    if (!(b != nullptr && b->IsEnabled())){
                        continue;
                    }
                    if (a->BroadCollisionCheck(*b) && a->Overlaping(*b))
                    {
                        a->PullPosition(*b);
                    }
                }
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