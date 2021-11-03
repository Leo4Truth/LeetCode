#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1291 {
public:
    vector<vector<int>> adj {
        {-1, -1}, {-1,  0}, {-1,  1},
        { 0, -1},           { 0,  1},
        { 1, -1}, { 1,  0}, { 1,  1}
    };
    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};
    int m, n;
    int shortest = INT32_MAX;

    bool isValid(vector<vector<int>>& grid, int x, int y) { return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0; }

    int shortestPathBinaryMatrix_bfs_overwriting_input(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;

        if (grid[0][0] == 1) return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push(vector<int>{0, 0});
        grid[0][0] = 1;
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            visited[x][y] = true;
            
            for (auto d : adj) {
                int nextX = x + d[0];
                int nextY = y + d[1];
                if (isValid(grid, nextX, nextY) && !visited[nextX][nextY]) {
                    q.push(vector<int>{nextX, nextY});
                    grid[nextX][nextY] = grid[x][y] + 1;
                }
            }
        }

        return visited[m - 1][n - 1] ? grid[m - 1][n - 1] : -1;
    }

    // Limit Time Exceeded
    int shortestPathBinaryMatrix_bfs_without_overwriting_input(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        if (grid[0][0] == 1) return -1;
        
        m = grid.size();
        n = grid[0].size();
        
        int step = 1;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        grid[0][0] = 1;
        
        while (!q.empty()) {
            int size = q.size(); 
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == m - 1 && y == n - 1) return step;
                for (int j = 0; j < 8; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j]; 
                    if (isValid(grid, nx, ny)) {
                        q.emplace(nx, ny);
                        grid[nx][ny] = 1;
                    }
                }
            }
            step++;
        }
        
        return -1;
    }

    int shortestPathBinaryMatrix_Astar(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;

        if (grid[0][0] == 1) return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        q.push(vector<int>{0, 0, 1});
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int length = q.front()[2];
            q.pop();

            visited[x][y] = true;
            if (x == m - 1 && y == n - 1) return length;
            
            for (auto d : adj) {
                int nextX = x + d[0];
                int nextY = y + d[1];
                if (isValid(grid, nextX, nextY) && !visited[nextX][nextY]) {
                    q.push(vector<int>{nextX, nextY, length + 1});
                }
            }
        }

        return -1;
    } 
    
    // Limit Time Exceeded
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int length) {
        visited[x][y] = true;
        
        if (x == m - 1 && y == n - 1) {
            shortest = length < shortest ? length : shortest;
        }
        else {
            for (auto d : adj) {
                int nextX = x + d[0];
                int nextY = y + d[1];
                if (isValid(grid, nextX, nextY) && !visited[nextX][nextY]) dfs(grid, visited, nextX, nextY, length + 1);
            }
        }

        visited[x][y] = false;
    }
    
    // Limit Time Exceeded
    int shortestPathBinaryMatrix_dfs(vector<vector<int>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;

        if (grid[0][0] == 1) return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(grid, visited, 0, 0, 1);

        return shortest == INT32_MAX ? -1 : shortest;
    }

    void print(vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) cout << grid[i][j] << " ";
                else cout << "x ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 2;
    int n = argc >= 3 ? stoi(argv[2]) : 2;
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

    Solution1291 solution;
    cout << solution.shortestPathBinaryMatrix_bfs_without_overwriting_input(grid) << endl;

    //system("pause");
    return 0;
}
