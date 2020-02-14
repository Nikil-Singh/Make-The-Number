#include "process.hpp"

//Converts string of a number into a vector.
vector<int> convertToVect(string num) {
    vector<int> number;
    for (int i = 0; i < num.length(); i++) {
        number.push_back(num[i] - '0');
    }
    return number;
}

// Goes though every permutation of the arrangement of numbers to brute force
// calculate all possible sums. 
void startProcess(int req, vector<int> numbers) {
    do {
         process(NONE, req, 0, 0, numbers, "");
    } while (next_permutation(numbers.begin(), numbers.end()));
}

// Recursively goes from number to number with applicable operations to create
// a sum.
void process(int op, int req, int sum, int depth, vector<int> numbers, string tmp) {
    // If depth is not 0, then we can calculate the sum.
    if (depth != 0) {
        if (op == DIVISION) {
            // If operation is division, we check if division results in no remainder.
            // If depth is equivalent to position of last number, we check operation
            // is compatible and if sum is met, then print out result.
            if (depth == numbers.size() - 1 && sum % numbers[depth] == 0) {
                sum = sum / numbers[depth];
                if (sum == req) {
                    tmp = tmp + " / " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size() && sum % numbers[depth] == 0) {
                // Concatenates to string the operation, and calls other functions to
                // perform required computation.
                tmp = tmp + " / " + to_string(numbers[depth]);
                sum = sum / numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, tmp);
            }
        } else if (op == MULTIPLICATION) {
            // If operation is multiplication.
            // If depth is equivalent to position of last number, we check operation
            // is compatible and if sum is met, then print out result.
            if (depth == numbers.size() - 1) {
                sum = sum * numbers[depth];
                if (sum == req) {
                    tmp = tmp + " * " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                // Concatenates to string the operation, and calls other functions to
                // perform required computation.
                tmp = tmp + " * " + to_string(numbers[depth]);
                sum = sum * numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, tmp);
            }
        } else if (op == ADDITION) {
            // If operation is addition.
            // If depth is equivalent to position of last number, we check operation
            // is compatible and if sum is met, then print out result.
            if (depth == numbers.size() - 1) {
                sum = sum + numbers[depth];
                if (sum == req) {
                    tmp = tmp + " + " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                // Concatenates to string the operation, and calls other functions to
                // perform required computation.
                tmp = tmp + " + " + to_string(numbers[depth]);
                sum = sum + numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, tmp);
            }
        } else if (op == SUBTRACTION) {
            // If operation is subtraction.
            // If depth is equivalent to position of last number, we check operation
            // is compatible and if sum is met, then print out result.
            if (depth == numbers.size() - 1) {
                sum = sum - numbers[depth];
                if (sum == req) {
                    tmp = tmp + " - " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                // Concatenates to string the operation, and calls other functions to
                // perform required computation.
                tmp = tmp + " - " + to_string(numbers[depth]);
                sum = sum - numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, tmp);
            }
        }
    } else {
        // Base Case, where it begins recursing through all numbers with different
        // operations.
        tmp = to_string(numbers[0]);
        process(DIVISION, req, numbers[0], 1, numbers, tmp);
        process(MULTIPLICATION, req, numbers[0], 1, numbers, tmp);
        process(ADDITION, req, numbers[0], 1, numbers, tmp);
        process(SUBTRACTION, req, numbers[0], 1, numbers, tmp);
    }
}