#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        unordered_map<int, int> count;
        int res = 0;
        for (auto row : grid) {
            for (int c1 = 0; c1 < row.size(); c1++) {
                if (row[c1] != 1) continue;
                for (int c2 = c1 + 1; c2 < row.size(); c2++) {
                    if (row[c2] != 1) continue;
                    int pos = c1 * 200 + c2;
                    int c = count[pos];
                    res += c;
                    count[pos] += 1;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 4;
    int n = argc >= 3 ? stoi(argv[2]) : 5;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    cout << solution.countCornerRectangles(grid) << endl;

    //system("pause");
    return 0;
}
