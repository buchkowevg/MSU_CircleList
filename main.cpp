#include <iostream>
#include "circlelist.h"
using namespace std;

int main()
{
    try
    {
        CircleList<int> list;
        list.insert(3);
        list.print();
        cout << list.searchmax() << endl;
        list.print();
        list.searchmax();
    }
    catch(const runtime_error &ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
