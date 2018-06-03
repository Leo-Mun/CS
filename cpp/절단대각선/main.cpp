#include <iostream>
#include <fstream>

#define MAXN 101

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int mat[MAXN][MAXN];
        int num, max = 0, sum = 0;
        inFile >> num;


        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                int element;
                inFile >> element;
                mat[j][k] = element;
            }
        }

        for (int j = 0; j < num; j++)
        {
            max += mat[j][j];
        }

        int elementCheck = 0, rowCheck = 0, columnCheck = 1, criteria = 1;


        while (criteria != num)
        {
            if (rowCheck == 0)
            {
                columnCheck = criteria;
            }
            sum += mat[rowCheck][columnCheck];
            rowCheck++;
            columnCheck++;
            elementCheck++;
            if(rowCheck == num)
            {
                rowCheck = 0;
            }
            if (columnCheck == num)
            {
                columnCheck = 0;
            }
            if (elementCheck == num)
            {
                elementCheck = 0;
                if (max < sum)
                {
                    max = sum;
                    sum = 0;
                }
                sum = 0;
                rowCheck = 0;
                criteria++;

            }

        }

        sum = 0;

        elementCheck = 0, rowCheck = 0, columnCheck = 0, criteria = 0;


        for (int j = 0; j < num; j++)
        {
            sum += mat[num - 1 - j][j];
        }

        if (max < sum)
        {
            max = sum;
        }

        sum = 0;

        while (criteria != num - 1)
        {
            if (rowCheck == 0)
            {
                columnCheck = criteria;
            }
            sum += mat[rowCheck][columnCheck];
            rowCheck++;
            columnCheck--;
            elementCheck++;
            if(rowCheck == num)
            {
                rowCheck = 0;
            }
            if (columnCheck < 0)
            {
                columnCheck = num - 1;
            }
            if (elementCheck == num)
            {
                elementCheck = 0;
                if (max < sum)
                {
                    max = sum;
                    sum = 0;
                }
                sum = 0;
                rowCheck = 0;
                criteria++;

            }
        }



         cout << max << endl;


    }

    inFile.close();
    return 0;

}
#include <iostream>
#include <fstream>

#define MAXN 101

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int mat[MAXN][MAXN];
        int num, max = 0, sum = 0;
        inFile >> num;


        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                int element;
                inFile >> element;
                mat[j][k] = element;
            }
        }

        for (int j = 0; j < num; j++)
        {
            max += mat[j][j];
        }

        int elementCheck = 0, rowCheck = 0, columnCheck = 1, criteria = 1;


        while (criteria != num)
        {
            if (rowCheck == 0)
            {
                columnCheck = criteria;
            }
            sum += mat[rowCheck][columnCheck];
            rowCheck++;
            columnCheck++;
            elementCheck++;
            if(rowCheck == num)
            {
                rowCheck = 0;
            }
            if (columnCheck == num)
            {
                columnCheck = 0;
            }
            if (elementCheck == num)
            {
                elementCheck = 0;
                if (max < sum)
                {
                    max = sum;
                    sum = 0;
                }
                sum = 0;
                rowCheck = 0;
                criteria++;

            }

        }

        sum = 0;

        elementCheck = 0, rowCheck = 0, columnCheck = 0, criteria = 0;


        for (int j = 0; j < num; j++)
        {
            sum += mat[num - 1 - j][j];
        }

        if (max < sum)
        {
            max = sum;
        }

        sum = 0;

        while (criteria != num - 1)
        {
            if (rowCheck == 0)
            {
                columnCheck = criteria;
            }
            sum += mat[rowCheck][columnCheck];
            rowCheck++;
            columnCheck--;
            elementCheck++;
            if(rowCheck == num)
            {
                rowCheck = 0;
            }
            if (columnCheck < 0)
            {
                columnCheck = num - 1;
            }
            if (elementCheck == num)
            {
                elementCheck = 0;
                if (max < sum)
                {
                    max = sum;
                    sum = 0;
                }
                sum = 0;
                rowCheck = 0;
                criteria++;

            }
        }



         cout << max << endl;


    }

    inFile.close();
    return 0;

}
