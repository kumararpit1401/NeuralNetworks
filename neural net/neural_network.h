#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "VectorUtils.h"
#include "MatrixUtils.h"
#include "activations.h"

using namespace std;
using namespace VectorUtils;
using namespace MatrixUtils;
using namespace Activations;

class NeuralNetwork {
private:
    int input_size;
    int hidden_size;
    float learning_rate;

    // Weights and biases
    Matrix W1;  // Input → Hidden
    vector<float> b1;

    Matrix W2;  // Hidden → Output
    float b2;

    // Cached forward values (for backprop)
    vector<float> z1, a1, z2, a2;

public:
    NeuralNetwork(int input_sz, int hidden_sz, float lr = 0.01f)
        : input_size(input_sz), hidden_size(hidden_sz), learning_rate(lr) {

        srand(time(0));

        // Initialize W1 (hidden_size x input_size)
        W1 = Matrix(hidden_size, vector<float>(input_size));
        for (auto& row : W1)
            for (float& val : row)
                val = ((float) rand() / RAND_MAX) * 2 - 1;

        // Initialize b1
        b1 = vector<float>(hidden_size, 0.0f);

        // Initialize W2 (1 x hidden_size)
        W2 = Matrix(1, vector<float>(hidden_size));
        for (float& val : W2[0])
            val = ((float) rand() / RAND_MAX) * 2 - 1;

        b2 = 0.0f;
    }

    // Step 1: Forward Propagation
    float forward(const vector<float>& x) {
        // z1 = W1 * x + b1
        z1 = add(mat_vec_mul(W1, x), b1);

        // a1 = relu(z1) now tanh
        a1 = apply(z1, tanh_activate); // new


        // z2 = W2 * a1 + b2
        z2 = { dot(W2[0], a1) + b2 };

        // a2 = sigmoid(z2)
        a2 = { sigmoid(z2[0]) };

        return a2[0];
    }
        // Step 2: Binary Cross-Entropy Loss
    float compute_loss(float predicted, float actual) {
        return - (actual * log(predicted + 1e-8f) + (1 - actual) * log(1 - predicted + 1e-8f));
    }

    // Step 3: Backward Propagation and Update
    void backward(const vector<float>& x, float y_true) {
        // dLoss/da2
        float da2 = -(y_true / (a2[0] + 1e-8f)) + (1 - y_true) / (1 - a2[0] + 1e-8f);

        // da2/dz2 = sigmoid'(z2)
        float dz2 = da2 * sigmoid_derivative_from_output(a2[0]);


        // dz2/dW2 = a1
        for (int j = 0; j < hidden_size; ++j) {
            W2[0][j] -= learning_rate * dz2 * a1[j];
        }

        b2 -= learning_rate * dz2;

        // dz2/da1 = W2, da1/dz1 = relu'(z1) now tanh'
        vector<float> dz1(hidden_size);
        for (int j = 0; j < hidden_size; ++j) {
            dz1[j] = dz2 * W2[0][j] * tanh_derivative(z1[j]); // new

        }

        // dz1/dW1 = x
        for (int i = 0; i < hidden_size; ++i) {
            for (int j = 0; j < input_size; ++j) {
                W1[i][j] -= learning_rate * dz1[i] * x[j];
            }
            b1[i] -= learning_rate * dz1[i];
        }
    }

    // Step 4: Train on one data point
    float train(const vector<float>& x, float y_true) {
        float pred = forward(x);
        float loss = compute_loss(pred, y_true);
        backward(x, y_true);
        return loss;
    }

    // Step 5: Predict (0 or 1)
    int predict(const vector<float>& x) {
        return forward(x) > 0.5 ? 1 : 0;
    }
};
#endif // NEURAL_NETWORK_H
