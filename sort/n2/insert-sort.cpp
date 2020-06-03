#include <iostream>

using namespace std;

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] > value) {
                arr[j + 1] = arr[j]; 
            } else {
                break; // current j value is the target index(after it) need insert element
            }
        }
        arr[j + 1] = value; // j + 1 means insert the element after it
    }

}

int main() {
    int arr[9] = {2, 9, 0, 8, 4, 3, 40, 80, 34};
    int n = sizeof(arr)/sizeof(arr[0]); 
    insertSort(arr, n);
    for (auto v: arr) {
        cout << v << " ";
    }
}