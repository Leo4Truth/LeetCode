#include <iostream>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int val_) : val(val_), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    /**
     * iterative dfs, use a stack to store the next nodes
     * Time Complexity: O(N),  access each node once
     * Space Complexity: O(N), the worst case is half of nodes need to be pushed into the stack
     */
    Node* flatten_stack(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        stack<Node*> next_stk;
        while (true) {
            if (curr->next && curr->child) {
                next_stk.push(curr->next);
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
                curr = curr->next;
            } else if (curr->next) {
                curr = curr->next;
            } else if (curr->child) {
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
                curr = curr->next;
            } else {
                if (!next_stk.empty()) {
                    curr->next = next_stk.top();
                    next_stk.pop();
                    curr->next->prev = curr;
                    curr = curr->next;
                } else {
                    // break the loop when no child not next and not node stored in stack
                    break;
                }
            }
        }
        return head;
    }
};

int main(int argc, char* argv[]) {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);
    Node* n11 = new Node(11);
    Node* n12 = new Node(12);

    n1->next = n2;

    n2->next = n3;
    n2->prev = n1;

    n3->next = n4;
    n3->prev = n2;
    n3->child = n7;

    n4->next = n5;
    n4->prev = n3;

    n5->next = n6;
    n5->prev = n4;
    
    n6->prev = n5;

    n7->next = n8;
    
    n8->next = n9;
    n8->prev = n7;
    n8->child = n11;

    n9->next = n10;
    n9->prev = n8;

    n10->prev = n9;

    n11->next = n12;
    
    n12->prev = n11;

    Solution solution;
    Node* head = solution.flatten(n1);

    Node* p = head;
    while (p) {
        cout << p->val;
        if (p->next) {
            cout << "->";
        }
        p = p->next;
    }
    cout << endl;

    return 0;
}
