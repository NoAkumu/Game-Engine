#include "engine/input/Input.h"
#include "engine/math/Vector2.h"

void Input::Update() {
    Vector2 InputDir(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        InputDir.x -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        InputDir.x += 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        InputDir.y -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        InputDir.y += 1;
    this->InputDirection = (InputDir.length() > 0 ? InputDir.normalized() : InputDir);
};  