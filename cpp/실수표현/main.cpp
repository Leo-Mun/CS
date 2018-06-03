#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        char data[257];
        inFile >> data;

        int length = strlen(data);

        bool result = false;
        bool num = false;
        bool character = false;
        bool dot = false;
        bool exp = false;

        for (int j = 0; j < length; j++)
        {
            if (isdigit(data[j]))
            {
                num = true;
            }
            else if (!dot && !exp && data[j] == '.')
            {
                dot = true;
            }
            else if (!exp && (data[j] == 'e' || data[j] == 'E'))
            {
                exp = true;
                if (j + 1 < length && num == true)
                {
                    j++;
                    if (!isdigit(data[j]) && data[j] != '-' && data[j] != '+')
                    {
						break;
                    }
					else if (data[j] == '-' || data[j] == '+') {
						if (j + 1 < length) {
							j++;
							if (!isdigit(data[j]))
                            {
								break;
                            }
						}
						else
							break;
					}
				}
				else
					break;
			}
			else
				break;
			if (j == length - 1)
            {
				result = true;
            }
		}
		if (result && (dot || exp) && num)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

    inFile.close();
    return 0;
}
