#pragma once
#include <SFML/Graphics.hpp>
#include "engine/core/Object.h"
#include "engine/core/ComponentParts.h"
#include "engine/core/Utils.h"
#include "engine/core/Event.h"
#include <iostream>
#include <string>
using namespace std;

// Sprite Component Class
class Sprite : public Component, public Renderable
{
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        string texturePath = "Debug.png";
    public:
        Sprite(string texturePath) : texturePath(texturePath), texture(LoadTexture(texturePath)), sprite(texture) {};
        virtual ~Sprite() = default;
        void Render() override;
};
// Collision Component Class
struct CollisionData
{
    void* objectHit;
    void* thisObject;
    Vector2 overlap;
};

class Collision : public Component
{
    private:
        bool grounded = false;
    public:
        bool Anchored = false;
        Vector2 min, max;
        Collision() = default;
        void FixedUpdate() {
            min = owner->Position - (owner->Size * owner->AnchorPoint);
            max = min + owner->Size;
        }
        virtual ~Collision() = default;
        Event<const CollisionData&> OnCollide;
        Vector2 Center() {
            return (min + max)/2;
        }
        Vector2 CalculateOverlap(Collision& other) {
            return Vector2(
                std::min(max.x, other.max.x) - std::max(min.x, other.min.x),
                std::min(max.y, other.max.y) - std::max(min.y, other.min.y)
            );
        }
        Vector2 CalculateNormal(Collision& other) {
            Vector2 direction(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );
            Vector2 overlap = CalculateOverlap(other);
            
            if (overlap.x < overlap.y)
            {
                return Vector2(direction.x >= 0.0f ? 1.0f : -1.0f, 0.0f);
            }
            
            return Vector2(0.0f, direction.y >= 0.0f ? 1.0f : -1.0f);
        }
        bool Overlaping(Collision& other) {
            return (
                min.x < other.max.x &&
                max.x > other.min.x &&
                min.y < other.max.y &&
                max.y > other.min.y
            );
        }
        
        bool BroadCollisionCheck(Collision &other) {
            Vector2 diff(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );

            float distanceSquared = (diff.x*diff.x) + (diff.y*diff.y);

            float radiusSum = (owner->Size.length()) + (other.owner->Size.length());

            return distanceSquared <= radiusSum*radiusSum;
        }
        void PullPosition(Collision &other) {
            if (CalculateNormal(other).y > 0)
            {
                grounded = true;
            }else
            {
                grounded = false;
            }
            if (Anchored) {
                return;
            }
            Vector2 overlap = CalculateOverlap(other);
            Vector2 direction(
                other.Center().x - Center().x,
                other.Center().y - Center().y
            );
            if (overlap.x < overlap.y)
            { 
                owner->Position.x += direction.x >= 0.0f ? -overlap.x : overlap.x;
            } else { 
                owner->Position.y += direction.y >= 0.0f ? -overlap.y : overlap.y;
            }
        }
        bool IsGrounded() {
            return grounded;
        }
};
// Physics Component Class
class Physics : public Component
{
    protected:
        Collision* collision = nullptr;
        Vector2 velocity;
        Vector2 acceleration;
        float gravity = 981.1f;
        float ApplyGravity();
    public:
        bool EnableGravity = true;
        Physics() = default ;
        virtual ~Physics() = default;
        virtual void Awake();
        virtual void FixedUpdate();
        void AddForce();
};
// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
    public:
        ScriptBehavior() = default;
        ~ScriptBehavior() = default;
};