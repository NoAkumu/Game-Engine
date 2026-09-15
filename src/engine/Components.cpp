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
    Main_Window.draw(sprite);
}

// Physics
bool pressed = false;
void Physics::FixedUpdate() {
    Vector2 actualaccel = acceleration;
    if (EnableGravity) {
        actualaccel.y = gravity;
    }
    velocity += actualaccel * Time::fixedDt;
    owner->Position += velocity * Time::fixedDt;
}