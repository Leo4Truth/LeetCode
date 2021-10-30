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
    virtual vector<int> singleNumber(vector<int>& nums) = 0;
};

/**
 * @brief bit operation
 * Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution_bit_operation : public Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (auto num : nums) xorsum ^= num;
        // overflow
        int lsb = (xorsum == INT32_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (auto num : nums) {
            if (num & lsb) type1 ^= num;
            else type2 ^= num;
        }
        return {type1, type2};
    }
};

/**
 * @brief hashmap record count of every number
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
class Solution_hashmap : public Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        if (n == 1) return {nums[0]};

        unordered_map<int, int> count;
        for (auto num : nums) count[num]++;

        vector<int> res;
        for (auto &entry : count) {
            if (entry.second == 1) res.push_back(entry.first);
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

    Solution *solution = nullptr;
    vector<int> res;

    solution = new Solution_hashmap();
    res = solution->singleNumber(nums);
    cout << "hashmap: ";
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution = new Solution_bit_operation();
    res = solution->singleNumber(nums);
    cout << "hashmap: ";
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}
