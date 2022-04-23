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
    virtual int minStartValue(vector<int>& nums) = 0;
};

class Solution_presum_optimized : public Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int sum = 0;
        int min = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            min = sum < min ? sum : min;
        }

        return min == 0 ? 1 : 1 - min;
    }
};

class Solution_presum : public Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0] > 0 ? 1 : 1 - nums[0];

        vector<int> presum(1, nums[0]);
        int min = presum[0] < 0 ? presum[0] : 0;
        for (int i = 1; i < n; i++) {
            presum.push_back(presum[i - 1] + nums[i]);
            min = presum[i] < min ? presum[i] : min;
        }

        return min == 0 ? 1 : 1 - min;
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

    Solution *solution = nullptr;

    solution = new Solution_presum();
    cout << "presum:           " << solution->minStartValue(nums) << endl;

    solution = new Solution_presum_optimized();
    cout << "presum optimized: " << solution->minStartValue(nums) << endl;
    
    return 0;
}
