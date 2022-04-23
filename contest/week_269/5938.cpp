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
    virtual vector<int> targetIndices(vector<int>& nums, int target) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int less = 0;
        int equal = 0;
        for (auto num : nums) {
            less += num < target;
            equal += num == target;
        }
        vector<int> res;
        for (int i = 0; i < equal; i++) res.push_back(less + i);
        return res;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int target = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    vector<int> res = solution->targetIndices(nums, target);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
