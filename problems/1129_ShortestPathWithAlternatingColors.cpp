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
    virtual vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) = 0;
};

class Solution_bfs : public Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        if (n == 0) return {};
        
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            next[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges) {
            next[1][e[0]].push_back(e[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX)); // dist[color_of_the_last_edge_of_the_shortest_path_to_the_node][node] = length of the shortest path to the node
        dist[0][0] = 0;
        dist[1][0] = 0;
        
        queue<pair<int, int>> q; // <node, color_of_the_last_edge_of_the_shortest_path_to_the_node>
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : next[1 - t][x]) {
                if (dist[1 - t][y] != INT_MAX) continue;
                dist[1 - t][y] = dist[t][x] + 1;
                q.push({y, 1 - t});
            }
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = min(dist[0][i], dist[1][i]);
            if (answer[i] == INT_MAX) answer[i] = -1;
        }

        return answer;
    }

private:
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int r = argc >= 3 ? stoi(argv[2]) : 0;
    int b = argc >= 4 ? stoi(argv[3]) : 0;

    vector<vector<int>> redEdges;
    vector<vector<int>> blueEdges;

    for (int i = 0; i < r; i++) {
        int a, b;
        cin >> a >> b;
        redEdges.emplace({a, b});
    }
    
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        blueEdges.emplace({u, v});
    }

    Solution *solution = nullptr;

    solution = new Solution_bfs();
    vector<int> res = solution->shortestAlternatingPaths(n, redEdges, blueEdges);

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}
