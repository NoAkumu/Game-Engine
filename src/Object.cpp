#include <SFML/Graphics.hpp>
#include "engine/core/Object.h"

void Object::Render(sf::RenderWindow *window) {
    sf::RectangleShape shap(Object::Size);
    shap.setFillColor(sf::Color::Blue);
    shap.setPosition(Object::Position);
    window->draw(shap);
}