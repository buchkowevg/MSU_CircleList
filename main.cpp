#include <iostream>
#include "circlelist.h"
using namespace std;

int main()
{
    try
    {
        CircleList<int> list;
        list.insert(0);
        list.insert(4);
        list.insert(100);
        list.insert(5);        
        list.print();
        list.rotateRight();
        list.print();
        list.rotateLeft(2);
        list.print();
    }
    catch(const runtime_error &ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
