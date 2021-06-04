#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

/**
 * @brief return the shortest path from node a to node b in a binary search tree.
 */
class Solution {
public:
    vector<Node*> treePath(Node* root, int a, int b) {
        deque<Node*> dqa;
        deque<Node*> dqb;

        Node* p = root;
        bool foundA = false;
        while (p) {
            dqa.push_back(p);
            if (p->val < a) p = p->right;
            else if (p->val > a) p = p->left;
            else {
                foundA = true;
                break;
            }
        }
        if (!foundA) return {}; // if a not found in tree, return empty result

        p = root;
        bool foundB = false;
        while (p) {
            dqb.push_back(p);
            if (p->val < b) p = p->right;
            else if (p->val > b) p = p->left;
            else {
                foundB = true;
                break;
            }
        }
        if (!foundB) return {}; // if b not found in tree, return empty result
        
        Node* pa = dqa.front();
        Node* pb = dqb.front();
        Node* lastSame = pa;
        while (pa == pb) {
            dqa.pop_front();
            dqb.pop_front();
            lastSame = pa;
            pa = dqa.front();
            pb = dqb.front();
        }
        
        vector<Node*> pathFromA2B;
        while (!dqa.empty()) {
            pathFromA2B.push_back(dqa.back());
            dqa.pop_back();
        }
        pathFromA2B.push_back(lastSame); // the last common node 
        while (!dqb.empty()) {
            pathFromA2B.push_back(dqb.front());
            dqb.pop_front();
        }

        return pathFromA2B;
    }
};

int main(int argc, char* argv[]) {
    Node* n0 = new Node(0);
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    n3->left = n2;
    n2->left = n0;
    n0->right = n1;
    n3->right = n5;
    n5->left = n4;
    n5->right = n6;
    n6->right = n7;

    Solution solution;
    vector<Node*> path = solution.treePath(n3, 1, 6);
    for (auto node : path) {
        cout << node->val << " ";
    }
    cout << endl;

    return 0;
}
