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
    // offical solution
    bool isCovered_official(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);   // 差分数组
        for (auto&& range: ranges) {
            ++diff[range[0]];
            --diff[range[1]+1];
        }
        // 前缀和
        int curr = 0;
        for (int i = 1; i <= 50; ++i) {
            curr += diff[i];
            if (i >= left && i <= right && curr <= 0) {
                return false;
            }
        }
        return true;
    }
    
    // brute force
    // sort
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (auto range : ranges) {
            if (range[0] > left) return false;
            left = range[1] >= left ? range[1] + 1 : left;
            if (left > right) return true;
        }
        return left > right;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int left = argc >= 3 ? stoi(argv[2]) : 0;
    int right = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> ranges;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges.push_back({l, r});
    }

    Solution solution;
    cout << solution.isCovered(ranges, left, right) << endl;

    //system("pause");
    return 0;
}
