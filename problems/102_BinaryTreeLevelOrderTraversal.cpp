#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution102 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res = vector<vector<int>>();
    	// empty tree
    	if (!root) return res;

        queue<TreeNode*> queues[2] = {
            queue<TreeNode*>(),
            queue<TreeNode*>()
        };
    	
        auto current = 0;
        auto next = 1;
        queues[current].push(root);
    	while (!queues[current].empty()) {
            vector<int> level;
    		while (!queues[current].empty()) {
	            auto* node = queues[current].front();
                queues[current].pop();
                level.push_back(node->val);
                if (node->left) queues[next].push(node->left);
                if (node->right) queues[next].push(node->right);
    		}
            res.push_back(level);
            swap(current, next);
    	}
        return res;
    }

    static void swap(int &a, int &b) {
	    const auto tmp = a;
        a = b;
        b = tmp;
    }
};

int main102() {
    Solution102 solution;
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
	 *  [n0, n1, n2, n3, n4, n5]
	 */
    auto* root = n0;
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    auto res = solution.levelOrder(root);
	for (const auto& level : res) {
        cout << "[";
		for (auto node_val : level) {
            cout << node_val << " ";
		}
        cout << "]" << endl;
	}

    system("pause");

    return 0;
}