#include <iostream>
#include <unordered_set> 

using namespace std;


void printPairs(int arr[], int arr_size, int target) {
    unordered_set <int> s;

    for (int i = 0; i < arr_size; i++) {
        int temp = target - arr[i];
        if (s.find(temp) != s.end()) {
            cout << arr[i] << " , " << temp << endl; 
        }
        s.insert(arr[i]);
    }
}

int main() {
    cout << "2 - sum" << endl;

    int arr[] = { 1, 4, 45, 6, 10, -8, 2, 14 }; 

    int target = 16;

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printPairs(arr, arr_size, target);
}