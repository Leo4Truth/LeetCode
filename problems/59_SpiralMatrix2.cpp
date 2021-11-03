#include <iostream>
#include <vector>

using namespace std;

class Solution59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n == 0) return res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<int>(n, 0));
        }
        int dr[] = { 0, 1, 0, -1 };
        int dc[] = { 1, 0, -1, 0 };
        int c = 0, r = 0;
        int di = 0;
        for (int i = 1; i <= n * n; i++) {
            res[r][c] = i;
            int cc = c + dc[di];
            int rr = r + dr[di];
            if (0 <= cc && cc < n && 0 <= rr && rr < n && res[rr][cc] == 0) {
                c = cc;
                r = rr;
            }
            else {
                di = (di + 1) % 4;
                c += dc[di];
                r += dr[di];
            }
        }
        return res;
    }
};

int main59() {
    Solution59 solution;
    int n;
    cin >> n;
    vector<vector<int>> res = solution.generateMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}