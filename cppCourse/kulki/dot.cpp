#include "dot.h"
#include <iostream>
#include <vector>

using namespace std;

QColor Dot::getColor() const
{
    return color;
}

QPoint Dot::getPoint() const
{
    return point;
}

void Dot::setPoint(const QPoint &value)
{
    point = value;
}

int Dot::getSize() const
{
    return size;
}

int Dot::getSpeedX() const
{
    return speedX;
}

void Dot::setSpeedX(int value)
{
    speedX = value;
}

int Dot::getSpeedY() const
{
    return speedY;
}

void Dot::setSpeedY(int value)
{
    speedY = value;
}

void Dot::update(int width,int height, vector<Dot> dotList)
{
    this->point.setX(this->point.x()+speedX);
    this->point.setY(this->point.y()+speedY);
}

Dot::Dot(int x, int y, int size, QColor color)
{
    this->point.setX(x);
    this->point.setY(y);
    this->size = size;
    this->color = color;
}
