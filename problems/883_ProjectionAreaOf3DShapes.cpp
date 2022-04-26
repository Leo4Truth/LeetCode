#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual int projectionArea(vector<vector<int>>& grid) = 0;
};

class Solution_init : public Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int nx = grid.size();
        if (nx == 0) return 0;
        int ny = grid[0].size();
        if (ny == 0) return 0;
        // cout << nx << ", " << ny << endl;
        int projx, projy = 0;
        int projz = nx * ny;
        int zero_cnt = 0;
        vector<int> highest_y = grid[0];
        for (int i = 0; i < nx; i++) {
            int highest_x = grid[i][0];
            for (int j = 0; j < ny; j++) {
                highest_y[j] = grid[i][j] > highest_y[j] ? grid[i][j] : highest_y[j];
                highest_x = grid[i][j] > highest_x ? grid[i][j] : highest_x;
                zero_cnt += grid[i][j] == 0;
            }
            projx += highest_x;
        }
        for (int j = 0; j < ny; j++) projy += highest_y[j];
        projz -= zero_cnt;
        // cout << zero_cnt << endl;
        // cout << projx << ", " << projy << ", " << projz << endl;
        return projx + projy + projz;
    }

private:
};

class Solution_standard : public Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++) {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = max(yzHeight, grid[j][i]);
                zxHeight = max(zxHeight, grid[i][j]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};

int main(int argc, char* argv[]) {
    int nx = argc >= 2 ? stoi(argv[1]) : 0;
    int ny = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> grid(nx, vector<int>(ny, 0));
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            int v;
            cin >> v;
            grid[i][j] = v;
        }
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->projectionArea(grid) << endl;

    solution = new Solution_standard();
    cout << solution->projectionArea(grid) << endl;

    return 0;
}
