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
    // Time  Complexity: O(N)
    // Space Complixity: O(1)
    int findUnsortedSubarray_onePass(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int maxn = INT32_MIN, right = -1;
        int minn = INT32_MAX, left = -1;
        for (int i = 0; i < n; i++) {
            if (maxn > nums[i]) right = i;
            else maxn = nums[i];
            if (minn < nums[n - i - 1]) left = n - i - 1;
            else minn = nums[n - i - 1];
        }
        return right == -1 ? 0 : right - left + 1;
    }

    int findUnsortedSubarray_sort(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> numsSorted(nums.begin(), nums.end());
        sort(numsSorted.begin(), numsSorted.end());
        int s = 0, t = n - 1;
        while (s < n && nums[s] == numsSorted[s]) s++;
        if (s == n) return 0;
        while (t >= 0 && nums[t] == numsSorted[t]) t--;
        return t - s + 1;
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
    cout << solution.findUnsortedSubarray_sort(nums) << endl;

    //system("pause");
    return 0;
}
