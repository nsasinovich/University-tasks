#include <iostream>
#include <fstream>
#include "blocks.h"

using namespace std;

int main()
{
    Coords s;
    int **platform = NULL;

    bool action1=answer();
    if(action1)
    {
        cout<<"\033[1;32m\n";
        cout<<"Введите размеры платформы: "<<endl;
        cin>>s.m;
        cin>>s.n;

        platform = new int *[s.m];
        for (int i=0 ; i<s.m ; ++i)
            platform[i] = new int[s.n];
        createPlatform(platform, s);
    }

    else
    {
        ifstream fin;
        fin.open("input.txt");
        fin>>s.m;
        fin>>s.n;
        fin.close();

        platform = new int *[s.m];
        for (int i=0 ; i<s.m ; ++i)
            platform[i] = new int[s.n];
        readPlatform(s, platform);
    }

    printPlatform(platform, s);
    cout<<endl;

    int max = findMax(s, platform);// находим высоту наивысшего столба
    int value = 0;
    Layer l(s);
    int zeroes;
    cout<<"\033[1;30m";
    cout<<"Формируем срезы(слои) единичной высоты. Считаем единицы\nобъема на каждом из них:\n"<<endl;
    for(int number = max ; number > 0 ; --number)
    {
        zeroes = 0;
        l.input(number, platform);

        for(int i=0; i<s.n; ++i) //поиск по каждой из границ
            if(l.get_number(0,i)==0)
                l.search(0,i);

        for(int i=0; i<s.n; ++i)
            if(l.get_number(s.m-1, i)==0)
                l.search(s.m-1,i);

        for(int i=0; i<s.m; ++i)
            if(l.get_number(i, 0)==0)
                l.search(i,0);

        for(int i=0; i<s.m; ++i)
            if(l.get_number(i, s.n-1)==0)
                l.search(i, s.n-1);
        zeroes = l.countZero(); //подсчет нулей на слое
        cout<<"\033[0;37m";
        cout<<"> "<<zeroes<<" единиц объема воды на слое "<<number<<endl;
        cout<<endl;
        value+=zeroes; //cуммируем единицы объема на каждом слое

    }
    cout<<"\033[0;35m";
    cout<<"> > > ОБЩИЙ ОБЪЕМ ВОДЫ РАВЕН "<<value<<"!";

    for(int i=0 ; i<s.m; ++i) //очистка памяти
        delete [] platform[i];
    delete [] platform;

    for(int i = 0 ; i<s.m ; ++i)
        for(int j = 0 ; j<s.n ; ++j )
            platform[i][j] = 0;

    s.m = 0;
    s.n = 0;
}


