#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void backtrack(TreeNode* node, int current, vector<int>& nums) {
		if (!node) return;
		if (!node->left && !node->right) nums.push_back(current * 10 + node->val);
		else {
			if (node->left) backtrack(node->left, current * 10 + node->val, nums);
			if (node->right) backtrack(node->right, current * 10 + node->val, nums);
		}
	}
	
    int sumNumbers_backtrack(TreeNode* root) {
		vector<int> nums;
		backtrack(root, 0, nums);
		int sum = 0;
		for (auto num : nums) sum += num;
		return sum;
    }

	// dfs
	int sumNumbers(TreeNode* root) {
		deque<pair<TreeNode*, int>> stk;
		stk.push_back(pair<TreeNode*, int>(root, root->val));
		while (!stk.empty()) {
			auto p = stk.back();
			stk.pop_back();
			if (p.first->left) stk.push_back(pair<TreeNode*, int>(p.first->left, p.second * 10 + p.first->val));
			if (p.first->left) stk.push_back(pair<TreeNode*, int>(p.first->left, p.second * 10 + p.first->val));
		}
	}
};