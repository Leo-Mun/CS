#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int getSetElement1, getSetElement2;
        inFile >> getSetElement1;

        unsigned int set1[132] = {0, };
        unsigned int set2[132] = {0, };

        unsigned int bitSet1[132] = {0, };
        unsigned int bitSet2[132] = {0, };
        unsigned int tmpSet2[132] = {0, };

        unsigned int bitAnd[132] = {0, };
        unsigned int bitOr[132] = {0, };
        unsigned int bitNor[132] = {0, };

        for (int j = 0; j < getSetElement1; j++)
        {
            unsigned int num;
            inFile >> num;

            for (int k = 0; k < 132; k++)
            {
                if (k != num)
                {
                    continue;
                }
                else
                {
                    set1[k] = num;
                    break;
                }
            }
        }

        inFile >> getSetElement2;

        for (int k = 0; k < getSetElement2; k++)
        {
            unsigned int num;
            inFile >> num;

            for (int j = 0; j < 132; j++)
            {
                if (j != num)
                {
                    continue;
                }
                else
                {
                    set2[j] = num;
                    break;
                }
            }
        }


        for (int j = 0; j < 132; j++)
        {
            if (j == set1[j])
            {
                bitSet1[j] = 1;
            }
        }

        for (int j = 0; j < 132; j++)
        {
            if (j == set2[j])
            {
                bitSet2[j] = 1;
                tmpSet2[j] = 1;
            }
        }

        for (int i = 0; i < 132; i++)
        {
            if (tmpSet2[i] == 1)
            {
                tmpSet2[i] = 0;
            }
            else
            {
                tmpSet2[i] = 1;
            }
        }


        for (int i = 0; i < 132; i++)
        {
            if ((bitSet1[i] & bitSet2[i]) == 1)
            {
                bitAnd[i] = i;
            }
            if ((bitSet1[i] | bitSet2[i]) == 1)
            {
                bitOr[i] = i;
            }
            if ((bitSet1[i] & tmpSet2[i]) == 1)
            {
                bitNor[i] = i;
            }
        }

        int andNum = 0, orNum = 0, norNum = 0;
        for (int i = 0; i < 132; i++)
        {
            if (bitAnd[i] != 0)
            {
                ++andNum;
            }
            if (bitOr[i] != 0)
            {
                ++orNum;
            }
            if (bitNor[i] != 0)
            {
                ++norNum;
            }
        }


        cout << andNum << " " ;
        for (int i = 0; i < sizeof(bitAnd) / sizeof(unsigned int); i++)
        {
            if (bitAnd[i] != 0)
            {
                cout << bitAnd[i] << " ";
            }
        }

        cout << endl;

        cout << orNum << " " ;
        for (int i = 0; i < sizeof(bitOr) / sizeof(unsigned int); i++)
        {
            if (bitOr[i] != 0)
            {
                cout << bitOr[i] << " ";
            }
        }

        cout << endl;

        cout << norNum << " " ;
        for (int i = 0; i < sizeof(bitNor) / sizeof(unsigned int); i++)
        {
            if (bitNor[i] != 0)
            {
                cout << bitNor[i] << " ";
            }

        }

        cout << endl;




    }




    inFile.close();
    return 0;
}
