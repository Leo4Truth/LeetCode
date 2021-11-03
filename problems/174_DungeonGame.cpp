#include <iostream>
#include <vector>

using namespace std;

class Solution174 {
public:
    int inf = INT32_MAX;
    int rows, cols;
    vector<vector<int>> dp;

    int getMinHealth(int currentCell, int nextRow, int nextCol) {
        if (nextRow >= this->rows || nextCol >= this->cols) return this->inf;
        int nextCell = dp[nextRow][nextCol];
        return max(1, nextCell - currentCell);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        this->rows = dungeon.size();
        if (this->rows == 0) return 0;
        this->cols = dungeon[0].size();
        if (this->cols == 0) return 0;
        dp = vector<vector<int>>(this->rows, vector<int>(this->cols, this->inf));
        
        int currentCell, rightHealth, downHealth, nextHealth, minHealth;
        for (int row = this->rows - 1; row >= 0; row--) {
            for (int col = this->cols - 1; col >= 0; col--) {
                currentCell = dungeon[row][col];
                
                rightHealth = getMinHealth(currentCell, row, col + 1);
                downHealth = getMinHealth(currentCell, row + 1, col);
                nextHealth = min(rightHealth, downHealth);

                if (nextHealth != this->inf) minHealth = nextHealth;
                else minHealth = currentCell >= 0 ? 1 : 1 - currentCell;

                this->dp[row][col] = minHealth;
            }
        }

#ifdef DEBUG
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->cols; j++) {
                cout << this->dp[i][j];
                if (j < this->rows - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
#endif // DEBUG

        return dp[0][0];
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 3;
    int n = argc >= 3 ? stoi(argv[2]) : 3;
    vector<vector<int>> dungeon;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        dungeon.push_back(row);
    }

    Solution174 solution;
    cout << solution.calculateMinimumHP(dungeon) << endl;

    //system("pause");
    return 0;
}
