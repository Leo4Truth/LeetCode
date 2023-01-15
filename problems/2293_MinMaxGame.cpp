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
    virtual int minMaxGame(vector<int>& nums) = 0;
};

class Solution_init : public Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        while (n > 0) {
            for (int i = 0; i < n / 2; i++) {
                if (i % 2 == 0) nums[i] = min(nums[i * 2], nums[i * 2 + 1]);
                else nums[i] = max(nums[i * 2], nums[i * 2 + 1]);
            }
            n /= 2;
        }
        return nums[0];
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
    cout << solution->minMaxGame(nums) << endl;

    return 0;
}
