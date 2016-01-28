#include "AVL_tree.h"

using namespace std;

AVL_tree::AVL_tree()
{
    root = 0;
}

AVL_tree::AVL_tree(const AVL_tree& a)
{
    root = cloneTree(root, a.root);
}

AVL_tree::~AVL_tree()
{
    AVL_tree::deleteTree(root);
    root = 0;
}


//---------------------------------------------------------------------------------------------

void AVL_tree::insert_el(int k)
{
    root = insertInNode(root, k);
}

void AVL_tree::remove_el(int k)
{
    root = remove(root, k);
}

bool AVL_tree::find_el(int k)
{
    NodeAVL *p = root;
    while(p)
    {
        if (p->key > k )
            p = p->left;
        else if (p->key < k)
            p = p->right;
        else
            return true;
    }
    return false;
}

NodeAVL* AVL_tree::cloneTree(NodeAVL* a, const NodeAVL* b)
{
    if (!b)
        return 0;
    a = new NodeAVL(b);
    a->left = cloneTree(a->left, b->left);
    a->right = cloneTree(a->right, b->right);
    return a;
}

NodeAVL* AVL_tree::insertInNode(NodeAVL* p,const int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new NodeAVL(k);
    if( k<p->key )
        p->left = insertInNode(p->left,k);
    else if(k > p->key)
        p->right = insertInNode(p->right,k);
    else return p;
    return balance(p);
}

NodeAVL* AVL_tree::remove(NodeAVL* p, int k) // удаление ключа k из дерева p
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);
    else //  k == p->key
    {
        NodeAVL* q = p->left;
        NodeAVL* r = p->right;
        delete p;
        if( !r ) return q;
        NodeAVL* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}


NodeAVL* AVL_tree::findMin(NodeAVL* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findMin(p->left):p;
}

NodeAVL* AVL_tree::removeMin(NodeAVL* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 )
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

NodeAVL* AVL_tree::balance(NodeAVL* p) // балансировка узла p
{
    fixHeight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateRight(p->right);
        return rotateLeft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateLeft(p->left);
        return rotateRight(p);
    }
    return p; // балансировка не нужна
}

int AVL_tree::bfactor(NodeAVL* p)
{
    return height(p->right)-height(p->left);
}

NodeAVL* AVL_tree::rotateRight(NodeAVL* p) // правый поворот вокруг p
{
    NodeAVL* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

NodeAVL* AVL_tree::rotateLeft(NodeAVL* q) // левый поворот вокруг q
{
    NodeAVL* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

void AVL_tree::fixHeight(NodeAVL* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

int AVL_tree::height(NodeAVL* p)
{
    return p?p->height:0;
}

void AVL_tree::deleteTree(NodeAVL *p)
{
    if (!p) return;
    deleteTree(p->left);
    deleteTree(p->right);
    delete p;
}


void AVL_tree::addElement(AVL_tree& tree, const NodeAVL *p)
{
    if(!p) return;
    tree.insert_el(p->key);
    addElement(tree, p->right);
    addElement(tree, p->left);
}

void AVL_tree:: deleteElement(AVL_tree& tree, NodeAVL* p)
{
    if(!p) return;
    tree.remove_el(p->key);
    deleteElement(tree, p->left);
    deleteElement(tree, p->right);
}

void AVL_tree::findCommonElement(AVL_tree& res, AVL_tree& b, NodeAVL *p)
{
    if(!p) return;
    if(b.find_el(p->key)) res.insert_el(p->key);
    findCommonElement(res, b, p->left);
    findCommonElement(res, b, p->right);
}

