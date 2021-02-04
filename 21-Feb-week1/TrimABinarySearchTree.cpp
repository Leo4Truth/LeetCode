#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution669 {
public:
    TreeNode* trimBST_rec(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;
        if (root->val > high) return trimBST_rec(root->left, low, high);
        if (root->val < low) return trimBST_rec(root->right, low, high);

        root->left = trimBST_rec(root->left, low, high);
        root->right = trimBST_rec(root->right, low, high);
        return root;
    }
};

