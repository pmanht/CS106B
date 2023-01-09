/* File: DigitalDigits.cpp
 *
 * A program that explores properties of digits of
 * numbers!
 */
#include <iostream>
#include "simpio.h"
#include "console.h"
using namespace std;

int sumOfDigitsOf(int n);
int digitalRootOf(int n);

int main() {
    int n = getInteger("Please provide only the finest of numbers: ");
    
    cout << "Its digit sum is " << sumOfDigitsOf(n) << endl;
    cout << "Its digital root is " << digitalRootOf(n) << endl;
    
    return 0;
}

int sumOfDigitsOf(int n) {
    /* Base case: Any single-digit number has a digit sum equal to itself. */
    if (n < 10) {
        return n;
    }
    /* Otherwise, sum all but the last digit, then add in the last digit. */
    else {
        return sumOfDigitsOf(n / 10) + (n % 10);
    }
}

int digitalRootOf(int n) {
    /* Keep summing the digits of n until we're down to a single digit. */
    while (n >= 10) {
        n = sumOfDigitsOf(n);
    }
    return n;
}
