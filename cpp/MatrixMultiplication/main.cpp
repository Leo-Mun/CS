#include <iostream>
#include <fstream>

using namespace std;

#define ROW 101
#define COL 101

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int r, s, t;
        inFile >> r >> s >> t;

        int mat1[ROW][COL];
        int mat2[ROW][COL];
        int matSum[ROW][COL];


        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < s; k++)
            {
                mat1[j][k] = 0;
            }
        }

        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < t; k++)
            {
                mat2[j][k] = 0;
            }
        }

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < t; k++)
            {
                matSum[j][k] = 0;
            }
        }

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < s; k++)
            {
                int num;
                inFile >> num;
                mat1[j][k] = num;
            }
        }

        for (int j = 0; j < s; j++)
        {
            for (int k = 0; k < t; k++)
            {
                int num;
                inFile >> num;
                mat2[j][k] = num;
            }
        }

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < t; k++)
            {
                for (int l = 0; l < s; l++)
                {
                    matSum[j][k] += mat1[j][l] * mat2[l][k];
                }
            }
        }

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < t; k++)
            {
                cout << matSum[j][k] << " ";
            }
            cout << endl;
        }





    }

    inFile.close();
    return 0;
}
