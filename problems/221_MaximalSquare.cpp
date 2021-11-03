#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    maxSide = dp[i][j] > maxSide ? dp[i][j] : maxSide;
                }
            }
        }
        return maxSide * maxSide;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    if (m == 0) cin >> m;
    if (n == 0) cin >> n;

    vector<vector<char>> matrix;
    for (int i = 0; i < m; i++) {
        vector<char> row;
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }

    Solution solution;
    cout << solution.maximalSquare(matrix) << endl;

    //system("pause");
    return 0;
}
