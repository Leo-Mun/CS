#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class NumberGame
{
private :
    vector<int> numbers;

public :
    NumberGame()
    {
        for (int i = 0; i <= 9999; i++)
        {
            num.push_back(i);
        }
    }

    void isCorrect (int num, int strike, int ball)
    {

    }
};
int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0 ; i < testCase; i++)
    {
        int numberOfQuestion;
        inFile >> numberOfQuestion;

        for (int j = 0; j < numberOfQuestion; j++)
        {
            int num, strike, ball;
            inFile >> num >> strike >> ball;



        }
    }






    return 0;
}
