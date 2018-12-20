#ifndef EX1_CPP_VECTOR3D_H
#define EX1_CPP_VECTOR3D_H

#include <iostream>

/**
 * Class representing a 3D matrix
 */
class Vector3D
{
public:
   /**
    * default constructor
    */
    Vector3D();
    /**
     * 3 doubles constructor
     * @param x
     * @param y
     * @param z
     */
    Vector3D(double x, double y, double z);
    /**
     * Double array constructor
     * @param numArr
     */
    Vector3D(double numArr[3]);
    /**
     * Copy constructor
     * @param old_vec
     */
    Vector3D(const Vector3D &old_vec);

    /**
     * Plus operator
     * @param rhs
     * @return
     */
    Vector3D operator+(const Vector3D& rhs) const;
    /**
     * Minus operator
     * @param rhs
     * @return
     */
    Vector3D operator-(const Vector3D& rhs) const;
    /**
     * Increment plus operator
     * @param rhs
     * @return
     */
    Vector3D& operator+=(const Vector3D& rhs);
    /**
     * Decrement minus operator
     * @param rhs
     * @return
     */
    Vector3D& operator-=(const Vector3D& rhs);
    /**
     * Increment by number operator
     * @param rhs
     * @return
     */
    Vector3D& operator+=(double rhs);
    /**
     * Decrement by number operator
     * @param rhs
     * @return
     */
    Vector3D& operator-=(double rhs);
    /**
     * Multiply by number
     * @param rhs
     * @return
     */
    Vector3D operator*(double rhs) const;
    /**
     * Divide by number
     * @param rhs
     * @return
     */
    Vector3D operator/(double rhs) const;
    /**
     * Multiply by number
     * @param lhs
     * @param rhs
     * @return
     */
    friend Vector3D operator*(double lhs, Vector3D& rhs);
    /**
     * Multiply increment by number
     * @param rhs
     * @return
     */
    Vector3D& operator*=(double rhs);
    /**
     * Divide increment by number
     * @param rhs
     * @return
     */
    Vector3D& operator/=(double rhs);
    /**
     * Calculate distance between vectors
     * @param rhs
     * @return
     */
    double operator|(const Vector3D& rhs) const;
    /**
     * Calculate scalar product
     * @param rhs
     * @return
     */
    double operator*(const Vector3D& rhs) const;
    /**
     * Calculate angle between vectors
     * @param rhs
     * @return
     */
    double operator^(const Vector3D& rhs) const;
    /**
     * Multiply vector by -1
     * @return
     */
    Vector3D operator-() const;
    /**
     * Assign vector
     * @param rhs
     * @return
     */
    Vector3D& operator=(const Vector3D& rhs);
    /**
     * Print vector
     * @param output
     * @param vec
     * @return
     */
    friend std::ostream& operator<<(std::ostream& output, const Vector3D& vec);
    /**
     * Get vector from input
     * @param input
     * @param vec
     * @return
     */
    friend std::istream& operator>>(std::istream& input, Vector3D& vec);
    /**
     * Write-access to row
     * @param i
     * @return
     */
    double& operator[](int i);
    /**
     * Read-access to row
     * @param i
     * @return
     */
    double operator[](int i) const;

    /**
     * Calculate norm
     * @return
     */
    double norm() const;
    /**
     * Calculate distance between vectors
     * @param vec
     * @return
     */
    double dist(const Vector3D& vec) const;

private:
    /* X coordinate */
    double _x;
    /* Y coordinate */
    double _y;
    /* Z coordinate */
    double _z;
};

#endif //EX1_CPP_VECTOR3D_H
