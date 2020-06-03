#include <iostream>

using namespace std;

void findAllSequences(int diff, char* out, int start, int end) {
    // We can't cover difference of more than n with 2n bits 
    if (abs(diff) > (end - start + 1) / 2) 
        return; 
    // base case
    if (start > end) {
        if (diff == 0) {
            cout << out << endl;
        }
    }
    // child case 1
    out[start] = '1' , out[end] = '1';
    findAllSequences(diff, out, start + 1, end - 1);

    // child case 2
    out[start] = '1', out[end] = '0';
    findAllSequences(diff + 1, out, start + 1, end - 1);

    // child case 3
    out[start] = '0', out[end] = '0';
    findAllSequences(diff, out, start + 1, end - 1);
    // child case 4
    out[start] = '0', out[end] = '1';
    findAllSequences(diff - 1, out, start + 1, end - 1);
}
int main() {
    const int n = 4;
    char out[2*n + 1];
    out[2*n] = '\0';
    findAllSequences(0, out, 0, 2*n - 1);

}