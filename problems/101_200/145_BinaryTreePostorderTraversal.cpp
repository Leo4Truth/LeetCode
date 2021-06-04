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
        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (node || !stk.empty()) {
            while (node) {
                if (node->right) stk.push(node->right);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            
        }
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

    //system("pause");
    return 0;
}
