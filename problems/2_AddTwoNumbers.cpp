#include <iostream>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2, *pSumHead = nullptr, *pSumCurrent = nullptr;

		pSumHead = pSumCurrent = new ListNode(0);

		bool isCarry = false;

		while (p1 && p2) {
			int tmp = 0;

			if (isCarry) tmp = p1->val + p2->val + 1;
			else tmp = p1->val + p2->val;
			
			if (tmp < 10) {
				pSumCurrent->val = tmp;
				isCarry = false;
			}
			else {
				pSumCurrent->val = tmp - 10;
				isCarry = true;
			}

			p1 = p1->next;
			p2 = p2->next;

			if (p1 || p2) {
				pSumCurrent->next = new ListNode(0);
				pSumCurrent = pSumCurrent->next;
			}
		}

		while (p1) {
			int tmp = 0;

			if (isCarry) tmp = p1->val + 1;
			else tmp = p1->val;

			if (tmp == 10) {
				pSumCurrent->val = 0;
				isCarry = true;
			}
			else {
				pSumCurrent->val = tmp;
				isCarry = false;
			}

			p1 = p1->next;

			if (p1) {
				pSumCurrent->next = new ListNode(0);
				pSumCurrent = pSumCurrent->next;
			}
		}

		while (p2) {
			int tmp = 0;

			if (isCarry) tmp = p2->val + 1;
			else tmp = p2->val;

			if (tmp == 10) {
				pSumCurrent->val = 0;
				isCarry = true;
			}
			else {
				pSumCurrent->val = tmp;
				isCarry = false;
			}

			p2 = p2->next;

			if (p2) {
				pSumCurrent->next = new ListNode(0);
				pSumCurrent = pSumCurrent->next;
			}
		}

		if (isCarry) pSumCurrent->next = new ListNode(1);

		return pSumHead;
	}
};