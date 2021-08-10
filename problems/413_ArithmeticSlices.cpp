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
    int numberOfArithmeticSlices_const_dp_21_08_10(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int dp = 0;
        int sum = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp++;
                sum += dp;
            }
            else dp = 0;
        }    
        return sum;
    }

    int numberOfArithmeticSlices_dp(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;

        vector<int> dp(n, 0);
        int sum = 0;
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[i] = dp[i - 1] + 1;
                sum += dp[i];
            }
        }    
        return sum;
    }

    int numberOfArithmeticSlices_const_dp(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;

        int dp = 0;
        int sum = 0;
        for (int i = 2; i < n; i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp++;
                sum += dp;
            }
            else dp = 0;
        }    
        return sum;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    Solution solution;
    cout << solution.numberOfArithmeticSlices_const_dp(A) << endl;

    //system("pause");
    return 0;
}

