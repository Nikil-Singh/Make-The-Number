#include "process.hpp"

//Converts string of a number into a vector.
vector<int> convertToVect(string num) {
    vector<int> number;
    for (int i = 0; i < num.length(); i++) {
        number.push_back(num[i] - '0');
    }
    return number;
}

//Calculates all possible ways of getting the sum.
void calculate(vector<int> number, int sum) {
    int newSum = 0;

    //Holds all valid solutions.
    vector<vector<int> > solutions;

    //Holds the temporary solution.
    vector<int> temp;

    //Initialises a string for holding all possible operations.
    if (number.size() > 4) {
    //If number of numbers is greater than number of operations (i.e. 4)

    } else {
    //If number of numbers is less than number of operations (i.e. 4)

    }

    //Performs required permutations for calculations.
    do {
        for (int i = 0; i < number.size(); i++) {
            if (i != number.size() - 1) {
                //newSum = updateSum(newSum, number[i], operation[i]);
                temp.push_back(number[i]);
                //temp.push_back(operation[i]);
            } else {
                temp.push_back(number[i]);
            }
        }
        if (newSum == sum) {
            solutions.push_back(temp);
        }
        temp.clear();
    } while (next_permutation(number.begin(), number.end()));

    //Prints out the final solution.
    printVectorMatrix(solutions);
}

//Updates the current sum.
int updateSum(int sum, int num, int operation) {
    if (operation == ADDITION) sum += num;
    if (operation == MULTIPLICATION) sum *= num;
    if (operation == SUBTRACTION && ((sum - num) < 0)) sum -= num;
    if (operation == DIVISION && ((sum % num) != 0)) sum /= num;
    return sum;
}

//Prints out all the results stored in the vector.
void printVectorMatrix(vector<vector<int> > numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            cout << numbers[i][j] << " ";
        }
        cout << "\n";
    }
}

//Generates power set for operations when number of operations is greater than
//number of numbers to operate on.
 vector<vector<int> > powerSet(vector<int> operation, int size) {
     vector<vector<int> > powerSet;
     vector<int> temp; //Temporarily holds operations.
     for (int i = 0; i < pow(operation.size(), 2); i++) {
         for (int j = 0; j < operation.size(); j++) {
             
         }
     }
     return powerSet;
 }



string startProcess(int req, vector<int> numbers) {
    string fullExpression;
    do {
         process(NONE, req, 0, 0, numbers, fullExpression, "");
    } while (next_permutation(numbers.begin(), numbers.end()));
    return fullExpression;
}

void process(int op, int req, int sum, int depth, vector<int> numbers, string expr, string tmp) {
    if (depth != 0) {
        if (op == DIVISION) {
            if (depth == numbers.size() - 1 && sum % numbers[depth] == 0) {
                sum = sum / numbers[depth];
                if (sum == req) {
                    tmp = tmp + " / " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size() && sum % numbers[depth] == 0) {
                tmp = tmp + " / " + to_string(numbers[depth]);
                sum = sum / numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, expr, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, expr, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, expr, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, expr, tmp);
            }
        } else if (op == MULTIPLICATION) {
            if (depth == numbers.size() - 1) {
                sum = sum * numbers[depth];
                if (sum == req) {
                    tmp = tmp + " * " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                tmp = tmp + " * " + to_string(numbers[depth]);
                sum = sum * numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, expr, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, expr, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, expr, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, expr, tmp);
            }
        } else if (op == ADDITION) {
            if (depth == numbers.size() - 1) {
                sum = sum + numbers[depth];
                if (sum == req) {
                    tmp = tmp + " + " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                tmp = tmp + " + " + to_string(numbers[depth]);
                sum = sum + numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, expr, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, expr, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, expr, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, expr, tmp);
            }
        } else if (op == SUBTRACTION) {
            if (depth == numbers.size() - 1) {
                sum = sum - numbers[depth];
                if (sum == req) {
                    tmp = tmp + " - " + to_string(numbers[depth]) + ",\n";
                    cout << tmp;
                }
            } else if (depth < numbers.size()) {
                tmp = tmp + " - " + to_string(numbers[depth]);
                sum = sum - numbers[depth];
                process(DIVISION, req, sum, depth + 1, numbers, expr, tmp);
                process(MULTIPLICATION, req, sum, depth + 1, numbers, expr, tmp);
                process(ADDITION, req, sum, depth + 1, numbers, expr, tmp);
                process(SUBTRACTION, req, sum, depth + 1, numbers, expr, tmp);
            }
        }
    } else {
        // Base Case.
        tmp = to_string(numbers[0]);
        process(DIVISION, req, numbers[0], 1, numbers, expr, tmp);
        process(MULTIPLICATION, req, numbers[0], 1, numbers, expr, tmp);
        process(ADDITION, req, numbers[0], 1, numbers, expr, tmp);
        process(SUBTRACTION, req, numbers[0], 1, numbers, expr, tmp);
    }
}