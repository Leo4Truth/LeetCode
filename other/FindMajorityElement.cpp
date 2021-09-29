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
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        unordered_map<int, int> count;
        for (auto num : nums) count[num]++;
        int maxCount = 0;
        int max = -1;
        for (auto entry : count) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                max = entry.first;
            }
        }
        return maxCount > n / 2 ? max : -1;
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
    cout << solution.majorityElement(nums) << endl;

    //system("pause");
    return 0;
}
