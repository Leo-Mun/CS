#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int numOfNum;
        inFile >> numOfNum;

        map<int, int> m;

        for (int j = 0; j < numOfNum; j++)
        {
            int num;
            inFile >> num;


            if (m.find(num) == m.end())
            {
                m[num] = 1;

            }
            else
            {
                m[num]++;
            }
        }

        int most = 0;

        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if (most < it -> second)
            {
                most = it -> second;
            }
        }
//        cout << "most : " << most << endl;

        vector<int> v;

        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            if (most == it -> second)
            {
                v.push_back(it -> first);
            }
        }

        cout << v.size() << " " << most << " " ;

        for (int i = 0; i < v.size(); i++)
        {
            cout << v.at(i) << " ";
        }

        cout << endl;




    }

    inFile.close();
    return 0;
}
