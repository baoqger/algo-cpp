#include <iostream>
#include <string>
#include <vector>

using namespace std;

int step(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return step(n -1) + step(n -2);
}
int main() {
    // cout << "before testFunc" << endl;
    cout << step(10);
    // cout << "after testFunc" << endl;
}