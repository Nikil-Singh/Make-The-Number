#include <iostream>
#include "check.hpp"
using namespace std;

//Checks if string contains only numbers.
int checkNum(string num) {
    int valid = -1;
    for (int i = 0; i < num.length(); i++) {
        if (!isdigit(num[i])) valid = num[i]; break;
    }
    return valid;
}

//Checks if number is positive.
int checkNumPositive(int num) {
    if (num >= 0) { return true; return false;}
}
