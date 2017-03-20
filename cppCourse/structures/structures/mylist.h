#ifndef MYLIST_H
#define MYLIST_H
#include "structures.h"
#include "element.h"
#include <iostream>


using namespace std;
template<typename T>
class MyList: public Structures<T>
{
public:
    explicit MyList(){
        cout<<"constructor"<<endl;
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
    }
    explicit MyList(MyList& list){
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        list.tmpPointer = list.backElement;
        int i=0;
        while(list.tmpPointer != NULL){
            this->pushFront(list.tmpPointer->value);
            list.tmpPointer = list.tmpPointer->next;
        }
    }

    Element<T>* frontElement;
    Element<T>* backElement;
    Element<T>* tmpPointer;

    ~MyList(){
        cout<<"destructor"<<endl;
        delete frontElement;
        delete backElement;
        delete tmpPointer;
    }

    T popFront(){
        if(this->backElement == NULL){
            cout<<"Empty Stack"<<endl;
            return NULL;
        }
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

    T popBack(){
        if(this->backElement == NULL){
            cout<<"Empty Stack"<<endl;
            return NULL;
        }
        T value= backElement->value;
        tmpPointer = backElement->next;
        delete backElement;
        backElement = tmpPointer;
        backElement->prev = NULL;
        return value;
    }
    void pushBack(T v){
        Element<T>* newElement = new Element<T>(v);

        if(this->backElement == NULL){
            this->backElement = newElement;
            this->frontElement = newElement;
        }else{
            tmpPointer = backElement;
            backElement = newElement;
            tmpPointer->prev = backElement;
            backElement->next = tmpPointer;
        }
    }

    void display(){
        string s;

        tmpPointer = backElement;
        int i=0;
        while(tmpPointer != NULL){
            cout<<i<<": ";
            cout<<tmpPointer->value<<endl;
            i++;
            tmpPointer = tmpPointer->next;
        }
    }

    MyList & operator=(MyList& list){
        if(this == &list){
            return *this;
        }
        delete frontElement;
        delete backElement;
        delete tmpPointer;
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        list.tmpPointer = list.backElement;
        while(list.tmpPointer != NULL){
            this->pushFront(list.tmpPointer->value);
            list.tmpPointer = list.tmpPointer->next;
        }
    }
};

#endif // MYLIST_H
