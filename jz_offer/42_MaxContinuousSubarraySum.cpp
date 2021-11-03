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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int pre = 0;
        int maxAns = nums[0];
        for (int i = 0; i < n; i++) {
            pre = pre + nums[i] > nums[i] ? pre + nums[i] : nums[i];
            maxAns = pre > maxAns ? pre : maxAns;
        }
        return maxAns;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;

    //system("pause");
    return 0;
}
