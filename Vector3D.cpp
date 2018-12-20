#include "Vector3D.h"
#include <iostream>
#include <cmath>

/**
 * Class representing a 3D matrix
 */

// ---------------- Constructors ----------------
/**
 * default constructor
 */
Vector3D::Vector3D() : Vector3D(0, 0, 0)
{
}

/**
 * 3 doubles constructor
 */
Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

/**
 * Double array constructor
 * @param numArr array of doubles
 */
Vector3D::Vector3D(double numArr[3]) : Vector3D(numArr[0], numArr[1], numArr[2])
{
}

/**
 * Copy constructor
 * @param old_vec obj to copy
 */
Vector3D::Vector3D(const Vector3D& old_vec) : Vector3D(old_vec._x, old_vec._y, old_vec._z)
{
}

// ---------------- Binary Operators ----------------
/**
 * Plus operator
 * @param rhs
 * @return
 */
Vector3D Vector3D::operator+(const Vector3D& rhs) const
{
    return Vector3D(_x + rhs._x, _y + rhs._y, _z + rhs._z);
}

/**
 * Minus operator
 * @param rhs
 * @return
 */
Vector3D Vector3D::operator-(const Vector3D& rhs) const
{
    return Vector3D(_x - rhs._x, _y - rhs._y, _z - rhs._z);
}

/**
 * Increment by operator
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
    *this = *this + rhs;
    return *this;
}

/**
 * Decrement by operator
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
    *this = *this - rhs;
    return *this;
}

/**
 * Increment Vector by number
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator+=(const double rhs)
{
    _x += rhs;
    _y += rhs;
    _z += rhs;
    return *this;
}

/**
 * Decrement Vector by number
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator-=(const double rhs)
{
    *this += (-rhs);
    return *this;
}

/**
 * Multiply vector by number
 * @param rhs
 * @return
 */
Vector3D Vector3D::operator*(const double rhs) const
{
    return Vector3D(_x * rhs, _y * rhs, _z * rhs);
}

/**
 * Divide vector by number
 * @param rhs
 * @return
 */
Vector3D Vector3D::operator/(const double rhs) const
{
    return Vector3D(_x / rhs, _y / rhs, _z / rhs);
}

/**
 * Multiply vector by number
 * @param lhs
 * @param rhs
 * @return
 */
Vector3D operator*(const double lhs, Vector3D& rhs)
{
    return rhs * lhs;
}

/**
 * Multiply vector by number
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator*=(const double rhs)
{
    *this = *this * rhs;
    return *this;
}

/**
 * Divide vector by number
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator/=(const double rhs)
{
    *this = *this / rhs;
    return *this;
}

/**
 * Calculate distance between vectors
 * @param rhs
 * @return
 */
double Vector3D::operator|(const Vector3D& rhs) const
{
    return dist(rhs);
}

/**
 * Calculate scalar product
 * @param rhs
 * @return
 */
double Vector3D::operator*(const Vector3D& rhs) const
{
    return (_x * rhs._x + _y * rhs._y + _z * rhs._z);
}

/**
 * Calculate angle between vectors
 * @param rhs
 * @return
 */
double Vector3D::operator^(const Vector3D& rhs) const
{
    double cosAlpha = (*this * rhs) / (this->norm() * rhs.norm());
    return acos(cosAlpha);
}

// ---------------- Unary Operators ----------------

/**
 * Negative vector
 * @return
 */
Vector3D Vector3D::operator-() const
{
    Vector3D minusVec = *this * (-1);
    return minusVec;
}

// ---------------- Assignment Operator ----------------
/**
 * Equal operator
 * @param rhs
 * @return
 */
Vector3D& Vector3D::operator=(const Vector3D& rhs)
{
    _x = rhs._x;
    _y = rhs._y;
    _z = rhs._z;
    return *this;
}

// ---------------- IO Operators ----------------
/**
 * Print operator
 * @param output
 * @param vec
 * @return
 */
std::ostream& operator<<(std::ostream& output, const Vector3D& vec)
{
    output << vec._x << " " << vec._y << " " << vec._z;
    return output;
}

/**
 * Input operator
 * @param input
 * @param vec
 * @return
 */
std::istream& operator>>(std::istream& input, Vector3D& vec)
{
    input >> vec._x >> vec._y >> vec._z;
    return input;
}

// ---------------- Subscript Operator ----------------
/**
 * Subscript for changing row
 * @param i
 * @return
 */
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

/**
 * Subscript for viewing row
 * @param i
 * @return
 */
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
/**
 * Norm of the vector
 * @return
 */
double Vector3D::norm() const
{
    return dist(Vector3D());
}

/**
 * Distance between vectors
 * @param vec
 * @return
 */
double Vector3D::dist(const Vector3D& vec) const
{
    return sqrt(pow(_x - vec._x, 2) + pow(_y - vec._y, 2) + pow(_z - vec._z, 2));
}