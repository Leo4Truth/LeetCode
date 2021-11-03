#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution78 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> current(0);
        backtracking(current, res, nums);
        return res;
    }

    void backtracking(vector<int>& current, vector<vector<int>>& res, vector<int>& nums) {
        /*
        cout << "current: " << endl;
        for (int i = 0; i < current.size(); i++) {
            cout << current[i];
            if (i < current.size() - 1) cout << ", ";
        }
        cout << endl;
        */
        res.push_back(current);
        /*
        cout << "res: " << endl;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j];
                if (j < res[i].size() - 1) cout << ", ";
            }
            cout << endl;
        }
        cout << endl;
        */
        for (int i = 0; i < nums.size(); i++) {
            if (current.empty() || nums[i] > current[current.size() - 1]) {
                current.push_back(nums[i]);
                backtracking(current, res, nums);
                current.pop_back();
            }
        }
    }
};

int main78() {
    Solution78 solution;
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> res = solution.subsets(nums);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "  [";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ", ";
        }
        cout << "], " << endl;
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}