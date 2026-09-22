#include "engine/Engine.h" 
#include "game/movement.h"

Physics* phys;
Collision* coll;

void Movement::Start() {
    phys = Movement::owner->GetComponent<Physics>();
    coll = Movement::owner->GetComponent<Collision>();
}
void Movement::Update() {
    Movement::owner->Position += Vector2(MainInput.InputDirection.x * 250 * Time::deltaTime, 0);
    
    if (phys == nullptr && coll == nullptr) { return; }
    
    if (MainInput.InputDirection.y < 0)
    {
        phys->AddForce(Vector2(0, -1000 * Time::deltaTime));
    }
}
