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
        int numOfStudents;
        inFile >> numOfStudents;

        int scores[101];

        for (int i = 0; i < 101; i++)
        {
            scores[i] = 0;
        }

        for (int j = 0; j < numOfStudents; j++)
        {
            int score;
            inFile >> score;

            scores[score]++;
        }

        for (int k = 0; k < 101; k++)
        {
            if (scores[k] > 0)
            {
                cout << k << " " << scores[k] << " ";
                continue;
            }
        }

        cout << endl;
    }

    inFile.close();
    return 0;
}
