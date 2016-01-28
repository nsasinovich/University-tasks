#ifndef BLOCKS_H_INCLUDED
#define BLOCKS_H_INCLUDED
#include <iostream>

struct Coords
{
    int m;
    int n;
};

class Layer
{
public:
    Layer(Coords s);
    Layer(Coords s, int**array);
    ~Layer();
    void input(int number, int **platform);
    void search(int i, int j);
    int countZero();

    void put_number(int i, int j, int number);
    int get_number(int i,int j);

private:
    int **mtr;
    Coords size;
};

bool answer();
void createPlatform(int **platform, Coords s);
void readPlatform(Coords size, int **platform);
void printPlatform(int **platform, Coords s);
int findMax(Coords size, int **platform);


#endif // BLOCKS_H_INCLUDED
