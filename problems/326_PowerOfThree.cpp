#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 1162261467 = 3^19 is the largest power of 3 within the range of 32-bit signed integers
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }

    bool isPowerOfThree_logn(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;

    Solution solution;
    cout << solution.isPowerOfThree(n) << endl;
    
    return 0;
}
