#include <iostream>
#include <vector>
#include <stack>

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

class Solution98 {
public:
    bool isValidBST_iterative(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long min, long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }

    bool isValidBST_inorderTraversal(TreeNode* root) {
        long inorder = LONG_MIN;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while (!stk.empty() || current) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top();
            stk.pop();
            if (current->val <= inorder) return false;
            inorder = current->val;
            current = current->right;
        }
        return true;
    }
};

int main98() {
    Solution98 solution;
    TreeNode* root;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(5);
    n2->left = n1;
    n2->right = n3;
    root = n2;
    cout << solution.isValidBST_inorderTraversal(root) << endl;
    system("pause");
    return 0;
}