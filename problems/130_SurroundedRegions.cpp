#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    q.push(pair<int, int>(i, j));
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int i = p.first, j = p.second;
            if (visit[i][j] || board[i][j] == 'X') continue;
            visit[i][j] = true;
            if (board[i][j] == 'O') {
                board[i][j] = 'E';
                if (i > 0) q.push(pair<int, int>(i - 1, j));
                if (i < m - 1) q.push(pair<int, int>(i + 1, j));
                if (j > 0) q.push(pair<int, int>(i, j - 1));
                if (j < n - 1) q.push(pair<int, int>(i, j + 1));
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'E') board[i][j] = 'O';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        bfs(board);
    }
};