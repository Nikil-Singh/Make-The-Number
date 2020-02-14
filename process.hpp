#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NONE -1
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

// The number of solutions found.
extern int solutions;

// Converts string of a number into a vector.
vector<int> convertToVect(string num);

// Goes though every permutation of the arrangement of numbers to brute force
// calculate all possible sums.  
void startProcess(int req, vector<int> numbers);

// Recursively goes from number to number with applicable operations to create
// a sum.
void process(int op, int req, int sum, int depth, vector<int> numbers, string tmp);

// Converts an expression into an expression with required parenthesis, to meet
// BODMAS standards.
string addBrackets(string expression);

// Adds a debug mode for a fully formed expression to demonstate the actual
// calculation leading to the sum.
string debugExpression(string expression);