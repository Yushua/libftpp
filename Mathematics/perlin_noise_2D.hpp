#ifndef PERLIN_NOISE_2D_HPP
#define PERLIN_NOISE_2D_HPP

#include <cmath>
#include <vector>

class PerlinNoise2D {
private:
    std::vector<int> permutation;

    static float fade(float t);
    static float lerp(float t, float a, float b);
    static float grad(int hash, float x, float y);

public:
    PerlinNoise2D();
    float sample(float x, float y) const;
};

#endif