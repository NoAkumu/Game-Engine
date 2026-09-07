#include "engine/core/Object.h"

void Object::Render(sf::RenderWindow& window) {
    sf::RectangleShape shap(Object::Size);
    shap.setFillColor(Object::Color);
    shap.setPosition(Object::Position - (Object::Size * AnchorPoint));
    window.draw(shap);
}