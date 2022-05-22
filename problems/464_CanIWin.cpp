#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual bool canIWin(int maxChoosableInteger, int desiredTotal) = 0;
};

/**
 * @brief 
 * Time Complexity: O(2^N * N)
 * Space Complexity: O(2^N)
 */
class Solution_MemorizeSearchWithStatusCompact : public Solution {
public:
    unordered_map<int, bool> memo;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger) / 2 < desiredTotal) {
            return false;
        }
        return dfs(maxChoosableInteger, 0, desiredTotal, 0);
    }

    bool dfs(int maxChoosableInteger, int usedNumbers, int desiredTotal, int currentTotal) {
        if (!memo.count(usedNumbers)) {
            bool res = false;
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (((usedNumbers >> i) & 1) == 0) {
                    if (i + 1 + currentTotal >= desiredTotal) {
                        res = true;
                        break;
                    }
                    if (!dfs(maxChoosableInteger, usedNumbers | (1 << i), desiredTotal, currentTotal + i + 1)) {
                        res = true;
                        break;
                    }
                }
            }
            memo[usedNumbers] = res;
        }
        return memo[usedNumbers];
    }
};

int main(int argc, char* argv[]) {
    int maxChoosableInteger = argc >= 2 ? stoi(argv[1]) : 0;
    int desiredTotal = argc >= 3 ? stoi(argv[2]) : 0;

    Solution *solution = nullptr;

    solution = new Solution_MemorizeSearchWithStatusCompact();
    cout << solution->canIWin(maxChoosableInteger, desiredTotal) << endl;

    return 0;
}
