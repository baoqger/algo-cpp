#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minIndex(vector<int> arr, int s, int e) {
    int sml = INT32_MAX;
    int mindex;
    for (int i = s; i < e; i++) {
        if (arr[i] < sml) {
            sml = arr[i];
            mindex = i;
        }
    }
    return mindex;
}	

void fun2(vector<int> arr, int start_index, int end_index) {
    if (start_index >= end_index) {
        for (auto v : arr) {
            cout << v << " " ;
        }
        return;
    }
    int min_index;
    int temp;

    min_index = minIndex(arr, start_index, end_index);

    temp = arr[start_index];
    arr[start_index] = arr[min_index];
    arr[min_index] = temp;

    fun2(arr, start_index + 1, end_index);
}

int main() {
    // cout << "hello world" << endl;
    // int arr[] = {9, 4, 6, 5, 3, 1, 2};
    vector<int> arr = {9, 4, 6, 5, 3, 1, 2};
    // int size = sizeof(arr) / sizeof(arr[0]);
    int size = arr.size();
    // cout << size << endl;
    fun2(arr, 0, size);
}