#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cmath>

using namespace std;

int aoti(char *str, int n) {
    if (n == 1) {
        return str[n - 1] - '0';
    }
    // 递归的问题都是可以用数学地推公式表达的 
    // 对于这个问题 f(n) = 10 * f(n -1) + digit(n)
    // 就是说长度n的字符串的值，等于长度n-1的值乘10加上当前第n位的值
    return 10 * aoti(str, n - 1) + (str[n -1] - '0') ;
}

int main() {
    // string str = "abcdef";
    char str[] = "12345678";
    cout << aoti(str, strlen(str));
    
}