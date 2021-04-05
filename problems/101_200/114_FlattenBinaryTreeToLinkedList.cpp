#include <iostream>
#include <queue>
#include <stack>



#include "TreeNode.h"

using namespace std;

class Solution114 {
public:
	// 先序遍历，stack，right先入栈，left后入栈
    void flatten(TreeNode* root) {
        if (!root) return;

        stack<TreeNode*> stk;

        TreeNode* head = nullptr;
    	TreeNode* prev = nullptr;
        TreeNode* current = nullptr;

    	stk.push(root);
    	while (!stk.empty()) {
            current = stk.top();
            stk.pop();

            if (current->right) stk.push(current->right);
            if (current->left) stk.push(current->left);

            current->left = nullptr;
            current->right = nullptr;

            if (!head) head = current;
            else prev->right = current;
            prev = current;
    	}

        root = head;
    }
};