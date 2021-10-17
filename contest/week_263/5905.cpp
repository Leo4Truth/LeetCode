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
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj_list(n + 1, vector<int>(0));
        for (auto& edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> fast;
        unordered_map<int, int> second;
        
        int first = -1;
        queue<pair<int, int>> q; // (node, time)
        q.push(make_pair(1, 0));
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int cur_time = p.second;
            for (auto next : adj_list[node]) {
                if (next == n) {
                    if (first == -1) first = cur_time + time;
                    else {
                        if (cur_time + time > first) return cur_time + time;
                    }
                }
                int next_time = cur_time + time;
                if ((next_time / change) % 2 == 1) next_time = (next_time / change + 1) * change;

                if (fast.find(next) == fast.end()) {
                    fast[next] = next_time;
                    q.push(make_pair(next, next_time));
                    continue;
                }
                if (second.find(next) == second.end() && fast[next] < next_time) {
                    second[next] = next_time;
                    q.push(make_pair(next, next_time));
                    continue;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int e = argc >= 3 ? stoi(argv[2]) : 0;
    int time = argc >= 4 ? stoi(argv[3]) : 0;
    int change = argc >= 5 ? stoi(argv[4]) : 0;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int s, t;
        cin >> s >> t;
        edges.push_back({s, t});
    }

    Solution solution;
    cout << solution.secondMinimum(n, edges, time, change) << endl;
    
    return 0;
}
