#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> scores(10);

    for (int i = 0;  < scores.size(); i++) {
        cout << "type : ";
        cin >> scores[i];
    }

    double highest = scores[0];
    for (int i = 0; i < scores.size(); i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }


    cout << "highest : " << highest << endl;


    return 0;
}
