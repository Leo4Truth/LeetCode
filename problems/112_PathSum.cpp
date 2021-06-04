#include <iostream>
#include <stack>


#include "TreeNode.h"

using namespace std;

class Solution112 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;

        stack<pair<TreeNode*, int>> stk;

        stk.push(pair<TreeNode*, int>(root, root->val));
    	while (!stk.empty()) {
            auto nodeSum = stk.top();
            stk.pop();

            auto* left = nodeSum.first->left;
            auto* right = nodeSum.first->right;
            auto currentSum = nodeSum.second;

            if (!left && !right && currentSum == sum) return true;

            if (left) stk.push(pair<TreeNode*, int>(left, currentSum + left->val));
            if (right) stk.push(pair<TreeNode*, int>(right, currentSum + right->val));
    	}

        return false;
    }

	bool hasPathSum_rec(TreeNode* root, int sum) {
        if (!root) return false;

        sum -= root->val;
        if (!root->left && !root->right) return sum == 0;
        return hasPathSum_rec(root->left, sum) || hasPathSum_rec(root->right, sum);
    }
};