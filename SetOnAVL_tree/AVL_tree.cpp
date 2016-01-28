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

void AVL_tree::insert(int k)
{
    root = insertInNode(root, k);
}

void AVL_tree::remove(int k)
{
    root = remove(root, k);
}

bool AVL_tree::find(int k)  const
{
    Node *p = root;
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

ostream &operator << (ostream& out, const AVL_tree& tree)
{
    AVL_tree::show(out, tree.root);
    return out;
}

AVL_tree AVL_tree:: operator+ (const AVL_tree& a) const
{
    AVL_tree result(*this);
    addElement(result, a.root);
    return result;
}

AVL_tree AVL_tree:: operator- (const AVL_tree& a) const
{
    AVL_tree result(*this);
    deleteElement(result, a.root);
    return result;
}

AVL_tree AVL_tree:: operator/ (const AVL_tree& a) const
{
    AVL_tree result;
    findCommonElement(result, a, root);
    return result;
}

AVL_tree AVL_tree:: operator% (const AVL_tree& a) const
{
    AVL_tree result(*this-(*this-a));
    return result;
} // ПЕРЕСЕЧЕНИЕ вариант 2

//---------------------------------------------------------------------------------------------

Node* AVL_tree::cloneTree(Node* a, const Node* b)
{
    if (!b)
    return 0;
    a = new Node(b);
    a->left = cloneTree(a->left, b->left);
    a->right = cloneTree(a->right, b->right);
    return a;
}

Node* AVL_tree::insertInNode(Node* p,const int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new Node(k);
    if( k<p->key )
        p->left = insertInNode(p->left,k);
    else if(k > p->key)
        p->right = insertInNode(p->right,k);
        else return p;
    return balance(p);
}

Node* AVL_tree::remove(Node* p, int k) // удаление ключа k из дерева p
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);
    else //  k == p->key
    {
        Node* q = p->left;
        Node* r = p->right;
        delete p;
        if( !r ) return q;
        Node* min = findMin(r);
        min->right = removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

Node* AVL_tree::findMin(Node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findMin(p->left):p;
}

Node* AVL_tree::removeMin(Node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 )
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}

Node* AVL_tree::balance(Node* p) // балансировка узла p
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

int AVL_tree::bfactor(Node* p)
{
    return height(p->right)-height(p->left);
}

Node* AVL_tree::rotateRight(Node* p) // правый поворот вокруг p
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

Node* AVL_tree::rotateLeft(Node* q) // левый поворот вокруг q
{
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

void AVL_tree::fixHeight(Node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

int AVL_tree::height(Node* p)
{
    return p?p->height:0;
}

void AVL_tree::deleteTree(Node *p)
{
    if (!p) return;
    deleteTree(p->left);
    deleteTree(p->right);
    delete p;
}

void AVL_tree::show(ostream& out, Node *p)
{
    if (!p) return;
    show(out, p->left);
    out << p->key << "(" << p->height << ")" << " "; // в скобках указывается высота данного элемента
    show(out, p->right);
}

void AVL_tree::addElement(AVL_tree& tree, const Node *p)
{
    if(!p) return;
    tree.insert(p->key);
    addElement(tree, p->right);
    addElement(tree, p->left);
}

void AVL_tree:: deleteElement(AVL_tree& tree, Node* p)
{
    if(!p) return;
    tree.remove(p->key);
    deleteElement(tree, p->left);
    deleteElement(tree, p->right);
}

void AVL_tree::findCommonElement(AVL_tree& res, const AVL_tree& b, Node *p)
{
    if(!p) return;
    if(b.find(p->key)) res.insert(p->key);
    findCommonElement(res, b, p->left);
    findCommonElement(res, b, p->right);
}
