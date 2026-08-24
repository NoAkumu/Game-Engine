#include <iostream>

#include "engine/core/Settings.h"

#include "tinyxml2.h"

using namespace tinyxml2;

Configs Load() {
    Configs c;
    XMLDocument doc;

    // Loading File
    XMLError result = doc.LoadFile("Assets/config.xml");
    if (result != XML_SUCCESS)
    {
        throw std::runtime_error("Error: Couldn't load Config file (should be located at 'Assets/config.xml')");
    }

    // Getting <config> header
    XMLElement* conf = doc.FirstChildElement("config");
    if (conf == nullptr) {
        throw std::runtime_error("There's no <config> header");
    }

    // Setting Screen Width
    XMLElement* screenW = conf->FirstChildElement("width");
    if (screenW)
    {
        screenW->QueryIntText(&c.WIDTH);
    }
    // Setting Screen Height
    XMLElement* screenH = conf->FirstChildElement("height");
    if (screenH)
    {
        screenH->QueryIntText(&c.HEIGHT);
    }

    XMLElement* fullscreen = conf->FirstChildElement("fullscreen");
    if (fullscreen && fullscreen->GetText()) {
        std::string value = fullscreen->GetText();

        c.Fullscreen =
            value == "true" ||
            value == "1" ||
            value == "yes";
    }

    std::cout << c.WIDTH << " : " << c.HEIGHT << std::endl;
    std::cout << c.Fullscreen << std::endl;

    return c;
}