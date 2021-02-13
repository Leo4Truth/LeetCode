#include <iostream>
#include <stack>
#include <vector>


#include "TreeNode.h"

using namespace std;

class Solution104 {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
    	
        int max_depth = 0;
        stack<int> depth;
        stack<TreeNode*> stack;

    	stack.push(root);
        depth.push(1);
    	while (!stack.empty()) {
            auto* node = stack.top();
            stack.pop();
            const auto d = depth.top();
            depth.pop();

            max_depth = d > max_depth ? d : max_depth;

            if (node->left) {
                stack.push(node->left);
                depth.push(d + 1);
            }
            if (node->right) {
                stack.push(node->right);
                depth.push(d + 1);
            }
    	}

        return max_depth;
    }
};

int main104() {
    Solution104 solution;

    auto* n0 = new TreeNode(0);
    auto* n1 = new TreeNode(1);
    auto* n2 = new TreeNode(2);
    auto* n3 = new TreeNode(3);
    auto* n4 = new TreeNode(4);
    auto* n5 = new TreeNode(5);

    /*
     *      n0
     *     /  \
     *    n1   n2
     *   / \    \
     *  n3 n4    n5
     *  [n0, n2, n1, n3, n4, n5]
     */
    auto* root = n0;
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    cout << "Max Depth: " << solution.maxDepth(root) << endl;

    system("pause");

    return 0;
}