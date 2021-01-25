#include <iostream>
#include <vector>


#include "TreeNode.h"

using namespace std;

class Solution108 {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
    	
        auto* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }
	
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nullptr;
        return helper(nums, 0, n - 1);
    }
};

int main108() {
    Solution108 solution;

    vector<int> nums = { -10, -3, 0, 5 ,9 };

    auto* root = solution.sortedArrayToBST(nums);

    system("pause");

    return 0;
}