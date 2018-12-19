#include "Vector3D.h"
#include <iostream>
#include <cmath>

// ---------------- Constructors ----------------
Vector3D::Vector3D()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vector3D::Vector3D(double numArr[3])
{
    _x = numArr[0];
    _y = numArr[1];
    _z = numArr[2];
}

Vector3D::Vector3D(const Vector3D& old_vec)
{
    _x = old_vec._x;
    _y = old_vec._y;
    _z = old_vec._z;
}

// ---------------- Binary Operators ----------------
Vector3D& Vector3D::operator+(const Vector3D& rval)
{
    auto *newVector = new Vector3D(_x + rval._x, _y + rval._y, _z + rval._z);
    return *newVector;
}

Vector3D& Vector3D::operator-(const Vector3D& rval)
{
    auto *newVector = new Vector3D(_x - rval._x, _y - rval._y, _z - rval._z);
    return *newVector;
}

Vector3D& Vector3D::operator+=(const Vector3D& rval)
{
    _x += rval._x;
    _y += rval._y;
    _z += rval._z;
}

Vector3D& Vector3D::operator-=(const Vector3D& rval)
{
    _x -= rval._x;
    _y -= rval._y;
    _z -= rval._z;
}

Vector3D& Vector3D::operator+=(const double rval)
{
    _x += rval;
    _y += rval;
    _z += rval;
}

Vector3D& Vector3D::operator-=(const double rval)
{
    operator+=(-rval);
}

Vector3D& Vector3D::operator*(const double rval)
{
    auto *newVector = new Vector3D(_x * rval, _y * rval, _z * rval);
    return *newVector;
}

Vector3D& Vector3D::operator/(const double rval)
{
    operator*(1/rval);
}

Vector3D& operator*(const double lval, Vector3D& rval)
{
    rval = rval * lval;
}

Vector3D& Vector3D::operator*=(const double rval)
{
    _x *= rval;
    _y *= rval;
    _z *= rval;
}

Vector3D& Vector3D::operator/=(const double rval)
{
    operator*=(1/rval);
}

double Vector3D::operator|(const Vector3D& rval)
{
    return sqrt(pow(_x - rval._x, 2) + pow(_y - rval._y, 2) + pow(_z - rval._z, 2));
}

double Vector3D::operator*(const Vector3D& rval)
{
    return (_x * rval._x + _y * rval._y + _z * rval._z);
}

// ---------------- Unary Operators ----------------

Vector3D& Vector3D::operator-()
{
    operator*(-1);
}

// ---------------- Assignment Operator ----------------
Vector3D& Vector3D::operator=(const Vector3D& rval)
{
    _x = rval._x;
    _y = rval._y;
    _z = rval._z;
}

// ---------------- IO Operators ----------------
std::ostream& operator<<(std::ostream& output, const Vector3D& vec)
{
    output << vec._x << " " << vec._y << " " << vec._z;
}

// ---------------- Subscript Operator ----------------
double& Vector3D::operator[](int i)
{
    if (i == 0)
    {
        return _x;
    }
    else if (i == 1)
    {
        return _y;
    }
    else if (i == 2)
    {
        return _z;
    }
}