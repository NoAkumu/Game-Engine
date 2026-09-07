// Engine Include
#include "engine/Engine.h"

//Player plr = gameObjects.create<Player>(Vector2(0,0), Vector2(50,50));
Button& butt = gameObjects.create<Button>(Vector2(60,60), Vector2(50,50), Vector2(0.5,0.5),1.1);

void Awake() {

}

void RenderStep(sf::RenderWindow& _window) {
    // Update Input Detection
    MainInput.Update(_window);
    gameObjects.RenderAll(_window);
}

void Update() {
    gameObjects.UpdateAll(Time::deltaTime);
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

    Awake(); // This shoulkd be run after object loading

    while (window.isOpen())
    {
        // Clock to count DeltaTime
        sf::Time deltaTimer = clock.restart();
        Time::deltaTime = deltaTimer.asMilliseconds()/1000;

        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        // Clear Window for Next Rendering
        window.clear(sf::Color::White);

        // Update Steps
        RenderStep(window);

        Update();
        
        LateUpdate();
        
        // Display whats been rendered 
        window.display();
    }

    bool saved = Save(_Config);
    if (saved) {
        std::cout << "Saved Config Sucessfully!" << std::endl;
    }
}

