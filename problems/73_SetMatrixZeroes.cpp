#include <iostream>
#include <vector>

using namespace std;

class Solution73 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) matrix[i][j] = 0;
            }
        }
    }
};

int main73() {
    Solution73 solution;

    system("pause");
    return 0;
}