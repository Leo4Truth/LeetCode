#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution84 {
public:
    // dp, O(N^2), exceed time limit
    int largestRectangleArea_dp(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int **dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[n];
            for (int j = 0; j < n; j++) {
                if (i > j) dp[i][j];
                else if (i == j) dp[i][j] = heights[i];
                else dp[i][j] = INT_MAX;
            }
        }

        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j > i) dp[i][j] = dp[i][j - 1] < dp[j][j] ? dp[i][j - 1] : dp[j][j];
                int area = dp[i][j] * (j - i + 1);
                if (area > max) max = area;
            }
        }

        return max;
    }

    // Brute Force
    int largestRectangleArea_bruteForce(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];

        int res = 0;

        for (int i = 0; i < n; i++) {
            int temp = heights[i];
            for (int j = i - 1; j >= 0; j--) {
                if (heights[j] >= heights[i]) temp += heights[i];
                else break;
            }
            for (int j = i + 1; j < n; j++) {
                if (heights[j] >= heights[i]) temp += heights[i];
                else break;
            }
            if (temp > res) res = temp;
        }

        return res;
    }

    // mono-stack, 单调栈
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];
        
        int res = 0;
        stack<int> stk;
        
        for (int i = 0; i < n; i++) {
            // 若heights[i] < heights[stk.top()]，栈顶元素弹出，直至所剩栈顶元素高度小于等于heights[i]或栈空
            // 同时每次弹出计算以所弹出元素为高度的（最大）矩形的面积，宽度(len)为当前栈顶元素下标到(i - 1)
            // 若栈空，len = (i - 1) - 0 + 1 = i
            // 若栈非空， len = (i - 1) - stk.top()(弹出计算高度的栈顶元素后的top) = i - 1 - stk.top()
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int len = i;
                if (!stk.empty()) len = i - stk.top() - 1;
                res = res > len * h ? res : len * h;
            }
            // 若heights[i] > heights[stk.top()]，继续入栈
            stk.push(i);
        }

        while (!stk.empty()) {
            int h = heights[stk.top()];
            stk.pop();
            int len = n;
            if (!stk.empty()) len = n - stk.top() - 1;
            res = res > len * h ? res : len * h;
        }

        return res;
    }
};

int main84() {
    Solution84 solution;
    int n;
    cin >> n;
    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heights.push_back(x);
    }
    cout << solution.largestRectangleArea(heights) << endl;
    system("pause");
    return 0;
}