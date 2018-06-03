#include <iostream>
#include <list>

using namespace std;


void printList(list<int> & li);

int main()
{
    list<int> myList;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    myList.insert(myList.begin(), 5);
    myList.insert(myList.end(), 45);
    printList(myList);

    return 0;
}

void printList(list<int> &li) {
    list<int>::iterator it;
    for(it=li.begin(); it!= li.end(); ++it) {
        cout << *it <<  " ";
    }
    cout << endl;
}
