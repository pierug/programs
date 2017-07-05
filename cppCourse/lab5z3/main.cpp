#include <iostream>

using namespace std;

class Zwierze{
private:
    string mImie;
public:
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

int main()
{
    Pies p("AZOR");
    cout<<p.naLancuch()<<endl;
    p.dajLape();
    p.szczekaj();
    return 0;
}
