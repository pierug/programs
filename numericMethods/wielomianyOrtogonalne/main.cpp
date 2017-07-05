#include <iostream>
#include <math.h>
using namespace std;

double wA(double x){
    return 1/(sqrt(1-(x*x)));
}

double fA(double x){
    return x*x;
}

double fB(double x){
    return cos(x);
}

void Chebyshev(){
    int n=3;
    double C = 0;
    double x;
    for(int i = 1;i<=n;i++){
        x = cos(((2*i-1)*M_PI)/(2*n));
        C += fA(x);
    }
    C = (C*M_PI)/n;
    cout<<"Wynik Chebysheva = "<<C<<endl;
}

void GaussHermite(){
    int n=5;
    double H[] = {0.019953, 0.393619, 0.945309, 0.393619, 0.019953};
    double x[] = {-2.020183, -0.958572, 0, 0.958572, 2.020183};
    double GH = 0;
    for(int i=0;i<n;i++){
        GH+=fB(x[i])*H[i];
    }
    cout<<"Wynik Hermite'a = "<<GH<<endl;
}
int main()
{
    Chebyshev();
    GaussHermite();
    return 0;
}
