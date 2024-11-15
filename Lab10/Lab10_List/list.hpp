// Functions to manipulate list of doubles
// Mikhail Nesterenko
// 11/2/2020

#ifndef LIST_HPP
#define LIST_HPP

// Prints the values in array "colPtr" of "size"
void output(double *colPtr, int size);

// Returns the index of the element in array "colPtr" of "size"
// that corresponds to the element holding "number"
// If number is not in the array, returns -1
int check(double *colPtr, double number, int size);

// Adds "number" to the array pointed to by "colPtr" of "size".
// If the number is already there, does nothing.
// Note, the size of the array is thus increased.
void addNumber(double *& colPtr, double number, int &size);

// Removes "number" from the array "colPtr" of "size".
// If "number" is not there, does nothing.
// Note, "size" changes.
void removeNumber(double *& colPtr, double number, int &size);

#endif // LIST_HPP
