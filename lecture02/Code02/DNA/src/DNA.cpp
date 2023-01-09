/* File: DNA.cpp
 *
 * A program for exploring DNA strands.
 */
#include <iostream>
#include <string>
#include <algorithm> // For swap
#include "simpio.h"
#include "strlib.h"  // For toUpperCase
#include "console.h"
using namespace std;

char pairsWith(char one, char two) {
    /* Cute little trick: sort the characters so that one <= two.
     * That means that we only need to check two possible pairs.
     */
    if (one >= two) swap(one, two);

    return (one == 'A' && two == 'T') ||
           (one == 'C' && two == 'G');
}

/* Given two DNA strands, returns whether they're complements of one another. */
bool areComplementary(string one, string two) {
    /* Base Case 1: If both strings are empty, then they're complements. */
    if (one == "" && two == "") {
        return true;
    }
    /* Base Case 2: If exactly one string is empty and the other isn't, then they
     * aren't complements.
     *
     * Question to ponder: why does this statement, which just says "at least one
     * string is empty," mean "exactly one string is empty?"
     */
    else if (one == "" || one == "") {
        return false;
    }
    /* Base Case 3: If the first characters don't pair, then the strings aren't
     * complements.
     */
    else if (!pairsWith(one[0], two[0])) {
        return false;
    }
    /* Recursive Case: The first characters match, so we complement one another if
     * our remaining characters complement each other.
     */
    else {
        return areComplementary(one.substr(1), two.substr(1));
    }

    /* Question to ponder: What happens if we replace Base Case 3 and the Recursive Case,
     * collectively, with the following?
     *
     *     return pairsWith(one[0], two[0]) && areComplementary(one.substr(1), two.substr(1));
     *
     * Or, what about this?
     *
     *     return areComplementary(one.substr(1), two.substr(1)) && pairsWith(one[0], two[0]);
     */
}

int main() {
    while (true) {
        string first  = toUpperCase(getLine("The first strand: "));
        string second = toUpperCase(getLine("And the next one: "));

        /* Question to ponder: How would you change the above lines of code to validate that
         * the input indeed consists purely of A, C, G, and T?
         */

        if (areComplementary(first, second)) {
            cout << "You have found your genetic soul mate!" << endl;
        } else {
            cout << "There's plenty of fish in the gene pool." << endl;
        }

        cout << endl;
    }
}

