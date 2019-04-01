#include "Vector.hpp"  
#include <math.h>

Vector::Vector(){}

Vector::Vector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(Vector const& p){
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

double Vector::getX(){
    return this->x;
}

double Vector::getY(){
    return this->y;
}

double Vector::getZ(){
    return this->z;
}

void Vector::setX(double x){
    this->x = x;
}

void Vector::setY(double y){
    this->y = y;
}
void Vector::setZ(double z){
    this->z = z;
}

double Vector::Norme(){
    return sqrt(getX()*getX() + getY()*getY()+ getZ()*getZ());
}

void Vector::Normalize(){
    double norme = this->Norme();
    this->x = this->x / norme;
    this->y = this->y / norme;
    this->z = this->z / norme;
}

double Vector::Scalar(Vector vector2){
    return this->x * vector2.x + this->y * vector2.y + this->z * vector2.z;
}

Vector Vector::Vectoriel(Vector vector2){
    double x = this->y * vector2.z - this->z * vector2.y;
    double y = this->z * vector2.x - this->x * vector2.z;
    double z = this->x * vector2.y - this->y * vector2.x;
    return Vector(x,y,z);
}

double Vector::Angle(Vector vector2){
    return cos(this->Norme() / vector2.Norme());
}

void Vector::Neg(){
    this->x = this->x * -1;
    this->y = this->y * -1;
    this->z = this->z * -1;
}