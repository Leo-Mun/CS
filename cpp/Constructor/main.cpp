#include <iostream>

using namespace std;

class SimpleClass
{
private :
    int num;
public :
    SimpleClass(int n) // Constructor
    {
        num = n;
    }
    int GetNum() const
    {
        return num;
    }
};

class SoSimple
{
private :
    int num1;
    int num2;
public :
    SoSimple(int n1, int n2)
        : num1(n1) // int num1 = n1; µø¿œ
    {
        num2 = n2;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
