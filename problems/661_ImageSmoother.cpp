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
    // in place modify
    // low 8 bit origin data
    // high 8 bit sum or avg
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        if (m == 0) return img;
        int n = img[0].size();
        if (n == 0) return img;

        vector<vector<int>> mask = {
            {-1, -1}, {0, -1}, {1, -1},
            {-1, 0}, {0, 0}, {1, 0},
            {-1, 1}, {0, 1}, {1, 1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cnt = 0;
                for (auto d : mask) {
                    if (i + d[0] >= 0 && i + d[0] < m && j + d[1] >= 0 && j + d[1] < n) {
                        sum += img[i + d[0]][j + d[1]] & 255;
                        cnt++;
                    }
                }
                img[i][j] ^= (sum / cnt) << 8; // add the sum to the high 8 bit
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }
        
        return img;
    }

    // copy
    vector<vector<int>> imageSmoother_copy(vector<vector<int>>& img) {
        int m = img.size();
        if (m == 0) return img;
        int n = img[0].size();
        if (n == 0) return img;

        vector<vector<int>> filtered(m, vector<int>(n, 0));
        vector<vector<int>> mask = {
            {-1, -1}, {0, -1}, {1, -1},
            {-1, 0}, {0, 0}, {1, 0},
            {-1, 1}, {0, 1}, {1, 1}
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int cnt = 0;
                for (auto d : mask) {
                    if (i + d[0] >= 0 && i + d[0] < m && j + d[1] >= 0 && j + d[1] < n) {
                        sum += img[i + d[0]][j + d[1]];
                        cnt++;
                    }
                }
                filtered[i][j] = sum / cnt;
            }
        }
        
        return filtered;
    }
};

int main(int argc, char* argv[]) {
    int m = argc >= 2 ? stoi(argv[1]) : 0;
    int n = argc >= 3 ? stoi(argv[2]) : 0;
    vector<vector<int>> img;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        img.push_back(row);
    }

    Solution solution;
    vector<vector<int>> filtered = solution.imageSmoother(img);
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << filtered[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
