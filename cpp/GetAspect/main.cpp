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
        int n, pos[300], direct;
        int posSum1 = 0, posSum2 = 0, sum = 0;
        inFile >> n;
        for (int j = 0; j < (n * 2); j++)
        {
            inFile >> pos[j];
        }
        pos[n * 2] = pos[0];
        pos[(n * 2) + 1] = pos[1];

        for (int k = 0; k < (n * 2); k += 2)
        {
            posSum1 += (pos[k] * pos[k+3]);
        }
        for (int l = (n * 2); l > 0; l -= 2)
        {
            posSum2 += (pos[l] * pos[l-1]);
        }
        sum = posSum1 - posSum2;

        if (sum < 0)
        {
            direct = -1;
            cout << -sum << " " << direct << endl;
        }
        else if (sum > 0)
        {
            direct = 1;
            cout << sum << " " << direct << endl;
        }
    }


    inFile.close();
    return 0;
}
