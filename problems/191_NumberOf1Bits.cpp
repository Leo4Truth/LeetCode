#include <iostream>
#include <vector>

using namespace std;

class Solution191 {
public:
    int hammingWeight_1(uint32_t n) {
        int bits = 0;
        int mask = 1;
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            mask <<= 1;
        }
        return bits;
    }

    int hammingWeight_2(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    uint32_t n = 0100000011;

    Solution191 solution;
    cout << solution.hammingWeight_1(n) << endl;

    //system("pause");
    return 0;
}
