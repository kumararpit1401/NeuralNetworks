#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Perceptron {
private:
    vector<float> weights;
    float bias;
    float learning_rate;

public:
    Perceptron(int input_size, float lr = 0.1) {
        learning_rate = lr;
        weights.resize(input_size);
        bias = 0.0f;

        // Initialize weights randomly between -1 and 1
        srand(time(0));
        for (int i = 0; i < input_size; ++i) {
            weights[i] = ((float) rand() / RAND_MAX) * 2 - 1;
        }
    }

    int predict(const vector<int>& inputs) {
        float sum = bias;
        for (int i = 0; i < inputs.size(); ++i) {
            sum += inputs[i] * weights[i];
        }
        return sum >= 0 ? 1 : 0; // Step activation
    }

    void train(const vector<vector<int>>& X, const vector<int>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (int i = 0; i < X.size(); ++i) {
                int prediction = predict(X[i]);
                int error = y[i] - prediction;

                // Update weights and bias
                for (int j = 0; j < weights.size(); ++j) {
                    weights[j] += learning_rate * error * X[i][j];
                }
                bias += learning_rate * error;
            }
        }
    }
};

int main() {
    // AND Gate Inputs and Outputs
    vector<vector<int>> X = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<int> y = {0, 0, 0, 1};

    Perceptron p(2);  // 2 input features
    p.train(X, y, 100);  // Train for 100 epochs

    cout << "Trained Perceptron on AND Gate:\n";
    for (int i = 0; i < X.size(); ++i) {
        cout << X[i][0] << " AND " << X[i][1] << " = " << p.predict(X[i]) << endl;
    }

    vector<vector<int>> Z = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<int> w = {0, 1, 1, 0};

    Perceptron q(2);  // 2 input features
    p.train(Z, w, 1000);  // Train for 1000 epochs

    cout << "Trained Perceptron on XOR Gate:\n";
    for (int i = 0; i < X.size(); ++i) {
        cout << Z[i][0] << " XOR " << Z[i][1] << " = " << q.predict(Z[i]) << endl;
    }
    // fails for XOR
    return 0;
}
