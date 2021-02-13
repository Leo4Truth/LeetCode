#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAXN 100001

class Solution {
public:
    // Key Point
    // 将 source 中的每个位置看成一个 node
    // 将 allowedSwaps 中的每一个 pair 看成一条 edge

    // Union-Find with compack
    int parent[MAXN];
    int ranking[MAXN];

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // compact
    }

    void unionSet(int a, int b) {
        a = find(a);
        b = find(b);

        if (ranking[a] < ranking[b]) swap(a, b); // union by ranking

        ranking[a]++;
        parent[b] = a;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        if (n == 0) return 0;

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            ranking[i] = 1;
        }

        for (auto swap : allowedSwaps) unionSet(swap[0], swap[1]);

        unordered_map<int, unordered_map<int, int>> freq_diff;
        for (int i = 0; i < n; i++) freq_diff[find(i)][source[i]]++; // freq_diff[key][num] = value source中以key为根的component中num的数量
        for (int i = 0; i < n; i++) freq_diff[find(i)][target[i]]--;

        int res = 0;
        for (auto componentNums : freq_diff) {
            auto nums = componentNums.second;
            for (auto num : nums) res += abs(num.second);
        }

        return res / 2;
    }

    // dfs
    void dfs(int u, vector<bool>& visited, vector<vector<int>> &graph, vector<int> &source, vector<int> &target, unordered_map<int, int> &count) {
        visited[u] = true;
        count[source[u]]++;
        count[target[u]]--;
        for (int v : graph[u]) {
            if (!visited[v]) dfs(v, visited, graph, source, target, count);
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        if (n == 0) return 0;

        // construct an undirected graph
        vector<vector<int>> graph(n, vector<int>());
        for (auto e : allowedSwaps) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int diff = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            // every loop dfs through a component, if visited, then skip
            if (!visited[i]) {
                // count the nums in the component
                unordered_map<int, int> count;
                dfs(i, visited, graph, source, target, count);
                for (auto [k, v] : count) diff += v > 0 ? v : 0;
            }
        }

        return diff;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 4;
    int m = argc >= 3 ? stoi(argv[2]) : 2;

    vector<int> source, target;
    vector<vector<int>> allowedSwaps;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        source.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        target.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        allowedSwaps.push_back(vector<int>{x, y});
    }

    Solution solution;
    
    cout << solution.minimumHammingDistance(source, target, allowedSwaps) << endl;

    //system("pause");
    return 0;
}
