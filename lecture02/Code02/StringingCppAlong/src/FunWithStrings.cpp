/* File: FunWithStrings.cpp
 *
 * A program for playing around with C++ strings!
 */
#include <iostream>
#include <string>
#include "simpio.h"
#include "console.h"
using namespace std;

string reverseOf(string input);

int main() {
    while (true) {
        string text = getLine("Enter some text: ");
        cout << "Behold, it is now \"" << reverseOf(text) << ".\"" << endl << endl;
    }
}

string reverseOf(string input) {
    /* Good question to ponder: why not set the base case to be strings of length one? */
    if (input == "") {
        return "";
    }
    /* Otherwise, move the first character to the end and reverse what's left. */
    else {
        return reverseOf(input.substr(1)) + input[0];
    }
}
