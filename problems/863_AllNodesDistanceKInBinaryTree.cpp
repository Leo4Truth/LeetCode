#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

// DFS + HashMap
class Solution {
public:
    // build graph and bfs
    vector<int> distanceK_buildMapBFS(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};
        // bfs build graph
        unordered_map<TreeNode*, vector<TreeNode*>> adjList;
        queue<TreeNode*> q;
        q.push(root);
        adjList[root] = vector<TreeNode*>();
        while (!q.empty()) {
            TreeNode* p = q.front();
#ifdef DEBUG
            cout << p->val << endl;
#endif // DEBUG
            q.pop();
            if (p->left) {
                adjList[p].push_back(p->left);
                adjList[p->left] = vector<TreeNode*>(1, p);
                q.push(p->left);
            }
            if (p->right) {
                adjList[p].push_back(p->right);
                adjList[p->right] = vector<TreeNode*>(1, p);
                q.push(p->right);
            }
        }
#ifdef DEBUG
        cout << endl;
        for (auto entry : adjList) {
            cout << entry.first->val << ": ";
            for (auto x : entry.second) cout << x->val << " ";
            cout << endl;
        }
        cout << endl;
#endif // DEBUG
        // bfs
        vector<int> res;
        bfs(target, nullptr, adjList, 0, k, res);
        return res;
    }

    void bfs(TreeNode* curr, TreeNode* from, unordered_map<TreeNode*, vector<TreeNode*>>& adjList, int dis, int k, vector<int>& res) {
#ifdef DEBUG
        cout << curr->val << endl;
#endif // DEBUG
        if (dis == k) {
            res.push_back(curr->val);
            return;
        }
        for (auto adj : adjList[curr]) {
            if (adj != from) bfs(adj, curr, adjList, dis + 1, k, res);
        }
    }

    // Official Solution
    vector<int> distanceK_official(TreeNode* root, TreeNode* target, int k) {
        // 从 root 出发 DFS，记录每个结点的父结点
        findParents(root);

        // 从 target 出发 DFS，寻找所有深度为 k 的结点
        findAns(target, nullptr, 0, k);

        return ans;
    }

private:
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;

    void findParents(TreeNode* node) {
        if (node->left != nullptr) {
            parents[node->left->val] = node;
            findParents(node->left);
        }
        if (node->right != nullptr) {
            parents[node->right->val] = node;
            findParents(node->right);
        }
    }

    void findAns(TreeNode* node, TreeNode* from, int depth, int k) {
        if (node == nullptr) {
            return;
        }
        if (depth == k) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != from) {
            findAns(node->left, node, depth + 1, k);
        }
        if (node->right != from) {
            findAns(node->right, node, depth + 1, k);
        }
        if (parents[node->val] != from) {
            findAns(parents[node->val], node, depth + 1, k);
        }
    }
};

int main(int argc, char* argv[]) {
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(8);

    n3->left = n5;
    n3->right = n1;
    n5->left = n6;
    n5->right = n2;
    n2->left = n7;
    n2->right = n4;
    n1->left = n0;
    n1->right = n8;

    Solution solution;
    vector<int> res = solution.distanceK_buildMapBFS(n3, n5, 2);
    for (auto x : res) cout << x << " ";
    cout << endl;

    //system("pause");
    return 0;
}
