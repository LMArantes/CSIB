#include "list.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    int size = 5;  // setting list array size
    double *a = new double[size]; // allocating dynamic array

    // initializing array
    a[0] = 0.0; a[1] = 10.0; a[2] = 20.0; a[3] = 30.0; a[4] = 40.0;

    output(a, size); // printing out the array

    // asking user to input a number
    cout << "Input number to find in the list: ";
    double number;
    cin >> number;

    // checking if the input number is in the list
    int index = check(a, number, size);
    if (index == -1)
        cout << "The number is not in the array" << endl;
    else
        cout << "The number is at position " << index << endl;

    delete [] a; // deallocating the array
}
