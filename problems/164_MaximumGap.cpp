#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual int maximumGap(vector<int>& nums) = 0;
}; 

class Solution_init : public Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;
        sort(nums.begin(), nums.end());
        int max_gap = nums[1] - nums[0];
        for (int i = 2; i < n; i++) max_gap = nums[i] - nums[i - 1] > max_gap ? nums[i] - nums[i - 1] : max_gap;
        return max_gap;
    }

private:
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

    solution = new Solution_init();
    cout << solution->maximumGap(nums) << endl;

    return 0;
}
