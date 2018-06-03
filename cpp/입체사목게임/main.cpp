#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while(testCase--) {
        int cheap;
        inFile >> cheap;

        for (int i = 0; i < cheap; i++) {

        }
    }

    inFile.close();
    return 0;
}
