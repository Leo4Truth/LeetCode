#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution79 {
public:
    // dfs
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    //cout << i << ", " << j << ": " << word[0] << endl;
                    //cout << "left: " << word.substr(1) << endl;
                    if (word.size() == 1) return true;
                    //print(visited);
                    visited[i][j] = true;
                    if (dfs(board, word.substr(1), i, j, visited)) return true;
                    visited[i][j] = false;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int row, int col, vector<vector<bool>>& visited) {
        int next[4][2] = {
            { -1, 0 },
            { 0, 1 },
            { 1, 0 },
            { 0, -1 }
        };
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < 4; i++) {
            if (valid(row + next[i][0], col + next[i][1], m, n, visited) && board[row + next[i][0]][col + next[i][1]] == word[0]) {
                //cout << row + next[i][0] << ", " << col + next[i][1] << ": " << word[0] << endl;
                //cout << "left: " << word.substr(1) << endl;
                visited[row + next[i][0]][col + next[i][1]] = true;
                //print(visited);
                if (word.size() == 1) {
                    return true;
                }
                else {
                    if (dfs(board, word.substr(1), row + next[i][0], col + next[i][1], visited)) return true;
                }
                visited[row + next[i][0]][col + next[i][1]] = false;
            }
        }
        return false;
    }

    bool valid(int y, int x, int rows, int cols, vector<vector<bool>>& visited) {
        return y >= 0 && y < rows && x >= 0 && x < cols && !visited[y][x];
    }

    void print(vector<vector<bool>> visited) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                cout << visited[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main79() {
    Solution79 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            board[i].push_back(x);
        }
    }
    string word;
    cin >> word;
    cout << solution.exist(board, word) << endl;
    system("pause");
    return 0;
}