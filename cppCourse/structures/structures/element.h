#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>
using namespace std;
template<typename T>
class Element{
public:
    Element* next;
    Element* prev;
    T value;

    Element(T v){
        next = NULL;
        prev = NULL;
        value = v;
    }
/*
    ~Element(){
        cout<<"Delete next and prev"<<endl;
        delete next;
        delete prev;
    }*/
};

#endif // ELEMENT_H
