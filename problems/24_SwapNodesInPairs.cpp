#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution24 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* prev = NULL;
		ListNode* first = head;
		ListNode* second = head->next;

		while (first && second) {
			ListNode* next = second->next;

			if (!prev) head = second;
			else prev->next = second;

			second->next = first;
			first->next = next;

			prev = first;
			first = prev->next;
			if (first) second = first->next;
			else second = NULL;
		}

		return head;
	}
};
