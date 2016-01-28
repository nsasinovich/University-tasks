#ifndef MYEXCEPTION_H_INCLUDED
#define MYEXCEPTION_H_INCLUDED

#include <exception>


class smartPointerException: public std::exception
{
        const char *what() const throw() {return "Error!!!Trying to dereference a null pointer!";}
};

#endif // MYEXCEPTION_H_INCLUDED
