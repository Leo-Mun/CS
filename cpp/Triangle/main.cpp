#include <iostream>
#include <fstream>
#include <algorithm>
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
        int sideA, sideB, sideC;
        inFile >> sideA >> sideB >> sideC;

        int sides[] = {sideA, sideB, sideC};
        sort(sides, sides + 3);

        if (sides[2] < sides[0] + sides[1])
        {
            if (sides[0] == sides[1] && sides[0] == sides[2] && sides[1] == sides[2])
            {
                cout << "1" << endl;
            }
            else if (pow(sides[2], 2) == pow(sides[0], 2) + pow(sides[1], 2))
            {
                cout << "2" << endl;
            }
            else if (sides[0] == sides[1] || sides[0] == sides[2] || sides[1] == sides[2])
            {
                cout << "3" << endl;
            }
            else
            {
                cout << "4" << endl;
            }
        }
        else
        {
            cout << "0" << endl;
        }




    }








    inFile.close();
    return 0;
}
