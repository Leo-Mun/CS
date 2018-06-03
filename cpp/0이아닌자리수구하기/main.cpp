#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int func(int num);

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int numberOfNumber;
        inFile >> numberOfNumber;

        unsigned int lastNumber = 1;
        int numberOfTwo = 0, numberOfFive = 0;

        for (int j = 0; j < numberOfNumber; j++)
        {
            int num;
            inFile >> num;

            while (num % 2 == 0)
            {
				numberOfTwo++;
				num /= 2;
			}
			while (num % 5 == 0)
            {
				numberOfFive++;
				num /= 5;
			}

			num %= 10;
			lastNumber *= num;
			lastNumber %= 10;

        }

       if (numberOfFive == numberOfTwo)
       {
			cout << lastNumber << " " << numberOfFive;
       }
		else if (numberOfFive >= numberOfTwo)
        {
			cout << (lastNumber * 5) % 10 << " " << numberOfTwo;
        }
		else
        {
			cout << (lastNumber * func(numberOfTwo - numberOfFive)) % 10 << " " << numberOfFive;
        }
		cout << endl;



    }



    inFile.close();
    return 0;
}

int func(int num)
{
    num %= 4;
    switch (num)
    {
    case 0 :
        return 6;
    case 1 :
        return 2;
    case 2 :
        return 4;
    case 3 :
        return 8;
    }
}
