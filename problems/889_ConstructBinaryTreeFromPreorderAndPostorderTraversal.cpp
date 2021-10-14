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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        if (n == 0) return nullptr;
        return _constructFromPrePost(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    /**
     * 1 2 4 5 3 6 7
     * 7
     */
    TreeNode* _constructFromPrePost(vector<int>& preorder, int pre_l, int pre_r, vector<int>& postorder, int post_l, int post_r) {
        if (pre_l > pre_r || post_l > post_r) return nullptr;
        if (pre_l == pre_r) return new TreeNode(preorder[pre_l]);
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[pre_l]);
        int left_root_val = preorder[pre_l + 1];
        int right_root_val = postorder[post_r - 1];
        int pre_right_l = pre_l + 1;
        int post_left_r = post_r - 1;
        while (preorder[pre_right_l] != left_root_val) pre_right_l++;
        while (postorder[post_left_r] != right_root_val) post_left_r--;
        root->left = _constructFromPrePost(preorder, pre_l + 1, pre_right_l - 1, postorder, post_left_r + 1, post_r);
        root->right = _constructFromPrePost(preorder, pre_right_l, pre_r, postorder, post_l, post_left_r);
        return root;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> preorder;
    vector<int> postorder;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        preorder.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        postorder.push_back(x);
    }

    Solution solution;
    TreeNode* root = solution.constructFromPrePost(preorder, postorder);

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
