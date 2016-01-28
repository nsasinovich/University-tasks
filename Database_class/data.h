#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Data
{
public:
    Data();
    Data(string new_name,int new_sum, short int new_number);
    ~Data();

    static bool cmpName(Data line1, Data line2, int order);  // посмотреть, что передавать
    static bool cmpSum(Data line1, Data line2, int order);
    static bool cmpNumber(Data line1, Data line2, int order);

    Data operator=(const Data&);

    string getName();
    int getSum();
    short int getNumber();
    string setName(string new_name);
    int setSum(int new_sum);
    short int setNumber(short int new_number);

private:
    string name;
    int sum;
    short int number;
};


#endif // DATA_H_INCLUDED
