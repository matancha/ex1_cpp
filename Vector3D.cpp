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
Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
    return Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
    return Vector3D(_x - rhs._x, _y - rhs._y, _z - rhs._z);
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    *this = *this + rhs;
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    *this = *this - rhs;
    return *this;
}

Vector3D& Vector3D::operator+=(const double rhs)
{
    _x += rhs;
    _y += rhs;
    _z += rhs;
    return *this;
}

Vector3D& Vector3D::operator-=(const double rhs)
{
    *this += (-rhs);
    return *this;
}

Vector3D Vector3D::operator*(const double rhs) const
{
    return Vector3D(_x * rhs, _y * rhs, _z * rhs);
}

Vector3D Vector3D::operator/(const double rhs) const
{
    return Vector3D(_x / rhs, _y / rhs, _z / rhs);
}

Vector3D operator*(const double lhs, Vector3D& rhs)
{
    return rhs * lhs;
}

Vector3D& Vector3D::operator*=(const double rhs)
{
    *this = *this * rhs;
    return *this;
}

Vector3D& Vector3D::operator/=(const double rhs)
{
    *this = *this / rhs;
    return *this;
}

double Vector3D::operator|(const Vector3D& rhs) const
{
    return dist(rhs);
}

double Vector3D::operator*(const Vector3D& rhs) const
{
    return (_x * rhs._x + _y * rhs._y + _z * rhs._z);
}

double Vector3D::operator^(const Vector3D& rhs) const
{
    double cosAlpha = (*this * rhs) / (this->norm() * rhs.norm());
    return acos(cosAlpha);
}

// ---------------- Unary Operators ----------------

Vector3D Vector3D::operator-() const
{
    Vector3D minusVec = *this * (-1);
    return minusVec;
}

// ---------------- Assignment Operator ----------------
Vector3D& Vector3D::operator=(const Vector3D& rhs)
{
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;
    return *this;
}

// ---------------- IO Operators ----------------
std::ostream& operator<<(std::ostream& output, const Vector3D& vec)
{
    output << vec._x << " " << vec._y << " " << vec._z;
    return output;
}

std::istream& operator>>(std::istream& input, Vector3D& vec)
{
    input >> vec._x >> vec._y >> vec._z;
    return input;
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
    else
    {
        fprintf(stderr, "Illegal index!");
        exit(EXIT_FAILURE);
    }
}

double Vector3D::operator[](int i) const
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
    else
    {
        fprintf(stderr, "Illegal index!");
        exit(EXIT_FAILURE);
    }
}

// ---------------- Extra Functions ----------------
double Vector3D::norm() const
{
    return dist(Vector3D());
}

double Vector3D::dist(const Vector3D& vec) const
{
    return sqrt(pow(_x - vec._x, 2) + pow(_y - vec._y, 2) + pow(_z - vec._z, 2));
}