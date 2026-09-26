#include <SFML/Graphics.hpp>
#include "engine/input/Input.hpp"
#include "engine/math/Math.hpp"
#include "engine/core/Window.hpp"

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
    Input::InputDirection = InputDir;
    sf::Vector2i mousePos = sf::Mouse::getPosition(Main_Window);
    Input::MousePosition = Vector2(mousePos);
};  