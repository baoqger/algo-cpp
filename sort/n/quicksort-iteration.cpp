#include <iostream>
#include <vector>

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

void quickSortByIteration(int arr[], int start, int end) {
    vector<int> stack;
    stack.push_back(start);
    stack.push_back(end);
    while (stack.size() > 0) {
        end = stack.back();
        stack.pop_back();
        start = stack.back();
        stack.pop_back();

        int p = partition(arr, start, end);

        if (start < p - 1) {
            stack.push_back(start);
            stack.push_back(p - 1);
        }
        if (p + 1 < end) {
            stack.push_back(p + 1);
            stack.push_back(end);
        }
    }
}

int main() {
    int arr[9] = {2, 9, 0, 8, 4, 3, 40, 80, 34};
    int n = sizeof(arr)/sizeof(arr[0]); 
    quickSortByIteration(arr, 0, n - 1);
    for (auto v: arr) {
        cout << v << " ";
    }
}