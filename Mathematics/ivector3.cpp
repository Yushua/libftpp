#ifndef IVECTOR3_CPP
#define IVECTOR3_CPP

#include "ivector3.hpp"

template <typename TType>
IVector3<TType> IVector3<TType>::operator+(const IVector3& other) const {
    return IVector3(x + other.x, y + other.y, z + other.z);
}

template <typename TType>
IVector3<TType> IVector3<TType>::operator-(const IVector3& other) const {
    return IVector3(x - other.x, y - other.y, z - other.z);
}

template <typename TType>
IVector3<TType> IVector3<TType>::operator*(const IVector3& other) const {
    return IVector3(x * other.x, y * other.y, z * other.z);
}

template <typename TType>
IVector3<TType> IVector3<TType>::operator/(const IVector3& other) const {
    return IVector3(x / other.x, y / other.y, z / other.z);
}

template <typename TType>
bool IVector3<TType>::operator==(const IVector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

template <typename TType>
bool IVector3<TType>::operator!=(const IVector3& other) const {
    return !(*this == other);
}

template <typename TType>
float IVector3<TType>::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

template <typename TType>
IVector3<float> IVector3<TType>::normalize() const {
    float len = length();
    return IVector3<float>(x / len, y / len, z / len);
}

template <typename TType>
float IVector3<TType>::dot(const IVector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

template <typename TType>
IVector3<TType> IVector3<TType>::cross(const IVector3& other) const {
    return IVector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

#endif