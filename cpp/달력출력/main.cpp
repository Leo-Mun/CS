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

    for (int k = 0; k < testCase; k++)
    {
        int year, month;
        int day = 1;
        inFile >> year >> month;

        int stdYear = 1582;
        int sumDays = 0;

        for (; stdYear < year; stdYear++) // 년도 계산
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

        for (int i = 1; i < month; i++) // 달수 계산
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




        int space, nextLineCheck = 0; // 공간 계산

        if (sumDays % 7 == 0)
        {
            space = 5;
        }
        else if (sumDays % 7 == 1)
        {
            space = 6;
        }
        else if (sumDays % 7 == 2)
        {
            space = 0;
        }
        else if (sumDays % 7 == 3)
        {
            space = 1;
        }
        else if (sumDays % 7 == 4)
        {
            space = 2;
        }
        else if (sumDays % 7 == 5)
        {
            space = 3;
        }
        else if (sumDays % 7 == 6)
        {
            space = 4;
        }


        int lastDay;
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
        {
            lastDay = 31;
        }
        else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
        {
            lastDay = 30;
        }
        else if ((month == 2))
        {
            if(isLeapYear(year))
            {
                lastDay = 29;
            }
            else
            {
                lastDay = 28;
            }
        }

        cout << year << " " << month << endl;

        for (int i = 0; i < space; i++) // 첫 날 까지 공
        {
            cout << 0 << " ";
            nextLineCheck++;
        }

        for (; day <= lastDay; day++) // 날짜 채우기
        {
            cout << day << " ";
            nextLineCheck++;
            if (nextLineCheck == 7)
            {
                nextLineCheck = 0;
                cout << endl;
            }
        }

        space = nextLineCheck;

        if (space > 0) // 나머지 공간
        {
            for (int j = 0; j < 7 - nextLineCheck; j++)
            {
                cout << 0 << " ";

            }
            if (k != testCase - 1)
            {
                cout << endl;
            }
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
