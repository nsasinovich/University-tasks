#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include <iostream>

using namespace std;

struct NodeAVL
{
    int key;
    unsigned int height;
    NodeAVL* left;
    NodeAVL* right;

    NodeAVL(int k)
    {
        key = k;
        left = right = 0;
        height = 1;
    }
    NodeAVL(const NodeAVL* n)
    {
        key = n->key;
        left = right = 0;
        height = n->height;
    }
};

class AVL_tree
{
public:
    AVL_tree();
    AVL_tree(const AVL_tree&);
    ~AVL_tree();

private:
    NodeAVL *root;

    void insert_el(int k);
    void remove_el(int k);
    bool find_el(int k);

    int height(NodeAVL* p);
    NodeAVL* insertInNode(NodeAVL* p,const int k);
    NodeAVL* balance(NodeAVL* p);
    int bfactor(NodeAVL* p);
    void fixHeight(NodeAVL* p);
    NodeAVL* rotateRight(NodeAVL* p);
    NodeAVL* rotateLeft(NodeAVL* q);
    NodeAVL* cloneTree(NodeAVL*, const NodeAVL*);
    NodeAVL* findMin(NodeAVL* p);
    NodeAVL* removeMin(NodeAVL* p);
    NodeAVL* remove(NodeAVL* p, int k);

    void deleteTree(NodeAVL *p);
    static void addElement(AVL_tree&, const NodeAVL*);
    static void deleteElement(AVL_tree&, NodeAVL*);
    static void findCommonElement(AVL_tree&, AVL_tree&, NodeAVL*);     // н
};

#endif // AVL_TREE_H_INCLUDED
