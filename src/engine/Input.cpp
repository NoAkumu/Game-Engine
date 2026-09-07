#include <SFML/Graphics.hpp>
#include "engine/input/Input.h"
#include "engine/math/Math.h"

void Input::Update(sf::WindowBase& relative) {
    Vector2 InputDir(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        InputDir.x -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        InputDir.x += 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        InputDir.y -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        InputDir.y += 1;
    Input::InputDirection = (InputDir.length() > 0 ? InputDir.normalized() : InputDir);
    sf::Vector2i mousePos = sf::Mouse::getPosition(relative);
    Input::MousePosition = Vector2(mousePos);
};  