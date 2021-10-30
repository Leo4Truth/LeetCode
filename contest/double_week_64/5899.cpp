#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool cmp(const vector<int>& e1, const vector<int>& e2) {
    return e1[1] < e2[1] || (e1[1] == e2[1] && e1[0] > e2[0]);
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        if (n == 0) return 0;

        cout << "[" << endl;
        for (int i = 0; i < n; i++) {
            cout << "  [";
            for (int j = 0; j < 3; j++) {
                cout << events[i][j];
                if (j < 2) cout << ",";
            }
            cout << "]";
            if (i < n - 1) cout << ",";
            cout << endl;
        }
        cout << "]" << endl;

        sort(events.begin(), events.end(), cmp);

        cout << "[" << endl;
        for (int i = 0; i < n; i++) {
            cout << "  [";
            for (int j = 0; j < 3; j++) {
                cout << events[i][j];
                if (j < 2) cout << ",";
            }
            cout << "]";
            if (i < n - 1) cout << ",";
            cout << endl;
        }
        cout << "]" << endl;

        int max = 0;
        int s1 = 0, t1 = 0, v1 = 0;
        int s2 = 0, t2 = 0, v2 = 0;
        for (int i = 0; i < n; i++) {
            s1 = events[i][0];
            t1 = events[i][1];
            v1 = events[i][2];
            max = v1 > max ? v1 : max;
            for (int j = i + 1; j < n; j++) {
                s2 = events[j][0];
                t2 = events[j][1];
                v2 = events[j][2];
                if (s2 > t1) max = v1 + v2 > max ? v1 + v2 : max;
                else break;
            }
        }

        return max;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> events;
    for (int i = 0; i < n; i++) {
        vector<int> event;
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            event.push_back(x);
        }
        events.push_back(event);
    }

    Solution solution;
    cout << solution.maxTwoEvents(events) << endl;
    
    return 0;
}
