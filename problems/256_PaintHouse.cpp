#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define DEBUG

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        unordered_map<string, int> memo;
        
    }

/**********************************************************************************************/

    // Time Limit Exceed
    // O(2^N)
    int minCost_dfs(vector<vector<int>>& costs) {
        n = costs.size();
        if (n == 0) return 0;
        vector<int> colors(n, -1);
        dfs(costs, colors, 0, 0);
        return tempMinCost;
    }

    void dfs(vector<vector<int>>& costs, vector<int>& colors, int s, int cost) {
        if (s == n) {
#ifdef DEBUG
            printColors(colors, cost);
#endif
            tempMinCost = cost < tempMinCost ? cost : tempMinCost;
            return;
        }
        for (int j = 0; j < 3; j++) {
            if (s == 0 || j != colors[s - 1]) {
                colors[s] = j;
                dfs(costs, colors, s + 1, cost + costs[s][j]);
            }
        }
    }

    void printColors(vector<int>& colors, int cost) {
        for (auto color : colors) {
            if (color != -1) cout << color << " ";
            else break;
        }
        cout << ", " << cost << endl;
    }

private:
    int n = 0;
    int tempMinCost = INT32_MAX;
};

int main(int argc, char* argv[]) {
    int n;
    vector<vector<int>> costs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> cost;
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            cost.push_back(x);
        }
        costs.push_back(cost);
    }

    Solution solution;
    cout << solution.minCost_dfs(costs) << endl;

    //system("pause");
    return 0;
}
