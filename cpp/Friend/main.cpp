#include <iostream>

using namespace std;


class Boy
{
private :
    int height;
    friend class Girl;
public :
    Boy(int len) : height(len){}
};

class Girl
{
private :
    char phNum[20];
public :
    Girl(char *num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn)
    {
        cout << "His height : " << frn.height <<endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
