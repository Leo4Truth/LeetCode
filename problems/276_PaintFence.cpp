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
    // dp
    // bottom-up, constant space
    int numWays_dp_bottom_up(int n, int k) {
        if (n == 1) return k;
        if (n == 2) return k * k;

        int twoPostWays = k;
        int onePostWays = k * k;
        int ways = (k - 1) * (twoPostWays + onePostWays);
        int nn = 3;
        while (nn < n) {
            twoPostWays = onePostWays;
            onePostWays = ways;
            ways = (k - 1) * (twoPostWays + onePostWays);
            nn++;
        }
        
        return ways;
    }

    // dp
    // bottom-up, iterative, known as tabulation
    int numWays_dp_bottom_up(int n, int k) {
        if (i == 1) return k;
        if (i == 2) return k * k;

        int totalWays[] = new int[n + 1];
        totalWays[1] = k;
        totalWays[2] = k * k;
        
        for (int i = 3; i <= n; i++) {
            totalWays[i] = (k - 1) * (totalWays[i - 1] + totalWays[i - 2]);
        }
        
        return totalWays[n];
    }

    // dp
    // top-down + recursion + memoization
    // k colors
    // 1. different color as one previous post: a b c (k - 1 possible c not b)
    //                     i-th
    //    totalWays(i) = (k - 1) * totalWays(i - 1)
    // 2. same color as one previous post, then two previous post must be dfferent from one post color: a b b (k - 1 possible b not a)
    //                  i-th   (i-1)-th
    //    totalWays(i) = 1   * (k - 1)  *  totalWays(i - 2)
    int numWays_dp_top_down(int n, int k) {
        unordered_map<int, int> memo;
        return totalWays(n, k, memo);
    }

    int totalWays(int i, int k, unordered_map<int, int>& memo) {
        if (i == 1) return k;
        if (i == 2) return k * k;
        if (memo.count(i)) return memo[i];
        memo[i] = (k - 1) * (totalWays(i - 1, k) + totalWays(i - 2, k));
        return memo[i];
    }

    // Time Limit Exceeded
    // dfs, optimize condition when n == 2
    int numWays_dfs(int n, int k) {
        if (n == 2) return k * k;
        vector<int> fence(n, 0);
        int count = 0;
        dfs(fence, 0, 0, k, count);
        return count;
    }

    // len: current length of the consective color
    void dfs(vector<int>& fence, int curr, int len, int k, int& count) {
        if (curr == fence.size()) {
            count++;
            return;
        }

        for (int c = 0; c < k; c++) {
            if (curr > 0 && fence[curr - 1] == c && len == 2) continue;
            fence[curr] = c;
            if (curr > 0 && fence[curr] == fence[curr - 1]) dfs(fence, curr + 1, 2, k, count);
            else dfs(fence, curr + 1, 1, k, count);
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;

    Solution solution;
    cout << solution.numWays(n, k) << endl;

    //system("pause");
    return 0;
}
