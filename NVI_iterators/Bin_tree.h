#ifndef BIN_TREE_H
#define BIN_TREE_H

#include "Tree.h"

class Bin_tree : public Tree
{
    public:
        Bin_tree();
        Bin_tree(const Tree *original);
        Bin_tree(const Bin_tree &original): Tree(original) {}
        Bin_tree(const Data *ar, int size);
        ~Bin_tree();

    private:
        Data &asteriscImpl(void *p) const;
        void nextImpl(void *&p) const;
        void previousImpl(void *&p) const;
        void *beginImpl() const;
        void findImpl(const Data &key, void *&p) const;
        void addImpl(const Data &key, void *&p);
        void removeImpl(void *&p);

        void clear();
        void copy(const Tree *original);

//-----------------Node----------------------//

        struct Node
        {
            Data content;
            Node *parent, *left, *right;
            enum Branching {origin, leftBranch, rightBranch} branching;
            Node(const Data &key, Node *parent, Branching branching);
            ~Node();
        } *root;

        void removeLeaf(Node *&node);
        void removeInChain(Node *&node);
        void removeFork(Node *&node);

        static void clear(Node *&node);
        static void copy(Node *&copyNode, Node *parent, Node *originalNode);
};



#endif //
