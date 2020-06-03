#include <iostream>
#include <string>

using namespace std;

void printAllKLengthRec(char set[], string prefix, int k, int n) {
    // base condition 终止条件
    if (k == 0) {
        cout << prefix << endl;
        return;
    } 
    // one by one add all characters from set  to prefix
    // for each character added, recursively call for k equal to k -1
    // 在for loop里调用了递归函数printAllKLengthRec,说明有n的子问题
    // set里的任意一个被选中后，子问题就变为：其他条件不变(set的size不变)，但是length从k变成k-1。
    // 因为需要遍历set的n个值, 所以就有n个子问题
    for (int i = 0; i < n ; i++ ) {
        string newPrefix;
        newPrefix = prefix + set[i];
        
        printAllKLengthRec(set, newPrefix, k - 1, n);
    }
}

void printAllKLength(char set[], int k, int n) {
    printAllKLengthRec(set, "", k, n);
}


int main() {
    cout << "hello world" << endl;
    cout << "First Test" << endl;
    char set1[] = {'a', 'b'};
    int k = 3;
    printAllKLength(set1, k, 2);
}