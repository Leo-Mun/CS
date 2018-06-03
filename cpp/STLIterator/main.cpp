#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<double> scores;

    while(true) {
        double value = 0;
        cout << "type : " ;
        cin >> value;
        if(value < 0)
            break;
        scores.push_back(value);
        double highest = -100;
        vector<double>::iterator it;
        for (it = scores.begin(); it < scores.end(); it++) {
            if (*it > highest)
                highest = *it;
        }
    }

    cout << highest;


    return 0;
}
