#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    int testCase;
    fstream inFile;
    inFile.open("input.txt");
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int k;
        inFile >> k;

        string graph[k][k];

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                graph[i][j] = '.';
            }
        }

        for (int i = 0; i < k; i++)
        {
            graph[i][k / 2] = 'I';
            graph[k / 2][i] = '+';
        }


        for (int i = 0; i < k; i++)
        {
            graph[k - 1 - i][i] = '*';
        }

        graph[k / 2][k / 2] = 'O';




        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cout << graph[i][j];
            }
            cout << endl;
        }

    }



    inFile.close();
    return 0;
}
