#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <tuple>    // C++11

using namespace std;

class Solution {
public:
    // Solution 1: bfs
    int shortestPathLength_floyd_dp(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return 0;
        
        // <v, mask, dist>
        // v, 节点序号
        // mask, 长度为n的二进制数，表示每一个节点是否经过. 如果mask的第i位为1, 则表示第i个节点已经过, 否则表示未经过
        // dist, 表示到当前节点所经过的路径长度
        queue<tuple<int, int, int>> q;
        // 数组记录(u, mask)是否已经被搜索过
        // seen[n][2^n]
        vector<vector<bool>> seen(n, vector<bool>(1 << n, false));
        for (int i = 0; i < n; i++) {
            q.emplace(i, 1 << i, 0);
            seen[i][1 << i] = true;
        }

        int ans = 0;
        while (!q.empty()) {
            auto [u, mask, dist] = q.front(); // C++17
            q.pop();
            // 在搜索的过程中，如果当前三元组中的 mask 包含 n 个 1 即 mask == 2^n −1, 那么我们就可以返回 dist 作为答案
            if (mask == (1 << n) - 1) {
                ans = dist;
                break;
            }
            for (int v : graph[u]) {
                int mask_v = mask | (1 << v);
                if (!seen[v][mask_v]) {
                    q.emplace(v, mask_v, dist + 1);
                    seen[v][mask_v] = true;
                }
            }
        }
        return ans;
    }


    // Solution 1: bfs
    int shortestPathLength_bfs(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return 0;

        // Initialize the distance 2D array
        // set the inf as INT32_MAX because there is an operation d[i][k] + d[k][j]
        vector<vector<int>> d(n, vector<int>(n, INT32_MAX / 2));
        for (int i = 0; i < n; ++i) {
            for (int j: graph[i]) {
                d[i][j] = 1;
            }
        }

        // 使用 floyd 算法预处理出所有点对之间的最短路径长度
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        
        vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2));
        for (int mask = 1; mask < (1 << n); ++mask) {
            // 如果 mask 只包含一个 1，即 mask 是 2 的幂
            if ((mask & (mask - 1)) == 0) {
                int u = __builtin_ctz(mask);
                f[u][mask] = 0;
            }
            else {
                for (int u = 0; u < n; ++u) {
                    if (mask & (1 << u)) {
                        for (int v = 0; v < n; ++v) {
                            if ((mask & (1 << v)) && u != v) {
                                f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] + d[v][u]);
                            }
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int u = 0; u < n; ++u) {
            ans = min(ans, f[u][(1 << n) - 1]);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++) {
        vector<int> adjVec;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adjVec.push_back(x);
        }
        graph.push_back(adjVec);
    }

    cout << "graph: " << "[";
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j];
            if (j < graph[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < n - 1) cout << ",";
    }
    cout << "]" << endl;

    Solution solution;
    cout << solution.shortestPathLength_floyd_dp(graph) << endl;

    //system("pause");
    return 0;
}
