#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution138 {
public:
    Node* copyRandomList(Node* head) {
        Node* h2 = nullptr;
        unordered_map<Node*, Node*> map;
        Node* current1 = head;
        Node* current2 = nullptr;
        Node* prev2 = nullptr;
        while (current1) {
            current2 = new Node(current1->val);
            if (!prev2) h2 = current2;
            else prev2->next = current2;
            prev2 = current2;
            map[current1] = current2;
            current1 = current1->next;
        }
        current1 = head;
        current2 = h2;
        while (current1) {
            current2->random = map[current1->random];
            current1 = current1->next;
            current2 = current2->next;
        }
        return h2;
    }
};
