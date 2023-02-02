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
    virtual int repeatedNTimes(vector<int>& nums) = 0;
};

/**
 * @brief record elements appeared in a hash set
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution_HashSet : public Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> found;
        for (int num: nums) {
            if (found.count(num)) {
                return num;
            }
            found.insert(num);
        }
        // 不可能的情况
        return -1;
    }
};

/**
 * @brief it can be proved that there must be two same x in neighbor or with one distance 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
class Solution_Math : public Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for (int gap = 1; gap <= 3; ++gap) {
            for (int i = 0; i + gap < n; ++i) {
                if (nums[i] == nums[i + gap]) {
                    return nums[i];
                }
            }
        }
        // impossible condition
        return -1;
    }
};

/**
 * @brief random select two indices, judge whether the elements are same, if same return
 *        the expect times to end the loop is 4
 * Time Complexity: O(1) = 2/2n * (n - 1)/2n = 4
 * Space Complexity: O(1)
 */
class Solution_RandomSelect : public Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        srand((unsigned int) time(nullptr));

        while (true) {
            int x = rand() % n, y = rand() % n;
            if (x != y && nums[x] == nums[y]) {
                return nums[x];
            }
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    for (int i = 0; i < n * 2; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution *solution = nullptr;

    solution = new Solution_HashSet();
    cout << "Hash Set     : " << solution->repeatedNTimes(nums) << endl;

    solution = new Solution_Math();
    cout << "Math         : " << solution->repeatedNTimes(nums) << endl;

    solution = new Solution_RandomSelect();
    cout << "Random Select: " << solution->repeatedNTimes(nums) << endl;

    return 0;
}
