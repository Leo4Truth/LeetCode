#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution145 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (!root->right || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);

    /**
     *      1
     *     / \
     *    2   3
     *       / \
     *      4   5
     * post order traversal: [2, 4, 5, 3, 1]
     */
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    TreeNode* root = n1;

    Solution145 solution;
    vector<int> postorder = solution.postorderTraversal(root);
    cout << "[";
    for (int i = 0; i < postorder.size(); i++) {
        cout << postorder[i];
        if (i < postorder.size() - 1) cout << ",";
    }
    cout << "]" << endl;
    
    return 0;
}
