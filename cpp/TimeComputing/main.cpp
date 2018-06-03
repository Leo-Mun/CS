#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream inFile;
    inFile.open("input.txt");

    int time;
    inFile >> time;

    for (int i = 0; i < time; i++)
    {
        int numberOfEmployee;
        int allSecond = 0;
        int workDay = 0, workHour = 0, workMinute = 0, workSecond = 0;
        int rDay = 0, rHour = 0, rMinute = 0, rSecond = 0;
        inFile >> numberOfEmployee;



        for (int j = 0; j < numberOfEmployee; j++)
        {
            int startHour, startMinute, startSecond, endHour, endMinute, endSecond;
            inFile >> startHour >> startMinute >> startSecond >> endHour >> endMinute >> endSecond;


            if ((endSecond - startSecond) < 0) {
                workSecond += (endSecond + 60) - startSecond;
                workMinute--;
            } else {
                workSecond += (endSecond - startSecond);
            }

            if ((endMinute - startMinute) < 0) {
                workMinute += (endMinute + 60) - startMinute;
                --workHour;
            } else {
                workMinute += (endMinute - startMinute);
            }

            if ((endHour - startHour) < 0) {
                workHour += (endHour + 24) - startHour;
            } else {
                workHour += (endHour - startHour);
            }

        }

        rSecond = workSecond % 60;
        rMinute = (workMinute + workSecond/60) % 60;
        rHour = (workHour + (workMinute + workSecond/60)/60)%24;
        rDay = (workHour + (workMinute + workSecond/60)/60)/24;



        cout << rDay << " " << rHour << " " << rMinute << " " << rSecond << endl;

    }




    inFile.close();
    return 0;
}
