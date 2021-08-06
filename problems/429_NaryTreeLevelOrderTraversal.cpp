#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<Node*> q1;
        queue<int> q2;

        q1.push(root);
        q2.push(0);
        while (!q1.empty()) {
            Node* node = q1.front();
            q1.pop();
            int d = q2.front();
            q2.pop();
            if (d == res.size()) res.push_back(vector<int>(0));
            res[d].push_back(node->val);
            for (auto child : node->children) {
                q1.push(child);
                q2.push(d + 1);
            }
        }

        return res;
    }
};

int main(int argc, char* argv[]) {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);

    n1->children.push_back(n3);
    n1->children.push_back(n2);
    n1->children.push_back(n4);
    n3->children.push_back(n5);
    n3->children.push_back(n6);

    Solution solution;
    vector<vector<int>> res = solution.levelOrder(n1);
    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << "\t[";
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j < res[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < res.size() - 1) cout << ",";
        cout << endl;
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}
