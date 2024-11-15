// list.cpp
// Implementation of functions for managing list of doubles

#include <iostream>
#include "list.hpp"

using std::cout; using std::endl;

// Prints the values in array pointed to by "colPtr" of "size"
void output(double *colPtr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << colPtr[i] << " ";
    }
    cout << endl;
}

// Returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// If number is not in the array, returns -1
int check(double *colPtr, double number, int size) {
    for (int i = 0; i < size; ++i) {
        if (colPtr[i] == number) {
            return i;
        }
    }
    return -1; // number not found
}
