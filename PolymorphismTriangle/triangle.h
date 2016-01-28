#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include <string>

class Triangle
{
public:
    Triangle();
    Triangle(const std::string &name);
    Triangle(const Triangle &);
    virtual ~Triangle() {};
    virtual double getPerimeter()const=0;
    virtual double getSquare()const=0;
    std::string getName();

private:
    std::string name;
};

//////////////////////////////////////////////////////////////////////


class Equilateral: public Triangle
{
public:
    Equilateral(double length, const std::string &name);
    Equilateral(const Equilateral &);
    ~Equilateral();
    double getPerimeter()const;
    double getSquare()const;

private:
    double length;
};


class Isosceles: public Triangle
{
public:
    Isosceles(double length_1, double length_2, const std::string &name);
    Isosceles(const Isosceles &);
    ~Isosceles();
    double getPerimeter()const;
    double getSquare()const;

private:
    double length_1, length_2;
};


class Arbitary: public Triangle
{
public:
    Arbitary(double length_1, double length_2, double length_3, const std::string &name);
    Arbitary(const Arbitary &);
    ~Arbitary();
    double getPerimeter()const;
    double getSquare()const;

private:
    double length_1, length_2, length_3;
};


class Right: public Triangle
{
public:
    Right(double leg_1, double leg_2, const std::string &name);
    Right(const Right &);
    ~Right();
    double getPerimeter()const;
    double getSquare()const;

private:
    double leg_1, leg_2;
};
////////////////////////////////////////////////////////////////////////////////////////

void input(Triangle **array,int n);
void output(Triangle **array,int n);
double multiply(const Triangle &triangle);

#endif // TRIANGLE_H_INCLUDED
