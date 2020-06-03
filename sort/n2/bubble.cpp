#include <iostream>

using namespace std;

void bubbleSort(int arr[9], int n) {
    for(int i = 0; i < n; i++) {
        bool flag = false; // 优化1: 如果没有数据交换，表示各个元素的排序已经完成，需要进行剩余的冒泡了
        for(int j = 0; j < n - i - 1; j++) { // 优化2: j的范围是n - i - 1, 每冒泡一轮，下一轮需要冒泡的元素范围就减1
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main() {
    int arr[9] = {2, 9, 0, 8, 4, 3, 40, 80, 34};
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n);
    for (auto v: arr) {
        cout << v << " ";
    }
}