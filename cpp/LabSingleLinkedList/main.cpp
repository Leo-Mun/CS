#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int id;
    string major;
    string grade;

};



int main()
{

    fstream inFile;
    inFile.open("data1.txt");

    vector<Student> students;

    Student a;

    for (; cin.eof();)
    {

    }


    return 0;
}

