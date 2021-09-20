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
    /**
     * @brief find number of Longest Increament Subsequence
     *        dynamic programming
     * 
     * @param nums 
     * @return int 
     */
    int findNumberOfLIS_dp(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 0); // nums[0...i] longest increment subsequence length
        vector<int> cnt(n, 0); // // nums[0...i] longest increment subsequenc count
        int max_len = 0;
        int max_len_cnt = 0;

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_len_cnt = cnt[i];
            } else if (dp[i] == max_len) {
                max_len_cnt += cnt[i];
            }
        }

        return max_len_cnt;
    }

    /**
     * @brief find number of Longest Increament Subsequence
     *        greedy + prefix sum + binary search
     * @todo understand, complete leetcode problem 300. Longest Increasing Subsequence
     * @param nums 
     * @return int 
     */
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<vector<int>> d, cnt;
        for (int v : nums) {
            int i = binarySearch(d.size(), [&](int i) { return d[i].back() >= v; });
            int c = 1;
            if (i > 0) {
                int k = binarySearch(d[i - 1].size(), [&](int k) { return d[i - 1][k] < v; });
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size()) {
                d.push_back({v});
                cnt.push_back({0, c});
            } else {
                d[i].push_back(v);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }

private:
    /**
     * @brief binary search
     * 
     * @param n
     * @param f binary search compare function
     * @return int 
     */
    int binarySearch(int n, function<bool(int)> f) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution solution;
    cout << solution.findNumberOfLIS(nums) << endl;
    
    return 0;
}
