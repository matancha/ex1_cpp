#ifndef EX1_CPP_MATRIX3D_H
#define EX1_CPP_MATRIX3D_H

#include "Vector3D.h"
#include <array>

class Matrix3D
{
public:
    /**
     * Default constructor
     */
    Matrix3D();
    /**
     * Number in the diagonal constructor
     * @param num
     */
    Matrix3D(double num);
    /**
     * 9 numbers constructor
     * @param num1
     * @param num2
     * @param num3
     * @param num4
     * @param num5
     * @param num6
     * @param num7
     * @param num8
     * @param num9
     */
    Matrix3D(double num1, double num2, double num3,
             double num4, double num5, double num6,
             double num7, double num8, double num9);
    /**
     * Number array constructor
     */
    Matrix3D(double nums[9]);
    /**
     * 2D Array constructor
     * @param nums
     */
    Matrix3D(double nums[3][3]);
    /**
     * 3 vectors constructor
     * @param vec1
     * @param vec2
     * @param vec3
     */
    Matrix3D(Vector3D vec1, Vector3D vec2, Vector3D vec3);
    /**
     * Copy constructor
     * @param mat
     */
    Matrix3D(const Matrix3D& mat);

    /* Plus operator */
    Matrix3D operator+(const Matrix3D& rhs) const;
    /* Minus operator */
    Matrix3D operator-(const Matrix3D& rhs) const;
    /* Matrix multiplication */
    Matrix3D operator*(const Matrix3D& rhs) const;
    /* Multiply matrix by vector */
    Vector3D operator*(const Vector3D& rhs) const;
    /* Multiply matrix by constant */
    Matrix3D& operator*=(double rhs);
    /* Add to matrix */
    Matrix3D& operator+=(const Matrix3D& rhs);
    /* Substract from matrix */
    Matrix3D& operator-=(const Matrix3D& rhs);
    /* Multiply by matrix */
    Matrix3D& operator*=(const Matrix3D& rhs);
    /* Divide matrix by constant */
    Matrix3D& operator/=(double rhs);
    /* Assign matrix */
    Matrix3D& operator=(const Matrix3D& rhs);
    /* Print matrix */
    friend std::ostream& operator<<(std::ostream &output, const Matrix3D &mat);
    /* Get matrix from input */
    friend std::istream& operator>>(std::istream &output, Matrix3D &mat);
    /* Write-access row */
    Vector3D& operator[](short i);
    /* Read-access row */
    Vector3D operator[](short i) const;

    /* Get matrix row */
    Vector3D row(short num) const;
    /* Get matrix column */
    Vector3D column(short num) const;
    /* Calculate trace */
    double trace() const;
    /* Calculate determinant */
    double determinant() const;

private:
    /* Matrix */
    std::array<Vector3D, 3> _matrix;
};

#endif //EX1_CPP_MATRIX3D_H
