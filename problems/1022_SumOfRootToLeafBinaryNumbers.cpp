#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

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
    virtual int sumRootToLeaf(TreeNode* root) = 0;
};

class Solution_init : public Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, root->val));
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* n = p.first;
            int curr = p.second;
            if (!n->left && !n->right) sum += curr;
            if (n->left) q.push(make_pair(n->left, curr * 2 + n->left->val));
            if (n->right) q.push(make_pair(n->right, curr * 2 + n->right->val));
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(0);
    TreeNode* n7 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution *solution = nullptr;

    solution = new Solution_init();
    cout << solution->sumRootToLeaf(n1) << endl;

    return 0;
}
