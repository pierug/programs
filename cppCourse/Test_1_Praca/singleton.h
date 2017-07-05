#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>
#include <vector>

using namespace std;

class Singleton
{
public:
    static Singleton* getInstance();
    void disp();
    int* makeFibonaci(int n);
    int *makeRecFibonaci(int i,int n,int* array);
    void dispArray(int n, int *array);
    vector<string> splitStringTxt(string txt, const char pattern);
    void dispSplitTxt(const vector<string> stringVec);
    void Karp_Rabin(string txt, string patern);
    void quicksort(int *array, int left, int right);
    void insertsort(int lenght, int *array);
    void selectionsort(int lenght, int *array);
private:
    ~Singleton();
    Singleton(){}
    static Singleton* instance;
};

#endif // SINGLETON_H
