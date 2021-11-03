#include <iostream>
#include <queue>

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
    // BFS, iterative
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) return false;

        queue<TreeNode*> queue1, queue2;
        queue1.push(p);
        queue2.push(q);

        while (!queue1.empty() && !queue2.empty()) {
            auto node1 = queue1.front();
            queue1.pop();
            auto node2 = queue2.front();
            queue2.pop();
            if (node1->val != node2->val) return false;

            auto left1 = node1->left, right1 = node1->right;
            auto left2 = node2->left, right2 = node2->right;

            if (left1 == nullptr ^ left2 == nullptr) return false;
            if (right1 == nullptr ^ right2 == nullptr) return false;

            if (left1 != nullptr) queue1.push(left1);
            if (right1 != nullptr) queue1.push(right1);
            if (left2 != nullptr) queue2.push(left2);
            if (right2 != nullptr) queue2.push(right2);
        }

        return queue1.empty() && queue2.empty();
    }
};

int main() {
    Solution solution;

    auto* n0 = new TreeNode(0);
    auto* n1 = new TreeNode(1);
    auto* n2 = new TreeNode(2);
    auto* n3 = new TreeNode(3);
    auto* n4 = new TreeNode(4);
    auto* n5 = new TreeNode(5);

    auto* n00 = new TreeNode(0);
    auto* n11 = new TreeNode(1);
    auto* n22 = new TreeNode(2);
    auto* n33 = new TreeNode(3);
    auto* n44 = new TreeNode(4);
    auto* n55 = new TreeNode(5);

    auto* root1 = n0;
    n0->left = n1;
    n0->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;

    auto* root2 = n00;
    n00->left = n11;
    n00->right = n22;
    n11->left = n33;
    n11->right = n44;
    n22->left = n55;

    cout << "Is same: " << solution.isSameTree(root1, root2) << endl;
	
    system("pause");

    return 0;
}
