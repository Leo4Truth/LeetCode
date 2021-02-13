#include <iostream>
#include <vector>

using namespace std;

class Solution1631 {
public:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };

    bool isValid(pair<int, int> pos) {
        return pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols;
    }

    bool isValid(int x, int y) {
        return y >= 0 && y < rows && x >= 0 && x < cols;
    }

    /*
     * Limit Time Exceed
     * dfs, backtrack
     */
    int rows = 0;
    int cols = 0;;
    int minMaxEffort = 1000000;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int effort, int maxEffort, pair<int, int> current) {
        maxEffort = effort > maxEffort ? effort : maxEffort;
        if (current.first == rows - 1 && current.second == cols - 1) // arrive right-bottom
            minMaxEffort = maxEffort < minMaxEffort ? maxEffort : minMaxEffort;

        for (int i = 0; i < 4; i++) {
            int dx = directions[i][0], dy = directions[i][1];
            pair<int, int> next(current.first + dy, current.second + dx);
            if (isValid(next) && !visited[next.first][next.second]) {
                visited[next.first][next.second] = true;
                int d = heights[next.first][next.second] - heights[current.first][current.second];
                if (d < 0) d = -d;
                dfs(heights, visited, d, maxEffort, next);
                visited[next.first][next.second] = false;
            }
        }
    }

    int minimumEffortPath_dfs_bk_lte(vector<vector<int>>& heights) {
        rows = heights.size();
        if (rows == 0) return 0;
        cols = heights[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[0][0] = true;
        
        pair<int, int> currentPos(0, 0);
        dfs(heights, visited, 0, 0, currentPos);

        return minMaxEffort;
    }

    /*
     * Binary Search
     */

    int minimumEffortPath(vector<vector<int>> &heights) {
        rows = heights.size();
        if (rows == 0) return 0;
        cols = heights[0].size();

        int left = 0;
        int right = 1000000;
        int result = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (dfsUtil(heights, mid)) {
                result = min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    bool dfsUtil(vector<vector<int>>& heights, int mid) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return canReachDestination(0, 0, heights, visited, mid);
    }

    // dfs
    bool canReachDestination(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& visited, int effortLimit) {
        if (x == rows - 1 && y == cols - 1) return true;
        visited[x][y] = true;
        for (auto dir : directions) {
            int nextX = x + dir[0];
            int nextY = y + dir[1];
            if (isValid(nextX, nextY) && !visited[nextY][nextX]) {
                int diff = heights[nextY][nextX] - heights[y][x];
                if (diff < 0) diff = -diff;
                if (diff <= effortLimit) {
                    if (canReachDestination(nextX, nextY, heights, visited, effortLimit)) return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int rows = argc >= 2 ? stoi(argv[1]) : 3;
    int cols = argc >= 3 ? stoi(argv[2]) : 3;
    vector<vector<int>> heights(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> heights[i][j];
        }
    }

    Solution1631 solution;
    cout << solution.minimumEffortPath(heights) << endl;

    //system("pause");
    return 0;
}
