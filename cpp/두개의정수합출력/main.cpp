#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int num1, num2;
        inFile >> num1 >> num2;

        int sum = 0;

        for (; num1 <= num2; num1++)
        {
            sum += num1;
        }

        cout << sum << endl;


    }


    inFile.close();
    return 0;
}
