#include <iostream>
#include "Figure.h"
#include "SmartPointer.h"
#include <vector>

using namespace std;

int main()
{
    try
    {
        vector<sharedPointer<Figure> > container;
        sharedPointer<Figure> circle(new Circle(3,4,2,"Circle"));
        sharedPointer<Figure> triangle(new Triangle(6,6,9,9,11,7,"Triangle"));
        sharedPointer<Figure> rectangle(new Rectangle(7,5,13,3,"Rectangle"));

        container.push_back(circle);
        container.push_back(triangle);
        container.push_back(rectangle);
        sharedPointer<Figure> testException;
        //testException->getName();
        for(unsigned int i=0; i<container.size(); ++i)
        {
            cout<<container[i]->getName()<<" ";
            if(container[i]->isBelong(0,8,13,0))
                cout<<"belongs"<<endl;
            else cout<<"doesn't belong"<<endl;
        }
    }
    catch(exception &exc)
    {
        cout<<exc.what();
    }

    return 0;
}
