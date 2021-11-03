#include <iostream>
#include <vector>

using namespace std;

class Solution213 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n -1));
    }

    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
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

    Solution213 solution;
    cout << solution.rob(nums) << endl;

    //system("pause");
    return 0;
}
