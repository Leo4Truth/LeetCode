#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup_21_6_27(ListNode* head, int k) {
		if (!head) return nullptr;	// empty list
		if (k == 1) return head;	// k == 1, no operation needed
		ListNode* node = head;
		int n = 0;
		while (node) {
			n++;
			node = node->next;
		}
		if (n < k) return head;		// length of the list less than k, no operation needed
		cout << n << endl;
		int groupNum = n / k;
		int gn = 0;
		int kk = 0;
		ListNode* newHead = nullptr;
		ListNode* prevGroupTail = nullptr;
		ListNode* groupTail = nullptr;
		ListNode* prev = nullptr;
		ListNode* curr = head;
		ListNode* next = nullptr;
		while (true) {
			kk++;
			if (kk == 1) {
				prevGroupTail = groupTail;
				groupTail = curr;
			}
			else if (kk == k) {
				if (!newHead) newHead = curr;
				if (prevGroupTail) {
					prevGroupTail->next = curr;
				}
				gn++;
				kk = 0;
			}
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			if (gn == groupNum) {
				groupTail->next = curr;
				return newHead;
			}
		}
		return newHead;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		// return if there is less than k nodes in the list
		int i = 0;
		for (ListNode* p = head; i < k; p = p->next, i++) if (!p) return head;

		ListNode* prev = NULL;
		ListNode* next = head;
		do {
			stack<ListNode*> stk;

			// push k nodes into stack as a block
			i = 0;
			for (ListNode* p = next; i < k; p = p->next, i++) {
				if (p) stk.push(p);
				else return head; // return if there is not enough nodes remain
				if (i == k - 1) next = p->next; // record the next node of the block
			}

			// the first block
			if (!prev) head = stk.top();

			// reverse the nodes in the block
			while (!stk.empty()) {
				ListNode* p = stk.top();

				// link the previous block to the current block
				if (prev && stk.size() == k) prev->next = p;
				
				stk.pop();

				// if the node is the last one in the block, record the tail pointer as prev
				if (stk.empty()) {
					p->next = next;
					prev = p;
				}
				else p->next = stk.top();
			}
		} while (true);

		return head;
	}
};

int main() {
	Solution solution;
	int n, k;
	ListNode* head = NULL;
	ListNode* current = NULL;
	ListNode* prev = NULL;
	int x;

	cout << "input length of the list:" << endl;
	cin >> n;
	cout << "input n elements of the list:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (!head) {
			head = new ListNode(x);
			prev = head;
		}
		else {
			current = new ListNode(x);
			prev->next = current;
			prev = current;
		}
	}
	cout << "input k:" << endl;
	cin >> k;

	ListNode* h = solution.reverseKGroup_21_6_27(head, k);
	for (ListNode* p = h; p; p = p->next) {
		cout << p->val;
		if (p->next) cout << ", ";
		else cout << endl;
	}

	system("pause");

	return 0;
}