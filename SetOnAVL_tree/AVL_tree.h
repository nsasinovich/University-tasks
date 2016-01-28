#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

#include <iostream>

using namespace std;

struct Node // структура для представления узлов дерева
{
    int key;
    unsigned int height;
    Node* left;
    Node* right;

    Node(int k)
    {
        key = k;
        left = right = 0;
        height = 1;
    }
    Node(const Node* n)
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
    void insert(int k); //вставка ключа
    void remove(int k); //удаление ключа
    bool find(int k) const; //есть ли ключ в дереве
    friend ostream& operator << (ostream&, const AVL_tree&);

    AVL_tree operator+ (const AVL_tree& a) const;
    AVL_tree operator- (const AVL_tree& a) const;
    AVL_tree operator/ (const AVL_tree& a) const;  // пересечение (вариант 1)
    AVL_tree operator% (const AVL_tree& a) const;  // пересечение (вариант 2)
    
private:
    Node *root;

    int height(Node* p);     // поиск высоты узла
    Node* insertInNode(Node* p,const int k);     // рекурсивная функция вставки
    Node* balance(Node* p);     // балансировка узла p
    int bfactor(Node* p);     // разница между высотой правого и левого поддеревьев
    void fixHeight(Node* p);     // установление новой высоты для узла
    Node* rotateRight(Node* p);     // поворот вправо
    Node* rotateLeft(Node* q);     // поворот влево
    Node* cloneTree(Node*, const Node*);     // рекурсивная функция копирования дерева
    Node* findMin(Node* p);     // поиск узла с минимальным ключом
    Node* removeMin(Node* p);     // удаление узла с минимальным ключом в дереве
    Node* remove(Node* p, int k);     // удаление ключа к
    void deleteTree(Node *p);     // рекурсивное удаление дерева
    static void show(ostream&, Node*);     // вывод дерева
    static void addElement(AVL_tree&, const Node*);     // добавление элементов в дерево объединения
    static void deleteElement(AVL_tree&, Node*);     // удаление ненужных эленентов из дерева разности
    static void findCommonElement(AVL_tree&, const AVL_tree&, Node*);     // нахождение общих элементов и занесение их в дерево пересечения
};


#endif // AVL_TREE_H_INCLUDED
