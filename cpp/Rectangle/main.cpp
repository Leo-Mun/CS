#include <iostream>

using namespace std;

class Point
{
private :
    int x;
    int y;
public :
    Point (const int &xpos, const int &ypos); // Constructor
    int GetX() const;
    int GetY() const;
    bool SetX(int xpos);
    bool SetY(int ypos);
};

Point::Point (const int &xpos, const int &ypos)
{
    x = xpos;
    y = ypos;
}

bool Point::SetX(int xpos)
{
    if (0 > xpos || xpos > 100)
    {
        return false;
    }
    x = xpos;
    return true;
}

class Rectangle
{
private :
    Point upLeft;
    Point lowRight;
public :
    Rectangle(const int &x1, cons int &y1, const int &x2, const int &y2);    void ShowRecInfo() const;
};
Rectangle::Rectangle(const int &x1, cons int &y1, const int &x2, const int &y2);
    : upLeft(x1, y1), lowRight(x2, y2)
{

}

void Rectangle::ShowRecInfo()
{
        cout << "좌 상단 : " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "우 하단 " << '[' << lowRight.x << ", ";
        cout << lowRight.y << ']' << endl << endl;
}

bool Rectangle::InitMembers(const Point &ul, const Point &lr);
{
        if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
        {
            return false;
        }
        upLeft = ul;
        lowRight = lr;
        return true;
}

int main()
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};
    rec.ShowRecInfo();

    retur 0;

}
