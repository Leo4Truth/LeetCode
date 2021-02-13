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

// 用于sort的compare函数
// 必须定义为全局
bool cmp (vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution987 {
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

    vector<vector<int>> verticalTraversal(TreeNode* root) {
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

int main(int argc, char* argv[]) {
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    Solution987 solution;
    vector<vector<int>> res = solution.verticalTraversal(n1);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ", ";
        }
        cout << endl;
    }

    //system("pause");
    return 0;
}
