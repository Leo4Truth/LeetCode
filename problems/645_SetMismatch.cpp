#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution645 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1, 1);
        for (int i = 0; i < n; i++) cnt[nums[i]]--;
        vector<int> res(2, 0);
        for (int i = 1; i < n + 1; i++) {
            if (cnt[i] == -1) res[0] = i;
            else if (cnt[i] == 1) res[1] = i;
        }
        return res;
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

    Solution645 solution;
    vector<int> res = solution.findErrorNums(nums);
    cout << "[" << res[0] << "," << res[1] << "]"<< endl;

    //system("pause");
    return 0;
}

