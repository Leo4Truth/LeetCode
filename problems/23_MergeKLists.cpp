#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for singly-linked list.
 struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

class Solution23 {
public:
	struct compare {
		bool operator()(const ListNode* node1, const ListNode* node2) {
			return node1->val > node2->val;
		}
	};

	// each turn choose the min of all front elements of all lists
	// optimize the algorithm by priority queue
	ListNode* mergeKListsPriority(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, compare> queue;
		
		for (auto list : lists) {
			// if (list) is neccessary, without which the program will exceed time limit
			if (list) queue.push(list);
		}

		if (queue.empty()) return NULL;

		ListNode* head = NULL;
		ListNode* current = NULL;
		ListNode* prev = NULL;

		while (!queue.empty()) {
			if (head == NULL) {
				head = queue.top();
				queue.pop();
				if (head && head->next) queue.push(head->next);
				prev = head;
			}
			else {
				current = queue.top();
				queue.pop();
				if (current && current->next) queue.push(current->next);
				prev->next = current;
				prev = current;
			}
		}

		return head;
	}

	// Merge lists Divide and Conquer
	ListNode* mergeKListsDivideAndConquer(vector<ListNode*>& lists) {
		if (lists.empty()) return NULL;

		int n = lists.size();
		// loop, merge until there is only one list in the lists array
		while (n > 1) {
			// next_n is the number of lists in the lists array next turn
			int next_n = (n + 1) / 2;

			// each turn, merge all pairs of two adjacent lists
			for (int i = 0; i < next_n; i++) {
				// deal with the case that there is only one single list left
				if (i * 2 + 1 < n)
					lists[i] = mergeTwoLists(lists[i * 2], lists[i * 2 + 1]);
				else
					lists[i] = lists[i * 2];
			}
			for (int i = next_n; i < n; i++) lists[i] = NULL;
			n = next_n;
		}
		return lists[0];
	}

	ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
		ListNode* p1 = h1;
		ListNode* p2 = h2;

		ListNode* head = NULL;
		ListNode* current = NULL;
		ListNode* prev = NULL;

		while (p1 && p2) {
			ListNode* tmp = NULL;
			if (p1->val <= p2->val) {
				tmp = p1;
				p1 = p1->next;
			}
			else {
				tmp = p2;
				p2 = p2->next;
			}

			if (head == NULL) {
				head = tmp;
				if (head) head->next = NULL;
				prev = head;
			}
			else {
				current = tmp;
				current->next = NULL;
				if (prev) prev->next = current;
				prev = current;
			}
		}

		if (p1) {
			if (head == NULL) head = p1;
			else if (current) current->next = p1;
			else head->next = p1;
		}
		if (p2) {
			if (head == NULL) head = p2;
			else if (current) current->next = p2;
			else head->next = p2;
		}

		return head;
	}
};

int main23() {
	Solution23 solution;
	vector<ListNode*> lists;
	int n, len, x;
	
	cout << "input number of lists: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "the " << i << "th list" << endl;
		cout << "please input the length of the " << i << "th list" << endl;
		cin >> len;
		cout << "input the elements of the " << i << "th list" << endl;
		ListNode* head = NULL;
		ListNode* current = NULL;
		ListNode* prev = NULL;
		for (int j = 0; j < len; j++) {
			cin >> x;
			if (head == NULL) {
				head = new ListNode(x);
				prev = head;
			}
			else {
				current = new ListNode(x);
				prev->next = current;
				prev = current;
				cout << prev->val;
			}
		}
		lists.push_back(head);
	}

	cout << "[" << endl;
	for (int i = 0; i < lists.size(); i++) {
		cout << "  [";
		for (ListNode* p = lists[i]; p != NULL;) {
			cout << p->val;
			if (p->next) {
				cout << ", ";
				p = p->next;
			}
			else break;
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;

	ListNode* merged = solution.mergeKListsDivideAndConquer(lists);

	cout << "merged" << endl;
	while (merged) {
		cout << merged->val;
		if (merged->next) {
			cout << "->";
			merged = merged->next;
		}
		else break;
	}
	cout << endl;

	system("pause");

	return 0;
}