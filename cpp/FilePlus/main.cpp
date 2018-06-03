#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    int count;
    inFile >> count;

    for (int i = 0; i < count; i++) {
        int time;
        inFile >> time;

        int sum = 0;

        for (int j = 0; j < time; j++) {
            int num;
            inFile >> num;
            sum += num;
        }

        cout << sum << endl;


    }

    inFile.close();
    return 0;
}
