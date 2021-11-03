#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort_1(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();

        vector<vector<int>> res(mat);

        vector<vector<pair<int, int>>> diagonalCoords;
        vector<vector<int>> diagonalNums;
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> currentDiagonalCoords;
            vector<int> currentDiagonalNums;
            int row = i, col = 0;
            while (row < m && col < n) {
                currentDiagonalCoords.push_back(pair<int, int>(row, col));
                currentDiagonalNums.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(currentDiagonalNums.begin(), currentDiagonalNums.end());
            diagonalNums.push_back(currentDiagonalNums);
            diagonalCoords.push_back(currentDiagonalCoords);
        }
        for (int j = 1; j < n; j++) {
            vector<pair<int, int>> currentDiagonalCoords;
            vector<int> currentDiagonalNums;
            int row = 0, col = j;
            while (row < m && col < n) {
                currentDiagonalCoords.push_back(pair<int, int>(row, col));
                currentDiagonalNums.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(currentDiagonalNums.begin(), currentDiagonalNums.end());
            diagonalNums.push_back(currentDiagonalNums);
            diagonalCoords.push_back(currentDiagonalCoords);
        }

        for (int i = 0; i < diagonalCoords.size(); i++) {
            for (int j = 0; j < diagonalCoords[i].size(); j++) {
                int row = diagonalCoords[i][j].first;
                int col = diagonalCoords[i][j].second;
                res[row][col] = diagonalNums[i][j];
            }
        }

        return res;
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return {};
        int n = mat[0].size();

        //vector<vector<int>> res(mat);

        vector<vector<int>> diagonalNums;
        for (int i = 0; i < m; i++) {
            vector<int> currentDiagonalNums;
            int row = i, col = 0;
            while (row < m && col < n) currentDiagonalNums.push_back(mat[row++][col++]);
            sort(currentDiagonalNums.begin(), currentDiagonalNums.end());
            diagonalNums.push_back(currentDiagonalNums);
        }
        for (int j = 1; j < n; j++) {
            vector<int> currentDiagonalNums;
            int row = 0, col = j;
            while (row < m && col < n) currentDiagonalNums.push_back(mat[row++][col++]);
            sort(currentDiagonalNums.begin(), currentDiagonalNums.end());
            diagonalNums.push_back(currentDiagonalNums);
        }

        int k = 0;
        for (int i = 0; i < m; i++) {
            int row = i, col = 0;
            int t = 0;
            while (row < m && col < n) mat[row++][col++] = diagonalNums[k][t++];
            k++;
        }
        for (int j = 1; j < n; j++) {
            int row = 0, col = j;
            int t = 0;
            while (row < m && col < n) mat[row++][col++] = diagonalNums[k][t++];
            k++;
        }

        return mat;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 3;
    int n = argc >= 3 ? stoi(argv[2]) : 4;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    vector<vector<int>> res = solution.diagonalSort(mat);
    
    cout << "[" << endl;
    for (int i = 0; i < m; i++) {
        cout << "\t[";
        for (int j = 0; j < n; j++) {
            cout << res[i][j];
            if (j < n - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    
    return 0;
}
