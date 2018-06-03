#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char string[80];

	strcpy( "Hello World from ", string );

    cout << string;
    return 0;
}
