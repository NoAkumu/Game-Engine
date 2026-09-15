#include "engine/core/Components.h"
#include "engine/core/Utils.h"
#include "engine/core/Window.h"
#include "engine/core/ComponentParts.h"
#include "engine/core/Settings.h"
#include <SFML/Graphics.hpp>

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

// Sprite
void Sprite::Render() {
    this->sprite.setPosition(owner->Position - (owner->Size * owner->AnchorPoint));
    Main_Window.draw(this->sprite);
}