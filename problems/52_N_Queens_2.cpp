#include <iostream>
#include <vector>

using namespace std;

class Solution52 {
public:
    // backtracking
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> current;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) row.append(".");
            current.push_back(row);
        }
        backtracking(0, current, n, res);
        return res.size();
    }

    void backtracking(int rowIdx, vector<string>& current, int n, vector<vector<string>>& res) {
        if (rowIdx == n) {
            res.push_back(current);
            return;
        }
        // board[rowIdx][i]
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < rowIdx; j++) {
                if (current[j][i] == 'Q') {
                    flag = false;
                    break;
                }
            }
            // dialog 1
            for (int j = rowIdx - 1, k = i - 1; j >= 0 && k >= 0; j--, k--) {
                if (current[j][k] == 'Q') {
                    flag = false;
                    break;
                }
            }
            // dialog 2
            for (int j = rowIdx - 1, k = i + 1; j >= 0 && k < n; j--, k++) {
                if (current[j][k] == 'Q') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                current[rowIdx][i] = 'Q';
                backtracking(rowIdx + 1, current, n, res);
                current[rowIdx][i] = '.';
            }
        }
        return;
    }
};

int main52() {
    Solution52 solution;
    int n;
    cin >> n;
    cout << solution.totalNQueens(n) << endl;
    system("pause");
    return 0;
}