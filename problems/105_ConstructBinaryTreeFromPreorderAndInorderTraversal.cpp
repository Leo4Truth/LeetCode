#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution105 {
private:
    unordered_map<int, int> index;

public:
	// Time: O(N), Space: O(N)
	TreeNode* buildTreeRoutine(vector<int>& preorder, vector<int>& inorder, 
        int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) return nullptr;

        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        auto* root = new TreeNode(preorder[preorder_root]);
        int left_size = inorder_root - inorder_left;
        root->left = buildTreeRoutine(preorder, inorder, preorder_left + 1, preorder_left + left_size, inorder_left, inorder_root - 1);
        root->right = buildTreeRoutine(preorder, inorder, preorder_left + left_size + 1, preorder_right, inorder_root + 1, inorder_right);

		return root;
	}
	
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
		for (auto i = 0; i < n; i++) {
            index[inorder[i]] = i;
		}
        return buildTreeRoutine(preorder, inorder, 0, n - 1, 0, n - 1);
    }

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

    static void swap(int& a, int& b) {
        const auto tmp = a;
        a = b;
        b = tmp;
    }
};

int main105() {
    Solution105 solution;

    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };

    auto* root = solution.buildTree(preorder, inorder);

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