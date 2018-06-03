#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int num;
        int numOfDivisor = 0, sum = 0;
        inFile >> num;

        for (int divisor = 1; divisor <= sqrt(num); divisor++)
        {
            if ((num % divisor) == 0 )
            {
                numOfDivisor++;
                sum += divisor;
                if (((num / divisor) != num) && (num / divisor) != divisor)
                {
                    sum += (num / divisor);
                    numOfDivisor++;
                }
            }
        }

        cout << numOfDivisor << " " << sum << endl;


    }

    inFile.close();
    return 0;

}
