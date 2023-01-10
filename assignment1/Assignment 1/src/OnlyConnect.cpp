/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "Testing/OnlyConnectTests.h"
using namespace std;

string getConsonant (string , string);
bool checkVowel (char ch);

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
//    (void) phrase;
//    return "";
    return getConsonant(phrase, "");
}

bool checkVowel (char ch) {
    if (!isalpha(ch))
        return true;
    else
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

string getConsonant (string input, string output) {
    if (input == "")
        return output;
    else {
        input[0] = toupper(input[0]);
        if (checkVowel(input[0])) {
            input.erase(0, 1);;
        }
        else {
            string ch = input.substr(0, 1);
            input.erase(0, 1);
            output.append(ch);
        }
        return getConsonant(input, output);
    }
}




/* * * * * * Test Cases * * * * * */

ADD_TEST("Converts lower-case to upper-case.") {
    EXPECT(onlyConnectize("lowercase") == "LWRCS");
    EXPECT(onlyConnectize("uppercase") == "PPRCS");
}

ADD_TEST("Handles non-letter characters properly.") {
    EXPECT(onlyConnectize("2.718281828459045") == "");
    EXPECT(onlyConnectize("c") == "HMM");
}

ADD_TEST("Handles single-character inputs.") {
    EXPECT(onlyConnectize("A") == "");
    EXPECT(onlyConnectize("+") == "");
    EXPECT(onlyConnectize("Q") == "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






