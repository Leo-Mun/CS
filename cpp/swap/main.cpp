#include <iostream>

using namespace std;

void swap(int *x, int *y);

int main()
{

     int a = 100, b = 200;
     cout << "before : " << a << " " << b << endl;
     swap(&a, &b);
     cout << "After : " << a << " " << b << endl;




    return 0;
}

//void swap (int x, int y) // call-by-value
//{
//    int tmp;
//
//    cout << "in swap() : " << x << " " << y << endl;
//
//    tmp = x, x = y, y = tmp;
//
//    cout << "in swap() : " << x << " " << y << endl;
//}

void swap (int * x, int * y)
{
    int tmp;

    cout << "in swap() : " << *x << " " << *y << endl;

    tmp = *x, *x = *y, *y = tmp;

    cout << "in swap() : " << *x << " " << *y << endl;
}
