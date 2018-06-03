#include <iostream>

using namespace std;

class Person
{
private :
    int age;
    char name[50];
public :
    Person(int myAge, char * myName) : age(myAge)
    {
        strcpy(name, myName);
    }
    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }
    void HowOldAreYou() const
    {
        cout << "i'm " << age << " years old" << endl;
    }
};

class UnivStudent : public Person // Inheritance
{
private :
    char major[50];
public :
    UnivStudent(char *myName, int myAge, char * myMajor)
        : Person(myAge, myName)
    {
        strcpy(major, myMajor);
    }
    void WhoAreYou() const
    {
        WhatYourName();
        HowOldAreYou();
        cout << "My major is " << major << endl << endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
