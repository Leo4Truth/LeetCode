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
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = word1[0] == word2[0];
        for (int i = 1; i < m; i++) dp[i][0] = word1[i] == word2[0] ? 1 : dp[i - 1][0];
        for (int j = 1; j < n; j++) dp[0][j] = word1[0] == word2[j] ? 1 : dp[0][j - 1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return m + n - dp[m - 1][n - 1] * 2;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;
    cout << solution.minDistance(s1, s2) << endl;

    return 0;
}
