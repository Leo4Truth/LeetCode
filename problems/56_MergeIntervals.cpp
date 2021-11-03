#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= res[res.size() - 1][1]) {
                res[res.size() - 1][1] = intervals[i][1] > res[res.size() - 1][1] ? intervals[i][1] : res[res.size() - 1][1];
            }
            else res.push_back(intervals[i]);
        }
        return res;
    }

    bool cmp(vector<int> const& a, vector<int> const& b) {
        return a[0] > b[0] ? true : false;
    }
};

int main56() {
    Solution56 solution;
    vector<vector<int>> intervals;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> interval;
        interval.push_back(a);
        interval.push_back(b);
        intervals.push_back(interval);
    }
    vector<vector<int>> res = solution.merge(intervals);
    cout << "res.size() = " << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << i << ": ";
        cout << res[i][0] << ", " << res[i][1] << endl;
    }
    system("pause");
    return 0;
}