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
#include <random>

using namespace std;

/**
 * @brief Hash Map
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]) == 1) map[nums[i]].push_back(i);
            else map[nums[i]] = vector<int>(1, i);
        }
        srand((unsigned) time(nullptr));
    }

    int pick(int target) {
        int n = 0;
        if (map.count(target) == 1) n = map[target].size();
        else return -1;
        int p = rand() % n;
        return map[target][p];
    }

private:
    unordered_map<int, vector<int>> map;
};

/**
 * @brief 
 * TODO: 水塘抽样法
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    vector<int> targets;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        targets.push_back(target);
    }

    Solution *solution = new Solution(nums);
    for (int i = 0; i < m; i++) {
        cout << "target: " << targets[i] << ", ";
        cout << "pick: " << solution->pick(targets[i]) << "." << endl;
    }

    return 0;
}
