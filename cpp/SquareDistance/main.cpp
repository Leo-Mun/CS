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

    for(int i = 0; i < testCase; i++)
    {
        int x1, y1, x2, y2;
        inFile >> x1 >> y1 >> x2 >> y2;

        int x, y;
        inFile >> x >> y;

        if ((x1 <= x && x <= x2) && (y1 <= y && y <= y2))
        {
            cout << "0" << " " << "0" << endl;
        }
        else
        {
            if (x1 <= x && x <= x2)
            {
                if (y < y1)
                {
                    cout << pow((y1 - y), 2) << " " << y1 - y << endl;
                }
                else if (y > y2)
                {
                    cout << pow((y - y2), 2) << " " << y - y2 << endl;
                }
            }

            else if (y1 <= y && y <= y2)
            {
                if (x1 > x)
                {
                    cout << pow((x1 - x), 2) << " " << x1 - x << endl;
                }
                else if (x > x2)
                {
                    cout << pow((x - x2), 2) << " " << x - x2 << endl;
                }
            }
            else if (x < x1 && y < y1)
            {
                cout << pow((x1 - x), 2) + pow((y1 - y), 2) << " " << abs(x1 - x) + abs(y1 - y) << endl;
            }
            else if (x < x1 && y > y2)
            {
                cout << pow((x1 - x), 2) + pow((y - y2), 2) << " " << abs(x1 - x) + abs(y - y2) << endl;
            }
            else if (x > x2 && y < y1)
            {
                cout << pow((x2 - x), 2) + pow((y1 - y), 2) << " " << abs(x2 - x) + abs(y1 - y) << endl;
            }
            else if (x > x2 && y > y2)
            {
                cout << pow((x2 - x), 2) + pow((y2 - y), 2) << " " << abs(x2 - x) + abs(y2 - y) << endl;
            }
        }
    }


    inFile.close();
    return 0;
}
