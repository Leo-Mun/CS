#include <iostream>

using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    bool room[100][100];

    while(testCase--) {
        int h, w, n;
        cin >> h >> w >> n;

        int nCheck = 0;

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                room[j][i] = true;
                nCheck++;
                if (nCheck == n) {
                    cout << j + 1;
                    if (i < 10) {
                        cout << 0 << i + 1 << endl;
                    }
                    else {
                        cout << i + 1 << endl;
                    }
                }
            }
        }

    }
    return 0;
}
