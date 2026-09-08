#include "engine/core/Object.h"

void Object::Awake(){
    for(auto& comp : Object::components) {
        comp->Awake();
    }
}
void Object::Start(){
    for(auto& comp : Object::components) {
        comp->Start();
    }
}
void Object::Update(float dt) {
    for(auto& comp : Object::components) {
        comp->Update();
    }
    // Physics stuff goes here i guess
    for(auto& comp : Object::components) {
        comp->LateUpdate();
    }
}
void Object::Render(sf::RenderWindow& window) {
    sf::RectangleShape shap(Object::Size);
    shap.setFillColor(Object::Color);
    shap.setPosition(Object::Position - (Object::Size * AnchorPoint));
    window.draw(shap);
}