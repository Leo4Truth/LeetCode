#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * @Problem 
 * A binary string is monotone increasing if it consists of some number of 0's (possibly none), 
 * followed by some number of 1's (also possibly none).
 * You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
 * Return the minimum number of flips to make s monotone increasing.
 */
class Solution {
public:
    /**
     * dp[n] = dp[n-1],                              if s[n] == '1' 
     *       = min(countOneUntil(n-1), dp[n-1] + 1), if s[n] == '0'
     *            flip all one before,  flip
     */
    int minFlipsMonoIncr_dp(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return 0;
        int one = 0;
        int flip = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') one++;
            else if (s[i] == '0') flip++;
            flip = min(one, flip);
        }
        return flip;
    }

    int minFlipsMonoIncr_prefixSum(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return 0;
        vector<int> p(n + 1, 0);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + (int)(s[i] - '0');
        int minOps = INT32_MAX;
        for (int i = 0; i <= n; i++) minOps = min(minOps, p[i] + n - i - (p[n] - p[i]));
        return minOps; 
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.minFlipsMonoIncr_dp(s) << endl;

    //system("pause");
    return 0;
}
