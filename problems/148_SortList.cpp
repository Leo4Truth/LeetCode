#include <iostream>
#include <vector>

#define DEBUG

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Quick Sort
    ListNode* sortList_quick(ListNode* head) {
        return quicksort(head)[0];
    }

    vector<ListNode*> quicksort(ListNode* head) {
        if (!head || !head->next) return {head, head};
        // nodes[0] nodes[1] nodes[2] nodes[3] nodes[4] nodes[5]
        // less than pivot   equal to pivot    more than pivot
        vector<ListNode*> nodes = partition(head);
        vector<ListNode*> part1 = quicksort(nodes[0]);
        vector<ListNode*> part2 = quicksort(nodes[4]);
#ifdef DEBUG
        cout << "part1: ";
        for (ListNode* p = part1[0]; p; p = p->next) cout << p->val << " ";
        cout << endl;
        cout << "mid  : ";
        for (ListNode* p = nodes[2]; p; p = p->next) cout << p->val << " ";
        cout << endl;
        cout << "part2: ";
        for (ListNode* p = part2[0]; p; p = p->next) cout << p->val << " ";
        cout << endl;
#endif // DEBUG
        ListNode* h = part1[0];
        if (part1[1]) part1[1]->next = nodes[2];
        else h = nodes[2];
        nodes[3]->next = part2[0];
        ListNode* t = part2[1];
        if (!part2[0]) t = nodes[3];
        return {h, t};
    }

    vector<ListNode*> partition(ListNode* head) {
        if (!head) return vector<ListNode*>(6, nullptr);
        if (!head->next) return {nullptr, nullptr, head, head, nullptr, nullptr};
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p1->next && p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        int pivot = p1->val;
#ifdef DEBUG
        cout << "pivot: " << pivot << endl;
#endif // DEBUG
        ListNode* h1 = nullptr;
        ListNode* h2 = nullptr;
        ListNode* h3 = nullptr;
        ListNode* t1 = nullptr;
        ListNode* t2 = nullptr;
        ListNode* t3 = nullptr;
        for (ListNode* p = head; p; p = p->next) {
            if (p->val < pivot) {
                if (!h1) h1 = p;
                else t1->next = p;
                t1 = p;
            }
            else if (p->val > pivot) {
                if (!h3) h3 = p;
                else t3->next = p;
                t3 = p;
            }
            else {
                if (!h2) h2 = p;
                else t2->next = p;
                t2 = p;
            }
        }
        if (t1) t1->next = nullptr;
        if (t2) t2->next = nullptr;
        if (t3) t3->next = nullptr;
#ifdef DEBUG
        cout << "left :";
        for (ListNode* p = h1; p; p = p->next) cout << p->val << " ";
        cout << endl;
        cout << "mid  :";
        for (ListNode* p = h2; p; p = p->next) cout << p->val << " ";
        cout << endl;
        cout << "right:";
        for (ListNode* p = h3; p; p = p->next) cout << p->val << " ";
        cout << endl;
#endif // DEBUG
        return {h1, t1, h2, t2, h3, t3};
    }

    // Merge Sort
    // Recursive
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        ListNode* prev = nullptr;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                current = p1;
                p1 = p1->next;
            }
            else {
                current = p2;
                p2 = p2->next;
            }
            if (!head) head = current;
            else prev->next = current;
            prev = current;
        }
        if (p1) prev->next = p1;
        if (p2) prev->next = p2;
        return head; 
    }

    ListNode* getMid(ListNode* head) {
        if (!head) return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p2 = p1->next;
        p1->next = nullptr;
        return p2;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(mid);
        return merge(p1, p2);
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 8;
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    ListNode* prev = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current = new ListNode(x);
        if (!head) head = current;
        else prev->next = current;
        prev = current;
    }

    ListNode* p = head;
    cout << "origin: ";
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    Solution solution;
    ListNode* sortedHead = solution.sortList_quick(head);
    p = sortedHead;
    cout << "sorted: ";    
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}
