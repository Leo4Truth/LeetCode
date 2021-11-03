#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution85  {
public:
    // dp
    int maximalRectangle_dp(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (m == 1 && n == 1) return matrix[0][0] - '0';

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && matrix[i][j] == '1') matrix[i][j] = matrix[i][j - 1] + 1;

                cout << matrix[i][j] << " ";

                int maxWidth = matrix[i][j] - '0';
                for (int k = i; k >= 0; k--) {
                    int widthHere = matrix[k][j] - '0';
                    if (widthHere == 0) break;
                    maxWidth = maxWidth < widthHere ? maxWidth : widthHere;
                    int curArea = maxWidth * (i - k + 1);
                    res = res > curArea ? res : curArea;
                }
            }
            cout << endl;
        }

        return res;
    }

    // mono-stack
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (m == 1 && n == 1) return matrix[0][0] - '0';

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j > 0 && matrix[i][j] == '1') matrix[i][j] = matrix[i][j - 1] + 1;

                cout << matrix[i][j] << " ";

                int maxWidth = matrix[i][j] - '0';
                for (int k = i; k >= 0; k--) {
                    int widthHere = matrix[k][j] - '0';
                    if (widthHere == 0) break;
                    maxWidth = maxWidth < widthHere ? maxWidth : widthHere;
                    int curArea = maxWidth * (i - k + 1);
                    res = res > curArea ? res : curArea;
                }
            }
            cout << endl;
        }

        return res;
    }
};

int main85() {
    Solution85 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            matrix[i].push_back(char(x + '0'));
        }
    }
    cout << solution.maximalRectangle(matrix) << endl;
    system("pause");
    return 0;
}