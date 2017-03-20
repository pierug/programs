#ifndef QUEUE_H
#define QUEUE_H
#include "mylist.h"

template<typename T>
class Queue: public MyList<T>{
public:
    /*Queue(): MyList(){

    }
    Queue(Queue& queue): MyList(queue){

    }*/
    void push(T v){
        MyList<T>::pushFront(v);
    }
    T dequeue(){
        return MyList<T>::popBack();
    }
};

#endif // QUEUE_H
