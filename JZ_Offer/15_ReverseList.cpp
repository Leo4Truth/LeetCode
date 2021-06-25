#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead) return nullptr;
        ListNode* pCurrent = pHead->next;
        ListNode* pPrev = pHead;
        pPrev->next = nullptr;
        while (pCurrent) {
            ListNode* pNext = pCurrent->next;
            pCurrent->next = pPrev;
            pPrev = pCurrent;
            pCurrent = pNext;
        }
        return pPrev;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 5;
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
    ListNode* pRHead = solution.ReverseList(pHead);

    ListNode* p = pRHead;
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}
