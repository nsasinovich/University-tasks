#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#include <iostream>
#include <string>


class Figure
{
public:
    Figure();
    Figure(const std::string &figureName);
    Figure(const Figure&);
    virtual ~Figure() {};

    virtual bool isBelong(int X1, int Y1, int X2, int Y2) const = 0;
    std::string getName();

private:
    std::string figureName;

};

//----------------------------------------------------------

class Circle: public Figure
{
public:
    Circle(int x, int y, int r, const std::string &figureName);
    Circle(const Circle&);
    ~Circle();

    bool isBelong(int X1, int Y1, int X2, int Y2) const;

private:
    int x, y, r;
};

class Triangle: public Figure
{
public:
    Triangle(int x1, int y1,int x2, int y2, int x3, int y3, const std::string &figureName);
    Triangle(const Triangle&);
    ~Triangle();

    bool isBelong(int X1, int Y1, int X2, int Y2) const;

private:
    int x1, y1, x2, y2, x3, y3;
};

class Rectangle: public Figure
{
public:
    Rectangle(int x1, int y1,int x2, int y2, const std::string &figureName);
    Rectangle(const Rectangle&);
    ~Rectangle();

    bool isBelong(int X1, int Y1, int X2, int Y2) const;

private:
    int x1, y1, x2, y2;
};

#endif // FIGURE_H_INCLUDED
