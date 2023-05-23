#include "Point.hpp"
using namespace std;

namespace ariel
{

    Point::Point(double x, double y)
    {
        x_cord = x;
        y_cord = y;
    }

    Point::Point()
    {
        x_cord = 0.0;
        y_cord = 0.0;
    }

    // Point::Point(Point &other)
    // {
    //     x_cord = other.getX();
    //     y_cord = other.getY();
    // }

    double Point::distance(Point dest) const
    {
        double dist_x = dest.getX() - x_cord;
        double dist_y = dest.getY() - y_cord;
        return std::sqrt(dist_x * dist_x + dist_y * dist_y);
    }

    double Point::getX() const
    {
        return x_cord;
    }

    double Point::getY() const
    {
        return y_cord;
    }

    string Point::print() const
    {
        return "(" + to_string(this->x_cord) + "," + to_string(this->y_cord) + ")";
    }


    Point Point::moveTowards(Point src, Point dst, double actual_dist)
    {
        if (actual_dist < 0)
        {
            throw invalid_argument("Distance can't be less than 0"); // throw an exception
        }

        // Calculate the distance between src and dst points
        double src_2_dst = src.distance(dst);

        if (src_2_dst <= actual_dist)
        {
            return dst; // The destination point is within the desired distance
        }

        // Calculate the new point
        double new_distance = actual_dist / src_2_dst;
        double new_x_cord = src.getX() + ((dst.getX() - src.getX()) * new_distance);
        double new_y_cord = src.getY() + ((dst.getY() - src.getY()) * new_distance);

        return Point(new_x_cord, new_y_cord);
    }

}