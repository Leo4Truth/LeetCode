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
    // Greedy, we hope taht the sequence grows larger as slow as possible
    // so we hope that the last element of the ascending sequence is as small as possible
    // d[i] represents the smallest last element in ascending sequence with length i
    // len records the length of the ascending sequence length
    // d[i] is monotonically increasing
    // Time Complexity: O(NlogN)
    // Space Complexity: O(N)
    int lengthOfLIS_greedy_binary(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int len = 1;
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > d[len]) {
                len++;
                d[len] = nums[i];
            } else {
                // binary search d[1...len] to find the smallest
                int l = 1, r = len;
                int pos = 0; // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (d[mid] < nums[i]) {
                        pos = mid; // d[1...mid] < nums[i], 所以从 pos + 1 = mid + 1 开始更新 d[pos + 1] = nums[i]
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        
        return len;
    }

    // dp
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    int lengthOfLIS_dp(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
                    max_len = dp[i] > max_len ? dp[i] : max_len;
                }
            }
        }
        
        return max_len;
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
    cout << solution.lengthOfLIS_greedy_binary(nums) << endl;
    
    return 0;
}
