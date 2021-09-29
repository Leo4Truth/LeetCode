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
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int m = relation.size();
        vector<vector<int>> adjList(n);
        for (auto edge : relation) adjList[edge[0]].push_back(edge[1]);
        int count = 0;
        dfs(adjList, 0, n - 1, k, count);
        return count;
    }

    void dfs(vector<vector<int>>& adjList, int current, int target, int k, int& count) {
        if (k == 0) {
            count += current == target;
            return;
        }
        for (auto next : adjList[current]) dfs(adjList, next, target, k - 1, count);
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int m = argc >= 3 ? stoi(argv[2]) : 0;
    int k = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> relation;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        relation.push_back({x, y});
    }

    Solution solution;
    cout << solution.numWays(n, relation, k) << endl;

    //system("pause");
    return 0;
}
