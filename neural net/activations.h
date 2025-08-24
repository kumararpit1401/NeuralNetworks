#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include <vector>
#include <cmath>

namespace Activations {
    inline float sigmoid(float x) {
        return 1.0f / (1.0f + std::exp(-x));
    }

    // inline float sigmoid_derivative(float x) {
    //     float sig = sigmoid(x);
    //     return sig * (1.0f - sig);
    // }

    inline float sigmoid_derivative_from_output(float sig) {
    return sig * (1.0f - sig);
    }

    inline float relu(float x) {
        return x > 0 ? x : 0;
    }

    inline float relu_derivative(float x) {
        return x > 0 ? 1.0f : 0.0f;
    }

    inline float tanh_activate(float x) {
        return std::tanh(x);
    }

    inline float tanh_derivative(float x) {
        float t = std::tanh(x);
        return 1.0f - t * t;
    }

    inline std::vector<float> apply(const std::vector<float>& vec, float (*func)(float)) {
        std::vector<float> result(vec.size());
        for (size_t i = 0; i < vec.size(); ++i) {
            result[i] = func(vec[i]);
        }
        return result;
    }
}

#endif
