// VectorUtils.h
#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include <vector>
#include <iostream>
#include <stdexcept>

namespace VectorUtils {

    float dot(const std::vector<float>& a, const std::vector<float>& b);

    std::vector<float> add(const std::vector<float>& a, const std::vector<float>& b);

    std::vector<float> subtract(const std::vector<float>& a, const std::vector<float>& b);

    std::vector<float> scalar_multiply(const std::vector<float>& a, float scalar);

    void print_vector(const std::vector<float>& v);
}

#endif // VECTOR_UTILS_H
