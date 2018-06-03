#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int time;
    inFile >> time;

    for (int i = 0; i < time; i++)
    {
        int height;
        inFile >> height;

        for (int j = 1; j <= height; j++)
        {
            cout << j << " ";

            int difference = height - 1;
            int num = j + difference;

            for (int k = 1; k < j; k++)
            {
                cout << num << " ";

                num += --difference;
            }
            cout << "\n";

        }


    }

    inFile.close();
    return 0;

}
