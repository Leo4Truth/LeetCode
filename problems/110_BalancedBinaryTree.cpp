#include <iostream>

#include "TreeNode.h"

using namespace std;

class Solution110 {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
    	// 当前节点平衡的充分必要条件：
    	// 1. 左右子树height差不超过1
    	// 2. 左子树平衡
    	// 3. 右子树平衡
        if (abs(height(root->left) - height(root->right)) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
    	return false;
    }

	int height(TreeNode* root) const {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main110() {
    Solution110 solution;

    auto* n0 = new TreeNode(0);
    auto* n1 = new TreeNode(1);
    auto* n2 = new TreeNode(2);
    auto* n3 = new TreeNode(3);
    auto* n4 = new TreeNode(4);
    auto* n5 = new TreeNode(5);
    auto* n6 = new TreeNode(6);

    /*
     *      n3
     *     /  \
     *    n1   n4
     *   / \    \
     *  n0 n2    n5
     */
    auto* root = n3;
    n3->left = n1;
    n3->right = n4;
    n1->left = n0;
    n1->right = n2;
    n4->right = n5;
    n5->right = n6;

    cout << "Is balanced: " << solution.isBalanced(root) << endl;
	
    system("pause");

    return 0;
}