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
    // bfs
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        queue<pair<int, int>> q;
        int area = 0;
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                area = 0;
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        cout << x << "," << y << endl;
                        q.pop();
                        area++;
                        maxArea = area > maxArea ? area : maxArea;
                        for (auto dir : dirs) {
                            if (x + dir[0] >= 0 && x + dir[0] < m &&
                                y + dir[1] >= 0 && y + dir[1] < n &&
                                grid[x + dir[0]][y + dir[1]] == 1) {
                                q.push({x + dir[0], y + dir[1]});
                                grid[x + dir[0]][y + dir[1]] = 0;
                            }
                        }
                    }
                }
            }
        }
        return maxArea;
    }

private:
    vector<vector<int>> dirs = {
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
    cout << solution.maxAreaOfIsland(grid) << endl;

    //system("pause");
    return 0;
}
