#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        int len = 0;
        int max = 0;
        stack<int> stk;
        // 开始循环前
        stk.push(-1);
        for (int i = 0; i < s.size(); i++) {
            // 遇到'('，将该字符在字符串中的下标直接压入堆栈
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                // 遇到')'，将堆栈顶端的元素抛出
                if (!stk.empty()) {
                    stk.pop();
                    // 更新len为当前字符下标减去栈顶元素（抛出之后的栈顶）
                    if (!stk.empty()) {
                        len = i - stk.top();
                        // 检查，更新max
                        if (len > max) max = len;
                    }
                }
                // 如果抛出栈顶元素后，堆栈空，将当前元素下标入栈
                if (stk.empty()) stk.push(i);
            }
        }
        return max;
    }
};