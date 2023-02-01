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
    virtual bool isUnivalTree(TreeNode* root) = 0;
};

class Solution_Recursive : public Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return isSameAsParent(root->left, root->val) && isSameAsParent(root->right, root->val);
    }

private:
    bool isSameAsParent(TreeNode* node, int val) {
        if (!node) return true;
        if (node->val != val) return false;
        return isSameAsParent(node->left, val) && isSameAsParent(node->right, val);
    }
};

class Solution_InorderIterative : public Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> stk;
        stack<TreeNode* > s;
        TreeNode* curr = root;
        while(!stk.empty() || curr){
            while (curr) {
                if (curr->val != root->val) return false;
                stk.push(curr);
                curr = curr->left;
            }
            TreeNode* node = stk.top();
            stk.pop();
            curr = node->right;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(1);
    TreeNode* n5 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(1);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;

    Solution *solution = nullptr;

    solution = new Solution_Recursive();
    cout << "Recursive: " << solution->isUnivalTree(n1) << endl;
    
    solution = new Solution_InorderIterative();
    cout << "Inorder  : " << solution->isUnivalTree(n1) << endl;

    return 0;
}
