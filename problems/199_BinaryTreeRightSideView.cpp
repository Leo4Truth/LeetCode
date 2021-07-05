#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution199 {
public:
    static void swap(int &a, int &b) {
	    const auto tmp = a;
        a = b;
        b = tmp;
    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        vector<vector<int>> levelOrder = vector<vector<int>>();
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
            levelOrder.push_back(level);
            swap(current, next);
    	}

        for (auto level : levelOrder) res.push_back(level.back());

        return res;
    }
};

