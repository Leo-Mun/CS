#include <iostream>
#include <fstream>
using namespace std;

class myDate
{
private:
    int year, month, day;
public:
// Constructor (생성자)
    myDate(int year=1582, int month=1, int day=1)
    {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }
// Accessor functions (접근자)
    int getDayOfMonth() const
    {
        return this->day;
    }

    int getMonth() const
    {
        return this -> month;
    }

    int getYear() const
    {
        return this -> year;
    }
// Mutator functions (변경자)
    void setDayOfMonth(int day)
    {
        this -> day = day;
    }

    void setMonth(int month)
    {
        this -> month = month;
    }

    void setYear(int year)
    {
        this -> year = year;
    }

    void setDate(int year, int month, int day)
    {
        this -> year = year;
        this -> month = month;
        this -> day = day;
    }
// utility functions
    bool isLeapYear() const
    {
        if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
    {

        int year = this->year;
        int month = this->month;
        if (month <= 2)
        {
            year -= 1;
            month += 12;
        }

        int a = year / 100;
        int b = year % 100;
        int c = month;
        int d = day;

        return ((21 * a / 4) + (5 * b / 4) + (26 * (c + 1) / 10) + d - 1) % 7;
    }

    int getDayOfWeek(int month, int day) const
    {
        int y = this->year;
        int m = month;
        if (m <= 2)
        {
            y -= 1;
            m += 12;
        }

        int a = year / 100;
        int b = year % 100;
        int c = m;
        int d = day;

        return ((21 * a / 4) + (5 * b / 4) + (26 * (c + 1) / 10) + d - 1) % 7;
    }

    int getDayOfYear() const
    {
        int result = 0;
        for (int i = 1; i < month; i++)
        {
            switch (i)
            {
            case 1 :
                result += 31;
                break;
            case 2:
                if (isLeapYear())
                    result += 29;
                else
                    result += 28;
                break;
            case 3:
                result +=31;
                break;
            case 4:
                result += 30;
                break;
            case 5:
                result += 31;
                break;
            case 6:
                result += 30;
                break;
            case 7:
                result +=31;
                break;
            case 8 :
                result += 31;
                break;
            case 9:
                result += 30;
                break;
            case 10:
                result += 31;
                break;
            case 11:
                result += 30;
                break;
            }

        }
        result += this->day;

        return result;
    } //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
    int getNumHolidays() const
    {
        int holiday = 0;

        int holidayMonth[] = {1, 3, 5, 6, 7, 8, 10, 12, 2, 2, 2, 5, 9, 9, 9};
        int holidayDay[] = {1, 1, 5, 6, 17, 15, 3, 25, 1, 2, 3, 15, 15, 16, 17};

        myDate tmp(year, 1, 1);
        int days = 365;
        if (isLeapYear())
            days += 1;

        int start = tmp.getDayOfWeek();
        days += start;

        for (; start < days; start++)
        {
            if(start % 7 == 0 || start % 7 == 6)
                holiday++;
        }

        for (int i = 0; i < 15; i++)
        {
            tmp.setDate(year, holidayMonth[i], holidayDay[i]);
            if (tmp.getDayOfWeek() != 6 && tmp.getDayOfWeek() != 0)
                holiday++;
        }
        return holiday;
    } //휴일수 계산
    int getNumSummerTimeDays() const
    {
        myDate tmp(year, 3, 31);

        int lastSunday = tmp.getDayOfWeek();
        tmp.setDayOfMonth(31 - lastSunday);
        int begin = tmp.getDayOfYear();

        tmp.setDate(year, 10, 31);

        lastSunday = tmp.getDayOfWeek();
        tmp.setDayOfMonth(31 - lastSunday);
        int end = tmp.getDayOfYear();

        return end - begin;
    } //써머타임 날짜수
    void printCalendarOfMonth() const
    {
        myDate tmp(year, month, 1);
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        int firstDay = tmp.getDayOfWeek();
        int lastDay = days[month - 1];
        if (month == 2 && isLeapYear())
            lastDay += 1;

        cout << year << " " << month << endl;

        int number = 1;

        for (int i = 0;; i++)
        {
            if (firstDay <= i)
            {
                if (number <= lastDay)
                    cout << number++ << " ";
                else
                    cout << "0 ";
                if (i % 7 == 6)
                {
                    cout << endl;

                    if (number > lastDay)
                        break;
                }
            }
            else
                cout << "0 ";
        }



    } // 달력출력하기
};

int main(void)
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    inStream >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        int year, month, day;
        inStream >> year >> month >> day;
        myDate date(year, month, day);
        cout << date.getNumSummerTimeDays() << endl;
        date.printCalendarOfMonth();
    }
    inStream.close();
    return 0;
}
