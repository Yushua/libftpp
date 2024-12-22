#ifndef RANDOM_2D_COORDINATE_GENERATOR_HPP
#define RANDOM_2D_COORDINATE_GENERATOR_HPP

class Random2DCoordinateGenerator {
private:
    long long seedValue;

public:
    Random2DCoordinateGenerator(long long seed = 0) : seedValue(seed) {}

    long long seed() const;
    long long operator()(const long long& x, const long long& y) const;
};

#endif