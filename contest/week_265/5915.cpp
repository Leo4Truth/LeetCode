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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head) return {-1, -1};
        vector<pair<int, ListNode*>> localMinMax;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        int idx = 0;
        while (curr) {
            if (prev && next) {
                if (prev->val > curr->val && next->val > curr->val) localMinMax.push_back(make_pair(idx, curr));
                if (prev->val < curr->val && next->val < curr->val) localMinMax.push_back(make_pair(idx, curr));
            }
            prev = curr;
            curr = next;
            idx++;
            if (curr) next = curr->next;
            else break;
        }

        cout << "localMinMax: " << endl;
        for (auto p : localMinMax) cout << "[" << p.first << ", " << p.second->val << "]" << endl;
        cout << endl;

        if (localMinMax.size() == 0 || localMinMax.size() == 1) return {-1, -1};
        int maxDistance = abs(localMinMax[0].first - localMinMax[localMinMax.size() - 1].first);
        int minDistance = maxDistance;
        for (int i = 1; i < localMinMax.size(); i++) {
            minDistance = min(minDistance, localMinMax[i].first - localMinMax[i - 1].first);
        }
        return {minDistance, maxDistance};
    }
};

int main(int argc, char* argv[]) {
    int n = argc >= 2 ? stoi(argv[1]) : 0;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    for (int i = 0; i < n; i++) {
        curr = new ListNode();
        cin >> curr->val;
        if (!head) head = curr;
        else prev->next = curr;
        prev = curr;
    }

    Solution solution;
    vector<int> res = solution.nodesBetweenCriticalPoints(head);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    
    return 0;
}

