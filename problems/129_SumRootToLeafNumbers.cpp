#include <iostream>
#include <vector>
#include <stack>

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
	virtual int sumNumbers(TreeNode* root) = 0;
};

class Solution_backtrack : public Solution {
public:
	void backtrack(TreeNode* node, int current, vector<int>& nums) {
		if (!node) return;
		if (!node->left && !node->right) nums.push_back(current * 10 + node->val);
		else {
			if (node->left) backtrack(node->left, current * 10 + node->val, nums);
			if (node->right) backtrack(node->right, current * 10 + node->val, nums);
		}
	}
	
    int sumNumbers(TreeNode* root) {
		vector<int> nums;
		backtrack(root, 0, nums);
		int sum = 0;
		for (auto num : nums) sum += num;
		return sum;
    }
};

class Solution_dfs : public Solution {
public:
	// dfs
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		stack<pair<TreeNode*, int>> stk;
		stk.push(pair<TreeNode*, int>(root, root->val));
		while (!stk.empty()) {
			pair<TreeNode*, int> p = stk.top();
			stk.pop();
			if (!p.first->left && !p.first->right) sum += p.second;
			if (p.first->left) stk.push(make_pair(p.first->left, p.second * 10 + p.first->left->val));
			if (p.first->right) stk.push(make_pair(p.first->right, p.second * 10 + p.first->right->val));
		}
		return sum;
	}
};

int main(int argc, char* argv[]) {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);

	n1->left = n2;
	n1->right = n3;

	Solution *solution = nullptr;

	solution = new Solution_backtrack();
	cout << solution->sumNumbers(n1) << endl;
	
	solution = new Solution_dfs();
	cout << solution->sumNumbers(n1) << endl;

	return 0;
}