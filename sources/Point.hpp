#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cmath>

using namespace std;
namespace ariel
{

    class Point
    {
    private:
        double x_cord;
        double y_cord;

    public:
        Point(double _x_, double _y_);
        Point();
        // Point(Point &other);
        double distance(Point src)const;
        double getX()const;
        double getY()const;
        string print()const;
        static Point moveTowards(Point src, Point dst, double dis);
    };
}