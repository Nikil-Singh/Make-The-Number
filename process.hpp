#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define NONE -1
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4
#define STRINGIFY 5

//Converts string of a number into a vector.
vector<int> convertToVect(string num);

//Calculates all possible ways of getting the sum.
void calculate(vector<int> number, int sum);

//Updates the current sum.
int updateSum(int sum, int num, int operation);

//Prints out all the results stored in the vector.
void printVectorMatrix(vector<vector<int> > numbers);

//Generates power set for operations when number of operations is greater than
//number of numbers to operate on.
 vector<vector<int> > powerSet(vector<int> operations, int size);

string startProcess(int req, vector<int> numbers);
void process(int op, int req, int sum, int depth, vector<int> numbers, string expr, string tmp);