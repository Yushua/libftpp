#ifndef PERLIN_NOISE_2D_HPP
#define PERLIN_NOISE_2D_HPP

#include <cmath>
#include <random>

class PerlinNoise2D {
private:
    int permutation[256];

    static float fade(float t);
    static float lerp(float t, float a, float b);
    static float grad(int hash, float x, float y);

public:
    PerlinNoise2D();
    float sample(float x, float y) const;
};

#endif