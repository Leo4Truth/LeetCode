#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution160 {
public:
    ListNode *getIntersectionNode_hashTable(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA) {
            set.insert(pA);
            pA = pA->next;
        }
        while (pB) {
            if (set.find(pB) == set.end()) set.insert(pB);
            else return pB;
            pB = pB->next;
        }
        return NULL;
    }
    
    ListNode *getIntersectionNode_twoPointers(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};

int main(int argc, char* argv[]) {
    ListNode* headA = NULL;
    ListNode* headB = NULL;
    
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);

    a1->next = a2;
    b1->next = b2;
    b2->next = b3;
    c1->next = c2;
    c2->next = c3;
    a2->next = c1;
    b3->next = c1;

    headA = a1;
    headB = b1;

    Solution160 solution;
    ListNode* res = solution.getIntersectionNode_twoPointers(a1, b1);
    ListNode* node = res;
    while (node) {
        cout << node->val;
        if (node->next) cout << "->";
        node = node->next;
    }
    cout << endl;

    //system("pause");
    return 0;
}

