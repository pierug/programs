#include "effort.h"
#include <ctime>
#include <iostream>
#include <chrono>
#include <numeric>

using namespace std;

int Effort::getWithGetSet() const
{
    return withGetSet;
}

void Effort::setWithGetSet(int value)
{
    withGetSet = value;
}

Effort::Effort()
{

}

void Effort::efforTestWith()
{
    uint32_t get;

    auto start = chrono::system_clock::now();
    for (int j = 0; j < 10000; ++j) {
        for (int i = 0; i < 10000; ++i) {
            get = this->getWithGetSet();
            this->setWithGetSet(get++);
        }
    }

    auto end = chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout<<"With get set: "<<diff.count()<<endl;
}

void Effort::efforTestWithout()
{
    uint32_t get;

    auto start = chrono::system_clock::now();
    for (int j = 0; j < 10000; ++j) {
        for (int i = 0; i < 10000; ++i) {
            get = withoutGetSet;
            withoutGetSet = get++;
        }
    }

    auto end = chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout<<"Without get set: "<<diff.count()<<endl;
}
