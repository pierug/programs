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

void Newton(int n, double *x, double *f, double arg){
    double result = 0;
    double t[n];
    n--;
    for(int i =0;i<=n;i++){
        t[i] = f[i];
    }
    for(int k=1;k<=n;k++){
            cout<<"k = " <<k <<endl;
        for(int i=n;i>=k;i--){
            t[i]=(t[i]-t[i-1])/(x[i]-x[i-k]);
            cout<<"t["<<i<<"]: "<< t[i] <<endl;
        }
    }
    n++;
    double N[n];
    for(int i=0;i<n;i++){
        N[i]= t[i];
        for(int k=0;k<i;k++){
            N[i]*=(arg-x[k]);
        }
        result+=N[i];
    }
    cout<<"wynik Newtona'a: "<< result <<endl;
}

void Cw1(){

    int n = 4;
    double arg = 4;
    double wynik=0;
    cout<<"Podaj argument funkcji N: ";
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
        Newton(n,x,f,arg);
    }else{
        cout<<"Nie spelnia warunkow"<<endl;
    }
}

int main()
{
    Cw1();

    return 0;
}
