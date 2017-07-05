#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
using namespace std;

class DrawImplementator{
public:
    virtual void drawCircle(const double x,const double y,const double rad)=0;
    virtual ~DrawImplementator(){}
};

class Drawing1: public DrawImplementator{
public:
    void drawCircle(const double x,const double y,const double rad){
        printf("Drawing1 x=%f, y=%f, rad=%f \n",x,y,rad);
    }
};

class Drawing2: public DrawImplementator{
public:
    void drawCircle(const double x,const double y,const double rad){
        printf("Drawing2 x=%f, y=%f, rad=%f \n",x,y,rad);
    }
};

class Shape
{
public:
    virtual void draw()=0;
    virtual void resizeByPrecentage(const double pct)=0;
    virtual ~Shape(){
        delete drawImplementator;
    }

protected:
    DrawImplementator* drawImplementator;
    Shape(DrawImplementator* draw){
        drawImplementator = draw;
    }

};

class CircleShape :public Shape {
private:
    double x,y,rad;
public:
    CircleShape(const double x,const double y,const double rad,DrawImplementator* draw):Shape(draw){
        this->x=x;
        this->y=y;
        this->rad=rad;
    }
    void draw(){
        drawImplementator->drawCircle(x,y,rad);
    }
    void resizeByPrecentage(const double pct){
        this->rad*=(1*pct/100);
    }


};

#endif // BRIDGE_H
