#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution150 {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            string token = tokens[i];
            if (token == "+") {
                int operand1, operand2;
                if (!stk.empty()) {
                    operand2 = stk.top();
                    stk.pop();
                }
                else return -1;
                if (!stk.empty()) {
                    operand1 = stk.top();
                    stk.pop();
                }
                else return -1;
                stk.push(operand1 + operand2);
            }
            else if (token == "-") {
                int operand1, operand2;
                if (!stk.empty()) {
                    operand2 = stk.top();
                    stk.pop();
                }
                else return -1;
                if (!stk.empty()) {
                    operand1 = stk.top();
                    stk.pop();
                }
                else return -1;
                stk.push(operand1 - operand2);
            }
            else if (token == "*") {
                int operand1, operand2;
                if (!stk.empty()) {
                    operand2 = stk.top();
                    stk.pop();
                }
                else return -1;
                if (!stk.empty()) {
                    operand1 = stk.top();
                    stk.pop();
                }
                else return -1;
                stk.push(operand1 * operand2);
            }
            else if (token == "/") {
                int operand1, operand2;
                if (!stk.empty()) {
                    operand2 = stk.top();
                    stk.pop();
                }
                else return -1;
                if (!stk.empty()) {
                    operand1 = stk.top();
                    stk.pop();
                }
                else return -1;
                stk.push(operand1 / operand2);
            }
            else {
                int num = stoi(token);
                stk.push(num);
            }
        }
        if (stk.size() == 1) return stk.top();
        else return -1;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> tokens;
    for (int i = 0; i < n; i++) {
        string token;
        cin >> token;
        tokens.push_back(token);
    }

    Solution150 solution;
    cout << solution.evalRPN(tokens) << endl;

    //system("pause");
    return 0;
}

