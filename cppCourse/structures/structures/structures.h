#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <iostream>

using namespace std;

template<typename T>
class Structures
{
public:
    virtual T popFront()=0;
    virtual T popBack()=0;
    virtual void pushFront(T v)=0;
    virtual void pushBack(T v)=0;
};


#endif // STRUCTURES_H
