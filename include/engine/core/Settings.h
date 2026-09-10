#pragma once

struct Configs
{
    int WIDTH = 1280;
    int HEIGHT = 720;
    bool Fullscreen = false;
};

bool Save(Configs c);
Configs Load();

inline Configs Config;