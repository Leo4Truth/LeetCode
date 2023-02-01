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
    virtual vector<int> findRightInterval(vector<vector<int>>& intervals) = 0;
};

/**
 * @brief binary search
 * Time Complexity: O(NlogN)
 * Space Complexity: O(N)
 */
class Solution_BinarySearch : public Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
        }
        sort(startIntervals.begin(), startIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
            if (it != startIntervals.end()) {
                ans[i] = it->second;
            }
        }
        return ans;
    }
};

/**
 * @brief two pointer
 * Time Complexity: O(NlogN)
 * Space Complexity: O(N)
 */
class Solution_TwoPointer : public Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    Solution *solution = nullptr;

    solution = new Solution_BinarySearch();
    vector<int> ans1 = solution->findRightInterval(intervals);
    cout << "binary search: [";
    for (int i = 0; i < n; i++) {
        cout << ans1[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    solution = new Solution_BinarySearch();
    vector<int> ans2 = solution->findRightInterval(intervals);
    cout << "two pointers : [";
    for (int i = 0; i < n; i++) {
        cout << ans1[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
