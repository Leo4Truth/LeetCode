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
    TreeNode* pruneTree(TreeNode* root) {
        return containsOne(root) ? root : nullptr;
    }

    bool containsOne(TreeNode* root) {
        if (!root) return false;
        bool leftContainsOne = containsOne(root->left);
        bool rightContainsOne = containsOne(root->right);
        if (!leftContainsOne) root->left = nullptr;
        if (!rightContainsOne) root->right = nullptr;
        return root->val == 1 || leftContainsOne || rightContainsOne;
    }
};

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
