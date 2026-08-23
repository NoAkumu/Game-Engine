#include <SFML/Graphics.hpp>

#define WIDTH 1280
#define HEIGHT 720


int main() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode({WIDTH,HEIGHT}), "SFML", sf::Style::Close | sf::Style::Titlebar);
    window.setPosition(sf::Vector2i((desktop.size.x/2)-(WIDTH/2),(desktop.size.y/2)-(HEIGHT/2)));
    window.setFramerateLimit(60);

    sf::Vector2f plrPos(10,10);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);

        sf::RectangleShape shap(sf::Vector2f(25,25));
        shap.setFillColor(sf::Color::Blue);
        shap.setPosition(plrPos);
        window.draw(shap);

        sf::Vector2f plrMove(0,0);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            plrMove.x -= 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            plrMove.x += 1;
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            plrMove.y -= 1;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            plrMove.y += 1;

        if(plrMove.length()  > 0)
           plrPos += plrMove.normalized();

        window.display();
    }
}

