#include <iostream>

#include "TreeNode.h"

using namespace std;

class Solution124 {
public:
	int max(const int a, const int b) {
		return a > b ? a : b;
	}
	
	int max_gain(TreeNode* node, int& max_sum) {
        if (!node) return 0;

        int left_gain = max(max_gain(node->left, max_sum), 0);
        int right_gain = max(max_gain(node->right, max_sum), 0);

        int price_newpath = node->val + left_gain + right_gain;

        max_sum = max(max_sum, price_newpath);

        return node->val + max(left_gain, right_gain);
	}
	
    int maxPathSum(TreeNode* root) {
		int max_sum = INT_MIN;
        max_gain(root, max_sum);

		return max_sum;
    }
};