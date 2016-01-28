#include "Figure.h"
#include <iostream>
#include <cstring>
using namespace std;

Figure::Figure()
{
}

Figure::Figure(const string &figureName):
    figureName(figureName)
{
}

string Figure::getName()
{
    return figureName;
}

Figure::Figure(const Figure &original):
    figureName(original.figureName)
{
}

//------------------------------------------------------

Circle::Circle(int x, int y, int r, const string &figureName):
    Figure(figureName), x(x), y(y), r(r)
{
}

Circle::Circle(const Circle &original):
    x(original.x), y(original.y), r(original.r)
{
}

Circle::~Circle()
{
    x = 0;
    y = 0;
    r = 0;
}

bool Circle::isBelong(int X1, int Y1, int X2, int Y2) const
{
    if ((x+r)>=X1 && (x+r)<=X2 && y>=Y2 && y<=Y1 &&
        x>=X1 && x<=X2 && (y+r)>=Y2 && (y+r)<=Y1 &&
        (x-r)>=X1 && (x-r)<=X2 && (y-r)<=Y1 && (y-r)>=Y2)
        return true;
    else return false;
}
//-------------------------------------------------------

Triangle::Triangle(int x1, int y1,int x2, int y2, int x3, int y3, const string &figureName):
    Figure(figureName), x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3)
{
}

Triangle::Triangle(const Triangle &original):
    x1(original.x1), y1(original.y1),
    x2(original.x2), y2(original.y2),
    x3(original.x3), y3(original.y3)
{
}

Triangle::~Triangle()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
}

bool Triangle::isBelong(int X1, int Y1, int X2, int Y2) const
{
    if (x1<=X1 && x1>=X2 && y1<=Y1 && y1>=Y2 &&
        x2<=X1 && x2>=X2 && y2<=Y1 && y2>=Y2 &&
        x3<=X1 && x3>=X2 && y3<=Y1 && y3>=Y2)
        return true;
    else return false;
}

//-----------------------------------------------------------

Rectangle::Rectangle(int x1, int y1,int x2, int y2, const string &figureName):
    Figure(figureName), x1(x1), y1(y1), x2(x2), y2(y2)
{
}

Rectangle::Rectangle(const Rectangle &original):
    x1(original.x1), y1(original.y1),
    x2(original.x2), y2(original.y2)
{
}

Rectangle::~Rectangle()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

bool Rectangle::isBelong(int X1, int Y1, int X2, int Y2) const
{
    if (x1<=X1 && x1>=X2 && y1<=Y1 && y1>=Y2 &&
        x2<=X1 && x2>=X2 && y2<=Y1 && y2>=Y2)
        return true;
    else return false;
}
