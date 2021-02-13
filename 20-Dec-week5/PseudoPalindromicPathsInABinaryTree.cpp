#include <iostream>
#include <vector>
#include <unordered_map>

#include "E:/repo/LeetCodeChallenge/lib/TreeNode.h"

using namespace std;

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int> map, int &paths) {
        if (root) map[root->val]++;
        else return;

        // if reach the leaf node
        if (!root->left && !root->right) {
            int oddCnt = 0;
            for (auto cnt : map) {
                if (cnt.second % 2 == 1) oddCnt++;
            }
            if (oddCnt > 1) return;
            else paths++;
        }
        if (root->left) dfs(root->left, map, paths);
        if (root->right) dfs(root->right, map, paths);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        if (!root) return 0;
        unordered_map<int, int> map;
        int paths = 0;

        dfs(root, map, paths);

        return paths;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;

    auto* n0 = new TreeNode(2);
    auto* n1 = new TreeNode(3);
    auto* n2 = new TreeNode(3);
    auto* n3 = new TreeNode(1);
    auto* n4 = new TreeNode(1);
    auto* n5 = new TreeNode(1);

    auto* root = n0;
    n0->left = n1;
    n0->right = n3;
    n1->left = n2;
    n1->right = n4;
    n3->right = n5;

    cout << "Pseudo-Palindromic Paths: " << solution.pseudoPalindromicPaths(root) << endl;

    return 0;
}