#include <iostream>
#include <set>
using namespace std;

template <typename T>
void printList(const T& container);

int main()
{
    set<int> mySet;
    multiset<int> myMultiSet;

    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);

    myMultiSet.insert(mySet.begin(), mySet.end());
    myMultiSet.insert(3);
    myMultiSet.insert(4);

    printList(mySet);
    printList(myMultiSet);


    return 0;
}

template <typename T>
void printList(const T& container) {
    T::const_iterator it;
    for (it = container.begin(); it!=container.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
