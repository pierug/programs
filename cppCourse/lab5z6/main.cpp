#include <iostream>

using namespace std;

class Zwierze{
private:
    string mImie;
public:
    Zwierze(){
        mImie = "";
    }
    Zwierze(string imie){
        mImie = imie;
    }
    void setImie(string imie){
        mImie = imie;
    }
    string naLancuch(){
        return dajRodzajZwierzecia() + mImie;
    }
    virtual string dajRodzajZwierzecia(){
        return "Zwierzatko: ";
    }
};

class Pies: public Zwierze{
private:

public:
    Pies(string imie): Zwierze(imie){

    }
    void szczekaj(){
        cout<<"HOW!!!"<<endl;
    }
    void dajLape(){
        cout<<"DajeLape!!!"<<endl;
    }
    string dajRodzajZwierzecia(){
        return "Pies: ";
    }
};

class SchroniskoDlaZwierzat{
private:
    Zwierze *zwierze;
    int indexZwierzecia;
public:
    SchroniskoDlaZwierzat(){
        zwierze = new Zwierze[100];
        indexZwierzecia = 0;
    }
    ~SchroniskoDlaZwierzat(){
        cout<<"Destruktor schroniska"<<endl;
        delete[] zwierze;
    }

    Zwierze *dajZwierze(int nr){
        return &zwierze[nr];
    }
    void dodajZwierze(Zwierze z){
        zwierze[indexZwierzecia] = z;
        indexZwierzecia++;
    }
};

int main()
{
    Pies p1("AZOR");
    Pies p2("Bydle");

    SchroniskoDlaZwierzat schron;
    schron.dodajZwierze(p1);
    schron.dodajZwierze(p2);

    cout<<schron.dajZwierze(0)->naLancuch()<<endl;
    return 0;
}
