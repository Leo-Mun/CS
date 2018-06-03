#include <iostream>

using namespace std;

class Person
{
private :
    char * name;
    int age;
public :
    Person(char * myName, int myAge)
    {
        int len = strlen(myName) + 1;
        name = new char[len];
        strcpy(name, myName);
        age = myAge;
    }
    void ShowPersonInfo() const
    {
        cout << "�̸� : " << name << endl;
        cout << "���� : " << age << endl;
    }
    ~Person() // destructor
    {
        delete []name; // destructor
        cout << "called destructor! " << endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
