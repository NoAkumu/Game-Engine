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
}

void Physics::FixedUpdate() {
    Vector2 actualaccel = acceleration;
    
    if (EnableGravity) {
        actualaccel.y += ApplyGravity();
    }
    //Print(velocity.y);
    velocity += actualaccel * Time::fixedDt;
    owner->Position += velocity * Time::fixedDt;
}
float Physics::ApplyGravity() {
    if (collision != nullptr) {
        if (collision->IsGrounded() || collision->Anchored)
        {
            if (velocity.y > 0) {
                velocity.y = 0;
            }
            return 0;
        } 
    }
    return gravity;
}