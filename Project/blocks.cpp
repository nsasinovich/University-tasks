#include <iostream>
#include <fstream>
#include "blocks.h"

using namespace std;

/////////////////__________CLASS FUNCTIONS__________/////////////////

Layer::Layer(Coords s)
{
    size = s;
    mtr = new int *[size.m];
    for (int i=0 ; i<size.m ; ++i)
        mtr[i] = new int[size.n];
}

Layer::Layer(Coords s, int **array)
{
    size = s;
    mtr = new int *[size.m];
    for (int i=0 ; i<size.m ; ++i)
        mtr[i] = new int[size.n];

    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j )
            mtr[i][j] = array[i][j];
}

Layer::~Layer()
{
    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j )
            mtr[i][j] = 0;
    for(int i=0 ; i<size.m; ++i)
        delete [] mtr[i];
    delete [] mtr;
    size.m = 0;
    size.n = 0;
}

void Layer::input(int number, int **platform) //заполнение слоя: если через клетку проходит столб, то присваиваем 1, иначе - 0
{
    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j)
        {
            if (platform[i][j] >= number)
                mtr[i][j]=1;
            else
                mtr[i][j]=0;
        }

}

void Layer::search(int i, int j)
{
    if(mtr[i][j]==0)
    {
        mtr[i][j]=1;

        if(i-1>=0)
        {
            search(i-1,j);
        }

        if(i+1<size.m)
        {
            search(i+1,j);
        }

        if(j-1>=0)
        {
            search(i,j-1);
        }

        if(j+1<size.n)
        {
            search(i,j+1);
        }
    }
}

int Layer::countZero()
{
    int ch = 0;
    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j)
        {
            if (mtr[i][j] == 0)
                ch+=1;
        }
    return ch;
}

void Layer::put_number(int i, int j, int number)
{
    mtr[i][j]=number;
}

int Layer::get_number(int i, int j)
{
    return mtr[i][j];
}



/////////////////__________OTHER FUNCTIONS__________/////////////////

bool answer()
{
    int ans;
    cout<<"\033[1;36m";
    cout<<"Выберите действие:"<<endl;
    cout<<"1 - Ввести платформу"<<endl;
    cout<<"2 - загрузить платформу из файла"<<endl;
    cin>>ans;
    if(ans==1) return true;
    else return false;
}

void createPlatform(int **platform, Coords s)
{
    int ch;
    for(int i=0; i<s.m; ++i)
    {
        cout<<"\033[0;32m\n";
        cout<<"Введите элементы строки "<<i+1<<":"<<endl;
        for(int j = 0 ; j<s.n ; ++j)
        {
            cout<<"\033[0;32m";
            cin>>ch;
            if (ch>=0)
                platform[i][j] = ch;
            else
            {
                --j;
                cout<<"\033[1;31m\n";
                cout<<"Некорректно введен элемент. Повторите попытку!"<<endl;
            }
        }

    }
}

void readPlatform(Coords size, int **platform)
{
    ifstream fin;
    fin.open("input.txt");
    fin>>size.m;
    fin>>size.n;
    int ch;

    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j)
        {
            if(!(fin.eof()))
            {
                fin>>ch;
                if (ch>=0)
                    platform[i][j]=ch;
                else throw (-1);
            }
            else throw (-1);
        }
    fin.close();
}

void printPlatform(int **platform, Coords s)
{
    for(int i = 0; i<s.m ; ++i)
    {
        for(int j = 0; j<s.n ; ++j)
        {
            cout<<"\033[1;35m";
            cout.width(5);
            cout<<platform[i][j];
        }
        cout<<endl;
    }
}

int findMax(Coords size, int **platform)
{
    int max=0;
    for(int i = 0 ; i<size.m ; ++i)
        for(int j = 0 ; j<size.n ; ++j )
            if (max<platform[i][j])
                max=platform[i][j];
    return max;
}



