#include <iostream>
#include <vector>

using namespace std;

class Solution55 {
public:
    // Greedy on the max pos the next step can reach with its max step (not greedy on the max pos the current step can reach)
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return true;
        if (nums.size() == 2) return nums[0] >= 1 ? true : false;
        int pos = 0;
        while (pos < nums.size() - 1) {
            if (nums[pos] == 0) return false;
            int nextStep = 1;
            int maxDis = 0;
            for (int i = nums[pos]; i >= 1; i--) {
                if (pos + i >= nums.size() - 1) return true;
                if (pos + i + nums[pos + i] > maxDis) {
                    maxDis = pos + i + nums[pos + i];
                    nextStep = i;
                }
            }
            pos += nextStep;
        }
        return true;
    }
};

int main55() {
    Solution55 solution;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << solution.canJump(nums) << endl;
    system("pause");
    return 0;
}