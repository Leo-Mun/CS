#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("input.txt");

    int time;
    inFile >> time;


    for (int i = 0; i < time; i++)
    {
        int total = 1, count, num;
        inFile >> count;

        for (int j = 0; j < count; j++)
        {

            inFile >> num;

            if (num > 10)
            {
                num %= 10;
            }

            total *= num;
            total %= 10;

        }
        cout << total << endl;
    }

    inFile.close();
    return 0;


}
