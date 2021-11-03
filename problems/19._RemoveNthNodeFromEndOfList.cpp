#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution19 {
public:
	ListNode* removeNthFromEndStack(ListNode* head, int n) {
		vector<ListNode*> stack;
		ListNode* current = head;
		int count = 0;
		while (current != NULL) {
			count++;
			stack.push_back(current);
			current = current->next;
		}

		cout << "count: " << count << endl;

		if (count == 1) return NULL;
		if (n == count) {
			head = stack[1];
			delete stack[0];
		}
		else {
			ListNode* NodeToRemove = stack[stack.size() - n];
			stack[stack.size() - n - 1]->next = NodeToRemove->next;
			delete NodeToRemove;
		}
		
		return head;
	}

	ListNode* removeNthFromEndTwoPass(ListNode* head, int n) {
		ListNode* p = head;
		int len = 0;
		while (p != NULL) {
			len++;
			p = p->next;
		};

		if (len == 1 && n == 1) return NULL; // the case only one node in list
		if (len == n) return head->next; // the case remove the head

		p = head;
		for (int i = 0; i < len - n - 1; i++) p = p->next;
		p->next = p->next->next;

		return head;
	}
};