#include <iostream>
#include <queue>

using namespace std;

// one queue
// pass
// Time:  0 ms, defeat 100%
// Space: 6.7 MB, defeat 50.60%
class MyStack_oneQueue {
public:
    /** Initialize your data structure here. */
    MyStack_oneQueue() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        int len = q.size();
        q.push(x);
        for (int i = 0; i < len; i++) {
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element = q.front();
        q.pop();
        return element;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};

// two queues
// pass
// Time:  4 ms, defeat 32.75%
// Space: 6.6 MB, defeat 77.54%
class MyStack_twoQueues {
public:
    /** Initialize your data structure here. */
    MyStack_twoQueues() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q[current].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int next = !current;
        while (q[current].size() > 1) {
            q[next].push(q[current].front());
            q[current].pop();
        }
        int element = q[current].front();
        q[current].pop();
        current = next;
        return element;
    }
    
    /** Get the top element. */
    int top() {
        int next = !current;
        while (q[current].size() > 1) {
            q[next].push(q[current].front());
            q[current].pop();
        }
        int element = q[current].front();
        q[current].pop();
        q[next].push(element);
        current = next;
        return element;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[current].empty() && q[!current].empty();
    }

private:
    queue<int> q[2];
    int current = 0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
