#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define DEBUG

using namespace std;

class Solution {
public:
    // Single Source Directed Graph -> Dijkstra 
    int networkDelayTime_Dijkstra(vector<vector<int>>& times, int n, int k) {
        const int inf = INT32_MAX;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        // pair<int, int> p
        // p.first distance, p.second index
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }

    // First Simple Solution
    // Adjacent List, maintain minimum delay of each node from source node.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>());
        for (auto time : times) adjList[time[0]].push_back({time[1], time[2]});
#ifdef DEBUG
        for (int u = 1; u <= n; u++) {
            cout << u << endl;
            for (auto adj : adjList[u]) {
                cout << "\t" << adj.first << ": " << adj.second << endl;
            }
        }
        cout << endl;
#endif // DEBUG
        vector<int> delay(n + 1, INT32_MAX);
        delay[k] = 0;
        dfs(adjList, k, 0, delay);
        int max = 0;
        for (int i = 1; i <= n; i++) {
#ifdef DEBUG
            cout << k << " -> " << i << ": " << delay[i] << endl; 
#endif // DEBUG
            if (delay[i] == INT32_MAX) return -1;
            max = delay[i] > max ? delay[i] : max;
        }
        return max;
    }

    void dfs(vector<vector<pair<int, int>>>& adjList, int curr, int time, vector<int>& delay) {
#ifdef DEBUG
        cout << curr << endl; 
#endif // DEBUG
        for (auto p : adjList[curr]) {
            if (time + p.second < delay[p.first]) {
                delay[p.first] = time + p.second;
                dfs(adjList, p.first, time + p.second, delay);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;
    int m = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> times;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        times.push_back({u, v, w});
    }

    Solution solution;
    cout << solution.networkDelayTime(times, n, k) << endl;

    //system("pause");
    return 0;
}
