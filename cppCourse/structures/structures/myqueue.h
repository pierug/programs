#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "structures.h"
#include <iostream>
#include "element.h"

using namespace std;
template<typename T>
class MyQueue: public Structures<T>
{
public:
    MyQueue();

    Element<T>* frontElement;
    Element<T>* backElement;
    Element<T>* tmpPointer;
};

#endif // MYQUEUE_H
