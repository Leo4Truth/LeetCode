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
    virtual vector<int> findDuplicates(vector<int>& nums) = 0;
};

class Solution_set : public Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        unordered_set<int> set;
        vector<int> dups;
        for (int i = 0; i < n; i++) {
            if (set.count(nums[i]) == 1) dups.push_back(nums[i]);
            else set.insert(nums[i]);
        }
        return dups;
    }

private:
};

class Solution_sign : public Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> dups;
        for (int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            // 能用 x - 1 做下标是因为 nums 中元素的范围是 [1, n]
            // 相当于用用 x - 1 处元素的正负来标记 x 之前是否出现过
            if (nums[x - 1] > 0) nums[x - 1] = -nums[x - 1];
            else dups.push_back(x);
        }
        return dups;
    }

private:
};

class Solution_swap : public Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> dups;
        for (int i = 0; i < n; ++i) {
            // nums[i] 处应该刚好是 i + 1，如果不是，则说明是重复元素
            if (nums[i] - 1 != i) {
                dups.push_back(nums[i]);
            }
        }
        return dups;
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

    solution = new Solution_set();
    vector<int> dups = solution->findDuplicates(nums);
    cout << "set : [";
    for (int i = 0; i < dups.size(); i++) {
        cout << dups[i];
        if (i < dups.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 该方法在 nums 数组上直接操作
    vector<int> nums1 = vector<int>(nums);
    solution = new Solution_sign();
    dups = solution->findDuplicates(nums1);
    cout << "sign: [";
    for (int i = 0; i < dups.size(); i++) {
        cout << dups[i];
        if (i < dups.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    // 该方法在 nums 数组上直接操作
    vector<int> nums2 = vector<int>(nums);
    solution = new Solution_swap();
    dups = solution->findDuplicates(nums2);
    cout << "swap: [";
    for (int i = 0; i < dups.size(); i++) {
        cout << dups[i];
        if (i < dups.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
