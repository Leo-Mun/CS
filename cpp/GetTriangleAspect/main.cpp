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
        int ax, ay, bx, by, cx, cy;
        int aspect, directCheck;
        inFile >> ax >> ay >> bx >> by >> cx >> cy;

        aspect = ((ax * by) + (bx * cy) + (cx * ay)) - ((bx * ay) + (cx * by) + (ax * cy));


        if (aspect == 0)
        {
            directCheck = 0;
            cout << aspect << " " << directCheck << endl;
        }
        else if (aspect < 0)
        {
            directCheck = -1;
            cout << - aspect << " " << directCheck << endl;
        }
        else if (aspect > 0)
        {
            directCheck = 1;
            cout << aspect << " " << directCheck << endl;
        }

    }


    inFile.close();
    return 0;
}
