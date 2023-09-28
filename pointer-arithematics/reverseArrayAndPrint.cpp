// write a C function to reverse the elementts
// of an array **in-place**. Use Pointer arithemetic
// to perform the array reversal.

// Basically pointer arithematic is *(arr + whatever) => value
// Doing *arr basically demposed array to its first element
#include <iostream>
using namespace std;

void reverseArrayAndPrint(int *arr, int length)
{
    // idea: Create a for loop may be?
    // after watching solution we can do swapping with for loop 
    // correction (while loop)

    int *s_arr = arr;
    // this basically points to 1st element
    int *e_arr = arr + length - 1;
    // this point to last element (-1 cause its array zero-indexed)

    while (s_arr < e_arr) {
        int temp = *s_arr;
        *s_arr = *e_arr;
        *e_arr = temp;

        ++s_arr;
        --e_arr;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int length = sizeof(arr) / sizeof(arr[0]);
    reverseArrayAndPrint(arr, length);

    for (int i = 0; i < length; ++i) {
        cout << *(arr + i) << ", ";
    }

    cout << endl;
}
