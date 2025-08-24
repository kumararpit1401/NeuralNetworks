// VectorUtils.cpp
#include "VectorUtils.h"

namespace VectorUtils {

    float dot(const std::vector<float>& a, const std::vector<float>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vectors must be of the same length.");
        }
        float result = 0.0;
        for (size_t i = 0; i < a.size(); ++i) {
            result += a[i] * b[i];
        }
        return result;
    }

    std::vector<float> add(const std::vector<float>& a, const std::vector<float>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vectors must be of the same length.");
        }
        std::vector<float> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }

    std::vector<float> subtract(const std::vector<float>& a, const std::vector<float>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vectors must be of the same length.");
        }
        std::vector<float> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] - b[i];
        }
        return result;
    }

    std::vector<float> scalar_multiply(const std::vector<float>& a, float scalar) {
        std::vector<float> result(a.size());
        for (size_t i = 0; i < a.size(); ++i) {
            result[i] = a[i] * scalar;
        }
        return result;
    }

    void print_vector(const std::vector<float>& v) {
        for (float val : v)
            std::cout << val << " ";
        std::cout << std::endl;
    }

}
