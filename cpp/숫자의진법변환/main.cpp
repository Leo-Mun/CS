#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while (testCase--)
    {
        int s, t;
        string n;
        int temporary = 0;
        inFile >> s >> n >> t;


        int tmp = 1;
        for (int i = n.size() - 1; i >= 0; i--)
        {
            if (n.at(i) <= '9')
            {
				temporary += (n.at(i) - '0') * tmp;
            }
			else
            {
				temporary += (n.at(i) - 'a' + 10) * tmp;
            }
			tmp *= s;
        }

        vector<int> change;

        while (temporary > 0)
        {
			change.push_back(temporary % t);
			temporary /= t;
		}

        for (int i = change.size() - 1; i >= 0; i--)
        {
            if (change.at(i) >= 10)
            {
                cout << (char)(change.at(i) - 10 + 'a');
            }
            else
            {
                cout << change.at(i);
            }
        }
        cout << endl;


    }

    inFile.close();
    return 0;

}
