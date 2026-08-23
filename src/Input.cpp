#include "engine/input/Input.h"
#include "engine/math/Vector2.h"

void Input::Update() {
    Vector2 InputDir(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        InputDir.x -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        InputDir.x += 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        InputDir.y -= 1;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        InputDir.y += 1;
    this->InputDirection = (InputDir.length() > 0 ? InputDir.normalized() : InputDir);
};  