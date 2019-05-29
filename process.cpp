#include "process.hpp"

//Converts string of a number into a vector.
vector<int> convertToVect(string num) {
    vector<int> number;
    for (int i = 0; i < num.length(); i++) {
        number.push_back(num[i] - '0');
        if (i != num.length() - 1) number.push_back('+');
    }
    return number;
}

//Calculates all possible ways of getting the sum.
void calculate(vector<int> number, int sum) {
    vector<vector<int> > solutions(1, vector<int>(number.size()));
}

//Updates the current sum.
int updateSum(int sum, int num, int operation) {
    if (operation == '+') sum += num;
    if (operation == '*') sum *= num;
    if (operation == '-' && ((sum - num) < 0)) sum -= num;
    if (operation == '/' && ((sum % num) != 0)) sum /= num;
    return sum;
}

//Prints out all the results stored in the vector.
void printVectorMatrix(vector<vector<int> > numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            cout << numbers[i][j];
        }
    }
}
