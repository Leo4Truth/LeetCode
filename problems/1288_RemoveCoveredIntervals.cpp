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
    int max_end[100001]; // C++ int数组 成员变量 自动全部初始化为全0
    // No sort
    int removeCoveredIntervals_no_sort(vector<vector<int>>& intervals) {
        // 0 <= l_i <= r_i <= 100000
        // vector<int> max_end(100001, 0); 慢
        // int max_end[100001]; C++ int数组 局部变量 不会自动初始化，数组内各element初始值不确定
        
        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            max_end[start] = end > max_end[start] ? end : max_end[start];
        }

        int cnt = 0;
        int max_right = -1;
        for (int i = 0; i < 100001; i++) {
            if (max_end[i] == 0) continue;
            if (max_end[i] > max_right) cnt++;
            max_right = max_end[i] > max_right ? max_end[i] : max_right;
        }

        return cnt;
    }

    // Greedy, sort
    // Time Complexity: O(NlogN), sort O(NlogN), traversal O(N)
    // Space Complexity: O(1)
    int removeCoveredIntervals_greedy(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // here we define the compare function of sort by lambda expression
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] ? a[0] < b[0];
        });

        int cnt = 0;
        int curr_end, prev_end = 0;
        for (auto curr_interval : intervals) {
            curr_end = curr_interval[1];
            // curr_start >= prev_start is ensured by the sort
            // we just check whether curr_end <= prev_end
            // if curr_end <= prev_end, curr_interval is covered by prev_interval
            // else, curr_interval is not covered by prev_interval, and then we count and update prev_end
            if (prev_end < curr_end) {
                cnt++;
                prev_end = end;
            }
        }

        return cnt;
    }

    // Simple idea, sort and check if the prev interval contains the following intervals
    // record whether each interval is covered or not
    // finally count all uncovered intervals
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    int removeCoveredIntervals_simple(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        // here we define the compare function of sort by lambda expression
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] > b[1] ? a[0] < b[0];
        });

        vector<bool> covered(n, false);
        for (int i = 0; i < n; i++) {
            int s = intervals[i][0];
            int t = intervals[i][1];
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] >= s && intervals[j][1] <= t) {
                    covered[j] = true;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += covered[i] ? 0 : 1;
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> intervals;
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        intervals.push_back({s, t});
    }

    Solution solution;
    cout << solution.removeCoveredIntervals(intervals) << endl;

    return 0;
}
