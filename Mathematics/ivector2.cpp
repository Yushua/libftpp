#ifndef IVECTOR2_CPP
#define IVECTOR2_CPP

#include "ivector2.hpp"

template <typename TType>
IVector2<TType> IVector2<TType>::operator+(const IVector2& other) const {
    return IVector2(x + other.x, y + other.y);
}

template <typename TType>
IVector2<TType> IVector2<TType>::operator-(const IVector2& other) const {
    return IVector2(x - other.x, y - other.y);
}

template <typename TType>
IVector2<TType> IVector2<TType>::operator*(const IVector2& other) const {
    return IVector2(x * other.x, y * other.y);
}

template <typename TType>
IVector2<TType> IVector2<TType>::operator/(const IVector2& other) const {
    return IVector2(x / other.x, y / other.y);
}

template <typename TType>
bool IVector2<TType>::operator==(const IVector2& other) const {
    return x == other.x && y == other.y;
}

template <typename TType>
bool IVector2<TType>::operator!=(const IVector2& other) const {
    return !(*this == other);
}

template <typename TType>
float IVector2<TType>::length() const {
    return std::sqrt(x * x + y * y);
}

template <typename TType>
IVector2<float> IVector2<TType>::normalize() const {
    float len = length();
    return IVector2<float>(x / len, y / len);
}

template <typename TType>
float IVector2<TType>::dot(const IVector2& other) const {
    return x * other.x + y * other.y;
}

template <typename TType>
IVector2<TType> IVector2<TType>::cross() const {
    return IVector2(-y, x);
}

#endif