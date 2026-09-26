#pragma once
#include <string>
using namespace std;

struct Configs
{
    int WIDTH = 1280;
    int HEIGHT = 720;
    bool Fullscreen = false;
    int maxFPS = 165;
};

extern string AssetPath;
extern string SpritePath;

bool Save(Configs c);
Configs Load();

inline Configs Config;