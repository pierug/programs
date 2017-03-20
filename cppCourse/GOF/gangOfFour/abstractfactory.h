#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>
using namespace std;

class Vehicle{
public:

    virtual void display()=0;
};

class CarBMW: public Vehicle{
public:
    void display(){
        cout<<"Car BMW"<<endl;
    }
};

class CarMercedes: public Vehicle{
public:
    void display(){
        cout<<"Car Mercedes"<<endl;
    }
};

class MotorBMW:public Vehicle{
public:
    void display(){
        cout<<"Motor BMW"<<endl;
    }
};

class MotorMercedes:public Vehicle{
public:
    void display(){
        cout<<"Motor Mercedes"<<endl;
    }
};


class AbstractFactory{
public:
    virtual Vehicle *createCar()=0;
    virtual Vehicle *createMotor()=0;
};

class BMWFactory: public AbstractFactory{
public:
    Vehicle* createCar(){
        return new CarBMW;
    }
    Vehicle *createMotor(){
        return new MotorBMW;
    }
};

class MercedesFactory: public AbstractFactory{
public:
    Vehicle *createCar(){
        return new CarMercedes;
    }

    Vehicle *createMotor(){
        return new MotorMercedes;
    }
};

#endif // ABSTRACTFACTORY_H
