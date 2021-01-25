#include <iostream>
#include <queue>
#include <vector>


#include "TreeNode.h"

using namespace std;

class Solution113 {
public:
	void helper(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (!root) return;

        path.push_back(root->val);

        if (sum == root->val && !root->left && !root->right) res.push_back(path);
        else {
            helper(root->left, sum - root->val, path, res);
            helper(root->right, sum - root->val, path, res);
        }

        path.pop_back();
	}
	
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, sum, path, res);
        return res;
    }
};