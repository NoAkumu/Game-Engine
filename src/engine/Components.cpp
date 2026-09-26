#include "engine/core/Components.h"
#include "engine/core/Utils.h"
#include "engine/core/Window.h"
#include "engine/core/ComponentParts.h"
#include "engine/core/Settings.h"
#include "engine/input/Input.h"
#include "engine/core/Time.h"
#include <SFML/Graphics.hpp>

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

// Sprite
void Sprite::Render() {
    sprite.setPosition(owner->Position - (owner->Size * owner->AnchorPoint));
    sprite.setScale({
        owner->Size.x / static_cast<float>(texture.getSize().x),
        owner->Size.y / static_cast<float>(texture.getSize().y)
    });
    Main_Window.draw(sprite);
}

// Physics
bool pressed = false;
void Physics::Awake() {
    collision = owner->GetComponent<Collision>();
    mass = ((owner->Size.x/100) * (owner->Size.y/100));
    collision->OnCollide.Subscribe([&](const CollisionData& a) {
        if(a.normal.x != 0 && velocity.x * a.normal.x > 0.0f) {
            velocity.x = 0;
        }
        if(a.normal.y != 0 && velocity.y * a.normal.y > 0.0f) {
            velocity.y = 0;
        }
    });
}

void Physics::FixedUpdate() {
    Vector2 actualaccel = acceleration;
    
    if (EnableGravity) {
        actualaccel.y += gravity;
    }
    velocity += actualaccel * Time::fixedDt;
    owner->Position += velocity * Time::fixedDt;
}
float Physics::ApplyGravity() {
    return gravity;
}
void Physics::AddForce(Vector2 f) {
    velocity += f;
};

Vector2 Physics::GetVelocity() {
    return velocity;
};