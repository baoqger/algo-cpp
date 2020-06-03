#include <iostream>

using namespace std;

int minIndex(int arr[], int s, int e) {
    int sml = INT32_MAX;
    int mindex;
    for (int i = s; i < e; i++) {
        if (arr[i] > sml) {
            sml = arr[i];
            mindex = i;
        }
    }
    return mindex;
}	

void fun2(int arr[], int start_index, int end_index) {
    if (start_index >= end_index) {
        cout << arr;
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

int main (){
    cout << "hello"; 
    int arr[] = {9, 1, 3, 4 ,5, 30, 43, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size;
    fun2(arr, 0, size);
    return 0;
}
