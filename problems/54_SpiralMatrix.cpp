#include <iostream>
#include <vector>

using namespace std;

class Solution54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int R = matrix.size();
        if (R == 0) return res;
        int C = matrix[0].size();
        if (C == 0) return res;

        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        bool **visit = new bool*[R];
        for (int i = 0; i < R; i++) {
            visit[i] = new bool[C];
            for (int j = 0; j < C; j++)
                visit[i][j] = false;
        }
        int r = 0, c = 0, di = 0;
        for (int i = 0; i < R * C; i++) {
            res.push_back(matrix[r][c]);
            visit[r][c] = true;
            int cr = r + dr[di];
            int cc = c + dc[di];
            if (0 <= cr && cr < R && 0 <= cc && cc < C && !visit[cr][cc]) {
                r = cr;
                c = cc;
            }
            else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        return res;
    }
};

int main54() {
    Solution54 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }
    vector<int> res = solution.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}