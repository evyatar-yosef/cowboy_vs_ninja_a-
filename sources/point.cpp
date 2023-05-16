#include "point.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;

Point::Point(double P_x, double P_y)    
{ 
  this->p_x = P_x;
  this->p_y = P_y;  
}

Point::Point()
{
}

double Point::distance(Point other) const {
    double dx = p_x - other.p_x;
    double dy = p_y - other.p_y;
    return std::sqrt(dx*dx + dy*dy);
}

std::string Point::print() const {
   // std::cout << "(" << p_x << ", " << p_y << ")";
   return "";
}

Point Point::moveTowards(Point source, Point dest, double distance) const {
    // double d = distance;
    // double dx = dest.p_x - source.p_x;
    // double dy = dest.p_y - source.p_y;
    // double distanceToDest = std::sqrt(dx*dx + dy*dy);
    // if (distanceToDest <= d) {
    //     return dest;
    // } else {
    //     double newX = source.p_x + dx * d / distanceToDest;
    //     double newY = source.p_y + dy * d / distanceToDest;
    //     return Point(newX, newY);
    // }
    return Point();
}
double Point:: getX()
{
    return 1;
}
double Point:: getY()
{
    return 1;
}
