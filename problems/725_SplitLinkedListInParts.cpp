#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            n++;
            p = p->next;
        }
        int quotient = n / k, remainder = n % k;

        vector<ListNode*> parts(k, nullptr);
        ListNode* curr = head;
        for (int i = 0; i < k && curr; i++) {
            parts[i] = curr;
            int part_size = quotient + (i < remainder ? 1 : 0);
            for (int j = 1; j < part_size; j++) {
                curr = curr->next;
            }
            ListNode* next = curr->next;
            curr->next = nullptr;
            curr = next;
        }

        return parts;
    }   
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    int k = argc >= 3 ? stoi(argv[2]) : 0;

    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    ListNode* prev = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr = new ListNode(x);
        if (!head) {
            head = curr;
        } else {
            prev->next = curr;
        }
        prev = curr;
    }

    ListNode* p = head;
    while (p) {
        cout << p->val;
        if (p->next) {
            cout << "->";
        }
        p = p->next;
    }
    cout << endl;

    Solution solution;
    vector<ListNode*> res = solution.splitListToParts(head, k);

    cout << "[" << endl;
    for (int i = 0; i < res.size(); i++) {
        p = res[i];
        cout << "\t";
        while (p) {
            cout << p->val;
            if (p->next) {
                cout << "->";
            }
            p = p->next;
        }
        cout << "," << endl;
    }
    cout << "]" << endl;

    return 0;
}
