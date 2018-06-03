#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while (testCase--) {
        string number;
        inFile >> number;

        int sum = 0;
        int check;
        int checkSum = (int)number.at(number.length() - 1) - 48;

        for (int i = number.length() - 1; i >= 0; i--) {
            if (number.length() % 2 == 0) {
                    if (i % 2 == 0) {
                        int num = ((int) number.at(i) - 48) * 2;
                        if (num >= 10) {
                            num -= 9;
                        }
                        sum += num;
                    }
                    else {
                        int num = (int) number.at(i) - 48;
                        sum += num;
                    }
            }
            else {
                        if (i % 2 == 1) {
                        int num = ((int) number.at(i) - 48) * 2;
                        if (num >= 10) {
                            num -= 9;
                        }
                        sum += num;
                    }
                    else {
                        int num = (int) number.at(i) - 48;
                        sum += num;
                    }
            }
        }
        check = 10 - (sum % 10);
        if (sum % 10 == 0) {
            check = 0;
        }
        int result;

        if (checkSum == check) {
            if (number.at(0) - 48 == 3 && (number.length() == 15 || number.length() == 14))
            {
                result = 1;
            }
            else if (number.at(0) - 48 == 6 && number.length() == 16) {
                result = 1;
            }
            else if (number.at(0) - 48 == 5 && number.length() == 16) {
                result = 1;
            }
            else if (number.at(0) - 48 == 4 && (number.length() == 13 || number.length() == 16)) {
                result = 1;
            }
            else {
                result = 0;
            }
        }
        else {
            result = 0;
        }

        cout << result << endl;

    }
    inFile.close();
    return 0;
}
