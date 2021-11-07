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
    virtual int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) = 0;
};

class Solution_bfs : public Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int e = edges.size();

        // map[node] = {{next1, time1}, {next2, time2}}
        // nondirection graph
        unordered_map<int, vector<vector<int>>> map(n);
        sort(edges.begin(), edges.end());
        for (auto& edge : edges) {
            map[edge[0]].push_back({edge[1], edge[2]});
            map[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> visit(n, 0);

        int maxValue = 0;
        // curr: {node, value, time}
        queue<vector<int>> q;
        q.push({0, values[0], 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (auto& entry : map[p[0]]) {
                int next = entry[0];
                int time = entry[1];

                int totalTime = p[2] + time; // total
                // end search, if totalTime out of range (> maxTime)
                if (totalTime > maxTime) continue;

                int totalValue = p[1]; // total
                // only add value at the first time visit
                if (visit[next] == 0) totalValue += values[next];
                visit[next]++;
                cout << next << ", " << totalTime << ", " << totalValue << endl;

                // update maxValue if reach node 0 within maxTime
                if (totalTime <= maxTime && next == 0) maxValue = totalValue > maxValue ? totalValue : maxValue;
                
                q.push({next, totalValue, totalTime});

                //visit[next]--;
                //if (visit[next] == 0) totalValue -= values[next];
            }
        }

        return maxValue;
    }

private:
};

class Solution_dfs : public Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int e = edges.size();

        // map[node] = {{next1, time1}, {next2, time2}}
        // nondirection graph
        unordered_map<int, vector<vector<int>>> map(n);
        sort(edges.begin(), edges.end());
        for (auto& edge : edges) {
            map[edge[0]].push_back({edge[1], edge[2]});
            map[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> visit(n, 0);

        int maxValue = 0;

        dfs(values, map, 0, values[0], 0, maxTime, 0, maxTime, visit);

        return maxValue;
    }

private:
    void dfs(vector<int>& values, unordered_map<int, vector<vector<int>>>& map, int curr, int totalValue, int totalTime, int& maxValue, int maxTime,, vector<int>& visit) {
        int n = values.size();
        int e = map.size();

        for (auto& entry : map[curr]) {
            int next = entry[0];
            int value = values[next];
            int time = entry[1];

            if (totalTime + time > maxTime) continue;
            totalTime += time;

            if (visit[next] == 0) totalValue += value;
            visit[next]++;
            if (next == 0) continue;
            dfs(values, map, next, totalValue, totalTime, maxValue, maxTime, visit);
            visit[next]--;
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int e = argc >= 3 ? stoi(argv[2]) : 0;
    int maxTime = argc >= 4 ? stoi(argv[3]) : 0;
    vector<int> values;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }
    for (int j = 0; j < e; j++) {
        int u, v, t;
        cin >> u >> v >> t;
        edges.push_back({u, v, t});
    }

    Solution *solution = nullptr;

    solution = new Solution_bfs();
    cout << "bfs: " << solution->maximalPathQuality(values, edges, maxTime) << endl;

    solution = new Solution_dfs();
    cout << "dfs: " << solution->maximalPathQuality(values, edges, maxTime) << endl;

    return 0;
}
