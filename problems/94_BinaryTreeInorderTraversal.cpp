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

class Solution94 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while (true) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            if (!stk.empty()) {
                res.push_back(stk.top()->val);
                current = stk.top()->right;
                stk.pop();
            }
            else break;
        }
        return res;
    }
    

    vector<int> solve20240316(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* current = root;
        while (true) {
            while (current) {
                stk.push(current);
                current = current->left;
            }
            if (!stk.empty()) {
                res.push_back(stk.top()->val);
                current = stk.top()->right;
                stk.pop();
            }
            else break;
        }
        return res;
    }
};

int main() {
    Solution94 solution;
    TreeNode* root;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    root = n1;
    n1->right = n2;
    n2->left = n3;
    vector<int> res = solution.inorderTraversal(root);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    vector<int> res2 = solution.solve20240316(root);
    cout << "[";
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i];
        if (i < res2.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    return 0;
}