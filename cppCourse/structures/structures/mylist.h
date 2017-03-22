#ifndef MYLIST_H
#define MYLIST_H
#include "structures.h"
#include "element.h"
#include <iostream>
#include <typeinfo>

using namespace std;
template<typename T>
class MyList: public Structures<T>
{
private:
    uint32_t len;
    enum Type{
        NUMBER,
        STRING
    };

public:
    explicit MyList(){
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        len=0;
        string check;
        T v;
        char* p;

        if((typeid(v).name()==typeid(check).name())||(typeid(v).name()==typeid(p).name())){
            type=STRING;
            cout << typeid(v).name() << endl;
        }else{
            type=NUMBER;
        }

    }
    explicit MyList(MyList& list){
        frontElement = NULL;
        backElement = NULL;
        tmpPointer = NULL;
        len=list.lenght();
        list.tmpPointer = list.backElement;
        int i=0;
        while(list.tmpPointer != NULL){
            this->pushFront(list.tmpPointer->value);
            list.tmpPointer = list.tmpPointer->next;
        }
    }

    Type type;
    uint32_t lenght(){
        return len;
    }

    Element<T>* frontElement;
    Element<T>* backElement;
    Element<T>* tmpPointer;


    ~MyList(){
        delete frontElement;
        delete backElement;
        delete tmpPointer;
    }

    T popFront(){
        if(this->backElement == NULL){
            cout<<"Empty Stack"<<endl;
            return NULL;
        }
        len--;
        T value= frontElement->value;
        tmpPointer = frontElement->prev;
        delete frontElement;
        frontElement = tmpPointer;
        frontElement->next = NULL;
        return value;
    }

    void pushFront(T v){
        len++;
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
        len--;
        T value= backElement->value;
        tmpPointer = backElement->next;
        delete backElement;
        backElement = tmpPointer;
        backElement->prev = NULL;
        return value;
    }
    void pushBack(T v){
        len++;
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

    void showFirstElementAdr(){
        cout<<"First Element Adres: "<<frontElement<<endl;
    }

    T getAt(uint32_t index){
        if(index >= this->lenght()){
            cout<<"Ogranij sie chlopie"<<endl;
            return NULL;
        }
        tmpPointer = backElement;
        int i=0;
        while(tmpPointer != NULL){
            if(i==index){
                return tmpPointer->value;
            }
            i++;
            tmpPointer = tmpPointer->next;
        }
        cout<<"Ogranij sie chlopie"<<endl;
    }


    void setAt(uint32_t index, T v){
        if(index >= this->lenght()){
            cout<<"Ogranij sie chlopie"<<endl;
        }else{
            tmpPointer = backElement;
            int i=0;
            while(tmpPointer != NULL){
                if(i==index){
                    tmpPointer->value = v;
                    break;
                }
                i++;
                tmpPointer = tmpPointer->next;
            }
        }
    }


    void insertSort(){

    }

    void quickSort(){

    }

    void selectionSort(){
        if(type == NUMBER){
            T tmp, M, I;
            int m;
            for(int i=0;i<this->lenght()-1;i++){
                m=i;

                for (int j = i+1; j < this->lenght(); j++) {
                    M = this->getAt(m);
                    I = this->getAt(j);
                    if(M < I){
                       //cout<<"Compare: "<<this->getAt(m)<<" < "<<this->getAt(j)<<endl;
                        m=j;
                        //cout<<m<<endl;
                    }
                }
                if(m=!i){
                    tmp = M = this->getAt(m);
                    I = this->getAt(i);
                    this->setAt(m,I);
                    this->setAt(i,M);
                    //tmp = this->getAt(m);
                    //this->setAt(m,this->getAt(i));
                    //this->setAt(i,tmp);

                }
            }
        }
    }

    void mergeSort(){

    }
};

#endif // MYLIST_H
