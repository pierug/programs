#ifndef TEMPLATEMETHOD_H
#define TEMPLATEMETHOD_H
#include <iostream>
#include <cstdlib>
using namespace std;

class TemplateSort{
public:
    void shellSort(int *v, int n){
        for(int g=n/2;g>0;g/=2){
            for (int i = g; i < n; i++) {
                for (int j = i-g; j >= 0; j-=g) {
                    if(sort(v[j],v[j+g])){
                        swap(v[j],v[j+g]);
                    }
                }
            }
        }
    }
    virtual ~TemplateSort(){}
private:
    virtual int sort(int,int)=0;
    void swap(int& a, int& b){
        int t=a;
        a=b;
        b=t;
    }
};

class Increase: public TemplateSort{
private:
    int sort(int a, int b){
        return a>b;
    }
};

class Decrease: public TemplateSort{
private:
    int sort(int a, int b){
        return a<b;
    }
};

#endif // TEMPLATEMETHOD_H
