#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution86 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;

        ListNode* h1 = nullptr;
        ListNode* p1 = nullptr;
        ListNode* h2 = nullptr;
        ListNode* p2 = nullptr;
        ListNode* current = head;

        while (current) {
            ListNode* tmp = new ListNode(current->val);
            if (current->val < x) {
                if (!h1) h1 = tmp;
                else p1->next = tmp;
                p1 = tmp;
            }
            else {
                if (!h2) h2 = tmp;
                else p2->next = tmp;
                p2 = tmp;
            }
            current = current->next;
        }

        if (h1) {
            p1->next = h2;
            return h1;
        }
        else return h2;
    }
};

int main86() {
    Solution86 solution;
    int n;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* current = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current = new ListNode(x);
        if (!head) head = current;
        else prev->next = current;
        prev = current;
    }
    int x;
    cin >> x;
    ListNode* res = solution.partition(head, x);
    ListNode* ptr = res;
    while (ptr) {
        cout << ptr->val;
        if (ptr->next) cout << "->";
        ptr = ptr->next;
    }
    cout << endl;
    system("pause");
    return 0;
}