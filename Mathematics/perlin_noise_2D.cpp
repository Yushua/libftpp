#include "perlin_noise_2D.hpp"
#include <algorithm>
#include <numeric>
#include <random>

float PerlinNoise2D::fade(float t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

float PerlinNoise2D::lerp(float t, float a, float b) {
    return a + t * (b - a);
}

float PerlinNoise2D::grad(int hash, float x, float y) {
    int h = hash & 15;
    float u = h < 8 ? x : y;
    float v = h < 4 ? y : h == 12 || h == 14 ? x : 0;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

PerlinNoise2D::PerlinNoise2D() {
    permutation.resize(256);
    std::iota(permutation.begin(), permutation.end(), 0);

    std::default_random_engine engine(std::random_device{}());
    std::shuffle(permutation.begin(), permutation.end(), engine);

    permutation.insert(permutation.end(), permutation.begin(), permutation.end());
}

float PerlinNoise2D::sample(float x, float y) const {
    int X = static_cast<int>(std::floor(x)) & 255;
    int Y = static_cast<int>(std::floor(y)) & 255;

    x -= std::floor(x);
    y -= std::floor(y);

    float u = fade(x);
    float v = fade(y);

    int a = permutation[X] + Y;
    int aa = permutation[a];
    int ab = permutation[a + 1];
    int b = permutation[X + 1] + Y;
    int ba = permutation[b];
    int bb = permutation[b + 1];

    return lerp(v, lerp(u, grad(permutation[aa], x, y),
                        grad(permutation[ba], x - 1, y)),
                lerp(u, grad(permutation[ab], x, y - 1),
                     grad(permutation[bb], x - 1, y - 1)));
}