#include "singleton.h"

Singleton* Singleton::uniqueInstance = NULL;

Singleton::~Singleton()
{
    delete Singleton::uniqueInstance;
    Singleton::uniqueInstance = NULL;
}

Singleton *Singleton::getInstance()
{
    if(Singleton::uniqueInstance==NULL){
        Singleton::uniqueInstance = new Singleton;
    }
    return Singleton::uniqueInstance;
}
