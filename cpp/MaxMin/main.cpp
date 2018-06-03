#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("input.txt");

	int time;
 	inFile >> time;

 	for (int i = 0; i < time; i++)
 	{
 		int count, first;
 		int max, min, num;

 		inFile >> count;

 		inFile >> first;
 		max = min = first;

 		for (int j = 1; j < count; j++)
 		{
 			inFile >> num;
 			if (max < num)
            {
 				max = num;
            }

 			if (min > num)
            {
 				min = num;
            }
 		}

 		cout << max << " " << min << endl;
 	}

 	inFile.close();
 	return 0;
 }
