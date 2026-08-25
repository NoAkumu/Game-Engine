#include <iostream>

#include <SFML/Graphics.hpp>

// Engine Include
#include "engine/math/Vector2.h"
#include "engine/physics/Physics.h"
#include "engine/core/ObjectManager.h"
#include "engine/core/Object.h"
#include "engine/input/Input.h"
#include "engine/core/Settings.h"

// Player
#include "game/Player.h"

// Input Bruh
ObjectManager gameObjects;

// PLr Instance (TEMP)
Player plr = gameObjects.create<Player>(Vector2(0,0), Vector2(50,50));

void RenderStep(sf::RenderWindow& _window) {
    gameObjects.RenderAll(_window);
    //plr.Render(_window);
}

void Update(float dt) {
    gameObjects.UpdateAll(dt);
}

void LateUpdate() {

}

int main() {
    Configs _Config = Load();

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode({_Config.WIDTH,_Config.HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i((desktop.size.x/2)-(_Config.WIDTH/2),(desktop.size.y/2)-(_Config.HEIGHT/2)));
    window.setFramerateLimit(165);

    sf::Clock clock;



    while (window.isOpen())
    {
        // Clock to count DeltaTime
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
        RenderStep(window);

        Update(deltaTime/1000);
        
        LateUpdate();
        
        // Display whats been rendered 
        window.display();
    }

    bool saved = Save(_Config);
    if (saved) {
        std::cout << "Saved Config Sucessfully!" << std::endl;
    }
}

