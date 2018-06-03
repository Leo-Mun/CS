#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Number {
    int billion, million, thousand, one;
    int number;
    string result;
public:
    Number() {
        result = "";
    }

    void getUnit() {
        billion = number / 1000000000;
		million = (number % 1000000000) / 1000000;
		thousand = (number % 1000000) / 1000;
		one = number % 1000;

		if (billion != 0) {
			result.append("Billion_");
			this->call(billion);
		}
		if (million != 0) {
			result.append("Million_");
			this->call(million);
		}
		if (thousand != 0) {
			result.append("Thousand_");
			this->call(thousand);
		}
		if (one != 0) {
			this->call(one);
		}
    }

    void call (int num) {
            int a = num / 100;
            int b = (num % 100) / 10;
            int c = num % 10;
            int d = num % 100;
            if (a != 0) {
                switch (a)
                {
                case 1:
                    result.append("One_");
                    break;
                case 2:
                    result.append("Two_");
                    break;
                case 3:
                    result.append("Three_");
                    break;
                case 4:
                    result.append("Four_");
                    break;
                case 5:
                    result.append("Five_");
                    break;
                case 6:
                    result.append("Six_");
                    break;
                case 7:
                    result.append("Seven_");
                    break;
                case 8:
                    result.append("Eight_");
                    break;
                case 9:
                    result.append("Nine_");
                    break;
                default:
                    break;
                }
                result.append("Hundred_");
            }
            if (d != 0) {
                if (d <= 19) {
                    switch ( d)
                    {
                    case 1:
                        result.append("One_");
                        break;
                    case 2:
                        result.append("Two_");
                        break;
                    case 3:
                        result.append("Three_");
                        break;
                    case 4:
                        result.append("Four_");
                        break;
                    case 5:
                        result.append("Five_");
                        break;
                    case 6:
                        result.append("Six_");
                        break;
                    case 7:
                        result.append("Seven_");
                        break;
                    case 8:
                        result.append("Eight_");
                        break;
                    case 9:
                        result.append("Nine_");
                        break;
                    case 10:
                        result.append("Ten_");
                        break;
                    case 11:
                        result.append("Eleven_");
                        break;
                    case 12:
                        result.append("Twelve_");
                        break;
                    case 13:
                        result.append("Thirteen_");
                        break;
                    case 14:
                        result.append("Fourteen_");
                        break;
                    case 15:
                        result.append("Fifteen_");
                        break;
                    case 16:
                        result.append("Sixteen_");
                        break;
                    case 17:
                        result.append("Seventeen_");
                        break;
                    case 18:
                        result.append("Eighteen_");
                        break;
                    case 19:
                        result.append("Nineteen_");
                        break;
                    default:
                        break;
                    }
                }
                else {
                    switch (b)
                    {
                    case 2:
                        result.append("Twenty_");
                        break;
                    case 3:
                        result.append("Thirty_");
                        break;
                    case 4:
                        result.append("Forty_");
                        break;
                    case 5:
                        result.append("Fifty_");
                        break;
                    case 6:
                        result.append("Sixty_");
                        break;
                    case 7:
                        result.append("Seventy_");
                        break;
                    case 8:
                        result.append("Eighty_");
                        break;
                    case 9:
                        result.append("Ninety_");
                        break;
                    default:
                        break;
                    }
                    switch (c)
                    {
                    case 1:
                        result.append("One_");
                        break;
                    case 2:
                        result.append("Two_");
                        break;
                    case 3:
                        result.append("Three_");
                        break;
                    case 4:
                        result.append("Four_");
                        break;
                    case 5:
                        result.append("Five_");
                        break;
                    case 6:
                        result.append("Six_");
                        break;
                    case 7:
                        result.append("Seven_");
                        break;
                    case 8:
                        result.append("Eight_");
                        break;
                    case 9:
                        result.append("Nine_");
                        break;
                    default:
                        break;
                    }
                }
            }
    }
    friend fstream& operator>>(fstream & inFile, Number & num) {
		inFile >> num.result;
		return inFile;
	}
	friend ostream& operator<<(ostream & cout, Number & num) {
		for (int i = 0; i < num.result.length() - 1; i++)
			cout << num.result.at(i);
		return cout;
	}
};


int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while(testCase--) {
        Number num;
        inFile >> num;

        num.getUnit();

		cout << num << endl;
    }
    inFile.close();
    return 0;
}
