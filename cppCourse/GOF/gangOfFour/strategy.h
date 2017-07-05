#ifndef STRATEGIA_H
#define STRATEGIA_H

#include <iostream>
#include <vector>
using namespace std;


class Strategy{
public:
    Strategy(string myString){
        this->myString=myString;
    }
    string result(){
        return makeAlghoritm();
    }
    virtual ~Strategy(){}
protected:
    string myString;
private:
    virtual string makeAlghoritm()=0;
};

class StrategySeparateColon: public Strategy{
public:
    StrategySeparateColon(string myString): Strategy(myString){
    }
private:
    string pattern;
    string makeAlghoritm(){
        string result = myString;
        for(int i=0; i<myString.length();i++){
            if(result[i]==','){
               result[i]='\n';
            }
        }
        return result;
    }
};

class StrategyBackwords: public Strategy{
public:
    StrategyBackwords(string myString): Strategy(myString){
    }
private:
    string makeAlghoritm(){
        string result = "";
        for(int i=myString.length()-1; i>=0;i--){
            result+=myString[i];
        }
        return result;
    }
};

class StrategySeparate: public Strategy{
public:
    StrategySeparate(string myString): Strategy(myString){
    }
private:
    string makeAlghoritm(){
        string result="";
        for(int i=0; i<myString.length();i++){
            result+=myString[i];
            result+='\n';
        }
        return result;
    }
};

class ContexString{
public:
    ContexString(){
        strategy = NULL;
    }

    enum type{NONE,SEPARATE_COLON,BACKWORDS,SEPARATE};

    void setStrategy(type t, string str){
        switch (t) {
        case SEPARATE_COLON:
            strategy = new StrategySeparateColon(str);
            break;
        case BACKWORDS:
            strategy = new StrategyBackwords(str);
            break;
        case SEPARATE:
            strategy = new StrategySeparate(str);
            break;
        default:
            break;
        }
    }
    void ContextStringInterface(){
        cout<< strategy->result()<<endl;
    }

private:
    Strategy* strategy;
};

#endif // STRATEGIA_H
