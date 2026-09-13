#include "engine/core/Object.h"
#include "engine/core/Utils.h"
#include "engine/core/ComponentParts.h"

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
    for (auto& comp : this->components)
    {
        if (auto* rend = dynamic_cast<Renderable*>(comp.get()))
        {
            rend->Render();
        }
        
    }
    
    // This is going to be on the renderable components

}