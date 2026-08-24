#include <iostream>

#include <SFML/Graphics.hpp>

// Engine Include
#include "engine/math/Vector2.h"
#include "engine/physics/Physics.h"
#include "engine/core/Object.h"
#include "engine/input/Input.h"

// Player
#include "game/Player.h"

#define WIDTH 1280
#define HEIGHT 720

// Input Bruh
Input MainInput;
//Window Pointer
sf::RenderWindow *_window;

// PLr Instance (TEMP)
Player plr(Vector2(0,0), Vector2(50,50));

void RenderStep() {
    plr.Render(_window);
}

void Update(float dt) {
    plr.Position += MainInput.InputDirection * 100 * dt;
}

void LateUpdate() {

}

int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode({WIDTH,HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i((desktop.size.x/2)-(WIDTH/2),(desktop.size.y/2)-(HEIGHT/2)));
    window.setFramerateLimit(165);

    _window = &window;

    sf::Clock clock;

    while (window.isOpen())
    {
        // 
        sf::Time deltaTimer = clock.restart();
        float deltaTime = deltaTimer.asMilliseconds();

        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        // Clear Window for Next Rendering
        window.clear(sf::Color::White);

        // Update Input Detection
        MainInput.Update();

        // Update Steps
        RenderStep();

        Update(deltaTime/1000);
        
        LateUpdate();
        
        // Display whats been rendered 
        window.display();
    }
}

