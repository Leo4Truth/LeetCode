#include <iostream>
#include <vector>
#include <stack>

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

class Solution95 {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return { nullptr };

        vector<TreeNode*> res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            
            for (auto& lt : leftTrees) {
                for (auto& rt : rightTrees) {
                    TreeNode* curTree = new TreeNode(i, lt, rt);
                    res.emplace_back(curTree);
                }
            }
        }
        return res;
    }

    void print(TreeNode* root) {
        ;
    }
};

int main95() {
    Solution95 solution;
    int n;
    cin >> n;
    vector<TreeNode*> res = solution.generateTrees(n);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "\t";
        solution.print(res[i]);
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}