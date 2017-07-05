#include <iostream>
#include <assert.h>
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
    const string getImie() const{
        return mImie;
    }
    friend ostream& operator <<(ostream& os, Zwierze& z);

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

class Miska{
private:
    int wartoscPorcji;

public:
    void operator()(int porcja){
        wartoscPorcji=porcja;
    }
    int dajPorcje(){
        return wartoscPorcji;
    }
};

class Pies: public Zwierze, public FunkcjeZyciowe{
private:
    enum Plec{PIES,SUKA};
    Plec plec;
    friend class Czlowiek;
    void jedz(int iloscPozywnia){
        glod+=iloscPozywnia;
    }

public:

    Pies(string imie): Zwierze(imie){
        int i = rand()%100+1;
        if(i%2){
            plec = PIES;
        }else{
            plec = SUKA;
        }
    }
    Pies operator +(Pies& p){
        assert(this->plec!=p.plec);
        Pies pies(this->getImie()+p.getImie());
        return pies;
    }

    void szczekaj(){
        cout<<"HOW!!!"<<endl;
    }
    void dajLape(){
        cout<<"DajeLape!!!"<<endl;
    }
    string dajRodzajZwierzecia(){
        string p="";
        switch (plec) {
        case SUKA:
            p="Suka, ";
            break;
        case PIES:
            p="Pies, ";
            break;
        }
        return p+"Pies: ";
    }
    void operator <<(Miska& m){
        jedz(m.dajPorcje());
        m(0);
    }


    void bawSie(int czas){

        glod-=czas;
        humor+=czas;
    }
};

class Czlowiek{
private:
    string imie;
    enum Plec{M,K};
    Plec plec;
    int wiek;
public:
    Czlowiek(string i,int w){
        imie = i;
        wiek = w;
        int tmp = rand()%100+1;
        if(tmp%2){
            plec = M;
        }else{
            plec = K;
        }
    }
    const string getImie()const{
        return imie;
    }
    const int getWiek()const{
        return wiek;
    }
    const string getPlec()const{
        string p="";
        switch (plec) {
        case K:
            p="Baba";
            break;
        case M:
            p="Facet";
            break;
        }
        return p;
    }
    void karmPsa(Pies& p,Miska& m){
        p.jedz(m.dajPorcje());
    }
    friend ostream& operator <<(ostream& os,Czlowiek& cz);
};

ostream& operator <<(ostream& os, Zwierze& z){
    os<<z.naLancuch()<<endl;
    return os;
}
ostream& operator <<(ostream& os,Czlowiek& cz){
    os<<cz.getImie()+", "+cz.getPlec()+", wiek: "+to_string(cz.getWiek());
    return os;
}

int main()
{
    Pies p1("AZOR");
    Pies p2("Bunia");
    Pies p3("Melchior");

    cout<<p1.naLancuch()<<endl;
    cout<<p2.naLancuch()<<endl;
    cout<<p3.naLancuch()<<endl;
    Pies p4 = p2+p3;

    Miska m;
    m(4);
    p4<<m;
    //cout<<p4.naLancuch()<<endl;
    p4<<m;
    //cout<<p4.naLancuch()<<endl;
    cout<<p4<<endl;
    Czlowiek cz("Adam",23);
    cout<<cz<<endl;
    m(6);
    cz.karmPsa(p4,m);
    cout<<p4<<endl;
    return 0;
}
