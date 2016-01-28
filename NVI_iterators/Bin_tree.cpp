#include "Bin_tree.h"
#include <cassert>

Bin_tree::Bin_tree():
    Tree(),
    root(0)
{}

Bin_tree::Bin_tree(const Tree *original)
{
    copy(original);
}

Bin_tree::Bin_tree(const Data *ar, int size):
    Tree(),
    root(0)
{
    for(int i = 0; i < size; ++i)
        ((Tree *)this)->add(ar[i]);
}

Bin_tree::~Bin_tree()
{
    clear();
}

Data &Bin_tree::asteriscImpl(void *p) const
{
    if(p)
        return ((Node *)p)->content;
    else
        throw -1;
}

void Bin_tree::nextImpl(void *&p) const
{
    Node *curr = (Node *)p;

    if(curr)
    {
        if(curr->right)
        {
            curr = curr->right;

            while(curr->left)
                curr = curr->left;
        }
        else
        {
            while(curr->parent && curr->branching == Node::rightBranch)
                curr = curr->parent;

            if(!curr->parent)
                curr = 0;
            else
                curr = curr->parent;
        }

        p = (void *)curr;
    }
}


void Bin_tree::previousImpl(void *&p) const
{
    Node *curr = (Node *)p;

    if(curr)
    {
        if(curr->left)
        {
            curr = curr->left;

            while(curr->right)
                curr = curr->right;

            p = (void *)curr;
        }
        else
        {
            while(curr->parent && curr->branching == Node::leftBranch)
                curr = curr->parent;

            if(curr->parent)
                p = (void *)curr->parent;
            else
                assert(0);
        }
    }
    else
    {
        curr = root;

        if(curr)
            while(curr->right)
                curr = curr->right;

        p = (void *)curr;
    }
}

void *Bin_tree::beginImpl() const
{
    Node *curr = root;

    if(curr)
        while(curr->left)
            curr = curr->left;

    return (void *)curr;
}

void Bin_tree::findImpl(const Data &key, void *&p) const
{
    Node *curr = root;

    while(curr && key != curr->content)
        curr = key < curr->content ? curr->left : curr->right;

    p = (void *)curr;
}

void Bin_tree::addImpl(const Data &key, void *&p)
{
    Node *parent = 0, *curr = (Node *)root;
    Node::Branching branching = Node::origin;

    while(curr)
    {
        parent = curr;

        if(key < curr->content)
        {
            branching = Node::leftBranch;
            curr = curr->left;
        }
        else
        {
            branching = Node::rightBranch;
            curr = curr->right;
        }
    }

    curr = new Node(key, parent, branching);

    if(parent)
        (branching == Node::leftBranch ? parent->left : parent->right) = curr;
    else
        root = curr;

    p = (void *)curr;
}

void Bin_tree::removeImpl(void *&p)
{
    if(p)
    {
        Node *curr = (Node *) p;

        if(curr->left && curr->right)
        {
            removeFork(curr);
        }
        else
        {
            nextImpl(p);
            bool rootErasing = root == curr;
            removeInChain(curr);

            if(rootErasing)
                root = curr;
        }
    }
}

void Bin_tree::removeLeaf(Bin_tree::Node *&node)
{
    assert(node);
    assert(!node->left && !node->right);

    if(node->branching == Node::leftBranch)
        node->parent->left = 0;
    else if(node->branching == Node::rightBranch)
        node->parent->right = 0;

    delete node;
    node = 0;
    assert(!node);
}

void Bin_tree::removeInChain(Bin_tree::Node *&node)
{
    assert(node);
    assert(!node->left || !node->right);

    if(!node->left && !node->right)
    {
        removeLeaf(node);
    }
    else
    {
        assert((!node->left && node->right) || (node->left && !node->right));
        Node *&child = node->left ? node->left : node->right;
        Node *&parent = node->parent;
        child->branching = node->branching;
        child->parent = parent;

        if(parent)
        {
            if(node->branching == Node::leftBranch)
                parent->left = child;
            else if(node->branching == Node::rightBranch)
                parent->right = child;
            else
                assert(0);
        }

        assert(child->parent == parent && (parent->left == child || parent->right == child));
        assert((child->branching == Node::leftBranch && parent->left == child) || (child->branching == Node::rightBranch && parent->right == child));
        delete node;
        node = 0;
        assert(!node);
        node = child;
    }
}

void Bin_tree::removeFork(Bin_tree::Node *&node)
{
    assert(node);
    assert(node->left && node->right);
    Node *replacement = node;
    replacement = replacement->right;

    while(replacement->left)
        replacement = replacement->left;

    node->content = replacement->content;
    removeInChain(replacement);
}

void Bin_tree::clear()
{
    clear(root);
}

void Bin_tree::clear(Bin_tree::Node *&node)
{
    if(node)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void Bin_tree::copy(const Tree *original)
{
    copy(root, 0, ((const Bin_tree *)original)->root);
}

void Bin_tree::copy(Bin_tree::Node *&copyNode, Bin_tree::Node *parent, Bin_tree::Node *originalNode)
{
    if(originalNode)
    {
        copyNode = new Node(originalNode->content, parent, originalNode->branching);
        copy(copyNode->left, copyNode, originalNode->left);
        copy(copyNode->right, copyNode, originalNode->right);
    }
}

//------------------------------- Node -------------------------------//

Bin_tree::Node::Node(const Data &key, Bin_tree::Node *parent, Bin_tree::Node::Branching branching):
    content(key),
    parent(parent),
    left(0),
    right(0),
    branching(branching)
{
}

Bin_tree::Node::~Node()
{
    content.~Data();
    parent = 0;
    left = 0;
    right = 0;
    branching = Node::origin;
}
