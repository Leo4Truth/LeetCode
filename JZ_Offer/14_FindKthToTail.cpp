#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // segment fault
    ListNode* FindKthToTail_1(ListNode* pHead, int k) {
        if (!pHead || k == 0) return nullptr;
        stack<ListNode*> stk;
        ListNode* p = pHead;
        while (p) {
            stk.push(p);
            p = p->next;
        }
        for (int i = 0; i < k; i++) {
            p = stk.top();
            stk.pop();
        }
        return p;
    }

    ListNode* FindKthToTail_2(ListNode* pHead, int k) {
        if (!pHead || k == 0) return nullptr;
        ListNode* p = pHead;
        ListNode* q = pHead;
        while (p && k != 0) {
            k--;
            p = p->next;
        }
        if (k != 0) return nullptr;
        while (p) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
    int k = argc >= 3 ? stoi(argv[2]) : 1;
    ListNode* pHead = nullptr;
    ListNode* pCurrent = nullptr;
    ListNode* pPrev = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pCurrent = new ListNode(x);
        if (!pHead) pHead = pCurrent;
        else pPrev->next = pCurrent;
        pPrev = pCurrent;
    }

    Solution solution;
    ListNode* pNode = solution.FindKthToTail_2(pHead, k);
    cout << pNode->val << endl;

    //system("pause");
    return 0;
}
