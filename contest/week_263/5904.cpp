#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define DEBUG

using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        int max = INT32_MIN;
        int max_cnt = 0;
        vector<int> current;
        dfs(nums, 0, 1, max, max_cnt, current, true);

        return max_cnt;
    }

private:
    void dfs(vector<int>& nums, int i, int val, int& max, int& max_cnt, vector<int>& current, bool empty) {
        int n = nums.size();
        if (i == n) {
            if (val > max) {
                max = val;
                max_cnt = 1;
            } else if (val == max) {
                max_cnt++;
            }
            return;
        }
        // recursive two branches:
        // 1. with nums[i]
        // 2. without nums[i]
        current.push_back(nums[i]);
        // if with nums[i], whether nums[i] is the first element we take
        if (empty) dfs(nums, i + 1, nums[i], max, max_cnt, current, false);
        else dfs(nums, i + 1, val | nums[i], max, max_cnt, current, false);
        current.pop_back();
        dfs(nums, i + 1, val, max, max_cnt, current, empty);
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

    cout << (3 | 1) << endl;

    Solution solution;
    cout << solution.countMaxOrSubsets(nums) << endl;
    
    return 0;
}
