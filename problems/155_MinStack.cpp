#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// One Stack, push diff
class MinStack {
private:
    stack<int> stk;
    int min;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        if (stk.empty()) {
            min = val;
            stk.push(val);
        }
        else {
            stk.push(val - min);
            if (val < min) min = val; // Update min
        }
    }
    
    void pop() {
        if (stk.empty()) return;
        int top = stk.top();
        stk.pop();
        if (top < 0) min = min - top();
    }
    
    int top() {
        int top = stk.top();
        if (top < 0) return min;
        else return top + min;
    }
    
    int getMin() {
        return min;
    }
};

// Two Stack
class MinStack_TwoStack {
private:
    stack<int> stk;
    stack<int> minStk;

public:
    /** initialize your data structure here. */
    MinStack() {
        minStk.push(INT32_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        minStk.push(min(minStk.top(), val));
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

class MinStack_naive {
public:
    /** initialize your data structure here. */
    MinStack() {
        this->capacity = 10;
        this->array = new int[this->capacity];
        this->size = 0;
    }
    
    void push(int val) {
        if (size < capacity) array[size++] = val;
        else {
            capacity *= 2;
            int *newArray = new int[this->capacity];
            for (int i = 0; i < size; i++) newArray[i] = array[i];
            delete[] array;
            array = newArray;
        }
    }
    
    void pop() {
        if (size > 0) size--;
    }
    
    int top() {
        if (size > 0) return array[size - 1];
        return -1;
    }
    
    int getMin() {
        int min = INT32_MAX;
        for (int i = 0; i < size; i++) min = array[i] < min ? array[i] : min;
        return min;
    }

private:
    int *array;
    int capacity;
    int size;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char* argv[]) {
    MinStack stk;

    //system("pause");
    return 0;
}
