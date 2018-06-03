#include <iostream>
#include <fstream>

using namespace std;

int hamingWeight(int num);

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while(testCase--)
    {
        unsigned int num1, num2;
        inFile >> num1 >> num2;

        cout << hamingWeight(num1) << " " << hamingWeight(num2) << " " << hamingWeight(num1 ^ num2) << endl;
    }

    inFile.close();
    return 0;
}

int hamingWeight(int num)
{
    int count = 0;
    while(num)
    {
        if (num % 2 == 1)
        {
            count++;
        }
        num /= 2;
    }
    return count;
}

