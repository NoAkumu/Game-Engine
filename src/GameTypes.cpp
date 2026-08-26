#include "game/GameTypes.h"
#include "engine/input/Input.h"
#include "engine/math/Math.h"
#include <iostream>

// Player Object
void Player::Update(float dt) {
    Player::Position += MainInput.InputDirection * 100 * dt;
}

// Button Object

void Button::Update(float dt) {
    std::cout << MainInput.MousePosition.x << " : " << MainInput.MousePosition.y << std::endl;
    Vector2 effectivePosition = Button::Position - (Button::Size * Button::AnchorPoint);
    if (Math::IsBetween(MainInput.MousePosition.x, effectivePosition.x, effectivePosition.x + Button::Size.x) && Math::IsBetween(MainInput.MousePosition.y, effectivePosition.y, effectivePosition.y + Button::Size.y))
    {
        if (Button::highlight > 0) {
            Button::Size = Button::OriginalSize * Button::highlight;
        }
        std::cout << Button::highlight << std::endl;
    }else{
        if (Button::highlight > 0 && Button::Size != Button::OriginalSize) {
            Button::Size = Button::OriginalSize;
        }
    }
    
}