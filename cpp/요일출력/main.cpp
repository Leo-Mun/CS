#include <iostream>
#include <fstream>

using namespace std;

bool isLeapYear (int year);

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int year, month, day;
        inFile >> year >> month >> day;

        int stdYear = 1582;
        int sumDays = 0;

        for (; stdYear < year; stdYear++)
        {
            if (isLeapYear(stdYear))
            {
                sumDays += 366;
            }
            else
            {
                sumDays += 365;
            }
        }

        for (int i = 1; i < month; i++)
        {
            if (i == 1)
            {
                sumDays += 31;
            }
            else if (i == 2)
            {
                if (isLeapYear(year))
                {
                    sumDays += 29;
                }
                else
                {
                    sumDays += 28;
                }
            }
            else if (i == 3)
            {
                sumDays += 31;
            }
            else if (i == 5)
            {
                sumDays += 31;
            }
            else if (i == 7)
            {
                sumDays += 31;
            }
            else if (i == 8)
            {
                sumDays += 31;
            }
            else if (i == 10)
            {
                sumDays += 31;
            }
            else if (i == 12)
            {
                sumDays += 31;
            }
            else
            {
                sumDays += 30;
            }

        }

        sumDays += day;
        sumDays -= 1;

        if (sumDays % 7 == 0)
        {
            cout << 5 << endl;
        }
        else if (sumDays % 7 == 1)
        {
            cout << 6 << endl;
        }
        else if (sumDays % 7 == 2)
        {
            cout << 0 << endl;
        }
        else if (sumDays % 7 == 3)
        {
            cout << 1 << endl;
        }
        else if (sumDays % 7 == 4)
        {
            cout << 2 << endl;
        }
        else if (sumDays % 7 == 5)
        {
            cout << 3 << endl;
        }
        else if (sumDays % 7 == 6)
        {
            cout << 4 << endl;
        }


    }

    inFile.close();
    return 0;
}

bool isLeapYear(int year)
{
    if (((year % 4) == 0) && ((year % 100) != 0) || ((year % 400) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
