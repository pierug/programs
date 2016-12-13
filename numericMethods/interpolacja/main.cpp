#include <iostream>

using namespace std;


bool check(double xp,double *x,int n)
{
    for(int i=1;i<n;i++)
    {
        if(x[i-1]>=x[i]){
            cout<<"x[i-1]>=x[i] "<<endl;
            return false;
        }

    }

    if(xp>=x[0] && xp<=x[n-1]){
        cout<<"OK "<<endl;
        return true;
    }
    else{
        cout<<"xp "<<xp<<endl;
        cout<<"x[0] "<<x[0]<<endl;
        cout<<"x[n] "<<x[n-1]<<endl;
        return false;
    }

}

void Lagrange(int n, double *x, double *f, double arg){
    double wynik = 0;
    double L[n];
    for(int i=0;i<n;i++){
        L[i] = 1;
        for(int k=0;k<n;k++){
            if(k!=i){
                L[i] *= (arg-x[k])/(x[i]-x[k]) ;
            }
        }
        wynik += f[i]*L[i];
    }
    cout<<"wynik Lagrange'a: "<< wynik <<endl;
}

void Cw2(){

    int n;
    double arg;
    double wynik=0;
    cout<<"Podaj argument funkcji L: ";
    cin>>arg;
    cout<<"Podaj liczbe punktow: ";
    cin>>n;
    double x[n];
    double f[n];
    for(int i=0;i<n;i++){
        cout<<"Podaj punkt ["<<i<<"] x: ";
        cin>>x[i];
        cout<<"Podaj ["<<i<<"] f: ";
        cin>>f[i];
    }

    if(check(arg,x,n)){
        Lagrange(n,x,f,arg);
    }else{
        cout<<"Nie spelnia warunkow"<<endl;
    }


}

int main()
{
    Cw2();
    return 0;
}
