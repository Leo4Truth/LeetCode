#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

	void print() {
		ListNode *p = this;
		while (p->next) {
			cout << p->val << "->";
			p = p->next;
		}
		cout << p->val << endl;
    }
};

class Solution21 {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2;
		ListNode *head = nullptr;
		ListNode *current = nullptr;

		if (!p1) return p2;
		if (!p2) return p1;

		if (p1->val <= p2->val) {
			head = current = p1;
			p1 = p1->next;
		}
		else {
			head = current = p2;
			p2 = p2->next;
		}

		while (p1 && p2) {
			if (p1->val <= p2->val) {
				current->next = p1;
				current = current->next;
				p1 = p1->next;
			}
			else {
				current->next = p2;
				current = current->next;
				p2 = p2->next;
			}
		}

		if (p1) current->next = p1;
		else if (p2) current->next = p2;

		return head;
	}
};

int main21() {
	ListNode *h1 = nullptr, *h2 = nullptr;
	ListNode *l1 = nullptr, *l2 = nullptr;
	int x;

	cin >> x;
	while (x != 0) {
		if (!l1) h1 = l1 = new ListNode(x);
		else {
			l1->next = new ListNode(x);
			l1 = l1->next;
		}
		cin >> x;
	}

	cin >> x;
	while (x != 0) {
		if (!l2) h2 = l2 = new ListNode(x);
		else {
			l2->next = new ListNode(x);
			l2 = l2->next;
		}
		cin >> x;
	}

	cout << "List 1: ";
	for (ListNode *node = h1; node != nullptr; node = node->next) {
		if (node->next) cout << node->val << "->";
		else cout << node->val;
	}
	cout << endl;

	cout << "List 2: ";
	for (ListNode *node = h2; node != nullptr; node = node->next) {
		if (node->next) cout << node->val << "->";
		else cout << node->val;
	}
	cout << endl;

	h1->print();
	h2->print();

	Solution21 solution;
	ListNode *res = solution.mergeTwoLists(h1, h2);
	res->print();
	
	system("pause");

	return 0;
}