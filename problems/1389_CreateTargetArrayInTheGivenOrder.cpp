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
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    vector<int> index;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        index.push_back(idx);
    }

    Solution solution;
    vector<int> res = solution.createTargetArray(nums, index);
    for (auto x : res) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
