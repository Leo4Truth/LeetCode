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

class Solution82 {
public:
    ListNode* deleteDuplicates_std(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;

        while (p1 && p2) {
            while (p2->next && p2->val == p2->next->val) p2 = p2->next;
            
            if (p1 != p2) {
                if (prev) prev->next = p2->next;
                else head = p2->next; 
            }
            else prev = p1;

            p1 = p2->next;
            p2 = p2->next;
        }
        
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* res = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            //if (prev) cout << "prev: " << prev->val;
            //if (current) cout << ", " << "current: " << current->val << endl;

            bool dup = false;
            while (current->next && current->val == current->next->val) {
                dup = true;
                current = current->next;
            }
            if (!dup) {
                if (!res) res = current;
                if (prev) prev->next = current;
                prev = current;
            }
            else {
                if (prev) prev->next = nullptr;
            }
            current = current->next;
        }
        return res;
    }
};

int main82() {
    Solution82 solution;
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
        if (prev) prev->next = current;
        prev = current;
    }
    ListNode* res = solution.deleteDuplicates(head);
    current = res;
    while (current) {
        cout << current->val;
        if (current->next) cout << "->";
        current = current->next;
    }
    cout << endl;
    system("pause");
    return 0;
}