#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while (testCase--)
    {
        char isbn[130];
        inFile >> isbn;

        int length = strlen(isbn);

        int country = 0, publish = 0, book = 0;
        int stringCheck  = 0;
        int checkSum = 0;
        int getCheckSum = 10;
        int numCount = 0;
        if (isbn[0] == '-')
        {
            cout << 0 << endl;
            continue;
        }

        for (int i = 0; i < length; i++)
        {
            if (isdigit(isbn[i]))
            {
                if (country < 5)
                {
                    country++;
                    numCount++;
                    checkSum += (isbn[i] - 48) * getCheckSum--;
                }
                else
                {
                    cout << 0 << endl;
                    break;
                }
            }
            else if (isbn[i] == '-')
            {
                stringCheck = ++i;
                break;
            }
            else if (!isdigit(isbn[i]))
            {
                cout << 0 << endl;
                break;
            }
        }
        for (int i = stringCheck; i < length; i++)
        {
            if (isdigit(isbn[i]))
            {
                if (publish < 7)
                {
                    publish++;
                    numCount++;
                    checkSum += (isbn[i] - 48) * getCheckSum--;
                }
                else
                {
                    cout << 0 << endl;
                    break;
                }
            }
            else if (isbn[i-1] != '-' && isbn[i] == '-')
            {
                stringCheck = ++i;
                break;
            }
            else if (!isdigit(isbn[i]))
            {
                cout << 0 << endl;
                break;
            }
        }

        for (int i = stringCheck; i < length; i++)
        {
            if (isdigit(isbn[i]))
            {
                if (book < 6)
                {
                    book++;
                    numCount++;
                    checkSum += (isbn[i] - 48) * getCheckSum--;
                }
                else
                {
                    cout << 0 << endl;
                    break;
                }
            }
            else if (isbn[i-1] != '-' && isbn[i] == '-')
            {
                stringCheck = ++i;
                break;
            }
            else
            {
                cout << 0 << endl;
                break;
            }
        }

        if (numCount > 9)
        {
            cout << 0 << endl;
            continue;
        }

        if (isdigit(isbn[lengt
                    h - 1]) && isdigit(isbn[length - 2]))
        {
            cout << 0 << endl;
            continue;
        }

        int check = 0;
        for (int i = 1; check < checkSum; i++)
        {
            check = i * 11;
        }
        int getResult = 0;
        if (check >= checkSum)
        {
            getResult = check - checkSum;
        }
        else
        {
            check += 11;
            getResult = check - checkSum;
        }

        if (isbn[length - 1] == 'X' && getResult == 10)
        {
            cout << 1 << endl;
        }
        else if ((isbn[length - 1] - 48) == getResult)
        {
            cout << 1 << endl;
        }
        else if ((isbn[length - 1] - 48) != getResult)
        {
            cout << 0 << endl;
        }

    }

    inFile.close();
    return 0;
}
