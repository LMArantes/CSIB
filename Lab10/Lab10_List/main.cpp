#include "list.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {
    int size = 0;  // initial size of the list
    double *numbers = new double[size]; // allocate an empty dynamic array

    char operation;
    double number;

    while (true) {
        cout << "enter operation [a/r/q] and number: ";
        cin >> operation;

        if (operation == 'q') {
            break; // quit
        }

        cin >> number; // get the number after the operation

        if (operation == 'a') {
            addNumber(numbers, number, size);
        } else if (operation == 'r') {
            removeNumber(numbers, number, size);
        } else {
            cout << "Invalid operation!" << endl;
            continue;
        }

        cout << "your numbers: ";
        output(numbers, size);
    }

    delete[] numbers; // deallocate the array
    return 0;
}
