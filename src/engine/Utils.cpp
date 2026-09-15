#include "engine/core/Utils.h"

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