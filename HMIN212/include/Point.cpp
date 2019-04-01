#include "Point.hpp"
#include <iostream>

using namespace std;

Point::Point(){}

Point::Point(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(Point const& p){
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}

double Point::getZ(){
    return this->z;
}

void Point::setX(double x){
    this->x = x;
}

void Point::setY(double y){
    this->y = y;
}

void Point::setZ(double z){
    this->z = z;
}

Point Point::ProjectOnLine(Point point1Line, Point point2Line){
    Vector vLigne = Vector(point2Line.getX() - point1Line.getX(), point2Line.getY() - point1Line.getY() ,point2Line.getZ() - point1Line.getZ());
    Vector v = Vector(this->getX() - point1Line.getX(), this->getY() - point1Line.getY(), this->getZ() - point1Line.getZ());

    double norme = v.Scalar(vLigne)/vLigne.Norme();
    vLigne.Normalize();
    Point pRes = Point(point1Line.getX() + vLigne.getX() * norme, point1Line.getY() + vLigne.getY() * norme, point1Line.getZ() + vLigne.getZ() * norme);
    return pRes;
}

Point Point::ProjectOnLine(Vector vecteur, Point pLine){
    Vector v = Vector(this->getX() - pLine.getX(), this->getY() - pLine.getY(), this->getZ() - pLine.getZ());
    double norme = vecteur.Scalar(v)/vecteur.Norme();
    vecteur.Normalize();
    Point pRes = Point(pLine.getX() + vecteur.getX() * norme, pLine.getY() + vecteur.getY() * norme, pLine.getZ() + vecteur.getZ() * norme);
    return pRes;
}

Point Point::ProjectOnPlane(Point pointOnPlane, Vector normalOfPlane){
    Vector v = Vector(this->getX() - pointOnPlane.getX(), this->getY() - pointOnPlane.getY(), this->getZ() - pointOnPlane.getZ());
    double norme = v.Scalar(normalOfPlane) / normalOfPlane.Norme();

    Point pRes = Point(this->getX() - normalOfPlane.getX() * norme, this->getY() - normalOfPlane.getY() * norme, this->getZ() - normalOfPlane.getZ() * norme);
    return pRes;

}