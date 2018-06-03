#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Shape
{

} typedef shape;

    struct Triangle
    {
        char name[20];
        float base;
        float height;


    } typedef triangle;

    struct Rectangle
    {
        char name[20];
        float side1;
        float side2;

    } typedef rectangle;

    struct round
    {
        char name[20];
        float radius;
    } typedef circle;




int main()
{
    fstream inFile;
    inFile.open("lab3.txt");

    Shape * shapes[8];

    for (int i = 0; i < 8; i++)
    {
        char frame[10];
        inFile >> frame;
//      cout << shape;
        if (strcmp(frame, "triangle") == 0)
        {
            triangle tri;
            strcpy(tri.name, frame);
            inFile >> tri.base >> tri.height;
            shapes[i] = tri;
        }
        else if (strcmp(frame, "rectangle"))
        {
            rectangle rec;
            strcpy(rec.name, frame);
            inFile >> rec.side1 >> rec.side2;
            shapes[i] = rec;
        }
        else if (strcmp(frame, "circle"))
        {
            circle cir;
            strcpy(cir.name, frame);
            inFile >> cir.radius;
            shapes[i] = cir;
        }

//        cout << shapes[i].name;


    }








    return 0;
}
