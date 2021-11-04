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
    // dp[i][j] the minSum of the nums[0...i] split into j parts
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));
        vector<int> prefixSum;
        int sum = 0;
        prefixSum.push_back(0);
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefixSum[i] - prefixSum[k]));
                }
            }
        }
        return dp[n][m];
    }
};

int main(int argc, char* argv[]) {
    int n, m;
    vector<int> nums;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    Solution solution;
    cout << solution.splitArray(nums, m) << endl;;
    
    return 0;
}
