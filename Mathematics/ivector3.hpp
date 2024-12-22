#ifndef IVECTOR3_HPP
#define IVECTOR3_HPP

#include <cmath>

template <typename TType>
struct IVector3 {
    TType x;
    TType y;
    TType z;

    IVector3() : x(0), y(0), z(0) {}
    IVector3(TType x, TType y, TType z) : x(x), y(y), z(z) {}

    // Operator overloads
    IVector3 operator+(const IVector3& other) const;
    IVector3 operator-(const IVector3& other) const;
    IVector3 operator*(const IVector3& other) const;
    IVector3 operator/(const IVector3& other) const;
    bool operator==(const IVector3& other) const;
    bool operator!=(const IVector3& other) const;

    // Additional methods
    float length() const;
    IVector3<float> normalize() const;
    float dot(const IVector3& other) const;
    IVector3 cross(const IVector3& other) const;
};

#include "ivector3.cpp"

#endif