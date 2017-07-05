#ifndef FACTORYMETHOD_H
#define FACTORYMETHOD_H
#include <iostream>
using namespace std;

class Computer{
public:
    virtual string getType()=0;
    virtual ~Computer(){}
};
class Assus: public Computer{
public:
    string getType(){
        cout<<"Assus"<<endl;
    }
};

class HP: public Computer{
public:
    string getType(){
        cout<<"HP"<<endl;
    }
};
class ComputerAbstractFactory{
public:
    virtual Computer* factoryMethod(const string & type)=0;
    virtual ~ComputerAbstractFactory(){}
};

class ComputerFactory: public ComputerAbstractFactory
{
public:
    Computer* factoryMethod(const string & type){
        if(type == "Assus"){
            return new Assus();
        }else if(type == "HP"){
            return new HP();
        }
        return NULL;
    }

};

#endif // FACTORYMETHOD_H
