#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    virtual string removeOuterParentheses(string s) = 0;
};

/**
 * @brief 栈匹配括号, 栈非空时每个字符都直接计入结果
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution_Stack : public Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> stk;
        for (auto c : s) {
            if (c == ')') stk.pop();
            if (!stk.empty()) res.push_back(c);
            if (c == '(') stk.emplace(c);
        }
        return res;
    }
};

/**
 * @brief 因为字符串的括号一定匹配, 因此可以直接计数, '(' + 1, ')' - 1, 和为0时去除外层()计入结果
 * Time Complexity: O(N)
 * Space Complexity: O(N), 除了结果之外并不需要额外的空间
 */
class Solution_Count : public Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        string curr;
        int count = 0;
        for (auto c : s) {
            if (c == '(') count++;
            if (c == ')') count--;
            curr.push_back(c);
            if (count == 0) {
                res.append(decomposition(curr));
                curr = "";
            }
        }
        return res;
    }

private:
    string decomposition(string s) {
        return s.substr(1, s.length() - 2);
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution *solution = nullptr;

    solution = new Solution_Stack();
    cout << "Stack: " << solution->removeOuterParentheses(s) << endl;
    
    solution = new Solution_Count();
    cout << "Count: " << solution->removeOuterParentheses(s) << endl;

    return 0;
}
