#include "Matrix3D.h"
#include "Vector3D.h"
#include <iostream>
#include <array>

// ---------------- Constructors ----------------
Matrix3D::Matrix3D()
{
    matrix = {Vector3D(0, 0, 0), Vector3D(0, 0, 0), Vector3D(0, 0, 0)};
}

Matrix3D::Matrix3D(double num)
{
    matrix = {Vector3D(num, 0, 0), Vector3D(0, num, 0), Vector3D(0, 0, num)};
}

Matrix3D::Matrix3D(double num1, double num2, double num3,
                   double num4, double num5, double num6,
                   double num7, double num8, double num9)
{
    matrix = {Vector3D(num1, num2, num3), Vector3D(num4, num5, num6), Vector3D(num7, num8, num9)};
}

Matrix3D::Matrix3D(double nums[9])
{
    matrix = {Vector3D(nums[0], nums[1], nums[2]), Vector3D(nums[3], nums[4], nums[5]), Vector3D
              (nums[6], nums[7], nums[8])};
}

Matrix3D::Matrix3D(double nums[3][3])
{
    matrix = {Vector3D(nums[0]), Vector3D(nums[1]), Vector3D(nums[2])};
}

Matrix3D::Matrix3D(Vector3D& vec1, Vector3D& vec2, Vector3D& vec3)
{
    matrix = {vec1, vec2, vec3};
}

Matrix3D::Matrix3D(const Matrix3D& mat)
{
    matrix = {mat.row(0), mat.row(1), mat.row(2)};
}

// ---------------- Binary Operators ----------------
//Matrix3D& Matrix3D::operator+(const Matrix3D& rhs)
//{
//    Matrix3D *mat = new Matrix3D(row(1) + rhs.row(1), row(2) + rhs.row(2), row(3) + rhs.row(3));
//    return *mat;
//}

// ---------------- IO Operators ----------------
std::ostream& operator<<(std::ostream& output, const Matrix3D& mat)
{
    output << mat.row(1) << std::endl << mat.row(2) << std::endl << mat.row(3);
    return output;
}

// ---------------- Extra Functions ----------------
const Vector3D Matrix3D::row(short num) const
{
    return matrix[num];
}