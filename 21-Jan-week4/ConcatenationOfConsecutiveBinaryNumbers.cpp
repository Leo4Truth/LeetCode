#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    const int MOD = 1000000007;

    // Time: O(NlogN), Space: O(N)
    int concatenatedBinary_binaryString(int n) {
        long result = 0;
        for (int i = 1; i <= n; i++) {
            // use a int array to represent the binary
            int length = (int)log2(i) + 1;
            int binary[length];
            int temp = i;
            // keep divide 2 and put into the binary array
            for (int index = length - 1; index >= 0; index--) {
                binary[index] = (temp % 2 == 0 ? 0 : 1);
                temp /= 2;
            }
            // append the value to the result
            for (int j = 0; j < length; j++) {
                result = (result * 2 + binary[j]) % MOD;
            }
        }
        return result;
    }

    int concatenatedBinary_math(int n) {
        int length = 0;   // bit length of addends
        long result = 0;  // long accumulator
        for (int i = 1; i <= n; i++) {
            // when meets power of 2, increase the bit length
            if (ceil(log2(i)) == floor(log2(i))) {
                length++;
            }
            result = ((result * (int)pow(2, length)) + i) % MOD;
        }
        return result;
    }

    int concatenatedBinary_math_bitwise_op(int n) {
        int length = 0;   // bit length of addends
        long result = 0;  // long accumulator
        for (int i = 1; i <= n; i++) {
            // when meets power of 2, increase the bit length
            if ((i & (i - 1)) == 0) {
                length++;
            }
            result = ((result << length) | i) % MOD;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 3;

    Solution solution;
    cout << solution.concatenatedBinary_binaryString(n) << endl;

    //system("pause");
    return 0;
}
