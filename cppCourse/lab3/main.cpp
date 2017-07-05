#include <iostream>
#include <math.h>

using namespace std;

class Punkt{
private:
    int X;
    int Y;
public:
    Punkt(int x,int y){
        X=x;
        Y=y;
    }

    Punkt(){
        X=0;
        Y=0;
    }
    int getX(){
        return X;
    }
    int getY(){
        return Y;
    }
    inline void wektor(){
        cout<<"["<<X<<","<<Y<<"]"<<endl;
    }

    inline void odl(){
        cout<<"odl: "<<sqrt(X*X+Y*Y)<<endl;
    }

    void odlPP(Punkt &p){
        cout<<"odlPP: "<<sqrt(pow(p.getX()-this->X,2)+pow(p.getY()-this->Y,2))<<endl;
    }
};

int main(int argc, char *argv[])
{
    Punkt p1(4,3);
    Punkt *p2 = new Punkt(14,13);
    Punkt p3;
    p1.wektor();
    p2->wektor();
    p2->odlPP(p1);
    return 0;
}
