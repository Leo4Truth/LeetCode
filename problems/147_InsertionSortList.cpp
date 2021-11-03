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
    // pass
    // Time:  44 ms, defeat 41.48%
    // Space: 9.2 ms, defeat 87.66%
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* dummyHead = new ListNode(INT32_MIN);
        ListNode* unsorted = head;
        while (unsorted) {
            ListNode* node = unsorted;
            unsorted = unsorted->next;
            ListNode* p = dummyHead;
            while (p->next && p->next->val < node->val) p = p->next;
            node->next = p->next;
            p->next = node;
        }
        return dummyHead->next;
    }
};

int main(int argc, char* argv[]) {

    Solution solution;

    //system("pause");
    return 0;
}
