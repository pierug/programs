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
    const string& naLancuch()const{
        return mImie;
    }
};

int main()
{
    Zwierze z("AZOR");
    cout<<z.naLancuch()<<endl;
    const Zwierze& zRef = z;
    cout<<zRef.naLancuch()<<endl;
    return 0;
}
