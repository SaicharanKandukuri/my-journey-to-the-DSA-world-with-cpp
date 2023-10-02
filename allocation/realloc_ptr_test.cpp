#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdlib.h>

int main() {
  using namespace std;
  int *ar = (int*) malloc(3*sizeof(int));
//  int *ar2 = (int*) realloc(ar, 4*sizeof(int));
  ar[0] = 2;
  ar = (int*) realloc(ar, 400000*sizeof(int));
  ar[100] = 3;

  cout << ar[0] << endl;
  cout << ar[100] << endl; 
  return 0;
}

// malloc & realloc return addresses
//  The realloc() function changes the size of the memory block pointed to by ptr to size bytes.  The  con‐
//  tents  will be unchanged in the range from the start of the region up to the minimum of the old and new
//  sizes.  If the new size is larger than the old size, the added memory will not be initialized. 
//
//  So it returns adresses but dosent set the pointer
//  to previous variable..
//

