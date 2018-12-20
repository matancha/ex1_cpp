#include "Matrix3D.h"
#include "Vector3D.h"
#include <iostream>
#include <array>

/**
 * Class representing a 3D matrix
 */

// ---------------- Constructors ----------------
/**
 * Default constructor
 */
Matrix3D::Matrix3D() : Matrix3D(Vector3D(0, 0, 0),
                                Vector3D(0, 0, 0),
                                Vector3D(0, 0, 0))
{
}

/**
 * Constructor with number in diagonal
 * @param num
 */
Matrix3D::Matrix3D(double num) : Matrix3D(Vector3D(num, 0, 0),
                                          Vector3D(0, num, 0),
                                          Vector3D(0, 0, num))
{
}

/**
 * Constructor with 9 numbers
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
Matrix3D::Matrix3D(double num1, double num2, double num3,
                   double num4, double num5, double num6,
                   double num7, double num8, double num9) : Matrix3D(Vector3D(num1, num2, num3),
                                                                     Vector3D(num4, num5, num6),
                                                                     Vector3D(num7, num8, num9))
{
}

/**
 * Constructor with number array
 * @param nums
 */
Matrix3D::Matrix3D(double nums[9]) : Matrix3D(Vector3D(nums[0], nums[1], nums[2]),
                                              Vector3D(nums[3], nums[4], nums[5]),
                                              Vector3D(nums[6], nums[7], nums[8]))
{
}

/**
 * Constructor with 2D-array
 * @param nums
 */
Matrix3D::Matrix3D(double nums[3][3]) : Matrix3D(Vector3D(nums[0]),
                                                 Vector3D(nums[1]),
                                                 Vector3D(nums[2]))
{
}

/**
 * Constructor with 3 vectors
 * @param vec1
 * @param vec2
 * @param vec3
 */
Matrix3D::Matrix3D(Vector3D vec1, Vector3D vec2, Vector3D vec3)
{
    _matrix = {vec1, vec2, vec3};
}

/**
 * Copy constructor
 * @param mat
 */
Matrix3D::Matrix3D(const Matrix3D& mat) : Matrix3D(Vector3D(mat.row(0)),
                                                   Vector3D(mat.row(1)),
                                                   Vector3D(mat.row(2)))
{
}

// ---------------- Binary Operators ----------------
/**
 * Plus operator
 * @param rhs
 * @return
 */
Matrix3D Matrix3D::operator+(const Matrix3D& rhs) const
{
    return Matrix3D(row(0) + rhs.row(0), row(1) + rhs.row(1), row(2) + rhs.row(2));
}

/**
 * Minus operator
 * @param rhs
 * @return
 */
Matrix3D Matrix3D::operator-(const Matrix3D& rhs) const
{
    return Matrix3D(row(0) - rhs.row(0), row(1) - rhs.row(1), row(2) - rhs.row(2));
}

/**
 * Multiplication operator
 * @param rhs
 * @return
 */
Matrix3D Matrix3D::operator*(const Matrix3D& rhs) const
{
    Vector3D firstRow = Vector3D(this->row(0) * rhs.column(0), this->row(0) * rhs.column(1),
                                 this->row(0) * rhs.column(2));
    Vector3D secondRow = Vector3D(this->row(1) * rhs.column(0), this->row(1) * rhs.column(1),
                                  this->row(1) * rhs.column(2));
    Vector3D thirdRow = Vector3D(this->row(2) * rhs.column(0), this->row(2) * rhs.column(1),
                                 this->row(2) * rhs.column(2));
    return Matrix3D(firstRow, secondRow, thirdRow);
}

/**
 * Multiply by vector
 * @param rhs
 * @return
 */
Vector3D Matrix3D::operator*(const Vector3D& rhs) const
{
    return Vector3D(this->row(0) * rhs, this->row(1) * rhs, this->row(2) * rhs);
}

/**
 * Multiply increment
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator*=(const double rhs)
{
    for (int i = 0; i < _matrix.size(); ++i)
    {
        _matrix[i] = _matrix[i] * rhs;
    }

    return *this;
}

/**
 * Plus increment
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D& rhs)
{
    *this = *this + rhs;
    return *this;
}

/**
 * Minus decrement
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D& rhs)
{
    *this = *this - rhs;
    return *this;
}

/**
 * Multiply increment
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator*=(const Matrix3D& rhs)
{
    *this = *this * rhs;
    return *this;
}

/**
 * Divide decrement
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator/=(const double rhs)
{
    *this = *this * (1 / rhs);
    return *this;
}

// ---------------- Assignment Operator ----------------
/**
 * Assignment operator
 * @param rhs
 * @return
 */
Matrix3D& Matrix3D::operator=(const Matrix3D& rhs)
{
    _matrix = {rhs.row(0), rhs.row(1), rhs.row(2)};
    return *this;
}

// ---------------- IO Operators ----------------
/**
 * Print operator
 * @param output
 * @param mat
 * @return
 */
std::ostream& operator<<(std::ostream& output, const Matrix3D& mat)
{
    output << mat.row(0) << std::endl << mat.row(1) << std::endl << mat.row(2) << std::endl;
    return output;
}

/**
 * Input operator
 * @param input
 * @param mat
 * @return
 */
std::istream& operator>>(std::istream& input, Matrix3D& mat)
{
    int num1, num2, num3, num4, num5, num6, num7, num8, num9;
    input >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9;
    mat[0] = Vector3D(num1, num2, num3);
    mat[1] = Vector3D(num4, num5, num6);
    mat[2] = Vector3D(num7, num8, num9);
    return input;
}

// ---------------- Subscript Operator ----------------
/**
 * Write-access subscript
 * @param i
 * @return
 */
Vector3D& Matrix3D::operator[](short i)
{
    return this->_matrix[i];
}

/**
 * Read-access subscript
 * @param i
 * @return
 */
Vector3D Matrix3D::operator[](short i) const
{
    return this->row(i);
}

// ---------------- Extra Functions ----------------
/**
 * get Matrix row
 * @param num
 * @return
 */
Vector3D Matrix3D::row(short num) const
{
    return _matrix[num];
}

/**
 * get Matrix column
 * @param num
 * @return
 */
Vector3D Matrix3D::column(short num) const
{
    return Vector3D(_matrix[0][num], _matrix[1][num], _matrix[2][num]);
}

/**
 * Calculate trace
 * @return
 */
double Matrix3D::trace() const
{
    return this->row(0)[0] + this->row(1)[1] + this->row(2)[2];
}

/**
 * Calculate determinant
 * @return
 */
double Matrix3D::determinant() const
{
    return this->row(0)[0] * (this->row(1)[1] * this->row(2)[2] -
    this->row(1)[2] * this->row(2)[1]) - row(0)[1] * (this->row(1)[0] * this->row(2)[2] -
    this->row(1)[2] * this->row(2)[0]) + row(0)[2] * (this->row(1)[0] * this->row(2)[1] -
    this->row(1)[1] * this->row(2)[0]);
}