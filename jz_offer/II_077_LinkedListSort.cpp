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
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution {
public:
    virtual ListNode* sortList(ListNode* head) = 0;
};

/**
 * @brief linked list quick sort
 * use a vector to store all list nodes and we can use the vector to access node at any index (random access)
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 */
class Solution_quickSort : public Solution{
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<ListNode*> nodes;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int n = 0;
        while (curr) {
            nodes.push_back(curr);
            prev = curr;
            curr = curr->next;
            prev->next = nullptr;
            n++;
        }

        sort(nodes.begin(), nodes.end(), cmp);

        for (int i = 0; i < n - 1; i++) nodes[i]->next = nodes[i + 1];
        
        return nodes[0];
    }

private:
    static bool cmp(const ListNode* n1, const ListNode* n2) {
        return n1->val < n2->val;
    }
};

/**
 * @brief merge sort recursive
 * top-down
 * Time Compleixty: O(nlogn)
 * Space Complexity: O(logn), the depth of the recursive method call stack
 */
class Solution_mergeSort_recursive : public Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* h2 = split(head);

        ListNode* h1 = sortList(head);
        h2 = sortList(h2);

        return merge(h1, h2);
    }

private:
    ListNode* split(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        return newHead;
    }

    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* p1 = h1;
        ListNode* p2 = h2;
        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                curr = p1;
                p1 = p1->next;
            }
            else {
                curr = p2;
                p2 = p2->next;
            }
            if (!head) head = curr;
            else prev->next = curr;
            prev = curr;
        }
        if (p1) prev->next = p1;
        if (p2) prev->next = p2;
        return head;
    }
};

/**
 * @brief merge sort iterative
 * bottom-up
 * Time Complexity: O(nlogn)
 * Space Complexity: O(1)
 */
class Solution_mergeSort_iterative : public Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        int n = 0;
        ListNode* p = head;
        while (p) {
            p = p->next;
            n++;
        }

        ListNode* dummy = new ListNode(0, head);

        for (int len = 1; len < n; len *= 2) {
            ListNode* headPrev = dummy;
            while (headPrev) {
                ListNode* mid = headPrev->next;
                for (int i = 0; i < len; i++) {
                    if (mid) mid = mid->next;
                    else break;
                }
                
                ListNode* tailNext = mid;
                for (int i = 0; i < len; i++) {
                    if (tailNext) tailNext = tailNext->next;
                    else break;
                }
                
                merge(headPrev, mid, tailNext);

                for (int i = 0; i < len * 2; i++) {
                    if (headPrev) headPrev = headPrev->next;
                    else break;
                }
            }
        }

        return dummy->next;
    }

private:
    void merge(ListNode* headPrev, ListNode* mid, ListNode* tailNext) {
        ListNode* p1 = headPrev->next;
        ListNode* p2 = mid;
        ListNode* prev = headPrev;
        ListNode* curr = nullptr;
        while (p1 != mid && p2 != tailNext) {
            if (p1->val <= p2->val) {
                curr = p1;
                p1 = p1->next;
            }
            else {
                curr = p2;
                p2 = p2->next;
            }
            prev->next = curr;
            prev = curr;
        }
        while (p1 != mid) {
            prev->next = p1;
            prev = p1;
            p1 = p1->next;
        }
        while (p2 != tailNext) {
            prev->next = p2;
            prev = p2;
            p2 = p2->next;
        }
        prev->next = tailNext;
    }
};


int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    vector<int> nums;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    ListNode* next = nullptr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
        curr = new ListNode(num);
        if (!head) head = curr;
        else prev->next = curr;
        prev = curr;
    }

    for (curr = head; curr; curr = curr->next) {
        cout << curr->val;
        if (curr->next) cout << "->";
    }
    cout << endl;

    Solution *solution = nullptr;
    ListNode* p = nullptr;
    
    solution = new Solution_quickSort();
    p = solution->sortList(head);
    cout << "quick sort: ";
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    head = nullptr;
    for (int i = 0; i < n; i++) {
        curr = new ListNode(nums[i]);
        if (!head) head = curr;
        else prev->next = curr;
        prev = curr;
    }
    solution = new Solution_mergeSort_recursive();
    p = solution->sortList(head);
    cout << "merge sort recursive: ";
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    head = nullptr;
    for (int i = 0; i < n; i++) {
        curr = new ListNode(nums[i]);
        if (!head) head = curr;
        else prev->next = curr;
        prev = curr;
    }
    solution = new Solution_mergeSort_iterative();
    p = solution->sortList(head);
    cout << "merge sort iterative: ";
    while (p) {
        cout << p->val;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;

    return 0;
}
