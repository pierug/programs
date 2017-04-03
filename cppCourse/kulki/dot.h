#ifndef DOT_H
#define DOT_H
#include <QPoint>
#include <QColor>
#include <iostream>
#include <vector>

using namespace std;

class Dot
{
private:
    QPoint point;
    QColor color;
    int size;
    int speedX;
    int speedY;

public:
    Dot(int x, int y, int size, QColor color);
    QPoint getPoint() const;
    void setPoint(const QPoint &value);
    int getSize() const;
    QColor getColor() const;
    int getSpeedX() const;
    void setSpeedX(int value);
    int getSpeedY() const;
    void setSpeedY(int value);

    virtual void update(int width,int height, vector<Dot> dotList);

    virtual ~Dot(){}
};

#endif // DOT_H
