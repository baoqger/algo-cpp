#include <iostream>

using namespace std;

int result[8]; 

void printQueens(int result[]) {
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 8; ++column) {
            if (result[row] == column) {
                cout << "Q "; 
            } else {
                cout << "* ";
            }
        } 
        cout << "\n";  
    }
    cout << "\n";
}

bool isOk(int row, int column) {
    int leftup = column - 1, rightup = column + 1;
    for (int i = row - 1; i >= 0; i--) {
        if (result[i] == column) { 
            return false;
        }
        if (leftup >= 0) {
            if (result[i] == leftup) return false;
        }
        if (rightup < 8) {
            if (result[i] == rightup) return false;
        }
        --leftup, ++rightup;
    }
    return true;
} 

void cal8queens(int row) {
    if (row == 8) {
        printQueens(result);
        return;
    }
    for (int column = 0; column < 8; ++column) {
        if (isOk(row, column)) {
            result[row] = column;
            cal8queens(row + 1);
        }
    }
}

int main () {
    cout << "start 8 queens";
    cal8queens(0);
}