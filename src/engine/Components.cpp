#include "engine/core/Components.h"
#include "engine/core/Utils.h"

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

// Sprite

void Sprite::Awake() {
    Print(Sprite::owner);
}