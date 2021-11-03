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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        queue<int> q;
        queue<int> depthQ;
        unordered_set<int> fresh;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push(i * n + j);
                    depthQ.push(0);
                }
                else if (grid[i][j] == 1)
                    fresh.insert(i * n + j);
            }
        }
        while (!q.empty()) {
            int p = q.front();
            int d = depthQ.front();
            q.pop();
            depthQ.pop();
            int x = p / n;
            int y = p % n;
            for (auto dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push(nx * n + ny);
                    depthQ.push(d + 1);
                    fresh.erase(nx * n + ny);
                    if (fresh.empty()) return d + 1;
                }
            }
        }
        if (fresh.empty()) return 0;
        return -1;
    }

private:
    vector<vector<int>> dirs{
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}
    };
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }

    Solution solution;
    cout << solution.orangesRotting(grid) << endl;

    //system("pause");
    return 0;
}
