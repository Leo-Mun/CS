#include <iostream>

using namespace std;

const int STACK_SIZE = 100;

class Element
{
public:
    short int row;
    short int col;
    short int dir;

};

class Offsets
{
public:
    int vert;
    int horiz;
};


class Stack
{
private:
    Element stack[STACK_SIZE];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    void push(Element num)
    {
        ++top;
        stack[top] = num;
    }
    Element pop()
    {
        if(!isEmpty()) {
            return stack[top--];
        }
        else {
            cout << "stack is empty";
        }
    }
    int isEmpty()
    {
        return top == -1;
    }

    int isFull()
    {
        return top == STACK_SIZE - 1;
    }
    Element topView()
    {
        if(!isEmpty())
            return stack[top];
        else
            cout << "stack is empty";
    }

    void displayStack();
};

void Stack::displayStack()
{
    int sp;
    sp = top;
    while (sp != -1)
    {
        cout << stack[sp].row << " " << stack[sp].col << endl;
        --sp;
    }
    cout << endl;
};

int mazeStart(int maze[6][6], int mark[6][6], Stack &stack1, Stack &stack2)
{
    int row, col, dir, nextRow, nextCol;
    bool found = false;

    Element temp;
    Offsets move[8];
    move[0].vert=-1; move[0].horiz=0; // N
    move[1].vert=-1; move[1].horiz=1; // NE
    move[2].vert=0; move[2].horiz=1;  // E
    move[3].vert=1; move[3].horiz=1;  // SE
    move[4].vert=1; move[4].horiz=0;  // S
    move[5].vert=1; move[5].horiz=-1; // SW
    move[6].vert=0; move[6].horiz=-1; // W
    move[7].vert=-1; move[7].horiz=-1;// NW

    temp.row = 0;
    temp.col = 0;
    temp.dir = 2;
    mark[0][0] = 1;
    stack1.push(temp);
    while(!stack1.isEmpty() && !found)
    {
        temp = stack1.topView();
        row = temp.row;
        col = temp.col;
        dir = temp.dir;

        if(dir == 8) {
            stack1.pop();
        }

        while(dir < 8 && !found)
        {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;

            if(nextRow == 5 && nextCol == 5)
            {
                mark[nextRow][nextCol] = 1;
                temp.row = nextRow;
                temp.col = nextCol;
                temp.dir = dir;
                stack1.push(temp);
                found = true;

            }
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
            {
                mark[nextRow][nextCol] = 1;
                temp.row = row;
                temp.col = col;
                temp.dir = dir;
                if(!temp.row && !temp.col) {
                    stack1.pop();
                }
                stack1.push(temp);
                row = nextRow;
                col = nextCol;
                dir = 0;
            }
            else
                dir++;
        }
    }
    while(!stack1.isEmpty())
    {
        temp = stack1.pop();
        stack2.push(temp);
    }
}

int main()
{
    Stack stack1;
    Stack stack2;

    int maze[6][6] = { 0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,0,1,0,0,1,1,1,1,1,1,0 };
    int mark[6][6] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    mazeStart(maze, mark, stack1, stack2);

    stack2.displayStack();
    cout << "-----------------------------" << endl;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cout << mark[i][j] << " ";
        }
        cout << endl;
    }

}
