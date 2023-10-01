#include <iostream>
using namespace std;

// without vector.h

class c_vector
{
private:
    int *arr; // elements
    int _size; // idk how to write about ?
    int _capacity; // holds max size of array

public:
    //int size();     // gets current size of array ( with elements )
    //int cap(); // gets max capacity of array
    //bool is_empty();// check if array is empty ?
    //int at(index);  // gets the element at the given index
    //void push(item); // push given element at the end of array
    //void insert(index, elem); // insert element at the index & shift all O(N)
    //void prepend(item); // prepend add element at the begining O(N)
    //void pop(); // remove the last element
    //void fdelete(index); // delete item at index, shifting all trailing elements left
    //void remove(item); //  looks for value and removes index holding it (even if in multiple places) O(N)
    //void find(item); //  looks for value and returns first index with that value, -1 if not found
    //void resize(new_cap); // resize to a length

    // constructor
    c_vector() : _size(0), _capacity(16) {
      arr = new int[_capacity];
    }

    int pop() {
      int pvar = arr[_size];
      arr[_size] = 0;
      _size--;

      return pvar;
    }

    int index(int elem) {
      for (int p=0; p<=_size; p++) {
        if (*(arr +p) == elem) {
          return p;
        }
      }

      return -1;
    }

    void prepend(int elem) {
      insert(0, elem);
    }

    void del(int index) {
      // finish in one shot :)

      if (index <= _capacity) {
        for (int p=0; p<= _size; p++) {
          // satisfies:
          // O(1) to add/remove at end (amortized for allocations for more space), index, or update
          if (p >= index) {
            // form target index
            arr[p] = arr[p+1];
          }
        }

        _size--;
      }
    }

    void remove(int elem) {
      // remove the element from the array
      // even in multiple locations

      // feels like a little long way?
      for (int p=0; p <= _size; p++) {
        if (*(arr + p) == elem) {
          this->del(p);
        }
      }
    }

    void insert(int index, int elem) {
      // if array is small resize it to fit the shifting
      if (index > _capacity) {
        resize(index+1);
      }

      if (index < _size) {
        for (int p=_capacity; p>=index; p--) {
          arr[p+1] = arr[p];
        }

        arr[index] = elem;
        _size++;
      
      } else {
        arr[index] = elem;
        _size = index+1;
      }
    }

    int at(int index) {
      // check 
      if (index <= _size) {
        return arr[index];
      } else {
        return -1;
      }
    }

    void push(int element) {
      // push element to the last index
      // requires to resize if out of _capacity
      // O(1) when size is store in (size)
      // O(n) when size is not stored

      if (_size == _capacity) {
        resize(2*_capacity);
      }
      
      // std::cout << "SIZE: " << _size << std::endl;
      arr[_size] = element;
      _size++;
    }

    void resize(int new_cap) {
      if (new_cap < _size) {
        std::cout << "less that size?" << endl;
      }

      int* new_elem = new int[new_cap];

      // copy all the elements to the new array
      for (int i=0; i< _size; i++) {
        new_elem[i] = arr[i];
      }

      // delete the previous array
      delete[] arr;

      // set the new resized array 
      arr = new_elem;
      _capacity = new_cap;
    }

    void stdout() {
      std::cout << "---" << std::endl;
      for (int p=0; p<_size; p++) {
        std::cout << p << "\t|\t" << *(arr + p) << std::endl;
      }
    }

    int size() {
      return _size;
    }
    int capacity() {
      return _capacity;
    }

    void afree() {
      delete [] arr;
    }
};

int main() {
  c_vector na;
  na.push(1);
  na.push(2);
  na.push(3);
  na.push(3);
  na.prepend(30);
  std::cout << na.pop() << std::endl;
  // | 0 | 1 | 2 | 3 | 4 |
  // | - | - | - | - | - |
  // | 1 | 2 | 3 | 0 | 0 |
  //               ^   ^
  //            _size  |
  //                _capacity

  // _capacity: current max capacity of the array
  // _size: a pointer to the aaaaaaaaaaaa!
  //        - when array is created all values are set to 0
  //        - so entire is useless so _size is 0
  //        - when values ex: push(3) index 0 is set to 3 
  //          and _size points to next index i.e 1
  //        - also when index(40, 1) index 40 is set to 1 
  //          and _size points to next index i.e 40
  //    Now i still dont what to say ? fk it
  na.stdout();
  na.insert(1, 3);
  na.stdout();
  // na.insert(14, 3);
  // na.stdout();

  // resize test
  // na.insert(21, 3);
  // na.stdout();

  // delete() test

  // remove() test
  // na.remove(3);
  // na.stdout();
  //
  // find() test
  
  int TARGET = 30;
  std::cout << TARGET << " found at index: " << na.index(TARGET) << std::endl;
  na.afree();
}
