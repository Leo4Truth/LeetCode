#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution92 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* t1 = head;
        ListNode* h3 = head;
        for (int i = 1; i <= n; i++) {
            if (i < m - 1) t1 = t1->next;
            h3 = h3->next;
        }
        if (m == 1) {
            head = reverseFirstN(head, n - m + 1);
            t1->next = h3;
        }
        else {
            ListNode* h2 = reverseFirstN(t1->next, n - m + 1);
            t1->next->next = h3;
            t1->next = h2;
        }
        return head;
    }

    ListNode* reverseFirstN(ListNode* head, int n) {
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = current->next;
        ListNode* newTail = head;
        ListNode* newHead = nullptr;
        for (int i = 1; i < n; i++) {
            current->next = prev;
            prev = current;
            if (!next) {
                //TODO: n < list length
                ;
            };
            ListNode* nextNext = next->next;
            next->next = current;
            current = next;
            next = nextNext;
        }
        newHead = current;
        newTail->next = next;
        return newHead;
    }
};

int main92() {
    Solution92 solution;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* current = nullptr;
    int k;
    cout << "input the length of the list: " << endl;
    cin >> k;
    cout << "input the list: " << endl;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        current = new ListNode(x);
        if (!head) head = current;
        if (prev) prev->next = current;
        prev = current;
    }
    int m, n;
    cout << "input m and n: " << endl;
    cin >> m >> n;
    ListNode* res = solution.reverseBetween(head, m, n);
    //ListNode* res = solution.reverseFirstN(head, m);
    for (current = res; current; current = current->next) {
        cout << current->val;
        if (current->next) cout << "->";
    }
    cout << endl;
    system("pause");
    return 0;
}