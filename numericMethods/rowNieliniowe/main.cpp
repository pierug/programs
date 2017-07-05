#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define K_MAX 50
inline double f(double x){
    return x*x*x-2*x*x-4*x-7;
}

inline double fp(double x){
    return 3*x*x-4*x-4;
}

inline double fpp(double x){
    return 6*x-4;
}

void bisekcja(double eps, double a, double b){
    int k=0;
    double x;
    while(fabs(b-a)>eps){
        k++;
        x=(a+b)/2;
        if(f(x)*f(a)<0)
            b = x;
        else
            a = x;
    }
    cout<<"miejsce zerowe bisekcja: "<<(a+b)/2<<", liczba krokow: "<<k<<", esp: "<<eps<<endl;
}

void Newton(double eps, double a, double b){
    double x;
    if(f(b)*fpp(b)>0){
        x=b;
    } else if(f(a)*fpp(a)>0){
        x=a;
    }
    int k=0;
    while(fabs(f(x))>eps){
        k++;
        x=x-(f(x)/fp(x));
        if(k>K_MAX)
            break;
    }
    cout<<"miejsce zerowe Newton: "<<x<<", liczba krokow: "<<k<<", esp: "<<eps<<endl;
}

double pierwiastekTrzeciego(double a)
{
    double eps = 0.000001;
    double x=a;
    int k=0;
    while(fabs(x*x*x-a)>eps){
        k++;
        x=x-((x*x*x-a)/(3*x*x));
        if(k>K_MAX){
           break;
        }
    }
    return x;
}

int main()
{
    double eps,a,b;
    cout<<"Wprowadz eps "<<endl;
    cin>>eps;
    cout<<"Wprowadz a "<<endl;
    cin>>a;
    cout<<"Wprowadz b "<<endl;
    cin>>b;
    bisekcja(eps,a,b);
    Newton(eps,a,b);
    cout<<"Pierwiastek trzeciego stopnia z 7: "<<pierwiastekTrzeciego(7)<<endl;
    return 0;
}
