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
    Pies p1("AZOR");
    Zwierze z1("Bydle");
    Zwierze& refZwierze = z1;
    Zwierze& refPies = p1;
    cout<<refZwierze.naLancuch()<<endl;
    cout<<refPies.naLancuch()<<endl;

    Pies *p2 = new Pies("BUREK");
    Zwierze *z2 = new Zwierze("Mord");
    Zwierze *pointZwierze = z2;
    Zwierze *pointPies = p2;
    cout<<pointZwierze->naLancuch()<<endl;
    cout<<pointPies->naLancuch()<<endl;

    return 0;
}
