#include <iostream>
#include <typeinfo>
using namespace std;

struct kot{
    string imie;
    int radosc;
};

struct pies {
    string imie;
    int radosc;
};

void bawSie(pies *p,kot *k,int n){
    p->radosc +=n;
    k->radosc--;
}

void funkcja(int &a){
    unsigned int adr=reinterpret_cast<unsigned int>(&a);
    cout<<"adres (dzisietnie): "<<dec<<adr<<endl;
}

int main(int argc, char *argv[])
{
    /*
    kot k;
    pies p;
    k.radosc=10;
    p.radosc=10;

    cout<<k.radosc<<endl;
    cout<<p.radosc<<endl;
    cout<<typeid(k.imie).name()<<endl;
    */
    int i=10;
    const int &r=i;
    cout<<"adres (dziesietnie): "<<dec<<reinterpret_cast<int>(&i)<<endl;
    funkcja(const_cast<int &>(r));
    int j=15;
    cout<<"i="<<i<<" j=0"<<j<<" a i/j="<<i/j<<endl;
    return 0;
}
