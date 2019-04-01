#ifndef POINT_HPP
#define POINT_HPP

#include "Vector.hpp"

class Point {
    private :
        double x, y,z;

    public : 
        Point();
        Point(double x, double y, double z);
        Point(Point const& p);

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        
        Point ProjectOnLine(Point point1Line, Point point2Line);
        Point ProjectOnLine(Vector vecteur, Point pLine);
        Point ProjectOnPlane(Point pointOnPlane, Vector normalOfPlane);
};

#endif