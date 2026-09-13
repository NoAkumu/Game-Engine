#include "engine/core/Components.h"
#include "engine/core/Utils.h"
#include "engine/core/Window.h"
#include "engine/core/ComponentParts.h"
#include <SFML/Graphics.hpp>

bool Component::IsEnabled() {
    return Component::enabled;
}
void Component::SetEnabled(bool value) {
    Component::enabled = value;
}

// Sprite
void Sprite::Render() {
    sf::RectangleShape shap(owner->Size);
    shap.setFillColor(owner->Color);
    shap.setPosition(owner->Position - (owner->Size * owner->AnchorPoint));
    Main_Window.draw(shap);
}