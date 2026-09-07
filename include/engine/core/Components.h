#pragma once

// Dummy Object class bc i was getting circular dependancy errors when including Objects.h
class Object; 

// Base Components Class (You shouldn't be using this)
class Component
{
    protected:
        Object* owner = nullptr;
        bool enabled = true;
    public:
        // Declarations
        explicit Component() = default;
        virtual ~Component() = default;
        // Virtual Functions
        virtual void Awake() = 0;
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void LateUpdate() = 0;
        // Functions
        bool IsEnabled();
        void SetEnabled(bool value);
};

// ScriptBehavior Component Class
class ScriptBehavior : public Component
{
private:
    
public:
    ScriptBehavior() : Component() {};
    ~ScriptBehavior();
    virtual void Awake() {};
    virtual void Start() {};
    virtual void Update() {};
    virtual void LateUpdate() {};
};