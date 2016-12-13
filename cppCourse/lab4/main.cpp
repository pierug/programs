#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Tablica2D{

private:
    int szerokosc;
    int wysokosc;
    string nazwa;
    int *poczotek;
public:
    Tablica2D(int s, int w,string n){
        szerokosc = s;
        wysokosc = w;
        nazwa = n;
        poczotek = new int[szerokosc*wysokosc];
    }

    Tablica2D(const Tablica2D& t){
        szerokosc = t.szerokosc;
        wysokosc = t.wysokosc;
        nazwa = t.nazwa;
        poczotek = t.poczotek;
    }

    ~Tablica2D(){
        cout<<"Destruktor: "<<this->nazwa<<endl;
        delete[] poczotek;
    }

    void setNazwa(string s){
        nazwa = s;
    }

    const string getNazwa()const{
        return nazwa;
    }

    const string& name()const{
        return nazwa;
    }

    const int getElement(int s, int w)const{
        return poczotek[w*this->szerokosc+s];
    }

    void setElement(int s, int w, int value){

        poczotek[w*this->szerokosc+s] = value;
    }

    Tablica2D dodaj(const Tablica2D& dodawana)const{
        Tablica2D t(this->szerokosc,this->wysokosc,"Dodana");
        for(int i=0;i<this->wysokosc;i++){
            for(int j=0;j<this->szerokosc;j++){
                t.setElement(j,i,(dodawana.getElement(j,i)+this->getElement(j,i)));
            }
        }
        return t;
    }

    Tablica2D mnoz(const Tablica2D& mnozona)const{
        Tablica2D t(this->szerokosc,this->wysokosc,"Mnozona");
        int value;
        for(int i=0;i<this->wysokosc;i++){
            for(int j=0;j<this->szerokosc;j++){
                value=0;
                for(int k=0;k<this->szerokosc;k++){
                    value+=mnozona.getElement(j,k)*this->getElement(k,i);
                }
                t.setElement(j,i,value);
            }
        }
        return t;
    }

    ostream& wyswietl(ostream& os)const{
        os<<this->getNazwa()<<endl;
        for(int i=0;i<this->wysokosc;i++){
            for(int j=0;j<this->szerokosc;j++){
                os<<setw(3)<<this->getElement(j,i);
            }
            os<<endl;
        }
        return os;
    }
};

int main(int argc, char *argv[])
{
    Tablica2D A(3,3,"A");
    Tablica2D B(3,3,"B");

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            A.setElement(j,i,j+3*i);
            B.setElement(j,i,sqrt(j+i+i));
        }
    }

    A.wyswietl(cout);
    B.wyswietl(cout);
    Tablica2D D = A.mnoz(B);
    D.wyswietl(cout);
    Tablica2D C = A.dodaj(B);
    C.wyswietl(cout);

    return 0;
}
