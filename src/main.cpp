// Engine Include
#include "engine/Engine.h"

//Player plr = gameObjects.create<Player>(Vector2(0,0), Vector2(50,50));
Button& butt = gameObjects.create<Button>(Vector2(60,60), Vector2(50,50), Vector2(0.5,0.5),1.1);

void Awake() {
    butt.AddComponent<Sprite>("/Debug.png");
    // Calls Awake() in all objects
    gameObjects.AwakeAll();
}

void FixedUpdate() {
    gameObjects.FixedUpdateAll();
}

void RenderStep(sf::RenderWindow& _window) {
    // Rendering all objects
    gameObjects.RenderAll();
}

void Update() {
    // Calls Update() in all objects
    gameObjects.UpdateAll();
}

void LateUpdate() {
    gameObjects.LateUpdateAll();
}

int main() {
    Config = Load();

    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    Main_Window = sf::RenderWindow(sf::VideoMode({Config.WIDTH,Config.HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    Main_Window.setPosition(sf::Vector2i((desktop.size.x/2)-(Config.WIDTH/2),(desktop.size.y/2)-(Config.HEIGHT/2)));
    Main_Window.setFramerateLimit(165);

    sf::Clock clock;
    clock.start();
    sf::Clock dtclock;

    Awake(); // This shoulkd be run after object loading

    while (Main_Window.isOpen())
    {
        // Clock to count DeltaTime
        sf::Time deltaTimer = dtclock.restart();
        Time::deltaTime = deltaTimer.asMilliseconds()/1000;
        Time::time = clock.getElapsedTime().asMilliseconds()/1000;

        while (const std::optional event = Main_Window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                Main_Window.close();
        }
        // Clear Window for Next Rendering
        Main_Window.clear(sf::Color::White);

        // Update Input Detection
        MainInput.Update();

        // Physics Update
        FixedUpdate();

        // Update Steps
        RenderStep(Main_Window);

        Update();
        
        LateUpdate();
        
        // Display whats been rendered 
        Main_Window.display();
    }

    bool saved = Save(Config);
    if (saved) {
        Print("Saved Config Sucessfully!");
    }
}

