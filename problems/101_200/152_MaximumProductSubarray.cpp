#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution152 {
public:
    int max(int a, int b, int c) {
        int tmp = a > b ? a : b;
        return tmp > c ? tmp : c;
    }

    int min(int a, int b, int c) {
        int tmp = a < b ? a : b;
        return tmp < c ? tmp : c;
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int res = max_so_far;
        for (int i = 1; i < n; i++) {
            int tmp_max = max(nums[i], nums[i] * max_so_far, nums[i] * min_so_far);
            min_so_far = min(nums[i], nums[i] * max_so_far, nums[i] * min_so_far);
            max_so_far = tmp_max;
            res = res > max_so_far ? res : max_so_far;
        }
        return res;
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

    Solution152 solution;
    cout << solution.maxProduct(nums) << endl;

    //system("pause");
    return 0;
}

