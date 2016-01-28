#include "Tree.h"

//-------------------------------- Tree ------------------------------//

Tree::Tree(const Tree &original)
{
    copy(&original);
}

Tree::~Tree()
{
    clear();
}

Tree::Iterator Tree::find(const Data &key) const
{
    void *p = 0;
    findImpl(key, p);
    return Iterator(this, p);
}

Tree::Iterator Tree::add(const Data &key)
{
    void *p = 0;
    addImpl(key, p);
    return Iterator(this, p);
}

Tree::Iterator Tree::remove(const Iterator &position)
{
    if(this != position.own)
        throw -1;

    void *p = position.curr;
    removeImpl(p);
    return TreeIt(this, p);
}

int Tree::remove(const Data &key)
{
    int counter = 0;
    void *p = 0;
    findImpl(key, p);

    while(p)
    {
        ++counter;
        removeImpl(p);
        findImpl(key, p);
    }

    return counter;
}

Tree::Iterator Tree::begin() const
{
    return Iterator(this, beginImpl());
}

Tree::Iterator Tree::end() const
{
    return Iterator(this, 0);
}

Data &Tree::asterisc(void *p) const
{
    return asteriscImpl(p);
}

void Tree::next(void *&p) const
{
    nextImpl(p);
}

void Tree::previous(void *&p) const
{
    previousImpl(p);
}
//----------------- TreeIt ------------------//

TreeIt::TreeIt():
    own(0),
    curr(0)
{}

TreeIt::~TreeIt()
{
    own = 0;
    curr = 0;
}

Data &TreeIt::operator*() const
{
    if(own)
        return own->asterisc(curr);
    else
        throw -1;
}

TreeIt TreeIt::operator++()
{
    if(own)
        own->next(curr);

    return *this;
}

TreeIt TreeIt::operator++(int)
{
    TreeIt result(*this);
    ++(*this);
    return result;
}

TreeIt TreeIt::operator--()
{
    if(own)
        own->previous(curr);

    return *this;
}

TreeIt TreeIt::operator--(int)
{
    TreeIt result(*this);
    --(*this);
    return result;
}

bool TreeIt::operator==(const TreeIt &other) const
{
    return own == other.own && curr == other.curr;
}

TreeIt::TreeIt(const Tree *own, void *curr):
    own(own),
    curr(curr)
{}


