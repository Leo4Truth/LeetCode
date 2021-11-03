#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // mono stack
    int trap_stack_21_07_21(vector<int>& height) {
        if (height.size() == 0 || height.size() == 1) return 0;
        stack<int> stk;
        int sum = 0;
        int current = 0;
        while (current < height.size()) {
            while (!stk.empty() && height[stk.top()] < height[current]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int d = current - stk.top() - 1;
                int bound_height = (height[current] < height[stk.top()] ? height[current] : height[stk.top()]) - height[top];
                sum += d * bound_height;
            }
            stk.push(current++);
        }
        return sum;
    }

    int trap_doublePointers(vector<int>& height) {
        if (height.size() == 0 || height.size() == 1) return 0;
        int leftMax = 0, rightMax = height.size() - 1;
        int left = 0, right = height.size() - 1;
        int vol = 0;
        while (true) {
            while (left < right && height[leftMax] <= height[rightMax]) {
                if (height[left] < height[leftMax]) {
                    vol += height[leftMax] - height[left];
                    cout << "left + " << height[leftMax] - height[left] << endl;
                }
                else leftMax = left;
                left++;
            }
            if (left == right) {
                if (height[left] < height[leftMax] && height[left] < height[rightMax])
                    vol += (height[leftMax] < height[rightMax] ? height[leftMax] : height[rightMax]) - height[left];
                break;
            }
            while (left < right && height[leftMax] >= height[rightMax]) {
                if (height[right] < height[rightMax]) {
                    vol += height[rightMax] - height[right];
                    cout << "right + " << height[rightMax] - height[right] << endl;
                }
                else rightMax = right;
                right--;
            }
            if (left == right) {
                if (height[left] < height[leftMax] && height[left] < height[rightMax])
                    vol += (height[leftMax] < height[rightMax] ? height[leftMax] : height[rightMax]) - height[left];
                break;
            }
        }
        return vol;
    }

    int trap_stack(vector<int>& height) {
        int vol = 0, current = 0;
        stack<int> stk;
        while (current < height.size()) {
            while (!stk.empty() && height[current] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int distance = current - stk.top() - 1;
                int bounded_height = (height[current] < height[stk.top()] ? height[current] : height[stk.top()]) - height[top];
                vol += distance * bounded_height;
            }
            stk.push(current++);
        }
        return vol;
    }
};

int main() {
    Solution solution;
    int n;
    vector<int> height;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << "double pointers: " << solution.trap_doublePointers(height) << endl;
    cout << "stack: " << solution.trap_stack(height) << endl;
    system("pause");
    return 0;
}