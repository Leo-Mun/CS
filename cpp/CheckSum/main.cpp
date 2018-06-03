#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while (testCase--)
    {
        unsigned int integer;
        inFile >> integer;

        unsigned int checkSum = 0;
        unsigned int bitMask = 0xFF;
        unsigned int realData = 0;

        checkSum = integer & bitMask;

        for (int i = 0; i < 3; i++)
        {
            integer >>= 8;
            realData += integer & bitMask;
        }

        realData %= 256;

        int checkSumCheck;
        checkSumCheck = 255 - realData;

        if (checkSum == checkSumCheck)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }



    }


    inFile.close();
    return 0;
}
