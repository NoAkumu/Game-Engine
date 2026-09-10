#include "engine/core/Object.h"
#include "engine/core/Utils.h"

void Object::Awake(){
    for(auto& comp : this->components) {
        comp->Awake();
    }
}
void Object::Start(){
    for(auto& comp : this->components) {
        comp->Start();
    }
}
void Object::Update(float dt) {
    for(auto& comp : this->components) {
        comp->Update();
    }
    // Physics stuff goes here i guess
    for(auto& comp : this->components) {
        comp->LateUpdate();
    }
}

void Object::Render() {
    sf::RectangleShape shap(Object::Size);
    shap.setFillColor(Object::Color);
    shap.setPosition(Object::Position - (Object::Size * AnchorPoint));
    Main_Window.draw(shap);
}