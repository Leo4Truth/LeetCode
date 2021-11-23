#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

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
    virtual int maxDepth(Node* root) = 0;
};

class Solution_queue : public Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        int depth = 0;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            // 这里用 auto , 不能用 auto&
            auto p = q.front();
            q.pop();
            depth = p.second > depth ? p.second : depth;
            for (auto child : p.first->children) q.push(make_pair(child, p.second + 1));
        }
        return depth;
    }

private:
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

    Solution *solution = nullptr;

    solution = new Solution_queue();
    cout << "queue: " << solution->maxDepth(n1) << endl;

    return 0;
}
