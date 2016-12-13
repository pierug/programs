#include <iostream>
#include <math.h>
using namespace std;

int nrCwiczenia = 0;

double f(double x){
    if(nrCwiczenia == 1)
        return ((cos(x)*cos(x)) + 1);
    else if(nrCwiczenia == 2)
        return 1/x;
    return 1;
}

void metodaTrapezow(double a ,int n, double h){
    double T = 0;
    double x=a;
    T+= f(x) * 0.5;
    for(int i=1;i<n;i++){
        x = a + (i * h);
        T+= f(x);
    }
    x = a + (n * h);
    T+= f(x) * 0.5;
    T = T*h;
    cout<<"wynik metoda trapezow: "<<T<<endl;
}

void metodaSimpsona(double a, double b,int n, double h){
    if(n%2){
        n=n+1;
        h=(b-a)/n;
    }
    long double result = f(a);
    double x=a;
    for(int i=1;i<n;i++){
        x = a + (i * h);
        if(i%2){
           result+=f(x)*4;
        }else{
           result+=f(x)*2;
        }
    }
    x = a + (n * h);
    result += f(x);

    result *= (double)(h/3);
    cout<<"wynik metoda Simpsona: "<<result<<endl;
}

void cw1(){
    nrCwiczenia = 1;
    cout<<"Cwiczenie 1) "<<endl;
    double a = 0;
    double b = M_PI*2;
    double h;

    cout<<"podaj krok h, pi/x: "<<endl;
    cin>>h;
    h = M_PI/h;
    double n = (b - a)/h;
    metodaTrapezow(a,n,h);
    metodaSimpsona(a,b,n,h);
}

void cw2(){
    nrCwiczenia = 2;
    cout<<"Cwiczenie 2) "<<endl;
    double a = 1;
    double b = 7;
    double h;
    cout<<"podaj krok h=  ";
    cin>>h;
    double n = (b - a)/h;
    metodaTrapezow(a,n,h);
    metodaSimpsona(a,b,n,h);
}

int main()
{
    cw1();
    cw2();
    return 0;
}
