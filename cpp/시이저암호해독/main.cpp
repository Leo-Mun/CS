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
        int encode;
        inFile >> encode;
        char capitalLetter[26];
        char smallLetter[26];

        for (int j = 0; j < 26; j++)
        {
            capitalLetter[j] = (65 + j);
            smallLetter[j] = (97 + j);
        }

        char stringInput[101];
        inFile >> stringInput;

        int length = strlen(stringInput);

        for (int j = 0; j < length; j++)
        {
            if (isalpha(stringInput[j]))
            {
                if (isupper(stringInput[j]))
                {

                    int encoding = encode;

                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == capitalLetter[k])
                        {
                            encoding += k;
                            if (encoding > 25)
                            {
                                encoding -= 26;
                            }
                            cout << capitalLetter[encoding];
                            break;
                        }
                    }
                }
                else
                {
                    int encoding = encode;

                    for (int k = 0; k < 26; k++)
                    {
                        if (stringInput[j] == smallLetter[k])
                        {
                            encoding += k;
                            if (encoding > 25)
                            {
                                encoding -= 26;
                            }
                            cout << smallLetter[encoding];
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
