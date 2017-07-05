#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "structures.h"
#include "element.h"

using namespace std;
template<typename T>
class MyStack : public Structures<T>
{
public:
    MyStack(){
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
    }
    MyStack(MyStack& stack){
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        stack.tmpPointer = stack.backElement;
        int i=0;
        while(stack.tmpPointer != NULL){
            this->pushFront(stack.tmpPointer->value);
            stack.tmpPointer = stack.tmpPointer->next;
        }
    }

    Element<T>* frontElement;
    Element<T>* backElement;
    Element<T>* tmpPointer;

    ~MyStack(){
        delete frontElement;
        delete backElement;
        delete tmpPointer;
    }

    T popFront(){
        if(this->backElement == NULL){
            cout<<"Empty Stack"<<endl;
            return NULL;
        }
        //elementNumbers--;
        T value= frontElement->value;
        tmpPointer = frontElement->prev;
        delete frontElement;
        frontElement = tmpPointer;
        frontElement->next = NULL;
        return value;
    }

    void pushFront(T v){
        Element<T>* newElement = new Element<T>(v);

        if(this->backElement == NULL){
            this->backElement = newElement;
            this->frontElement = newElement;
        }else{
            tmpPointer = frontElement;
            frontElement = newElement;
            tmpPointer->next = frontElement;
            frontElement->prev = tmpPointer;
        }
    }

    T popBack(){}
    void pushBack(T v){}

   // friend ostream & operator<<(ostream & os,const MyStack<T>& str);

    void display(){
        string s;
        tmpPointer = backElement;
        int i=0;
        while(tmpPointer != NULL){
            s+= to_string(i)+": "+to_string(tmpPointer->value)+"\n";
            i++;
            tmpPointer = tmpPointer->next;
        }
        cout<<s;
    }

    MyStack & operator=(MyStack& stack){
        if(this == &stack){
            return *this;
        }
        delete frontElement;
        delete backElement;
        delete tmpPointer;
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        stack.tmpPointer = stack.backElement;
        while(stack.tmpPointer != NULL){
            this->pushFront(stack.tmpPointer->value);
            stack.tmpPointer = stack.tmpPointer->next;
        }
    }
};
/*
template<typename T>
ostream & operator<<(ostream & os,const MyStack<T>& str){

    str.tmpPointer = str.backElement;
    int i=0;
    while(str.tmpPointer->next != NULL){
        os<<i<<": "<<str.tmpPointer->value<<endl;
        i++;
        str.tmpPointer = str.tmpPointer->next;
    }
    return os;
}*/
#endif // STACK_H
