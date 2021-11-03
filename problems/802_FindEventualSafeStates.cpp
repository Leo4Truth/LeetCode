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
    // dfs + three colors mark
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0) return {};
        
        vector<int> color(n, 0);

        function<bool(int)> safe = [&](int x) {
            if (color[x] > 0) {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x]) {
                if (!safe(y)) {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> adjVec;
        for (int j = 0; j < m; j++) {
            int adj;
            cin >> adj;
            adjVec.push_back(adj);
        }
        graph.push_back(adjVec);
    }

    Solution solution;
    vector<int> safe = solution.eventualSafeNodes(graph);
    for (auto x : safe) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
