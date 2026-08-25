#include "game/Player.h"
#include "engine/input/Input.h"
#include <iostream>

void Player::Update(float dt) {
    Player::Position += MainInput.InputDirection * 100 * dt;
}