#include "engine/core/Components.h"

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

// Sprite

void Sprite::Awake() {
    //Sprite::owner
}