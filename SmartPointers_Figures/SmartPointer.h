#ifndef sharedPointer_H_INCLUDED
#define sharedPointer_H_INCLUDED

#include "myException.h"
class RefCount
{
private:
    int count;

public:
    void add()
    {
        count++;
    }

    int del()
    {
        return --count;
    }
};

template < typename T > class sharedPointer
{
private:
    T*    pData;
    RefCount* ref;

public:
    sharedPointer() : pData(0)
    {
        ref = new RefCount();
        ref->add();
    }

    sharedPointer(T* pValue) : pData(pValue), ref(0)
    {
        ref = new RefCount();
        ref->add();
    }

    sharedPointer(const sharedPointer<T>& sPointer) : pData(sPointer.pData), ref(sPointer.ref)
    {
        ref->add();
    }

    ~sharedPointer()
    {

        if(ref->del() == 0)
        {
            delete pData;
            delete ref;
        }
    }

//-----------------------------------------------------------

    T& operator* () const
    {
        if(pData==0)
            throw smartPointerException();
        return *pData;
    }

    T* operator-> () const
    {
        if(pData==0)
            throw smartPointerException();
        return pData;
    }

    sharedPointer<T>& operator = (const sharedPointer<T>& sPointer)
    {
        if (this != &sPointer)
        {
            if(ref->del() == 0)
            {
                delete pData;
                delete ref;
            }
            pData = sPointer.pData;
            ref = sPointer.ref;
            ref->add();
        }
        return *this;
    }

    operator bool()
    {
        return pData;
    }

    T* standartPointer()
    {
        return pData;
    }

    operator T*()
    {
        return pData;
    }

    operator const T*()const
    {
        return reinterpret_cast<T*>(pData);
    }
};

//-------------------------------------------------------

#endif // sharedPointer_H_INCLUDED
