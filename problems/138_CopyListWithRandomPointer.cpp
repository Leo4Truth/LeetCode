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

class Solution {
public:
    // Pass
    // Time  Complexity: O(N), defeat 88.52%
    // Space Complexity: O(1), defeat 72.92%
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* head2 = nullptr;
        Node* curr1 = nullptr;
        Node* curr2 = nullptr;
        curr1 = head;
        // copy
        while (curr1) {
            curr2 = new Node(curr1->val * 2);
            if (!head2) head2 = curr2;
            curr2->next = curr1->next;
            curr1->next = curr2;
            curr1 = curr2->next;
        }
        // set random ptr
        curr1 = head;
        curr2 = head2;
        while (curr1) {
            if (curr1->random) curr2->random = curr1->random->next;
            else curr2->random = nullptr;
            curr1 = curr2->next;
            if (curr1) curr2 = curr1->next;
            else curr2 = nullptr;
        }
        // break the copy linked list
        Node* prev1 = nullptr;
        Node* prev2 = nullptr;
        curr1 = head;
        curr2 = head2;
        while (curr1) {
            prev1 = curr1;
            prev2 = curr2;
            curr1 = curr2->next;
            if (curr1) curr2 = curr1->next;
            else curr2 = nullptr;
            prev1->next = curr1;
            prev2->next = curr2;
        }
        return head2;
    }

    Node* copyRandomList_21_07_05(Node* head) {
        if (!head) return nullptr;
        Node* head2 = nullptr;
        Node* current2 = nullptr;
        Node* prev2 = nullptr;
        Node* current1 = head;
        unordered_map<Node*, Node*> map;
        while (current1) {
            current2 = new Node(current1->val);
            if (!head2) head2 = current2;
            else prev2->next = current2;
            prev2 = current2;
            map[current1] = current2;
            current1 = current1->next;
        }
        current1 = head;
        current2 = head2;
        while (current1) {
            current2->random = map[current1->random];
            current1 = current1->next;
            current2 = current2->next;
        }
        return head2;
    }

    Node* copyRandomList_hashmap(Node* head) {
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


int main(int argc, char* argv[]) {
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n1->random = n3;
    n2->random = n4;
    n3->random = n5;
    n4->random = n1;
    n5->random = n2;

    Solution solution;
    Node* h = solution.copyRandomList(n1);
    Node* p = n1;
    cout << "origin: ";
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    p = h;
    cout << "copy  : ";
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    p = h;
    cout << "copy r: ";
    while (p) {
        if (p->random) cout << p->random->val << " ";
        else cout << "  ";
        p = p->next;
    }
    cout << endl;
    
    return 0;
}