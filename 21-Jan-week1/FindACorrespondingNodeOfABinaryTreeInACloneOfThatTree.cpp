#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (!original || !cloned || !target) return nullptr;

        stack<TreeNode*> stk1, stk2;
        stk1.push(original);
        stk2.push(cloned);

        while (!stk1.empty()) {
            auto* p1 = stk1.top();
            auto* p2 = stk2.top();
            stk1.pop();
            stk2.pop();

            if (p1 == target) return p2;

            if (p1->left) {
                stk1.push(p1->left);
                stk2.push(p2->left);
            }
            if (p1->right) {
                stk1.push(p1->right);
                stk2.push(p2->right)
            }
        }

        return nullptr;
    }
};