// Write a C function that takes an integer array 
// and its length as parameters, 
// and returns the sum of all the elements in the array 
// using pointer arithmetic.

#include <iostream>

int func(int *arr, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main() {
    using namespace std;
    int arr[] = {1, 2, 3, 4};
    int arr_size = sizeof(arr) / sizeof(int);
    cout << func(arr, arr_size) << endl;
    return 0;
}
