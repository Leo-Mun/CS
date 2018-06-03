#include <iostream>
#include <fstream>

using namespace std;

class Square
{
public:
    int num;
    bool check;
};

class Board
{
private :
    Square board[5][5];

public:


    void setBoard(int inputs[5][5])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                board[i][j].num = inputs[i][j];
                board[i][j].check = false;
            }
        }
        board[2][2].check = true;
    }

    bool rowCheck (int data)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j].num == data)
                {
                    if (board[i][0].check == true && board[i][1].check == true && board[i][2].check == true && board[i][3].check == true && board[i][4].check == true)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }


            }
        }
    }

    bool colCheck (int data)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j].num == data)
                {
                    if (board[0][j].check == true && board[1][j].check == true && board[2][j].check == true && board[3][j].check == true && board[4][j].check == true)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }


            }
        }
    }

    bool crossCheck ()
    {
            if (board[0][0].check == true && board[1][1].check == true && board[2][2].check == true && board[3][3].check == true && board[4][4].check == true)
            {
                return true;
            }
            else if (board[4][0].check == true && board[3][1].check == true && board[2][2].check == true && board[1][3].check == true && board[0][4].check == true)
            {
                return true;
            }
            else
            {
                return false;
            }
    }

    bool edgeCheck ()
    {
        if (board[0][0].check == true && board[0][4].check == true && board[4][0].check == true && board[4][4].check == true )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool findData (int data)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (board[i][j].num == data)
                {
                    board[i][j].check = true;
                    return true;
                }
            }
        }
        return false;
    }

};


int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while (testCase--)
    {
        Board bingo;
        int count = 0;
        int inputs[5][5];

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int data;
                inFile >> data;
                inputs[i][j] = data;
            }
        }

        bingo.setBoard(inputs);

        int datas[75];
        for (int i = 0; i < 75; i++)
        {
            int data;
            inFile >> data;
            datas[i] = data;
        }

        for (int i = 0; i < 75; i++) {

            count++;

            if (bingo.findData(datas[i]))
            {
                if (bingo.rowCheck(datas[i]))
                {
                    cout << count << endl;
                    break;
                }
                else if (bingo.colCheck(datas[i]))
                {
                    cout << count << endl;
                    break;
                }
                else if (bingo.crossCheck())
                {
                    cout << count << endl;
                    break;
                }
                else if (bingo.edgeCheck())
                {
                    cout << count << endl;
                    break;
                }
            }

        }




    }


    inFile.close();
    return 0;
}
