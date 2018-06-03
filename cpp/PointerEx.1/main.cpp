#include <iostream>

using namespace std;

int main()
{
    int i = 3000;
    int *p = &i;

    cout << &i << endl;
    cout << p << endl;

    cout << i << endl;
    cout << *p << endl;


    return 0;
}
