#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


#include "../lib/Node.h"

using namespace std;

class Solution {
public:
    Node* findRoot_1(vector<Node*> tree) {
        unordered_set<Node*> set;
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i]) {
                for (auto* child : tree[i]->children) set.insert(child);
            }
        }

        for (int i = 0; i < tree.size(); i++) {
            if (!set.count(tree[i])) return tree[i];
        }
    }

    Node* findRoot_2(vector<Node*> tree) {
        unordered_map<int, Node*> map;
        int sum = 0;
        int children_sum = 0;
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i]) {
                map[tree[i]->val] == tree[i];
                sum += tree[i]->val;
                for (auto* child : tree[i]->children) children_sum += child->val;
            }
        }
        
        cout << sum << endl;
        cout << children_sum << endl;

        return map[sum - children_sum];
    }

    Node* constructNAryTreeFromNodeList(vector<Node*> nodeList) {
        vector<int> parent;
        parent.push_back(-1);
        int root = -1;
        int size = nodeList.size();
        for (int i = 1; i < size; i++) {
            if (!nodeList[i]) {
                root++;
                while (root < 0 || !nodeList[root])
                    root++;
                parent.push_back(-1);
            }
            else  parent.push_back(root);
            if (nodeList[i]) cout << nodeList[i]->val << " root " << root << endl;
            else cout << "null" << " root " << -1 << endl;
        }

        for (int i = 0; i < size; i++) {
            if (nodeList[i] && parent[i] >= 0) {
                nodeList[parent[i]]->children.push_back(nodeList[i]);
            }
        }

        for (int i = 0; i < size; i++) {
            if (nodeList[i]) {
                cout << nodeList[i]->val << " children: ";
                for (auto child : nodeList[i]->children)
                    cout << child->val << " ";
            }
            cout << endl;
        }

        return nodeList[0];
    }

    void print(Node* root) {
        if (!root) return;
        cout << root->val << ", ";
        for (Node* child : root->children) print(child);
    }
};

int main(int argc, char* argv[]) {
    vector<Node*> tree;
    int n;
    cout << "please input size of node list: ";
    cin >> n;
    cout << "please input " << n << " nodes (null node represented by 0): " << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) tree.push_back(new Node(x));
        else tree.push_back(nullptr);
    }

    Solution solution;
    Node* root = solution.findRoot_2(tree);
    
    solution.print(root);

    return 0;
}