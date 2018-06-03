#include <iostream>

using namespace std;

class Car
{
private :
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public :
    void InitMembers(char * ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();
};

int main()
{
    Car run99;
    strcpy(run99.gamerID, "run99");
    run99.fuelGauge = 100;
    run99.curSpeed = 0;

    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();



    return 0;
}
