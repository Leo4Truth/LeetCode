#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define DEBUG

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution133 {
public:
    // bfs
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
#ifdef DEBUG
        vector<Node*> newNodes;
#endif // DEBUG
        unordered_map<Node*, int> color;
        unordered_map<Node*, Node*> map;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (color[node] == 0) {
                Node* newNode = new Node(node->val);
                map[node] = newNode;
                color[node] = 2;
#ifdef DEBUG
                newNodes.push_back(newNode);
#endif // DEBUG
            }
            else if (color[node] == 1) color[node] = 2;

            for (auto adjNode : node->neighbors) {
                // not visited yet
                if (color[adjNode] == 0) {
                    q.push(adjNode);
                    Node* newNode = new Node(adjNode->val);
                    map[adjNode] = newNode;
                    color[adjNode] = 1;
                    map[node]->neighbors.push_back(map[adjNode]);
                    map[adjNode]->neighbors.push_back(map[node]);
#ifdef DEBUG
                    newNodes.push_back(newNode);
#endif // DEBUG
                }
                else if (color[adjNode] == 1) {
                    q.push(adjNode);
                    map[node]->neighbors.push_back(map[adjNode]);
                    map[adjNode]->neighbors.push_back(map[node]);
                }
            }
        }

#ifdef DEBUG
        for (auto newNode : newNodes) {
            cout << newNode->val << ": ";
            for (auto adj : newNode->neighbors) cout << adj->val << ",";
            cout << endl;
        }
#endif // DEBUG
        return map[node];
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n1);
    n3->neighbors.push_back(n2);

    Solution133 solution;
    Node* cloneNode = solution.cloneGraph(n1);

    return 0;
}

