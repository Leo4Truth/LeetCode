#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution99 {
public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder = inorderTraversal(root);
        sort(inorder.begin(), inorder.end());
        stack<TreeNode*> stk;
        TreeNode* current = root;
        int i = 0;
        while (true) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            if (!stk.empty()) {
                stk.top()->val = inorder[i];
                i++;
                current = stk.top()->right;
                stk.pop();
            }
            else break;
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while (true) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            if (!stk.empty()) {
                res.push_back(stk.top()->val);
                current = stk.top()->right;
                stk.pop();
            }
            else break;
        }
        return res;
    }
};

int main99() {
    Solution99 solution;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    n1->left = n3;
    n3->right = n2;
    TreeNode* root = n1;
    vector<int> origin = solution.inorderTraversal(root);
    for (int i = 0; i < origin.size(); i++) {
        cout << origin[i] << " ";
    }
    cout << endl;
    solution.recoverTree(root);
    vector<int> res = solution.inorderTraversal(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}