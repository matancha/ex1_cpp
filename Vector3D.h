#ifndef EX1_CPP_VECTOR3D_H
#define EX1_CPP_VECTOR3D_H

#include <iostream>

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

    /* Plus operator */
    Vector3D operator+(const Vector3D& rhs) const;
    /* Minus operator */
    Vector3D operator-(const Vector3D& rhs) const;
    /* Increment plus operator */
    Vector3D& operator+=(const Vector3D& rhs);
    /* Decrement minus operator */
    Vector3D& operator-=(const Vector3D& rhs);
    /* Increment by number operator */
    Vector3D& operator+=(double rhs);
    /* Decrement by number operator */
    Vector3D& operator-=(double rhs);
    /* Multiply by number */
    Vector3D operator*(double rhs) const;
    /* Divide by number */
    Vector3D operator/(double rhs) const;
    /* Multiply by number */
    friend Vector3D operator*(double lhs, Vector3D& rhs);
    /* Multiply increment by number */
    Vector3D& operator*=(double rhs);
    /* Divide increment by number */
    Vector3D& operator/=(double rhs);
    /* Calculate distance between vectors */
    double operator|(const Vector3D& rhs) const;
    /* Calculate scalar product */
    double operator*(const Vector3D& rhs) const;
    /* Calculate angle between vectors */
    double operator^(const Vector3D& rhs) const;
    /* Multiply vector by -1 */
    Vector3D operator-() const;
    /* Assign vector */
    Vector3D& operator=(const Vector3D& rhs);
    /* Print vector */
    friend std::ostream& operator<<(std::ostream& output, const Vector3D& vec);
    /* Get vector from input */
    friend std::istream& operator>>(std::istream& input, Vector3D& vec);
    /* Write-access to row */
    double& operator[](int i);
    /* Read-access to row */
    double operator[](int i) const;

    /* Calculate norm */
    double norm() const;
    /* Calculate distance between vectors */
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
