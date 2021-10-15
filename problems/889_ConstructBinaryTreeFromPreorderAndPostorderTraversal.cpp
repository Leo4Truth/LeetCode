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
        if (n == 0 || n != postorder.size()) return nullptr;
        // entry of the recursive call
        return _constructFromPrePost(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    TreeNode* _constructFromPrePost(vector<int>& preorder, int pre_l, int pre_r, vector<int>& postorder, int post_l, int post_r) {
        int n = preorder.size();
        // return nullptr if any argument is invalid
        if (pre_l < 0 || pre_r >= n || post_l < 0 || post_r >= n) return nullptr;
        if (pre_l > pre_r || post_l > post_r) return nullptr;
        if (pre_r - pre_l != post_r - post_l) return nullptr;

        TreeNode* root =  new TreeNode(preorder[pre_l]);
        if (pre_l == pre_r) return root;
        int left_val = preorder[pre_l + 1];
        int right_val = postorder[post_r - 1];
        // have only one child
        if (left_val == right_val) {
            root->left = _constructFromPrePost(preorder, pre_l + 1, pre_r, postorder, post_l, post_r - 1);
            return root;
        }
        int pre_right_root_idx = pre_l + 1;
        int post_left_root_idx = post_r - 1;
        cout << left_val << " " << right_val << endl;
        cout << pre_right_root_idx << " " << post_left_root_idx << endl;
        while (preorder[pre_right_root_idx] != right_val) pre_right_root_idx++;
        while (postorder[post_left_root_idx] != left_val) post_left_root_idx--;
        root->left = _constructFromPrePost(preorder, pre_l + 1, pre_right_root_idx - 1, postorder, post_l, post_left_root_idx);
        root->right = _constructFromPrePost(preorder, pre_right_root_idx, pre_r, postorder, post_left_root_idx + 1, post_r - 1);
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
