#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
using namespace std;
class Singleton
{
private:

    static Singleton* uniqueInstance;
    Singleton(){}

public:
    ~Singleton();
    static Singleton* getInstance();
    string s;
};

#endif // SINGLETON_H
