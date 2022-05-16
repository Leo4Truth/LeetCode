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
    virtual TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) = 0;
};

/**
 * @brief standard iterative inorder traversal using stack
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
class Solution_Stack : public Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return nullptr;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            if (prev == p) return curr;
            prev = curr;
            curr = curr->right;
        }
        return nullptr;
    }
};

/**
 * @brief use the property of BST
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
class Solution_BSTProperty : public Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *successor = nullptr;
        if (p->right != nullptr) {
            successor = p->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }
            return successor;
        }
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val > p->val) {
                successor = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return successor;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    n2->left = n1;
    n2->right = n3;

    Solution *solution = nullptr;

    solution = new Solution_Stack();
    cout << "Inorder traversal using stack: " << solution->inorderSuccessor(n2, n1)->val << endl;

    solution = new Solution_BSTProperty();
    cout << "use BST property             : " << solution->inorderSuccessor(n2, n1)->val << endl;

    return 0;
}
