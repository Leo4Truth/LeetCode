#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>


#include "TreeNode.h"

using namespace std;

class Solution106 {
private:
    unordered_map<int, int> index;

public:
	TreeNode* buildTreeRoutine(vector<int>& inorder, vector<int>& postorder,
        int inorder_left, int inorder_right, int postorder_left, int postorder_right) {
        if (postorder_left > postorder_right) return nullptr;

        int postorder_root = postorder_right;
        int inorder_root = index[postorder[postorder_root]];

        int left_size = inorder_root - inorder_left;
		
        auto* root = new TreeNode(postorder[postorder_root]);
        root->left = buildTreeRoutine(inorder, postorder, inorder_left, inorder_root - 1, postorder_left, postorder_left + left_size - 1);
        root->right = buildTreeRoutine(inorder, postorder, inorder_root + 1, inorder_right, postorder_left + left_size, postorder_right - 1);

        return root;
	}
	
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) return nullptr;
        for (auto i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildTreeRoutine(inorder, postorder, 0, n - 1, 0, n - 1);
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

int main106() {
    Solution106 solution;

    vector<int> inorder = { 9,3,15,20,7 };
    vector<int> postorder = { 9,15,7,20,3 };

    auto* root = solution.buildTree(inorder, postorder);

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