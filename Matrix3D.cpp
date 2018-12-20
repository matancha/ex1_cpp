#include "Matrix3D.h"
#include "Vector3D.h"
#include <iostream>
#include <array>

// ---------------- Constructors ----------------
Matrix3D::Matrix3D()
{
    _matrix = {Vector3D(0, 0, 0), Vector3D(0, 0, 0), Vector3D(0, 0, 0)};
}

Matrix3D::Matrix3D(double num)
{
    _matrix = {Vector3D(num, 0, 0), Vector3D(0, num, 0), Vector3D(0, 0, num)};
}

Matrix3D::Matrix3D(double num1, double num2, double num3,
                   double num4, double num5, double num6,
                   double num7, double num8, double num9)
{
    _matrix = {Vector3D(num1, num2, num3), Vector3D(num4, num5, num6), Vector3D(num7, num8, num9)};
}

Matrix3D::Matrix3D(double nums[9])
{
    _matrix = {Vector3D(nums[0], nums[1], nums[2]), Vector3D(nums[3], nums[4], nums[5]), Vector3D
              (nums[6], nums[7], nums[8])};
}

Matrix3D::Matrix3D(double nums[3][3])
{
    _matrix = {Vector3D(nums[0]), Vector3D(nums[1]), Vector3D(nums[2])};
}

Matrix3D::Matrix3D(Vector3D vec1, Vector3D vec2, Vector3D vec3)
{
    _matrix = {vec1, vec2, vec3};
}

Matrix3D::Matrix3D(const Matrix3D& mat)
{
    _matrix = {mat.row(0), mat.row(1), mat.row(2)};
}

// ---------------- Binary Operators ----------------
Matrix3D Matrix3D::operator+(const Matrix3D& rhs) const
{
    return Matrix3D(row(1) + rhs.row(1), row(2) + rhs.row(2), row(3) + rhs.row(3));
}

Matrix3D Matrix3D::operator-(const Matrix3D& rhs) const
{
    return Matrix3D(row(1) - rhs.row(1), row(2) - rhs.row(2), row(3) - rhs.row(3));
}

Matrix3D Matrix3D::operator*(const Matrix3D& rhs) const
{
    Vector3D firstRow = Vector3D(this->row(1) * rhs.column(1), this->row(1) * rhs.column(2),
                                 this->row(1) * rhs.column(3));
    Vector3D secondRow = Vector3D(this->row(2) * rhs.column(1), this->row(2) * rhs.column(2),
                                  this->row(2) * rhs.column(3));
    Vector3D thirdRow = Vector3D(this->row(3) * rhs.column(1), this->row(3) * rhs.column(2),
                                 this->row(3) * rhs.column(3));
    return Matrix3D(firstRow, secondRow, thirdRow);
}

Vector3D Matrix3D::operator*(const Vector3D& rhs) const
{
    return Vector3D(this->row(1) * rhs, this->row(2) * rhs, this->row(3) * rhs);
}

Matrix3D& Matrix3D::operator*=(const double rhs)
{
    for (int i = 0; i < _matrix.size(); ++i)
    {
        _matrix[i] = _matrix[i] * rhs;
    }

    return *this;
}

Matrix3D& Matrix3D::operator+=(const Matrix3D& rhs)
{
    *this = *this + rhs;
    return *this;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D& rhs)
{
    *this = *this - rhs;
    return *this;
}

Matrix3D& Matrix3D::operator*=(const Matrix3D& rhs)
{
    *this = *this * rhs;
    return *this;
}

Matrix3D& Matrix3D::operator/=(const double rhs)
{
    *this = *this * (1/rhs);
    return *this;
}

// ---------------- Assignment Operator ----------------
Matrix3D& Matrix3D::operator=(const Matrix3D& rhs)
{
    _matrix = {rhs.row(0), rhs.row(1), rhs.row(2)};
    return *this;
}

// ---------------- IO Operators ----------------
std::ostream& operator<<(std::ostream& output, const Matrix3D& mat)
{
    output << mat.row(1) << std::endl << mat.row(2) << std::endl << mat.row(3);
    return output;
}

//std::istream& operator>>(std::istream& input, Matrix3D& vec)
//{
//    input >> vec._x >> vec._y >> vec._z;
//    return input;
//}

// ---------------- Subscript Operator ----------------
Vector3D& Matrix3D::operator[](short i)
{
    return this->_matrix[i];
}

Vector3D Matrix3D::operator[](short i) const
{
    return this->row(i);
}

// ---------------- Extra Functions ----------------
Vector3D Matrix3D::row(short num) const
{
    return _matrix[num];
}

Vector3D Matrix3D::column(short num) const
{
    return Vector3D(_matrix[0][num], _matrix[1][num], _matrix[2][num]);
}

double Matrix3D::trace() const
{
    return this->row(1)[0] + this->row(2)[1] + this->row(3)[2];
}

double Matrix3D::determinant() const
{

}