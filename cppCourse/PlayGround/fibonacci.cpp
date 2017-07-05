#include "fibonacci.h"



Fibonacci::Fibonacci(int lenght)
{
    if(lenght<2){
        cout<<"damn za malo"<<endl;
    }else{
        this->m_lenght=lenght;
        this->array = new int[lenght];
    }
}

void Fibonacci::display()
{
    for (int i = 0; i < m_lenght; ++i) {
        cout<<i<<": "<<array[i]<<endl;
    }
}

void Fibonacci::makeNormalFib()
{
    array[0]=0;
    array[1]=1;
    for (int i = 2; i < m_lenght; ++i) {
        array[i]=array[i-1]+array[i-2];
    }
}

void Fibonacci::recFib(int i)
{
    if(i==0){
        array[0]=0;
    }else if(i==1){
        array[1]=1;
    }else{
        array[i]=array[i-1]+array[i-2];
    }
    i++;
    if(i!=m_lenght)
        recFib(i);

}

void Fibonacci::makeReclFib()
{
    recFib(0);
}
