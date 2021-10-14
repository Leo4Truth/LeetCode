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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        return _bstFromPreorder(preorder, 0, preorder.size() - 1);
    }

private:
    TreeNode* _bstFromPreorder(vector<int>& preorder, int l, int r) {
        int n = preorder.size();
        if (l == r) return new TreeNode(preorder[l]);
        if (l < r && r < n) {
            int rroot = l + 1;
            while (rroot < n && rroot <= r && preorder[rroot] <= preorder[l]) rroot++;
            TreeNode* root = new TreeNode(preorder[l]);
            root->left = _bstFromPreorder(preorder, l + 1, rroot - 1);
            root->right = _bstFromPreorder(preorder, rroot, r);
            return root;
        }
        return nullptr;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> preorder;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    
    Solution solution;
    TreeNode* root = solution.bstFromPreorder(preorder);

    stack<TreeNode*> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        cout << p->val << ", ";
        if (p->right) stk.push(p->right);
        if (p->left) stk.push(p->left); 
    }
    
    return 0;
}
