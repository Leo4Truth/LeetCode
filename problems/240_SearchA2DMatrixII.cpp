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
    bool searchMatrix_z(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                --y;
            }
            else {
                ++x;
            }
        }
        return false;
    }

    bool searchMatrix_binarySearch(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    int rows = argc >= 2 ? stoi(argv[1]) : 0;
    int cols = argc >= 3 ? stoi(argv[2]) : 0;
    int target = argc >= 4 ? stoi(argv[3]) : 0;
    vector<vector<int>> matrix;
    for (int i = 0; i < rows; i++) {
        vector<int> row;
        for (int j = 0; j < cols; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }

    Solution solution;
    cout << solution.searchMatrix_z(matrix, target) << endl;
    
    return 0;
}
