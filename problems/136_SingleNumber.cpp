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
    virtual int singleNumber(vector<int>& nums) = 0;
};

/**
 * @brief bit operation
 */
class Solution_bitOperation : public Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

class Solution_hashmap : public Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        unordered_map<int, int> count;
        for (auto num : nums) count[num]++;
        for (auto entry : count) {
            if (entry.second == 1) return entry.first;
        }

        return -1;
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

    solution = new Solution_hashmap();
    cout << solution->singleNumber(nums) << endl;

    return 0;
}
