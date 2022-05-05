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
    virtual int numSubarrayProductLessThanK(vector<int>& nums, int k) = 0;
};

class Solution_slideWindow : public Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int cnt = 0;
        int prod = 1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            prod *= nums[r];
            while (l < r && prod >= k) {
                prod /= nums[l];
                l++;
            }
            if (prod < k) cnt += r - l + 1;
        }
        return cnt;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_slideWindow();
    cout << "slide window: " << solution->numSubarrayProductLessThanK(nums, k) << endl;

    return 0;
}
