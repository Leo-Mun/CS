#include <iostream>
#include <fstream>
#include <ctype.h>
#include <cstring>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        char stringInput[501];
        inFile >> stringInput;

        double alphabetFrequency[26] = { 8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

        char capitalLetter[26];
        char smallLetter[26];

        for (int j = 0; j < 26; j++)
        {
            capitalLetter[j] = (65 + j);
            smallLetter[j] = (97 + j);
        }

        int LetterFrequency[26] = {0, };

        int length = strlen(stringInput);

        for (int j = 0; j < length; j++)
        {
            if (isalpha(stringInput[j]))
            {
                if (isupper(stringInput[j]))
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == capitalLetter[k])
                        {
                            LetterFrequency[k]++;
                            break;
                        }

                    }
                }
                else
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == smallLetter[k])
                        {
                            LetterFrequency[k]++;
                            break;
                        }

                    }
                }
            }
            else
            {
                continue;
            }
        }

        double LetterFrequency2[26] = {0, };

        for (int j = 0; j < 26; j++)
        {
            LetterFrequency2[j] = (double) LetterFrequency[j] / length;
        }

        int key;
        double min = 0;
        for (int j = 0; j < 26; j++ )
        {
            double temporary = 0;
            for (int k = 0; k < 26; k++)
            {
                int check = k + j;
                if (check > 25)
                {
                    check -= 26;
                }
                temporary += (LetterFrequency2[check] * LetterFrequency2[check]) / alphabetFrequency[k];
            }
            if (j == 0)
            {
                min = temporary;
                key = j;
                continue;
            }
            if (min > temporary)
            {
                min = temporary;
                key = j;
            }
        }

        for (int j = 0; j < length; j++)
        {
            if (isalpha(stringInput[j]))
            {
                if (isupper(stringInput[j]))
                {

                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == capitalLetter[k])
                        {
                            int check = k;
                            check -= key;
                            if (check < 0)
                            {
                                check += 26;
                            }
                            cout << capitalLetter[check];
                            break;
                        }
                    }
                }
                else
                {
                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == smallLetter[k])
                        {
                            int check = k;
                            check -= key;
                            if (check < 0)
                            {
                                check += 26;
                            }
                            cout << smallLetter[check];
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << stringInput[j];
            }
        }
        cout << endl;



    }
    inFile.close();
    return 0;
}
