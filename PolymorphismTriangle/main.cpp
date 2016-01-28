#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
    Triangle **ar = 0;
    int n;

    cout<<"Введите количество треугольников: "<<endl;
    cin>>n;
    ar = new Triangle*[n];
    for(int i = 0; i < n; ++i)
        ar[i] = 0;

    input(ar, n);
    output(ar, n);

    for(int i = 0; i < n; ++i)
        delete ar[i];
    delete [] ar;

    return 0;
}
