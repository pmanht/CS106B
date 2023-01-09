/* File: Factorials.cpp
 *
 * A program that computes n!.
 */

#include <iostream>
#include "console.h"
using namespace std;

int factorial(int n);

int main() {
    int n = factorial(5);
    cout << "5! = " << n << endl;
    return 0;
}

int factorial(int n) {
    /* Base case: 0! = 1. */
    if (n == 0) {
        return 1;
    }
    /* Recursive case: n! = n * (n - 1)! */
    else {
        return n * factorial(n - 1);
    }
}
