#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> vec;

    vec.push_back("MILK");
    vec.push_back("BREAD");
    vec.push_back("BUTTER");

    vector<string>::iterator it;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    vec.insert(vec.begin() + 1, "APPLE");
    vec.pop_back();

    for (it = vec.begin(); it != vec.end(); ++it) {

    }
    return 0;
}
