#include <iostream>

using namespace std;

int sizeOfArray(int arr[]);

int main()
{
    int arr[4];

    cout << sizeof(arr) << endl;
    cout << sizeOfArray(arr);

    return 0;
}

int sizeOfArray (int * arr)
{
    int size;
    size = sizeof(arr) / sizeof(* arr);

    return size;

}
