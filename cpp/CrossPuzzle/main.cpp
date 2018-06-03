#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;


void searchLetter(string words[]) {

}


int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int testCase;
    inFile >> testCase;

    while(testCase--) {
        char board[MAX][MAX];

        int row, column;
        inFile >> row >> column;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                char data;
                inFile >> data;
                board[i][j] = data;
            }
        }

        int numberOfWords;
        inFile >> numberOfWords;


        for (int i = 0; i < numberOfWords; i++) {
            string data;
            inFile >> data;

            int len = data.length();

            for (int j = 0; j < row; j++) {
                for (int k = 0; k < column; k++) {
                    if (data.at(0) == board[j][k]) {
                        cout << j+1 << " " << k+1 << " ";
                        for (int l = 1; l < len; l++) {
                            if (data.at(l) == board[j-1][k] && j - (len - 1) >= 0) {
                                if (data.at(len - 1) == board[j-1][k]) {
                                    cout << 0 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j-1][k+1] && j - (len - 1) >= 0 && k + (len - 1) <= column) {
                                if (data.at(len - 1) == board[j-1][k+1]) {
                                    cout << 1 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j][k+1] && k + (len - 1) <= column) {
                                if (data.at(len - 1) == board[j-1][k+1]) {
                                    cout << 2 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j+1][k+1] && i + (len - 1) <= row && k + (len - 1) <= column) {
                                if (data.at(len - 1) == board[j+1][k+1]) {
                                    cout << 3 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j+1][k] && i + (len - 1) <= row) {
                                if (data.at(len - 1) == board[j+1][k]) {
                                    cout << 4 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j+1][k-1] && i + (len - 1) <= row && k - (len - 1) <= 0) {
                                if (data.at(len - 1) == board[j+1][k-1]) {
                                    cout << 5 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j][k-1] && k - (len - 1) >= 0) {
                                if (data.at(len - 1) == board[j][k-1]) {
                                    cout << 6 << endl;
                                    break;
                                }
                                continue;
                            }
                            else if (data.at(l) == board[j-1][k-1] && i - (len - 1) >= 0 && k - (len - 1) >= 0) {
                                if (data.at(len - 1) == board[j-1][k-1]) {
                                    cout << 7 << endl;
                                    break;
                                }
                                continue;
                            }
                        }
                    }

                }
            }

        }



    }

    inFile.close();
    return 0;
}
