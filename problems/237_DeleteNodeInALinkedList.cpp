#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr && curr->next) {
            curr->val = curr->next->val;
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int deleteVal = argc >= 3 ? stoi(argv[2]) : 0;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    ListNode* deleteNode = nullptr;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        curr = new ListNode(val);
        if (!head) {
            head = curr;
            deleteNode = curr;
        }
        else prev->next = curr;
        prev = curr;
        if (curr->val == deleteVal) deleteNode = curr;
    }

    Solution solution;
    solution.deleteNode(deleteNode);
    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    return 0;
}
