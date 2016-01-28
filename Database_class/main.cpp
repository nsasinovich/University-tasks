#include <iostream>
#include "data.h"
#include "database.h"

using namespace std;

bool answer();

int main()
{
    bool action1=answer();
    Database JStore;

    if(action1)
    {
        JStore.createDB();
    }
    else
    {
        JStore.readDB();
    }

    int action2;
    do
    {
        cout<<"Выберите действие:"<<endl;
        cout<<"1 - печать"<<endl;
        cout<<"2 - сортировка"<<endl;
        cout<<"3 - сохранить"<<endl;
        cout<<"0 - выход из программы"<<endl;
        cin>>action2;

        switch(action2)
        {

        case 1:
            JStore.printDB();
            break;

        case 2:
        {
            int option;
            cout<<"1 - по фамилии"<<endl;
            cout<<"2 - по сумме покупок"<<endl;
            cout<<"3 - по количеству покупок"<<endl;
            cin>>option;

            int order;
            cout<<"1 - по возрастанию"<<endl;
            cout<<"-1 - по убыванию"<<endl;
            cin>>order;
            int strNum = JStore.getStringNumber();

            switch(option)
            {
            case 1:
                JStore.doSort(0, strNum-1, Data::cmpName, order);
                break;
            case 2:
                JStore.doSort(0, strNum-1, Data::cmpSum, order);
                break;
            case 3:
                JStore.doSort(0, strNum-1, Data::cmpNumber, order);
                break;
            }
        }
        break;

        case 3:
            JStore.saveDB();
            break;

        case 0:
            break;
        }
    }
    while(action2);


    return 0;
}



//***************************************************

bool answer()
{
    int ans;
    cout<<"Выберите действие:"<<endl;
    cout<<"1 - создать БД"<<endl;
    cout<<"2 - загрузить БД из файла"<<endl;
    cin>>ans;
    if(ans==1) return true;
    else return false;
}
