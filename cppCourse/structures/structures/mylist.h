#ifndef MYLIST_H
#define MYLIST_H
#include "structures.h"
#include "element.h"
#include <iostream>
#include <typeinfo>
#include <cstdio>
#include <cstring>
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
    enum SortType{
        FROM_MAX_TO_MIN,
        FROM_MIN_TO_MAX
    };

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

    T getAt(const int& index){
        if(index >= this->lenght()){
            cout<<"Ogranij sie chlopie, getAt, index :"<<index<<endl;
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
        cout<<"Ogranij sie chlopie, getAt, index :"<<index<<endl;
    }


    void setAt(const int& index, T v){
        if(index >= this->lenght()){
            cout<<"Ogranij sie chlopie, setAt, index :"<<index<<endl;
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


    void insertSort(SortType sortType = FROM_MIN_TO_MAX){
        T tmp;
        int j;
        if(type == NUMBER){

            if(sortType == FROM_MIN_TO_MAX){
                for(int i=1;i<this->lenght();i++){
                    j=i-1;
                    tmp = this->getAt(i);

                    while (j>=0 && this->getAt(j)>tmp) {
                        this->setAt(j+1,this->getAt(j));
                        j--;
                    }
                    this->setAt(j+1,tmp);
                }
            }else{
                for(int i=1;i<this->lenght();i++){
                    j=i-1;
                    tmp = this->getAt(i);

                    while (j>=0 && this->getAt(j)<tmp) {
                        this->setAt(j+1,this->getAt(j));
                        j--;
                    }
                    this->setAt(j+1,tmp);
                }
            }
        }else{
            if(sortType == FROM_MIN_TO_MAX){
                for(int i=1;i<this->lenght();i++){
                    j=i-1;
                    tmp = this->getAt(i);
                    while (j>=0 && (this->getAt(j).compare(tmp)>0)) {
                        this->setAt(j+1,this->getAt(j));
                        j--;
                    }
                    this->setAt(j+1,tmp);
                }
            }else{
                for(int i=1;i<this->lenght();i++){
                    j=i-1;
                    tmp = this->getAt(i);
                    while (j>=0 && (this->getAt(j).compare(tmp)<0)) {
                        this->setAt(j+1,this->getAt(j));
                        j--;
                    }
                    this->setAt(j+1,tmp);
                }
            }

        }
    }

    void quickSortRecoursive(const int& leftIndex,const int& rightIndex,SortType sortType = FROM_MIN_TO_MAX){

        T tmp;
        int centerIndex = (rightIndex + leftIndex)/2;
        T centerValue = this->getAt(centerIndex);
        int l = leftIndex;
        int r = rightIndex;

        if(type==NUMBER){
            if(sortType==FROM_MIN_TO_MAX){
                do{
                    while( this->getAt(l)<centerValue ) l++;
                    while( this->getAt(r)>centerValue ) r--;

                    if(l<=r){
                        tmp=this->getAt(l);
                        this->setAt(l,this->getAt(r));
                        this->setAt(r,tmp);

                        l++;
                        r--;
                    }
                }while(l<=r);
                if(l<rightIndex)quickSortRecoursive(l,rightIndex,sortType);
                if(leftIndex<r)quickSortRecoursive(leftIndex,r,sortType);
            }else{
                do{
                    while( this->getAt(l)>centerValue ) l++;
                    while( this->getAt(r)<centerValue ) r--;

                    if(l<=r){
                        tmp=this->getAt(l);
                        this->setAt(l,this->getAt(r));
                        this->setAt(r,tmp);

                        l++;
                        r--;
                    }
                }while(l<=r);
                if(l<rightIndex)quickSortRecoursive(l,rightIndex,sortType);
                if(leftIndex<r)quickSortRecoursive(leftIndex,r,sortType);
            }
        }else{
            if(sortType==FROM_MIN_TO_MAX){
                do{
                    while( this->getAt(l).compare(centerValue)<0 ) l++;
                    while( this->getAt(r).compare(centerValue)>0 ) r--;

                    if(l<=r){
                        tmp=this->getAt(l);
                        this->setAt(l,this->getAt(r));
                        this->setAt(r,tmp);

                        l++;
                        r--;
                    }
                }while(l<=r);
                if(l<rightIndex)quickSortRecoursive(l,rightIndex,sortType);
                if(leftIndex<r)quickSortRecoursive(leftIndex,r,sortType);
            }else{
                do{
                    while( this->getAt(l).compare(centerValue)>0 ) l++;
                    while( this->getAt(r).compare(centerValue)<0 ) r--;

                    if(l<=r){
                        tmp=this->getAt(l);
                        this->setAt(l,this->getAt(r));
                        this->setAt(r,tmp);

                        l++;
                        r--;
                    }
                }while(l<=r);
                if(l<rightIndex)quickSortRecoursive(l,rightIndex,sortType);
                if(leftIndex<r)quickSortRecoursive(leftIndex,r,sortType);
            }
        }


    }

    void quickSort(SortType sortType = FROM_MIN_TO_MAX){
        quickSortRecoursive(0,this->lenght()-1,sortType);
    }

    void selectionSort(SortType sortType = FROM_MIN_TO_MAX){
        T tmp;
        int m;
        if(type == NUMBER){
            if(sortType == FROM_MIN_TO_MAX){
                for(int i=0;i<this->lenght()-1;i++){
                    m=i;
                    for (int j = i+1; j < this->lenght(); j++) {
                        if(this->getAt(m) > this->getAt(j)){
                            m=j;
                        }
                    }
                    tmp = this->getAt(m);
                    this->setAt(m,this->getAt(i));
                    this->setAt(i,tmp);
                }
            }else{
                for(int i=0;i<this->lenght()-1;i++){
                    m=i;
                    for (int j = i+1; j < this->lenght(); j++) {
                        if(this->getAt(m) < this->getAt(j)){
                            m=j;
                        }
                    }
                    tmp = this->getAt(m);
                    this->setAt(m,this->getAt(i));
                    this->setAt(i,tmp);
                }
            }
        }else{
            if(sortType == FROM_MIN_TO_MAX){
                for(int i=0;i<this->lenght()-1;i++){
                    m=i;
                    for (int j = i+1; j < this->lenght(); j++) {
                        if(this->getAt(m).compare(this->getAt(j))>0){
                            m=j;
                        }
                    }
                    tmp = this->getAt(m);
                    this->setAt(m,this->getAt(i));
                    this->setAt(i,tmp);
                }
            }else{
                for(int i=0;i<this->lenght()-1;i++){
                    m=i;
                    for (int j = i+1; j < this->lenght(); j++) {
                        if(this->getAt(m).compare(this->getAt(j))<0){
                            m=j;
                        }
                    }
                    tmp = this->getAt(m);
                    this->setAt(m,this->getAt(i));
                    this->setAt(i,tmp);
                }
            }
        }
    }

    void mergeSort(SortType sortType = FROM_MIN_TO_MAX){

    }
};

#endif // MYLIST_H
