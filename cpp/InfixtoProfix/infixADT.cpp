#include "infix.h"

class Stack
{
public:
    int myStack[STACK_SIZE];
    int top;

    Stack()
    {
        top = -1;
    }
    int isFull()
    {
        if (top == STACK_SIZE - 1) return 1;
        else return 0;
    }
    int isEmpty()
    {
        if (top == -1) return 1;
        else return 0;
    }
    void push(int num)
    {
        ++top;
        myStack[top] = num;
    }
    int pop()
    {
        return (myStack[top--]);
    }


};
void postfix (void)
{
    Stack tmpStack;

    char symbol;
    int n = 0;
    int top = 0;
    myStack[0] = eos;
    for (token= get_token(symbol, n); token!= '\0';)
    {
    if (token == operand) cout << symbol;
        else if (token == lparen) Push(top, token)
            else if (token == rparen)
            {
                while (stack[top] != lparen)
                print_token(POP(top));
                POP(top);
            }
            else
            {
                if (isp[stack[top]] <= icp[token]) Push(top, token);
                else {
                while ((stack!=empty)&& (isp[stack[top]] >= icp[token]))
                print_token(POP(top));
                Push(top, token);
                }
                }
                while ((token=POP(top)) != eos) print_token(token);
                }
}

