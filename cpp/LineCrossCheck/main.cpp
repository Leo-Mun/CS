#include <iostream>
#include <fstream>

using namespace std;

int getArea (int x1, int y1, int x2, int y2, int x3, int y3);


int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    for (int i = 0; i < testCase; i++)
    {
        int crossCheck, signCheck1, signCheck2;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        inFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        signCheck1 = getArea(x1, y1, x2, y2, x3, y3) * getArea(x1, y1, x2, y2, x4, y4);
		signCheck2 = getArea(x3, y3, x4, y4, x1, y1) * getArea(x3, y3, x4, y4, x2, y2);

		if (signCheck1 < 0 && signCheck2 < 0)
		{
            crossCheck = 1;
		}
		else if (signCheck1 <= 0 && signCheck2 <= 0)
		{
            crossCheck = 2;
		}
		else
        {
            crossCheck = 0;
        }

        cout << crossCheck << endl;



    }

    inFile.close();
    return 0;
}
int getArea (int x1, int y1, int x2, int y2, int x3, int y3)
{
    int area;
    area = ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
    return area;
}

