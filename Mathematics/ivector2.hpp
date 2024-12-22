#ifndef IVECTOR2_HPP
#define IVECTOR2_HPP

#include <cmath>

template <typename TType>
struct IVector2 {
    TType x;
    TType y;

    IVector2() : x(0), y(0) {}
    IVector2(TType x, TType y) : x(x), y(y) {}

    // Operator overloads
    IVector2 operator+(const IVector2& other) const;
    IVector2 operator-(const IVector2& other) const;
    IVector2 operator*(const IVector2& other) const;
    IVector2 operator/(const IVector2& other) const;
    bool operator==(const IVector2& other) const;
    bool operator!=(const IVector2& other) const;

    // Additional methods
    float length() const;
    IVector2<float> normalize() const;
    float dot(const IVector2& other) const;
    IVector2 cross() const;
};

#include "ivector2.cpp"

#endif