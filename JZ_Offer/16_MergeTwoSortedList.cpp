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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        ListNode* pH = nullptr;        
        ListNode* pCurrent = nullptr;
        ListNode* pPrev = nullptr;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                pCurrent = p1;
                p1 = p1->next;
            }
            else {
                pCurrent = p2;
                p2 = p2->next;
            }
            if (!pH) pH = pCurrent;
            else pPrev->next = pCurrent;
            pPrev = pCurrent;
        }
        if (p1) pPrev->next = p1;
        if (p2) pPrev->next = p2;
        return pH;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;

    //system("pause");
    return 0;
}
