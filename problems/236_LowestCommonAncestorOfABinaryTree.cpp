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
    // dfs recursive
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    TreeNode* ans = nullptr;
    /**
     * @brief 
     * return true if:
     *  1. p is root
     *  2. q is root
     *  3. p is a descendant of root
     *  4. p is a descendant of root
     */

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || root->val == p->val || root->val == q->val) ans = root;
        return lson || rson || root->val == p->val || root->val == q->val;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);

    n3->left = n5;
    n3->right = n1;
    n5->left = n6;
    n5->right = n2;
    n2->left = n7;
    n2->right = n4;
    n1->left = n0;
    n1->right = n8;

    Solution solution;
    TreeNode* ans = solution.lowestCommonAncestor(n3, n5, n1);
    cout << (ans ? ans->val : -1) << endl;

    //system("pause");
    return 0;
}
