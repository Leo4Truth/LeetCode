#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dp, iterative solution
class Solution {
public:
    int dp[101][101][101];
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof dp);
        int n = boxes.size();
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                // tricky: 当前序列 [l, r] 右侧最多只有 n - 1 - r 个元素
                for (int k = 0; k < n - 1 - r; k++) {
                    // 策略1: 消除当前序列 [l, r] 中的最右侧 1 个 和 当前序列右侧 k 个 的得分
                    dp[l][r][k] = max(dp[l][r][k], (r - 1 < l ? 0 : dp[l][r - 1][0]) + (k + 1) * (k + 1));
                    // 策略2: 消除当前序列中从 t 到 r 的与 boxes[r] 同色的 和 当前序列右侧 k 个 的得分
                    for (int t = l; t <= r - 1; t++) {
                        if (boxes[t] == boxes[r]) {
                            dp[l][r][k] = max(dp[l][r][k], dp[t + 1][r - 1][0] + dp[l][t][k + 1]);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][0];
    }
};

// dp, recursive solution
class Solution_official {
public:
    int dp[100][100][100];

    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof dp);
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] == 0) {
            dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
            for (int i = l; i < r; i++) {
                if (boxes[i] == boxes[r]) {
                    dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
                }
            }
        }
        return dp[l][r][k];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> boxes;
    for (int i = 0; i < n; i++) {
        int box;
        cin >> box;
        boxes.push_back(box);
    }

    Solution solution;
    cout << solution.removeBoxes(boxes) << endl;
    
    return 0;
}
