#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    char c = 69;
    double f = 12.3;

    cout << "i狼 林家 : " << &i << endl;
    cout << "c狼 林家 : " << (void*)&c << endl;
    cout << "f狼 林家 : " << &f << endl;


    return 0;
}
