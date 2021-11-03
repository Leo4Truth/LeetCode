#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

enum EventType {
    OPEN,
    CLOSE
};

struct Event {
    int x;
    EventType type;

    bool operator<(const Event& other) const {
        return x < other.x || (x == other.x && type < other.type);
    }
};

class Solution57 {
public:
    // Similar to the Bracket matching, Runtime: 38.81%, Memory Usage: 13.85%
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<Event> events;

        for (const auto& interval : intervals) {
            events.push_back(Event{ interval[0], OPEN });
            events.push_back(Event{ interval[1], CLOSE });
        }

        events.push_back(Event{ newInterval[0], OPEN });
        events.push_back(Event{ newInterval[1], CLOSE });

        sort(events.begin(), events.end());

        int start = -1;
        int balance = 0;
        vector<vector<int>> new_segments;

        for (const auto& e : events) {
            if (e.type == OPEN) {
                balance += 1;
            }
            else if (e.type == CLOSE) {
                balance -= 1;
            }

            if (balance == 1 && e.type == OPEN) {
                start = e.x;
            }
            else if (balance == 0 && e.type == CLOSE) {
                int end = e.x;
                new_segments.push_back(vector<int>{start, end});
            }
        }

        return new_segments;
    }

    // Original Solution by myself, Runtime: 60%, Memory Usage: 42.58%
    vector<vector<int>> insert_1(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (newInterval.size() < 2) return intervals;

        vector<int> merged;
        if (intervals.size() == 0) res.push_back(newInterval);
        for (int i = 0; i < intervals.size(); i++) {
            if (merged.size() == 2) {
                res.push_back(intervals[i]);
                continue;
            }

            // intervals: 1   1  
            // new:              1   1
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                if (i == intervals.size() - 1) res.push_back(newInterval);
            }
            // intervals: 1   1  
            // new:         1   1
            else if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[0] && intervals[i][1] <= newInterval[1]) {
                merged.push_back(intervals[i][0]);
                if (i == intervals.size() - 1) {
                    merged.push_back(newInterval[1]);
                    res.push_back(merged);
                }
            }
            // intervals: 1      1  
            // new:         1  1
            else if (intervals[i][0] <= newInterval[0] && intervals[i][1] >= newInterval[1]) {
                return intervals;
            }
            // intervals:   1  1  
            // new:       1      1
            else if (intervals[i][0] > newInterval[0] && intervals[i][1] < newInterval[1]) {
                if (merged.size() == 0) merged.push_back(newInterval[0]);
                if (i == intervals.size() - 1) {
                    merged.push_back(newInterval[1]);
                    res.push_back(merged);
                }
            }
            // intervals:   1   1  
            // new:       1   1
            else if (intervals[i][0] >= newInterval[0] && intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[1]) {
                if (merged.size() == 0) merged.push_back(newInterval[0]);
                merged.push_back(intervals[i][1]);
                res.push_back(merged);
            }
            // intervals:        1   1  
            // new:       1   1
            else if (intervals[i][0] > newInterval[1]) {
                if (merged.size() == 0) {
                    merged = newInterval;
                    res.push_back(merged);
                    res.push_back(intervals[i]);
                }
                else if (merged.size() == 1) {
                    // cz merged.size() > 0, so must not i = 0
                    if (intervals[i - 1][1] > newInterval[1]) merged.push_back(intervals[i - 1][1]);
                    else merged.push_back(newInterval[1]);
                    res.push_back(merged);
                    res.push_back(intervals[i]);
                }
            }
        }
        if (merged.size() == 1) {
            int end = intervals[intervals.size() - 1][1] > newInterval[1] ? intervals[intervals.size() - 1][1] : newInterval[1];
            merged.push_back(end);
            res.push_back(merged);
        }
        return res;
    }
};

int main57() {
    Solution57 solution;
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
    vector<int> newInterval;
    int a, b;
    cin >> a >> b;
    newInterval.push_back(a);
    newInterval.push_back(b);
    vector<vector<int>> res = solution.insert(intervals, newInterval);
    for (int i = 0; i < res.size(); i++) {
        cout << i << ": ";
        cout << res[i][0] << ", " << res[i][1] << endl;
    }
    system("pause");
    return 0;
}