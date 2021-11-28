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
    virtual int minimumDeletions(vector<int>& nums) = 0;
};

class Solution_init : public Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        int maxIndex = 0;
        int minIndex = 0;
        int max = INT32_MIN;
        int min = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
            if (nums[i] < min) {
                min = nums[i];
                minIndex = i;
            }
        }

        int maxLeftDis = maxIndex + 1;
        int maxRightDis = n - maxIndex;
        int minLeftDis = minIndex + 1;
        int minRightDis = n - minIndex;

        int minOps = INT32_MAX;

        // 从左侧
        int ops = maxLeftDis > minLeftDis ? maxLeftDis : minLeftDis;
        minOps = ops < minOps ? ops : minOps;

        // 从右侧
        ops = maxRightDis > minRightDis ? maxRightDis : minRightDis;
        minOps = ops < minOps ? ops : minOps;
        
        // 从两侧
        ops = (maxLeftDis < minLeftDis ? maxLeftDis : minLeftDis) + (maxRightDis < minRightDis ? maxRightDis : minRightDis);
        minOps = ops < minOps ? ops : minOps;

        return minOps;
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
    solution = new Solution_init();
    cout << solution->minimumDeletions(nums) << endl;

    return 0;
}
