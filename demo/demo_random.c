/*  ----------------------------------------------------------------------------
    File: demo_random.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include <trilobite/xutil/random.h>
#include <stdint.h>
#include <math.h>

// Perceptron model parameters
double weights[2] = {0.0, 0.0};
double learning_rate = 0.1;

// Training data
typedef struct {
    int input1;
    int input2;
    int label;
} TrainingExample;

TrainingExample training_data[] = {
    {0, 0, 0},
    {0, 1, 0},
    {1, 0, 0},
    {1, 1, 1},
};

// Perceptron model prediction
int predict(int input1, int input2) {
    double sum = weights[0] * input1 + weights[1] * input2;
    return (sum > 0) ? 1 : 0;
}

// Perceptron model training
void train_perceptron() {
    for (size_t epoch = 0; epoch < 1000; ++epoch) {
        for (size_t i = 0; i < sizeof(training_data) / sizeof(TrainingExample); ++i) {
            int prediction = predict(training_data[i].input1, training_data[i].input2);
            int error = training_data[i].label - prediction;

            weights[0] += learning_rate * error * training_data[i].input1;
            weights[1] += learning_rate * error * training_data[i].input2;
        }
    }
}

// Main program
int main() {
    // Initialize random seed
    random_seed(42);

    // Train the perceptron model
    train_perceptron();

    // Test the trained model
    printf("Prediction for (0, 0): %d\n", predict(0, 0));
    printf("Prediction for (0, 1): %d\n", predict(0, 1));
    printf("Prediction for (1, 0): %d\n", predict(1, 0));
    printf("Prediction for (1, 1): %d\n", predict(1, 1));

    return 0;
} // end of func
