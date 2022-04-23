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
    virtual ListNode* reverseEvenLengthGroups(ListNode* head) = 0;
};

class Solution_init : public Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (!head || !head->next) return head;

        int len = 1;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (true) {
            // <next, len of sublist>
            pair<ListNode*, int> p = cut(curr, len);
            ListNode* next = p.first;
            int l = p.second;
            
            if (l % 2 == 0) {
                vector<ListNode*> v = reverse(curr);
                if (prev) prev->next = v[0];
                prev = v[1];
                prev->next = p.first;
            }
            else {
                if (prev) prev->next = curr;
                for (int i = 0; i < l; i++) {
                    if (i == l - 1) prev = curr;
                    curr = curr->next;
                }
            }

            curr = p.first;
            if (!curr) break;
            len++;
        }

        return head;
    }

private:
    // reverse, return head and tail of the reversed list
    vector<ListNode*> reverse(ListNode* head) {
        if (!head || !head->next) return {head, head};
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {prev, head};
    }

    // cut off a sublist with len length from a list
    // return the head of the remain list
    pair<ListNode*, int> cut(ListNode* head, int len) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int i = 0;
        while (curr && i < len) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = nullptr;
        return {curr, i};
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        curr = new ListNode(val);
        if (!head) head = curr;
        else prev->next = curr;
        prev = curr;
    }
    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    Solution_init *solution = nullptr;

    solution = new Solution_init();
    //ListNode* h = solution->reverseEvenLengthGroups(head);
    ListNode* h = solution->reverseEvenLengthGroups(head);
    p = h;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    return 0;
}
