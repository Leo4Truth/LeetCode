#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;

        int n = heights.size();
        if (n == 0) return res;
        if (n == 1) return heights[0];

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int len = i;
                if (!stk.empty()) len = i - stk.top() - 1;
                res = res > len * h ? res : len * h;
            }
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

int main() {
    Solution solution;

    return 0;
}