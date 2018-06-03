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
        int numberOfnum;
        int numbers[256];
        inFile >> numberOfnum;

        for (int j = 0; j < numberOfnum; j++)
        {
            int num;
            inFile >> num;
            numbers[j] = num;
        }

        int frequency;
        inFile >> frequency;

        cout << (numberOfnum - frequency + 1) << " ";

        int check = 0;
        int sum = 0;
        for (int j = 0; j < (numberOfnum - frequency + 1); j++)
        {
            for (int k = 0; k < frequency; k++)
            {
                sum += numbers[k + check];
            }
            check++;
            cout << sum / frequency << " ";
            sum = 0;
        }
        cout << endl;

    }
    inFile.close();
    return 0;
}
