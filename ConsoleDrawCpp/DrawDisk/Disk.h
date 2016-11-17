#pragma once
#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Disk
{
public:
    Disk(Point center, int radius)
        :center(center),radius(radius)
    {
    }
    Disk(int x = 0, int y = 0, int radius = 5)
        :center(x,y),radius(radius)
    {
    }
    void Draw()
    {
        size_t height = radius * 2 + center.y + 1;
        size_t width = radius * 2 + center.x + 1;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                cout << (inDisk(x, y) ? "* " : "  ");
            }
            cout << endl;
        }
    }
private:
    Point center;
    int radius;

    bool inDisk(int x, int y)
    {
        return powTwo(x - center.x) + powTwo(y - center.y) <= powTwo(radius);
    }

    inline int powTwo(int number)
    {
        return number * number;
    }
};