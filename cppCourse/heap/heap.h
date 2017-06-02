#ifndef HEAP_H
#define HEAP_H

#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
class Heap {
public:
    Heap();
    ~Heap();

    void insert(T value);
    T deletemin();
    void print();
    int size() { return heap.size(); }

private:
    int getParentIndex(int nodeIndex){return nodeIndex/2;}
    int getLeftChildIndex(int nodeIndex){return nodeIndex*2;}
    int getRightChildIndex(int nodeIndex){return (nodeIndex*2)+1;}
    void reconfigurate();

    vector<T> heap;
    int chooseChild(int nodeIndex);
};

template <typename T>
Heap<T>::Heap()
{
    T null = NULL;
    heap.push_back(null);
}
template <typename T>
Heap<T>::~Heap()
{

}

template <typename T>
void Heap<T>::insert(T value)
{
    heap.push_back(value);
    reconfigurate();

}
template <typename T>
T Heap<T>::deletemin()
{
    T r = heap.at(1);
    swap(heap.at(1),heap.at(size()-1));
    heap.erase(heap.end()-1);
    //cout<<heap.at(1)<<endl;
    int i=1;
    while(i<size()){
        cout<<"index: "<<i<<endl;
        if(i*2+1<size()){
            if((heap.at(i*2)>heap.at(i)) && (heap.at(i*2+1)>heap.at(i))){
                if(heap.at(i*2)>heap.at(i*2+1)){
                    swap(heap.at(i),heap.at(i*2));
                    i=i*2;
                }else{
                    swap(heap.at(i),heap.at(i*2+1));
                    i=i*2+1;
                }
            }else if(heap.at(i*2)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2));
                i=i*2;
            }else if(heap.at(i*2+1)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2+1));
                i=i*2+1;
            }else{
                break;
            }
        }else if(i*2<size()){
            if(heap.at(i*2)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2));
                i=i*2;
            }else{
                break;
            }
        }else{
            break;
        }
    }
   /* for(int i = 1; i<size(); i=i*2)
    {
        cout<<"index: "<<i<<endl;
        if(i*2+1<size()){
            if((heap.at(i*2)>heap.at(i)) && (heap.at(i*2+1)>heap.at(i))){
                if(heap.at(i*2)>heap.at(i*2+1)){
                    swap(heap.at(i),heap.at(i*2));
                }else{
                    swap(heap.at(i),heap.at(i*2+1));
                    i++;
                }
            }else if(heap.at(i*2)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2));
            }else if(heap.at(i*2+1)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2+1));
                i++;
            }else{
                break;
            }
        }else if(i*2<size()){
            if(heap.at(i*2)>heap.at(i)){
                swap(heap.at(i),heap.at(i*2));
            }else{
                break;
            }
        }
    }*/
    return r;
}
template <typename T>
int Heap<T>::chooseChild(int nodeIndex){
    if(nodeIndex*2>size){
        return nodeIndex;
    }
    if(heap.at(nodeIndex*2)>heap.at(nodeIndex)){
        return nodeIndex*2;
    }
    if(nodeIndex*2+1>size){
        return nodeIndex;
    }
    if(heap.at(nodeIndex*2+1)>heap.at(nodeIndex)){
        return nodeIndex*2+1;
    }
    return nodeIndex;
}

template <typename T>
void Heap<T>::print()
{
    for (T v:heap) {
        cout<<v<<endl;
    }
}

template <typename T>
void Heap<T>::reconfigurate()
{
    for(int i = size()-1; i>1; i=i/2){
        if(heap.at(i)>heap.at(i/2)){
            swap(heap.at(i),heap.at(i/2));
        }
    }
}

#endif // HEAP_H
