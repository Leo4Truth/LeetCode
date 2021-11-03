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
    // Greedy
    // Time  Complexity: O(MN), defeat 100%
    // Space Complexity: O(1),  defeat 69.97%
    // The order of a set of operations doesn't matter
    // So we can consider operations on row first, and then on column
    // To make sum maximum, all row start with 1
    // To make sum maximum, ensure all columns have more 1 than 0
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        // row, only the first row
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++)
                    grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            }
        }
        // columns except the first column
        for (int j = 1; j < n; j++) {
            int zeros = 0;
            for (int i = 0; i < m; i++) zeros += grid[i][j] == 0;
            if (zeros > m / 2) {
                for (int i = 0; i < m; i++)
                    grid[i][j] = grid[i][j] == 1 ? 0 : 1;
            }
        }
        // sum
        int sum = 0;
        for (int i = 0; i < m; i++) {
            int row = 0;
            for (int j = 0; j < n; j++) {
                row *= 2;
                row += grid[i][j];
            }
            sum += row;
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }

    Solution solution;
    cout << "after operations: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Max Sum: " << solution.matrixScore(grid) << endl;

    //system("pause");
    return 0;
}
