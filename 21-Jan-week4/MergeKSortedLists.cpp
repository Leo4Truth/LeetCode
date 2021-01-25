#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#include "lib/ListNode.h"

using namespace std;

class Compare{
public:
    bool operator() (ListNode* node1, ListNode* node2){
        return node1->val > node2->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> q; //min heap
        for (auto head : lists) {
            auto node = head;
            while (node) {
                q.push(node);
                node = node->next;
            }
        }
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while (!q.empty()) {
            auto current = q.top();
            q.pop();
            if (!head) head = current;
            else prev->next = current;
            prev = current;
        }
        if (prev) prev->next = nullptr;
        return head;
    }
};

int main(int argc, char* argv[]) {
    string s1 = argc >= 2 ? argv[1] : "";
    string s2 = argc >= 3 ? argv[2] : "";

    Solution solution;

    //system("pause");
    return 0;
}
