#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution1721 {
public:
    // strict swap nodes
    ListNode* swapNodes1(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* p = dummyHead;
        ListNode* prev1 = nullptr;
        ListNode* prev2 = nullptr;
        int cnt = 0;
        while (true) {
            cout << cnt << endl;
            if (cnt == k - 1) prev1 = p;
            else if (cnt == k) prev2 = dummyHead;
            else if (cnt > k) prev2 = prev2->next;
            cnt++;
            p = p->next;
            if (!p) break;
        }
        cout << "prev1:" << prev1->val << ", prev2:" << prev2->val << endl;
        ListNode* node1 = prev1->next;
        ListNode* node2 = prev2->next;
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;
        if (node1) next1 = node1->next;
        if (node2) next2 = node2->next;
#ifdef DEBUG
        if (prev1) cout << "prev1:" << prev1->val << endl;
        if (node1) cout << "node1:" << node1->val << endl;
        if (next1) cout << "next1:" << next1->val << endl;
        if (prev2) cout << "prev2:" << prev2->val << endl;
        if (node2) cout << "node2:" << node2->val << endl;
        if (next2) cout << "next2:" << next2->val << endl;
#endif // DEBUG
        if (prev1->next == prev2) {
            node1->next = next2;
            node2->next = node1;
            prev1->next = node2;
        }
        else if (prev2->next == prev1) {
            node2->next = next1;
            node1->next = node2;
            prev2->next = node1;
        }
        else {
            node1->next = next2;
            node2->next = next1;
            prev1->next = node2;
            prev2->next = node1;
        }
        return dummyHead->next;
    }

    // strict swap values of nodes
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        ListNode* p3 = nullptr;
        int cnt = 0;
        while (true) {
            cnt++;
            if (cnt == k) {
                p1 = head;
                if (p2) p3 = p2->next;
                else p3 = head;
            }
            else if (cnt > k) p1 = p1->next;
            if (!p2) p2 = head;
            else p2 = p2->next;
            if (!p2->next) break;
    #ifdef DEBUG
            cout << "cnt:" << cnt << " ";
            if (p1) cout << "p1:" << p1->val << " ";
            if (p2) cout << "p2:" << p2->val << " ";
            if (p3) cout << "p3:" << p3->val << " ";
            cout << endl;
    #endif // DEBUG
        }
        int tmp = p1->val;
        p1->val = p3->val;
        p3->val = tmp;
        return head;
    }
};

int main(int argc, char* argv[]) {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    Solution1721 solution;
    ListNode* p = solution.swapNodes(n1, 2);
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}
