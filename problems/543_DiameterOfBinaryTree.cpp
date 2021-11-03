#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return current;
    }

    int depth(TreeNode* root) {
        if (!root) return 0;
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        current = max(current, ldepth + rdepth);
        return max(ldepth, rdepth) + 1;
    }

private:
    int current = 0;
};

int main(int argc, char* argv[]) {
    Solution solution;
    
    return 0;
}
