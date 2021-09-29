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
    int hammingWeight(uint32_t n) {
        uint32_t one = 1;
        int cnt = 0;
        while (n > 0) {
            cnt += (n & one);
            n = n >> 1;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    uint32_t n;
    cin >> n;

    Solution solution;
    cout << solution.hammingWeight(n) << endl;

    //system("pause");
    return 0;
}
