#include <iostream>

using namespace std;

void magic(int n)
{
    int Max_Size = n;
    int square[Max_Size][Max_Size], k, l;
    // n이 올바른 값인지 검사
    if (n != 5)
    {
        cout << "You typed the wrong number." << endl;

        return;
    }
    // square를 0으로 초기화
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            square[i][j] = 0;
        }
    }

    square[0][(n - 1) / 2] = 1; //첫 행의 중간에 1삽입

    // i와 j는 현재 위치
    int key = 2, i = 0;
    int j = (n - 1) / 2;

    while(key <= n * n) {

        // 왼쪽 위로 이동
        if(i - 1 < 0)
        {
            k = n - 1;
        }
        else
        {
            k = i - 1;
        }
        if(j - 1 < 0)
        {
            l = n - 1;
        }
        else
        {
            l = j - 1;
        }

        if(square[k][l])
        {
            i = (i + 1) % n;
        }
        // square가 채워짐. 아래로 이동
        else { // square[k][l]이 채워지지 않음
            i = k;
            j = l;
        }

        square[i][j] = key;

        key++;

    } // end while


    // 매직 스퀘어를 출력
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    magic(5);

    return 0;
}
