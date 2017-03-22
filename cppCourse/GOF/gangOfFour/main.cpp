#include <iostream>
#include "singleton.h"
#include "abstractfactory.h"
#include "prototype.h"
#include "factorymethod.h"
#include "builder.h"
#include "adapter1.h"
#include "decorator.h"

//#define MERCEDES
using namespace std;

int main(int argc, char *argv[])
{
    /*Singleton*/
    cout<<"Singleton"<<endl;
    Singleton * a = Singleton::getInstance();
    Singleton * b = Singleton::getInstance();
    b->s = "pierwszy";
    a->s = "drugi";
    cout<<Singleton::getInstance()->s<<endl;

    /*Abstract Factory*/
    cout<<"Abstract Factory"<<endl;
#ifdef MERCEDES
    MercedesFactory* factory = new MercedesFactory();
#else
    BMWFactory* factory = new BMWFactory();
#endif
    Vehicle* vehicle[3];

    vehicle[0] = factory->createCar();
    vehicle[1] = factory->createMotor();
    vehicle[2] = factory->createCar();

    for(int i=0;i<3;i++){
        vehicle[i]->display();
    }

    /*Prototype*/
    cout<<"Prototype"<<endl;
    Trooper* troopers[6];

    troopers[0]= CloneFactory::create(TrooperType::FOREST);
    troopers[1]= CloneFactory::create(TrooperType::SCOUT);
    troopers[2]= CloneFactory::create(TrooperType::SCOUT);
    troopers[3]= CloneFactory::create(TrooperType::STORM);
    troopers[4]= CloneFactory::create(TrooperType::FOREST);
    troopers[5]= CloneFactory::create(TrooperType::STORM);

    for (int i = 0; i < 6; ++i) {
        cout<<i<<": ";
        troopers[i]->Salute();
    }

    /*Factory Method*/
    cout<<"Factory Method"<<endl;
    ComputerAbstractFactory* compuerFactory = new ComputerFactory;
    Computer* computer[2];
    computer[0]=compuerFactory->factoryMethod("Assus");
    computer[1]=compuerFactory->factoryMethod("HP");
    for(int i=0;i<2;i++){
        computer[i]->getType();
    }

    /*Builder*/
    cout<<"Builder"<<endl;

    Director* director = new Director();
    director->construct();

    delete director;

    /*Adapter*/
    cout<<"Adapter"<<endl;
    Timer* timer = new WINTimer;
    char* ptr;
    ptr = timer->printTime();
    cout<<"Zegar OSI pokazal: "<<ptr<<endl;
    delete timer;

    /*Decorator*/
    cout<< "Decorator" <<endl;

    Component* cA = new ConcreteDecoratorA(new ConcreteComponent);
    Component* cAB = new ConcreteDecoratorB(new ConcreteDecoratorA(new ConcreteComponent));

    cA->operation();
    cAB->operation();

    delete cA;
    delete cAB;
    return 0;
}
