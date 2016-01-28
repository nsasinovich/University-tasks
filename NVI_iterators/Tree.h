#ifndef TREE_H
#define TREE_H


typedef int Data;

class TreeIt;

class Tree
{
    public:
        friend class TreeIt;
        typedef TreeIt Iterator;

        Tree() {}
        Tree(const Tree &original);
        ~Tree();

        Iterator find(const Data &key)const;
        Iterator add(const Data &key);
        Iterator remove(const Iterator &position);
        int remove(const Data &key);

        Iterator begin() const;
        Iterator end() const;

    private:
        Data &asterisc(void *p) const;
        void next(void *&p) const;
        void previous(void *&p) const;

        virtual Data &asteriscImpl(void *p) const = 0;
        virtual void nextImpl(void *&p) const = 0;
        virtual void previousImpl(void *&p) const = 0;
        virtual void *beginImpl() const = 0;
        virtual void findImpl(const Data &key, void *&p) const = 0;
        virtual void addImpl(const Data &key, void *&p) = 0;
        virtual void removeImpl(void *&p) = 0;

        virtual void clear() {}
        virtual void copy(const Tree *) {}
};

//---------------Iterator---------------//
class TreeIt
{
    public:
        friend class Tree;
        TreeIt();
        ~TreeIt();

        Data &operator*() const;
        TreeIt operator++();
        TreeIt operator++(int);
        TreeIt operator--();
        TreeIt operator--(int);
        bool operator==(const TreeIt &other) const;
        bool operator!=(const TreeIt &other) const {return !(*this == other);}
    private:
        const Tree *own;
        void *curr;

        TreeIt(const Tree *own, void *curr);
};



#endif // TREE_H
