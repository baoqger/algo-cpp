#include <iostream>

using namespace std;

void swap(int arr[], int i , int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, end);
    return i + 1;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int q = partition(arr, start, end);
        quickSort(arr, start, q - 1);
        quickSort(arr, q + 1, end);
    }
}

int main() {
    int arr[9] = {2, 9, 0, 8, 4, 3, 40, 80, 34};
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSort(arr, 0, n - 1);
    for (auto v: arr) {
        cout << v << " ";
    }
}