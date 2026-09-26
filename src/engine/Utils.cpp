#include "engine/core/Utils.hpp"

sf::Texture LoadTexture(const std::string& path) {
    try
        {
            return sf::Texture(SpritePath + path);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return sf::Texture(SpritePath + "Debug.png");
        }
}