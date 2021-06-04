#include <iostream>

#include "TreeNode.h"

using namespace std;

class Solution101 {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        // Three Conditions of p and q are mirror:
        // 1. The value of node p and node q are same
        // 2. The left child of node p and the right child of node q are mirror
        // 3. The right child of node p and the left child of node q are mirror
        return p->val == q->val &&
            isMirror(p->left, q->right) &&
            isMirror(p->right, q->left);
    }
};

int main101() {
    Solution101 solution;

    auto* n0 = new TreeNode(0);
    auto* n1 = new TreeNode(1);
    auto* n2 = new TreeNode(2);
    auto* n3 = new TreeNode(3);
    auto* n4 = new TreeNode(4);
    auto* n5 = new TreeNode(5);

    auto* root = n0;
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;

    cout << "Is symmetric: " << solution.isSymmetric(root) << endl;
	
    system("pause");

    return 0;
}