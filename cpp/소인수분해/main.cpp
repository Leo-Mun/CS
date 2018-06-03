#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

bool isPrime(int n);

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int num;
        inFile >> num;

        map<int, int> primeNumber;

        int j = 2;
        while (j < 10000)
        {
            if (isPrime(j) && ((num % j) == 0) || num == 1)
            {
                if (num != 1)
                {
                    if (primeNumber.find(j) == primeNumber.end())
                    {
                        primeNumber[j] = 1;
                        num /= j;
                        continue;
                    }
                    else
                    {
                        primeNumber[j]++;
                        num /= j;
                        continue;
                    }
                }
                else
                {
                    vector<int> pNumber;
                    vector<int> numberOfPNumber;

                    for (map<int, int>::iterator it = primeNumber.begin(); it != primeNumber.end(); it++)
                    {
                        pNumber.push_back(it -> first);
                        numberOfPNumber.push_back(it -> second);
                    }

                    cout << pNumber.size() << " ";

                    for (int k = 0; k < pNumber.size(); k++)
                    {
                        cout << pNumber.at(k) << " " << numberOfPNumber.at(k) << " ";
                    }
                    cout << endl;
                    break;
                }
            }
            else
            {
                j++;
                continue;
            }


        }

    }
    inFile.close();
    return 0;
}

bool isPrime(int n)
{
    int isPrimeCount = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            isPrimeCount++;
        }
    }
    if (isPrimeCount == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
