#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

bool cmp (vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution314 {
public:
    deque<vector<vector<int>>> deq;
    int left = 0;
    int right = 0;


    void dfs(TreeNode* node, int partition, int depth) {
        if (node) {
            if (partition < left) {
                left--;
                deq.push_front(vector<vector<int>>());
            }
            else if (partition > right) {
                right++;
                deq.push_back(vector<vector<int>>());
            }
            else {
                if (deq.empty()) deq.push_back(vector<vector<int>>());
            }
            deq[partition - left].push_back(vector<int>{node->val, depth});
            dfs(node->left, partition - 1, depth + 1);
            dfs(node->right, partition + 1, depth + 1);
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);

        vector<vector<int>> res;
        for (auto partition : deq) {
            sort(partition.begin(), partition.end(), cmp);
            vector<int> tmp;
            for (auto p : partition) tmp.push_back(p[0]);
            res.push_back(tmp);
        }
        return res;
    }
};
