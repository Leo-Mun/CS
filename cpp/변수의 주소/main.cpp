#include <iostream>

using namespace std;

int main()
{
    int i = 10;
    char c = 69;
    double f = 12.3;

    cout << "i�� �ּ� : " << &i << endl;
    cout << "c�� �ּ� : " << (void*)&c << endl;
    cout << "f�� �ּ� : " << &f << endl;


    return 0;
}
