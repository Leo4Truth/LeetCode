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
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) return -1;
        int x = stack2.top();
        stack2.pop();
        return x;
    }

private:
    stack<int> stack1 = stack<int>();
    stack<int> stack2 = stack<int>();
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<string> ops;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            nums.push_back(x);
        }
        else nums.push_back(-1);
        ops.push_back(op);
    }

    Solution solution;
    for (int i = 0; i < n; i++) {
        if (ops[i] == "push") solution.push(nums[i]);
        else if (ops[i] == "pop") {
            int x = solution.pop();
            if (x == -1) {
                cout << "Pop from empty queue!" << endl;
                return -1;
            }
            cout << x << endl;
        }
        else {
            cout << "wrong operation!" << endl;
            return -1;
        }
    }

    //system("pause");
    return 0;
}

