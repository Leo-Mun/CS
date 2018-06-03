#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int getDistance(int ax, int ay, int bx, int by);

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;


    for (int i = 0; i < testCase; i++)
    {
        int ax, ay, bx, by, cx, cy;
        int AB, BC, CA;

        inFile >> ax >> ay >> bx >> by >> cx >> cy;

        AB = pow((bx - ax), 2) + pow((by - ay), 2);
        BC = pow((cx - bx), 2) + pow((cy - by), 2);
        CA = pow((cx - ax), 2) + pow((cy - ay), 2);

        int sides[3] = {AB, BC, CA};
        sort(sides, sides + 3);


        if ((ay - by) * (bx - cx) == (by - cy) * (ax - bx))
        {
			cout << "0" << endl;
        }
        else
        {
            if (sqrt(sides[2]) < sqrt(sides[0]) + sqrt(sides[1]))
            {
                if (sides[2] == sides[0] + sides[1])
                {
                    cout << "1" << endl;
                }
                else if (sides[2] > sides[0] + sides[1])
                {
                    cout << "2" << endl;
                }
                else if (sides[2] < sides[0] + sides[1])
                {
                    cout << "3" << endl;
                }
            }
            else
            {
                cout << "0" << endl;
            }

        }

    }



    inFile.close();
    return 0;
}
