#include <iostream>

using namespace std;

class Zwierze{
private:
    string mImie;
protected:
    int glod;
    int humor;
public:
    Zwierze(){
        mImie = "";
        glod = 0;
        humor = 0;
    }
    Zwierze(string imie){
        mImie = imie;
        glod = 0;
        humor = 0;
    }
    void setImie(string imie){
        mImie = imie;
    }
    string naLancuch(){
        return dajRodzajZwierzecia() + mImie +", glod: "+to_string(glod)+", humor: "+to_string(humor);
    }
    virtual string dajRodzajZwierzecia(){
        return "Zwierzatko: ";
    }
};

class FunkcjeZyciowe{
private:

public:
    virtual void jedz(int iloscPozywnia)=0;
    virtual void bawSie(int czas)=0;
};

class Pies: public Zwierze, public FunkcjeZyciowe{
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
    void jedz(int iloscPozywnia){
        glod+=iloscPozywnia;
    }
    void bawSie(int czas){
        glod-=czas;
        humor+=czas;
    }
};



int main()
{
    Pies p1("AZOR");

    p1.jedz(6);
    cout<<p1.naLancuch()<<endl;
    p1.bawSie(4);
    cout<<p1.naLancuch()<<endl;
    FunkcjeZyciowe& fz = p1;
    fz.jedz(6);
    Pies &p2= dynamic_cast<Pies &>(fz);
    cout<<p2.naLancuch()<<endl;
    fz.bawSie(4);
    cout<<p2.naLancuch()<<endl;

    return 0;
}
