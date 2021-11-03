#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n == 0) return true;
        if (n % 2 != 0) return false;

        stack<char> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                char top = stk.top();
                stk.pop();
                if (top == '(' && s[i] == ')') continue;
                else if (top == '[' && s[i] == ']') continue;
                else if (top == '{' && s[i] == '}') continue;
                else return false;
            }
        }

        return stk.empty();
    }
};

int main(int argc, char* argv[]) {
    string s = argc >= 2 ? argv[1] : "";

    Solution solution;
    cout << solution.isValid(s) << endl;

    //system("pause");
    return 0;
}
