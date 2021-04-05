#include <iostream>
#include <stack>


#include "TreeNode.h"

using namespace std;

class Solution111 {
public:
    int minDepth_dfs(TreeNode* root) {
        if (!root) return 0;
    	
        int min = INT_MAX;
        stack<TreeNode*> stk;
        stack<int> d_stk;
    	
        stk.push(root);
        d_stk.push(1);
    	while (!stk.empty()) {
            auto* node = stk.top();
            stk.pop();
            int d = d_stk.top();
            d_stk.pop();

    		if (!node->left && !node->right)
    			if (d < min) min = d;

            if (node->left) {
                stk.push(node->left);
                d_stk.push(d + 1);
            }
            if (node->right) {
                stk.push(node->right);
                d_stk.push(d + 1);
            }
    	}

        return min;
    }

	int minDepth_rec(TreeNode* root) {
        if (!root) return 0;

        if (!root->left && !root->right) return 1;

        int min = INT_MAX;
        if (root->left) {
            int d = minDepth_rec(root->left);
            min = min < d ? min : d;
        }
        if (root->right) {
            int d = minDepth_rec(root->right);
            min = min < d ? min : d;
        }

        return min + 1;
    }
};
