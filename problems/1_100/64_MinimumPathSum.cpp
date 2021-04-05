#include <iostream>
#include <vector>

using namespace std;

class Solution64 {
public:
    // DP, operate on the original vector
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        return grid[m - 1][n - 1];
    }
};

int main64() {
    Solution64 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    cout << solution.minPathSum(grid) << endl;
    system("pause");
    return 0;
}