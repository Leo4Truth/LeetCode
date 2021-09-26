#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    // a:     11101101010101
    // b:     01101010101101
    // a & b: 01101010101101
    // c:     11010101011010
    // a ^ b: 10000111111000 异或, 0 ^ 0 = 0, 1 ^ 1 = 0, 0 ^ 1 = 1, 1 ^ 0 = 1
    // a = a ^ b
    // b = c = (a & b) << 1
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};

int main(int argc, char* argv[]) {
    int a = argc >= 2 ? stoi(argv[1]) : 0;
    int b = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.getSum(a, b) << endl;
    
    return 0;
}
