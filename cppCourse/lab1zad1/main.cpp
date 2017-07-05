#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;



void konwerter(){
    string input;
    cin>>input;
    stringstream ss;
    int value;
    if(input.substr(0,2)=="0x"){
        input[1]='0';
        ss<<hex <<input;
        ss>>value;

    }else if(input.front()=='0'){
        ss<<oct <<input;
        ss>>value;
    }else {
        value = stoi(input);
    }
    cout<<"jaką reperezentacje wybierasz 1-hex, 2-oct, 3-dec"<<endl;
    int wybor=0;
    cin>>wybor;
    switch(wybor){
        case 1:{
            cout<<showbase<<hex<<value;
            break;
        }
        case 2:{
            cout<<showbase<<oct<<value;
            break;
        }
        case 3:{
            cout<<value;
            break;
        }
    }
}

struct Pracownicy{
    string imie;
    int stawka;
    int liczbaH;
    string data;
};

void stworzPracownika(Pracownicy &p, string n, int s, int lH,string d){
    p.data=d;
    p.imie = n;
    p.stawka = s;
    p.liczbaH = lH;
}

void wyswietlTabPrac(Pracownicy *p){
    for(int i=0;i<2;i++){
       cout<<setw(15)<<p[i].imie<<setw(15)<<p[i].stawka<<setw(15)<<p[i].liczbaH<<setw(15)<<p[i].data<<endl;
    }
}

void dwojkowy(int value){
    int tmp;
    for(int i=31;i>=0;i--){
        tmp= (1<<i);
        if(tmp&value){
            cout<<"1";
        }else
            cout<<"0";
    }
}
void pobierzPracownikow(){
    ifstream input("plik.txt");
    string linia;
    if(input.is_open()){
        while(getline(input,linia)){
            cout<<linia<<endl;
        }
    }
}

int main(int argc, char *argv[])
{
   /* Pracownicy p[2];
    stworzPracownika(p[0],"Adam",33,33,"2016-23-12");
    stworzPracownika(p[1],"Elżbieta",33,33,"2016-23-12");
    wyswietlTabPrac(p);*/
    //dwojkowy(3333333333);
    pobierzPracownikow();
    return 0;
}
