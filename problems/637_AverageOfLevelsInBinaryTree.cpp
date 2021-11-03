#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution637 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(root);
        int level = 0;
        while (true) {
            long long sum = 0;
            int cnt = 0;
            if (!q1.empty()) {
                cnt = q1.size();
                while (!q1.empty()) {
                    TreeNode* node = q1.front();
                    q1.pop();
                    if (node->left) q2.push(node->left);
                    if (node->right) q2.push(node->right);
                    sum += node->val;
                }
            }
            else if (!q2.empty()) {
                cnt = q2.size();
                while (!q2.empty()) {
                    TreeNode* node = q2.front();
                    q2.pop();
                    if (node->left) q1.push(node->left);
                    if (node->right) q1.push(node->right);
                    sum += node->val;
                }
            }
            else break;
            res.push_back((double) sum / cnt);
            level++;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = NULL;

    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    root = n1;

    Solution637 solution;
    vector<double> res = solution.averageOfLevels(root);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}

