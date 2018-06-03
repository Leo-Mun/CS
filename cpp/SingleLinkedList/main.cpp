#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};
class List
{
private:
    Node *head;
public:
    List ()
    {
        head = 0;
    }
    void insert(int);
    void append(int);
    bool isEmpty();
    void display();
};
void List::insert(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = 0;
    if (head != 0)
    {
        temp->next = head;
        head = temp;
    }
    else head = temp;
}
void List::append(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = 0;
    if (head == 0)
        head = temp;
    else
    {
        Node *ptr = head;
        while (ptr->next != 0)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
bool List::isEmpty()
{
    if (head == 0) return true;
    else return false;
}
void List::display()
{
    Node *ptr;
    ptr = head;
    while (ptr)
    {
        cout << ptr->data;
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    List l1;
    l1.insert(40);
    l1.insert(30);
    l1.append(50);
    l1.append(80);
    l1.display();

    return 0;
}
