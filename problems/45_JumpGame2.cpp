#include <iostream>
#include <vector>

using namespace std;

class Solution45 {
public:
    // backtracking, work but exceed time limit
    int jump(vector<int>& nums) {
        return jump_base(nums, 0, 0);
    }

    int jump_base(vector<int>& nums, int pos, int step) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return 0;
        if (pos + nums[pos] >= nums.size() - 1) return step + 1;
        int minSteps = INT_MAX;
        for (int i = nums[pos]; i >= 1; i--) {
            int steps = jump_base(nums, pos + i, step + 1);
            if (steps < minSteps) minSteps = steps;
        }
        return minSteps;
    }

    // Greedy on the max pos the next step can reach with its max step (not greedy on the max pos the current step can reach)
    int jump_greedy(vector<int>& nums) {
        int pos = 0;
        int steps = 0;
        while (pos < nums.size() - 1) {
            int nextStep = 1;
            int maxDis = 0;
            for (int i = nums[pos]; i >= 1; i--) {
                if (pos + i >= nums.size() - 1) return steps + 1;
                if (pos + i + nums[pos + i] > maxDis) {
                    maxDis = pos + i + nums[pos + i];
                    nextStep = i;
                }
            }
            pos += nextStep;
            steps++;
        }
        return steps;
    }
};

int main45() {
    Solution45 solution;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << solution.jump(nums) << endl;
    system("pause");
    return 0;
}