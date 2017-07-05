#ifndef PROXY_H
#define PROXY_H
#include <iostream>

using namespace std;

class Person{
private:
    string name;
public:

    void setName(const string& n){
        name=n;
    }

    string getName() const{
        return name;
    }

};

class Programmer: public Person{
public:
    static string list[];
    static int index;
    Programmer(){
        setName(list[index++]);
    }
};

string Programmer::list[]={"Walu","Wojtas","Spejson","Łysa"};
int Programmer::index = 0;


class Salesman: public Person{
public:
    static string list[];
    static int index;
    Salesman(){
        setName(list[index++]);
    }
};

string Salesman::list[]={"Marta","Zbychu","Drogba","Andzelo"};
int Salesman::index = 0;

class BankAccount{
private:
    int accountSum;
public:
    BankAccount(){
        accountSum=1800;
    }
    bool withdraw(int amount){
        if(amount>accountSum)
            return false;
        accountSum-=amount;
        return true;
    }
    int getAccountSum()const{
        return accountSum;
    }
};

class Payment{
private:
    BankAccount bankaccount;
public:
    bool withdraw(Programmer& programmer, int amount){
        if(programmer.getName()=="Walu" || programmer.getName()=="Wojtas" || programmer.getName()=="Spejson"){
            return bankaccount.withdraw(amount);
        }
        return false;
    }
    bool withdraw(Salesman& salesman, int amount){
        if(salesman.getName()=="Marta" || salesman.getName()=="Drogba" || salesman.getName()=="Andzelo"){
                    return bankaccount.withdraw(amount);
                }
                return false;
    }
    int getAccountSum(){
        return bankaccount.getAccountSum();
    }
};

#endif // PROXY_H


