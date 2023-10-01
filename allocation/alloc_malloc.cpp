#include <iostream>
#include <stdlib.h>

int main(void) {
  int *arr = malloc(sizeof(int));
  if (arr == NULL) {
    return -1;
  }

  std::cout << sizeof(arr) << std::endl;
  free(arr);
}
