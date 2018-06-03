#include <iostream>

using namespace std;

void magic(int n)
{
    int Max_Size = n;
    int square[Max_Size][Max_Size], k, l;
    // n�� �ùٸ� ������ �˻�
    if (n != 5)
    {
        cout << "You typed the wrong number." << endl;

        return;
    }
    // square�� 0���� �ʱ�ȭ
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            square[i][j] = 0;
        }
    }

    square[0][(n - 1) / 2] = 1; //ù ���� �߰��� 1����

    // i�� j�� ���� ��ġ
    int key = 2, i = 0;
    int j = (n - 1) / 2;

    while(key <= n * n) {

        // ���� ���� �̵�
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
        // square�� ä����. �Ʒ��� �̵�
        else { // square[k][l]�� ä������ ����
            i = k;
            j = l;
        }

        square[i][j] = key;

        key++;

    } // end while


    // ���� ����� ���
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
