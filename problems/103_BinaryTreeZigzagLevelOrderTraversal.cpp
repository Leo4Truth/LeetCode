#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "TreeNode.h"

using namespace std;

class Solution103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res = vector<vector<int>>();
        // empty tree
        if (!root) return res;
    	
        stack<TreeNode*> stacks[2] = {
            stack<TreeNode*>(),
            stack<TreeNode*>()
        };
        
        auto current = 0;
        auto next = 1;
        stacks[current].push(root);
        while (!stacks[current].empty()) {
            vector<int> level;
            while (!stacks[current].empty()) {
                auto* node = stacks[current].top();
                stacks[current].pop();
                level.push_back(node->val);
            	if (current == 0) {
                    if (node->left) stacks[next].push(node->left);
                    if (node->right) stacks[next].push(node->right);
            	}
                else {
                    if (node->right) stacks[next].push(node->right);
                    if (node->left) stacks[next].push(node->left);
                }
                
            }
            res.push_back(level);
            swap(current, next);
        }
        return res;
    }

    static void swap(int& a, int& b) {
        const auto tmp = a;
        a = b;
        b = tmp;
    }
};


int main103() {
    Solution103 solution;

	auto* n0 = new TreeNode(0);
    auto* n1 = new TreeNode(1);
    auto* n2 = new TreeNode(2);
    auto* n3 = new TreeNode(3);
    auto* n4 = new TreeNode(4);
    auto* n5 = new TreeNode(5);

    /*
     *      n0
     *     /  \
     *    n1   n2
     *   / \    \
     *  n3 n4    n5
     *  [n0, n2, n1, n3, n4, n5]
     */
    auto* root = n0;
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    vector<vector<int>> res = solution.zigzagLevelOrder(root);
    for (const auto& level : res) {
        cout << "[";
        for (auto node_val : level) {
            cout << node_val << " ";
        }
        cout << "]" << endl;
    }

    system("pause");

    return 0;
}