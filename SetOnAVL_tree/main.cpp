#include <iostream>
#include "AVL_tree.h"

using namespace std;

int main()
{
    AVL_tree tree1, tree2, tree3;

    for (int i =0; i < 10; ++i)
    {
        tree2.insert(3*i);
        tree1.insert(2*i);
    }

    cout<<"Дерево 1:"<<endl<<tree1<<endl<<endl;
    cout<<"Дерево 2:"<<endl<<tree2<<endl<<endl;

    tree1.insert(11);
    cout<<"Вставка элемента в дерево 1:"<<endl;
    cout<<tree1<<endl<<endl;

    cout<<"Есть ли элемент в дереве 2:"<<endl;
    if (tree2.find(9))
        cout<<"Да"<<endl<<endl;
    else
        cout<<"Нет"<<endl<<endl;

    cout<<"Объединение:"<<endl;
    cout<<tree1+tree2<<endl<<endl;

    cout<<"Пересечение (вариант 1):"<<endl;
    cout<<tree1/tree2<<endl<<endl;
    
    cout<<"Пересечение (вариант 2):"<<endl;
    cout<<tree1%tree2<<endl<<endl;

    cout<<"Разность:"<<endl;
    cout<<tree2-tree1<<endl<<endl;
    return 0;
}

