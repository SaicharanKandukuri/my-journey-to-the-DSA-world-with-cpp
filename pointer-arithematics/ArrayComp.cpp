// Implement a function in C that takes two integer arrays 
// and their lengths as parameters.
// The function should return 1 if the arrays are equal
// (i.e., contain the same elements in the same order), 
// and 0 otherwise.Use pointer arithmetic to compare the arrays.

#include <iostream>
using namespace std;

bool isArrayEqual( int *arr_a, int *arr_b, int length ) {
    for (int i = 0; i < length; ++i) {
        cout << *(arr_a + i) << "|" << *(arr_a + i) << endl;
        if (*(arr_a + i) != *(arr_b + i)) {
            return false;
        }
    }

    return true;
}

int main () {
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};
    int len = sizeof(b) / sizeof(b[0]);

    if (isArrayEqual(a, b, len)) {
        cout << "Both are equal" << endl;
    } else {
        cout << "Not equal" << endl;
    }

    return 0;
}
