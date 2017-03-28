#include <iostream>
#include "singleton.h"
#include "abstractfactory.h"
#include "prototype.h"
#include "factorymethod.h"
#include "builder.h"
#include "adapter1.h"
#include "decorator.h"
#include "facade.h"
#include "proxy.h"
#include "composite.h"
#include "ceocomposite.h"

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

    /*Facade*/
    cout<<"Facade"<<endl;

    systemInterface::software();

    /*Proxy*/
    cout<<"Proxy"<<endl;

    Payment payment;
    Programmer programer[4];
    Salesman salesman[4];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            if(i%2){
                if(payment.withdraw(programer[j],(1+j)*200)){
                    cout<<programer[j].getName()<<" otrzymal "<<(1+j)*200<<"zl"<<endl;
                }else{
                    cout<<programer[j].getName()<<" nie otrzymal wylaty"<<endl;
                }
                cout<<"Na koncie pozostalo: "<<payment.getAccountSum()<<"zl"<<endl;
            }else{
                if(payment.withdraw(salesman[j],(1+j)*150)){
                    cout<<salesman[j].getName()<<" otrzymal "<<(1+j)*150<<"zl"<<endl;
                }else{
                    cout<<salesman[j].getName()<<" nie otrzymal wylaty"<<endl;
                }
                cout<<"Na koncie pozostalo: "<<payment.getAccountSum()<<"zl"<<endl;
            }
        }
    }

    /*Composite*/
    cout<<"Composite"<<endl;

    TreeComposite treeComposite;
    for (int i = 0; i < 4; ++i) {
        treeComposite.add(new Leaf(i*2+3));
    }
    treeComposite.print();

    /*CEO Composite*/
    cout<<"CEO Composite"<<endl;

    Manager president("Adam Piasecki", 10000000.0);

    Manager manager_engineering_department ("Michael Biner",400000.0);
    Manager manager_quality_control_department ("David Jaskson",280000.0);

    Manager team_leader_RandD ("Jorge Creig", 250000.0);
    Manager team_leader_QA ("Arnold Lambero", 200000.0);

    Worker software_developer1 ("Andrey Lapidos", 200000.0);
    Worker software_developer2 ("Maxim  Laertsky", 240000.0);
    Worker tester ("Miki  Minaj", 130000.0);

    president.add(&manager_engineering_department);
    president.add(&manager_quality_control_department);

    manager_engineering_department.add(&team_leader_RandD);
    manager_engineering_department.add(&team_leader_QA );

    team_leader_RandD.add(&software_developer1);
    team_leader_RandD.add(&software_developer2);

    team_leader_QA.add(&tester);

    cout << "The hierarchy of the company,\ni.e. president and all who is under his supervision :\n\n" ;
        president.printSalary(0);

    return 0;

}
