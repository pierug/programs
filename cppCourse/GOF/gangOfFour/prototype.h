#ifndef TROOPER_H
#define TROOPER_H

#include <iostream>
#define NUM_OF_PROTOTYPES 3

using namespace std;

enum TrooperType{STORM,FOREST , SCOUT};


class Trooper
{
public:
    virtual Trooper* clone()=0;
    virtual void Salute()=0;
    virtual ~Trooper(){}
    TrooperType trooperType;
};


class StormTrooper: public Trooper{
public:
    StormTrooper(){
        trooperType=STORM;
    }

    Trooper* clone(){
        return this;
    }
    void Salute(){
        cout<<"Hail!! Storm Trooper"<<endl;
    }
};

class ForestTrooper: public Trooper{
public:
    ForestTrooper(){
        trooperType=FOREST;
    }
    Trooper* clone(){
        return this;
    }
    void Salute(){
        cout<<"Hail!! Forest Trooper"<<endl;
    }
};

class ScoutTrooper: public Trooper{
public:
    ScoutTrooper(){
        trooperType=SCOUT;
    }
    Trooper* clone(){
        return this;
    }
    void Salute(){
        cout<<"Hail!! Scout Trooper"<<endl;
    }
};
class CloneFactory{
public:
    static Trooper* create(TrooperType);
private:
    static Trooper* prototypes[NUM_OF_PROTOTYPES];
};
Trooper* CloneFactory::prototypes[NUM_OF_PROTOTYPES]={
  new StormTrooper, new ForestTrooper, new ScoutTrooper
};
Trooper* CloneFactory::create(TrooperType trooperType){
    return prototypes[trooperType]->clone();
}

#endif // TROOPER_H
