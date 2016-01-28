#include <iostream>
#include "Tree.h"
#include "Bin_tree.h"

using namespace std;

int main()
{
    Tree *tree1;
    Bin_tree tree2;
    tree1 = &tree2;
    tree1->add(23);
    tree1->add(3);
    tree1->add(-2);
    tree1->add(12);
    tree1->add(6);
    tree1->add(5);
    TreeIt begin=tree1->begin();
    TreeIt end=tree1->end();
    while(begin!=end)
    {
        cout<<*begin<<" ";
        ++begin;
    }

    return 0;
}
