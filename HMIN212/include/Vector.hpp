#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
    private :
        double x, y ,z;

    public :
        Vector();
        Vector(double x, double y, double z);
        Vector(Vector const &p);

        double getX();
        double getY();
        double getZ();

        void setX(double x);
        void setY(double y);
        void setZ(double z);
        
        double Norme();
        void Normalize();
        double Scalar(Vector vector2);
        Vector Vectoriel(Vector vector2);
        double Angle(Vector vector2);
        void Neg();
};

#endif