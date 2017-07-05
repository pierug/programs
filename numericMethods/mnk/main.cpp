#include <iostream>
#include <cmath>

using namespace std;

bool check(double *x,int n)
{
    for(int i=1;i<n;i++)
    {
        if(x[i-1]>=x[i]){
            cout<<"x[i-1]>=x[i] "<<endl;
            return false;
        }
    }
}

void MNK(int n,double* x,double *f){
    double Ex = 0;
    double Ex2 = 0;
    double Ef = 0;
    double Efx = 0;
    double n1 = n+1;
    for(int i=0;i<n+1;i++){
        Ex += x[i];
        Ex2 += x[i]*x[i];
        Ef += f[i];
        Efx += f[i]*x[i];
    }
    double W=(n1*Ex2)-(Ex*Ex);
    double Wa0=(Ef*Ex2)-(Efx*Ex);
    double Wa1=(n1*Efx)-(Ef*Ex);
    double a0 = (double)(Wa0/W);
    double a1 = (double)(Wa1/W);

    cout<<"y= "<<a0<<" + "<<a1<<"x"<<endl;
}

void MNK2(int n,double* x,double *f){
    double Ex = 0;
    double Ex2 = 0;
    double Ef = 0;
    double Efx = 0;
    double n1 = n+1;

    for(int i=0;i<n+1;i++){
        f[i] = log(f[i]);
        Ex += x[i];
        Ex2 += x[i]*x[i];
        Ef += f[i];
        Efx += f[i]*x[i];
        cout<<"f["<<i<<"]= "<<f[i]<<endl;
    }
    cout<<"Ex= "<<Ex<<endl;
    cout<<"Ex2= "<<Ex2<<endl;
    cout<<"Ef= "<<Ef<<endl;
    cout<<"Efx= "<<Efx<<endl;
    double W=(n1*Ex2)-(Ex*Ex);
    double Wa0=(Ef*Ex2)-(Efx*Ex);
    double Wa1=(n1*Efx)-(Ef*Ex);
    cout<<"W= "<<W<<endl;
    cout<<"Wa0= "<<Wa0<<endl;
    cout<<"Wa1= "<<Wa1<<endl;
    double a0 = (double)(Wa0/W);
    double a1 = (double)(Wa1/W);
    a0 = exp(a0);
    a1 = exp(a1);
    cout<<"y(x) = "<<a0<<" * "<<a1<<"^x"<<endl;
}

void Cw1(){
    int n = 0;
    int decision = 0;
    cout<<"1) Funkcja Liniowa"<<endl<<"2) Funkcja Wykladnicza"<<endl;
    cin>>decision;
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
    if(check(x,n)){
        switch(decision){
            case 1:{
                MNK(n-1,x,f);
                break;
            }
            case 2:{
                MNK2(n-1,x,f);
                break;
            }
        }
    }
}

int main()
{
    Cw1();
    return 0;
}
