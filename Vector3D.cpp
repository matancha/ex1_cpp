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
Vector3D& Vector3D::operator+(const Vector3D& rhs)
{
    auto *newVector = new Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
    return *newVector;
}

Vector3D& Vector3D::operator+(const Vector3D& rhs) const
{
    auto *newVector = new Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
    return *newVector;
}

Vector3D& Vector3D::operator-(const Vector3D& rhs)
{
    auto *newVector = new Vector3D(_x - rhs._x, _y - rhs._y, _z - rhs._z);
    return *newVector;
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    _x += rhs._x;
    _y += rhs._y;
    _z += rhs._z;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    _x -= rhs._x;
    _y -= rhs._y;
    _z -= rhs._z;
}

Vector3D& Vector3D::operator+=(const double rhs)
{
    _x += rhs;
    _y += rhs;
    _z += rhs;
}

Vector3D& Vector3D::operator-=(const double rhs)
{
    operator+=(-rhs);
}

Vector3D& Vector3D::operator*(const double rhs)
{
    auto *newVector = new Vector3D(_x * rhs, _y * rhs, _z * rhs);
    return *newVector;
}

Vector3D& Vector3D::operator/(const double rhs)
{
    operator*(1/rhs);
}

Vector3D& operator*(const double lhs, Vector3D& rhs)
{
    rhs = rhs * lhs;
}

Vector3D& Vector3D::operator*=(const double rhs)
{
    _x *= rhs;
    _y *= rhs;
    _z *= rhs;
}

Vector3D& Vector3D::operator/=(const double rhs)
{
    operator*=(1/rhs);
}

double Vector3D::operator|(const Vector3D& rhs)
{
    return sqrt(pow(_x - rhs._x, 2) + pow(_y - rhs._y, 2) + pow(_z - rhs._z, 2));
}

double Vector3D::operator*(const Vector3D& rhs)
{
    return (_x * rhs._x + _y * rhs._y + _z * rhs._z);
}

// ---------------- Unary Operators ----------------

Vector3D& Vector3D::operator-()
{
    operator*(-1);
}

// ---------------- Assignment Operator ----------------
Vector3D& Vector3D::operator=(const Vector3D& rhs)
{
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;
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