#include <iostream>
#include <unordered_map>

#define DEBUG

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> map;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int sum = 0;
        for (auto p = dummy; p; p = p->next) {
            sum += p->val;
            map[sum] = p;
        }
        sum = 0;
        for (auto p = dummy; p; p = p->next) {
            sum += p->val;
            p->next = map[sum]->next;
        }
        auto newHead =  dummy->next;
        delete(dummy);
        return newHead;
    }
};

int main(int argc, char* argv[]) {
    ListNode* n0 = new ListNode(0);
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(-3);
    ListNode* n4 = new ListNode(3);
    ListNode* n5 = new ListNode(-2);
    ListNode* n6 = new ListNode(1);
    ListNode* n7 = new ListNode(1);
    ListNode* n8 = new ListNode(1);
    ListNode* n00 = new ListNode(0);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;


#ifdef DEBUG
    ListNode* p = n0;
    cout << "[";
    while (p) {
        cout << p->val;
        if (p->next) cout << ",";
        p = p->next;
    }
    cout << "]" << endl;
#endif // DEBUG 

    Solution solution;
    ListNode* head = solution.removeZeroSumSublists(n1);
    
#ifdef DEBUG
    cout << "[";
    p = head;
    while (p) {
        cout << p->val;
        if (p->next) cout << ",";
        p = p->next;
    }
    cout << "]" << endl;
#endif // DEBUG 

    return 0;
}
