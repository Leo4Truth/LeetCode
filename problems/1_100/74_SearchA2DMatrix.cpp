#include <iostream>
#include <vector>

using namespace std;

class Solution74 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        for (int i = 0; i < m - 1; i++) {
            if (target > matrix[i + 1][0]) continue;
            for (int j = 0; j < n; j++)
                if (target == matrix[i][j]) return true;
        }
        for (int j = 0; j < n; j++)
            if (target == matrix[m - 1][j]) return true;
        return false;
    }
};

int main74() {
    Solution74 solution;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            matrix[i].push_back(x);
        }
    }
    int target;
    cin >> target;
    cout << solution.searchMatrix(matrix, target) << endl;
    system("pause");
    return 0;
}