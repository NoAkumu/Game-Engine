#pragma once

struct Configs
{
    int WIDTH = 1280;
    int HEIGHT = 720;
    bool Fullscreen = 0;
};


Configs Save();
Configs Load();