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

    while(testCase--) {
        string time;
		int n;

		inFile >> time >> n;

		int hour = 0;
		int minute = 0;

		for (int i = 0; i < 2; i++) {
			hour *= 10;
			hour += time[i] - '0';
		}

		for (int i = 3;i < 5;i++) {
			minute *= 10;
			minute += time[i] - '0';
		}

		hour %= 12;
		if (time[5] == 'P') {
			hour += 12;
		}

		int h, m;

		h = (n / 60) % 24;
		m = n % 60;
		minute += m;
		hour += h;
		while (minute >= 60) {
			minute -= 60;
			hour++;
		}
		while (minute < 0) {
			hour--;
			minute += 60;
		}
		while (hour < 0) {
			hour += 24;
		}

		while(hour >= 24) {
			hour -= 24;
		}

		if (hour < 12) {
			if (hour == 0) {
				hour = 12;
			}

			if (hour < 10) {
				cout << 0;
			}

			cout << hour << ":";

			if (minute < 10) {
				cout << 0;
			}

			cout << minute << "AM" << endl;
		}

		else {
			hour -= 12;
			if (hour == 0) {
				hour = 12;
			}
			if (hour < 10) {
				cout << 0;
			}

			cout << hour << ":";
			if (minute < 10) {
				cout << 0;
			}
			cout << minute << "PM" << endl;
		}
    }

    inFile.close();
    return 0;
}
