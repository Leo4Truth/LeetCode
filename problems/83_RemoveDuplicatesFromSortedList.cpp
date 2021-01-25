#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution83 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *current = head, *prev = nullptr;
		ListNode *next = nullptr;

		while (current != nullptr) {
			next = current->next;
			if (next != nullptr && next->val == current->val) {
				ListNode *dup = next;
				current->next = next->next;
				delete dup;
			}
			else {
				prev = current;
				current = current->next;
			}
		}

		return head;
	}
};

int main83() {
	return 0;
}