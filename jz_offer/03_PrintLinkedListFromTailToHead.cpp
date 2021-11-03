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
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p = head;
        stack<int> stk;
        vector<int> res;
        while (p) {
            stk.push(p->val);
            p = p->next;
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    ListNode* head = nullptr;
    ListNode* current = nullptr;
    ListNode* prev = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        current = new ListNode(x);
        if (!head) head = current;
        else prev->next = current;
        prev = current;
    }

    Solution solution;
    vector<int> res = solution.printListFromTailToHead(head);
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    //system("pause");
    return 0;
}

