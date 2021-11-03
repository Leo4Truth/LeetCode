#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>

#define DEBUG

using namespace std;

class Solution {
public:
    vector<vector<int>> adjList;
    unordered_set<int> seen;

    bool dfs(int node, int parent) {
        if (seen.count(node) != 0) return false;
        seen.insert(node);
        for (auto neighbour : adjList[node]) {
            if (parent != neighbour) {
                bool res = dfs(neighbour, node);
                if (!res) return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        int e = edges.size();
        if (e != n - 1) return false;

        adjList = vector<vector<int>>(n, vector<int>());
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

#ifdef DEBUG
        cout << "adjacent list:" << endl;
        for (auto list : adjList) {
            for (int j = 0; j < list.size(); j++) {
                cout << list[j];
                if (j < list.size() - 1) cout << "->";
            }
            cout << endl;
        }
        cout << endl;
#endif // DEBUG
        return dfs(0, -1) && seen.size() == n;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 3;
    int e = argc >= 3 ? stoi(argv[2]) : 2;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> edge;
        edge.push_back(a);
        edge.push_back(b);
        edges.push_back(edge);
    }

    cout << "edges: " << endl;
    for (auto edge : edges) cout << edge[0] << ", " << edge[1] << endl;
    cout << endl;

    Solution solution;
    cout << solution.validTree(n, edges) << endl;

    //system("pause");
    return 0;
}
