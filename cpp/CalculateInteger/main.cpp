#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

   int count;
   inFile >> count;

   for (int i = 0; i < count; i++) {
        int a, b;
        inFile >> a >> b;
        cout << a + b << " " << a - b << " ";

        if ((a - b) < 0) {
            cout << -(a - b) << " ";
        } else {
            cout << (a - b) << " ";
        }

        cout << a * b << " " << a / b << " " << a % b << " ";

        if (a > b) {
            cout << a << " ";
        } else {
            cout << b << " ";
        }
        if (a == b) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

   }

    inFile.close();
   return 0;
}
