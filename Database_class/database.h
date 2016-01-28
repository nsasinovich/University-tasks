#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include "data.h"

using namespace std;

class Database
{
public:

    Database();
    ~Database();

    void createDB();
    void readDB();
    void printDB();
    void saveDB();
    void doSort(int l, int r, bool (*cmp)(Data, Data, int), int order);

    int getStringNumber();

private:
    Data *JewelryStore;
    int StringNumber;
};

#endif // DATABASE_H_INCLUDED
