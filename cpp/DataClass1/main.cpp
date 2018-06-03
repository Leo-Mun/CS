#include <iostream>
#include <fstream>
#include <cstdlib>

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
    int getDayOfMonth() const {
        return this->day;
    }

    int getMonth() const {
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
        if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0)) {
            return 1;
        }
        else {
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
    int getDayOfYear() const
    {
        int result = 0;
        for (int i = 1; i < month; i++) {
            switch (i) {
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
    int getNumHolidays() const {
        int holiday = 0;
        int a = year / 100;
        int b = year % 100;

        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j < 31; j++) {
                int c = i;
                int d = j;
                int jera = ((21 * a / 4) + (5 * b / 4) + (26 * (c + 1) / 10) + d - 1) % 7;

                if ((i == 1 && j == 1) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 2 && (j == 1 || j == 2 || j == 3)) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 3 && j == 1) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 5 && j == 5) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 5 && j == 15) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 6 && j == 6) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 7 && j == 17) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 8 && j == 15) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 9 && (j == 15 || j == 16 || j == 17)) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 10 && j == 3) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if ((i == 12 && j == 25) && (jera != 6 || jera != 0)) {
                    holiday++;
                }

                if (jera == 6 || jera == 0) {
                    holiday++;
                }
                if (isLeapYear() && i == 2 && j == 29) {
                    break;
                }
                else if (!isLeapYear() && i == 2 && j == 28) {
                    break;
                }
                else if ((i == 4 || i == 6 || i == 9 || i == 11) && j == 30) {
                    break;
                }
            }
        }
        return holiday;
    } //휴일수 계산
    int getNumSummerTimeDays()const {

    } //써머타임 날짜수
    void printCalendarOfMonth() const; // 달력출력하기
};


int main(void)
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    inStream >> numTestCases;
    for (int i=0; i<numTestCases; i++)
    {
        int year, month, day;
        inStream >> year >> month >> day;
        myDate date1(year, month, day), date2;
        cout << date1.getYear() << " ";
        cout << date1.getMonth() << " ";
        cout << date1.getDayOfMonth() << endl;
        cout << date1.isLeapYear() << " ";
        cout << date1.getDayOfWeek () << endl;
        inStream >> year >> month >> day;
        date2.setDayOfMonth(day);
        date2.setMonth(month);
        date2.setYear(year);
        cout << date2.getYear() << " ";
        cout << date2.getMonth() << " ";
        cout << date2.getDayOfMonth() << endl;
        cout << date2.isLeapYear() << " ";
        cout << date2.getDayOfWeek () << endl;
        inStream >> year >> month >> day;
        date2.setDate(year, month, day);
        cout << date2.getYear() << " ";
        cout << date2.getMonth() << " ";
        cout << date2.getDayOfMonth() << endl;
        cout << date2.isLeapYear() << " ";
        cout << date2.getDayOfWeek () << endl;
    }
    inStream.close();
    return 0;
}
