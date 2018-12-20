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

    Vector3D operator+(const Vector3D& rhs) const;
    Vector3D operator-(const Vector3D& rhs) const;
    Vector3D& operator+=(const Vector3D& rhs);
    Vector3D& operator-=(const Vector3D& rhs);
    Vector3D& operator+=(double rhs);
    Vector3D& operator-=(double rhs);
    Vector3D operator*(double rhs) const;
    Vector3D operator/(double rhs) const;
    friend Vector3D operator*(double lhs, Vector3D& rhs);
    Vector3D& operator*=(double rhs);
    Vector3D& operator/=(double rhs);
    double operator|(const Vector3D& rhs) const;
    double operator*(const Vector3D& rhs) const;
    double operator^(const Vector3D& rhs) const;
    Vector3D operator-() const;
    Vector3D& operator=(const Vector3D& rhs);
    friend std::ostream& operator<<(std::ostream& output, const Vector3D& vec);
    friend std::istream& operator>>(std::istream& input, Vector3D& vec);
    double& operator[](int i);
    double operator[](int i) const;

    double norm() const;
    double dist(const Vector3D& vec) const;

private:
    double _x;
    double _y;
    double _z;
};

#endif //EX1_CPP_VECTOR3D_H
