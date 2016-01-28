#include "data.h"
#include <iostream>
#include <string.h>

using namespace std;

Data::Data():
name(), sum(0), number(0)
{
}

Data::Data(string new_name,int new_sum, short int new_number):
name(new_name), sum(new_sum), number(new_number)
{
}

Data::~Data()
{
}

//**************************************************************************


Data Data::operator = (const Data & other)
{
    if (this != &other)
    {
        name=other.name;
        sum=other.sum;
        number=other.number;
    };

    return *this;
}

string Data::getName()
{
    return name;
}

int Data::getSum()
{
    return sum;
}

short int Data::getNumber()
{
    return number;
}

string Data::setName(string new_name)
{
    return name=new_name;
}

int Data::setSum(int new_sum)
{
    return sum=new_sum;
}

short int Data::setNumber(short int new_number)
{
    return number=new_number;
}


//**************************************************************************


bool Data::cmpName(Data line1, Data line2, int order)
{
    if (order*strcmp(line1.name.c_str(), line2.name.c_str())<0)
        return true;
    else return false;
}

bool Data::cmpSum(Data line1, Data line2, int order)
{
    if (order*(line1.sum-line2.sum)<0)
        return true;
    else return false;
}

bool Data::cmpNumber(Data line1, Data line2, int order)
{
    if (order*(line1.number-line2.number)<0)
        return true;
    else return false;
}
