#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <iostream>
#include <vector>

using namespace std;

class Fibonacci
{
private:
    int m_lenght;
    int *array;
    void recFib(int i);
public:
    Fibonacci(int lenght);
    ~Fibonacci(){
        delete array;
    }
    void display();
    void makeNormalFib();
    void makeReclFib();
};

#endif // FIBONACCI_H
