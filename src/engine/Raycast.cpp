#include "engine/physics/Raycast.hpp"

bool CheckLineCast(Ray ray, float maxDist) {
    ray.direction = ray.direction.normalized();
    
    for (auto& obj : gameObjects.GetObjects())
    {
        if (Collision* a = obj.get()->GetComponent<Collision>()) {
            if (ray.direction.x == 0.0f)
            {
                if (ray.origin.x < a->min.x || ray.origin.x > a->max.x )
                    continue;
            }else{
                float t1 = (a->min.x - ray.origin.x) / ray.direction.x;
                float t2 = (a->max.x - ray.origin.x) / ray.direction.x;
                
                if (t1 > t2){
                    std::swap(t1, t2);
                }  
                
                float t_min = std::max(t1, 0.0f);
                float t_max = std::min(t2, maxDist);

                if (t_min > t_max)
                    continue;
            }
            if (ray.direction.y == 0.0f)
            {
                if (ray.origin.y < a->min.y || ray.origin.y > a->max.y )
                    continue;
            }else{
                float t1 = (a->min.y - ray.origin.y) / ray.direction.y;
                float t2 = (a->max.y - ray.origin.y) / ray.direction.y;
                
                if (t1 > t2){
                    std::swap(t1, t2);
                }  
                
                float t_min = std::max(t1, 0.0f);
                float t_max = std::min(t2, maxDist);

                if (t_min > t_max)
                    continue;
            }
            return true;
        }
    }
    return false;
}
