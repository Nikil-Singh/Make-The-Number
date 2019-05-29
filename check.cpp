#include "check.hpp"

//Checks if string contains only numbers.
int checkNum(string num) {
    int valid = -1;
    for (int i = 0; i < num.length(); i++) {
        if (!isdigit(num[i])) valid = num[i]; break;
    }
    return valid;
}
