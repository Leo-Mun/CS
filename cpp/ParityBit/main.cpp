#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        unsigned long num, bitCheck = 0;
        inFile >> num;

        unsigned long parityBitNum = 0, parityBit[32];

        if (num == 0)
        {
            cout << num << endl;
            continue;
        }

        for (int j = 2; num != 0; num /= j )
        {
            if (num % 2 == 0)
            {
                parityBit[bitCheck] = 0;
                bitCheck++;
            }
            else if (num % 2 == 1)
            {
                parityBit[bitCheck] = 1;
                bitCheck++;
            }

        }

        for (; bitCheck < 31; bitCheck++)
        {
            parityBit[bitCheck] = 0;
        }

        int numOfOne = 0;

        for (int i = 0; i < 31; i++)
        {
            if (parityBit[i] == 1)
            {
                numOfOne++;
            }

        }

        if (numOfOne % 2 == 0)
        {
            parityBit[31] = 0;
        }
        else
        {
            parityBit[31] = 1;
        }

        for (int i = 0; i < 32; i++)
        {
            parityBitNum += parityBit[i] * pow(2, i);
        }

        cout << parityBitNum << endl;


    }


    inFile.close();
    return 0;
}
