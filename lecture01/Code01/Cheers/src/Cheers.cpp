#include <iostream>
#include "console.h"
using namespace std;

/* This code doesn't compile because the function cheer() is referenced before it's
 * declared. You can fix this either by
 *
 *   1. Reordering these functions, or
 *   2. Introducing a forward declaration.
 */

int main() {
    cheer(3);
    return 0;
}

void cheer(int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        cout << "Hip hip, hooray!" << endl;
    }
}
