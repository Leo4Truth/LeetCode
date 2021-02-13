#include <iostream>
#include <vector>

using namespace std;

class Solution63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        bool block = false;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) obstacleGrid[i][0] = 1;
            else if (obstacleGrid[i][0] == 1) block = true;
            if (block) obstacleGrid[i][0] = 0;
        }
        block = false;
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 0) obstacleGrid[0][j] = 1;
            else if (obstacleGrid[0][j] == 1) block = true;
            if (block) obstacleGrid[0][j] = 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }
        }

        /*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << obstacleGrid[i][j] << " ";
            }
            cout << endl;
        }
        */

        return obstacleGrid[m - 1][n - 1];
    }
};

int main63() {
    Solution63 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            obstacleGrid[i].push_back(0);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        obstacleGrid[y][x] = 1;
    }
    cout << solution.uniquePathsWithObstacles(obstacleGrid) << endl;
    system("pause");
    return 0;
}