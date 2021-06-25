#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class NumArraySegmentTree {
public:
    NumArraySegmentTree(vector<int>& nums) {
        int n = nums.size();
        queue<Node*> q;
        for (int i = 0; i < n; i++) {
            Node* node = new Node(nums[i], i, i);
            q.push(node);
        }
        while (q.size() > 1) {
            Node* left = q.front();
            q.pop();
            Node* right = nullptr;
            if (!q.empty()) {
                right = q.front();
                q.pop();
            }
            Node* parent = new Node(left->sum + right->sum, left->start, right ? right->end : left->end);
            parent->left = left;
            parent->right = right;
            q.push(parent);
        }
        if (q.size() == 1) {
            root = q.front();
            q.pop();
        }
        else root = nullptr;
    }
    
    void update(int index, int val) {
        Node* node = root;
        stack<Node*> stk;
        while (node) {
            stk.push(node);
            int mid = (node->start + node->end) / 2;
            if (index >= node->start && index <= mid) node = node->left;
            else if (index > mid && index <= node->right) node = node->right;
            else return;
        }
        int old = stk.top()->sum;
        while (!stk.empty()) {
            node = stk.top();
            stk.pop();
            node->sum = node->sum - old + val;
        }
    }
    
    int sumRange(int left, int right) {
        
    }

private:
    class Node {
    public:
        int sum;
        int start;
        int end;
        Node* left;
        Node* right;
        Node(int _sum, int _start, int _end) : sum(_sum), start(_start), end(_end), left(nullptr), right(nullptr) {}
    };
    Node* root;
};

// Prefix
// Limit Time Exceeded
class NumArrayPrefix {
public:
    NumArrayPrefix(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sums.push_back(sum);
        }
        printSums();
    }
    
    void update(int index, int val) {
        int n = sums.size();
        int tmp = index == 0 ? 0 : sums[index - 1];
        for (int i = index; i < n; i++) {
            sums[i] = sums[i] - (sums[index] - tmp) + val; 
        }
        printSums();
    }
    
    int sumRange(int left, int right) {
        if (left < 0 || left > right) return 0;
        return left == 0 ? sums[right] : sums[right] - sums[left - 1];
    }

    void printSums() {
        for (int i = 0; i < sums.size(); i++) {
            cout << sums[i] << " ";
        }
        cout << endl;
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
