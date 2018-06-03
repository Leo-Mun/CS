#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    set<int> getHamingSet;
    getHamingSet.insert(1);

    set<int>::iterator it = getHamingSet.begin();
    while(getHamingSet.size() <= 1500)
    {
        getHamingSet.insert((*it) * 2);
		getHamingSet.insert((*it) * 3);
		getHamingSet.insert((*it) * 5);
		it++;
    }

    vector<int> hamingNumber;
    for (set<int>::iterator i = getHamingSet.begin(); i != getHamingSet.end(); i++)
    {
        hamingNumber.push_back(*i);
    }


    for (int k = 0; k < testCase; k++)
    {
		int num;
		inFile >> num;
		cout << hamingNumber.at(num - 1) << endl;
	}

    inFile.close();
    return 0;
}
