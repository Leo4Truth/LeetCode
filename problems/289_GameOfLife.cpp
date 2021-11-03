#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int helper(vector<vector<int>>& board, int x, int y) {
        int neighbors[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, 1},            {1, 1},
            {1, 0},   {1, -1}, {0, -1}
        };

        int m = board.size();
        if (m == 0) return 0;
        int n = board[0].size();

        int liveCnt = 0;
        int deadCnt = 0;

        for (int i = 0; i < 8; i++) {
            int d[] = {neighbors[i][0], neighbors[i][1]};

            int xx = x + d[0], yy = y + d[1];
            if (isValid(xx, yy, m, n)) {
                if (board[xx][yy] == 1) liveCnt++;
                else deadCnt++;
            }
        }

        if (board[x][y] == 1 && liveCnt == 2 || liveCnt == 3) return 1;
        else if (board[x][y] == 0 && liveCnt == 3) return 1;
        else return 0;
    } 

    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> res(board);

        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = helper(board, i, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = res[i][j];
            }
        }
    }

    void print(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        cout << "[" << endl;
        for (int i = 0; i < m; i++) {
            cout << "  [";
            for (int j = 0; j < n; j++) {
                cout << board[i][j];
                if (j < n - 1) cout << ",";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;
    }
};

int main(int argc, char *argv[]) {
    int m, n;
    if (argc == 3) {
        m = stoi(argv[1]);
        n = stoi(argv[2]);
    }
    else {
        cout << "Please input m, n: " << endl;
        cin >> m >> n;
    }

    cout << "m=" << m << ", n=" << n << endl;

    vector<vector<int>> board;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        cout << "Please input line " << i + 1 << " of the board." << endl;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        board.push_back(row);
    }

    Solution solution;

    solution.print(board);
    solution.gameOfLife(board);
    solution.print(board);

    return 0;
}