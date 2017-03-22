#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
using namespace std;

class Component{
public:
    virtual void operation()=0;
    virtual ~Component(){}
};


class ConcreteComponent : public Component{
public:
    void operation(){
        cout<<"Concrete Componenet"<<endl;
    }
    ~ConcreteComponent(){
        cout<<"Concrete Componenet destructor"<<endl;
    }
};

class Decorator : public Component{
private:
    Component* component;

public:
    Decorator(Component* c){
        component = c;
    }
    ~Decorator(){
        delete component;
    }
    void operation(){
        component->operation();
    }
};

class ConcreteDecoratorA: public Decorator{
public:
    ConcreteDecoratorA(Component* c):Decorator(c){
    }
    ~ConcreteDecoratorA(){
        cout<<"Concrete DecoratorA destructor"<<endl;
    }
    void operation(){
        Decorator::operation();
        cout<<"Concrete DecoratorA"<<endl;
    }
};


class ConcreteDecoratorB: public Decorator{
public:
    ConcreteDecoratorB(Component* c):Decorator(c){
    }
    ~ConcreteDecoratorB(){
        cout<<"Concrete DecoratorB destructor"<<endl;
    }
    void operation(){
        Decorator::operation();
        cout<<"Concrete DecoratorB"<<endl;
    }
};

#endif // DECORATOR_H
