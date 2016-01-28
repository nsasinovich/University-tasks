#include "database.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Database::Database():
JewelryStore(NULL), StringNumber(0)
{
}

Database::~Database()
{
    delete JewelryStore;
}


//**************************************************************************


void Database::createDB()
{
    cout<<"Введите количество строк:\n";
    cin>>StringNumber;
    JewelryStore=new Data[StringNumber];
    string new_name;
    int new_sum;
    short int new_number;

    for(int i=0; i<StringNumber; ++i)
    {
        cout<<"Введите данные(фамилия, сумма покупок, количество покупок) клиента "<<i+1<<":"<<endl;
        cin>>new_name;
        cin>>new_sum;
        cin>>new_number;
        JewelryStore[i].setName(new_name);
        JewelryStore[i].setSum(new_sum);
        JewelryStore[i].setNumber(new_number);
    }
}

void Database::readDB()
{
    ifstream fin;
    fin.open("file.txt");
    fin>>StringNumber;
    JewelryStore=new Data[StringNumber];
    string new_name;
    int new_sum;
    short int new_number;

    for (int i=0; i<StringNumber; ++i)
    {
        fin>>new_name;
        fin>>new_sum;
        fin>>new_number;
        JewelryStore[i].setName(new_name);
        JewelryStore[i].setSum(new_sum);
        JewelryStore[i].setNumber(new_number);
    }
    fin.close();
}

void Database::printDB()
{
    cout<<'|';
    for(int i=0; i<38; ++i)
        cout<<"-";
    cout<<'|';
    cout<<endl<<"|";
    cout.width(20);
    cout<<"surname";
    cout<<"|";
    cout.width(10);
    cout<<"sum";
    cout<<"|";
    cout.width(6);
    cout<<"number";
    cout<<"|"<<endl<<"|";
    for(int i=0; i<32; ++i)
        if(i==20||i==31) cout<<"+";
        else cout<<"-";
    cout<<"------|"<<endl;

    for(int st=0; st<StringNumber; ++st)
    {
        cout<<"|";
        cout.width(20);
        cout<<JewelryStore[st].getName();
        cout<<"|";
        cout.width(10);
        cout<<JewelryStore[st].getSum();
        cout<<"|";
        cout.width(6);
        cout<<JewelryStore[st].getNumber();
        cout<<"|"<<endl<<"|";
        for(int i=0; i<32; ++i)
            if(i==20||i==31) cout<<"+";
            else cout<<"-";
        cout<<"------|"<<endl;
    }
}

void Database::saveDB()
{
    ofstream fout;
    fout.open("saved.txt");
    for (int i=0; i<StringNumber; ++i)
    {
        fout<<JewelryStore[i].getName();
        fout<<JewelryStore[i].getSum();
        fout<<JewelryStore[i].getNumber();
    }
    fout.close();
}


void Database::doSort(int l, int r, bool (*cmp)(Data, Data, int), int order)
{
    if (l < r)
    {
        doSort(l, (r + l) / 2, cmp, order);
        doSort((r + l) / 2 + 1, r, cmp, order);
        // create first half copy
        int size_br = (r + l) / 2 - l + 1;
        Data *br = new Data[size_br];
        for (int i = 0; i < size_br; ++i)
        {
            br[i] = JewelryStore[l + i];
        }
        // create second half copy
        int size_cr = r - ((r + l) / 2 + 1) + 1;
        Data *cr = new Data[size_cr];
        for (int i = 0; i < size_cr; ++i)
        {
            cr[i] = JewelryStore[(r + l) / 2 + 1 + i];
        }
        // fill base array from copies and sort data
        int m = l;
        int j = 0;
        int k = 0;
        while ((j < size_br) && (k < size_cr))
        {
            if (cmp(br[j],cr[k],order))
            {
                JewelryStore[m] = br[j];
                ++j;
            }
            else
            {
                JewelryStore[m] = cr[k];
                ++k;
            }
            ++m;
        }
        for (; j < size_br; ++j, ++m)
        {
            JewelryStore[m] = br[j];
        }
        for (; k < size_cr; ++k, ++m)
        {
            JewelryStore[m] = cr[k];
        }

        delete [] br;
        delete [] cr;
    }
}

//**************************************************************************


int Database::getStringNumber()
{
    return StringNumber;
}
