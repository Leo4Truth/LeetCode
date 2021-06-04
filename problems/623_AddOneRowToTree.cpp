#include <iostream>
#include <vector>
#include <queue>

#define DEBUG

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution623 {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<vector<TreeNode*>> levels;

        int depth = 1;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            depth++;
            vector<TreeNode*> level;
            if (!q1.empty()) {
                while (!q1.empty()) {
                    TreeNode* node = q1.front();
                    q1.pop();
                    level.push_back(node);
                    if (depth == d) {
                        TreeNode* l = node->left;
                        TreeNode* r = node->right;
                        node->left = new TreeNode(v);
                        node->left->left = l;
                        node->right = new TreeNode(v);
                        node->right->right = r;
                    }
                    if (node->left) q2.push(node->left);
                    if (node->right) q2.push(node->right);
                }
            }
            else if (!q2.empty()) {
                while (!q2.empty()) {
                    TreeNode* node = q2.front();
                    q2.pop();
                    level.push_back(node);
                    if (depth == d) {
                        TreeNode* l = node->left;
                        TreeNode* r = node->right;
                        node->left = new TreeNode(v);
                        node->left->left = l;
                        node->right = new TreeNode(v);
                        node->right->right = r;
                    }
                    if (node->left) q1.push(node->left);
                    if (node->right) q1.push(node->right);
                }
            }
            levels.push_back(level);
        }

#ifdef DEBUG
        cout << "[" << endl;
        for (int i = 0; i < levels.size(); i++) {
            cout << "\t[";
            for (int j = 0; j < levels[i].size(); j++) {
                cout << levels[i][j]->val;
                if (j < levels[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i < levels.size() - 1) cout << ", ";
            cout << endl;
        }
        cout << "]" << endl;
#endif // DEBUG

        return root;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(4);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n5 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(5);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    TreeNode* root = n1;

    Solution623 solution;
    TreeNode* res = solution.addOneRow(root, 1, 2);

    //system("pause");
    return 0;
}
