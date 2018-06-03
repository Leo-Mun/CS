#include <iostream>

using namespace std;

const int stackSize = 4;
class Stack
{
private :
    int stack[stackSize];
    int top;

public :
    Stack()
    {
        top = -1;
    }

    void push (int val)
    {
        stack[++top] = val;
    }

    int pop ()
    {
        return stack[top--];
    }

    int isEmpty ()
    {
        return top == -1;
    }

    int isFull()
    {
        return top == stackSize - 1;
    }

    void push(int top, int item)
    {
        if (top >= stackSize - 1)
        {
            stack
        }
    }
};


int main()
{
    return 0;
}
