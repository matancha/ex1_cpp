#ifndef EX1_CPP_MATRIX3D_H
#define EX1_CPP_MATRIX3D_H

#include "Vector3D.h"
#include <array>

class Matrix3D
{
public:
    Matrix3D();
    Matrix3D(double num);
    Matrix3D(double num1, double num2, double num3,
             double num4, double num5, double num6,
             double num7, double num8, double num9);
    Matrix3D(double nums[9]);
    Matrix3D(double nums[3][3]);
    Matrix3D(Vector3D& vec1, Vector3D& vec2, Vector3D& vec3);
    Matrix3D(const Matrix3D& mat);

//    Matrix3D& operator+(const Matrix3D& rhs);
    friend std::ostream& operator<<(std::ostream &output, const Matrix3D &mat);
    const Vector3D row(short num) const;

private:
    std::array<Vector3D, 3> matrix;
};

#endif //EX1_CPP_MATRIX3D_H
