#include "triangle.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
}

Triangle::Triangle(const string &name):
    name(name)
{
}

string Triangle::getName()
{
    return name;
}

Triangle::Triangle(const Triangle &original):
    name(original.name)
{
}

///////////////////////////////////////////////////////////////////////////

Equilateral::Equilateral(double l, const string &name):
    Triangle(string("равносторонний ")+name),
    length(l)
{}

Equilateral::Equilateral(const Equilateral &original):
    length(original.length)
{
}

Equilateral::~Equilateral()
{
    length=0;
}

double Equilateral::getSquare()const
{
    return sqrt(3)*pow(length, 2)/4;
}

double Equilateral::getPerimeter()const
{
    return 3*length;
}

/////////////////////////////////////////////////////////////////////////////

Isosceles::Isosceles(double l_1, double l_2, const string &name):
    Triangle(string("равнобедренный ")+name),
    length_1(l_1),
    length_2(l_2)
{}

Isosceles::Isosceles(const Isosceles &original):
    length_1(original.length_1),
    length_2(original.length_2)
{
}

Isosceles::~Isosceles()
{
    length_1=0;
    length_2=0;
}


double Isosceles::getSquare()const
{
    return length_2/4*sqrt(4*pow(length_1, 2)-pow(length_2, 2));
}

double Isosceles::getPerimeter()const
{
    return 2*length_1+length_2;
}

//////////////////////////////////////////////////////////////////////////////

Arbitary::Arbitary(double l_1, double l_2, double l_3, const string &name):
    Triangle(string("произвольный ")+name),
    length_1(l_1),
    length_2(l_2),
    length_3(l_3)
{}

Arbitary::Arbitary(const Arbitary &original):
    length_1(original.length_1),
    length_2(original.length_2),
    length_3(original.length_3)
{
}

Arbitary::~Arbitary()
{
    length_1=0;
    length_2=0;
    length_3=0;
}

double Arbitary::getSquare()const
{
    double p = getPerimeter()/2.0;
    return sqrt(p * (p - length_1) * (p - length_2) * (p - length_3));
}

double Arbitary::getPerimeter()const
{
    return length_1+length_2+length_3;
}
////////////////////////////////////////////////////////////////////////////////

Right::Right(double l_1, double l_2, const string &name):
    Triangle(string("прямоугольный ")+name),
    leg_1(l_1),
    leg_2(l_2)
{}

Right::Right(const Right &original):
    leg_1(original.leg_1),
    leg_2(original.leg_2)
{
}

Right::~Right()
{
    leg_1=0;
    leg_2=0;
}

double Right::getSquare()const
{
    return 0.5*leg_1*leg_2;
}

double Right::getPerimeter()const
{
    return leg_1+leg_2+sqrt(pow(leg_1, 2)+pow(leg_2, 2));
}

//////////////////////////////////////////////////////////////////////////////////

void input(Triangle **array,int n)
{
    for(int i = 0; i < n; ++i)
    {
        int figure;
        cout<<"Выберите треугольник: "<<endl;
        cout<<"1 - равносторонний"<<endl;
        cout<<"2 - равнобедренный"<<endl;
        cout<<"3 - произвольный"<<endl;
        cout<<"4 - прямоугольный"<<endl;
        cin>>figure;

        string name;
        double a, b, c;

        switch(figure)
        {
        case 1:
            cout<<"Введите имя равностороннего треугольника: "<<endl;
            cin>>name;
            cout<<"Введите длину стороны: "<<endl;
            cin>>a;
            array[i] = new Equilateral(a,name);
            break;
        case 2:

            cout<<"Введите имя равнобедренного треугольника: "<<endl;
            cin>>name;
            while(true)
            {
                cout<<"Введите длину боковой стороны: "<<endl;
                cin>>a;
                cout<<"Введите длину основаия: "<<endl;
                cin>>b;
                if((2*a>b) && (a+b>b))
                {
                    array[i] = new Isosceles(a, b, name);
                    break;
                }
                else cout<<"ОШИБКА при вводе сторон! Повторите ввод: "<<endl;
            }
            break;
        case 3:
            cout<<"Введите имя произвольного треугольника: "<<endl;
            cin>>name;
            while(true)
            {
                cout<<"Введите длину первой стороны: "<<endl;
                cin>>a;
                cout<<"Введите длину второй стороны: "<<endl;
                cin>>b;
                cout<<"Введите длину третьей стороны: "<<endl;
                cin>>c;
                if((c+a>b) && (a+b>c) && (b+c>a))
                {
                    array[i] = new Arbitary(a, b, c, name);
                    break;
                }
                else cout<<"ОШИБКА при вводе сторон! Повторите ввод: "<<endl;
            }
            break;
        case 4:
            cout<<"Введите имя прямоугольного треугольника: "<<endl;
            cin>>name;
            cout<<"Введите длину первого катета: "<<endl;
            cin>>a;
            cout<<"Введите длину второго катета: "<<endl;
            cin>>b;
            array[i] = new Right(a, b, name);
            break;
        }
    }
}


void output(Triangle **array,int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout<<"Фигура: "<<i+1<<" - "<<array[i]->getName()<<endl;
        cout<<"Периметр равен "<<array[i]->getPerimeter()<<endl;
        cout<<"Площадь равна "<<array[i]->getSquare()<<endl;
        cout<<"Произведение площади и периметра равно "<<multiply(*array[i])<<endl<<endl;
    }
}

double multiply(const Triangle &triangle)
{
    return triangle.getSquare()*triangle.getPerimeter();
}



