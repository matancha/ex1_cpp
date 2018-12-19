#ifndef EX1_CPP_VECTOR3D_H
#define EX1_CPP_VECTOR3D_H

#include <iostream>

class Vector3D
{
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    Vector3D(double numArr[3]);
    Vector3D(const Vector3D &old_vec);

    Vector3D& operator+(const Vector3D& rval);
    Vector3D& operator-(const Vector3D& rval);
    Vector3D& operator+=(const Vector3D& rval);
    Vector3D& operator-=(const Vector3D& rval);
    Vector3D& operator+=(double rval);
    Vector3D& operator-=(double rval);
    Vector3D& operator*(double rval);
    Vector3D& operator/(double rval);
    friend Vector3D& operator*(double lval, Vector3D& rval);
    Vector3D& operator*=(double rval);
    Vector3D& operator/=(double rval);
    double operator|(const Vector3D& rval);
    double operator*(const Vector3D& rval);
    Vector3D& operator-();
    Vector3D& operator=(const Vector3D& rval);
    friend std::ostream& operator<<(std::ostream &output, const Vector3D &vec);
    double& operator[](int i);

private:
    double _x;
    double _y;
    double _z;
};

#endif //EX1_CPP_VECTOR3D_H
