#include <iostream>
#include "engine/core/GameTypes.h"
#include "engine/input/Input.h"
#include "engine/math/Math.h"

/* Moving these to a component */

/*
// Player Object
void Player::Update(float dt) {
    Player::Position += MainInput.InputDirection * 100 * dt;
}

// Button Object
void Button::Update(float dt) {
    Vector2 effectivePosition = Button::Position - (Button::Size * Button::AnchorPoint);
    if (Math::IsBetween(MainInput.MousePosition.x, effectivePosition.x, effectivePosition.x + Button::Size.x) && Math::IsBetween(MainInput.MousePosition.y, effectivePosition.y, effectivePosition.y + Button::Size.y))
    {
        if (Button::highlight > 0) {
            Button::Size = Button::OriginalSize * Button::highlight;
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            if (!pressed) {
                Button::pressed = true;
                if (Button::clickFunction) {
                    Button::clickFunction();    
                } else {
                    std::cerr << "Error: No Callback Function / Bad Function (Button: " << this << ")" << std::endl;
                }
            }
        }else{
            Button::pressed = false;
        }
    }else{
        if (Button::highlight > 0 && Button::Size != Button::OriginalSize) {
            Button::Size = Button::OriginalSize;
        }
    }
}
*/
