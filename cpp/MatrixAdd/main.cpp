#include <iostream>
#include <fstream>

#define ROW 101
#define COL 101
using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int row, column;
        inFile >> row >> column;

        int mat1[ROW][COL];
        int mat2[ROW][COL];
        int matSum[ROW][COL];


        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                mat1[row][column] = 0;
            }
        }

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                mat2[row][column] = 0;
            }
        }

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                matSum[row][column] = 0;
            }
        }

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                int num;
                inFile >> num;
                mat1[j][k] = num;
            }
        }

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                int num;
                inFile >> num;
                mat2[j][k] = num;
            }
        }



        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < column; k++)
            {
                matSum[j][k] = mat1[j][k] + mat2[j][k];
                cout << matSum[j][k] << " ";
            }
            cout << endl;
        }


    }



    inFile.close();
    return 0;
}
