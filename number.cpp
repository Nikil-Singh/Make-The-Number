#include <iostream>
#include <string>
#include "check.hpp"
#include "process.hpp"

using namespace std;
int solutions = 0;
int main() {
    string num, sum;

    // Beginning text explaining purpose of program.
    cout << "This program takes any number of positive digits and attempts to have them\n";
    cout << "evaluate to a certain positive number. E.g. For 1234 and 10, a possible\n";
    cout << "solution is 1 + 2 + 3 + 4 = 10. The available operations are +, -, *, /.\n";

    // Gets numbers to be used for calculation and checks its validity.
    cout << "Enter numbers to be used: ";
    cin >> num;
    char j = checkNum(num);
    if (j != -1) { cout << j << " is not a valid number.\n"; return 0;}

    // Gets the sum number and checks its validity.
    cout << "Enter sum to be reached: ";
    cin >> sum;
    j = checkNum(sum);
    if (j != -1) { cout << j << " is not a valid number.\n"; return 0;}

    // Gets the requried number string in the appropriate formats for calculations.
    vector<int> number = convertToVect(num);
    int finalSum = stoi(sum);

    startProcess(finalSum, number);
    cout << "Number of Solutions: " << solutions << "\n";
    return 0;
}
