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
    // count
    // the idea is similar to prefix
    // count(nums, bound) calculates the number of subarrays whose max element is at most bound
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        if (n == 0) return 0;
        return count(nums, right) - count(nums, left - 1);
    }

    int count(vector<int>& nums, int bound) {
        int res = 0, cur = 0;
        for (int num : nums) {
            cur = num <= bound ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    if (n == 0) cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    int left, right;
    cin >> left >> right;

    Solution solution;
    cout << solution.numSubarrayBoundedMax(nums, left, right) << endl;

    //system("pause");
    return 0;
}
