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
    virtual vector<int> sortArrayByParity(vector<int>& nums) = 0;
};

class Solution_init : public Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return nums;
        vector<int> sorted(n, 0);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) sorted[l++] = nums[i];
            else sorted[r--] = nums[i];
        }
        return sorted;
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
    vector<int> sorted = solution->sortArrayByParity(nums);
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << sorted[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
