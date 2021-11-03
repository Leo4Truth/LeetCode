#include <iostream>
#include <vector>

using namespace std;

class Solution198 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], dp[i + 2] + nums[i]);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int next, nextNext;
        nextNext = 0;
        next = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int current = max(next, nextNext + nums[i]);
            nextNext = next;
            next = current;
        }
        return next;
    }
};

int main(int argc, char* argv[]) {
    int n;
    vector<int> nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution198 solution;
    cout << solution.rob(nums) << endl;

    //system("pause");
    return 0;
}
