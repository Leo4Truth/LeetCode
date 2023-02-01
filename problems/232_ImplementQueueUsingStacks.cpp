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

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        while (!stk1.empty()) {
            stk0.push(stk1.top());
            stk1.pop();
        }
        stk0.push(x);
    }
    
    int pop() {
        while (!stk0.empty()) {
            stk1.push(stk0.top());
            stk0.pop();
        }
        int x = stk1.top();
        stk1.pop();
        return x;
    }
    
    int peek() {
        while (!stk0.empty()) {
            stk1.push(stk0.top());
            stk0.pop();
        }
        int x = stk1.top();
        return x;
    }
    
    bool empty() {
        return stk0.empty() && stk1.empty();
    }

private:
    stack<int> stk0, stk1;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char* argv[]) {
    MyQueue *q = new MyQueue();
    string op;
    cin >> op;
    while (op.compare("end") != 0) {
        if (op.compare("push") == 0) {
            int x;
            cin >> x;
            q->push(x);
        }
        else if (op.compare("pop") == 0) {
            q->pop();
        }
        else if (op.compare("peek") == 0) {
            cout << q->peek() << endl;
        }
        else if (op.compare("empty") == 0) {
            cout << q->empty() << endl;
        }
        else {
            cout << "invalid operation." << endl;
        }
        cin >> op;
    }

    return 0;
}
