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
    // inorder
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return -1;
        vector<int> inorder;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            if (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                inorder.push_back(cur->val);
                if (inorder.size() == k) return inorder.back();
                cur = cur->right;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);

    n5->left= n3;
    n5->right = n6;
    n3->left = n2;
    n3->right = n4;
    n2->left = n1;

    Solution solution;
    cout << solution.kthSmallest(n5, 3) << endl;

    return 0;
}
