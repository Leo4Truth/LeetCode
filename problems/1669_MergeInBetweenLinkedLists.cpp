#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
public:
    virtual ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) = 0;
};

class Solution_init : public Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (!list1) return list2;

        ListNode *prev = nullptr, *curr = list1, *next = nullptr;
        int count = 0;
        while (count++ < a) {
            prev = curr;
            curr = curr->next;
            if (curr) next = curr->next;
        }
        while (count++ <= b) {
            curr = curr->next;
            if (curr) next = curr->next;
        }

        if (!list2) {
            prev->next = next;
            return list1;
        }

        ListNode *head2 = list2, *tail2 = list2;
        while (tail2 && tail2->next) tail2 = tail2->next;

        if (prev) prev->next = head2;
        else list1 = head2;

        if (tail2) tail2->next = next;

        return list1;
    }

private:
};

int main(int argc, char* argv[]) {
    int n1 = argc >= 2 ? stoi(argv[1]) : 0;
    int n2 = argc >= 3 ? stoi(argv[2]) : 0;
    int a = argc >= 4 ? stoi(argv[3]) : 0;
    int b = argc >= 5 ? stoi(argv[4]) : 0;

    ListNode *head1 = nullptr, *head2 = nullptr, *curr = nullptr, *prev = nullptr;

    cout << "input " << n1 << " integers as list1" << endl;
    for (int i = 0; i < n1; i++) {
        int val;
        cin >> val;
        curr = new ListNode(val);
        if (!prev) head1 = curr;
        else prev->next = curr;
        prev = curr;
    }

    head2 = nullptr;
    prev = nullptr;
    cout << "input " << n2 << " integers as list2" << endl;
    for (int i = 0; i < n2; i++) {
        int val;
        cin >> val;
        curr = new ListNode(val);
        if (!prev) head2 = curr;
        else prev->next = curr;
        prev = curr;
    }

    Solution *solution = nullptr;

    solution = new Solution_init();
    
    ListNode* head = solution->mergeInBetween(head1, a, b, head2);
    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    return 0;
}
