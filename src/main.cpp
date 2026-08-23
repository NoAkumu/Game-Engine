#include <SFML/Graphics.hpp>

#include "engine/math/Vector2.h"
#include "engine/physics/Physics.h"
#include "engine/core/Object.h"
#include "engine/input/Input.h"

#define WIDTH 1280
#define HEIGHT 720

Input MainInput;

void RenderStep() {

}

void Update() {

}

void LateUpdate() {

}

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode({WIDTH,HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i((desktop.size.x/2)-(WIDTH/2),(desktop.size.y/2)-(HEIGHT/2)));
    window.setFramerateLimit(60);

    Object plr(Vector2(0,0), Vector2(50,50));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);

        MainInput.Update();

        plr.Position += MainInput.InputDirection * 5;
        
        plr.Render(&window);
        
        window.display();
    }
}

