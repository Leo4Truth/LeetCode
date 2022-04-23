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
    virtual long long subArrayRanges(vector<int>& nums) = 0;
};

class Solution_init : public Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return 0;

        vector<vector<int>> min(n, vector<int>(n, INT32_MAX));
        vector<vector<int>> max(n, vector<int>(n, INT32_MIN));
        for (int i = 0; i < n; i++) {
            min[i][i] = nums[i];
            max[i][i] = nums[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                min[i][j] = nums[j] < min[i][j - 1] ? nums[j] : min[i][j - 1];
                max[i][j] = nums[j] > max[i][j - 1] ? nums[j] : max[i][j - 1];
                sum += (max[i][j] - min[i][j]);
            }
        }

        return sum;
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
    cout << solution->subArrayRanges(nums) << endl;

    return 0;
}
