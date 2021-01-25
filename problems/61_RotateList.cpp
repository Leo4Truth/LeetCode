#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution61 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int n = 0;
        ListNode* current = head;
        while (true) {
            n++;
            if (current->next == nullptr) {
                current->next = head;
                break;
            }
            else current = current->next;
        }
        k = n - k % n;
        current = head;
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
        }
        ListNode* res = current->next;
        current->next = nullptr;
        return res;
    }
};

int main61() {
    Solution61 solution;
    int n;
    ListNode* list = nullptr;
    ListNode* prev = nullptr;
    ListNode* current = nullptr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current = new ListNode(x);
        if (!list) list = current;
        else prev->next = current;
        prev = current;
    }
    current = list;
    for (int i = 0; i < n; i++) {
        cout << current->val << "->";
        current = current->next;
    }
    cout << "NULL" << endl;
    int k;
    cin >> k;
    ListNode* res = solution.rotateRight(list, k);
    for (int i = 0; i < n; i++) {
        cout << res->val << "->";
        res = res->next;
    }
    cout << "NULL" << endl;
    system("pause");
    return 0;
}