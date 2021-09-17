#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define DEBUG

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(vector<int>& pre, vector<int>& vin, int lpre, int rpre, int lin, int rin) {
#ifdef DEBUG
        cout << "preorder: ";
        for (int i = lpre; i <= rpre; i++) cout << pre[i] << " ";
        cout << endl;
        cout << "inorder: ";
        for (int i = lin; i <= rin; i++) cout << vin[i] << " ";
        cout << endl;
#endif // DEBUG
        int target = pre[lpre];
        int mid = lin;
        while (mid <= rin && vin[mid] != target) mid++;
        if (mid > rin) return nullptr;
        int nleft = mid - lin;
        TreeNode* root = new TreeNode(target);
        root->left = helper(pre, vin, lpre + 1, lpre + nleft, lin, mid - 1);
        root->right = helper(pre, vin, lpre + nleft + 1, rpre, mid + 1, rin);
        return root;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        int n = pre.size();
#ifdef DEBUG
        cout << "n = " << n << endl;
#endif // DEBUG
        return helper(pre, vin, 0, n - 1, 0, n-1);
    }

    void print(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        int level = 0;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            cout << level++ << ": ";
            while (!q1.empty()) {
                TreeNode* node = q1.front();
                cout << node->val << " ";
                q1.pop();
                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
            }
            cout << endl;
            cout << level++ << ": ";
            while (!q2.empty()) {
                TreeNode* node = q2.front();
                cout << node->val << " ";
                q2.pop();
                if (node->left) q1.push(node->left);
                if (node->right) q1.push(node->right);
            }
            cout << endl;
        }
    }

};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> pre;
    vector<int> vin;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pre.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vin.push_back(x);
    }

    Solution solution;
    TreeNode* root = solution.reConstructBinaryTree(pre, vin);

#ifdef DEBUG
    solution.print(root);
#endif // DEBUG

    //system("pause");
    return 0;
}

