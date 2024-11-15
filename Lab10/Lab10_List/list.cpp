#include <iostream>
#include "list.hpp"

using std::cout; using std::endl;

void output(double *colPtr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << colPtr[i] << " ";
    }
    cout << endl;
}


int check(double *colPtr, double number, int size) {
    for (int i = 0; i < size; ++i) {
        if (colPtr[i] == number) {
            return i;
        }
    }
    return -1;
}

void addNumber(double *&colPtr, double number, int &size) {
    if (check(colPtr, number, size) != -1) {
        cout << "duplicate!" << endl;
        return;
    }

    double *newArray = new double[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = colPtr[i];
    }
    newArray[size] = number;

    delete[] colPtr;
    colPtr = newArray;
    ++size;
}

void removeNumber(double *&colPtr, double number, int &size) {
    int index = check(colPtr, number, size);
    if (index == -1) {
        cout << "not present!" << endl;
        return;
    }

    double *newArray = new double[size - 1];
    bool found = false;

    for (int i = 0, j = 0; i < size; ++i) {
        if (colPtr[i] == number) {
            found = true;
        } else {
            newArray[j] = colPtr[i];
            ++j;
        }
    }

    delete[] colPtr;
    colPtr = newArray;
    --size;
}
