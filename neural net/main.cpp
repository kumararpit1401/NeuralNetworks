#include "neural_network.h"

int main() {
    NeuralNetwork net(2, 4, 0.1f);  // 2 inputs, 4 hidden neurons

    vector<pair<vector<float>, float>> dataset = {
        {{0, 0}, 0},
        {{0, 1}, 1},
        {{1, 0}, 1},
        {{1, 1}, 0}  // for XOR task
    };

    for (int epoch = 0; epoch < 50000; ++epoch) {
        float total_loss = 0;
        for (auto& pair : dataset) {
            vector<float>& x = pair.first;
            float y = pair.second;
            total_loss += net.train(x, y);
        }
        if (epoch % 1000 == 0)
            cout << "Epoch " << epoch << " | Loss: " << total_loss / dataset.size() << endl;
    }

    for (auto& pair : dataset) {
        vector<float>& x = pair.first;
        float y = pair.second;
        cout << "Input: [" << x[0] << ", " << x[1] << "] XOR Predicted: " << net.predict(x)
             << " (Expected: " << y << ")\n";
    }
}
