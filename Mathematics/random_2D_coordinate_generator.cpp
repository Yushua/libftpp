#include "random_2D_coordinate_generator.hpp"

long long Random2DCoordinateGenerator::seed() const {
    return seedValue;
}

long long Random2DCoordinateGenerator::operator()(const long long& x, const long long& y) const {
    long long n = x + y * 57 + seedValue;
    n = (n << 13) ^ n;
    return (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff;
}