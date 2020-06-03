#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n -1 ; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[9] = {2, 9, 0, 8, 4, 3, 40, 80, 34};
    int n = sizeof(arr)/sizeof(arr[0]); 
    selectionSort(arr, n);
    for (auto v: arr) {
        cout << v << " ";
    }
}